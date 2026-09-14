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
*  File Name         :  EcuM.c                                               *
*  Module Short Name :  EcuM                                                 *
*  Description       :  This file contains implementations of the Ecu        *
*                       State Manager                                        *
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
#ifndef ECUM_C
#define ECUM_C

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "EcuM.h"
#include "EcuM_PrivateCfg.h"
#include "ComM_EcuMBswM.h"
#include "ComM.h"
#if ((ECUM_INCLUDE_NVM_MGR != FALSE)||(ECUM_INCLUDE_NVM_READALL != FALSE))
#include "NvM.h"
#endif
#include "Rte_EcuM.h"
#include "EcuM_Cfg.h"
#if (ECUM_INCLUDE_BSWM != FALSE)
#include "BswM.h"
#endif

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
# define ECUM_TIMER_NOT_SET                         (0xFFFFu)
# define ECUM_TIMER_EXPIRED                         (0x00u)

#define EcuM_GetModuleState()                       EcuM_InternalParam.ModuleState
#define EcuM_SetModuleState(Value)                  EcuM_GetModuleState() = (EcuM_StateType)Value

#define EcuM_GetTimer()                             EcuM_InternalParam.Timer
#define EcuM_SetTimer(Value)                        EcuM_GetTimer() = (uint16)Value

#define MORE_THAN_1_BITS_RAISED                     ((uint8)255)


#define ECUM_USER_RUN_MASK                          (0x01u)
#define ECUM_USER_POST_RUN_MASK                     (0x02u)

#define ECUM_USER_REQUEST_TYPE                      (0x01u)
#define ECUM_USER_RELEASE_TYPE                      (0x02u)

#if (FALSE != ECUM_INCLUDE_NVM_MGR)

#define ECUM_NVM_WRITEALL_IDLE                      (0x00u)
#define ECUM_NVM_WRITEALL_REQUIRED                  (0x01u)
#define ECUM_NVM_WRITEALL_STARTED                   (0x02u)
#define ECUM_NVM_WRITEALL_CANCELED                  (0x03u)
#define ECUM_NVM_WRITEALL_COMPLETED                 (0x04u) 

#endif
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef struct
{
    EcuM_UserType User;
    uint8 Mask;
    uint8 ApiId;
    uint8* Counter_p;
}EcuM_UserParam_t;

typedef struct
{                                                           /** INIT/UINIT **|*********************Description*******************/
    EcuM_WakeupSourceType   EnabledWakeupSource;            /*  INIT:0       | Holds the enabled wakeup sources                 */
    EcuM_WakeupSourceType   ValidatedWakeups;               /*  INIT:0       | Holds the validated wakeup sources               */
    EcuM_WakeupSourceType   PostedWakeups;                  /*  INIT:0       | Holds the posted wakeup sources                   */
    EcuM_WakeupSourceType   ClearedPostedWakeups;           /*  INIT:0       | Holds the posted wkp sources, that were cleared  */
    EcuM_WakeupSourceType   ExpiredPostedWakeups;           /*  INIT:0       | Holds the posted wkp sources, that were expired  */
    EcuM_WakeupSourceType   ComM_BufferedWakeups;           /*  INIT:0       | Holds wakeups that happened before ComM_Init     */
    uint16                  Timer;                          /*  INIT:FFFFh   | 16-bit Timer variable for EcuM                   */
    EcuM_UserType           Users[ECUM_MAX_CFG_USERS];      /*  INIT:0       | Table of EcuM configured users                   */
    EcuM_StateType          ModuleState;                    /*  INIT:11h     | Holds the current state of the EcuMgr            */
    EcuM_StateType          LastShutdownTarget;             /*  UNITIALIZED  | Shutdown Target that was executed previous       */
    EcuM_StateType          CurrentShutdownTarget;          /*  DEFAULT CFG  | Shutdown Target that has to be executed now      */
    uint8                   LastShutdownMode;               /*  UNITIALIZED  | Shutdown Mode of previous shutdown operation     */
    uint8                   CurrentShutdownMode;            /*  DEFAULT CFG  | Current Shutdown Mode                            */
    uint8                   ShutdownCause;                  /*  INIT:0       | Reason for the last Shutdown                     */
    uint8                   RunRequestCounter;              /*  INIT:0       | Number of users requested for RUN                */
    uint8                   PostRunRequestCounter;          /*  INIT:0       | Number of users requested for POST RUN           */
    uint8                   KillAllRequestStatus;           /*  INIT:0       | Kill All request status                          */
    uint8                   NvMServiceId;                   /*  INIT:0       | NvM Service Id: WriteAll, CancelAll, ReadAll     */
    uint8                   NvMWriteAllStatus;              /*  INIT:IDLE:0  | Status of NvM WriteAll request                   */
    NvM_RequestResultType   NvMJobResult;                   /*  INIT:NOT_OK  | Result of NvM request placed by EcuMgr           */
    boolean                 NvMCbkNotified;                 /*  INIT:FALSE   | Flag to indicate if the NvM callback is issued?  */
    boolean                 NvMCbkReadAllNotified;          /*  INIT:FALSE   | Flag to indicate if the NvM Read All callback    */
}EcuM_ParamType;                                            /********************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
#define ECUM_DATA_SEC_START
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */

static EcuM_ParamType EcuM_InternalParam;

static EcuM_WakeupSrcValidationTime EcuM_ValidationTimeouts[ECUM_MAX_NUM_WAKEUP_SOURCE];

//below statements are required to suppress the coverity warning for inclusion of PrivateCfg.h
#ifndef ECUM_PRIVATE_CFG_REQUIRED
static uint8 EcuM_PrivateCfg;   //reserved for future use with EcuM Private Cfg
#endif

#define ECUM_DATA_SEC_END
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */


static void EcuM_EnterRunState(void);
static void EcuM_StateMachine(void);
static void EcuM_InternalClearWakeupEvent (EcuM_WakeupSourceType WakeupSource);
static Std_ReturnType EcuM_InternalRequestRUN (EcuM_UserParam_t fl_user_param);
static Std_ReturnType EcuM_InternalReleaseRUN (EcuM_UserParam_t fl_user_param);
#if (ECUM_INCLUDE_COMM != FALSE)
static boolean EcuM_QryComMRunRequest (void);
#endif
static void EcuM_InternalKillAllRequests (uint8 mask);
static void EcuM_EnterSleep (void);
static void EcuM_InternalEnterHaltMode (void);
static void EcuM_InternalEnterPollingMode(void);
static void EcuM_InternalWakeupSourcesValidation(void);
static uint8 EcuM_InternalCheckWakupMaskValidity(EcuM_WakeupSourceType wkpSrcMask);
#if (ECUM_INCLUDE_COMM != FALSE)
static void EcuM_InternalBufferedComMNotifications(void);
#endif
#if (ECUM_INCLUDE_NVM_MGR != FALSE)
static boolean EcuM_WaitOnNvMCancelWriteAll (void);
static boolean EcuM_WaitOnNvMWriteAll (void); 
#endif /* NVM MGR Included check */
void EcuM_Init (void);
void EcuM_StartupTwo(void);
extern void EcuM_Shutdown(void);
Std_ReturnType EcuM_RequestRUN(EcuM_UserType user);
Std_ReturnType EcuM_ReleaseRUN(EcuM_UserType user);
Std_ReturnType EcuM_RequestPOST_RUN(EcuM_UserType user);
Std_ReturnType EcuM_ReleasePOST_RUN(EcuM_UserType user);
void EcuM_KillAllRUNRequests(void );
void EcuM_KillAllPostRUNRequests( void );
Std_ReturnType EcuM_SelectShutdownTarget(EcuM_StateType target,EcuM_SleepModeType mode );
Std_ReturnType EcuM_GetShutdownTarget(EcuM_StateType* shutdownTarget,EcuM_SleepModeType* sleepMode );
Std_ReturnType EcuM_GetLastShutdownTarget(EcuM_StateType* shutdownTarget,EcuM_SleepModeType* sleepMode);
Std_ReturnType EcuM_GetState(EcuM_StateType* state);
EcuM_WakeupSourceType EcuM_GetPendingWakeupEvents(void);
void EcuM_ClearWakeupEvent( EcuM_WakeupSourceType sources);
EcuM_WakeupSourceType EcuM_GetValidatedWakeupEvents( void );
EcuM_WakeupSourceType EcuM_GetExpiredWakeupEvents(void);
EcuM_WakeupStatusType EcuM_GetStatusOfWakeupSource(EcuM_WakeupSourceType sources);
void EcuM_StartCheckWakeup (EcuM_WakeupSourceType WakeupSource );
void EcuM_EndCheckWakeup( EcuM_WakeupSourceType WakeupSource);
Std_ReturnType EcuM_SelectBootTarget(EcuM_BootTargetType target);
Std_ReturnType EcuM_GetBootTarget(EcuM_BootTargetType * target);
void EcuM_MainFunction( void );
void EcuM_CB_NfyNvMJobEnd(uint8 ServiceId,NvM_RequestResultType JobResult);


#define ECUM_CODE_SEC_START
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_19.1 */
static FUNC(void, ECUM_CODE_SEC_START) ECUM_REPORT_ERROR(uint8 ApiId, uint8 ErrorId);

