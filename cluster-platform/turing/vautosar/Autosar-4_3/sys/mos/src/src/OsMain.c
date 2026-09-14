/**
 * @verbatim
               CONFIDENTIAL VISTEON CORPORATION

 This is an unpublished work of authorship, which contains trade
 secrets, created in 2013. Visteon Corporation owns all rights to
 this work and intends to maintain it in confidence to preserve
 its trade secret status. Visteon Corporation reserves the right,
 under the copyright laws of the United States or those of any
 other country that may have jurisdiction, to protect this work
 as an unpublished work, in the event of an inadvertent or
 deliberate unauthorized publication. Visteon Corporation also
 reserves its rights under all copyright laws to protect this
 work as a published work, when appropriate. Those having access
 to this work may not copy it, use it, modify it or disclose the
 information contained in it without the written authorization
 of Visteon Corporation.
 * @endverbatim
 * @file        OsMain.c
 * @details     <b>Implements the Events concepts of Autosar 4.2.1</b>
 * @note
 *              Compiler    : Independant \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2021
 *
 */

#ifndef OS_MAIN_C
#define OS_MAIN_C

#include "OsMain.h"
#include "OsPrivate.h"
#include "Os_HooksCfg.h"
#include "OsMemProtection.h"
#include "AssertLib.h"
#include "OsMetrics.h"


#define MOS_MODULE_ID                   0x0001u
#define MOS_VENDOR_ID                   0x0033u
#define MOS_AR_RELEASE_MAJOR_VERSION    0x04u /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define MOS_AR_RELEASE_MINOR_VERSION    0x02u /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define MOS_AR_RELEASE_PATCH_VERSION    0x01u /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define MOS_SW_MAJOR_VERSION            0x01u
#define MOS_SW_MINOR_VERSION            0x01u
#define MOS_SW_PATCH_VERSION            0x47u
#define OSMAIN_VALUE_ONE                1

#define OS_CORE_BSS_NOCACHE_SEC_START
#include "Os_IntMemMap.h"
/*RAM*/
/* Local variables */
VAR(OsCtrlParamType, OS_VAR_MEMCLASS)OsCtrlParam;
osStackPtrType osIntSP; 




#define OS_CORE_BSS_NOCACHE_SEC_END
#include "Os_IntMemMap.h"
#define OS_CORE_CODE_SEC_START
#define OS_CORE_CONST_SEC_START
#define OS_CORE_DATA_SEC_START
#define OS_CORE_BSS_SEC_START
#include "Os_IntMemMap.h"
static AccessType OsPrvCheckObjAccessRights (const OsObjConfigType * const pObj, MemoryStartAddressType Address, MemorySizeType Size);
static AccessType OsCheckObjAccessRights (const OsMPUAccessGroupConfigType * const pAccessConfig, MemoryStartAddressType Address, MemorySizeType Size);


/**
 * @brief This function is called by the system to get the current context
 * @name Os_GetContext
 * @param None
 * @return Context of the Os
 * @author ssukuma1
*/
FUNC(osuint16, OS_CODE) Os_GetContext (void)
{
    VAR(osuint16, OS_VAR_MEMCLASS) Context;
    // Enter Critical Sction
    OsPrvEnterCriticalSection();
    // Get the current context
    Context = OsCtrlParam.CurrentContext;
    // Exit Critical Sction
    OsPrvExitCriticalSection();
    return Context;
}

/**
 * @brief This function is called by the system to set the current context
 * @name Os_SetContext
 * @param Context
 * @return StatusType
 * @author ssukuma1
 * 
*/
FUNC(StatusType, OS_CODE) Os_SetContext (osuint16 Context)
{
    StatusType Result = E_OK;
    if(Context < osdCtxMax)
    {
        OsCtrlParam.CurrentContext = Context;
    }
    else
    {
        Result = E_NOT_OK;
    }
    return Result;
}


/**
 * @brief ShutdownOS - The user can call this system service to abort the overall system
 *
 * @param Error
 *
 * @return StatusType
 */
FUNC(void, OS_CODE) osShutdownOS (StatusType Error)
{
    (void)Error;
    OS_UNRECOVERABLE_ERROR_HOOK(); /*MISRA RULE 4.9 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    
    DisableAllInterrupts();     // Disable all interrupts

    /* No come back here since osShutdownOS is called. */
    while (!FALSE)
    {
        ;   // Do nothing, wait for watchdog reset
    }
}

