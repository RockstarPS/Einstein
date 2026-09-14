
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
 * @file        OsApplication.c
 * @author      sivasujith.sukumaran@visteon.com
 * @details     <b>Implements the Os Application concepts of Autosar 4.2.1</b>
 * @note
 *              Compiler    : GHS \n
 *              Target Hw   : Independent
 * @date        06 June, 2020
 *
 * @copyright   Visteon (c) 2021
 *
 */

#ifndef OS_APPLICATION_C
#define OS_APPLICATION_C

/************************************* Includes **********************************/
#include "Os.h"
#include "OsPrivate.h"
#include "AssertLib.h"

#define OS_CORE_CODE_SEC_START
#define OS_CORE_CONST_SEC_START
#define OS_CORE_DATA_SEC_START
#define OS_CORE_BSS_SEC_START
#include "Os_IntMemMap.h"

static ObjectTypeType OsPrvGetObjectType(ObjectIdType ObjID);
/*************************************** Macros **********************************/


/********************************** Internal Data **********************************/
static VAR(OsAppParamType, OS_VAR_MEMCLASS) OsAppParam[OsNumberOfApplications];



/**
 * @brief Returns the AppParam
 *
 * @param AppId
 * @return OsAppParamType*
 */
OsAppParamType* OsGetAppParam (ApplicationType AppId)
{
    OsAppParamType *pAppParam = (OsAppParamType*)NULL;

    if(AppId < OsNumberOfApplications)
    {
        pAppParam = &(OsAppParam[AppId]);
    }
    else
    {
        OsErr_osApplicationErrorHook(OsDlt_OsGetAppParam, NULL, E_OS_LIMIT);
    }
    return (pAppParam);
}

/**
 * @brief Service Abstraction for GetApplicationId() API
 * @note  Returns the ActiveApplId of the calling Task/ISR
 * @return ApplicationType
 */
ApplicationType OsGetApplicationId (void)
{
    const OsObjConfigType * const pOwnObj = OsCtrlParam.pActiveObjRef;
    /*todo check if critical section is reqd*/
    return(pOwnObj->pAppRef->AppId);
}

/**
 * @brief Service Abstraction for GetCurrentApplicationID() API
 * @note  Returns the Currnet running Applicatin Id
 * @return ApplicationType
 */

ApplicationType OsGetCurrentApplicationID (void)
{
    return (OsCtrlParam.pActiveObjRef->pAppRef->AppId);
}

/**
 * @brief Service Abstraction for GetCurrentObjectID() API
 * @note  Returns the Currnet running Thread/ISR (object) Id
 * @return ObjectIdType
 */

ObjectIdType OsGetCurrentObjectID (void)
{
    return (OsCtrlParam.pActiveObjRef->ObjId);
}

/**
 * @brief Service Abstraction for OsGetCurrentObj() API
 * @note  Returns the Current Object
 * @return OsObjConfigRefType
 */

OsObjConfigRefType OsGetCurrentObj (void)
{
    ObjectIdType Obj = OsGetCurrentObjectID();
    OsObjConfigRefType RetVal = NULL;
    if(Obj < OsMaxNumOfObjectId)
    {
        RetVal = (OsObjRefConfig[Obj]);
    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }
    return RetVal;
}

/**
 * @brief Service Abstraction for OsGetCurrentApplication() API
 * @note Returns the current ApplicationId
 * @return OsAppConfigRefType
 */

OsAppConfigRefType OsGetCurrentApplication (void)
{
    ApplicationType AppId = OsGetCurrentApplicationID();
    OsAppConfigRefType RetVal = NULL;
    if(AppId < OsNumberOfApplications)
    {
        RetVal = (OsAppRefListDyn[AppId]);
    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }
    return RetVal;
}

/**
 * @brief Service Abstraction for OsTerminateApplication() API
 * @note Restarts the owner application as per RestartOption
 * @return StatusType
 */

StatusType OsTerminateApplication (ApplicationType Application, RestartType RestartOption)
{
    (void)Application;
    (void)RestartOption;
    StatusType  Ret = E_OS_ACCESS;
    /*Todo: check if this API has any use case*/
    return Ret;
}

/**
 * @brief Service Abstraction for OsAllowAccess() API
 * @note Sets current application state to accessible if it was restarting
 * @return StatusType
 */