/*============================================================================
**
** Function Name    :   EcuM_Init
**
** Visibility       :   Public
**
** Description      :   The Init function is called to initiate the startup 
**                      procedure that takes place before the OS is started
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/

void EcuM_Init (void)
{
    uint8 loop = 0;
    
    
    /* Let other modules know that we are in Startup state */
    EcuM_SetModuleState(ECUM_STATE_STARTUP);
    
    EcuM_AL_DriverInitZero();
    
    EcuM_InternalParam.EnabledWakeupSource = ECUM_WKSOURCE_NONE;
    
    /* Clear wakeups from all sources */
    EcuM_InternalClearWakeupEvent(ECUM_WKSOURCE_ALL_SOURCES);
    
    EcuM_InternalParam.ShutdownCause = 0U;
    EcuM_InternalParam.CurrentShutdownTarget = ECUM_DEFAULT_SHUTDOWN_TARGET;
    
    #if (ECUM_DEFAULT_SHUTDOWN_TARGET >  ECUM_STATE_SLEEP)
    EcuM_InternalParam.CurrentShutdownMode = ECUM_DEFAULT_RESET_MODE_REF;
    #else
    EcuM_InternalParam.CurrentShutdownMode = ECUM_DEFAULT_SLEEP_MODE_REF;
    #endif
    
    EcuM_SetTimer(ECUM_TIMER_NOT_SET);
    
    EcuM_InternalParam.KillAllRequestStatus = 0U;
    EcuM_InternalParam.PostRunRequestCounter = 0U;
    EcuM_InternalParam.RunRequestCounter = 0U;

    #if (ECUM_INCLUDE_NVM_MGR != FALSE)
    EcuM_InternalParam.NvMWriteAllStatus = ECUM_NVM_WRITEALL_IDLE;
    EcuM_InternalParam.NvMCbkNotified = FALSE;
    EcuM_InternalParam.NvMCbkReadAllNotified = FALSE;
    EcuM_InternalParam.NvMJobResult = NVM_REQ_NOT_OK;
    EcuM_InternalParam.NvMServiceId = 0U;
    #endif

    for (loop=0; loop < ECUM_MAX_NUM_WAKEUP_SOURCE; loop++)
    {
        EcuM_ValidationTimeouts[loop] = ECUM_NO_VALIDATION;
    }

    /* WakeupEvents will be posted once the global interrupt is enabled */
    EcuM_InternalParam.ValidatedWakeups = 0U;
    EcuM_InternalParam.PostedWakeups = 0U;
    EcuM_InternalParam.ClearedPostedWakeups = 0U;
    EcuM_InternalParam.ExpiredPostedWakeups = 0U;
    
    for (loop=0; loop < ECUM_MAX_CFG_USERS; loop++)
    {
        EcuM_InternalParam.Users[loop] = 0U;
    }

    /* Set the current state of the EcuM as Startup ONE */
    EcuM_SetModuleState(ECUM_STATE_STARTUP_ONE);

    EcuM_AL_DriverInitOne(ECUM_DRIVER_INIT_LIST_ONE);

    /* We are all set to start the OS now   */
    /* This call will never return          */
    StartOS(ECUM_DEFAULT_APP_MODE);
}

/*============================================================================
**
** Function Name    :   EcuM_StartupTwo
**
** Visibility       :   Public
**
** Description      :   The function implements the startup phase where 
**                      the OS is already running.
**                      This function should be scheduled by a task directly after 
**                      StartOS() and only be called once.
**
** Invocation       :   Function could be called from interrupt level or from task level
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
void EcuM_StartupTwo(void)
{
    /*********************************
        Set state as STARTUP_TWO
        Init SchM and BswM
        Init List 2
        Start RTE
        Init List 3
        Initiate StateMachine
    **********************************/
    
   
    
    /* Initialization of the schedule Manager */
    SchM_Init();
#if (ECUM_INCLUDE_BSWM != FALSE)    
    BswM_Init(ECUM_BSWM_CONFIG_POINTER);
#endif    
    EcuM_AL_DriverInitTwo(ECUM_DRIVER_INIT_LIST_TWO);
    
    EcuM_OnRTEStartup();
    
    (void)Rte_Start();        /* Start Rte */
    EcuM_NvmExt_ReadAll_Start();
    EcuM_SetModuleState(ECUM_STATE_STARTUP_TWO_WAIT);
    /* Call the state machine from here to start EcuM operations */
    EcuM_StateMachine();
}

#if (ECUM_VERSION_INFO_API == TRUE)
/*============================================================================
**
** Function Name    :   EcuM_GetVersionInfo
**
** Visibility       :   Public
**
** Description      :   This function returns the Version informations 
**                      of this module.
**
** Invocation       :   
**
** Inputs           :   Std_VersionInfoType * VersionInfo - Pointer to a VersionInfo type.
**
** Outputs          :   Void
**
** Critical Section :   NA
**
**==========================================================================*/
/*MISRA warning - extern function not used anywhere other than the current source file*/
/*Deviation - This function will be called by other files on the necessity that 
the version of EcuM should be known*/
void EcuM_GetVersionInfo (Std_VersionInfoType* VersionInfo)
{
    if (VersionInfo != NULL_PTR)
	{
        VersionInfo->vendorID         = ECUM_VENDOR_ID;
        VersionInfo->moduleID         = ECUM_MODULE_ID;
        VersionInfo->sw_major_version = ECUM_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = ECUM_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = ECUM_SW_PATCH_VERSION;
    }
}
#endif
/*============================================================================
**
** Function Name    :   EcuM_Shutdown
**
** Visibility       :    Public
**
** Description      :   Typically called from the shutdown hook, this function takes
**                      over execution control and will carry out GO OFF II activities.
**
** Invocation       :   ShutdownHook of the OS
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
void EcuM_Shutdown(void)
{
    EcuM_OnGoOffTwo();

    ECUM_ENTER_CRITICAL_SECTION();
    EcuM_StateType CurrShutdownTarget = EcuM_InternalParam.CurrentShutdownTarget;
    ECUM_EXIT_CRITICAL_SECTION();

    if (CurrShutdownTarget == ECUM_STATE_RESET)
    {
        EcuM_AL_Reset(ECUM_RESET_MCU);
    }
    else if (CurrShutdownTarget == ECUM_STATE_OFF)
    {
        EcuM_AL_SwitchOff();
    }
    else
    {
        ECUM_REPORT_ERROR(ECUM_API_ECUM_SHUTDOWN, EcuM_InternalParam.CurrentShutdownTarget);
    }
}

/*============================================================================
**
** Function Name    :   EcuM_RequestRUN
**
** Visibility       :   Public
**
** Description      :   Places a request for the RUN state. Requests can be placed
**                      by every user known to the state manager at configuration time.
**                      In Development mode ECUM_E_MULTIPLE_RUN_REQUESTS will thrown if
**                      a User requests multiple RUN states
**
** Invocation       :   From Task Level
**
** Inputs           :   User which requests RUN state
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType EcuM_RequestRUN(EcuM_UserType user)
{
    EcuM_UserParam_t fl_user_param;
    Std_ReturnType retval = E_NOT_OK;

    fl_user_param.User = user;
    fl_user_param.ApiId = ECUM_API_ECUM_REQUESTRUN;
    fl_user_param.Mask = ECUM_USER_RUN_MASK;
	ECUM_ENTER_CRITICAL_SECTION();
    fl_user_param.Counter_p = &EcuM_InternalParam.RunRequestCounter;
	ECUM_EXIT_CRITICAL_SECTION();

    retval = EcuM_InternalRequestRUN(fl_user_param);

    return retval;
}

/*============================================================================
**
** Function Name    :   EcuM_ReleaseRUN
**
** Visibility       :   Public
**
** Description      :   Releases a RUN request previously done with a call to EcuM_RequestRUN.
**                      In Development mode the error code ECUM_E_MISMATCHED_RUN_RELEASES will
**                      be thrown if a user releases a RUN state without a matching request.
**
** Invocation       :   Task Level
**
** Inputs           :   User which releases RUN state
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType EcuM_ReleaseRUN(EcuM_UserType user)
{
    EcuM_UserParam_t fl_user_param;
    Std_ReturnType retval = E_NOT_OK;

    fl_user_param.User = user;
    fl_user_param.ApiId = ECUM_API_ECUM_RELEASERUN; 
    fl_user_param.Mask = ECUM_USER_RUN_MASK;
	ECUM_ENTER_CRITICAL_SECTION();
    fl_user_param.Counter_p = &EcuM_InternalParam.RunRequestCounter;
	ECUM_EXIT_CRITICAL_SECTION();

    retval = EcuM_InternalReleaseRUN(fl_user_param);

    return retval;
}

/*============================================================================
**
** Function Name    :   EcuM_RequestPOST_RUN
**
** Visibility       :   Public
**
** Description      :   Places a request for the POST RUN state. Requests can be placed
**                      for every user known to the state manager at configuration time.
**                      In Development mode ECUM_E_MULTIPLE_RUN_REQUESTS will thrown if a
**                      User requests multiple POST RUN states.
**
** Invocation       :
**
** Inputs           :   User which requests POST RUN
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType EcuM_RequestPOST_RUN(EcuM_UserType user)
{
    EcuM_UserParam_t fl_user_param;
    Std_ReturnType retval = E_NOT_OK;

    fl_user_param.User = user;
    fl_user_param.ApiId = ECUM_API_ECUM_REQUESTPOSTRUN; 
    fl_user_param.Mask = ECUM_USER_POST_RUN_MASK;
	ECUM_ENTER_CRITICAL_SECTION();
    fl_user_param.Counter_p = &EcuM_InternalParam.PostRunRequestCounter;
	ECUM_EXIT_CRITICAL_SECTION();

    retval = EcuM_InternalRequestRUN(fl_user_param);

    return retval;
}


/*============================================================================
**
** Function Name    :   EcuM_ReleasePOST_RUN
**
** Visibility       :   Public
**
** Description      :   Releases a POST RUN request previously done with a call
**                      to EcuM_RequestPOST_RUN().
**                      In Development mode the error code ECUM_E_MISMATCHED_RUN_RELEASES
**                      will be thrown if a user releases a RUN  state without a matching request.
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType EcuM_ReleasePOST_RUN(EcuM_UserType user)
{
    EcuM_UserParam_t fl_user_param;
    Std_ReturnType retval = E_NOT_OK;

    fl_user_param.User = user;
    fl_user_param.ApiId = ECUM_API_ECUM_RELEASEPOSTRUN; 
    fl_user_param.Mask = ECUM_USER_POST_RUN_MASK;
	ECUM_ENTER_CRITICAL_SECTION();
    fl_user_param.Counter_p = &EcuM_InternalParam.PostRunRequestCounter;
	ECUM_EXIT_CRITICAL_SECTION();

    retval = EcuM_InternalReleaseRUN(fl_user_param);

    return retval;

}

/*============================================================================
**
** Function Name    :   EcuM_InternalRequestRUN
**
** Visibility       :   Local to EcuM
**
** Description      :   Called whenever RUN or POST_RUN request is called
**
** Invocation       :   EcuM_RequestRUN() or EcuM_RequestPOST_RUN()
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
static Std_ReturnType EcuM_InternalRequestRUN (EcuM_UserParam_t fl_user_param)
{
    Std_ReturnType retval = E_NOT_OK;

    if (fl_user_param.User < ECUM_MAX_CFG_USERS)
    {
        /* Check if there is no KillAllRequest of either RUN or POST_RUN */
		ECUM_ENTER_CRITICAL_SECTION();
        if ((EcuM_InternalParam.KillAllRequestStatus & fl_user_param.Mask) == 0U)
        {
			ECUM_EXIT_CRITICAL_SECTION();
            if ((EcuM_InternalParam.Users[fl_user_param.User] & fl_user_param.Mask) == 0U)
            {
                EcuM_InternalParam.Users[fl_user_param.User] |= fl_user_param.Mask;
				if(*(fl_user_param.Counter_p) < 0xFFU)
				{
                (*(fl_user_param.Counter_p))++;
				}
				else
				{
                    ECUM_REPORT_ERROR(fl_user_param.ApiId,ECUM_E_MULTIPLE_RUN_REQUESTS);
				}
                retval = E_OK;
            }
        }
		else
		{
		ECUM_EXIT_CRITICAL_SECTION();
		}
    }

    return retval;
}

