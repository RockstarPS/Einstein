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
#ifndef E2E_P02_H
#define E2E_P02_H
/*****************************************************************************
*  File Name         :  E2E_P02.h                                            *
*  Module Short Name :  E2E_H                                                *
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
    E2E_P02STATUS_OK            = 0x00u,
    E2E_P02STATUS_NONEWDATA     = 0x01u,
    E2E_P02STATUS_WRONGCRC      = 0x02u,
    E2E_P02STATUS_SYNC          = 0x03u,
    E2E_P02STATUS_INITIAL       = 0x04u,
    E2E_P02STATUS_REPEATED      = 0x08u,
    E2E_P02STATUS_OKSOMELOST    = 0x20u,
    E2E_P02STATUS_WRONGSEQUENCE = 0x40u
} E2E_P02CheckStatusType;

typedef struct
{
    uint16 DataLength;
    uint16 Offset;
    uint8  DataIDList[16];
    uint8  MaxDeltaCounterInit;
    uint8  MaxNoNewOrRepeatedData;
    uint8  SyncCounterInit;
} E2E_P02ConfigType;

typedef struct
{
    uint8  Counter;
} E2E_P02ProtectStateType;

typedef struct
{
    E2E_P02CheckStatusType Status;
    uint8 LastValidCounter;
    uint8 MaxDeltaCounter;
    uint8 LostData;
    uint8 SyncCounter;
    uint8 NoNewOrRepeatedDataCounter;
    boolean WaitForFirstData;
    boolean NewDataAvailable;
} E2E_P02CheckStateType;

/*****************************************************************************
*                            External Function Declarations	     		     *
******************************************************************************/
/*============================================================================
**
** Function Name    :   E2E_P02Protect
**
** Visibility       :   Public
**
** Description      :   Protects the array/buffer to be transmitted using the E2E profile 2.
**						This includes checksum calculation, handling of sequence counter and Data ID.
**
** Invocation       :
**
** Inputs           :   E2E_P02ConfigType * ConfigPtr - Pointer to a configuration type.
**						E2E_P02ProtectStateType * StatePtr - Pointer to ProtectState type.
**						uint8 * DataPtr - Data Pointer.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
extern Std_ReturnType E2E_P02Protect(const E2E_P02ConfigType* ConfigPtr, E2E_P02ProtectStateType* StatePtr, uint8* DataPtr);
/*============================================================================
**
** Function Name    :   E2E_P02ProtectInit
**
** Visibility       :   Public
**
** Description      :   Initializes the Counter.
**
** Invocation       :
**
** Inputs           :   E2E_P02ProtectStateType * StatePtr - Pointer to ProtectState type.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
extern Std_ReturnType E2E_P02ProtectInit(E2E_P02ProtectStateType* StatePtr);
/*============================================================================
**
** Function Name    :   E2E_P02Check
**
** Visibility       :   Public
**
** Description      :   Check the array/buffer using the E2E profile 2. This includes checksum
**						calculation, handling of sequence counter and Data ID.
**
** Invocation       :
**
** Inputs           :   E2E_P02ConfigType * ConfigPtr - Pointer to a configuration type.
**						E2E_P02CheckStateType * StatePtr - Pointer to CheckSate type.
**						uint8 * DataPtr - Data Pointer.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
extern Std_ReturnType E2E_P02Check(const E2E_P02ConfigType* ConfigPtr, E2E_P02CheckStateType* StatePtr, const uint8* DataPtr);
/*============================================================================
**
** Function Name    :   E2E_P02CheckInit
**
** Visibility       :   Public
**
** Description      :   Initializes the check states.
**
** Invocation       :
**
** Inputs           :   E2E_P02CheckStateType * StatePtr - Pointer to CheckSate type.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
extern Std_ReturnType E2E_P02CheckInit(E2E_P02CheckStateType* StatePtr);
/*============================================================================
**
** Function Name    :   E2E_P02MapStatusToSM
**
** Visibility       :   Public
**
** Description      :   The function maps the check status of Profile 2 to a generic check status, which
**						can be used by E2E state machine check function. The E2E Profile 2 delivers a
**						more fine-granular status, but this is not relevant for the E2E state machine.
**
** Invocation       :
**
** Inputs           :   E2E_P02ProtectStateType * StatePtr - Pointer to ProtectState type.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
extern E2E_PCheckStatusType E2E_P02MapStatusToSM(Std_ReturnType CheckReturn, E2E_P02CheckStatusType Status, boolean profileBehavior);

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
Date               : 17-Apr-2020
CDSID              : ssebast1
Traceability       : RTC #794879
Change Description : Initial Framework version of E2E Module with Profile2
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/
