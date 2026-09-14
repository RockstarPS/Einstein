/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2026 by Visteon Corporation.       All rights reserved.         
*                                                                                                                    
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                   
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve              
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States     
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,             
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its       
* rights under all copyright laws to protect this work as a published work, when appropriate.                        
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it   
* without the written authorization of Visteon Corporation.                                                          
********************************************************************************************************************/

/*******************************************************************************************************************
*    @file EcuM_Cfg.h
*    @ingroup EcuM Configuration
*    @brief This is EcuM Pre-compile time configuration header file. It contains definitions of pre-compile time
*    configuration parameters for the EcuM module.
*    Auto generated code in vAUTOSAR TOOL by ABASAVAR at 2026-08-17 19:13:12.831324200
********************************************************************************************************************/

#ifndef ECUM_CFG_H
#define ECUM_CFG_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Os.h"
#include "EcuM_Types.h"
#include "BswM.h"
#include "Mcu.h"
#include "ComM.h"
#include "Det.h"
#include "Rte_Main.h"
#include "SchM_EcuM.h"

/*****************************************************************************
*  						 	 Version Information                             *
******************************************************************************/
/* Software Version */
#define ECUM_CFG_SW_MAJOR_VERSION                                     1U
#define ECUM_CFG_SW_MINOR_VERSION                                     0U
#define ECUM_CFG_SW_PATCH_VERSION                                     22U
/* Autosar Release */
#define ECUM_CFG_AR_RELEASE_MAJOR_VERSION                             4U
#define ECUM_CFG_AR_RELEASE_MINOR_VERSION                             3U
#define ECUM_CFG_AR_RELEASE_REVISION_VERSION                          1U
/*****************************************************************************
*                            Macro Definitions                          	 *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#ifndef Rte_TypeDef_EcuM_BootTargetType
#define Rte_TypeDef_EcuM_BootTargetType
typedef uint8 EcuM_BootTargetType;
#endif
#ifndef Rte_TypeDef_EcuM_ModeType
#define Rte_TypeDef_EcuM_ModeType
typedef uint8 EcuM_ModeType;
#endif
#ifndef Rte_TypeDef_EcuM_ShutdownCauseType
#define Rte_TypeDef_EcuM_ShutdownCauseType
typedef uint8 EcuM_ShutdownCauseType;
#endif
#ifndef Rte_TypeDef_EcuM_StateType
#define Rte_TypeDef_EcuM_StateType
typedef uint8 EcuM_StateType;
#endif
#ifndef Rte_TypeDef_EcuM_TimeType
#define Rte_TypeDef_EcuM_TimeType
typedef uint32 EcuM_TimeType;
#endif
#ifndef Rte_TypeDef_EcuM_UserType
#define Rte_TypeDef_EcuM_UserType
typedef uint8 EcuM_UserType;
#endif

#define ECUM_FIXED_BEHAVIOR                                           TRUE
#define ECUM_GLOBAL_INTERRUPTS_ENABLE()                               EnableAllInterrupts()
#define ECUM_GLOBAL_INTERRUPTS_DISABLE()                              DisableAllInterrupts()
#define ECUM_ENTER_CRITICAL_SECTION()                                 SuspendAllInterrupts()
#define ECUM_EXIT_CRITICAL_SECTION()                                  ResumeAllInterrupts()

#define ECUM_MAX_NUM_SLEEP_MODE                                       2U
#define ECUM_MAX_COM_CHANNELS                                         1U
#define ECUM_USE_DUMMY_STATEMENT                                      STD_ON
#define ECUM_NUMBER_OF_CORES                                          1U
#define ECUM_SLEEPMODELIST                                            STD_ON
#define ECUM_STARTOS                                                  STD_OFF
#define ECUM_RAMHASH                                                  STD_OFF
#define ECUM_CHECKWAKEUPTIMEOFWAKEUPSOURCELIST                        STD_OFF
#define ECUM_VERSION_INFO_API                                         STD_OFF

/* Number of EcuM Users*/
#define ECUM_MAX_CFG_USERS                                            1U