/*============================================================================
**
** Function Name    :   EcuM_InternalReleaseRUN
**
** Visibility       :   Local to EcuM
**
** Description      :   Called whenever RUN or POST_RUN release is called
**
** Invocation       :   EcuM_ReleaseRUN() and EcuM_ReleasePOST_RUN
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
static Std_ReturnType EcuM_InternalReleaseRUN (EcuM_UserParam_t fl_user_param)
{
    Std_ReturnType retval = E_NOT_OK;
    
    if (fl_user_param.User < ECUM_MAX_CFG_USERS)
    {
        /* Check if a RUN or POST_RUN request is already placed for this user */
        if ((EcuM_InternalParam.Users[fl_user_param.User] & fl_user_param.Mask) != 0U)
        {
            EcuM_InternalParam.Users[fl_user_param.User] &= (EcuM_UserType)(~fl_user_param.Mask);
            
            if (0u < *(fl_user_param.Counter_p))
            {
                (*(fl_user_param.Counter_p))--;
                retval = E_OK;
            }
			else
			{
                ECUM_REPORT_ERROR(fl_user_param.ApiId,ECUM_E_MISMATCHED_RUN_RELEASE);
			}
        }
    }
    
    return retval;
}
/*============================================================================
**
** Function Name    :   EcuM_KillAllRUNRequests
**
** Visibility       :   Public
**
** Description      :   The consequence of a call to this service is that the 
**                      shutdown sequence will be initiated.
**                      Use this function with care. Side affects may occur in the Applications
**
** Invocation       :   Should be called only by ComM (Communication Manager)
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
void EcuM_KillAllRUNRequests(void )
{
    EcuM_InternalKillAllRequests (ECUM_USER_RUN_MASK);
}

/*============================================================================
**
** Function Name    :   EcuM_KillAllPostRUNRequests
**
** Visibility       :   Public
**
** Description      :   The consequence of a call to this service is that the
**                      shutdown sequence will be initiated. Use this function with care.
**                      Side affects may occur in the Applications.
**
** Invocation       :   Should be called only by ComM (Communication Manager)
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
void EcuM_KillAllPostRUNRequests( void )
{
    EcuM_InternalKillAllRequests (ECUM_USER_POST_RUN_MASK);
}

/*============================================================================
**
** Function Name    :   EcuM_InternalKillAllRequests
**
** Visibility       :   Local to EcuM
**
** Description      :   Called whenever KillAll RUN or POST_RUN request is called
**
** Invocation       :   By EcuM KillAllRUN/POST_RUN User Request
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
static void EcuM_InternalKillAllRequests (uint8 mask)
{
    EcuM_UserType user = 0; 
    
    /* Let the Internal flag know that there is a KillAll Request */
	ECUM_ENTER_CRITICAL_SECTION();
    EcuM_InternalParam.KillAllRequestStatus |= mask;
    ECUM_EXIT_CRITICAL_SECTION();
    /* Clear all run/post_run status of each users */
    for (user=0; user < ECUM_MAX_CFG_USERS; user++)
    {
        EcuM_InternalParam.Users[user] &= (EcuM_UserType)(~mask);
    }
    
    if (mask == ECUM_USER_RUN_MASK)
    {
        /* 1. Clear Run request counter
           2. Clear all wakeup events
           3. Clear EcuM_Timer
        */
        ECUM_ENTER_CRITICAL_SECTION();
        EcuM_InternalParam.RunRequestCounter = 0;
        ECUM_EXIT_CRITICAL_SECTION();
        EcuM_ClearWakeupEvent(ECUM_WKSOURCE_ALL_SOURCES);
        
        if (EcuM_GetModuleState() == ECUM_STATE_APP_RUN)
        {
            EcuM_SetTimer(ECUM_TIMER_EXPIRED);
        }
    } /* end if kill all run requests*/
    else
    {
        /* clear post run request counter */
		ECUM_ENTER_CRITICAL_SECTION();
        EcuM_InternalParam.PostRunRequestCounter = 0;
        ECUM_EXIT_CRITICAL_SECTION();
    }
/* end if kill all post run requests */
}

/*============================================================================
**
** Function Name    :   EcuM_SelectShutdownTarget
**
** Visibility       :   Public
**
** Description      :   Selects a new Shutdown Target for an intended Restart
**
** Invocation       :   Called from Interrupt or Task Level
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType EcuM_SelectShutdownTarget(EcuM_StateType target,EcuM_SleepModeType mode )
{
    Std_ReturnType retval = E_NOT_OK;
    
    if (EcuM_GetModuleState() > ECUM_STATE_APP_RUN)
    {
        /* Check if the parameters are valid states and in case with the correct modes
        * if (STATE == RESET AND ResetMode in Range) OR
        *     STATE == SLEEP AND SleepMode in Range OR
        *     STATE == OFF)
        */
        if ((((target == (EcuM_StateType)ECUM_STATE_RESET) && (mode < ECUM_MAX_RESET_MODE)) || \
            ((target == (EcuM_StateType)ECUM_STATE_SLEEP) && (mode < ECUM_SLEEP_MODE_MAX))) || \
            (target == (EcuM_StateType)ECUM_STATE_OFF))
        {
			ECUM_ENTER_CRITICAL_SECTION();
            EcuM_InternalParam.CurrentShutdownTarget = target;
			ECUM_EXIT_CRITICAL_SECTION();
        
            if (target == (EcuM_StateType)ECUM_STATE_OFF)
            {
                mode = 0;       /* keep mode as 0 if target is OFF */
            }
            ECUM_ENTER_CRITICAL_SECTION();
            EcuM_InternalParam.CurrentShutdownMode = mode;
			ECUM_EXIT_CRITICAL_SECTION();
        
            retval = E_OK;
        }
    }
    return retval;
}

