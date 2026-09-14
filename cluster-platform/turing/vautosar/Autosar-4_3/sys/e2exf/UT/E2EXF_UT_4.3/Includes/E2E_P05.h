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
#ifndef E2E_P05_H
#define E2E_P05_H
/*****************************************************************************
*  File Name         :  E2E_P05_H                                            *
*  Module Short Name :  E2E_P05_H                                            *
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
    E2E_P05STATUS_OK            = 0x00u,
    E2E_P05STATUS_NONEWDATA     = 0x01u,
    E2E_P05STATUS_ERROR         = 0x07u,
    E2E_P05STATUS_REPEATED      = 0x08u,
    E2E_P05STATUS_OKSOMELOST    = 0x20u,
    E2E_P05STATUS_WRONGSEQUENCE = 0x40u,
} E2E_P05CheckStatusType;

typedef struct
{
    uint16 Offset;
    uint16 DataLength;
    uint16 DataID;
    uint8  MaxDeltaCounter;
} E2E_P05ConfigType;

typedef struct
{
    uint8  Counter;
} E2E_P05ProtectStateType;

typedef struct
{
    E2E_P05CheckStatusType Status;
    uint8 Counter;
} E2E_P05CheckStateType;

/*****************************************************************************
*                            External Function Declarations	     		     *
******************************************************************************/
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
extern Std_ReturnType E2E_P05Protect(E2E_P05ConfigType* ConfigPtr, E2E_P05ProtectStateType* StatePtr, uint8* DataPtr, uint16 Length);

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
extern Std_ReturnType E2E_P05ProtectInit(E2E_P05ProtectStateType* StatePtr);

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
extern Std_ReturnType E2E_P05Check(E2E_P05ConfigType* ConfigPtr, E2E_P05CheckStateType* StatePtr, uint8* DataPtr, uint16 Length);

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
extern Std_ReturnType E2E_P05CheckInit(E2E_P05CheckStateType* StatePtr);

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
extern E2E_PCheckStatusType E2E_P05MapStatusToSM(Std_ReturnType CheckReturn, E2E_P05CheckStatusType Status);
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
Change Description : Initial Framework version of E2E Module with Profile5
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/