#ifndef EcuMUserConfig_EcuMFixedUserConfig
	#define EcuMUserConfig_EcuMFixedUserConfig (0U)
#endif

/* Mentions which all wakeup sources are enabled for EcuM (irrespective of sleep mode) */
/* Updated with a value having bit fields enabled for respective wakeup source */
/* If first 4 wakeup sources are enabled , then ECUM_WAKEUP_SOURCE_MASK = 0x0F */
#define ECUM_WAKEUP_SOURCE_MASK	\
	(ECUM_WKSOURCE_POWER | \
	ECUM_WKSOURCE_RESET | \
	ECUM_WKSOURCE_INTERNAL_RESET | \
	ECUM_WKSOURCE_INTERNAL_WDG | \
	ECUM_WKSOURCE_EXTERNAL_WDG | \
	ECUM_WKSOURCE_WAKEUP_RESET | \
	ECUM_WKSOURCE_CAN | \
	ECUM_WKSOURCE_IGN | \
	ECUM_WKSOURCE_RTC)

#define ECUM_INCLUDE_DET                                              FALSE
#define ECUM_DEV_ERROR_DETECT                                         TRUE
#define ECUM_INCLUDE_COMM                                             FALSE
#define ECUM_INCLUDE_NVM_MGR                                          FALSE
#define ECUM_INCLUDE_NVM_READALL                                      TRUE
#define ECUM_INCLUDE_BSWM                                             TRUE
#define ECUM_MAIN_FUNCTION_PERIOD_MSEC                                10UL

/* Timeout = Required_Time (in seconds) / EcuM_MainFunction periodicity
*   If Expected timeout is 5second,
*   TIMEOUT = (5000 /  ECUM_MAIN_FUNCTION_PERIOD_MSEC)
*/
#define ECUM_NVM_READALL_TIMEOUT                                      0UL
#define ECUM_NVM_WRITEALL_TIMEOUT                                     10000UL
#define ECUM_RUN_MINIMUM_DURATION                                     500UL

#define ECUM_DEFAULT_APP_MODE                                         OSDEFAULTAPPMODE	/** EcuMDefaultAppMode of the Os module defined in tcbpost.h */
#define ECUM_OS_RESOURCE                                              RES_SCHEDULER	/** EcuMOSResource of the Os module defined in tcbpost.h */
#define ECUM_DEFAULT_SHUTDOWN_TARGET                                  ECUM_STATE_SLEEP
#define ECUM_DEFAULT_STATE                                            ECUM_STATE_OFF
#define ECUM_DEFAULT_RESET_MODE_REF                                   ECUM_CFG_WKSOURCE_ECUM_WKSOURCE_POWER
#define ECUM_DEFAULT_SLEEP_MODE_REF                                   ECUM_SLEEP_MODE_HALT

#define ECUM_NORMAL_MODE_MCU_REF                                      (Mcu_ModeType)0xFF

/*  EcuM_WAKEUP_SOURCE_ID      */
/* ------------------------------------- Range of EcuM_WakeupSourceType -------------------------------------------- */
#define ECUM_WKSOURCE_NONE                                            (EcuM_WakeupSourceType)(0x00000000UL)
#define ECUM_WKSOURCE_ALL_SOURCES                                     (EcuM_WakeupSourceType)(~((EcuM_WakeupSourceType)0x00UL))
#define ECUM_WKSOURCE_POWER                                           (EcuM_WakeupSourceType)(0x1UL) //Standard
#define ECUM_WKSOURCE_RESET                                           (EcuM_WakeupSourceType)(0x2UL) //Standard
#define ECUM_WKSOURCE_INTERNAL_RESET                                  (EcuM_WakeupSourceType)(0x4UL) //Standard
#define ECUM_WKSOURCE_INTERNAL_WDG                                    (EcuM_WakeupSourceType)(0x8UL) //Standard
#define ECUM_WKSOURCE_EXTERNAL_WDG                                    (EcuM_WakeupSourceType)(0x10UL) //Standard
#define ECUM_WKSOURCE_WAKEUP_RESET                                    (EcuM_WakeupSourceType)(0x20UL) //User
#define ECUM_WKSOURCE_CAN                                             (EcuM_WakeupSourceType)(0x40UL) //User
#define ECUM_WKSOURCE_IGN                                             (EcuM_WakeupSourceType)(0x80UL) //User
#define ECUM_WKSOURCE_RTC                                             (EcuM_WakeupSourceType)(0x100UL) //User