/*============================================================================
**
** Function Name    :   EcuM_GetShutdownTarget
**
** Visibility       :   Public
**
** Description      :   Returns the actual chosen shutdown target
**
** Invocation       :   Called from Interrupt or Task Level
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType EcuM_GetShutdownTarget(EcuM_StateType* shutdownTarget,EcuM_SleepModeType* sleepMode )
{
    Std_ReturnType retval = E_NOT_OK;

    if ((shutdownTarget == NULL) || (sleepMode == NULL))
    {
        ECUM_REPORT_ERROR(ECUM_API_ECUM_GETSHUTDOWNTARGET,ECUM_E_INV_POINTER);
    }
    else
    {
		ECUM_ENTER_CRITICAL_SECTION();
        *shutdownTarget = EcuM_InternalParam.CurrentShutdownTarget;
        *sleepMode      = EcuM_InternalParam.CurrentShutdownMode;
		ECUM_EXIT_CRITICAL_SECTION();
        retval = E_OK;
    }
    return retval;
}

/*============================================================================
**
** Function Name    :   EcuM_GetLastShutdownTarget
**
** Visibility       :   Public
**
** Description      :   Returns the shutdown target set before the last reset
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType EcuM_GetLastShutdownTarget(EcuM_StateType* shutdownTarget,EcuM_SleepModeType* sleepMode)
{
    Std_ReturnType retval = E_NOT_OK;

    if ((shutdownTarget == NULL) || (sleepMode == NULL))
    {
        ECUM_REPORT_ERROR(ECUM_API_ECUM_GETLASTSHUTDOWNTARGET,ECUM_E_INV_POINTER);
    }
    else
    {
		ECUM_ENTER_CRITICAL_SECTION();
        *shutdownTarget = EcuM_InternalParam.LastShutdownTarget;
        *sleepMode      = EcuM_InternalParam.LastShutdownMode;
		ECUM_EXIT_CRITICAL_SECTION();
        retval = E_OK;
    }
    return retval;}

/*============================================================================
**
** Function Name    :   EcuM_GetState
**
** Visibility       :   Public
**
** Description      :   Returns the current module state of the ECUM
**
** Invocation       :   Function could be called from task level
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType EcuM_GetState(EcuM_StateType* state)
{
    Std_ReturnType retval = E_NOT_OK;
    
    if (state == NULL)
    {

       ECUM_REPORT_ERROR(ECUM_API_ECUM_GETSTATE,ECUM_E_INV_POINTER);
    
    }
    else
    {
        *state = EcuM_GetModuleState();
        retval = E_OK;
    }

    return retval;
}

/*============================================================================
**
** Function Name    :   EcuM_GetPendingWakeupEvents
**
** Visibility       :   Public
**
** Description      :   Returns wakeup events which have been set but not yet validated
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section : Yes
**
**==========================================================================*/
EcuM_WakeupSourceType EcuM_GetPendingWakeupEvents(void)
{
    EcuM_WakeupSourceType RetVal = 0;

    ECUM_ENTER_CRITICAL_SECTION();
    RetVal = EcuM_InternalParam.PostedWakeups;
    ECUM_EXIT_CRITICAL_SECTION();

    return RetVal;
}
/*============================================================================
**
** Function Name    :   EcuM_ClearWakeupEvent
**
** Visibility       :   Public
**
** Description      :   API which clears all pending, validated, checkWakeup 
**                      and expired wakeup events
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
void EcuM_ClearWakeupEvent( EcuM_WakeupSourceType sources)
{
    EcuM_InternalClearWakeupEvent(sources);
}

/*============================================================================
**
** Function Name    :   EcuM_GetValidatedWakeupEvents
**
** Visibility       :   Public
**
** Description      :   Return the wakeup source where the wakeup validation 
**                      was successful
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
EcuM_WakeupSourceType EcuM_GetValidatedWakeupEvents( void )
{
    EcuM_WakeupSourceType RetVal = 0;

    ECUM_ENTER_CRITICAL_SECTION();
    RetVal = EcuM_InternalParam.ValidatedWakeups;
    ECUM_EXIT_CRITICAL_SECTION();

    return RetVal;
}

/*============================================================================
**
** Function Name    :   EcuM_GetExpiredWakeupEvents
**
** Visibility       :   Public
**
** Description      :   Returns all events that have been set and for which
**                      validation has failed.
**                      Events which do not need validation must never be reported by this service
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
EcuM_WakeupSourceType EcuM_GetExpiredWakeupEvents(void)
{
    return ECUM_WKSOURCE_NONE;
}

/*============================================================================
**
** Function Name    :   EcuM_GetStatusOfWakeupSource
**
** Visibility       :   Public
**
** Description      :   Returns the status of the passed wakeup sources
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
EcuM_WakeupStatusType EcuM_GetStatusOfWakeupSource(EcuM_WakeupSourceType sources)
{
    (void)sources;
    return ECUM_WKSTATUS_NONE;
}

/*============================================================================
**
** Function Name    :   EcuM_StartCheckWakeup
**
** Visibility       :   Public
**
** Description      :   Start the timeout mechanism for check wakeup
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
void EcuM_StartCheckWakeup (EcuM_WakeupSourceType WakeupSource )
{
    (void)WakeupSource;
    /* No Implementation, just for Autosar public API compatibility */
    return;
}

/*============================================================================
**
** Function Name    :   EcuM_EndCheckWakeup
**
** Visibility       :   Public
**
** Description      :   Stops the timeout mechanism for check wakeup 
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
void EcuM_EndCheckWakeup( EcuM_WakeupSourceType WakeupSource)
{
    (void)WakeupSource;
    /* No Implementation, just for Autosar public API compatibility */
    return;
}

/*============================================================================
**
** Function Name    :   EcuM_SelectBootTarget
**
** Visibility       :   Public
**
** Description      :   Sets the boot target for the next boot
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType EcuM_SelectBootTarget(EcuM_BootTargetType target)
{
    (void)target;
    return E_NOT_OK;
}

/*============================================================================
**
** Function Name    :   EcuM_GetBootTarget
**
** Visibility       :   Public
**
** Description      :   Returns the current selected boot target of the ECU
**
** Invocation       :
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
Std_ReturnType EcuM_GetBootTarget(EcuM_BootTargetType * target)
{
    (void)target;
    return E_NOT_OK;
}

/*============================================================================
**
** Function Name    :   EcuM_MainFunction
**
** Visibility       :   Public
**
** Description      :   The service which implements all activities of the 
**                      ECU state Manager while OS is up and running. In the
**                      MainFunction the wakeup validation is handled.
**
** Invocation       :   Function Could be called from task Level . Called by SchM
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
void EcuM_MainFunction( void )
{
    
    /* If comM is enabled, then process the buffered comM wakeups */
    /*
        If Run Timer started, then decrement it.
        Perform StateMachine execution till there is a transition
    */
    
    if ((EcuM_GetTimer() != ECUM_TIMER_NOT_SET) && (EcuM_GetTimer() != ECUM_TIMER_EXPIRED))
    {
		ECUM_ENTER_CRITICAL_SECTION();
        EcuM_InternalParam.Timer--;
		ECUM_EXIT_CRITICAL_SECTION();
    }
#if (ECUM_INCLUDE_COMM != FALSE)    
    EcuM_InternalBufferedComMNotifications();
#endif
    EcuM_InternalWakeupSourcesValidation();

    EcuM_StateMachine();
}

#if ((ECUM_INCLUDE_NVM_MGR != FALSE)||(ECUM_INCLUDE_NVM_READALL != FALSE))
/*============================================================================
**
** Function Name    :   EcuM_CB_NfyNvMJobEnd
**
** Visibility       :   Public
**
** Description      :   Callback-function which is used to indicate the Jobend
**                      (in this case NvM_WriteAll() is relevant)
**
** Invocation       :   from interrupt level or from task level
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :   EcuM_Init() must be called before
**
**==========================================================================*/
void EcuM_CB_NfyNvMJobEnd(uint8 ServiceId,NvM_RequestResultType JobResult)
{
	ECUM_ENTER_CRITICAL_SECTION();
    EcuM_InternalParam.NvMServiceId = ServiceId;
    EcuM_InternalParam.NvMJobResult = JobResult;
	ECUM_EXIT_CRITICAL_SECTION();
    if ((ServiceId == NVM_WRITE_ALL) || (ServiceId == NVM_CANCEL_WRITE_ALL))
    {
		ECUM_ENTER_CRITICAL_SECTION();
        //Set tje Cbk flag only for Write All or Cancel Write All
        EcuM_InternalParam.NvMCbkNotified = TRUE;
		ECUM_EXIT_CRITICAL_SECTION();
    }
    if (ServiceId == NVM_READ_ALL) 
    {
        EcuM_InternalParam.NvMCbkReadAllNotified = TRUE;
    }
}
#endif

/*============================================================================
**
** Function Name    :   EcuM_SetWakeupEvent
**
** Visibility       :   Public
**
** Description      :   Marks a wakeupevent as pending if validation is required.
**                      EcuM_ValidateSetWakeupEvent will be called within this function.
**
** Invocation       :   from interrupt level or from task level
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
void EcuM_SetWakeupEvent(EcuM_WakeupSourceType sources)
{
    uint8 wkpSrcId = MORE_THAN_1_BITS_RAISED;

    /* validate input */
    wkpSrcId = EcuM_InternalCheckWakupMaskValidity(sources);

    /* input is valid if only 1 bit is raised and its id is lower than max wakeup */
    if (((wkpSrcId > ECUM_STD_WAKEUPS_COUNT) || (sources == ECUM_WKSOURCE_RESET)) && (wkpSrcId<ECUM_MAX_NUM_WAKEUP_SOURCE))
    {
        ECUM_ENTER_CRITICAL_SECTION();

        /* if wakeup source is not yet in posted wakeup list */
        if ((EcuM_InternalParam.PostedWakeups & sources) == ECUM_WKSOURCE_NONE)
        {
            /* remove it from cleared posted list */
            EcuM_InternalParam.ClearedPostedWakeups &= (~sources);

            /* does it need validation */
            if (EcuM_WakeupSourceList[wkpSrcId].ValidationTime != ECUM_NO_VALIDATION)
            {
                /* Mark the wakeup source as a non-validated Wakeup source */
                EcuM_InternalParam.PostedWakeups |= sources;

#if (ECUM_INCLUDE_BSWM != FALSE)
                BswM_EcuM_CurrentWakeup(sources, ECUM_WKSTATUS_PENDING);
#endif

                /*init timeout, real value takes place in following EcuM_MainFunction */
                EcuM_ValidationTimeouts[wkpSrcId] = ECUM_NO_VALIDATION;

                ECUM_EXIT_CRITICAL_SECTION();
            }
            /* it does not need validation */
            else
            {
                ECUM_EXIT_CRITICAL_SECTION();

                EcuM_ValidateWakeupEvent(sources);
            }
        }
        /* wakeup source is already posted */
        else
        {
            ECUM_EXIT_CRITICAL_SECTION();
            /* do nothing */
        }
    }
    /* input is invalid */
    else
    {
        ECUM_REPORT_ERROR(ECUM_API_ECUM_SETWAKEUPEVENT,ECUM_E_PARAM_SEID);
    }
}

