
/**
 * @file        OsError.c
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
 * @author      vbalakr3@visteon.com
 * @details     <b>Implements the Error Hooks concepts of Autosar 4.2.1</b>
 * @note
 *              Compiler    : GHS \n
 *              Target Hw   : Independent
 * @date        11 July, 2019
 *
 * @copyright   Visteon (c) 2021
 *
 */

#ifndef OS_ERR_C
#define OS_ERR_C

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "OsMain.h"
#include "OsPrivate.h"

extern void OsCheckIntDisEnPair(void);

//@cond
#define OS_ERROR_CODE_SEC_START
#include "Os_IntMemMap.h"
//@endcond

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#define OS_PROTECTION_HOOK_IS_IGNORE_ALLOWED() (0 != OS_IS_SELFTEST_ACTIVE())

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/


static void OsErr_SetErrServiceInfo(OsServiceIdType ServiceId, StatusType Reason);

osErrParamType osErrParam;


/**
 * @brief OsErr_GetServiceId - Returns the error service ID
 *
 * @param
 * @return OsServiceIdType
 */

OsServiceIdType OsErr_GetServiceId (void)
{
    return (osErrParam.OsServiceId);
}

/**
 * @brief OsCheckIntDisEnPair - Checks interrupt disable enable pair for cat2 isr
 *
 * @param
 * @return OsServiceIdType
 */

void OsCheckIntDisEnPair( void )
{
/*To Check: To Handle Suspend Resume interrupt pair for Cat2 ISR during its end*/
}

/**
 * @brief OsErr_SetErrServiceInfo - Sets the error parameters for OsHooks
 *
 * @param ServiceId
 * @param Reason
 * @return OsServiceIdType
 */

static void OsErr_SetErrServiceInfo(OsServiceIdType ServiceId, StatusType Reason)
{
    osErrParam.OsServiceId = ServiceId;
    osErrParam.LastErrReason = osErrParam.ErrReason;
    osErrParam.ErrReason = Reason;
    (void)osGetTaskID((TaskRefType)&(osErrParam.CallingTask));
}

/**
 * @brief OsError_InitMemory - Initializes the error structure
 *
 * @return void
 */

void OsError_InitMemory(void)
{
    osErrParam.ErrReason = E_OS_INVALID;
    osErrParam.ExceptionDetails = E_OK;
    osErrParam.OsServiceId = OsDlt_OsInvalidService;
    osErrParam.CallingTask = INVALID_TASK;
}

/**
 * @brief osMissingTerminateError - Reports osMissingTerminateError to fatal errorhook
 *
 * @param
 * @return OsServiceIdType
 */

void osMissingTerminateError (void)
{
    OsErr_osFatalErrorHook(OsDlt_OsInternalService, NULL, E_OS_MISSINGEND);
}

/**
 * @brief OsErr_osFatalErrorHook - Handles the fatal errors reported by informing application and calling osShutdownOS
 *
 * @param ServiceId
 * @param pStatus
 * @param Status
 * @return OsServiceIdType
 */

void OsErr_osFatalErrorHook (OsServiceIdType ServiceId, StatusType* pStatus, StatusType Status)
{
/*Caller API's will pass NULL to pStatus if they dont need Ret value. In that case ErrorStatus is used for capturing error status*/
    StatusType FatalErrorStatus = Status;
    if(NULL_PTR != pStatus)
    {
        OsErr_LogExtendedStatus(pStatus, Status);
        OsErr_SetErrServiceInfo(ServiceId, *pStatus);
    }
    else
    {
        OsErr_LogExtendedStatus(&FatalErrorStatus, Status);
        OsErr_SetErrServiceInfo(ServiceId, FatalErrorStatus);
    }

    OS_ERROR_HOOK(osErrParam);
    osShutdownOS(osErrParam.ErrReason);
    /*No come back here*/
}

/**
 * @brief osSysErrAssert - Reports assertion error to application errorhook
 *
 * @param
 * @return void
 */

