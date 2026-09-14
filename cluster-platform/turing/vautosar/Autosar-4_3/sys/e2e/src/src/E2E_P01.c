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
#ifndef E2E_P01_C
#define E2E_P01_C
/*****************************************************************************
*  File Name         :  E2E_P01.c                                            *
*  Module Short Name :  E2E_P01                                              *
*  Description       :  This file contains E2E Profile 2 Implementation      *
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
#include "E2E_P01.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define E2E_P01_MAX_COUNTER_LIMIT       14u

#define E2E_P01_MAX_VAL_8BITu           0xffu
#define E2E_P01_MAX_VAL_8BIT            0xffu
#define E2E_P01_INC_BY_1U               1u
#define E2E_P01_DEC_BY_1U               1u
#define E2E_P01_VAL_1U                  1u
#define E2E_P01_VAL_240U                240u
#define E2E_P01_MOD_BY_2U               2u
#define E2E_P01_MOD_BY_8U               8u
#define E2E_P01_MOD_BY_15U              15u
#define E2E_P01_VAL_0xf0u               0xf0u
#define E2E_P01_VAL_0x0fu               0x0fu
#define E2E_P01_SHIFT_BY_8U             8U
#define E2E_P01_SHIFT_BY_3U             3U
#define E2E_P01_SHIFT_BY_4U             4U
/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
static uint8 E2E_P01ComputeCRC(const uint8* DataPtr,const E2E_P01ConfigType* ConfigPtr, uint8 Counter);
static void E2E_ProcessDeltaCounter(const E2E_P01ConfigType* ConfigPtr, E2E_P01CheckStateType* StatePtr, uint8 ReceivedCounter);
static void E2E_UpdateSyncStatus(const E2E_P01ConfigType* ConfigPtr,E2E_P01CheckStateType* StatePtr);


#define E2EP01_CODE_SEC_START
#include "MemMap.h"
/*============================================================================
**
** Function Name    :   E2E_P01ComputeCRC
**
** Visibility       :   Private
**
** Description      :   Computes CRC over a given data, and DataID
**
**
** Invocation       :
**
** Inputs           :   E2E_P01ConfigType * ConfigPtr - Pointer to a configuration type.
**						uint8  Counter - Counter
**						uint8 * DataPtr - Data Pointer.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
static uint8 E2E_P01ComputeCRC(const uint8* DataPtr,const E2E_P01ConfigType* ConfigPtr, uint8 Counter)
{
    uint8 CRC = 0U;
    uint8 EvaluatedDataID = 0U;
    uint16 EvaluatedOffset = 0U;
    uint16 EvaluatedDataLen = 0U;

    /* Compute CRC over DataID, depending on DataIdMode*/
    switch (ConfigPtr->DataIDMode)
    {
    case E2E_P01_DATAID_BOTH:
        EvaluatedDataID = (uint8)(ConfigPtr->DataID & E2E_P01_MAX_VAL_8BITu);
        CRC = Crc_CalculateCRC8 (&EvaluatedDataID, E2E_P01_VAL_1U, E2E_P01_MAX_VAL_8BIT, FALSE);
        EvaluatedDataID = (uint8)(ConfigPtr->DataID >> E2E_P01_SHIFT_BY_8U) & E2E_P01_MAX_VAL_8BITu;
        CRC = Crc_CalculateCRC8 (&EvaluatedDataID, E2E_P01_VAL_1U, CRC, FALSE); /* CRC over 2 bytes*/
        break;
    case E2E_P01_DATAID_LOW:
        EvaluatedDataID = (uint8)(ConfigPtr->DataID & E2E_P01_MAX_VAL_8BITu);
        CRC = Crc_CalculateCRC8 (&EvaluatedDataID, E2E_P01_VAL_1U, E2E_P01_MAX_VAL_8BIT, FALSE); /*CRC over lower byte only*/
        break;
    case E2E_P01_DATAID_NIBBLE:
        EvaluatedDataID = (uint8)(ConfigPtr->DataID & E2E_P01_MAX_VAL_8BITu);
        CRC = Crc_CalculateCRC8 (&EvaluatedDataID, E2E_P01_VAL_1U, E2E_P01_MAX_VAL_8BIT, FALSE);
        EvaluatedDataID = 0u;
        CRC = Crc_CalculateCRC8 (&EvaluatedDataID, E2E_P01_VAL_1U, CRC, FALSE);
        break;
    case E2E_P01_DATAID_ALT:
        if ((Counter % E2E_P01_MOD_BY_2U) == 0u) /* Alternate inclusions depending upon Parity counter*/
        {
            EvaluatedDataID = (uint8)(ConfigPtr->DataID & E2E_P01_MAX_VAL_8BITu);
            CRC = Crc_CalculateCRC8 (&EvaluatedDataID, E2E_P01_VAL_1U, E2E_P01_MAX_VAL_8BIT, FALSE);
        }
        else
        {
            EvaluatedDataID = (uint8)(ConfigPtr->DataID >> E2E_P01_SHIFT_BY_8U) & E2E_P01_MAX_VAL_8BITu;
            CRC = Crc_CalculateCRC8 (&EvaluatedDataID, E2E_P01_VAL_1U, E2E_P01_MAX_VAL_8BIT, FALSE);
        }
        break;
    default: /* if DataIDMode is not known/valid */
        break;
    }

    EvaluatedOffset = ConfigPtr->CRCOffset >> E2E_P01_SHIFT_BY_3U;
    if ((EvaluatedOffset) > 0u)
    {
        CRC = Crc_CalculateCRC8 ( DataPtr, EvaluatedOffset, CRC, FALSE);
    }
    EvaluatedDataLen = ConfigPtr->DataLength >> E2E_P01_SHIFT_BY_3U;
    if (EvaluatedOffset < (EvaluatedDataLen - E2E_P01_DEC_BY_1U))
    {
        CRC = Crc_CalculateCRC8 ( &DataPtr[EvaluatedOffset + E2E_P01_INC_BY_1U], (uint32)((uint32)(EvaluatedDataLen) - (uint32)(EvaluatedOffset) - E2E_P01_DEC_BY_1U), CRC, FALSE);
    }

    return CRC ^ E2E_P01_MAX_VAL_8BITu;
}

