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
#ifndef E2E_SM_H
#define E2E_SM_H
/*****************************************************************************
*  File Name         :  E2E_SM_H                                             *
*  Module Short Name :  E2E_SM_H                                             *
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
/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Error flags used by all E2E Library functions */

# define E2E_E_INPUTERR_NULL  0x13u

# define E2E_E_INPUTERR_WRONG 0x17u

# define E2E_E_INTERR         0x19u

# define E2E_E_WRONGSTATE     0x1au

# define E2E_E_OK             0x00u

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{
    E2E_P_OK            = 0x00u,
    E2E_P_REPEATED      = 0x01u,
    E2E_P_WRONGSEQUENCE = 0x02u,
    E2E_P_ERROR         = 0x03u,
    E2E_P_NOTAVAILABLE  = 0x04u,
    E2E_P_NONEWDATA	    = 0x05u
} E2E_PCheckStatusType;

typedef struct
{
    uint8 WindowSize;

    uint8 MinOkStateInit;
    uint8 MaxErrorStateInit;

    uint8 MinOkStateValid;
    uint8 MaxErrorStateValid;

    uint8 MinOkStateInvalid;
    uint8 MaxErrorStateInvalid;
} E2E_SMConfigType;

typedef enum
{
    E2E_SM_VALID   = 0x00u,
    E2E_SM_DEINIT  = 0x01u,
    E2E_SM_NODATA  = 0x02u,
    E2E_SM_INIT    = 0x03u,
    E2E_SM_INVALID = 0x04u
} E2E_SMStateType;

typedef struct
{
    uint8* ProfileStatusWindow;
    uint8  WindowTopIndex;
    uint8  OkCount;
    uint8  ErrorCount;
    E2E_SMStateType SMState;
} E2E_SMCheckStateType;

/*****************************************************************************
*                            External Function Declarations	     		     *
******************************************************************************/
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
extern Std_ReturnType E2E_SMCheck(E2E_PCheckStatusType ProfileStatus, E2E_SMConfigType* ConfigPtr, E2E_SMCheckStateType* StatePtr);

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
extern Std_ReturnType E2E_SMCheckInit(E2E_SMCheckStateType* StatePtr, E2E_SMConfigType* ConfigPtr);

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
Date               : 22-May-2020
CDSID              : pangraje
Traceability       : RTC #897020
Change Description : Initial Framework version of E2E Module with Profile1
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/
