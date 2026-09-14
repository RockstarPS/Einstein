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
 * @file        OsMemProtection.c
 * @details     <b>Implements the mOs handling Os MPU Autosar 4.2.1</b>
 * @note
 *              Compiler    : GHS \n
 *              Target Hw   : Independents
 *
 * @copyright   Visteon (c) 2021
 *
 */

#ifndef OS_HAL_MEMPROTECTION_C
#define OS_HAL_MEMPROTECTION_C


/************************************* Includes **********************************/
#include "OsPrivate.h"
#include "OsMemProtection.h"
#include "AssertLib.h"
#include "OsApplication.h"


/*************************************** Macros **********************************/
#define OS_CORE_CODE_SEC_START
#define OS_CORE_CONST_SEC_START
#define OS_CORE_DATA_SEC_START
#define OS_CORE_BSS_SEC_START
#include "Os_IntMemMap.h"

#define OS_MEMPROT_MAX_OBJ                  2UL /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/

#define OS_MPU_UNINIT                       0U
#define OS_MPU_INIT                         1U
#define OS_MPU_OS_STATE                     2U
#define OS_MPU_APP_STATE                    3U /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OS_MPU_TRUSTEDCALL_STATE            4U /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OS_MPU_UNDEFINED_STATE              0xFFU /*MISRA RULE 2.5 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
#define OS_MPU_ARRAY_SIZE_TWO               2

extern const OsMPUAccessGroupConfigType OsMPUAccessGroupConfig[OsMaxAccessGroupIds];

/********************************** Internal Data **********************************/
static void OsMemProtPrv_MpuSwitchSafeSegments(AccessRightsIdType Prev, AccessRightsIdType Next);
static void OsMemProtPrv_MpuSwitch (AccessRightsIdType AccessId);

#define OS_CORE_BSS_BSW_SEC_START
#include "Os_IntMemMap.h"
static osuint8 OsMemProt_MPUState = OS_MPU_UNINIT;
#define OS_CORE_BSS_BSW_SEC_END
#include "Os_IntMemMap.h"
/********************************** Internal Functions *****************************/
/**
 * @brief osMemProtPrv_MpuSwitchSafeSegments -  Internal Function
 *
 * @param Prev
 * @param Next
 *
 * @return void
 */

static void OsMemProtPrv_MpuSwitchSafeSegments(AccessRightsIdType Prev, AccessRightsIdType Next)
{
#if OsMaxAccessGroupIds > 0U
    if((Next < OsMaxAccessGroupIds) && (Prev < OsMaxAccessGroupIds))
    {
    const OsMPUAccessGroupConfigType * const pMpuAccessGroup = &(OsMPUAccessGroupConfig[Next]);

    const OsMpuAccessGroupDiffType* const pThisAccessGroupDiff = &(OsMpuAccessGroupDiff[Next][Prev]);

    osuint8 Ix = 0;
    osuint32 MpuRegionToSwitch = 0;

    //for all differences between Prev and Next MpuAccess groups
    for (Ix = 0; Ix < pThisAccessGroupDiff->DiffCount; Ix++)
    {
        //get the Id of the region and reconfigure it
        MpuRegionToSwitch = pThisAccessGroupDiff->DiffRegions[Ix];
        OsCpuHal_MpuSwitch(&(pMpuAccessGroup->pMpuConfig[MpuRegionToSwitch]));
    }
    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }
#endif
}

/**
 * @brief osMemProtPrv_MpuSwitch -  Internal Function
 *
 * @param AccessId
 *
 * @return void
 */

static void OsMemProtPrv_MpuSwitch (AccessRightsIdType AccessId)
{
#if OsMaxAccessGroupIds > 0U
    osuint32 Ix=0;
    if(AccessId < OsMaxAccessGroupIds)
    {
    const OsMPUAccessGroupConfigType * const pMpuAccessGroup = &(OsMPUAccessGroupConfig[AccessId]);
    for(Ix=0;Ix<pMpuAccessGroup->RegionCount;Ix++)
    {
        OsCpuHal_MpuSwitch(&(pMpuAccessGroup->pMpuConfig[Ix]));
    }
    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }
#endif
}