void osSysErrAssert (void)
{
    OsErr_osApplicationErrorHook(OsDlt_OsInternalService, NULL, E_OS_SYS_ASSERTION);
}

/**
 * @brief osSysInternalErrAssert - Misra rule 17.2 is resolved with this by breaking the infinite loop
 *
 * @param
 * @return void
 */
void osSysInternalErrAssert (void)
{
    OS_UNRECOVERABLE_ERROR_HOOK();

    while(FALSE==FALSE)
    {
        //15.5 and 14.4 misra warning
    }
}
/**
 * @brief OsErr_LogExtendedStatus - Decides whether to enable extended errors or not
 *
 * @param pStatus
 * @param Status
 * @return void
 */

void OsErr_LogExtendedStatus(StatusType* pStatus, StatusType Status)
{
#if OS_CFG_OS_STATUS == OS_STATUS_EXTENDED
    if(NULL_PTR != pStatus)
    {
        *pStatus = Status;
    }
#else
    if(NULL_PTR != pStatus)
    {
        *pStatus = E_NOT_OK;
    }
#endif
}

/**
 * @brief OsErr_osApplicationErrorHook - Handles the application errors reported by informing application
 *
 * @param ServiceId
 * @param pStatus
 * @param Status
 * @return void
 */

void OsErr_osApplicationErrorHook (OsServiceIdType ServiceId, StatusType* pStatus, StatusType Status)
{
/*Caller API's will pass NULL to pStatus if they dont need Ret value. In that case ErrorStatus is used for capturing error status*/
    StatusType ErrorStatus = Status;
    if(NULL_PTR != pStatus)
    {
        OsErr_LogExtendedStatus(pStatus, Status);
        OsErr_SetErrServiceInfo(ServiceId, *pStatus);
    }
    else
    {
        OsErr_LogExtendedStatus(&ErrorStatus, Status);
        OsErr_SetErrServiceInfo(ServiceId, ErrorStatus);
    }
    /*This is a common error.*/
    OS_ERROR_HOOK(osErrParam);
}

/**
 * @brief OsErr_osProtectionHook - Handles the protection errors reported by informing application and calling osShutdownOS
 *
 * @param ErrorInfo
 * @return void
 */

void OsErr_osProtectionHook(ProtectionErrType ErrorInfo)
{   
    /*MISRA RULE 14.3 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    if((OS_PROTECTION_HOOK(ErrorInfo) != PRO_IGNORE)&& (FALSE != OS_PROTECTION_HOOK_IS_IGNORE_ALLOWED()))
    {
        osShutdownOS(ErrorInfo.ProtectionError);
    }

}

/**
 * @brief OsInvalidSvcCallHook - Invokes osShutdownOS if an invalid svc call occured
 * @param 
 * @return void
 */

void OsErr_InvalidSvcCallHook(void)
{
   osShutdownOS (E_OS_ID);

}
//@cond
#define OS_ERROR_CODE_SEC_END
#include "Os_IntMemMap.h"
//@endcond

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
**   ------------------------------------------------------------------------------ **
**   Date              : 09-Sep-2016                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : ------                                                     **
**   Change Description: Initial Version                                            **
**----------------------------------------------------------------------------------**
**   Date              : 18-Aug-2020                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : 1005188                                                    **
**   Change Description: Os Extended Error Support                                  **
**   ------------------------------------------------------------------------------ **
**----------------------------------------------------------------------------------**
**   Date              : 13-May-2022                                                **
**   CDSID             : eganesan                                                   **
**   RTC Id            : 1648619                                                    **
**   Change Description: Coverity & Misra Medium Warning Fix                        **
**----------------------------------------------------------------------------------**
**   Date              : 09-June-2022                                               **
**   CDSID             : eganesan                                                   **
**   RTC Id            : 1679233                                                    **
**   Change Description: Coverity & Misra Low Warning Fix                           **
**----------------------------------------------------------------------------------**/

/* end of file =============================================================*/
