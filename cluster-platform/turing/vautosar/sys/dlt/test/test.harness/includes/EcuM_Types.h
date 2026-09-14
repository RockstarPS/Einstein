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
*  File Name         :  EcuM_Types.h                                         *
*  Module Short Name :  EcuM_Types                                           *
*  Description       :  This file contains declations of the Autosar ECU     *
*                       State Manager types and macros                       *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  Platform Indpendent                                    *
*                                                                            *
******************************************************************************/
#ifndef ECUM_TYPES_H
#define ECUM_TYPES_H

#include "Std_Types.h"
#include "Mcu_Types.h"

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
/*----------------- Range of EcuM_StateType ------------------------- */
#define ECUM_SUBSTATE_MASK                                  (0x0Fu)
#define ECUM_STATE_STARTUP                                  (0x10u)
#define ECUM_STATE_STARTUP_ONE                              (0x11u)
#define ECUM_STATE_STARTUP_TWO                              (0x12u)
#define ECUM_STATE_STARTUP_TWO_WAIT                         (0x13u)
#define ECUM_STATE_WAKEUP                                   (0x20u)
#define ECUM_STATE_WAKEUP_ONE                               (0x21u)
#define ECUM_STATE_WAKEUP_VALIDATION                        (0x22u)
#define ECUM_STATE_WAKEUP_REACTION                          (0x23u)
#define ECUM_STATE_WAKEUP_TWO                               (0x24u)
#define ECUM_STATE_WAKEUP_WAKESLEEP                         (0x25u)
#define ECUM_STATE_WAKEUP_TTII                              (0x26u)
#define ECUM_STATE_RUN                                      (0x30u)
#define ECUM_STATE_APP_RUN                                  (0x32u)
#define ECUM_STATE_APP_POST_RUN                             (0x33u)
#define ECUM_STATE_SHUTDOWN                                 (0x40u)
#define ECUM_STATE_PREP_SHUTDOWN                            (0x44u)
#define ECUM_STATE_GO_SLEEP                                 (0x49u)
#define ECUM_STATE_GO_OFF_ONE                               (0x4Du)
#define ECUM_STATE_GO_OFF_TWO                               (0x4Eu)
/* State OFF, RESET AND SLEEP are defined by the RTE */
#define ECUM_STATE_SLEEP                                    (0x50u)
#define ECUM_STATE_OFF                                      (0x80u)
#define ECUM_STATE_RESET                                    (0x90u)
#define ECUM_STATE_ERROR                                    (0xFFu)

typedef uint32  EcuM_WakeupSourceType;



#define ECUM_BOOT_TARGET_APP            (EcuM_BootTargetType)0
#define ECUM_BOOT_TARGET_OEM_BOOTLOADER (EcuM_BootTargetType)1
#define ECUM_BOOT_TARGET_SYS_BOOTLOADER (EcuM_BootTargetType)2


typedef uint8   EcuM_ComMChannelsType;

typedef uint8   EcuM_WakeupReactionType;

typedef uint16  EcuM_WakeupSrcValidationTime;
/*----------------- Range of EcuM_WakeupReactionType ------------------------- */
#define ECUM_WKACT_RUN              (EcuM_WakeupReactionType)0
#define ECUM_WKACT_TTII             (EcuM_WakeupReactionType)2
#define ECUM_WKACT_SHUTDOWN         (EcuM_WakeupReactionType)3


typedef uint8   EcuM_WakeupStatusType;
/*----------------- Range of EcuM_WakeupStatusType ------------------------- */
#define ECUM_WKSTATUS_NONE                                  (0u)
#define ECUM_WKSTATUS_PENDING                               (1u)
#define ECUM_WKSTATUS_VALIDATED                             (2u)
#define ECUM_WKSTATUS_EXPIRED                               (3u)

/* The following state was introduced to support asynchronous transceiver handling */
/* todo: included only for build success - need to reconsider */
#define ECUM_WKSTATUS_CHECKWAKEUP                           (5u)
#define ECUM_WKSTATUS_ENABLED                               (6u)

#define ECUM_NO_VALIDATION        ((EcuM_WakeupSrcValidationTime)0)
#define ECUM_NO_COMM_CHANNEL      ((EcuM_ComMChannelsType)255)

typedef struct
{
    void * Config_Ptr;
}EcuM_ConfigType;


typedef struct 
{
    EcuM_WakeupSrcValidationTime ValidationTime;
    EcuM_ComMChannelsType Channel;
}EcuM_WakeupSourceListType;

typedef struct
{
    EcuM_WakeupSourceType WakeupSource;
    Mcu_ModeType  McuMode;
    boolean IsPollingAllowed;
}EcuM_SleepModeListType;

typedef uint8 EcuM_RunStatusType; /*murali added*/
typedef uint8 EcuM_ResetType; /*murali added*/

#endif
/*============================================================================
**============================================================================
** R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
**===========================================================================*/
/*---------------------------------------------------------------------------
Date               : 20-Aug-2015
CDSID              : ssukuma1
Traceability       : RTC #396021
Change Description : Initial Framework version of EcuMgr
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 04-Sep-2015
CDSID              : ssukuma1
Traceability       : RTC #398223
Change Description : Start up Ecu Mode Implementation
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 12-Mar-2021
CDSID              : praj1
Traceability       : RTC #1254354
Change Description :  ECUM_STATE_STARTUP_TWO_WAIT state added
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/


