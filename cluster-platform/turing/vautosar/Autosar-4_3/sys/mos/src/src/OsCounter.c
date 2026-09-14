
/**
 * @file        OsCounter.c
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
 * @details     <b>Implements the Counter concepts of Autosar 4.2.1</b>
 * @note
 *              Compiler    : GHS \n
 *              Target Hw   : Independent
 * @date        11 July, 2019
 *
 * @copyright   Visteon (c) 2021
 *
 */

#ifndef OS_COUNTER_C
#define OS_COUNTER_C

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "OsMain.h"
#include "OsPrivate.h"

//@cond
#define OS_CORE_CODE_SEC_START
#define OS_CORE_CONST_SEC_START
#define OS_CORE_DATA_SEC_START
#define OS_CORE_BSS_SEC_START
//@endcond
#include "Os_IntMemMap.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

#define OSCOUNTER_INC_BY_ONE                   1U
#define OSMAXALLOWEDVALUE                      (0xffffffffUL)

/**
 * @brief Internal Funciton
 *
 */
void osIncrementHardwareCounters (void)
{
    CounterType i=0;
    for(i = 0; i< osMaxCounterId; i++)
    {
        if(CounterRefConfig[i]->OsCounterType == HARDWARE)
        {
            CounterRefConfig[i]->OsCounterParam->TickCount = CounterRefConfig[i]->OsCounterParam->TickCount + OSCOUNTER_INC_BY_ONE;
        }
    }
}


/**
 * @brief This service increments a software counter
 * @remarks Synchronous, may cause rescheduling
 * @param CounterId - The Counter to be incremented
 * @return StatusType
 *          E_OK: No errors
 *          E_OS_ID (only in EXTENDED status): The CounterID was not valid or
 *          counter is implemented in hardware and can not be incremented by software
 */
StatusType OsIncrementCounter (CounterType CounterId)
{
    StatusType retVal = E_NOT_OK;
    if (CounterId >= osMaxCounterId)
    {
        retVal = E_OS_ID;
    }
    else
    {
        if(CounterRefConfig[CounterId]->OsCounterType == HARDWARE)
    {
        retVal = E_OS_ID;
    }
    else
    {
        SuspendAllInterrupts();
        CounterRefConfig[CounterId]->OsCounterParam->TickCount = CounterRefConfig[CounterId]->OsCounterParam->TickCount + OSCOUNTER_INC_BY_ONE;
        ResumeAllInterrupts();
        retVal = E_OK;
    }
    }
    if(retVal != (StatusType)E_OK)
    {
        OsErr_osApplicationErrorHook(OsDlt_OsIncrementCounter, &retVal, E_OS_ID);
    }
    return retVal;
}

/**
 * @brief   This service reads the current count value of a counter (returning either the
 *          hardware timer ticks if counter is driven by hardware or the software ticks when
 *          user drives counter).
 * @remark  Synchronous, Re-entrant
 * @param CounterId - The Counter which tick value should be read
 * @param ValueRef - Contains the current tick value of the counter
 * @return StatusType
 *          E_OK: No errors
 *          E_OS_ID (only in EXTENDED status): The <CounterID> was not valid
 */
StatusType OsGetCounterValue (CounterType CounterID, TickRefType Value)
{
    TickType tempVal = 0;
    StatusType retVal = E_NOT_OK;

    if (CounterID < osMaxCounterId)
    {
        SuspendAllInterrupts();
        tempVal = CounterRefConfig[CounterID]->OsCounterParam->TickCount;
        *Value = tempVal;
        ResumeAllInterrupts();
        retVal = E_OK;
    }
    else
    {
        OsErr_osApplicationErrorHook(OsDlt_OsGetCounterValue, &retVal, E_OS_ID);
    }

    return retVal;
}

/**
 * @brief   This service gets the number of ticks between the current tick value and a
 *          previously read tick value.
 * @remark  Synchronous, Reentrant
 * @param CounterId     The counter to be read
 * @param ValueRef      in: the previously read tick value of the counter \n
 *                      out: the current tick value of the counter
 * @param ElapsedValRef out: the current tick value of the counter
 * @return StatusType   E_OK: No errors
 *                      E_OS_ID (only in EXTENDED status): The CounterID was not valid
 *                      E_OS_VALUE (only in EXTENDED status): The given Value was not valid
 */
StatusType OsGetElapsedValue (CounterType CounterID, TickRefType Value, TickRefType ElapsedValue)
{
    TickType now = 0;
    StatusType retVal = E_NOT_OK;

    if((NULL_PTR == Value) || (NULL_PTR == ElapsedValue))
    {
        OsErr_osApplicationErrorHook(OsDlt_OsGetElapsedValue, &retVal, E_NOT_OK);
    }
    else if ((*Value > OSMAXALLOWEDVALUE) || (*ElapsedValue > OSMAXALLOWEDVALUE))
    {
        OsErr_osApplicationErrorHook(OsDlt_OsGetElapsedValue, &retVal, E_OS_VALUE);
    }
    else if (CounterID < osMaxCounterId)
    {
        SuspendAllInterrupts();
        now = CounterRefConfig[CounterID]->OsCounterParam->TickCount;

        //todo: OSMAXALLOWEDVALUE checks need to modified for counter specific max values
        if(now < 0xffffffffU) 
        {
        while(now > OSMAXALLOWEDVALUE)
        {
            now -= (OSMAXALLOWEDVALUE + OSCOUNTER_INC_BY_ONE); /*MISRA RULE 12.4 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
            }
        }
        if (now < (*Value))
        {
            *ElapsedValue = ((OSMAXALLOWEDVALUE - (*Value)) + OSCOUNTER_INC_BY_ONE) + now;
        }
        else
        {
            *ElapsedValue = now - (*Value);
        }
        *Value = now;

        ResumeAllInterrupts();

        retVal = E_OK;
    }
    else
    {
        OsErr_osApplicationErrorHook(OsDlt_OsGetElapsedValue, &retVal, E_OS_ID);
    }

    return retVal;
}

/**
 * @brief Internal Service
 *
 * @param CounterId
 * @return StatusType
 */
StatusType osResetCounter (CounterType CounterId)
{
    StatusType retVal = E_NOT_OK;

    if (CounterId < osMaxCounterId)
    {
        SuspendAllInterrupts();
        CounterRefConfig[CounterId]->OsCounterParam->TickCount = 0;
        ResumeAllInterrupts();
        retVal = E_OK;
    }
    else
    {
        OsErr_osApplicationErrorHook(OsDlt_osResetCounter, &retVal, E_OS_ID);
    }
    return retVal;
}

//@cond
#define OS_CORE_CODE_SEC_END
#define OS_CORE_CONST_SEC_END
#define OS_CORE_DATA_SEC_END
#define OS_CORE_DATA_NOCACHE_SEC_END
#define OS_CORE_BSS_SEC_END
//@endcond
#include "Os_IntMemMap.h"

#endif /* OS_MAIN_C */
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
**   Date              : 11-Jul-2019                                                **
**   CDSID             : vbalakr3                                                   **
**   Traceability      :                                                            **
**   RTC Version       : ------                                                     **
**   Change Description: Initial version.                                           **
**   ------------------------------------------------------------------------------ **
**   Date              : 16-Jan-2020                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Version       : 718485                                                     **
**   Change Description: MISRA Warning Fix                                          **
**   ------------------------------------------------------------------------------ **
**   Date              : 18-Aug-2020                                                **
**   CDSID             : ssukuma1                                                   **
**   RTC Id            : 966911                                                     **
**   Change Description: MISRA Warning fix                                          **
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
