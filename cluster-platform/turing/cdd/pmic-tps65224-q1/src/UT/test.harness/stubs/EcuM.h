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
*  File Name         :  EcuM.h                                               *
*  Module Short Name :  EcuM_H                                               *
*  Description       :                                                       *
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
#ifndef ECUM_H
#define ECUM_H

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "EcuM_Types.h"
#include "EcuM_Cbk.h"
#include "EcuM_Cfg.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
# define ECUM_E_HOOK_CONFIGURATION_DATA_INCONSISTENT                  (Std_ReturnType)(0x08u)

/* Module Id */
#define ECUM_MODULE_ID           10U
/* Instance Id */
#define ECUM_INSTANCE_ID         0U

/* API ID */
#define ECUM_API_ECUM_SHUTDOWN                 2U
#define ECUM_API_ECUM_REQUESTRUN               0x03U
#define ECUM_API_ECUM_RELEASERUN               0x04U
#define ECUM_API_ECUM_REQUESTPOSTRUN           0x0EU
#define ECUM_API_ECUM_RELEASEPOSTRUN           0x0BU
#define ECUM_API_ECUM_GETSHUTDOWNTARGET        0x09U
#define ECUM_API_ECUM_GETLASTSHUTDOWNTARGET    0x08U
#define ECUM_API_ECUM_GETSTATE                 0x07U
#define ECUM_API_ECUM_SETWAKEUPEVENT           0x0CU
#define ECUM_API_ECUM_VALIDATEWAKEUPEVENT      0X14U
#define ECUM_API_ECUM_STATE_APP_POST_RUN       0x15U

/*Error Code*/
#define ECUM_E_MULTIPLE_RUN_REQUESTS   0x19U
#define ECUM_E_MISMATCHED_RUN_RELEASE  0x20U
#define ECUM_E_INV_POINTER             0x14U
#define ECUM_E_PARAM_SEID              0x13U
#define ECUM_E_NO_INIT                 0x10U

/* EcuM Reset Type */
#define ECUM_RESET_MCU           0U
#define ECUM_RESET_WDG           1U
#define ECUM_RESET_IO            2U


#define ECUM_VENDOR_ID            (51u)

#define ECUM_SW_MAJOR_VERSION     (1u)
#define ECUM_SW_MINOR_VERSION	  (0u)
#define ECUM_SW_PATCH_VERSION	  (22u)
#define ECUM_AR_RELEASE_MAJOR_VERSION       4U
#define ECUM_AR_RELEASE_MINOR_VERSION       3U
#define ECUM_AR_RELEASE_REVISION_VERSION    1U

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

#define ECUM_START_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern void EcuM_Init (void);
extern void EcuM_StartupTwo(void);
extern void EcuM_Shutdown(void);
extern Std_ReturnType EcuM_RequestRUN(EcuM_UserType user);
extern Std_ReturnType EcuM_ReleaseRUN(EcuM_UserType user);
extern Std_ReturnType EcuM_RequestPOST_RUN(EcuM_UserType user);
extern Std_ReturnType EcuM_ReleasePOST_RUN(EcuM_UserType user);
extern void EcuM_KillAllRUNRequests(void );
extern void EcuM_KillAllPostRUNRequests( void );
extern Std_ReturnType EcuM_SelectShutdownTarget(EcuM_StateType target,EcuM_SleepModeType mode );
extern Std_ReturnType EcuM_GetShutdownTarget(EcuM_StateType* shutdownTarget,EcuM_SleepModeType* sleepMode );
extern Std_ReturnType EcuM_GetLastShutdownTarget(EcuM_StateType* shutdownTarget,EcuM_SleepModeType* sleepMode);
extern Std_ReturnType EcuM_GetState(EcuM_StateType* state);
extern EcuM_WakeupSourceType EcuM_GetPendingWakeupEvents(void);
extern void EcuM_ClearWakeupEvent( EcuM_WakeupSourceType sources);
extern EcuM_WakeupSourceType EcuM_GetValidatedWakeupEvents( void );
extern EcuM_WakeupSourceType EcuM_GetExpiredWakeupEvents(void);
extern EcuM_WakeupStatusType EcuM_GetStatusOfWakeupSource(EcuM_WakeupSourceType sources);
extern void EcuM_StartCheckWakeup (EcuM_WakeupSourceType WakeupSource );
extern void EcuM_EndCheckWakeup( EcuM_WakeupSourceType WakeupSource);
extern Std_ReturnType EcuM_SelectBootTarget(EcuM_BootTargetType target);
extern Std_ReturnType EcuM_GetBootTarget(EcuM_BootTargetType * target);
extern void EcuM_MainFunction( void );


extern void EcuM_ErrorHook(uint16 reason);
extern void EcuM_AL_DriverInitZero( void );
extern void EcuM_DeterminePbConfiguration( void );
extern void EcuM_AL_DriverInitOne(const EcuM_ConfigType * ConfigPtr);
extern void EcuM_AL_DriverInitTwo(const EcuM_ConfigType * ConfigPtr);
extern void EcuM_AL_DriverInitThree (const EcuM_ConfigType * ConfigPtr);
extern void EcuM_NvmExt_ReadAll_Start (void);
extern void EcuM_OnRTEStartup( void );
extern void EcuM_OnEnterRun (void );
extern void EcuM_OnExitRun( void );
extern void EcuM_OnExitPostRun ( void );
extern void EcuM_OnPrepShutdown( void );
extern void EcuM_OnGoSleep( void );
extern void EcuM_OnGoOffOne( void );
extern void EcuM_OnGoOffTwo( void );
extern void EcuM_ShutdownOS(Std_ReturnType ErrCode);
extern void EcuM_EnableWakeupSources (EcuM_WakeupSourceType wakeupSource );
extern void EcuM_GenerateRamHash( void );
extern void EcuM_AL_SwitchOff( void );
extern void EcuM_DisableWakeupSources(EcuM_WakeupSourceType wakeupSource );
extern void EcuM_AL_DriverRestart(const EcuM_ConfigType * ConfigPtr);
extern void EcuM_StartWakeupSources (EcuM_WakeupSourceType wakeupSource);
extern void EcuM_CheckValidation(EcuM_WakeupSourceType wakeupSource);
extern void EcuM_StopWakeupSources(EcuM_WakeupSourceType wakeupSource );
extern EcuM_WakeupReactionType EcuM_OnWakeupReaction(EcuM_WakeupReactionType wact);
extern void EcuM_SleepActivity ( void );
extern void EcuM_McuSetMode(Mcu_ModeType McuMode);
extern void EcuM_OnEnterSleep (void);
extern void EcuM_OnFailedNvmWriteAllJobReaction(void);
extern void EcuM_AL_Reset(EcuM_ResetType Reset);

#if (ECUM_VERSION_INFO_API == STD_ON)
void EcuM_GetVersionInfo(Std_VersionInfoType* VersionInfo);
#endif

#define ECUM_STOP_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */


















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
Date               : 15-Jun-2023
CDSID              : eganesan
Traceability       : RTC #2043995
Change Description : EcuM 4.3 Migration 
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/