/**
 * @brief GetISRId - This service returns the identifier of the currently executing ISR
 * @param   None
 * @return ISRType
  */
FUNC(ISRType, OS_CODE) OsGetISRId (void)
{
    ISRType ISRId = INVALID_ISR;

    SuspendAllInterrupts();
    if(Os_GetContext() == (uint16)osdCtxISRCat2)
    {
        ISRId = OsCtrlParam.ActiveISRId;
    }
    ResumeAllInterrupts();

    return (ISRId);
}


/**
 * @brief OsMainInitObjRef - Internal Function
 *
 * @param pObj
 *
 * @return void
 */
FUNC(void, OS_CODE) OsMainInitObjRef(OsObjConfigRefType pObj)
{
    // Setup the OsCtrlParam with ActiveTaskIndex environments
    // Enter Critical Sction
    OsPrvEnterCriticalSection();
    if(NULL_PTR != pObj)
    {
        OsCtrlParam.pActiveObjRef = pObj;
        OsCtrlParam.pLastObjRef = pObj;
    }
    // Exit Critical Sction
    OsPrvExitCriticalSection();
}

/**
 * @brief OsPrvSetActiveParam - Internal Function
 * @param pCurrObjRef
 * @return void
 * @attention This API should be called within critical section
 */
FUNC(void, OS_CODE) OsPrvSetActiveParam(OsObjConfigRefType pCurrObjRef)
{
    /* Setup the OsCtrlParam with ActiveTaskIndex environments */
    /* Interrupts are disabled before entering this API */
    OsCtrlParam.pLastObjRef = OsCtrlParam.pActiveObjRef;
    OsCtrlParam.pActiveObjRef = pCurrObjRef;
}


/**
 * @brief OsPrvSetTaskActiveParam - Internal Function
 * @param None
 * @return void
 * @attention   This API should be called within critical section
 */
FUNC(void, OS_CODE) OsPrvSetTaskActiveParam(void)
{
    const TaskType  TaskId = OsCtrlParam.ActiveTaskIndex;

    if(TaskId < OsNumberOfTasks)
    {
        const OsObjConfigRefType pCurrObjRef = TcbTaskRefConfig[TaskId]->pObjRef;
        OsPrvSetActiveParam(pCurrObjRef);
    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }
}

/**
 * @brief OsPrvSetIsrActiveParam - Internal Function
 * @param None
 * @return void
 * @attention   This API should be called within critical section
 * @details      This API is called when an ISR is entered
 */
FUNC(void, OS_CODE) OsPrvSetIsrActiveParam(void)
{
    const ISRType IsrId = OsCtrlParam.ActiveISRId;
    if(IsrId < OsNumberOfIsr)
    {
        const OsObjConfigRefType pCurrObjRef = OsIsrRefConfig[IsrId]->pObjRef;
        OsPrvSetActiveParam(pCurrObjRef);
    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }
}

/**
 * @brief OsPrvSetAlarmActiveParam - Internal Function
 * @param None
 * @return void
 * @attention   This API should be called within critical section
 */
FUNC(AccessLevelType, OS_CODE) OsPrvGetCurrAppAccessLevel(void)
{
    return (OsCtrlParam.pActiveObjRef->pAppRef->AccessLevel);
}

/**
 ** @brief  Private Os API to Enter Critical Section
 ** @name OsPrvEnterCriticalSection
 ** @param None
 ** @return None
 ** @details This API is called by the system to enter the critical section
 ** @author ssukuma1
 */
FUNC(void, OS_CODE) OsPrvEnterCriticalSection (void)
{
    osSuspendAllInterrupts();
}

/**
 ** @brief Private Os API to Exit Critical Section
 ** @name OsPrvExitCriticalSection
 ** @param None
 ** @return None
 ** @details This API is called by the system to exit the critical section
 ** @author ssukuma1
 */
FUNC(void, OS_CODE) OsPrvExitCriticalSection (void)
{
    osResumeAllInterrupts();
}

/**
 ** @brief  Private Os APi to get Dynamic Os Appication Reference.
 ** @param None
 ** @return OsAppConfigRefType - Reference to Current Dynamic OS App 
 */