/*============================================================================
**
** Function Name    :   E2E_ProcessDeltaCounter
**
** Visibility       :   Private
**
** Description      :   Provides further checks with respect to Sync
**
** Invocation       :
**
** Inputs           :   E2E_P01ConfigType * ConfigPtr - Pointer to a configuration type.
**						E2E_P01CheckStateType * StatePtr - Pointer to CheckSate type.
**                      uint8 ReceivedCounter - Received counter value
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
static void E2E_ProcessDeltaCounter(const E2E_P01ConfigType* ConfigPtr, E2E_P01CheckStateType* StatePtr, uint8 ReceivedCounter)
{
    uint8 DeltaCounter = 0U;

    DeltaCounter = (((ReceivedCounter) - (StatePtr->LastValidCounter)) & (E2E_P01_VAL_0x0fu)); /* Lower Nibble */

    if (DeltaCounter == 0u)
    {
        if (StatePtr->NoNewOrRepeatedDataCounter < E2E_P01_MAX_COUNTER_LIMIT)
        {
            StatePtr->NoNewOrRepeatedDataCounter++;
        }
        StatePtr->Status = E2E_P01STATUS_REPEATED;
    }
    else
    {
        if (DeltaCounter == E2E_P01_VAL_1U)
        {
            StatePtr->MaxDeltaCounter = ConfigPtr->MaxDeltaCounterInit;
            StatePtr->LastValidCounter = ReceivedCounter;
            StatePtr->LostData = 0u;
            StatePtr->Status = E2E_P01STATUS_OK;
            E2E_UpdateSyncStatus (ConfigPtr, StatePtr);
        }
        else
        {
            /* No subsequent data received, delta counter is within range */
            if (DeltaCounter <= StatePtr->MaxDeltaCounter)
            {
                StatePtr->MaxDeltaCounter = ConfigPtr->MaxDeltaCounterInit;
                StatePtr->LastValidCounter = ReceivedCounter;
                StatePtr->LostData = DeltaCounter - E2E_P01_DEC_BY_1U;
                StatePtr->Status = E2E_P01STATUS_OKSOMELOST;
                E2E_UpdateSyncStatus (ConfigPtr, StatePtr);
            }
            else
            {
                /* Incorrect sequence of Data received */
                StatePtr->NoNewOrRepeatedDataCounter = 0u;
                StatePtr->SyncCounter = ConfigPtr->SyncCounterInit;
                if (StatePtr->SyncCounter > 0u)
                {
                    StatePtr->MaxDeltaCounter = ConfigPtr->MaxDeltaCounterInit;
                    StatePtr->LastValidCounter = ReceivedCounter;
                }
                StatePtr->Status = E2E_P01STATUS_WRONGSEQUENCE;
            }
        }
    }
}