/********************************** Private Functions *******************************/
/**
 * @brief osMemProtectPrv_GetCurrentAccessRightsId -  Internal Function
 *
 * @param
 *
 * @return AccessRightsIdType
 */
AccessRightsIdType OsMemProtectPrv_GetCurrentAccessRightsId (void)
{
    AccessRightsIdType AccessRights = OsMaxAccessGroupIds;
    OsPrvEnterCriticalSection();
    AccessRights = OsCtrlParam.pActiveObjRef->AccessId;
    OsPrvExitCriticalSection();
    return AccessRights;
}

/********************************** Extended Functions *****************************/
/**
 * @brief osOsMemProtect_Init -  Internal Function
 *
 * @param
 *
 * @return void
 */

void OsMemProtect_Init (void)
{
    OsPrvEnterCriticalSection();
    OsIntMpuConfigType OsSysStackMpuConfig;
    const CoreIdType CoreId = OsCore_GetCurrentCore();
    if(CoreId < OsNumberOfCores)
    {
        const OsCoreConfigRefType pThisCore = (OsCoreRefConfig[CoreId]);
        OsMainInitObjRef(pThisCore->pOsCoreObjRef);
        OsCpuHal_DisableGlobalMPU();
        /* Setup MPU region for stack with Core own obj parameters */
        /* Since We are here in os kernel object */
        OsSysStackMpuConfig.RegnAccess = OS_ACCESS_TYPE_RW;      /*RegnAccess for Stack is always RW*/
        OsSysStackMpuConfig.RegnAttribute = pThisCore->pOsCoreObjRef->StackRegAttribute;
        OsSysStackMpuConfig.RegnBaseAddress = (osuint32)pThisCore->pOsCoreObjRef->StackStartAddress; /*MISRA RULE 11.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
        OsSysStackMpuConfig.RegnNumber = OS_CFG_MPU_STACK_REGION_NUM;    /*RegnNumber for Stack is reserved.*/
        OsSysStackMpuConfig.RegnSize = pThisCore->pOsCoreObjRef->StackSize;
        OsSysStackMpuConfig.RegnSizeAndEnable = pThisCore->pOsCoreObjRef->StackRegnSizeAndEnable;
        OsCpuHal_MpuSwitch(&OsSysStackMpuConfig);
        /* Setup MPU regions with Core Object Access Id*/
        OsMemProtPrv_MpuSwitch(pThisCore->pOsCoreObjRef->AccessId);
        OsMemProt_MPUState = OS_MPU_INIT;
        OsCpuHal_EnableGlobalMPU();
        OsPrvExitCriticalSection();
    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }
}



/**
 * @brief osMemProtPrv_AppMpuSwitch -  Internal Function
 *
 * @param Prev
 * @param Next
 *
 * @return void
 */
void OsMemProtPrv_AppMpuSwitch (AccessRightsIdType Prev, AccessRightsIdType Next)
{
	#if OS_CFG_MPU_SWITCH_APP == STD_ON

    if(Prev != Next)
    {
        OsMemProtPrv_MpuSwitchSafeSegments(Prev, Next);
    }
    #else
        (void)Prev;
        (void)Next;
    #endif
}

/**
 * @brief osMemProtPrv_ObjMpuSwitch -  Internal Function
 *
 * @param Prev
 * @param Next
 *
 * @return void
 */
void OsMemProtPrv_ObjMpuSwitch (AccessRightsIdType Prev, AccessRightsIdType Next)
{
	#if OS_CFG_MPU_SWITCH_OBJ == STD_ON

    if(Prev != Next)
    {
        OsMemProtPrv_MpuSwitchSafeSegments(Prev, Next);
    }
    #else
        (void)Prev;
        (void)Next;
    #endif
}

/**
 * @brief OsMemProt_GetAccessRights -  Internal Function
 *
 * @param Id
 *
 * @return OsMpuAccessGroupConfigRefType
 */