/*============================================================================
**
** Function Name    :   EcuM_ValidateWakeupEvent
**
** Visibility       :   Public
**
** Description      :   After wakeup, the ECU State Manager will stop the process
**                      during the WAKEUP VALIDATION state to wait for validation
**                      of the wakeup event. 
**                      The validation is carried out with a call to this API service.
**
** Invocation       :   rom interrupt level or from task level
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
void EcuM_ValidateWakeupEvent(EcuM_WakeupSourceType sources)
{
    uint8 wkpSrcId = MORE_THAN_1_BITS_RAISED;

    /* validate input */
    wkpSrcId = EcuM_InternalCheckWakupMaskValidity(sources);

    /* input is valid if only 1 bit is raised and its id is lower than max wakeup */
    if (wkpSrcId < ECUM_MAX_NUM_WAKEUP_SOURCE)
    {
        ECUM_ENTER_CRITICAL_SECTION();

        /* Register the validated wakeup source */
        EcuM_InternalParam.ValidatedWakeups |= sources;

        /* Intimate BSWM Current Wakeup as validated */
#if (ECUM_INCLUDE_BSWM != FALSE)
        if(EcuM_GetModuleState() > ECUM_STATE_STARTUP_TWO)
        {
          BswM_EcuM_CurrentWakeup(sources, ECUM_WKSTATUS_VALIDATED);
          /* Defect id - DICVA-14997 */
        }
#endif

#if (ECUM_INCLUDE_COMM != FALSE)
        /* If ComM channel is related, notify ComM for wakeup */
        if (EcuM_WakeupSourceList[wkpSrcId].Channel != ECUM_NO_COMM_CHANNEL)
        {
            ComM_InitStatusType ComMStatus;
            Std_ReturnType retVal;
            retVal = ComM_GetStatus(&ComMStatus);
            if ((retVal == E_OK) && (ComMStatus == COMM_INIT))
            {
                ComM_EcuM_WakeUpIndication(EcuM_WakeupSourceList[wkpSrcId].Channel);
            }
            else
            {
                /* buffer the wakeup, until ComM gets initialized */
                EcuM_InternalParam.ComM_BufferedWakeups |= ((EcuM_WakeupSourceType)(sources));
            }
        }
#endif

        /* Remove wakeup from Pending wakeup List */
        EcuM_InternalParam.PostedWakeups &= (EcuM_WakeupSourceType)(~sources);

        /* init timeout */
        EcuM_ValidationTimeouts[wkpSrcId] = ECUM_NO_VALIDATION;

        ECUM_EXIT_CRITICAL_SECTION();
    }
    /* input is invalid */
    else
    {
        ECUM_REPORT_ERROR(ECUM_API_ECUM_VALIDATEWAKEUPEVENT,ECUM_E_PARAM_SEID);
    }
}


/*============================================================================
**
** Function Name    :   EcuM_StateMachine
**
** Visibility       :   Public
**
** Description      :   Statemachine of EcuM for fixed behavior
**
** Invocation       :   From EcuM_MainFunction
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
static void EcuM_StateMachine (void)
{
    #if (ECUM_COMM_COMMUNICATION_ALLOWED != FALSE)
    uint8 loop = 0;
    #endif

    switch (EcuM_GetModuleState())
    {
        case ECUM_STATE_STARTUP_TWO_WAIT:
        {
            if (EcuM_InternalParam.NvMCbkReadAllNotified != FALSE)
            {
				ECUM_ENTER_CRITICAL_SECTION();
                EcuM_InternalParam.NvMCbkNotified = FALSE; 
				ECUM_EXIT_CRITICAL_SECTION();
                EcuM_AL_DriverInitThree(ECUM_DRIVER_INIT_LIST_THREE);

                EcuM_SetModuleState(ECUM_STATE_STARTUP_TWO);
            }
            else
            {
                EcuM_SetModuleState(ECUM_STATE_STARTUP_TWO_WAIT);
            }
            break;
        }
        
        case ECUM_STATE_STARTUP_TWO:
        {
			ECUM_ENTER_CRITICAL_SECTION();
            if (EcuM_InternalParam.ValidatedWakeups != 0U)
            {
				ECUM_EXIT_CRITICAL_SECTION();
                EcuM_EnterRunState();
            }
            else
            {
				ECUM_EXIT_CRITICAL_SECTION();
               /* no validated wake up event notified, change to wakeup validation */
               EcuM_SetModuleState(ECUM_STATE_WAKEUP_VALIDATION);
            }
            break;
        
        
        }
        /**********************************************************
         * RUN STATE
         *********************************************************/
        case ECUM_STATE_APP_RUN:
        {
			ECUM_ENTER_CRITICAL_SECTION();
            if ((EcuM_InternalParam.RunRequestCounter == 0U)
#if (ECUM_INCLUDE_COMM != FALSE)
                && (EcuM_QryComMRunRequest() == FALSE)
#endif
                && (EcuM_GetTimer() == ECUM_TIMER_EXPIRED))
            {
                /* proceed to shutdown state */
                /* Defect id - DICVA-14987 */
                /* No pending wakeup is present - wakeups can be cleared */
				ECUM_EXIT_CRITICAL_SECTION();
                EcuM_ClearWakeupEvent(ECUM_WKSOURCE_ALL_SOURCES);

                #if (ECUM_COMM_COMMUNICATION_ALLOWED != FALSE)
                /* If com allowed list exists, set communication of all com channels */
                for (loop=0; loop < ECUM_COMM_MAX_ALLOWED_LIST; loop++)
                {
                    /* Set communication of all ComM channels to allowed when enter run state */
                    ComM_CommunicationAllowed(EcuM_ComMAllowedChannels[loop], FALSE);
                }
                #endif
                EcuM_OnExitRun();
                (void)EcuM_Rte_Call_Switch_currentMode(RTE_MODE_EcuM_Mode_POST_RUN);
                EcuM_SetModuleState(ECUM_STATE_APP_POST_RUN);
            }
			else
			{
			ECUM_EXIT_CRITICAL_SECTION();
			}
            break;
        }
        /**********************************************************
         * POST RUN STATE
         *********************************************************/
        case ECUM_STATE_APP_POST_RUN:
        {
			ECUM_ENTER_CRITICAL_SECTION();
            if ((EcuM_InternalParam.RunRequestCounter != 0U)
#if (ECUM_INCLUDE_COMM != FALSE)
                || (EcuM_QryComMRunRequest() != FALSE)
#endif
                || (EcuM_InternalParam.ValidatedWakeups != 0U))
            {
				ECUM_EXIT_CRITICAL_SECTION();
                /* Transit to Run */
                EcuM_EnterRunState();
            }
            else if (EcuM_InternalParam.PostRunRequestCounter == 0U)
            {
                #if (ECUM_INCLUDE_NVM_MGR != FALSE)
                /* Mark that NvM_WriteAll must be performed, caused by pending data */
                EcuM_InternalParam.NvMWriteAllStatus = ECUM_NVM_WRITEALL_REQUIRED;                
                #endif
				ECUM_EXIT_CRITICAL_SECTION();
                /* Transit to PrepShutdown */
                EcuM_OnExitPostRun();

                /* Transit to Prep Shutdown */
                EcuM_SetModuleState(ECUM_STATE_PREP_SHUTDOWN);
            }
			else
			{
				ECUM_EXIT_CRITICAL_SECTION();
                ECUM_REPORT_ERROR(ECUM_API_ECUM_STATE_APP_POST_RUN,ECUM_E_NO_INIT);
            }
            break;
        }
        /**********************************************************
         * PREPARE SHUTDOWN STATE
         *********************************************************/
        case ECUM_STATE_PREP_SHUTDOWN:
        {
            EcuM_OnPrepShutdown();
            ECUM_ENTER_CRITICAL_SECTION();
            if (EcuM_InternalParam.CurrentShutdownTarget == ECUM_STATE_SLEEP)
            {
				ECUM_EXIT_CRITICAL_SECTION();
                /* Transit to Go Sleep */
                EcuM_SetModuleState(ECUM_STATE_GO_SLEEP);
                EcuM_OnGoSleep();
            }
            else
            {
				ECUM_EXIT_CRITICAL_SECTION();
                EcuM_SetModuleState(ECUM_STATE_GO_OFF_ONE);
                EcuM_OnGoOffOne();
                /* Transit to Go Off */
            }
            break;
        }
        /**********************************************************
         * GO SLEEP STATE
         *********************************************************/
        case ECUM_STATE_GO_SLEEP:
        {
			ECUM_ENTER_CRITICAL_SECTION();
            if (EcuM_InternalParam.ValidatedWakeups != 0U)
            {
				ECUM_EXIT_CRITICAL_SECTION();
                #if (ECUM_INCLUDE_NVM_MGR != FALSE)
                    (void)EcuM_WaitOnNvMCancelWriteAll();
                #endif
                /* Transit to Wakeup Validation */
                EcuM_SetModuleState(ECUM_STATE_WAKEUP_VALIDATION);
            }
            #if (ECUM_INCLUDE_NVM_MGR != FALSE)
            else if (FALSE != EcuM_WaitOnNvMWriteAll())
            {
				ECUM_EXIT_CRITICAL_SECTION();
                /* Wait for Callback from NVM for WriteAll */
            }
            #endif
            else
            {
				ECUM_EXIT_CRITICAL_SECTION();
                EcuM_OnEnterSleep();
                /* Transit to Sleep */
                EcuM_SetModuleState(ECUM_STATE_SLEEP);
            }
            break;
        }
        /**********************************************************
         * SLEEP STATE
         *********************************************************/
        case ECUM_STATE_SLEEP:
        {
            /* Clear all KillAll Requests */
			ECUM_ENTER_CRITICAL_SECTION();
            EcuM_InternalParam.KillAllRequestStatus = 0u;
			
            if (EcuM_InternalParam.CurrentShutdownTarget == ECUM_STATE_SLEEP)
            {
				ECUM_EXIT_CRITICAL_SECTION();
                (void)EcuM_Rte_Call_Switch_currentMode(RTE_MODE_EcuM_Mode_SLEEP);
                EcuM_EnterSleep();
            }
            else
            {
				ECUM_EXIT_CRITICAL_SECTION();
                /* Defect id - DICVA-14999 */
            }
            /* Transit to Wakeup Validation */
            EcuM_SetModuleState(ECUM_STATE_WAKEUP_VALIDATION);
            break;
        }
        case ECUM_STATE_WAKEUP_VALIDATION:
        {
			ECUM_ENTER_CRITICAL_SECTION();
        #ifdef ECUM_WKSOURCE_INTERNAL_GPT
            if (FALSE != (EcuM_InternalParam.ValidatedWakeups & ECUM_WKSOURCE_INTERNAL_GPT))
            {
				
                EcuM_InternalParam.ValidatedWakeups &= (~ECUM_WKSOURCE_INTERNAL_GPT);
                ECUM_EXIT_CRITICAL_SECTION();
                EcuM_SleepActivity();
                
                /* Transit to Go Sleep */
                EcuM_SetModuleState(ECUM_STATE_GO_SLEEP);
            }
            else
        #endif
            {
                /* If any wakeup validated OR no more posted wakeups */
                if ((EcuM_InternalParam.ValidatedWakeups != ECUM_WKSOURCE_NONE) ||
                    (EcuM_InternalParam.PostedWakeups == ECUM_WKSOURCE_NONE))
                {
					ECUM_EXIT_CRITICAL_SECTION();
                    /* Transit to Wakeup Reaction */
                    EcuM_SetModuleState(ECUM_STATE_WAKEUP_REACTION);
                    (void)EcuM_OnWakeupReaction(ECUM_WKACT_RUN);
                }
				else
				{
				ECUM_EXIT_CRITICAL_SECTION();
				}
            }
            break;
        }
        case ECUM_STATE_WAKEUP_REACTION:
        {
        #if (ECUM_INCLUDE_NVM_MGR != FALSE)
            /* Wait for Cancel NVM Write all */
            if (FALSE == EcuM_WaitOnNvMCancelWriteAll())
            {

            }
            else
        #endif
            {
				ECUM_ENTER_CRITICAL_SECTION();
                /* Cancel WriteAll done */
                if (EcuM_InternalParam.ValidatedWakeups != ECUM_WKSOURCE_NONE)
                {
					ECUM_EXIT_CRITICAL_SECTION();
                    /* Transit to RUN state*/
                    EcuM_EnterRunState();
                }
                else
                {
					ECUM_EXIT_CRITICAL_SECTION();
                    /* Transit to WAKESLEEP state*/
                    EcuM_SetModuleState(ECUM_STATE_WAKEUP_WAKESLEEP);
                }
            }
            break;
        }
        case ECUM_STATE_WAKEUP_WAKESLEEP:
        {
			ECUM_ENTER_CRITICAL_SECTION();
            #if (ECUM_INCLUDE_NVM_MGR != FALSE)
            /* Mark that NvM_WriteAll must be performed */		    
            EcuM_InternalParam.NvMWriteAllStatus = ECUM_NVM_WRITEALL_REQUIRED;
			
            #endif
            if (EcuM_InternalParam.CurrentShutdownTarget == ECUM_STATE_SLEEP)
            {
				ECUM_EXIT_CRITICAL_SECTION();
                /* Transit to Go Sleep */
                EcuM_SetModuleState(ECUM_STATE_GO_SLEEP);
                EcuM_OnGoSleep();
            }
            else
            {
				ECUM_EXIT_CRITICAL_SECTION();
                EcuM_SetModuleState(ECUM_STATE_GO_OFF_ONE);
                EcuM_OnGoOffOne();
                /* Transit to Go Off */
            }
			
            break;
        }
        case ECUM_STATE_GO_OFF_ONE:
        {
            (void)EcuM_Rte_Call_Switch_currentMode(RTE_MODE_EcuM_Mode_SHUTDOWN);
            #if (ECUM_INCLUDE_NVM_MGR != FALSE)
            if (FALSE == EcuM_WaitOnNvMWriteAll())
            {
                //Go Ahead to shutdown if No NvMWriteAll is pending
                (void)Rte_Stop();
                #if (ECUM_INCLUDE_COMM != FALSE)
                    ComM_DeInit();
                #endif

                EcuM_ShutdownOS(E_OK);
                
                /* Transit to Error State, if EcuM_ShutdownOS returns */
                EcuM_SetModuleState(ECUM_STATE_ERROR);
            }
            #endif
            break;
        }
        default:
        {
            ECUM_REPORT_ERROR(ECUM_API_ECUM_STATE,ECUM_INVALID_STATE);
            EcuM_ErrorHook(0);
            break;
        }
        
    }
}