FUNC(OsAppConfigRefType, OS_CODE) OsPrvGetDynApp(void)
{
    // Get the Dynamic App Reference, validation of the AppId is not required
    P2CONST(OsAppConfigType, OS_VAR_MEMCLASS, OS_PTRCLASS) pDynAppConst = NULL_PTR;
    OsAppConfigRefType pCurrApp = OsGetCurrentApplication();
    if(pCurrApp != NULL_PTR){
        pDynAppConst = OsAppRefListDyn[pCurrApp->AppId];
    }

    return pDynAppConst;
}

/**
 ** @brief Private Os APi to get Dynamic Os Appication Reference. 
 ** 
 ** @param pDynApp - Current Dynamic OS App Reference
 */
FUNC(void, OS_CODE) OsPrvSetDynApp(OsAppConfigRefType pDynApp)
{
    OsAppConfigRefType pCurrApp = OsGetCurrentApplication();
    if(pCurrApp != NULL_PTR)
    {
        OsAppRefListDyn[pCurrApp->AppId] = pDynApp;
    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }
}

#if (OS_CFG_MEMORY_PROTECTION == STD_ON)
#if OsNumberOfTrustedFns > 0U
/**
 * @brief CallTrustedFunction - Calls the Trusted Function provided by the FnIndex
 *
 * @param FnIndex
 * @param FnParam
 *
 * @return StatusType
 */
/*coverity - Audit speculative execution, Triaging this error since no major impact - tested*/
StatusType OsCallTrustedFunction (TrustedFunctionIndexType FnIndex, TrustedFunctionParameterRefType FnParam)
{
    StatusType Ret = E_OS_SERVICEID;
    

    if(FnIndex < OsNumberOfTrustedFns)
    {
        OsPrvEnterCriticalSection();

        OsAppConfigRefType pCurrApp = OsGetCurrentApplication(); /*MISRA RULE 8.13 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
        const OsTrustedCallConfigType * const pTfConfig = &(OsCfgTrustedCallConfig[FnIndex]); 

        if( (pCurrApp != NULL) && (pCurrApp->AppId < OsNumberOfApplicationsCore0) && (pTfConfig->pOwnerAppRef->AppId < OsNumberOfApplicationsCore0) )
        {
            OsAppConfigRefType pCurrAppprev = OsAppRefListDyn[pCurrApp->AppId];
            AccessRightsIdType TfAppAccessId = OS_CFG_APPLICATION_INVALID;
            TfAppAccessId = pTfConfig->pOwnerAppRef->AccessId;

            if(OsAppRefListDyn[pCurrApp->AppId]->AccessId != TfAppAccessId)
            {
                OsMemProt_MpuSwitchTrustedCall(pCurrAppprev->AccessId,TfAppAccessId);    
            }
            OsAppRefListDyn[pCurrApp->AppId] = pTfConfig->pOwnerAppRef;

            OsCtrlParam.LockDispatcher++;

            OsPrvExitCriticalSection();
            
            /* All trsuted calls are entered in privileged mode through trap so now,
             * Identify if current Trusted call requires Privileged access, if not then exit priveleged mode. */
            if(pTfConfig->pOwnerAppRef->AccessLevel != OS_ACCESS_PRIVILEGED)
            {
                OsCpuHal_ExitTrusted();
            }


            //Call TrustedFunction Directly
            if(NULL != pTfConfig->Service)
            {
                pTfConfig->Service(FnIndex,FnParam);
                Ret = E_OK;
            }
            else
            {
                OsErr_osApplicationErrorHook(OsDlt_OsCallTrustedFunction, &Ret, E_OS_SERVICEID);
            }

            /* Enter Privileged mode again to finish the Os routines after servicing trusted call. */
            if(FALSE == OsCpuHal_IsOsPrivilegeMode())
            {
                OsCpuHal_EnterTrusted();
            }
           
            OsPrvEnterCriticalSection();

            OsMemProt_MpuSwitchTrustedCall(TfAppAccessId,pCurrAppprev->AccessId);    
            OsAppRefListDyn[pCurrApp->AppId] = pCurrAppprev;
            OsCtrlParam.LockDispatcher--;
            OsPrvExitCriticalSection();
            Ret = E_OK;
        }
        else
        {
            OsPrvExitCriticalSection();
            DEBUG_ASSERT( FALSE );
        }
    }
    else
    {
        osSysErrAssert();
    }

    return Ret;
}
#endif
/**
 * @brief CheckISRMemoryAccess - Service to return the AccessType of ISR
 *
 * @param ISRId
 * @param Address
 * @param Size
 * @return AccessType
 */

