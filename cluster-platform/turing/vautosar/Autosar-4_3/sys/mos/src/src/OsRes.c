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
 * @file        OsRes.c
 * @details     <b>Implements the resource handling of the operating system Autosar 4.2.1</b>
 * @note
 *              Compiler    : GHS \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2021
 *
 */

#ifndef OS_RES_C
#define OS_RES_C

#include "OsMain.h"
#include "OsPrivate.h"

#define OS_CORE_CODE_SEC_START
#define OS_CORE_CONST_SEC_START
#define OS_CORE_DATA_SEC_START
#define OS_CORE_BSS_SEC_START
#include "Os_IntMemMap.h"

static osResCounterType OsResOccupationCtr[NumberOfResources];

/**
 * @brief OsRes_InitMemory - Internal Function
 *
 * @param dest
 *
 * @return void
 */


void OsRes_InitMemory(void)
{
    osuint32 Ix=0;
    for(Ix=0;Ix<NumberOfResources;Ix++)
    {
        OsResOccupationCtr[Ix] = 0;
    }
}

/**
 * @brief OsGetResource - This call serves to enter critical sections in the code that are assigned to the resource referenced by <ResID>.
 *
 * @param Res
 *
 * @return StatusType
 */

StatusType osGetResource (ResourceType Res)
{
    OsCtrlParamType * const pOsCtrl = &OsCtrlParam;
    osuint8 AppRefIndex = 0;
    Std_ReturnType IsResAppValid = E_NOT_OK;
    Std_ReturnType Ret = E_OK;

    /* Perform Validity Tests for calling this API */
    if(Res >= NumberOfResources)
    {
        OsErr_osApplicationErrorHook(OsDlt_OsGetResource, &Ret, E_OS_ID);
    }
    else
    {
        if(0 == (pOsCtrl->CurrentContext & osdGetResourceAllowedContext))
        {
            Ret = E_OS_CALLEVEL;
        }

    /* Check if Resource is already occupied */
        if(OsResOccupationCtr[Res] != 0U)
        {
            Ret = E_OS_ACCESS;
        }

        if(osCheckInterruptsEnabled() == FALSE)
        {
            Ret = E_OS_DISABLEDINT;
        }

        const OsResConfigRefType pThisResCfg = (OsResRefConfig[Res]);

        for (AppRefIndex = 0; AppRefIndex < pThisResCfg->NumofpAppRef; AppRefIndex++)
        {
            if(pOsCtrl->pActiveObjRef->pAppRef->AppId == pThisResCfg->pAppRef[AppRefIndex]->AppId)
            {
                IsResAppValid = E_OK;
                break;
                /* Quit this loop if we detect valid App references ****************************
                 * After getting the valid app reference no need of further traversing the loop*/
            }
        }

        if(IsResAppValid != (uint8)E_OK)
        {
            Ret = E_OS_ACCESS;
        }

        if(Ret != (uint8)E_OK)
        {
            OsErr_osApplicationErrorHook(OsDlt_OsGetResource, &Ret, Ret);
        }
        else
        {
            /* Actual Implementation starts here */

            OsPrvEnterCriticalSection();
            osSchedGetResource(pThisResCfg);
            /*Now the active priority should be the ceiling priority*/
            OsResOccupationCtr[Res]++;
            OsPrvExitCriticalSection();
        }
    }
    return Ret;
}

/**
 * @brief OsReleaseResource - ReleaseResource is the counterpart of GetResource and serves to leave critical sections in the code that are assigned to the resource referenced by <ResID>.
 *
 * @param Res
 *
 * @return StatusType
 */