/*============================================================================
**
** Function Name    :   EcuM_InternalClearWakeupEvent
**
** Visibility       :   Local to EcuM
**
** Description      :   To initialize the pending, validated and the expired variable.
**
** Invocation       :   From EcuM_Init() and EcuM_ClearWakeupEvent()
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/

static void EcuM_InternalClearWakeupEvent (EcuM_WakeupSourceType WakeupSource)
{
    ECUM_ENTER_CRITICAL_SECTION();

    /* Clear all validated wakeups if any */
    EcuM_InternalParam.ValidatedWakeups &= ((EcuM_WakeupSourceType)(~WakeupSource));
    /* clear posted wakeups if any */
    EcuM_InternalParam.PostedWakeups &= ((EcuM_WakeupSourceType)(~WakeupSource));

    /* clear posted and cleared wakeups if any */
    EcuM_InternalParam.ClearedPostedWakeups &= ((EcuM_WakeupSourceType)(~WakeupSource));

    /* clear posted and expired wakeups if any */
    EcuM_InternalParam.ExpiredPostedWakeups &= ((EcuM_WakeupSourceType)(~WakeupSource));

#if (ECUM_INCLUDE_COMM != FALSE)
    EcuM_InternalParam.ComM_BufferedWakeups &= ((EcuM_WakeupSourceType)(~WakeupSource));
#endif

    ECUM_EXIT_CRITICAL_SECTION();
}


/*============================================================================
**
** Function Name    :   EcuM_EnterRunState
**
** Visibility       :   Local to EcuM
**
** Description      :   Called whenever Run State need to be entered
**
** Invocation       :   From EcuM_StateMachine()
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
static void EcuM_EnterRunState (void)
{
    #if (ECUM_COMM_COMMUNICATION_ALLOWED != FALSE)
    uint8 loop = 0;
    #endif

    /* Transit to Run State */
    (void)EcuM_Rte_Call_Switch_currentMode(RTE_MODE_EcuM_Mode_RUN);
    EcuM_SetModuleState(ECUM_STATE_APP_RUN);
    EcuM_OnEnterRun();
    
    #if (ECUM_COMM_COMMUNICATION_ALLOWED != FALSE)
    /* If com allowed list exists, set communication of all com channels */
    for (loop=0; loop < ECUM_COMM_MAX_ALLOWED_LIST; loop++)
    {
        /* Set communication of all ComM channels to allowed when enter run state */
        ComM_CommunicationAllowed(EcuM_ComMAllowedChannels[loop], TRUE);
    }
    #endif
    
    /*****************************************************************************
        Set Minimum Run duration timer value 
        Once the state is changed to APP_RUN state, this timer needs to be started 
        The timer should be decremented for every EcuM_MainFunction schedule
        If there is no RUN request from users, then Run state can be left and Shutdown
        state need to be processed.
     *****************************************************************************/
    EcuM_SetTimer(ECUM_RUN_MINIMUM_DURATION);

}

#if (ECUM_INCLUDE_COMM != FALSE)
/*============================================================================
**
** Function Name    :   EcuM_QryComMRunRequest
**
** Visibility       :   Local to EcuM
**
** Description      :   Called RUN or POST_RUN state is left
**
** Invocation       :   By State Machine
**
** Inputs           :
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
static boolean EcuM_QryComMRunRequest  (void)
{
    /* Defect id - DICVA-15001 */
    uint8 index = 0;
    boolean retVal = FALSE;
    ComM_StateType currentState;

  for(index = 0u; index < ECUM_MAX_COM_CHANNELS; index++)
  {
    if(E_OK == ComM_GetState((NetworkHandleType)EcuM_ComMChannels[index], &currentState))
    {
      if(currentState != COMM_NO_COM_NO_PENDING_REQUEST)
      {
        retVal = TRUE;
        break;
      }
    }
  }
  return retVal;
}
#endif