AccessType OsCheckISRMemoryAccess (ISRType ISRId, MemoryStartAddressType Address, MemorySizeType Size)
{
    AccessType Result = OS_ACCESS_TYPE_NON;
    
    if(ISRId < osdNumberOfConfiguredIRQs)
    {
        const OsIsrConfigRefType pIsrConfig = (OsIsrRefConfig[ISRId]);
        Result = OsPrvCheckObjAccessRights(pIsrConfig->pObjRef,Address,Size);
    }
    return Result;
}

/**
 * @brief CheckTaskMemoryAccess - Service to provide the Access Type of the Task TaskID
 *
 * @param TaskID
 * @param Address
 * @param Size
 * @return AccessType
 */

AccessType OsCheckTaskMemoryAccess (TaskType TaskID, MemoryStartAddressType Address, MemorySizeType Size)
{
    AccessType Result = OS_ACCESS_TYPE_NON;
    
    if(TaskID < OsNumberOfTasks)
    {
        const OsTaskConfigRefType pTaskConfig = (TcbTaskRefConfig[TaskID]);
        Result = OsPrvCheckObjAccessRights(pTaskConfig->pObjRef,Address,Size);
    }
    return Result;        
}

/**
 * @brief PrvCheckObjAccessRights - Internal Function
 *
 * @param const pObj
 * @param Address
 * @param Size
 * @return AccessType
 */

static AccessType OsPrvCheckObjAccessRights (const OsObjConfigType * const pObj, MemoryStartAddressType Address, MemorySizeType Size)
{
    AccessType Result = OS_ACCESS_TYPE_NON;
    AccessRightsIdType AccessId = pObj->AccessId;
    if(AccessId < OsMaxAccessGroupIds)
    {
    const OsMPUAccessGroupConfigType * const pAccessConfig = &(OsMPUAccessGroupConfig[AccessId]);
    
    Result = OsCheckObjAccessRights(pAccessConfig,Address,Size);
    }
    return Result;
}

/**
 * @brief PrvCheckObjAccessRights - Internal Function
 *
 * @param pAccessConfig
 * @param Address
 * @param Size
 * @return AccessType
 */
/*coverity - Audit speculative execution, Triaging this error since no major impact */
static AccessType OsCheckObjAccessRights (const OsMPUAccessGroupConfigType * const pAccessConfig, MemoryStartAddressType Address, MemorySizeType Size)
{
    AccessType Result = OS_ACCESS_TYPE_NON;
    osuint32 Idx;
    MemoryStartAddressType StartAddress = Address;
    MemoryStartAddressType EndAddress =  ((StartAddress + Size)-1U);
    osuint32 RegionCount = pAccessConfig->RegionCount;

    for(Idx=0;Idx<RegionCount;Idx++)
    {
        const OsIntMpuConfigType * pMpuConfig = &pAccessConfig->pMpuConfig[Idx];
        const osuint32 RegnStartAddress = pMpuConfig->RegnBaseAddress;
        const osuint32 RegnEndAddress = ((RegnStartAddress + pMpuConfig->RegnSize)-1U);
        if((StartAddress >= RegnEndAddress) && (EndAddress <= RegnEndAddress))
        {
            Result = pMpuConfig->RegnAccess;
            break;
        }
    }
    return Result;
}

#endif /* OS_CFG_MEMORY_PROTECTION */

/**
 * @brief GetTaskStackUsage - This function outputs the stack usage of a task. This function outputs the stack usage of a task decrementing stack.
 *
 * @param TaskId
 * @return osStackUsageType
 */

