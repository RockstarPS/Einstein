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
#ifndef E2E_P01_H
#define E2E_P01_H
/*****************************************************************************
*  File Name         :  E2E_P01_H                                            *
*  Module Short Name :  E2E_P01_H                                            *
*  Description       :                                                       *
*                                                                            *
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
#include "Std_Types.h"
#include "E2E_SM.h"
#include "Crc.h"
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

typedef enum
{
    E2E_P01STATUS_OK,
    E2E_P01STATUS_NONEWDATA,
    E2E_P01STATUS_WRONGCRC,
    E2E_P01STATUS_SYNC,
    E2E_P01STATUS_INITIAL,
    E2E_P01STATUS_REPEATED,
    E2E_P01STATUS_OKSOMELOST,
    E2E_P01STATUS_WRONGSEQUENCE
} E2E_P01CheckStatusType;

typedef enum
{
    E2E_P01_DATAID_BOTH,
    E2E_P01_DATAID_ALT,
    E2E_P01_DATAID_LOW,
    E2E_P01_DATAID_NIBBLE,
} E2E_P01DataIDMode;

typedef struct
{
    E2E_P01DataIDMode DataIDMode;
    uint16 CounterOffset;
    uint16 CRCOffset;
    uint16 DataID;
    uint16 DataIDNibbleOffset;
    uint16 DataLength;
    uint8 MaxDeltaCounterInit;
    uint8 MaxNoNewOrRepeatedData;
    uint8 SyncCounterInit;
} E2E_P01ConfigType;

typedef struct
{
    uint8 Counter;
} E2E_P01ProtectStateType;

typedef struct
{
    E2E_P01CheckStatusType Status;
    uint8 LastValidCounter;
    uint8 MaxDeltaCounter;
    uint8 LostData;
    uint8 SyncCounter;
    uint8 NoNewOrRepeatedDataCounter;
    boolean WaitForFirstData;
    boolean NewDataAvailable;
} E2E_P01CheckStateType;

/*****************************************************************************
*                            External Function Declarations	     		     *
******************************************************************************/
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
extern Std_ReturnType E2E_P01Protect(E2E_P01ConfigType* ConfigPtr, E2E_P01ProtectStateType* StatePtr, uint8* DataPtr);

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
extern Std_ReturnType E2E_P01ProtectInit(E2E_P01ProtectStateType* StatePtr);

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
extern Std_ReturnType E2E_P01Check(E2E_P01ConfigType* ConfigPtr, E2E_P01CheckStateType* StatePtr, uint8* DataPtr);

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
extern Std_ReturnType E2E_P01CheckInit(E2E_P01CheckStateType* StatePtr);

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
extern E2E_PCheckStatusType E2E_P01MapStatusToSM(Std_ReturnType CheckReturn, E2E_P01CheckStatusType Status, boolean profileBehavior);

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
Change Description : Initial Framework version of E2E Module with Profile1
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/
