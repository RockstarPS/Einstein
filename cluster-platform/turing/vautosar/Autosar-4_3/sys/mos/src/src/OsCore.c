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
 * @file        OsCore.c
 * @details     <b>Implements the Os Core concepts of Autosar 4.2.1</b>
 * @note
 *              Compiler    : GHS \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2021
 *
 */
#ifndef OS_CORE_C
#define OS_CORE_C

/************************************* Includes **********************************/
#include "OsMain.h"
#include "AssertLib.h"

#define OS_CORE_CODE_SEC_START
#define OS_CORE_CONST_SEC_START
#define OS_CORE_DATA_SEC_START
#define OS_CORE_BSS_SEC_START
#include "Os_IntMemMap.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/



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
static OsCoreParamType OsCoreParam[OsNumberOfCores];


/*****************************************************************************
*                         Global Function Definitions                        *
******************************************************************************/

/**
 * @brief Internal function - OsCore_InitMem 
 * @param 
 * @return void
 */

void OsCore_InitMem (void)
{
    CoreIdType Core = 0;
    for (Core=0;Core<OsNumberOfCores;Core++)
    {
        OsCoreParam[Core].State = CORE_NOT_STARTED;
    }
}

/**
 * @brief Internal function - OsCore_GetCurrentCore 
 * @param 
 * @return void
 */

CoreIdType OsCore_GetCurrentCore (void)
{
    CoreIdType CoreId = (CoreIdType)OS_CFG_CORE_COREINVALID; 
    const OsObjConfigRefType pOwnObj = OsGetCurrentObj(); /*MISRA RULE 8.13 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
    if(NULL_PTR != pOwnObj)
    {
        CoreId = pOwnObj->CoreId;
    }
    return CoreId;
}

/**
 * @brief Internal function - OsGetNumberOfActivatedCores 
 *
 * @param 
 * @return uint32
 */

uint32 OsGetNumberOfActivatedCores(void)
{
    uint32 RetCores=0;
    uint32 Idx=0;

    for (Idx=0;Idx<OsNumberOfCores;Idx++)
    {
        if(OsCoreParam[Idx].State == CORE_STARTED)
        {
            RetCores++;
        }
    }
    return RetCores;
}

/**
 * @brief Internal function - OsGetCoreId
 *
 * @param 
 * @return CoreIdType
 */

CoreIdType OsGetCoreId(void)
{
    CoreIdType CoreId = OsCore_GetCurrentCore();
   return (CoreId);
}

/**
 * @brief Internal function - OsStartCore
 *
 * @param CoreId
 * @param StatusRef
 * @return void
 */

void OsStartCore(CoreIdType CoreId, StatusType* StatusRef)
{
    *StatusRef = E_OS_ID;
    if(CoreId < OsNumberOfCores)
    {
    const OsCoreConfigRefType pCore = (OsCoreRefConfig[CoreId]);

    //Todo: Check if this call is OS Start
    if(OsCoreParam[CoreId].State == CORE_STARTED)
    {
        *StatusRef = E_OS_STATE;
    }
    else
    {
		if (FALSE == OsCoreRefConfig[CoreId]->IsAsrCore)
		{
			*StatusRef = E_OS_STATE;
		}
		else
		{
        if(NULL_PTR != pCore->pHookRef->StartHook)
        {
            pCore->pHookRef->StartHook();
        }
        if(NULL_PTR != pCore->pHookRef->PreHook )
        {
            pCore->pHookRef->PreHook();
        }
        //start the core
        //right now no implementation to start core
        //set the state as started
        OsCoreParam[CoreId].State = CORE_STARTED;
        *StatusRef = E_OK;
        if(NULL_PTR != pCore->pHookRef->PostHook)
        {
            pCore->pHookRef->PostHook();
        }
        }
    }
    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }
}

/**
 * @brief Internal function - OsStartNonAutosarCore
 *
 * @param CoreId
 * @param StatusRef
 * @return void
 */

void OsStartNonAutosarCore(CoreIdType CoreId, StatusType* StatusRef)
{
    *StatusRef = E_OS_ID;
    if(CoreId < OsNumberOfCores)
    {
     if(OsCoreParam[CoreId].State == CORE_STARTED)
    {
        *StatusRef = E_OS_STATE;
    }
    else
    {
        OsCoreParam[CoreId].State = CORE_STARTED;
        *StatusRef = E_OK;
    }
    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }
}


#define OS_CORE_CODE_SEC_END
#define OS_CORE_CONST_SEC_END
#define OS_CORE_DATA_SEC_END
#define OS_CORE_DATA_NOCACHE_SEC_END
#define OS_CORE_BSS_SEC_END
#include "Os_IntMemMap.h"

#endif  /* End of File */
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

