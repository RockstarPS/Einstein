/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2013. Visteon Corporation owns all rights to           *
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
*  File Name         :  EcuM_Cfg.h                                           *
*  Module Short Name :  EcuM_Cfg_H                                           *
*  Description       :  This is a generated file.                            *
*                                                                            *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  Platform Independent                                   *
*                                                                            *
******************************************************************************/
#ifndef ECUM_CFG_H
#define ECUM_CFG_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "EcuM_Types.h"
#if (ECUM_INCLUDE_BSWM != FALSE)
#include "BswM.h"
#endif

#include "Os.h"
#include "Mcu.h"
#include "Det.h"
#include "ComM.h"


/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define ECUM_FIXED_BEHAVIOR              TRUE
#define ECUM_GLOBAL_INTERRUPTS_ENABLE()         EnableAllInterrupts()

#define ECUM_GLOBAL_INTERRUPTS_DISABLE()        DisableAllInterrupts()

#define ECUM_ENTER_CRITICAL_SECTION()           SuspendAllInterrupts()
#define ECUM_EXIT_CRITICAL_SECTION()            ResumeAllInterrupts()

#define ECUM_MAX_NUM_SLEEP_MODE         2u

#define ECUM_MAX_COM_CHANNELS           1u 
#define ECUM_USE_DUMMY_STATEMENT        STD_ON 
#define ECUM_NUMBER_OF_CORES            1
#define ECUM_SLEEPMODELIST              STD_ON
#define ECUM_STARTOS                    STD_OFF
#define ECUM_RAMHASH                    STD_OFF
#define ECUM_CHECKWAKEUPTIMEOFWAKEUPSOURCELIST  STD_OFF 
#define ECUM_VERSION_INFO_API           FALSE

/* Number of Users of the EcuM */
#define ECUM_MAX_CFG_USERS              1U

/* Mentions which all wakeup sources are enabled for EcuM (irrespective of sleep mode */
/* Updated with a value having bit fields enabled for respective wakeup source */
/* If first 4 wakeup sources are enabled , then ECUM_WAKEUP_SOURCE_MASK = 0x0F */
#define ECUM_WAKEUP_SOURCE_MASK                 \
                (ECUM_WKSOURCE_POWER         | \
                ECUM_WKSOURCE_RESET          | \
                ECUM_WKSOURCE_INTERNAL_RESET | \
                ECUM_WKSOURCE_INTERNAL_WDG   | \
                ECUM_WKSOURCE_EXTERNAL_WDG   | \
                ECUM_WKSOURCE_WAKEUP_RESET   | \
                ECUM_WKSOURCE_CAN            | \
                ECUM_WKSOURCE_RTC)



#define ECUM_INCLUDE_DET                        (FALSE)
#define ECUM_DEV_ERROR_DETECT                   (TRUE)
#define ECUM_INCLUDE_COMM                       (FALSE)
#define ECUM_INCLUDE_NVM_MGR                    (FALSE)
#define ECUM_INCLUDE_NVM_READALL                (TRUE)

#define ECUM_INCLUDE_BSWM                       (FALSE)

#define ECUM_MAIN_FUNCTION_PERIOD_MSEC          10

/* Timeout = Required_Time (in seconds) / EcuM_MainFunction periodicity
*   If Expected timeout is 5second,
*   TIMEOUT = (5000 /  ECUM_MAIN_FUNCTION_PERIOD_MSEC)
*/
#define ECUM_NVM_READALL_TIMEOUT                0UL     /* seconds */
#define ECUM_NVM_WRITEALL_TIMEOUT               10000UL   /* 100 seconds (10ms*100)*/
#define ECUM_RUN_MINIMUM_DURATION               500UL   /* 5 seconds */
     
#define ECUM_DEFAULT_APP_MODE                   OSDEFAULTAPPMODE   
#define ECUM_OS_RESOURCE                        OsResource          
#define ECUM_DEFAULT_SHUTDOWN_TARGET            ECUM_STATE_SLEEP 
#define ECUM_DEFAULT_STATE                      ECUM_STATE_OFF
#define ECUM_DEFAULT_RESET_MODE_REF             ECUM_CFG_WKSOURCE_INTERNAL_RESET
#define ECUM_DEFAULT_SLEEP_MODE_REF             ECUM_SLEEP_MODE_HALT
#define ECUM_SLEEP_MODE                         ECUM_SLEEP_MODE_POLLING
#define ECUM_SLEEP_MODE_MCU_REF                 (Mcu_ModeType)0
#define ECUM_NORMAL_MODE_MCU_REF                (Mcu_ModeType)0xFF

 /*  EcuM_WAKEUP_SOURCE_ID      */
