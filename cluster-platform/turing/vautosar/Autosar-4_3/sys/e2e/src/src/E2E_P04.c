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
#ifndef E2E_P04_C
#define E2E_P04_C
/*****************************************************************************
*  File Name         :  E2E_P04.c                                            *
*  Module Short Name :  E2E_P04                                              *
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
#include "E2E_P04.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define MAX_counter_value               0xffffu
#define CRC_Base_Offset                 8u
#define Header_Length                   12u

#define E2E_P04_MUL_BY_8U               8U
#define E2E_P04_INC_BY_2U               2U
#define E2E_P04_INC_BY_4U               4U
#define E2E_P04_INC_BY_8U               8U
#define E2E_P04_VAL_1U                  1U
#define E2E_P04_VAL_2U                  2U
#define E2E_P04_VAL_4U                  4U
#define E2E_P04_MAX_VAL_8BITu           0x000000ffu
#define E2E_P04_MAX_VAL_16BIT           0xFFFF
#define E2E_P04_MAX_VAL_32BITu          0xFFFFFFFFu
#define E2E_P04_MAX_VAL_16BITu          0xFFFFu
/*****************************************************************************
******************************************************************************/
#define E2EP04_CODE_SEC_START
#include "MemMap.h"
#include "AssertLib.h"
/*****************************************************************************
*                       Locally used Variable Declarations     				 *
******************************************************************************/
static void datacpy(uint8* DataPtr,uint32 src_val,uint16 Offset,uint8 Nof_bytes);
static uint32 dataget(uint8* DataPtr,uint16 Offset,uint8 Nof_bytes);
/*============================================================================
**
** Function Name    :   E2E_P04ProtectInit
**
** Visibility       :   Public
**
** Description      :   Initializes the Counter.
**
** Inputs           :   E2E_P04ProtectStateType * StatePtr - Pointer to ProtectState type.
**
** Outputs          :	Std_ReturnType
**
**==========================================================================*/
Std_ReturnType E2E_P04ProtectInit(E2E_P04ProtectStateType* StatePtr)
{
    Std_ReturnType ret_val = 0;
    if (StatePtr == NULL)
    {
        ret_val = E2E_E_INPUTERR_NULL;
    }
    else
    {
        StatePtr->Counter = 0x0000u;
        ret_val = E2E_E_OK;

    }
    return ret_val;
}
/*============================================================================
**
** Function Name    :   datacpy
**
** Visibility       :   Public
**
** Description      :   insert the  src_val to the DataPtr in postion Offset
**
** Inputs           :   uint32 src_val  - source value to copy.
**						uint8 * DataPtr - Data Pointer.
**                      uint16 Nof_bytes - number of bytes to copy
**						uint16 Offset - offset postion for copy
**
** Outputs          :	Std_ReturnType
**
**==========================================================================*/
static void datacpy(uint8* DataPtr,uint32 src_val,uint16 Offset,uint8 Nof_bytes)
{
    uint8 bytecnt = 0;
    for(bytecnt=0; bytecnt<Nof_bytes; bytecnt++)
    {
        DataPtr[Offset+bytecnt] = (uint8)((src_val & (E2E_P04_MAX_VAL_8BITu<<(bytecnt*E2E_P04_MUL_BY_8U))) >> (bytecnt*E2E_P04_MUL_BY_8U));
    }

}
/*============================================================================
**
** Function Name    :   E2E_P04Protect
**
** Visibility       :   Public
**
** Description      :  This function used to Protects the buffer (DataPtr) by calculate and inlclude the checksum.
**
** Inputs           :   E2E_P04ConfigType * ConfigPtr - Pointer to a configuration type.
**						E2E_P04ProtectStateType * StatePtr - Pointer to ProtectState type.
**						uint8 * DataPtr - Data Pointer.
**                      uint16 Length - Length of the data
**
** Outputs          :	Std_ReturnType
**
**==========================================================================*/
Std_ReturnType E2E_P04Protect(E2E_P04ConfigType* ConfigPtr, E2E_P04ProtectStateType* StatePtr, uint8* DataPtr, uint16 Length)
{
    uint16 Offset = 0u;
    uint32 CRC_val = 0u;
    Std_ReturnType ret_val = 0u;

    if((ConfigPtr != NULL)&&(StatePtr != NULL) && (DataPtr!=NULL))
    {
        if((Length >= ConfigPtr->MinDataLength) && (Length <= ConfigPtr->MaxDataLength))
        {
            Offset = ConfigPtr->Offset / CRC_Base_Offset;
            datacpy( &DataPtr[0],(uint32)Length,Offset,(uint8)E2E_P04_VAL_2U);/*length 2 bytes*/
            datacpy( &DataPtr[0],(uint32)StatePtr->Counter,Offset+E2E_P04_INC_BY_2U,(uint8)E2E_P04_VAL_2U);/*Counter 2 bytes*/
            datacpy( &DataPtr[0],(uint32)ConfigPtr->DataID,Offset+E2E_P04_INC_BY_4U,(uint8)E2E_P04_VAL_4U);/*DataID 4 bytes*/

            /*E2E CRC coputation*/
            CRC_val = Crc_CalculateCRC32P4(&DataPtr[0], (uint32)(Offset + E2E_P04_INC_BY_8U), E2E_P04_MAX_VAL_32BITu, TRUE);
            if((Offset + Header_Length) < Length)
            {
                /*E2E CRC coputation*/
                CRC_val = Crc_CalculateCRC32P4(&DataPtr[Offset + Header_Length], (uint32)((uint32)(Length)-(uint32)(Offset)-Header_Length), CRC_val, FALSE);
            }

            datacpy( &DataPtr[0],(uint32)CRC_val,Offset+E2E_P04_INC_BY_8U,(uint8)E2E_P04_VAL_4U);/*CRC_val 2 bytes*/
            if(StatePtr->Counter < E2E_P04_MAX_VAL_16BIT )
            {
                StatePtr->Counter++;
            }
            else
            {
                DEBUG_ASSERT( FALSE );
            }
            if(StatePtr->Counter == MAX_counter_value)
            {
                StatePtr->Counter = 0u;
            }
            ret_val = E2E_E_OK;
        }
        else
        {
            ret_val = E2E_E_INPUTERR_WRONG;
        }
    }
    else
    {
        ret_val = E2E_E_INPUTERR_NULL;
    }
    return ret_val;
}
/*============================================================================
**
** Function Name    :   dataget
**
** Visibility       :   Public
**
** Description      :   get upto four bytes from the DataPtr
**
** Inputs           :   uint8 * DataPtr - Data Pointer as source.
**                      uint16 Nof_bytes - number of bytes to copy
**						uint16 Offset - offset postion for copy
**
** Outputs          :	uint32
**
**==========================================================================*/
static uint32 dataget(uint8* DataPtr,uint16 Offset,uint8 Nof_bytes)
{
    uint32 ret_val = 0u;
    uint8 bytecnt = 0u;
    for(bytecnt=0; bytecnt<Nof_bytes; bytecnt++)
    {
        ret_val =ret_val|((uint32)DataPtr[Offset + bytecnt]<<(bytecnt*E2E_P04_MUL_BY_8U));

    }
    return ret_val;
}
/*============================================================================
**
** Function Name    :   E2E_P04Check
**
** Description      :   This function used to check the buffer (DataPtr) by using the CRC, to ensure E2E profile 4 preotection.
**
** Inputs           :   E2E_P04ConfigType * ConfigPtr - Pointer to a configuration type.
**						E2E_P04CheckStateType * StatePtr - Pointer to CheckSate type.
**						uint8 * DataPtr - Data Pointer.
**                      uint16 Length - Length of the data
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
Std_ReturnType E2E_P04Check(E2E_P04ConfigType* ConfigPtr, E2E_P04CheckStateType* StatePtr, uint8* DataPtr, uint16 Length)
{
    uint16 Offset      = 0u;
    uint32 Rcv_CRC     = 0u;
    uint16 Rcv_Length  = 0u;
    uint16 Rcv_Counter = 0u;
    uint32 Rcv_DataID  = 0u;
    uint32 CRC_val     = 0u;
    uint16 DeltaCounter = 0u;
    Std_ReturnType ret_val = 0u;

    if ( (ConfigPtr != NULL) && (StatePtr != NULL) )
    {
        if(((DataPtr != NULL) && (Length != 0u)) || ((DataPtr == NULL) && (Length == 0u)))
        {
            if(DataPtr != NULL)
            {
                if((Length >= ConfigPtr->MinDataLength) && (Length <= ConfigPtr->MaxDataLength))
                {

                    Rcv_Length  = (uint16)dataget( &DataPtr[0],Offset,(uint8)E2E_P04_VAL_2U);/*length 2 bytes*/
                    Rcv_Counter = (uint16)dataget( &DataPtr[0],Offset+E2E_P04_INC_BY_2U,(uint8)E2E_P04_VAL_2U);/*counter 2 bytes*/
                    Rcv_DataID  = (uint32)dataget( &DataPtr[0],Offset+E2E_P04_INC_BY_4U,(uint8)E2E_P04_VAL_4U);/*DataID 4 bytes*/
                    Rcv_CRC     = (uint32)dataget( &DataPtr[0],Offset+E2E_P04_INC_BY_8U,(uint8)E2E_P04_VAL_4U);/*CRC 4 bytes*/

                    /*E2E CRC coputation*/
                    CRC_val = Crc_CalculateCRC32P4(&DataPtr[0], (uint32)(Offset + E2E_P04_INC_BY_8U), E2E_P04_MAX_VAL_32BITu, TRUE);
                    if((Offset + Header_Length) < Length)
                    {
                        /*E2E CRC coputation*/
                        CRC_val = Crc_CalculateCRC32P4(&DataPtr[Offset + Header_Length], (uint32)((uint32)(Length)-(uint32)(Offset)-Header_Length), CRC_val, FALSE);
                    }

                    if(Rcv_CRC == CRC_val)
                    {
                        if(Rcv_DataID == ConfigPtr->DataID)
                        {
                            if(Rcv_Length == Length)
                            {
                                DeltaCounter = Rcv_Counter - StatePtr->Counter;
                                if (DeltaCounter <= ConfigPtr->MaxDeltaCounter)
                                {
                                    if (DeltaCounter > 0u)
                                    {
                                        if (DeltaCounter == E2E_P04_VAL_1U)
                                        {
                                            StatePtr->Status = E2E_P04STATUS_OK;
                                        }
                                        else
                                        {
                                            StatePtr->Status = E2E_P04STATUS_OKSOMELOST;
                                        }
                                    }
                                    else
                                    {
                                        StatePtr->Status = E2E_P04STATUS_REPEATED;
                                    }
                                }
                                else
                                {
                                    StatePtr->Status = E2E_P04STATUS_WRONGSEQUENCE;
                                }
                                StatePtr->Counter = Rcv_Counter;
                            }
                            else
                            {
                                StatePtr->Status = E2E_P04STATUS_ERROR;
                            }
                        }
                        else
                        {
                            StatePtr->Status = E2E_P04STATUS_ERROR;
                        }
                    }
                    else
                    {
                        StatePtr->Status = E2E_P04STATUS_ERROR;
                    }
                }
                else
                {
                    ret_val = E2E_E_INPUTERR_WRONG;
                }
            }
        }
        else
        {
            ret_val = E2E_E_INPUTERR_WRONG;
        }
    }
    else
    {
        ret_val = E2E_E_INPUTERR_NULL;
    }
    return ret_val;
}
/*============================================================================
**
** Function Name    :   E2E_P04CheckInit
**
** Description      :   Initializes the check states.
**
** Inputs           :   E2E_P04CheckStateType * StatePtr - Pointer to CheckSate type.
**
** Outputs          :	Std_ReturnType
**
**==========================================================================*/
Std_ReturnType E2E_P04CheckInit(E2E_P04CheckStateType* StatePtr)
{
    Std_ReturnType ret_val = 0u;
    if (StatePtr == NULL)
    {
        ret_val = E2E_E_INPUTERR_NULL;
    }
    else
    {
        StatePtr->Counter = E2E_P04_MAX_VAL_16BITu;
        StatePtr->Status  = E2E_P04STATUS_ERROR;
        ret_val = E_OK;
    }
    return ret_val;
}
/*============================================================================
**
** Function Name    :   E2E_P04MapStatusToSM
**
** Visibility       :   Public
**
** Description      :   The function used to check the status of Profile 4.
**
** Inputs           :   E2E_P04ProtectStateType * StatePtr - Pointer to ProtectState type.
**
** Outputs          :	Std_ReturnType
**
**==========================================================================*/
E2E_PCheckStatusType E2E_P04MapStatusToSM(Std_ReturnType CheckReturn, E2E_P04CheckStatusType Status)
{
    E2E_PCheckStatusType ret_val = E2E_P_ERROR;
    if ((Std_ReturnType)E_NOT_OK != CheckReturn)
    {
        switch(Status)
        {
        case E2E_P04STATUS_OK:
            ret_val = E2E_P_OK;
            break;
        case E2E_P04STATUS_OKSOMELOST:
            ret_val = E2E_P_OK;
            break;
        case E2E_P04STATUS_ERROR:
            ret_val = E2E_P_ERROR;
            break;
        case E2E_P04STATUS_REPEATED:
            ret_val = E2E_P_REPEATED;
            break;
        case E2E_P04STATUS_NONEWDATA:
            ret_val = E2E_P_NONEWDATA;
            break;
        case E2E_P04STATUS_WRONGSEQUENCE:
            ret_val = E2E_P_WRONGSEQUENCE;
            break;
        default:
            /*do nothing*/
            break;
        }

    }
    return ret_val;
}

#define E2EP04_CODE_SEC_END
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
Date               : 02-Jan-2021
CDSID              : praj1
Traceability       : RTC #1179541
Change Description : Initial Framework version of E2E Module with Profile4
-----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
Date              : 27-03-2022
CDSID             : gthanapp
Traceability      : RTC#1564070
Change Description: Cert-C warning analysis and fix
--------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 09-Jun-2022
CDSID              : dbalasub
Traceability       : RTC #1683388
Change Description : Audit fix
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/

