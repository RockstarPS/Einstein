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
#ifndef E2E_P05_C
#define E2E_P05_C
/*****************************************************************************
*  File Name         :  E2E_P05.c                                            *
*  Module Short Name :  E2E_P05                                              *
*  Description       :  This file contains E2E Profile 4 Implementation      *
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
#include "E2E_P05.h"

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define E2E_P05_MAX_COUNTER_LIMIT       0xffu

#define E2E_P05_DIV_BY_8U               8U
#define E2E_P05_VAL_1U                  1U
#define E2E_P05_SHIFT_BY_8U             8U
#define E2E_P05_MAX_VAL_16BIT_U         0xFFFFu
#define E2E_P05_MAX_VAL_8BIT            0xFFu
#define E2E_P05_INC_BY_1U               1U
#define E2E_P05_INC_BY_2U               2U
#define E2E_P05_DEC_BY_2U               2U
#define E2E_P05_VAL_0xff00u             0xff00u
#define E2E_P05_VAL_0x00ffu             0x00ffu
#define E2E_P05_MAX_VAL_16BIT           0xFFFFu
/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
static void E2E_ProcessDeltaCounter(const E2E_P05ConfigType* ConfigPtr, E2E_P05CheckStateType* StatePtr, uint8 ReceivedCounter);

#define E2EP05_CODE_SEC_START
#include "MemMap.h"
/*============================================================================
**
** Function Name    :   E2E_ProcessDeltaCounter
**
** Visibility       :   Private
**
** Description      :   Provides further checks with respect to Delta Counter
**
** Invocation       :
**
** Inputs           :   E2E_P05ConfigType * ConfigPtr - Pointer to a configuration type.
**						E2E_P05CheckStateType * StatePtr - Pointer to CheckSate type.
**                      uint8 ReceivedCounter - Received Counter value
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
static void E2E_ProcessDeltaCounter(const E2E_P05ConfigType* ConfigPtr, E2E_P05CheckStateType* StatePtr, uint8 ReceivedCounter)
{
    uint8 DeltaCounter = 0u;
    if(ReceivedCounter >= StatePtr->Counter)
    {
        DeltaCounter = ReceivedCounter - StatePtr->Counter;
    }
    else
    {
        DEBUG_ASSERT( FALSE );
    }
    if (DeltaCounter <= ConfigPtr->MaxDeltaCounter)
    {
        if (DeltaCounter > 0u)
        {
            if (DeltaCounter == E2E_P05_VAL_1U)
            {
                StatePtr->Status = E2E_P05STATUS_OK;
            }
            else
            {
                StatePtr->Status = E2E_P05STATUS_OKSOMELOST;
            }
        }
        else
        {
            StatePtr->Status = E2E_P05STATUS_REPEATED;
        }
    }
    else
    {
        StatePtr->Status = E2E_P05STATUS_WRONGSEQUENCE;
    }
}

/*============================================================================
**
** Function Name    :   E2E_P05Protect
**
** Visibility       :   Public
**
** Description      :   Protects the array/buffer to be transmitted using the E2E profile 5.
**						This includes checksum calculation, handling of sequence counter and Data ID.
**
** Invocation       :
**
** Inputs           :   E2E_P05ConfigType * ConfigPtr - Pointer to a configuration type.
**						E2E_P05ProtectStateType * StatePtr - Pointer to ProtectState type.
**						uint8 * DataPtr - Data Pointer.
**                      uint16 Length - Length of the data
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
Std_ReturnType E2E_P05Protect(E2E_P05ConfigType* ConfigPtr, E2E_P05ProtectStateType* StatePtr, uint8* DataPtr, uint16 Length)
{
    uint16 Offset = 0u;
    uint16 ComputedCRC = 0u;
    Std_ReturnType ret = 0u;
    uint8 var = 0u;

    if((ConfigPtr != NULL)&&(StatePtr != NULL) && (DataPtr!=NULL))
    {
        if(Length == ConfigPtr->DataLength)
        {
            Offset = ConfigPtr->Offset / E2E_P05_DIV_BY_8U;

            DataPtr[Offset+E2E_P05_INC_BY_2U]  = (uint8)(StatePtr->Counter); /* Copy 1 byte of Counter onto Data in little endian format*/

            if(ConfigPtr->Offset >0u)
            {
                ComputedCRC = Crc_CalculateCRC16(&DataPtr[0], (uint32)(Offset), E2E_P05_MAX_VAL_16BIT_U, TRUE);
                if((Offset + E2E_P05_INC_BY_2U) < Length) /* To Protect negative rollback value */
                {
                    ComputedCRC = Crc_CalculateCRC16(&DataPtr[Offset+E2E_P05_INC_BY_2U], (uint32)((uint32)(Length)-(uint32)(Offset)-E2E_P05_DEC_BY_2U), ComputedCRC, FALSE);
                }
            }
            else
            {
                if((Offset + E2E_P05_INC_BY_2U) < Length) /* To Protect negative rollback value */
                {
                    ComputedCRC = Crc_CalculateCRC16(&DataPtr[Offset+E2E_P05_INC_BY_2U], (uint32)((uint32)(Length)-(uint32)(Offset)-E2E_P05_DEC_BY_2U),E2E_P05_MAX_VAL_16BIT_U, TRUE);
                }
            }

            var = (uint8)(ConfigPtr->DataID & E2E_P05_MAX_VAL_8BIT);
            ComputedCRC= Crc_CalculateCRC16(&var, E2E_P05_VAL_1U, ComputedCRC, FALSE);
            var = (uint8)(((ConfigPtr->DataID) >> (E2E_P05_SHIFT_BY_8U)) & (E2E_P05_MAX_VAL_8BIT));
            ComputedCRC= Crc_CalculateCRC16(&var, E2E_P05_VAL_1U, ComputedCRC, FALSE);

            /* Copy 2 bytes of ComputedCRC onto Data in little endian format*/
            DataPtr[Offset]  = (uint8)((ComputedCRC & E2E_P05_VAL_0xff00u) >> E2E_P05_SHIFT_BY_8U);
            DataPtr[Offset+E2E_P05_INC_BY_1U]= (uint8)(ComputedCRC & E2E_P05_VAL_0x00ffu);

            StatePtr->Counter++;
            if(StatePtr->Counter == E2E_P05_MAX_COUNTER_LIMIT)
            {
                StatePtr->Counter = 0u;
            }
            ret = E2E_E_OK;
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
** Function Name    :   E2E_P05ProtectInit
**
** Visibility       :   Public
**
** Description      :   Initializes the Counter.
**
** Invocation       :
**
** Inputs           :   E2E_P05ProtectStateType * StatePtr - Pointer to ProtectState type.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
Std_ReturnType E2E_P05ProtectInit(E2E_P05ProtectStateType* StatePtr)
{
    Std_ReturnType ret = 0u;
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
** Function Name    :   E2E_P05Check
**
** Visibility       :   Public
**
** Description      :   Check the array/buffer using the E2E profile 5. This includes checksum
**						calculation, handling of sequence counter and Data ID.
**
** Invocation       :
**
** Inputs           :   E2E_P05ConfigType * ConfigPtr - Pointer to a configuration type.
**						E2E_P05CheckStateType * StatePtr - Pointer to CheckSate type.
**						uint8 * DataPtr - Data Pointer.
**                      uint16 Length - Length of the data
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
Std_ReturnType E2E_P05Check(E2E_P05ConfigType* ConfigPtr, E2E_P05CheckStateType* StatePtr, uint8* DataPtr, uint16 Length)
{
    uint16 ReceivedCRC     = 0u;
    uint8  ReceivedCounter = 0u;
    uint16 ComputedCRC     = 0u;
    uint16 Offset          = 0u;
    Std_ReturnType ret     = 0u;
    uint8 var              = 0u;

    if ((ConfigPtr != NULL) && (StatePtr != NULL))
    {
        if(((DataPtr != NULL) && (Length != 0u)) || ((DataPtr == NULL) && (Length == 0u)))
        {
            if(DataPtr != NULL)
            {
                if(Length == ConfigPtr->DataLength)
                {
                    ReceivedCounter = (uint8)DataPtr[Offset + E2E_P05_INC_BY_2U];
                    ReceivedCRC     = (uint16)(((uint16)DataPtr[Offset] << E2E_P05_SHIFT_BY_8U) | ((uint16)DataPtr[Offset + E2E_P05_INC_BY_1U]));

                    if(ConfigPtr->Offset >0u)
                    {
                        ComputedCRC = Crc_CalculateCRC16(&DataPtr[0], Offset, E2E_P05_MAX_VAL_16BIT, TRUE);
                        if((Offset + E2E_P05_INC_BY_2U) < Length) /* To Protect negative rollback value */
                        {
                            ComputedCRC = Crc_CalculateCRC16(&DataPtr[Offset+E2E_P05_INC_BY_2U], (uint32)((uint32)(Length)-(uint32)(Offset)-E2E_P05_DEC_BY_2U), ComputedCRC, FALSE);
                        }
                    }
                    else
                    {
                        if((Offset + E2E_P05_INC_BY_2U) < Length) /* To Protect negative rollback value */
                        {
                            ComputedCRC = Crc_CalculateCRC16(&DataPtr[Offset+E2E_P05_INC_BY_2U], (uint32)((uint32)(Length)-(uint32)(Offset)-E2E_P05_DEC_BY_2U),E2E_P05_MAX_VAL_16BIT_U, TRUE);
                        }
                    }

                    var = (uint8)(ConfigPtr->DataID & E2E_P05_MAX_VAL_8BIT);
                    ComputedCRC= Crc_CalculateCRC16(&var, E2E_P05_VAL_1U, ComputedCRC, FALSE);
                    var = (uint8)(((ConfigPtr->DataID) >> (E2E_P05_SHIFT_BY_8U)) & (E2E_P05_MAX_VAL_8BIT));
                    ComputedCRC = Crc_CalculateCRC16(&var, E2E_P05_VAL_1U, ComputedCRC, FALSE);

                    if(ReceivedCRC == ComputedCRC)
                    {
                        E2E_ProcessDeltaCounter(ConfigPtr, StatePtr, ReceivedCounter);
                        StatePtr->Counter = ReceivedCounter;
                    }

                    else
                    {
                        StatePtr->Status = E2E_P05STATUS_NONEWDATA;
                    }
                    /*The condition check for NewDataAvailable was added as per the spec. The check is removed because of static analysis*/
                    /*CID 15564324*/
                }

                else
                {
                    ret = E2E_E_INPUTERR_WRONG;
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
** Function Name    :   E2E_P05CheckInit
**
** Visibility       :   Public
**
** Description      :   Initializes the check states.
**
** Invocation       :
**
** Inputs           :   E2E_P05CheckStateType * StatePtr - Pointer to CheckSate type.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
Std_ReturnType E2E_P05CheckInit(E2E_P05CheckStateType* StatePtr)
{
    Std_ReturnType ret = 0u;

    if (StatePtr != NULL)
    {
        StatePtr->Counter = E2E_P05_MAX_VAL_8BIT;
        StatePtr->Status = E2E_P05STATUS_ERROR;
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
** Function Name    :   E2E_P05MapStatusToSM
**
** Visibility       :   Public
**
** Description      :   The function maps the check status of Profile 5 to a generic check status, which
**						can be used by E2E state machine check function. The E2E Profile 5 delivers a
**						more fine-granular status, but this is not relevant for the E2E state machine.
**
** Invocation       :
**
** Inputs           :   E2E_P05ProtectStateType * StatePtr - Pointer to ProtectState type.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
E2E_PCheckStatusType E2E_P05MapStatusToSM(Std_ReturnType CheckReturn, E2E_P05CheckStatusType Status)
{
    E2E_PCheckStatusType RetVal = E2E_P_ERROR;

    if ((Std_ReturnType)E_NOT_OK != CheckReturn)
    {
        if(Status == E2E_P05STATUS_OK)
        {
            RetVal = E2E_P_OK;
        }
        else if (Status ==E2E_P05STATUS_OKSOMELOST)
        {
            RetVal = E2E_P_OK;
        }
        else if (Status == E2E_P05STATUS_ERROR)
        {
            RetVal = E2E_P_ERROR;
        }
        else if (Status == E2E_P05STATUS_REPEATED)
        {
            RetVal = E2E_P_REPEATED;
        }
        else if (Status == E2E_P05STATUS_NONEWDATA)
        {
            RetVal = E2E_P_NONEWDATA;
        }
        else if (Status == E2E_P05STATUS_WRONGSEQUENCE)
        {
            RetVal = E2E_P_WRONGSEQUENCE;
        }
        else
        {
            /*do nothing*/
        }
    }
    return RetVal;
}

#define E2EP05_CODE_SEC_END
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
Change Description : Initial Framework version of E2E Module with Profile 5
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 09-Jun-2022
CDSID              : dbalasub
Traceability       : RTC #1683388
Change Description : Audit fix
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/
