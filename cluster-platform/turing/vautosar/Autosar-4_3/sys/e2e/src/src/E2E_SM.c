/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2020. Visteon Corporation owns all rights to           *
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
#ifndef E2E_SM_C
#define E2E_SM_C
/*****************************************************************************
*  File Name         :  E2E_SM.c                                             *
*  Module Short Name :  E2E_SM                                               *
*  Description       :  This file contains E2E State Machine Implementation  *
*                       		                                             *
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
/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "E2E_SM.h"
/*****************************************************************************/
/*============================================================================
**
** Function Name    :   E2E_SMCheck
**
** Visibility       :   Public
**
** Description      :   It determines if the data can be used for safety-related application, based on history of checks performed by a
**                      corresponding E2E_P0XCheck() function. Checks the communication channel.
**
** Invocation       :
**
** Inputs           :   E2E_SMConfigType * ConfigPtr - Pointer to a configuration type.
**						E2E_PCheckStatusType ProfileStatus - Profile-independent status of the reception on one single Data in one cycle
**                      E2E_SMCheckStateType* StatePtr - Pointer to port/data communication state
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
#define E2ESM_CODE_SEC_START
#include "MemMap.h"

Std_ReturnType E2E_SMCheck(E2E_PCheckStatusType ProfileStatus, E2E_SMConfigType* ConfigPtr, E2E_SMCheckStateType* StatePtr)
{
    Std_ReturnType ret = 0U;
    if ( (StatePtr != NULL) && (ConfigPtr != NULL) )
    {
        ret = E2E_E_OK;
        switch (StatePtr->SMState)
        {
        case E2E_SM_VALID:
            if ((StatePtr->OkCount <= ConfigPtr->MaxErrorStateInit)&&(StatePtr->OkCount>=ConfigPtr->MinOkStateInit))
            {
                StatePtr->SMState = E2E_SM_VALID;
            }
            else
            {
                /*stay in E2E_SM_INVALID */
                StatePtr->SMState = E2E_SM_INVALID;
            }
            break;
        case E2E_SM_DEINIT:
            ret = E2E_E_WRONGSTATE;
            break;
        case E2E_SM_NODATA:
            if((ProfileStatus != E2E_P_ERROR) && (ProfileStatus != E2E_P_NONEWDATA))
            {
                StatePtr->SMState = E2E_SM_INIT;
            }
            else
            {
                StatePtr->SMState = E2E_SM_NODATA;
            }
            break;
        case E2E_SM_INIT:
            if (StatePtr->ErrorCount > ConfigPtr->MaxErrorStateInit)
            {
                StatePtr->SMState = E2E_SM_INVALID;
            }
            else if ((StatePtr->OkCount <= ConfigPtr->MaxErrorStateInit)&&(StatePtr->OkCount>=ConfigPtr->MinOkStateInit))
            {
                StatePtr->SMState = E2E_SM_VALID;
            }
            else
            {
                /*stay in E2E_SM_INIT */
                StatePtr->SMState = E2E_SM_INIT;
            }
            break;
        case E2E_SM_INVALID:
            if ((StatePtr->OkCount <= ConfigPtr->MaxErrorStateInit)&&(StatePtr->OkCount>=ConfigPtr->MinOkStateInit))
            {
                StatePtr->SMState = E2E_SM_VALID;
            }
            else
            {
                /*stay in E2E_SM_INVALID */
                StatePtr->SMState = E2E_SM_INVALID;
            }
            break;
        default:
            ret = E2E_E_INPUTERR_WRONG;
            break;
        }
    }
    else
    {
        ret = E2E_E_INPUTERR_NULL;
    }
    return ret;
}

/*============================================================================
**
** Function Name    :   E2E_SMCheckInit
**
** Visibility       :   Public
**
** Description      :   Initializes the state machine.
**
** Invocation       :
**
** Inputs           :   E2E_SMConfigType * ConfigPtr - Pointer to a configuration type.
**                      E2E_SMCheckStateType* StatePtr - Pointer to port/data communication state
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/

Std_ReturnType E2E_SMCheckInit(E2E_SMCheckStateType* StatePtr, E2E_SMConfigType* ConfigPtr)
{
    uint8 f1_index = 0U;
    Std_ReturnType ret = 0U;
    if((StatePtr != NULL) && (ConfigPtr != NULL))
    {
        for(f1_index = 0U; f1_index<ConfigPtr->WindowSize; f1_index++)
        {
            StatePtr->ProfileStatusWindow[f1_index] = (uint8)E2E_P_NOTAVAILABLE;
        }
        StatePtr->WindowTopIndex = 0u;
        StatePtr->OkCount = 0u;
        StatePtr->ErrorCount = 0u;
        StatePtr->SMState = E2E_SM_NODATA;
        ret = E2E_E_OK;
    }
    else
    {
        ret = E2E_E_INPUTERR_NULL;
    }
    return ret;
}
#define E2ESM_CODE_SEC_END
#include "MemMap.h"
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
Date               : 21-May-2020
CDSID              : pangraje
Traceability       : RTC #897020
Change Description : Initial Framework version of E2E Module with Profile2
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 10-May-2022
CDSID              : dbalasub
Traceability       : RTC #1654041
Change Description : Coverity & MISRA warning analysis and fix
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 09-Jun-2022
CDSID              : dbalasub
Traceability       : RTC #1683388
Change Description : Audit fix
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/