OsMpuAccessGroupConfigRefType OsMemProt_GetAccessRights(AccessRightsIdType Id)
{
    OsMpuAccessGroupConfigRefType pAccessRights = (OsMpuAccessGroupConfigRefType)NULL;
#if OsMaxAccessGroupIds > 0U
    if(Id < OsMaxAccessGroupIds)
    {
        pAccessRights = (OsMpuAccessGroupConfigRefType)&(OsMPUAccessGroupConfig[Id]);/*MISRA RULE 11.8 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    }
    else
    {
        OsErr_osApplicationErrorHook(OsDlt_OsInternalService, NULL, E_OS_ILLEGAL_ADDRESS);
    }
#endif
    return pAccessRights;
}

/***** This API should be called within critical section *********************************/
/**
 * @brief OsMemProt_MpuSwitch -  Internal Function
 *
 * @param
 *
 * @return void
 */

void OsMemProt_MpuSwitch(void)
{
    OsObjConfigRefType pPrevObj = OsCtrlParam.pLastObjRef; /*MISRA RULE 8.13 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    OsObjConfigRefType pNextObj = OsCtrlParam.pActiveObjRef;

    //Do not switch if we are in OS State
    if(OsMemProt_MPUState != OS_MPU_OS_STATE)
    {
        if(NULL_PTR != pPrevObj)
        {
            if(pPrevObj->AccessId != pNextObj->AccessId)
            {
                /* If App access check is required */
                OsMemProtPrv_AppMpuSwitch(pPrevObj->pAppRef->AccessId,pNextObj->pAppRef->AccessId);

                /* If Obj level access switch is enabled */
                OsMemProtPrv_ObjMpuSwitch(pPrevObj->AccessId,pNextObj->AccessId);
            }
        }
        else
        {
            OsErr_osApplicationErrorHook(OsDlt_OsInternalService, NULL, E_OS_ILLEGAL_ADDRESS);
        }
    }
}

void OsMemProt_MpuSwitchFromISR(void)
{
    OsObjConfigRefType pPrevObj = OsCtrlParam.pLastObjRef; /*MISRA RULE 8.13 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    OsObjConfigRefType pNextObj = OsCtrlParam.pActiveObjRef;

    //Do not switch if we are in OS State
    if(OsMemProt_MPUState != OS_MPU_OS_STATE)
    {
        if(pPrevObj != NULL_PTR)
        {
            if((OsAppRefListDyn[pPrevObj->pAppRef->AppId]->AccessId != OsAppRefListDyn[pNextObj->pAppRef->AppId]->AccessId))
            {
                /* If App access check is required */
                
                // OsMemProtPrv_AppMpuSwitch(pPrevObj->pAppRef->AccessId,pNextObj->pAppRef->AccessId);
                OsMemProtPrv_AppMpuSwitch(OsAppRefListDyn[pPrevObj->pAppRef->AppId]->AccessId,OsAppRefListDyn[pNextObj->pAppRef->AppId]->AccessId);

                /* If Obj level access switch is enabled */
                OsMemProtPrv_ObjMpuSwitch(pPrevObj->AccessId,pNextObj->AccessId);
            }
        }
        else
        {
            OsErr_osApplicationErrorHook(OsDlt_OsInternalService, NULL, E_OS_ILLEGAL_ADDRESS);
        }
    }
}

/**
 * @brief OsMemProt_MpuSwitchTrustedCall -  Internal Function
 *
 * @param Prev
 * @param Next
 *
 * @return void
 */

void OsMemProt_MpuSwitchTrustedCall (AccessRightsIdType Prev, AccessRightsIdType Next)
{
    if(Prev != Next)
    {
        OsMemProtPrv_MpuSwitchSafeSegments(Prev, Next);
    }
}

/**
 * @brief OsMemProt_ClearOSStateCntr -  Internal Function
 *
 *
 * @return void
 */


void OsMemProt_ClearOSStateCntr (void)
{
	return;
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
**   ****************************************************************************   **
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
**----------------------------------------------------------------------------------**/