StatusType OsAllowAccess (void)
{
    StatusType Ret = E_OS_ACCESS;
    ApplicationStateRefType pAppState = &(OsCtrlParam.AppParam.State);

    if(*pAppState != OS_APPLICATION_RESTARTING)
    {
        Ret = E_OS_STATE;
        OsErr_osApplicationErrorHook(OsDlt_OsGetElapsedValue, &Ret, E_OS_STATE);
    }
    else
    {
        *pAppState = OS_APPLICATION_ACCESSIBLE;
        Ret = E_OK;
    }
    return Ret;
}

/**
 * @brief Service Abstraction for OsGetApplicationState() API
 * @note Service to Get the App state
 * @return StatusType
 */

StatusType OsGetApplicationState (ApplicationType Application, ApplicationStateRefType Value)
{
    StatusType Ret = E_NOT_OK;

    if(Application < OsNumberOfApplications)
    {
        *Value = OsAppParam[Application].State;
        Ret = E_OK;
    }
    else
    {
        OsErr_osApplicationErrorHook(OsDlt_OsGetApplicationState, &Ret, E_OS_ID);
    }
    return Ret;
}

/**
 * @brief Service Abstraction for OsPrvGetObjectType() API
 * @note Service to Get the Previous Object type
 * @return ObjectTypeType
 */

static ObjectTypeType OsPrvGetObjectType(ObjectIdType ObjID)
{
    ObjectTypeType ObjType = OS_OBJECT_INVALID;
    if (ObjID < Object_ObjectIdMax)
    {
        ObjType = OsObjRefConfig[ObjID]->ObjType;
    }
    return ObjType;
}



/**
 * @brief Service Abstraction for OsCheckObjectAccess() API
 * @note Service to check if the Object is allowed access in the App
 * @return ObjectAccessType
 */

ObjectAccessType OsCheckObjectAccess(ApplicationType AppID, ObjectTypeType ObjType, ObjectIdType ObjID)
{
    ObjectAccessType Access = OS_OBJECT_NO_ACCESS;
    if(ObjID < OsMaxNumOfObjectId)
    {
    const OsObjConfigRefType pObjRef = (OsObjRefConfig[ObjID]);

    if((AppID >= OsNumberOfApplications) || (ObjID >= Object_ObjectIdMax))
    {
        Access = OS_OBJECT_NO_ACCESS;
    }
    else if (OsPrvGetObjectType(ObjID) != ObjType)
    {
        Access = OS_OBJECT_NO_ACCESS;
    }
    else
    {
        /* code 
        We have validated if the ObjID and AppID is within limits
        ObjType passed is same as configured
        Check if the Object has access to the AppID */
        if(pObjRef->pAppRef->AppId == AppID)
        {
            Access = OS_OBJECT_ACCESS;
        }
    }
    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }
    return Access;
}


/**
 * @brief Service Abstraction for OsCheckObjectOwnership() API
 * @note Service to check the object ownership
 * @return ApplicationType
 */

ApplicationType OsCheckObjectOwnership(ObjectTypeType ObjType, ObjectIdType ObjID)
{
    ApplicationType AppId = OS_CFG_APPLICATION_INVALID;
    if(ObjID < OsMaxNumOfObjectId)
    {
        const OsObjConfigRefType pObjRef = (OsObjRefConfig[ObjID]);
        if (OsPrvGetObjectType(ObjID) != ObjType)
        {
            AppId = OS_CFG_APPLICATION_INVALID;
            DEBUG_ASSERT( FALSE );
            /*Todo: Log faults*/
        }
        else
        {
            /* code */
            AppId = pObjRef->pAppRef->AppId;
        }
    }
    else
    {
        AppId = OS_CFG_APPLICATION_INVALID;
        DEBUG_ASSERT( FALSE );
    }
    return AppId;

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
**   ------------------------------------------------------------------------------ **
**   Date              : 06-Jun-2020                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : 920651                                                     **
**   Change Description: OS SC3 Support - Initial Version                           **
**----------------------------------------------------------------------------------**
**   Date              : 18-Aug-2020                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : 966911                                                     **
**   Change Description: MISRA Warning fix                                          **
**   ------------------------------------------------------------------------------ **
**   Date              : 7-Oct-2021                                                 **
**   CDSID             : vrusstar                                                   **
**   RTC Id            : 1464024                                                    **
**   Change Description: Review and fix of high Coverity issues                     **
**   ------------------------------------------------------------------------------ **
**   Date              : 09-June-2022                                               **
**   CDSID             : eganesan                                                   **
**   RTC Id            : 1679233                                                    **
**   Change Description: Coverity & Misra Low Warning Fix                           **
**----------------------------------------------------------------------------------**/

