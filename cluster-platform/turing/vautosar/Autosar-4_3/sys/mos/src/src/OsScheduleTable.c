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
 * @file        OsScheduleTable.c
 * @details     <b>Implements the Os Schedule Table functionality for Autosar 4.2.1</b>
 * @note
 *              Compiler    : GHS \n
 *              Target Hw   : Independent
 *
 * @copyright   Visteon (c) 2021
 *
 */

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/

#include "OsPrivate.h"
#include "OsScheduleTable.h"
#include "AssertLib.h"

#if (OS_CFG_SCHEDULE_TABLE == STD_ON) 
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define SCHEDULE_TABLE_PREEXPIRY_POINT			0xFFFFFFFFUL
#define SCHEDULE_TABLE_FINAL_DELAY              0xFFFFFFFFU
#define EXPIRY_POINT_PREVIOUS_OFFSET            1U
#define LAST_EXPIRY_POINT_INDEX_OFFSET          1U

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/


#define OS_INTVECT_BSS_NOCACHE_SEC_START
#include "Os_IntMemMap.h"
/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

#define OS_INTVECT_BSS_NOCACHE_SEC_END
#include "Os_IntMemMap.h"


#define OS_CORE_CODE_SEC_START
#define OS_CORE_CONST_SEC_START
#define OS_CORE_DATA_SEC_START
#define OS_CORE_BSS_SEC_START
#include "Os_IntMemMap.h"

/**
 * @brief OsStartScheduleTableAbs - Start Schedule Table with absolute value
 *
 * @param ScheduleTableID
 * @param Start
 *
 * @return StatusType
 */

StatusType OsStartScheduleTableAbs(ScheduleTableType ScheduleTableID, TickType Start)
{
    StatusType    Status = E_NOT_OK;

    if(ScheduleTableID < OsNumberOfScheduleTables)
    {
        OsSchTblParamRefType pThisSchedTbl = OsScheduleTableRefConfig[ScheduleTableID]->SchTblParam;

        if (pThisSchedTbl->Status != SCHEDULETABLE_STOPPED)
        {
            OsErr_osApplicationErrorHook(OsDlt_OsStartScheduleTableAbs, &Status, E_OS_STATE);
        }
        else if (Start == 0U) //|| greater than max cfg value
        {
            OsErr_osApplicationErrorHook(OsDlt_OsStartScheduleTableAbs, &Status, E_OS_VALUE);
        }
        else        /* Valid condition*/
        {
            pThisSchedTbl->CurrentExpiryPoint = SCHEDULE_TABLE_PREEXPIRY_POINT;
            pThisSchedTbl->NextTimestamp = Start;
            pThisSchedTbl->Status = SCHEDULETABLE_RUNNING;
            Status = E_OK;
        }
    }
    else
    {
        OsErr_osApplicationErrorHook(OsDlt_OsStartScheduleTableAbs, &Status, E_OS_ID);

    }
    return Status;
}

/**
 * @brief OsStartScheduleTableRel - Start Schedule Table with relative value
 *
 * @param ScheduleTableID
 * @param Start
 *
 * @return StatusType
 */

