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
/*****************************************************************************
*  File Name         :  E2E_P07_H                                            *
*  Module Short Name :  E2E_P07_H                                            *
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
#ifndef E2E_P07_H
#define E2E_P07_H

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

#ifndef E2E_P07_C
#define EXTERN extern
#else
#define EXTERN
#endif

#define E2E_UINT64_MAX_VALUE 0xFFFFFFFFFFFFFFFFuLL
#define E2E_ZERO_VALUE       0x0u

#define E2E_P07_SHIFT_BY_56U 56u
#define E2E_P07_SHIFT_BY_48U 48u
#define E2E_P07_SHIFT_BY_40U 40u
#define E2E_P07_SHIFT_BY_32U 32u
#define E2E_P07_SHIFT_BY_24U 24u
#define E2E_P07_SHIFT_BY_16U 16u
#define E2E_P07_SHIFT_BY_8U  8u
#define E2E_P07_SHIFT_BY_3U  3u

#define E2E_P07_DIV_BY_8U 8u
/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/


typedef struct{
    uint32 DataID;
    uint32 Offset;
    uint32 MinDataLength;
    uint32 MaxDataLength;
    uint32 MaxDeltaCounter;
}E2E_P07ConfigType;

typedef struct{
    uint32 Counter;
}E2E_P07ProtectStateType;

typedef enum
{
    E2E_P07STATUS_OK            = 0x00u,
    E2E_P07STATUS_NONEWDATA     = 0x01u,
    E2E_P07STATUS_ERROR         = 0x02u,
    E2E_P07STATUS_REPEATED      = 0x08u,
    E2E_P07STATUS_OKSOMELOST    = 0x20u,
    E2E_P07STATUS_WRONGSEQUENCE = 0x40u,
} E2E_P07CheckStatusType;

typedef struct{
    E2E_P07CheckStatusType Status;
    uint32 Counter;
}E2E_P07CheckStateType;

/*****************************************************************************
*                            External Function Declarations	     		     *
******************************************************************************/
/*============================================================================
**
** Function Name    :   E2E_P07Protect
**
** Visibility       :   Public
**
** Description      :   Protects the array/buffer to be transmitted using the E2E profile 7. 
**                      This includes checksum calculation, handling of counter and Data ID.
**
** Invocation       :
**
** Inputs           :   E2E_P07ConfigType* ConfigPtr - Pointer to a configuration type.
**						E2E_P07ProtectStateType* StatePtr - Pointer to ProtectState type.
**						uint8 * DataPtr - Data Pointer.
**                      uint32 Length - Length of the data
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
EXTERN Std_ReturnType E2E_P07Protect( const E2E_P07ConfigType* ConfigPtr, E2E_P07ProtectStateType* StatePtr, uint8* DataPtr, uint32 Length );


/*============================================================================
**
** Function Name    :   E2E_P07ProtectInit
**
** Visibility       :   Public
**
** Description      :   Initializes the protection state.
**
** Invocation       :
**
** Inputs           :   E2E_P07ProtectStateType* StatePtr - Pointer to ProtectState type.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
EXTERN Std_ReturnType E2E_P07ProtectInit( E2E_P07ProtectStateType* StatePtr );

/*============================================================================
**
** Function Name    :   E2E_P07Check
**
** Visibility       :   Public
**
** Description      :   Checks the Data received using the E2E profile 7. 
**                      This includes CRC calculation, handling of Counter and Data ID.
**
** Invocation       :
**
** Inputs           :   const E2E_P07ConfigType* ConfigPtr - Pointer to a configuration type.
**						E2E_P07CheckStateType* StatePtr - Pointer to CheckSate type.
**						const uint8* DataPtr - Data Pointer.
**                      uint32 Length - Length of the data
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
EXTERN Std_ReturnType E2E_P07Check( const E2E_P07ConfigType* ConfigPtr, E2E_P07CheckStateType* StatePtr, const uint8* DataPtr, uint32 Length );


/*============================================================================
**
** Function Name    :   E2E_P07CheckInit
**
** Visibility       :   Public
**
** Description      :   Initializes the check states.
**
** Invocation       :
**
** Inputs           :   E2E_P07CheckStateType* StatePtr - Pointer to CheckSate type.
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
EXTERN Std_ReturnType E2E_P07CheckInit( E2E_P07CheckStateType* StatePtr );

/*============================================================================
**
** Function Name    :   E2E_P07MapStatusToSM
**
** Visibility       :   Public
**
** Description      :   The function maps the check status of Profile 7 to a generic check status, 
**                      which can be used by E2E state machine check function. The E2E Profile 7 delivers a
**                      more fine-granular status, but this is not relevant for the E2E state machine
**
** Invocation       :
**
** Inputs           :   Std_ReturnType CheckReturn - Profile-independent status of the reception on one single Data in one cycle.
**                      E2E_P07CheckStatusType Status - Status determined by E2E_P07Check function
**
** Outputs          :	Std_ReturnType
**
** Critical Section :	NA
**
**==========================================================================*/
EXTERN E2E_PCheckStatusType E2E_P07MapStatusToSM( Std_ReturnType CheckReturn, E2E_P07CheckStatusType Status );

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
Date               : 19-Oct-2023
CDSID              : gthanapp
Traceability       : JIRA #DICVA-395
Change Description : Initial Framework version of E2E Module with Profile7
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/