/*============================================================================
**
** Function Name    :   EcuM_EnterSleep
**
** Visibility       :   Local to EcuM
**
** Description      :   This module puts
**
** Invocation       :   By State Machine
**
** Inputs           :   mode of sleep
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
static void EcuM_EnterSleep (void)
{
    EcuM_WakeupSourceType fl_CurrentWakeupSource = 0;
    EcuM_WakeupSourceType Enabledwakeupsource_temp = 0;
	if(ECUM_MAX_NUM_SLEEP_MODE > EcuM_InternalParam.CurrentShutdownMode)
    {
    fl_CurrentWakeupSource = EcuM_SleepModeList[EcuM_InternalParam.CurrentShutdownMode].WakeupSource;
    }
    
        
    /* Check if any other wakeup source is active which are not required for this sleep mode */
	ECUM_ENTER_CRITICAL_SECTION();
    if (0U != (EcuM_InternalParam.EnabledWakeupSource & (~fl_CurrentWakeupSource)))
    {
		ECUM_EXIT_CRITICAL_SECTION();
        /* Disable all other wakeup sources which are not active for this sleep mode */
        /* Call the callout for disabling the inactive wake up sources */
        EcuM_DisableWakeupSources(EcuM_InternalParam.EnabledWakeupSource & (~fl_CurrentWakeupSource));
    }
    else
	{
		ECUM_EXIT_CRITICAL_SECTION();
	}
	ECUM_ENTER_CRITICAL_SECTION();
    EcuM_InternalParam.EnabledWakeupSource = fl_CurrentWakeupSource;
    
    EcuM_EnableWakeupSources(EcuM_InternalParam.EnabledWakeupSource);
    ECUM_EXIT_CRITICAL_SECTION();
    (void)GetResource(ECUM_OS_RESOURCE);
    
    /* Suspend all interrupts during this sleep mode (required by Mcu_SetMode) */
    ECUM_GLOBAL_INTERRUPTS_DISABLE() ;
    
    //SuspendOSInterrupts();
    
    /* Check if a wakeup request is available in EnterSleep phase */
	ECUM_ENTER_CRITICAL_SECTION();
    if (EcuM_InternalParam.ValidatedWakeups == ECUM_WKSOURCE_NONE)
    {
		
        EcuM_InternalParam.LastShutdownTarget   = EcuM_InternalParam.CurrentShutdownTarget;
        EcuM_InternalParam.LastShutdownMode     = EcuM_InternalParam.CurrentShutdownMode;
		ECUM_EXIT_CRITICAL_SECTION();
      	if(ECUM_MAX_NUM_SLEEP_MODE > EcuM_InternalParam.CurrentShutdownMode)
        {
        if (EcuM_SleepModeList[EcuM_InternalParam.CurrentShutdownMode].IsPollingAllowed != FALSE)
        {
            /* Polling Mode Implementation */
            EcuM_InternalEnterPollingMode();
        }
        else
        {
            /* Halt Implementation of the selected Mcu Sleep Mode */
            EcuM_InternalEnterHaltMode();
        }
    }
    }
    else
    {
		ECUM_EXIT_CRITICAL_SECTION();
        /* Restore interrupts as we didnt enter sleep due to wakeup available in EnterSleep Phase */
        ECUM_GLOBAL_INTERRUPTS_ENABLE() ;
        
    }
    
    /* Reached here due to some wakeup */
    
    ECUM_GLOBAL_INTERRUPTS_DISABLE() ;
    
    EcuM_McuSetMode(ECUM_NORMAL_MODE_MCU_REF);
    
    /* Restore interrupts */
    ECUM_GLOBAL_INTERRUPTS_ENABLE() ;
    
    /* Transit to RUN if one source is already validated */
	ECUM_ENTER_CRITICAL_SECTION();
    if (EcuM_InternalParam.ValidatedWakeups != 0u)
    {
		Enabledwakeupsource_temp = EcuM_InternalParam.EnabledWakeupSource;
		ECUM_EXIT_CRITICAL_SECTION();
        /* Disable all sources that were active during the current sleepmode */
        EcuM_DisableWakeupSources(Enabledwakeupsource_temp);
		ECUM_ENTER_CRITICAL_SECTION();
        EcuM_InternalParam.EnabledWakeupSource = 0;
		ECUM_EXIT_CRITICAL_SECTION();
    }
	else
	{
    /* Call the Driver Restart Callout */
	ECUM_EXIT_CRITICAL_SECTION();
	}
    EcuM_AL_DriverRestart(ECUM_DRIVER_RESTART_LIST);

    (void)ReleaseResource(ECUM_OS_RESOURCE);
}

static void EcuM_InternalEnterPollingMode (void)
{
    /* Defect id - DICVA-15002 */
}



static void EcuM_InternalEnterHaltMode (void)
{
	uint8 Currentshutdownmode_temp = 0;
    do
    {
        /*  No need to suspend interrupts as this step is done 
            * by the caller routine in case of sleep entry and
            * by this routine in case of wake sleep                 */
        
        /*  After a Wakeup the EcuM goes back to sleep if no 
            validated wakeup is stored. */
		ECUM_ENTER_CRITICAL_SECTION();	
        if(ECUM_MAX_NUM_SLEEP_MODE > EcuM_InternalParam.CurrentShutdownMode)
        {
		Currentshutdownmode_temp = EcuM_InternalParam.CurrentShutdownMode;
		ECUM_EXIT_CRITICAL_SECTION();
        EcuM_McuSetMode(EcuM_SleepModeList[Currentshutdownmode_temp].McuMode);
        }
		else
		{
        /* Do a global restore to be in a defined status after Mcu_SetMode. */
		ECUM_EXIT_CRITICAL_SECTION();
		}
        ECUM_GLOBAL_INTERRUPTS_ENABLE();

        /* Defect id - DICVA-15004 */
        
        /* This window is the place to service pending interrupts that triggered wakeup */
        
        /* GlobalSuspend is needed for the new call of Mcu_SetMode. It is called at this place 
        * to not miss any wakeup events. */
        ECUM_GLOBAL_INTERRUPTS_DISABLE();
        
        
    }while (EcuM_InternalParam.ValidatedWakeups == ECUM_WKSOURCE_NONE);
    /** A valid wakeup is recognized by the EcuMgr 
     ** Resume Global interrupts for sub-sequent operations of EcuMgr */
    ECUM_GLOBAL_INTERRUPTS_ENABLE();
}

/*============================================================================
**
** Function Name    :   EcuM_InternalWakeupSourcesValidation
**
** Visibility       :   Local
**
** Description      :   Iterates over posted wakeups and performs validation
**
** Invocation       :   EcuM_MainFunction
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   None
**
**==========================================================================*/
static void EcuM_InternalWakeupSourcesValidation(void)
{
    uint8 loop = 0;
    EcuM_WakeupSourceType wkpSrcMask;

    /* iterate through all user-defined wakeup sources */
    for (loop = ECUM_STD_WAKEUPS_COUNT; loop < ECUM_MAX_NUM_WAKEUP_SOURCE; loop++)
    {
        /* construct the mask of the current wakeup source */
        wkpSrcMask = (EcuM_WakeupSourceType)(1U << loop);

        /* check if wakeup source is posted */
        if ((wkpSrcMask & EcuM_InternalParam.PostedWakeups) != ECUM_WKSOURCE_NONE)
        {
            /* is validation started */
            if (EcuM_ValidationTimeouts[loop] > (EcuM_WakeupSrcValidationTime)0)
            {
                /* decrement tick counter */
                EcuM_ValidationTimeouts[loop]--;

                /* perform validation */
                EcuM_CheckValidation(wkpSrcMask);

                /* if wakeup source is still posted, but timeout expired */
                if (((wkpSrcMask & EcuM_InternalParam.PostedWakeups) != ECUM_WKSOURCE_NONE) &&
                    ((EcuM_ValidationTimeouts[loop]) == 0U))
                {
                    /* remove wakeup source from posted and add it to expired wakeups */
                    EcuM_InternalParam.PostedWakeups &= (~wkpSrcMask);
                    EcuM_InternalParam.ExpiredPostedWakeups |= wkpSrcMask;

                    /* stop validation procedure for this wakeup src */
                    EcuM_StopWakeupSources(wkpSrcMask);
                }

            }
            /* validation not started yet */
            else
            {
                /* arm timeout tick counter */
                EcuM_ValidationTimeouts[loop] = EcuM_WakeupSourceList[loop].ValidationTime;

                /* start validation procedure for this wakeup src */
                EcuM_StartWakeupSources(wkpSrcMask);

                /* perform validation */
                EcuM_CheckValidation(wkpSrcMask);
            }
        }
        /* check if wakeup source, that was posted, is cleared now*/
        else if ((wkpSrcMask & EcuM_InternalParam.ClearedPostedWakeups) != ECUM_WKSOURCE_NONE)
        {
            /* remove wakeup from list */
            EcuM_InternalParam.ClearedPostedWakeups &= (~wkpSrcMask);

            /* stop validation procedure for this wakeup src */
            EcuM_StopWakeupSources(wkpSrcMask);
        }
        /* wakeup source is neither posted, nor cleared */
        else
        {
            /* do nothing */
        }
    }
}

/*============================================================================
**
** Function Name    :   EcuM_InternalCheckWakupMaskValidity
**
** Visibility       :   Local
**
** Description      :   Checks the validity of provided mask:
**                      - only 1 bit shall be raised
**                      - bit shall be < max wakeup src configured
**
** Invocation       :   EcuM_SetWakeupEvent
**                      EcuM_ValidateWakeupEvent
**                      EcuM_ClearWakeupEvent
**
** Inputs           :   wkpSrcMask - mask to check
**
** Outputs          :   wkpSrcId - Id of the wakeup source in the mask
**                      MORE_THAN_1_BITS_RAISED - when < 1 bit is raised in the mask
**
** Critical Section :   None
**
**==========================================================================*/
static uint8 EcuM_InternalCheckWakupMaskValidity(EcuM_WakeupSourceType wkpSrcMask)
{
    uint8 wkpSrcId = 0;

    /* validate input */
    while (wkpSrcMask != ECUM_WKSOURCE_NONE)
    {
        /* test if LSB is raised */
        if ((wkpSrcMask & (EcuM_WakeupSourceType)1) != (EcuM_WakeupSourceType)0)
        {
            /* if LSB is 1, expectation is remaining bits are 0s */
            wkpSrcMask = wkpSrcMask >> 1;
            if (wkpSrcMask != ECUM_WKSOURCE_NONE)
            {
                wkpSrcId = MORE_THAN_1_BITS_RAISED;
            }
            break;
        }

        /* move to next bit and increment wakeup source */
        wkpSrcMask = wkpSrcMask >> 1;
        wkpSrcId++;
    }

    return wkpSrcId;
}