StatusType OsStartScheduleTableRel(ScheduleTableType ScheduleTableID, TickType Start)
{
    StatusType    Status = E_NOT_OK;
    TickType Value = 0;

    if(ScheduleTableID < OsNumberOfScheduleTables)
    {
        OsSchTblParamRefType pThisSchedTbl = OsScheduleTableRefConfig[ScheduleTableID]->SchTblParam;

        if (pThisSchedTbl->Status != SCHEDULETABLE_STOPPED)
        {
            OsErr_osApplicationErrorHook(OsDlt_OsStartScheduleTableRel, &Status, E_OS_STATE);
        }
        else if (Start == 0U) //|| greater than max cfg value
        {
            OsErr_osApplicationErrorHook(OsDlt_OsStartScheduleTableRel, &Status, E_OS_VALUE);
        }
        else        /* Valid condition*/
        {
            pThisSchedTbl->CurrentExpiryPoint = SCHEDULE_TABLE_PREEXPIRY_POINT;
            Status = GetCounterValue(OsScheduleTableRefConfig[ScheduleTableID]->CounterRef->CounterId, &Value);
            if(Status == (StatusType)E_OK)
            {
                // ssebast1; is counter overflow logic required here?
                pThisSchedTbl->NextTimestamp = Value + Start;
                pThisSchedTbl->Status = SCHEDULETABLE_RUNNING;
            }
        }
    }
    else
    {
        OsErr_osApplicationErrorHook(OsDlt_OsStartScheduleTableRel, &Status, E_OS_ID);
    }
    return Status;
}

/**
 * @brief OsStopScheduleTable - Stop Schedule Table 
 *
 * @param ScheduleTableID
 *
 * @return StatusType
 */

StatusType OsStopScheduleTable(ScheduleTableType ScheduleTableID)
{
    StatusType  Status = E_NOT_OK;

    if(ScheduleTableID < OsNumberOfScheduleTables)
    {
        OsSchTblParamRefType pThisSchedTbl = OsScheduleTableRefConfig[ScheduleTableID]->SchTblParam;
        if(pThisSchedTbl->Status == SCHEDULETABLE_STOPPED)
        {
            OsErr_osApplicationErrorHook(OsDlt_OsStopScheduleTable, &Status, E_OS_NOFUNC);
        }
        else
        {
            pThisSchedTbl->Status = SCHEDULETABLE_STOPPED;
            Status = E_OK;
        }
    }
    else
    {
        OsErr_osApplicationErrorHook(OsDlt_OsStopScheduleTable, &Status, E_OS_ID);
    }

    return Status;
}

/**
 * @brief OsNextScheduleTable - Switch Schedule Tables
 *
 * @param ScheduleTableID_From
 * @param ScheduleTableID_To
 *
 * @return StatusType
 */

StatusType OsNextScheduleTable(ScheduleTableType ScheduleTableID_From, ScheduleTableType ScheduleTableID_To)
{
    (void)ScheduleTableID_From;
    (void)ScheduleTableID_To;
    StatusType    Status = E_OS_SERVICE_NOT_SUPPORTED;
    //Service is not supported
    //Log as E_OS_SERVICE_NOT_SUPPORTED
    return Status;
}

/**
 * @brief OsGetScheduleTableStatus - Return the Schedule Table Status
 *
 * @param ScheduleTableID
 * @param ScheduleStatus
 *
 * @return StatusType
 */
StatusType OsGetScheduleTableStatus(ScheduleTableType ScheduleTableID, ScheduleTableStatusRefType ScheduleStatus)
{
    StatusType    Status = E_NOT_OK;
    if(ScheduleTableID < OsNumberOfScheduleTables)
    {
        *ScheduleStatus = OsScheduleTableRefConfig[ScheduleTableID]->SchTblParam->Status;
        Status = E_OK;
    }
    else
    {
        OsErr_osApplicationErrorHook(OsDlt_OsGetScheduleTableStatus, &Status, E_OS_ID);
    }
    return Status;
}

/**
 * @brief ProcessScheduleTable - Process configured schedule tables
 *
 * @param 
 *
 * @return StatusType
 */