StatusType osReleaseResource (ResourceType Res)
{
    OsCtrlParamType * const pOsCtrl = &OsCtrlParam;
    osuint8 AppRefIndex = 0;
    Std_ReturnType IsResAppValid = E_NOT_OK;
    Std_ReturnType Ret = E_OK;

    if( Res >= NumberOfResources )
    {
        OsErr_osApplicationErrorHook(OsDlt_OsReleaseResource, &Ret, E_OS_ID);
    }
    else
    {
        /* Perform Validity Tests for calling this API */
        if(0 == (pOsCtrl->CurrentContext & osdGetResourceAllowedContext))
        {
            Ret = E_OS_CALLEVEL;
        }

        /* Check if Resource is not occupied */
        if(OsResOccupationCtr[Res] == 0U)
        {
            Ret = E_OS_ACCESS;
        }

        if(osCheckInterruptsEnabled() == FALSE)
        {
            Ret = E_OS_DISABLEDINT;
        }

        const OsResConfigRefType pThisResCfg = (OsResRefConfig[Res]);

        for (AppRefIndex = 0; AppRefIndex < pThisResCfg->NumofpAppRef; AppRefIndex++)
        {
            if(pOsCtrl->pActiveObjRef->pAppRef->AppId == pThisResCfg->pAppRef[AppRefIndex]->AppId)
            {
                IsResAppValid = E_OK;
                break;
                /* Quit this loop if we detect valid App references ****************************
                 * After getting the valid app reference no need of further traversing the loop*/
            }
        }

        if(IsResAppValid != (uint8)E_OK)
        {
            Ret = E_OS_ACCESS;
        }

        if(Ret != (uint8)E_OK)
        {
            OsErr_osApplicationErrorHook(OsDlt_OsGetResource, &Ret, Ret);
        }
        else
        {
            /* Actual Implementation starts here */
            OsPrvEnterCriticalSection();
            OsResOccupationCtr[Res]--;
            osSchedReleaseResource(pThisResCfg);
            if((pOsCtrl->LockDispatcher == 0U) && (pOsCtrl->RequestScheduler != 0U))
            {
                OsPrvExitCriticalSection();
                // Call the Dispatcher here as we have set the RequestScheduler
                osDispatch();
            }
            OsPrvExitCriticalSection();
        }
    }
    return Ret;
}

/**
 * @brief OsSysReleaseResource - ReleaseResource is the counterpart of GetResource and serves to leave critical sections in the code that are assigned to the resource referenced by <ResID>.
 *
 * @param Res
 *
 * @return StatusType
 */

StatusType osSysReleaseResource (ResourceType Res)
{
    OsCtrlParamType * const pOsCtrl = &OsCtrlParam;
    osuint8 AppRefIndex = 0;
    Std_ReturnType IsResAppValid = E_NOT_OK;
    Std_ReturnType Ret = E_OK;

    if( Res >= NumberOfResources )
    {
        OsErr_osApplicationErrorHook(OsDlt_OsReleaseResource, &Ret, E_OS_ID);
    }
    else
    {
        /* Perform Validity Tests for calling this API */
        if(0U == (pOsCtrl->CurrentContext & osdGetResourceAllowedContext))
        {
            Ret = E_OS_CALLEVEL;
        }

        /* Check if Resource is not occupied */
        if(OsResOccupationCtr[Res] == 0U)
        {
            Ret = E_OS_ACCESS;
        }

		/* since we are in the svc context as interrupts disabled */
		/* Global interrupt check and critical sections removed */
        const OsResConfigRefType pThisResCfg = (OsResRefConfig[Res]);

        for (AppRefIndex = 0; AppRefIndex < pThisResCfg->NumofpAppRef; AppRefIndex++)
        {
            if(pOsCtrl->pActiveObjRef->pAppRef->AppId == pThisResCfg->pAppRef[AppRefIndex]->AppId)
            {
                IsResAppValid = E_OK;
                break;
                /* Quit this loop if we detect valid App references ****************************
                 * After getting the valid app reference no need of further traversing the loop*/
            }
        }

        if(IsResAppValid != (uint8)E_OK)
        {
            Ret = E_OS_ACCESS;
        }

        if(Ret != (uint8)E_OK)
        {
            OsErr_osApplicationErrorHook(OsDlt_OsGetResource, &Ret, Ret);
        }
        else
        {
            /* Actual Implementation starts here */
            OsPrvEnterCriticalSection();
            OsResOccupationCtr[Res]--;
            osSchedReleaseResource(pThisResCfg);
            OsPrvExitCriticalSection();
        }
    }
    return Ret;
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
**   Traceability      :------------                                                **
**   RTC Version       : ------                                                     **
**   Change Description: Initial version.                                           **
**   ------------------------------------------------------------------------------ **
**   Date              : 7-Oct-2021                                                 **
**   CDSID             : vrusstar                                                   **
**   RTC Id            : 1464024                                                    **
**   Change Description: Review and fix of high Coverity issues                     **
**   ------------------------------------------------------------------------------ **
**   Date              : 13-May-2022                                                **
**   CDSID             : eganesan                                                   **
**   RTC Id            : 1648619                                                    **
**   Change Description: Coverity & Misra Medium Warning Fix                        **
**----------------------------------------------------------------------------------**
**   Date              : 09-June-2022                                               **
**   CDSID             : eganesan                                                   **
**   RTC Id            : 1679233                                                    **
**   Change Description: Coverity & Misra Low Warning Fix                           **
**----------------------------------------------------------------------------------**
**----------------------------------------------------------------------------------**/