osStackUsageType osGetTaskStackUsage (TaskType TaskId)
{
    osStackPtrType stackPtr = NULL;
    osStackPtrType stackStart = NULL;  /*MISRA RULE 8.13 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    osStackPtrType stackEnd = NULL;  /*MISRA RULE 8.13 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    osStackUsageType stackUsage = 0;
    
    if (TaskId >= OsNumberOfTasks)
    {
        osSysErrAssert();
    }
    else
    {
    stackPtr = TcbTaskRefConfig[TaskId]->TaskStackStartAddress - OSMAIN_VALUE_ONE;/*MISRA RULE 18.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    stackEnd = (osStackPtrType)((osStackDataType)stackPtr - TcbTaskRefConfig[TaskId]->TaskStackSize); /*MISRA RULE 11.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    
    stackStart = stackPtr;
    
    while (stackPtr > stackEnd) /*MISRA RULE 18.3 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    {
        if (*stackPtr == (osStackDataType)osdStackCheckPattern)
        {
            break;
        }
        stackPtr--;
    }
    stackUsage = ((osStackUsageType)((stackStart - stackPtr) * sizeof(osStackDataType)));
    }
    return stackUsage;
}

/**
 * @brief GetISRStackUsage - This function outputs the stack usage of a ISR. The functionality stands good only for Mcu has a decrementing stack.
 *
 * @param ISRId
 * @return osStackUsageType
 */

osStackUsageType osGetISRStackUsage (ISRType ISRId)
{
    osStackPtrType stackPtr = NULL;
    osStackPtrType stackStart = NULL;  /*MISRA RULE 8.13 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    osStackPtrType stackEnd = NULL;  /*MISRA RULE 8.13 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    osStackUsageType stackUsage = 0;
    
    if (ISRId >= osdNumberOfCat2ISRs)
    {
        osSysErrAssert();
    }
    else
    {
    stackPtr = IsrStackConfig[ISRId] - OSMAIN_VALUE_ONE;/*MISRA RULE 18.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    stackEnd = (osStackPtrType)((osStackDataType)stackPtr - IsrStackSize[ISRId]); /*MISRA RULE 11.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    
    stackStart = stackPtr;
    
    while (stackPtr > stackEnd) /*MISRA RULE 18.3 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    {
        if (*stackPtr == (osStackDataType)osdStackCheckPattern)
        {
            break;
        }
        stackPtr--;
    }
    stackUsage = ((osStackUsageType)((stackStart - stackPtr) * sizeof(osStackDataType))); /*MISRA RULE 10.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    }
    return stackUsage;
}

/**
 * @brief CheckTaskStackOverflow - This function checks the stack overflow of a task. This function checks the stack overflow of a task.
 *
 * @param TaskId
 *
 * @return void
 */

void osCheckTaskStackOverflow (TaskType TaskId)
{
    osStackPtrType stackPtr = NULL;
    osStackPtrType stackEnd = NULL;

    if (TaskId >= OsNumberOfTasks)
    {
        osSysErrAssert();
    }
    else
    {
        stackPtr = TcbTaskRefConfig[TaskId]->TaskStackStartAddress; 
        stackEnd = (osStackPtrType)((osStackDataType)stackPtr - TcbTaskRefConfig[TaskId]->TaskStackSize); /*MISRA RULE 11.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
        if(*(stackEnd) != (osStackDataType)osdStackCheckPattern)
        {
            *stackEnd = (osStackDataType)osdStackCheckPattern;
            osMemProtectionFault();
        }
    }
}

/**
 * @brief CheckISRStackOverflow - This function checks the stack overflow of a ISR. Triggers a osMemProtectionFault if overflow detects.
 *
 * @param ISRId
 *
 * @return void
 */

void osCheckISRStackOverflow (ISRType ISRId)
{
    osStackPtrType stackPtr = NULL;
    osStackPtrType stackEnd = NULL;

    if (ISRId >= osdNumberOfCat2ISRs)
    {
        osSysErrAssert();
    }
    else
    {
        stackPtr = IsrStackConfig[ISRId];
        stackEnd = (osStackPtrType)((osStackDataType)stackPtr - IsrStackSize[ISRId]);
        if(*(stackEnd) != (osStackDataType)osdStackCheckPattern)
        {
            *stackEnd = (osStackDataType)osdStackCheckPattern;
            osMemProtectionFault();
        }
    }
}

/**
 * @brief EnableAllInterrupts - Refer @osEnableGlobalInterruptAsm
 *
 * @param
 *
 * @return void
 */

void osEnableAllInterrupts (void)
{
    /* Clear IntSaveDisableRequestCounter and IntSaveStatus as interrupts are enabled globally */
    OsCtrlParam.IntSaveDisableRequestCounter = 0U;
    OsCtrlParam.IntSaveStatus = 0U;
    osEnableGlobalInterruptAsm();
}

/**
 * @brief DisableAllInterrupts - Refer @osDisableGlobalInterruptAsm
 *
 * @param
 *
 * @return void
 */

void osDisableAllInterrupts (void)
{
    osDisableGlobalInterruptAsm();
}

/**
 * @brief SuspendAllInterrupts - This service saves the recognition status of all interrupts and disables all interrupts for which the hardware supports disabling.
 *
 * @param
 *
 * @return void
 */

void osSuspendAllInterrupts (void)
{
    if (OsCtrlParam.IntSaveDisableRequestCounter > osdMaxAllowedCriticalSectionNesting)
    {
        osSysInternalErrAssert();
    }
    else
    {
        if (OsCtrlParam.IntSaveDisableRequestCounter == 0U)
        {
            OsCtrlParam.IntSaveStatus = osSuspendInterruptsAsm();
            osCriticalSectionStartHook();   
        }
    
        OsCtrlParam.IntSaveDisableRequestCounter++;
    }
}

/**
 * @brief ResumeAllInterrupts - This service restores the recognition status of all interrupts saved by the SuspendAllInterrupts service.
 *
 * @param
 *
 * @return void
 */

void osResumeAllInterrupts (void)
{
    if (OsCtrlParam.IntSaveDisableRequestCounter != 0U)
    {
        OsCtrlParam.IntSaveDisableRequestCounter--;
        if(OsCtrlParam.IntSaveDisableRequestCounter == 0U)
        {
            osCriticalSectionStopHook();
            osResumeInterruptsAsm(OsCtrlParam.IntSaveStatus);
        }
    }
}

/**
 * @brief SuspendOsInterrupts - This service saves the recognition status of interrupts of category 2 and disables the recognition of these interrupts.
 *
 * @param
 *
 * @return void
 */

void osSuspendOsInterrupts (void) /*MISRA RULE 8.7 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
{
    if (OsCtrlParam.OsIntSaveDisableRequestCounter > osdMaxAllowedCriticalSectionNesting)
    {
        //some error
    }
    else
    {
        if (OsCtrlParam.OsIntSaveDisableRequestCounter == 0U)
        {
            OsDisableSystickInt(); /*MISRA RULE 4.9 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
            osCriticalSectionStartHook(); /*MISRA RULE 2.2 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
            
        }
    
        OsCtrlParam.OsIntSaveDisableRequestCounter++;
    }
}

/**
 * @brief ResumeOsInterrupts - This service restores the recognition status of interrupts saved by the SuspendOSInterrupts service
 *
 * @param
 *
 * @return void
 */
void osResumeOsInterrupts (void) /*MISRA RULE 8.7 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
{
    if (OsCtrlParam.OsIntSaveDisableRequestCounter != 0U)
    {
        OsCtrlParam.OsIntSaveDisableRequestCounter--;
        if(OsCtrlParam.OsIntSaveDisableRequestCounter == 0U)
        {
            osCriticalSectionStopHook(); /*MISRA RULE 2.2 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
            OsEnableSystickInt(); /*MISRA RULE 4.9 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
        }
    }
}

/**
 * @brief CheckInterruptsEnabled -  Service to check if Global Interrupt is enabled
 *
 * @param
 *
 * @return osbool
 */

osbool osCheckInterruptsEnabled (void)
{
    osbool Ret = FALSE;
    Ret = osIsGlobalIntEnabled();
    return Ret;
}

#if (MOS_VERSION_INFO_API == STD_ON)
/**
 * @brief GetVersionInfo -  Service to return version info of the module
 *
 * @param VersionInfo
 *
 * @return void
 */

void Os_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
    if(NULL_PTR != VersionInfo)
    {
        VersionInfo->vendorID         = (uint16)MOS_VENDOR_ID;
        VersionInfo->moduleID         = (uint16)MOS_MODULE_ID;
        VersionInfo->sw_major_version = (uint8)MOS_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = (uint8)MOS_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = (uint8)MOS_SW_PATCH_VERSION;   
    } 
}
#endif

ISRType  osGetISRID(void) /*MISRA RULE 4.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
{
    return 0;
}

/**
 * @brief osTaskStartHook -  Internal Function
 *
 * @param
 *
 * @return void
 */

void osTaskStartHook (void)
{
    #ifdef mOS_SUPPORT_INTERNAL_METRICS   
    OsGetStartTaskMetrics();
    #endif    
    OS_TASK_START_HOOK();
}

/**
 * @brief osTaskResumeHook -  Internal Function
 *
 * @param
 *
 * @return void
 */

void osTaskResumeHook (void)
{
    #ifdef mOS_SUPPORT_INTERNAL_METRICS    
    OsGetResumeTaskMetrics(); 
    #endif 
    OS_TASK_RESUME_HOOK();
}

/**
 * @brief osTaskStopHook -  Internal Function
 *
 * @param
 *
 * @return void
 */
void osTaskStopHook (void)
{
    OS_TASK_STOP_HOOK();
}

/**
 * @brief osCriticalSectionStartHook -  Internal Function
 *
 * @param
 *
 * @return void
 */

void osCriticalSectionStartHook(void)
{
    OS_ENTER_CRITICAL_SECTION_HOOK();
}

/**
 * @brief osCriticalSectionStopHook -  Internal Function
 *
 * @param
 *
 * @return void
 */

void osCriticalSectionStopHook(void)
{
    OS_EXIT_CRITICAL_SECTION_HOOK();
}

#define OS_CORE_CODE_SEC_END
#define OS_CORE_CONST_SEC_END
#define OS_CORE_DATA_SEC_END
#define OS_CORE_DATA_NOCACHE_SEC_END
#define OS_CORE_BSS_SEC_END
#include "Os_IntMemMap.h"

#endif
/*----------------------------------------------------------------------------------**
**  ------------------------------------------------------------------------------- **
**   ****************************************************************************   **
**      for each change to this file, be sure to record:                            **
**         1.  who made the change and when the change was made                     **
**         2.  why the change was made and the intended result                      **
**      Following block needs to be repeated for each change                        **
**   ****************************************************************************   **
**      Note: In the traceability column we need to trace back to the Design Doc.   **
**      For the initial version it is traced to the Design Document section.        **
**      For further changes it shall trace to the source of the change which may    **
**      be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any     **
**      other reason                                                                **
**   ****************************************************************************   **
**  ------------------------------------------------------------------------------- **
**                                                                                  **
**  ------------------------------------------------------------------------------- **
**   Date              : 20-Jun-2016                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : ------                                                     **
**   Change Description: Initial version.                                           **
**   ------------------------------------------------------------------------------ **
**  ------------------------------------------------------------------------------- **
**   Date              : 13-Aug-2019                                                **
**   CDSID             : ssebast1                                                   **
**   RTC Id            : ------                                                     **
**   Change Description: Added support for ISR stack usage and Task/ISR Stack       **
**                       Overflow Detection.                                        **
**   ------------------------------------------------------------------------------ **
**   Date              : 09-Dec-2019                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : 1393561                                                    **
**   Change Description: Added supporting Function osCheckInterruptsEnabled         **
**   ------------------------------------------------------------------------------ **
**   Date              : 16-Jan-2020                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : 718485                                                     **
**   Change Description: MISRA Warning fix                                          **
**   ------------------------------------------------------------------------------ **
**   Date              : 18-Aug-2020                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : 966911                                                     **
**   Change Description: MISRA Warning fix                                          **
**   ------------------------------------------------------------------------------ **
**   Date              :23-Sep-2021                                                **
**   CDSID             : praj1                                                   **
**   RTC Id            : 1449970                                                     **
**   Change Description: OSTrsuedCall nested call defect fix   
**   ------------------------------------------------------------------------------ **
**   Date              : 8-Oct-2021                                                 **
**   CDSID             : vrusstar                                                   **
**   RTC Id            : 1464024                                                    **
**   Change Description: Review and fix of high Coverity issues                     **
**   ------------------------------------------------------------------------------ **
**----------------------------------------------------------------------------------**
**   Date              : 13-May-2022                                                **
**   CDSID             : eganesan                                                   **
**   RTC Id            : 1648619                                                    **
**   Change Description: Coverity & Misra Medium Warning Fix                        **
**----------------------------------------------------------------------------------**
**----------------------------------------------------------------------------------**
**   Date              : 27-May-2022                                                **
**   CDSID             : eganesan                                                   **
**   RTC Id            : 1672091                                                    **
**   Change Description: Bsw general requirements supported                         **
**----------------------------------------------------------------------------------**
**   Date              : 09-June-2022                                               **
**   CDSID             : eganesan                                                   **
**   RTC Id            : 1679233                                                    **
**   Change Description: Coverity & Misra Low Warning Fix                           **
**----------------------------------------------------------------------------------**
**   Date              : 09-Apr-2024                                                **
**   CDSID             : ssukuma1                                                   **
**   Traceability      : PE4TI29141-2219                                            **
**   Change Description: Compiler Abstraction & BSW General Requirements            **
**----------------------------------------------------------------------------------**/