void OsProcessScheduleTable(void)
{
    osuint32      ScheduleTableIndex = 0;
    osuint32      NoOfTasks = 0;
    osuint32      NoOfEvents = 0;
    osuint32      TaskIndex = 0;
    osuint32      EventIndex = 0;
    TaskType      EventTask = 0;
    EventMaskType EventMask = 0;
    StatusType    Status = 0;
    TickType      Value = 0;

    for(ScheduleTableIndex=0; ScheduleTableIndex<OsNumberOfScheduleTables ; ScheduleTableIndex++)
    {
        const OsScheduleTableConfigRefType pSchedTblConfig = OsScheduleTableRefConfig[ScheduleTableIndex];
        OsSchTblParamRefType const pSchedTblData = OsScheduleTableRefConfig[ScheduleTableIndex]->SchTblParam;

        if(pSchedTblData->Status == SCHEDULETABLE_RUNNING)
        {
            Status = GetCounterValue(pSchedTblConfig->CounterRef->CounterId, &Value);
            if(Status == (StatusType)E_OK)
            {
                if( pSchedTblData->CurrentExpiryPoint < pSchedTblConfig->NoOfExpiryPoint)
                {
                    if(pSchedTblData->NextTimestamp == Value)
                    {
                        /* Expiry Point Reached... Activate Task or Set Events */
                        NoOfTasks = pSchedTblConfig->ExpiryPointListRef[pSchedTblData->CurrentExpiryPoint].NoOfTaskActivate;
                        if(NoOfTasks != 0U)
                        {
                            for(TaskIndex=0; TaskIndex<NoOfTasks; TaskIndex++)
                            {
                                (void)osSysActivateTask(pSchedTblConfig->ExpiryPointListRef[pSchedTblData->CurrentExpiryPoint].TaskActivateListRef[TaskIndex].ActivateTaskRef->TasksID);
                            }
                        }
                        NoOfEvents = pSchedTblConfig->ExpiryPointListRef[pSchedTblData->CurrentExpiryPoint].NoOfEventSet;
                        if(NoOfEvents != 0U)
                        {
                            for(EventIndex=0; EventIndex<NoOfEvents; EventIndex++)
                            {
                                EventTask = pSchedTblConfig->ExpiryPointListRef[pSchedTblData->CurrentExpiryPoint].EventSetListRef[EventIndex].EventTaskRef->TasksID;
                                EventMask = pSchedTblConfig->ExpiryPointListRef[pSchedTblData->CurrentExpiryPoint].EventSetListRef[EventIndex].EventMask;
                                (void)osSysSetEvent(EventTask, EventMask); /*MISRA RULE 17.7 VIOLATION: This is the reason why the MISRA rule could not be followed in this special case*/
                            }
                        }
                        /* Schedule next Expiry Point */
                        pSchedTblData->CurrentExpiryPoint++;
                        if( pSchedTblData->CurrentExpiryPoint < pSchedTblConfig->NoOfExpiryPoint)
                        {
                            /* Expiry Point end not reached.... Continue... */
                            if(pSchedTblConfig->ExpiryPointListRef[pSchedTblData->CurrentExpiryPoint].ExpPointOffset != 0U)
                            {
                                osuint32 PreviousExPoIndex = pSchedTblData->CurrentExpiryPoint - EXPIRY_POINT_PREVIOUS_OFFSET;
                                pSchedTblData->NextTimestamp += (pSchedTblConfig->ExpiryPointListRef[pSchedTblData->CurrentExpiryPoint].ExpPointOffset - pSchedTblConfig->ExpiryPointListRef[PreviousExPoIndex].ExpPointOffset);
                            }
                            else
                            {
                                DEBUG_ASSERT( FALSE );
                            }
                        }
                        else
                        {
                            /* End of Expiry Points... Execute Final Delay ... */
                            osuint8 LastExPoIndex = pSchedTblConfig->NoOfExpiryPoint - LAST_EXPIRY_POINT_INDEX_OFFSET;
                            TickType LastExPoOffset = pSchedTblConfig->ExpiryPointListRef[LastExPoIndex].ExpPointOffset;
                            if((pSchedTblData->NextTimestamp + (pSchedTblConfig->SchedTblDuration - LastExPoOffset)) < SCHEDULE_TABLE_FINAL_DELAY)
                            {
                                pSchedTblData->NextTimestamp += pSchedTblConfig->SchedTblDuration - LastExPoOffset;
                            }
                            else
                            {
                                DEBUG_ASSERT( FALSE );
                            }
                        }
                    }
                    else
                    {
                        /* Do nothing. Offset didnt match with Counter value */
                    }
                }
                if(pSchedTblData->CurrentExpiryPoint == pSchedTblConfig->NoOfExpiryPoint)
                {
                    /* Wait for Final Delay ... */
                    if(pSchedTblData->NextTimestamp == Value)
                    {
                        /* Final Delay over */
                        pSchedTblData->CurrentExpiryPoint = 0;
                        if(pSchedTblConfig->OsSchedTblRepeating != FALSE)
                        {
                            if(pSchedTblConfig->ExpiryPointListRef[pSchedTblData->CurrentExpiryPoint].ExpPointOffset != 0U)
                            {
                                pSchedTblData->NextTimestamp = pSchedTblConfig->ExpiryPointListRef[pSchedTblData->CurrentExpiryPoint].ExpPointOffset;
                            }
                            else
                            {
                                DEBUG_ASSERT( FALSE );
                            }
                            if(pSchedTblConfig->SyncConfigRef->SchTblSyncType == SCHEDULETABLE_SYNC_IMPLICIT)
                            {
                                (void)osResetCounter(pSchedTblConfig->CounterRef->CounterId);
                            }
                            else
                            {
                                /* SCHEDULETABLE_SYNC_EXPLICIT NOT SUPPORTED */
                            }
                        }
                        else
                        {
                            /* Schedule Table is Single-Shot. Stop the Schedule Table */
                            pSchedTblData->NextTimestamp = 0;
                            pSchedTblData->Status = SCHEDULETABLE_STOPPED;
                        }
                    }
                    else
                    {
                        /* Do nothing. Waiting for Final delay */
                    }
                }
                else if(pSchedTblData->CurrentExpiryPoint == SCHEDULE_TABLE_PREEXPIRY_POINT)
                {
                    /* SCHEDULE_TABLE_PREEXPIRY_POINT. Start the first expiry point offset here. */
                    if(pSchedTblData->NextTimestamp == Value)
                    {
                        pSchedTblData->CurrentExpiryPoint = 0;
                        if(pSchedTblConfig->ExpiryPointListRef[pSchedTblData->CurrentExpiryPoint].ExpPointOffset != 0U)
                        {
                            pSchedTblData->NextTimestamp = pSchedTblData->NextTimestamp + pSchedTblConfig->ExpiryPointListRef[pSchedTblData->CurrentExpiryPoint].ExpPointOffset;
                        }
                        else
                        {
                            DEBUG_ASSERT( FALSE );
                        }
                    }
                }
                else
                {
                    /* Do nothing. Shall not reach here. */
                }
            }
            else
            {
                /* Do nothing. OsCounter not working */
            }
        }
        else
        {
            /* Do nothing. Schedule table is not in RUNNING state */
        }
    }
}

#define OS_CORE_CODE_SEC_END
#define OS_CORE_CONST_SEC_END
#define OS_CORE_DATA_SEC_END
#define OS_CORE_DATA_NOCACHE_SEC_END
#define OS_CORE_BSS_SEC_END
#include "Os_IntMemMap.h"
#endif /* #if (OS_CFG_SCHEDULE_TABLE == STD_ON)  */
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
Date               : 26-Jul-19
CDSID              : ssebast1
Traceability       : 
Change Description : Initial version
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 13-July-2020
CDSID              : ssukuma1
Traceability       : 951142
Change Description : ASIL B - Optimizations on ProcessScheduleTable
-----------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------
Date              : 26/March/2022
By                : gthanapp
Traceability      : RTC #1564070
Change Description: Cert-C warning analysis and fix
----------------------------------------------------------------------------------------------------------------------*/
/**   Date              : 13-May-2022                                                **
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
