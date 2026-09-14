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
#ifndef E2E_USERPROFILE_H
#define E2E_USERPROFILE_H
/*****************************************************************************
*  File Name         :  E2E_USERPROFILE_H                         	     	 *
*  Module Short Name :  E2E_USERPROFILE_H                         	     	 *
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

/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*8bit checksum and rolling counter */
typedef enum
{
    E2E_USERPROFILE8BITCHECKSUMSTATUS_OK            = 0x00u,
    E2E_USERPROFILE8BITCHECKSUMSTATUS_ERROR         = 0x01u,
    E2E_USERPROFILE8BITCHECKSUMSTATUS_ABN_CHECKSUM  = 0x02u,
    E2E_USERPROFILE8BITCHECKSUMSTATUS_ROLLING_COUNTER_LOCK  = 0x003u,
} E2E_UserProfile8BitCheckSumCheckStatusType;

#define STANDARD_FRAME_TYPE  0x8U
#define EXTENDED_FRAME_TYPE  0x0U

typedef struct
{
    uint32 CounterOffset;
} E2E_UserProfile8BitCheckSumConfigType;

typedef struct
{
    boolean InitValue;
    uint8 Counter;
    uint32 Protect_Timecounter;
} E2E_UserProfile8BitCheckSumProtectStateType;

typedef struct
{
    E2E_UserProfile8BitCheckSumCheckStatusType Status;
    uint8 Cal_wind_Time;
    uint32 Error_count;
    uint8 Check_Timecounter;
} E2E_UserProfile8BitCheckSumCheckStateType;

/*****************************************************************************
*                            External Function Declarations                  *
******************************************************************************/
/*============================================================================
**
** Function Name    :   E2E_UserProfile8BitCheckSumProtect
**
** Visibility       :   Public
**
** Description      :   Protects the array/buffer to be transmitted using the E2E UserProfile.
**                      This includes checksum calculation and handling of alive counter.
**
** Invocation       :
**
** Inputs           :   E2E_UserProfile8BitCheckSumConfigType * ConfigPtr - Pointer to a configuration type.
**                      E2E_UserProfile8BitCheckSumProtectStateType * StatePtr - Pointer to ProtectState type.
**                      uint8 * DataPtr - Data Pointer.
**                      uint16 Length - Length of the data
**
** Outputs          :   Std_ReturnType
**
** Critical Section :   NA
**
**==========================================================================*/
extern Std_ReturnType E2E_ProtectUserProfile8BitCheckSumProtect(E2E_UserProfile8BitCheckSumConfigType* ConfigPtr, E2E_UserProfile8BitCheckSumProtectStateType* StatePtr, uint8* DataPtr, uint16 Length);

/*============================================================================
**
** Function Name    :   E2E_UserProfile8BitCheckSumProtectInit
**
** Visibility       :   Public
**
** Description      :   Initializes the Counter.
**
** Invocation       :
**
** Inputs           :   E2E_UserProfile8BitCheckSumProtectStateType * StatePtr - Pointer to ProtectState type.
**
** Outputs          :   Std_ReturnType
**
** Critical Section :   NA
**
**==========================================================================*/
extern Std_ReturnType E2E_UserProfile8BitCheckSumProtectInit(E2E_UserProfile8BitCheckSumProtectStateType* StatePtr);

/*============================================================================
**
** Function Name    :   E2E_UserProfile8BitCheckSumCheck
**
** Visibility       :   Public
**
** Description      :   Check the array/buffer using the E2E the E2E UserProfile.
**                      This includes checksum calculation and handling of alive counter.
**
** Invocation       :
**
** Inputs           :   E2E_UserProfile8BitCheckSumConfigType * ConfigPtr - Pointer to a configuration type.
**                      E2E_UserProfile8BitCheckSumCheckStateType * StatePtr - Pointer to CheckSate type.
**                      uint8 * DataPtr - Data Pointer.
**                      uint16 Length - Length of the data
**
** Outputs          :   Std_ReturnType
**
** Critical Section :   NA
**
**==========================================================================*/
extern Std_ReturnType E2E_CheckUserProfile8BitCheckSumCheck(E2E_UserProfile8BitCheckSumConfigType* ConfigPtr, E2E_UserProfile8BitCheckSumCheckStateType* StatePtr, uint8* DataPtr, uint16 Length);

/*============================================================================
**
** Function Name    :   E2E_UserProfile8BitCheckSumCheckInit
**
** Visibility       :   Public
**
** Description      :   Initializes the check states.
**
** Invocation       :
**
** Inputs           :   E2E_UserProfile8BitCheckSumCheckStateType * StatePtr - Pointer to CheckSate type.
**
** Outputs          :   Std_ReturnType
**
** Critical Section :   NA
**
**==========================================================================*/
extern Std_ReturnType E2E_UserProfile8BitCheckSumCheckInit(E2E_UserProfile8BitCheckSumCheckStateType* StatePtr);
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
Date               : 11-Sep-2020
CDSID              : bbaskara
Traceability       : RTC #1039071
Change Description : Initial Framework version of E2E Module
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 10-May-2022
CDSID              : dbalasub
Traceability       : RTC #1654041
Change Description : Coverity & MISRA warning analysis and fix
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/