#if (ECUM_INCLUDE_COMM != FALSE)
/*============================================================================
**
** Function Name    :   EcuM_InternalBufferedComMNotifications
**
** Visibility       :   Local
**
** Description      :   Checks for ComM initialization and notifies ComM in
**                      case of wakeups that happened before ComM_Init
**
** Invocation       :   EcuM_MainFunction
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :   None
**
**==========================================================================*/
static void EcuM_InternalBufferedComMNotifications(void)
{
    /* if any buffered wakeups */
    if (EcuM_InternalParam.ComM_BufferedWakeups != ECUM_WKSOURCE_NONE)
    {
        /* check if ComM is already initialized */
        ComM_InitStatusType ComMStatus;
        Std_ReturnType retVal;
        retVal = ComM_GetStatus(&ComMStatus);
        if ((retVal == E_OK) && (ComMStatus == COMM_INIT))
        {
            uint8 wkpSrcId;
            for (wkpSrcId = ECUM_MAX_NUM_WAKEUP_SOURCE - (uint8)1; wkpSrcId > (uint8)0; wkpSrcId--)
            {
                /* check if wakeup is buffered */
                if ((EcuM_InternalParam.ComM_BufferedWakeups &
                    ((EcuM_WakeupSourceType)1 << (EcuM_WakeupSourceType)wkpSrcId)) != ECUM_WKSOURCE_NONE)
                {
                    /* place notification to ComM */
                    ComM_EcuM_WakeUpIndication(EcuM_WakeupSourceList[wkpSrcId].Channel);

                    /* clear the list with buffered wakeups */
                    EcuM_InternalParam.ComM_BufferedWakeups &= (~((EcuM_WakeupSourceType)1 << (EcuM_WakeupSourceType)wkpSrcId));
                }

                /* if no more buffered wakeup exit the loop */
                if (EcuM_InternalParam.ComM_BufferedWakeups == ECUM_WKSOURCE_NONE)
                {
                    break;
                }
            }
        }
    }
}
#endif

#if (ECUM_INCLUDE_NVM_MGR != FALSE)
/*============================================================================
**
** Function Name    :   EcuM_WaitOnNvMCancelWriteAll
**
** Visibility       :   Local
**
** Description      :   Routine to Kill the NvmWriteAll request
**
** Invocation       :   StateMachine
**
** Inputs           :   
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
static boolean EcuM_WaitOnNvMCancelWriteAll (void)
{
    boolean retVal = TRUE;
    
    switch (EcuM_InternalParam.NvMWriteAllStatus)
    {
        case ECUM_NVM_WRITEALL_IDLE:
        {
            /* WriteAll finished - Stop timer */
            EcuM_SetTimer(ECUM_TIMER_NOT_SET);
            retVal = FALSE; //do not wait for Cancel WriteAll
            break;
        }
        case ECUM_NVM_WRITEALL_STARTED:
        {
            //Start timeout for Cancel WriteAll
            EcuM_SetTimer(ECUM_NVM_WRITEALL_TIMEOUT);
            NvM_CancelWriteAll();
			ECUM_ENTER_CRITICAL_SECTION();
            EcuM_InternalParam.NvMWriteAllStatus = ECUM_NVM_WRITEALL_CANCELED;
			ECUM_EXIT_CRITICAL_SECTION();
            //Wait till call back for NvM Cancel WriteAll
            break;
        }
        case ECUM_NVM_WRITEALL_CANCELED:
        {
            //Wait for CBk or Timer Expiry to determine the Cancel WriteAll is complete
            ECUM_ENTER_CRITICAL_SECTION();
            if ((EcuM_InternalParam.NvMCbkNotified != FALSE) || \
                (EcuM_GetTimer() == ECUM_TIMER_EXPIRED))
            {
                if (EcuM_InternalParam.NvMJobResult != NVM_REQ_OK)
                {
                    EcuM_OnFailedNvmWriteAllJobReaction();
                }
                EcuM_InternalParam.NvMCbkNotified = FALSE;
                EcuM_InternalParam.NvMJobResult = NVM_REQ_NOT_OK;
                EcuM_InternalParam.NvMWriteAllStatus = ECUM_NVM_WRITEALL_IDLE;
                
                retVal = FALSE; //cancel write all is complete, no need to wait
            }
            ECUM_EXIT_CRITICAL_SECTION();
            break;
        }
        default:
        {
            /*do nothing*/
            break;
        }
    }
    return retVal;
}

/*============================================================================
**
** Function Name    :   EcuM_WaitOnNvMWriteAll
**
** Visibility       :   Local to EcuM
**
** Description      :   
**
** Invocation       :   
**
** Inputs           :   
**
** Outputs          :
**
** Critical Section :
**
**==========================================================================*/
static boolean EcuM_WaitOnNvMWriteAll (void)
{
    boolean retVal = TRUE;  //Initially tell to wait for NvMWriteAll
    
    /* ECUM_NVM_WRITEALL_REQUIRED gets triggered on the following scenarios
        1. EcuM decides to leave APP_POST_RUN Mode 
        2. EcuM */

    switch (EcuM_InternalParam.NvMWriteAllStatus)
    {
        case ECUM_NVM_WRITEALL_IDLE:
        {
            /* WriteAll finished - Stop timer */
            retVal = FALSE;
            EcuM_SetTimer(ECUM_TIMER_NOT_SET);
            break;
        }
        case ECUM_NVM_WRITEALL_REQUIRED:
        {
			ECUM_ENTER_CRITICAL_SECTION();
            EcuM_InternalParam.NvMWriteAllStatus = ECUM_NVM_WRITEALL_STARTED;
			ECUM_EXIT_CRITICAL_SECTION();
            EcuM_SetTimer(ECUM_NVM_WRITEALL_TIMEOUT);
            NvM_WriteAll();
            break;
        }
        case ECUM_NVM_WRITEALL_STARTED:
        {
            ECUM_ENTER_CRITICAL_SECTION();
            /* wait for write all completion or timer expiry */
            if (EcuM_InternalParam.NvMCbkNotified != FALSE)
            {
                EcuM_InternalParam.NvMCbkNotified = FALSE;
                EcuM_InternalParam.NvMWriteAllStatus = ECUM_NVM_WRITEALL_COMPLETED;
            }
            else if (EcuM_GetTimer() == ECUM_TIMER_EXPIRED)
            {
                EcuM_SetTimer(ECUM_TIMER_NOT_SET);
                EcuM_InternalParam.NvMJobResult = NVM_REQ_NOT_OK;
                EcuM_InternalParam.NvMWriteAllStatus = ECUM_NVM_WRITEALL_COMPLETED;
            }
            else
            {
                /* Defect id - DICVA-15005 */
            }
            
            ECUM_EXIT_CRITICAL_SECTION();
            break;
        }
        case ECUM_NVM_WRITEALL_COMPLETED:
        {
            ECUM_ENTER_CRITICAL_SECTION();
            
            if (EcuM_InternalParam.NvMJobResult != NVM_REQ_OK)
            {
                EcuM_OnFailedNvmWriteAllJobReaction();
            }
            EcuM_InternalParam.NvMJobResult = NVM_REQ_NOT_OK;
            
            ECUM_EXIT_CRITICAL_SECTION();
            
            EcuM_InternalParam.NvMWriteAllStatus = ECUM_NVM_WRITEALL_IDLE;
            retVal = FALSE;  //Nvm Write All job is completed, no need to wait
            break;
        }
        default:
        {
            EcuM_ErrorHook(0);
            break;
        }
    }
    return retVal;
}

#endif /* If NVM Manager check is included */

static FUNC(void, ECUM_CODE_SEC_START) ECUM_REPORT_ERROR(uint8 ApiId, uint8 ErrorId)
{
    #if(ECUM_DEV_ERROR_DETECT == TRUE && ECUM_INCLUDE_DET == TRUE)
    (void)Det_ReportError(ECUM_MODULE_ID,ECUM_INSTANCE_ID,ApiId, ErrorId);
    #endif
}

#define ECUM_CODE_SEC_END
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
Date               : 14-Feb-2016
CDSID              : ssukuma1
Traceability       : RTC #495524
Change Description : EcuM Sleep Mode Implementation
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 24-Feb-2016
CDSID              : ssukuma1
Traceability       : RTC #495524
Change Description : EcuM wait for Nvm Cancel WriteAll Callback changes
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 29-Jun-2016
CDSID              : ssukuma1
Traceability       : RTC #629326
Change Description : EcuM Ram structure design change
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 12-Mar-2021
CDSID              : praj1
Traceability       : RTC #1254354
Change Description : EcuM MODE Change RTE call out added and 
                    driver init three called after Nvm read all
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 07-May-2021
CDSID              : ssebast1
Traceability       : RTC #1291707
Change Description : EcuM Wakeup Validation implementation 
-----------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------
Date              : 27/March/2022
By                : gthanapp
Traceability      : RTC #1564070
Change Description: Cert-C warning analysis and fix
----------------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 15-Jun-2023
CDSID              : eganesan
Traceability       : RTC #2043995
Change Description : EcuM 4.3 Migration 
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 10-Jul-2024
CDSID              : gthanapp
Traceability       : DICVA-13936
Change Description : Compiler warning fix
-----------------------------------------------------------------------------*/

/* end of file =============================================================*/