/* ------------------------------------- Range of EcuM_WakeupSourceType -------------------------------------------- */
#define ECUM_WKSOURCE_NONE           (EcuM_WakeupSourceType)(0x00000000UL)
#define ECUM_WKSOURCE_ALL_SOURCES    (EcuM_WakeupSourceType)(~((EcuM_WakeupSourceType)0x00UL))
#define ECUM_WKSOURCE_POWER          (EcuM_WakeupSourceType)(0x01UL) //standard
#define ECUM_WKSOURCE_RESET          (EcuM_WakeupSourceType)(0x02UL) //standard
#define ECUM_WKSOURCE_INTERNAL_RESET (EcuM_WakeupSourceType)(0x04UL) //standard
#define ECUM_WKSOURCE_INTERNAL_WDG   (EcuM_WakeupSourceType)(0x08UL) //standard
#define ECUM_WKSOURCE_EXTERNAL_WDG   (EcuM_WakeupSourceType)(0x10UL) //standard
#define ECUM_WKSOURCE_WAKEUP_RESET   (EcuM_WakeupSourceType)(0x20UL) //user
#define ECUM_WKSOURCE_CAN            (EcuM_WakeupSourceType)(0x40UL) //user
#define ECUM_WKSOURCE_RTC            (EcuM_WakeupSourceType)(0x80UL) //user

#define ECUM_MAX_NUM_WAKEUP_SOURCE                             (8U) //total count (std + user)
#define ECUM_STD_WAKEUPS_COUNT                                 (5U) //standard count only
/* ------------------------------------- Symblic Name Defines for EcuM_WakeupSourceType ---------------------------- */
#define ECUM_CFG_WKSOURCE_POWER                 (Mcu_ResetType)(0UL) 
#define ECUM_CFG_WKSOURCE_RESET                 (Mcu_ResetType)(1UL) 
#define ECUM_CFG_WKSOURCE_INTERNAL_RESET        (Mcu_ResetType)(2UL) 
#define ECUM_CFG_WKSOURCE_INTERNAL_WDG          (Mcu_ResetType)(3UL) 
#define ECUM_CFG_WKSOURCE_EXTERNAL_WDG          (Mcu_ResetType)(4UL) 
#define ECUM_CFG_WKSOURCE_INTERNAL_ICU          (Mcu_ResetType)(5UL) 

/* ID for each user to be populated */
/*       EcuM_FIXED_USER_ID         */
#define ECUM_FIXED_USER_ECUMEXT                 (0UL)

#define ECUM_COMM_COMMUNICATION_ALLOWED         (FALSE)

#if (ECUM_COMM_COMMUNICATION_ALLOWED != FALSE)
    #define ECUM_COMM_MAX_ALLOWED_LIST              1
    #define ECUM_COMM_COMMUNICATION_ALLOWED_LIST    {0}
#endif

/* Bsw config pointers */
#define ECUM_SCHM_CONFIG_POINTER                NULL
#define ECUM_DEM_CONFIG_POINTER                 NULL
#define ECUM_BSWM_CONFIG_POINTER                NULL_PTR


#define ECUM_MAX_RESET_MODE                     (4uL)


/*----------------- Range of Sleep Modes  ------------------------- */
//todo: Need to be modified as per the sleep modes supported by McuDrv
#define ECUM_SLEEP_MODE_HALT                                (0u)
#define ECUM_SLEEP_MODE_POLLING                             (1uL)
#define ECUM_SLEEP_MODE_MAX                                 (2uL)

/*****************************************************************************
*                                 function Declarations                          *
******************************************************************************/
extern void SchM_Init(void);
extern void Rte_Start(void);
extern void Rte_Stop(void);

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/




#define ECUM_DRIVER_INIT_LIST_ONE               &EcuM_ConfigPtr
#define ECUM_DRIVER_INIT_LIST_TWO               &EcuM_ConfigPtr
#define ECUM_DRIVER_INIT_LIST_THREE             &EcuM_ConfigPtr
#define ECUM_DRIVER_RESTART_LIST                &EcuM_ConfigPtr

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

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

 






#endif