#define ECUM_MAX_NUM_WAKEUP_SOURCE                                    (9UL) //total count (std + user)
#define ECUM_STD_WAKEUPS_COUNT                                        (5UL) //standard count only

/* ------------------------------------- Symblic Name Defines for EcuM_WakeupSourceType ---------------------------- */
#define ECUM_CFG_WKSOURCE_ECUM_WKSOURCE_POWER                         0U
#define ECUM_CFG_WKSOURCE_ECUM_WKSOURCE_RESET                         1U
#define ECUM_CFG_WKSOURCE_ECUM_WKSOURCE_INTERNAL_RESET                2U
#define ECUM_CFG_WKSOURCE_ECUM_WKSOURCE_INTERNAL_WDG                  3U
#define ECUM_CFG_WKSOURCE_ECUM_WKSOURCE_EXTERNAL_WDG                  4U
#define ECUM_CFG_WKSOURCE_ECUM_WKSOURCE_WAKEUP_RESET                  5U
#define ECUM_CFG_WKSOURCE_ECUM_WKSOURCE_CAN                           6U
#define ECUM_CFG_WKSOURCE_ECUM_WKSOURCE_IGN                           7U
#define ECUM_CFG_WKSOURCE_ECUM_WKSOURCE_RTC                           8U

#define ECUM_COMM_COMMUNICATION_ALLOWED                               TRUE

#define ECUM_COMM_MAX_ALLOWED_LIST                                    1U
#define ECUM_COMM_COMMUNICATION_ALLOWED_LIST                          {0}

#define ECUM_SCHM_CONFIG_POINTER                                      NULL_PTR
#define ECUM_DEM_CONFIG_POINTER                                       NULL_PTR
#define ECUM_BSWM_CONFIG_POINTER                                      NULL_PTR

#define ECUM_MAX_RESET_MODE                                           4UL

/*----------------- Range of Sleep Modes  ------------------------- */
#define ECUM_SLEEP_MODE_HALT                                          0UL
#define ECUM_SLEEP_MODE_POLLING                                       1UL
#define ECUM_SLEEP_MODE_MAX                                           2UL
 
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
#define ECUM_DRIVER_INIT_LIST_ONE                                     &EcuM_ConfigPtr
#define ECUM_DRIVER_INIT_LIST_TWO                                     &EcuM_ConfigPtr
#define ECUM_DRIVER_INIT_LIST_THREE                                   &EcuM_ConfigPtr
#define ECUM_DRIVER_RESTART_LIST                                      &EcuM_ConfigPtr

#define EcuM_Rte_Call_Switch_currentMode(Mode_Value) Rte_Switch_currentMode_currentMode(Mode_Value)

#define ECUM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

extern const EcuM_WakeupSourceListType  EcuM_WakeupSourceList[ECUM_MAX_NUM_WAKEUP_SOURCE];
extern const EcuM_SleepModeListType     EcuM_SleepModeList[ECUM_MAX_NUM_SLEEP_MODE];
extern const EcuM_ComMChannelsType      EcuM_ComMChannels[ECUM_MAX_COM_CHANNELS];
extern const EcuM_ConfigType            EcuM_ConfigPtr;
#if (ECUM_COMM_COMMUNICATION_ALLOWED != FALSE)
extern const EcuM_ComMChannelsType      EcuM_ComMAllowedChannels[ECUM_COMM_MAX_ALLOWED_LIST];
#endif

#define ECUM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#endif

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/