/*============================================================================
**
** Function Name    :   E2E_UpdateSyncStatus
**
** Visibility       :   Private
**
** Description      :   Provides further checks with respect to Sync
**
** Invocation       :
**
** Inputs           :   E2E_P01ConfigType * ConfigPtr - Pointer to a configuration type.
**						E2E_P01CheckStateType * StatePtr - Pointer to CheckSate type.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
static void E2E_UpdateSyncStatus(const E2E_P01ConfigType* ConfigPtr,E2E_P01CheckStateType* StatePtr)
{
    if (StatePtr->NoNewOrRepeatedDataCounter <= ConfigPtr->MaxNoNewOrRepeatedData)
    {
        StatePtr->NoNewOrRepeatedDataCounter = 0u;
        if (StatePtr->SyncCounter > 0u)
        {
            StatePtr->SyncCounter--;
            StatePtr->Status = E2E_P01STATUS_SYNC;
        }
    }
    else
    {
        StatePtr->NoNewOrRepeatedDataCounter = 0u;
        StatePtr->SyncCounter = ConfigPtr->SyncCounterInit;
        StatePtr->Status = E2E_P01STATUS_SYNC;
    }
}

/*============================================================================
**
** Function Name    :   E2E_P01Protect
**
** Visibility       :   Public
**
** Description      :   Protects the array/buffer to be transmitted using the E2E profile 1.
**						This includes checksum calculation, handling of sequence counter and Data ID.
**
** Invocation       :
**
** Inputs           :   E2E_P01ConfigType * ConfigPtr - Pointer to a configuration type.
**						E2E_P01ProtectStateType * StatePtr - Pointer to ProtectState type.
**						uint8 * DataPtr - Data Pointer.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
Std_ReturnType E2E_P01Protect(E2E_P01ConfigType* ConfigPtr, E2E_P01ProtectStateType* StatePtr, uint8* DataPtr)
{
    Std_ReturnType ret = E2E_E_INPUTERR_WRONG;
    uint8 ComputedCRC = 0u;
    uint16 CRCOffset = 0U;

    if ((ConfigPtr != NULL) && (StatePtr != NULL) && (DataPtr != NULL))
    {
        if(((ConfigPtr->DataLength % E2E_P01_MOD_BY_8U) == 0u) && (ConfigPtr->DataLength != 0u) && (ConfigPtr->DataLength <= E2E_P01_VAL_240U))
            /*The DataLength is a multiple of 8 bits, and not equal to 0*/
        {
            if (StatePtr->Counter > E2E_P01_MAX_COUNTER_LIMIT)
            {
                ret = E2E_E_INPUTERR_WRONG;
            }
            else
            {
                ret = E2E_E_OK;
                CRCOffset = ConfigPtr->CounterOffset >> E2E_P01_SHIFT_BY_3U;
                /*Write the counter in the Data, at the configured CounterOffset*/
                if ((ConfigPtr->CounterOffset >> E2E_P01_SHIFT_BY_3U) == 0u)
                {
                    DataPtr[CRCOffset] = (DataPtr[CRCOffset] & E2E_P01_VAL_0xf0u) | (StatePtr->Counter & E2E_P01_VAL_0x0fu); /*The counter goes into low nibble of Data*/
                }

                else
                {
                    DataPtr[CRCOffset] = (DataPtr[CRCOffset] & E2E_P01_VAL_0x0fu) | ((StatePtr->Counter << E2E_P01_SHIFT_BY_4U) & E2E_P01_VAL_0xf0u); /*The counter goes into high nibble of Data*/
                }

                /*Write the low nibble of high byte of Data ID*/
                if (ConfigPtr->DataIDMode == E2E_P01_DATAID_NIBBLE)
                {
                    CRCOffset = ConfigPtr->DataIDNibbleOffset >> E2E_P01_SHIFT_BY_3U;
                    if ((ConfigPtr->DataIDNibbleOffset >> E2E_P01_SHIFT_BY_3U) == 0u)
                    {
                        DataPtr[CRCOffset] = ((DataPtr[CRCOffset] & E2E_P01_VAL_0xf0u)| ((uint8)(ConfigPtr->DataID >> E2E_P01_SHIFT_BY_8U) & E2E_P01_VAL_0x0fu));
                    }
                    else
                    {
                        DataPtr[CRCOffset] = ((DataPtr[CRCOffset] & E2E_P01_VAL_0x0fu)| ((uint8)(ConfigPtr->DataID >> E2E_P01_SHIFT_BY_4U) & E2E_P01_VAL_0xf0u));
                    }
                }

                ComputedCRC = E2E_P01ComputeCRC ( DataPtr, ConfigPtr, StatePtr->Counter); /*Calculate CRC over data*/

                DataPtr[ConfigPtr->CRCOffset >> E2E_P01_SHIFT_BY_3U] = ComputedCRC; /* CRC is written to the Data at configured location*/
                StatePtr->Counter = (StatePtr->Counter+E2E_P01_INC_BY_1U) % E2E_P01_MOD_BY_15U; /*Increment the counter modulo 15 (i.e. next value after 14 is 0)*/
            }
        }
        else
        {
            ret = E2E_E_INPUTERR_WRONG;
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
** Function Name    :   E2E_P01ProtectInit
**
** Visibility       :   Public
**
** Description      :   Initializes the Counter.
**
** Invocation       :
**
** Inputs           :   E2E_P01ProtectStateType * StatePtr - Pointer to ProtectState type.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
Std_ReturnType E2E_P01ProtectInit(E2E_P01ProtectStateType* StatePtr)
{
    Std_ReturnType ret = E2E_E_INPUTERR_WRONG;
    if (StatePtr != NULL)
    {
        StatePtr->Counter = 0u;
        ret = E2E_E_OK;
    }
    else
    {
        ret = E2E_E_INPUTERR_NULL;
    }
    return ret;
}

/*============================================================================
**
** Function Name    :   E2E_P01Check
**
** Visibility       :   Public
**
** Description      :   Check the array/buffer using the E2E profile 1. This includes checksum
**						calculation, handling of sequence counter and Data ID.
**
** Invocation       :
**
** Inputs           :   E2E_P01ConfigType * ConfigPtr - Pointer to a configuration type.
**						E2E_P01CheckStateType * StatePtr - Pointer to CheckSate type.
**						uint8 * DataPtr - Data Pointer.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
Std_ReturnType E2E_P01Check(E2E_P01ConfigType* ConfigPtr, E2E_P01CheckStateType* StatePtr, uint8* DataPtr)
{

    Std_ReturnType ret = E2E_E_INPUTERR_WRONG;
    uint8  ReceivedCounter = 0u;
    uint8  ReceivedDataIDNibble = 0u;
    uint8  ComputedCRC = 0u;
    uint8  ReceivedCRC = 0u;
    uint16 ComputedOffset = 0u;

    if ((ConfigPtr != NULL) && (StatePtr != NULL) && (DataPtr != NULL))
    {
        if(((ConfigPtr->DataLength % E2E_P01_MOD_BY_8U) == 0u) && (ConfigPtr->DataLength != 0u) && (ConfigPtr->DataLength <= E2E_P01_VAL_240U))
        {
            if ((StatePtr->LastValidCounter > E2E_P01_MAX_COUNTER_LIMIT)||(StatePtr->MaxDeltaCounter > E2E_P01_MAX_COUNTER_LIMIT)||(StatePtr->SyncCounter > ConfigPtr->SyncCounterInit)||(StatePtr->NoNewOrRepeatedDataCounter > E2E_P01_MAX_COUNTER_LIMIT))
            {
                ret = E2E_E_INPUTERR_WRONG;
            }
            else
            {
                ret = E2E_E_OK;
                if (StatePtr->MaxDeltaCounter < E2E_P01_MAX_COUNTER_LIMIT)
                {
                    StatePtr->MaxDeltaCounter++; /* At every function invocation, the maximum allowed delta between previous and current Counter is incremented*/
                }
                if (FALSE != StatePtr->NewDataAvailable) /* If any NEW data is available to be checked*/
                {
                    ComputedOffset  = ConfigPtr->CounterOffset >> E2E_P01_SHIFT_BY_3U; /* Read the Counter from Data, at the configured offset*/
                    if ((ConfigPtr->CounterOffset >> E2E_P01_SHIFT_BY_3U) == 0u)
                    {
                        ReceivedCounter = DataPtr[ComputedOffset] & E2E_P01_VAL_0x0fu;
                    }
                    else
                    {
                        ReceivedCounter = (DataPtr[ComputedOffset] >> E2E_P01_SHIFT_BY_4U) & E2E_P01_VAL_0x0fu;
                    }
                    if (ReceivedCounter <= E2E_P01_MAX_COUNTER_LIMIT)
                    {
                        ComputedOffset  = ConfigPtr->CRCOffset >> E2E_P01_SHIFT_BY_3U;
                        ReceivedCRC     = DataPtr[ComputedOffset];

                        if (ConfigPtr->DataIDMode == E2E_P01_DATAID_NIBBLE)
                        {
                            ComputedOffset = ConfigPtr->DataIDNibbleOffset >> E2E_P01_SHIFT_BY_3U;
                            if ((ConfigPtr->DataIDNibbleOffset >>E2E_P01_SHIFT_BY_3U) == 0u)
                            {
                                ReceivedDataIDNibble = DataPtr[ComputedOffset] & E2E_P01_VAL_0x0fu;
                            }
                            else
                            {
                                ReceivedDataIDNibble = (DataPtr[ComputedOffset] & E2E_P01_VAL_0xf0u) >> E2E_P01_SHIFT_BY_4U;
                            }
                        }
                        ComputedCRC = E2E_P01ComputeCRC ( DataPtr, ConfigPtr, ReceivedCounter);

                        if ((ConfigPtr->DataIDMode == E2E_P01_DATAID_NIBBLE) && (ReceivedDataIDNibble != (ConfigPtr->DataID >> E2E_P01_SHIFT_BY_8U)))
                        {
                            StatePtr->Status = E2E_P01STATUS_WRONGCRC;
                        }
                        else
                        {
                            /* check CRC */
                            if (ReceivedCRC == ComputedCRC)
                            {
                                if (StatePtr->WaitForFirstData == FALSE)
                                {
                                    E2E_ProcessDeltaCounter (ConfigPtr, StatePtr, ReceivedCounter);
                                }
                                else
                                {
                                    StatePtr->WaitForFirstData = FALSE;
                                    StatePtr->MaxDeltaCounter = ConfigPtr->MaxDeltaCounterInit;
                                    StatePtr->LastValidCounter = ReceivedCounter;
                                    StatePtr->Status = E2E_P01STATUS_INITIAL;
                                }
                            }
                            else
                            {
                                StatePtr->Status = E2E_P01STATUS_WRONGCRC;
                            }
                        }
                    }
                    else
                    {
                        ret =  E2E_E_INPUTERR_WRONG;
                    }
                }
                else
                {
                    if (StatePtr->NoNewOrRepeatedDataCounter < E2E_P01_MAX_COUNTER_LIMIT)
                    {
                        StatePtr->NoNewOrRepeatedDataCounter++;
                    }
                    StatePtr->Status = E2E_P01STATUS_NONEWDATA;
                }
            }
        }
        else
        {
            ret = E2E_E_INPUTERR_WRONG;
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
** Function Name    :   E2E_P01CheckInit
**
** Visibility       :   Public
**
** Description      :   Initializes the check states.
**
** Invocation       :
**
** Inputs           :   E2E_P01CheckStateType * StatePtr - Pointer to CheckSate type.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
Std_ReturnType E2E_P01CheckInit(E2E_P01CheckStateType* StatePtr)
{
    Std_ReturnType ret = E2E_E_INPUTERR_WRONG;
    if (StatePtr != NULL)
    {
        StatePtr->LastValidCounter           = 0u;
        StatePtr->MaxDeltaCounter            = 0u;
        StatePtr->WaitForFirstData           = TRUE;
        StatePtr->NewDataAvailable           = TRUE;
        StatePtr->LostData                   = 0u;
        StatePtr->Status                     = E2E_P01STATUS_NONEWDATA;
        StatePtr->NoNewOrRepeatedDataCounter = 0u;
        StatePtr->SyncCounter                = 0u;

        ret = E_OK;
    }

    else
    {
        ret = E2E_E_INPUTERR_NULL;
    }
    return ret;
}

/*============================================================================
**
** Function Name    :   E2E_P01MapStatusToSM
**
** Visibility       :   Public
**
** Description      :   The function maps the check status of Profile 1 to a generic check status, which
**						can be used by E2E state machine check function. The E2E Profile 1 delivers a
**						more fine-granular status, but this is not relevant for the E2E state machine.
**
** Invocation       :
**
** Inputs           :   E2E_P01ProtectStateType * StatePtr - Pointer to ProtectState type.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
E2E_PCheckStatusType E2E_P01MapStatusToSM(Std_ReturnType CheckReturn, E2E_P01CheckStatusType Status, boolean profileBehavior)
{
    E2E_PCheckStatusType RetVal = E2E_P_ERROR;
    if ((Std_ReturnType)E_NOT_OK != CheckReturn)
    {
        if(Status == E2E_P01STATUS_OK)
        {
            RetVal = E2E_P_OK;
        }
        else if(Status == E2E_P01STATUS_NONEWDATA)
        {
            RetVal = E2E_P_NONEWDATA;
        }
        else if(Status == E2E_P01STATUS_WRONGCRC)
        {
            RetVal = E2E_P_ERROR;
        }
        else if(Status == E2E_P01STATUS_SYNC)
        {
            if (FALSE == profileBehavior)
            {
                RetVal = E2E_P_WRONGSEQUENCE;
            }
            else
            {
                RetVal = E2E_P_OK;
            }
        }
        else if(Status == E2E_P01STATUS_INITIAL)
        {

            if (FALSE == profileBehavior)
            {
                RetVal = E2E_P_OK;
            }
            else
            {
                RetVal = E2E_P_WRONGSEQUENCE;
            }
        }
        else if(Status == E2E_P01STATUS_REPEATED)
        {
            RetVal = E2E_P_REPEATED;
        }
        else if(Status == E2E_P01STATUS_OKSOMELOST)
        {
            RetVal = E2E_P_OK;
        }
        else if(Status == E2E_P01STATUS_WRONGSEQUENCE)
        {
            RetVal = E2E_P_WRONGSEQUENCE;
        }
        else
        {
            //do nothing
        }
    }

    return RetVal;
}

#define E2EP01_CODE_SEC_END
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
Date               : 19-May-2020
CDSID              : pangraje
Traceability       : RTC #897020
Change Description : Initial Framework version of E2E Module with Profile1
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 09-Jun-2022
CDSID              : dbalasub
Traceability       : RTC #1683388
Change Description : Audit fix
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/
