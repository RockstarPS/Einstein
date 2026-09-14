/*===================================================================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2001. Visteon Corporation owns all rights to this work and
** intends to maintain it in confidence to preserve its trade secret status.
** Visteon Corporation reserves the right, under the copyright laws of the
** United States or those of any other country that may have jurisdiction,
** to protect this work as an unpublished work, in the event of an
** inadvertent or deliberate unauthorized publication. Visteon Corporation
** also reserves its rights under all copyright laws to protect this work as
** a published work, when appropriate. Those having access to this work may
** not copy it, use it, modify it or disclose the information contained in
** it without the written authorization of Visteon Corporation.
**
**===================================================================================================================
**
** Name:           Mgrdiagcdd.h
**
** Description:
**
**
**====================================================================================================================*/
#ifndef MGRDIAGCDD_H
#define MGRDIAGCDD_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/
#include "Mgrdiagcdd_cfg.h"
/*====================================================================================================================
**   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/
#define cFALSE              (0U)
#define cTRUE               (1U)

#define DATA_BYTE_0         (uint8)0u
#define DATA_BYTE_1         (uint8)1u
#define DATA_BYTE_2         (uint8)2u
#define DATA_BYTE_3         (uint8)3u
#define DATA_BYTE_4         (uint8)4u
#define DATA_BYTE_5         (uint8)5u
#define DATA_BYTE_6         (uint8)6u
#define DATA_BYTE_7         (uint8)7u
#define DATA_BYTE_8         (uint8)8u
#define DATA_BYTE_9         (uint8)9u
#define DATA_BYTE_10        (uint8)10u
#define DATA_BYTE_11        (uint8)11u
#define DATA_BYTE_12        (uint8)12u
#define DATA_BYTE_13        (uint8)13u
#define DATA_BYTE_14        (uint8)14u
#define DATA_BYTE_15        (uint8)15u
#define DATA_BYTE_16        (uint8)16u
#define DATA_BYTE_17        (uint8)17u
#define DATA_BYTE_18        (uint8)18u
#define DATA_BYTE_19        (uint8)19u
#define DATA_BYTE_20        (uint8)20u
#define DATA_BYTE_21        (uint8)21u
#define DATA_BYTE_22        (uint8)22u
#define DATA_BYTE_23        (uint8)23u
#define DATA_BYTE_24        (uint8)24u
#define DATA_BYTE_25        (uint8)25u
#define DATA_BYTE_26        (uint8)26u
#define DATA_BYTE_27        (uint8)27u
#define DATA_BYTE_28        (uint8)28u
#define BYTE_MAX_FF         (uint8)0xFFu

#define MEET_INDEX_ZERO     (uint8)0u
#define MEET_INDEX_ONE      (uint8)1u
#define MEET_INDEX_TWO      (uint8)2u

#define INC_BY_1            (uint8)1u
#define ROUTINETYPE1        0x10U
#define ROUTINETYPE2        0x20U

#define INVALID_RCTYPE      0xFFU

#define MGRDIAGCDD_MAX_ALLOWED_SERVICE ((uint8)29U)

/*======================================================================================================================
** T Y P E  D E F I N I T I O N S
**======================================================================================================================*/

typedef enum
{
    eROUTINE_INACTIVE,
    eROUTINE_INPROGRESS,
    eROUTINE_FINISH_OK,
    eROUTINE_FINISH_NOK,
    eROUTINE_STOPPED,
} eRoutineStatus;

typedef enum
{
    eROUTINE_COMPLETED,
    eROUTINE_ABORTED,
    eROUTINE_ACTIVE,
} eRoutineStatus2;

typedef enum
{
    eROUTINE_CHECKSUM_NOK,
    eROUTINE_CHECKSUM_OK,
    eROUTINE_CHECKSUM_DEFAULT = 0xFF,
} eRoutineStatus_Recorder_Byte;

typedef enum NVMWriteRequestStatus
{
    eNVMWrite_InitiateRequest,
    eNVMWrite_WaitForResponse
} NVMWriteRequestState;

#if 0
typedef enum GIPDataRquestStatus
{
    eGIP_InitiateRequest,
    eGIP_WaitForResponse
}GIPDataRquestState;
#endif

/*=====================================================================================================================
 *  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
 **===================================================================================================================*/
#ifdef READ_INTERFACE_FOR_APPL_COMPONENTS
static uint8 IsUpdateCompletedForThisInit = E_NOT_OK;
#endif
/*=====================================================================================================================
 *   P U B L I C
 **=====================================================================================================================*/

#if (BCDMANIPUTATION_ENABLE_ANALOG_DIAG > 0) || (BCDMANIPUTATION_ENABLE_DIMMING_CTRL > 0)
extern uint16 DutyManipulateWithBCD(uint16 Data_msb, uint16 Data_lsb);
#endif

#if (DECIMALMANIPUTATION_ENABLE_ANALOG_DIAG > 0) || (DECIMALMANIPUTATION_ENABLE_DIMMING_CTRL > 0)
extern uint16 DutyManipulateWitDecimal(uint16 Data_msb, uint16 Data_lsb);
#endif

extern uint8 RoutineCtrlStatusUpdate(uint8 RCType, uint8 RCState);
/*======================================================================================================================
**  for each change to this file, be sure to record:
**  1.who made the change and when the change was made
**  2.why the change was made and the intended result
**  following block needs to be repeated for each change
**======================================================================================================================*/
/*   Note: In the traceability column we need to trace back to the Design Doc.
**   For the initial version it is traced to the Design Document section.
**   For further changes it shall trace to the source of the change which may
**   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any
**   other reason
**======================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/09/2023
** CDSID             :  mprajapa
** Traceability      :  JIRA 3839
** Change Description:  Upddated identation and INVALID MODE macro migration in cfg header file.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/01/2020
** CDSID             :  dkasiman
** Traceability      :  RTC 1380314
** Change Description:  Coverity/Misra fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  12/12/2019
** CDSID             :  dkasiman
** Traceability      :  RTC 1389704
** Change Description:  Additional macros added for future purpose.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  9/11/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1368184
** Change Description:  For MGRDIAGCDD_..._ACTION comments modified
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  26/Mar/2019
** CDSID             :  dkasiman
** Traceability      :  RTC 1303833
** Change Description:  GIPDataRquestState definition moved to Mgrdiagcdd_cfg.h.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  18/march/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1297724
** Change Description:  DutyManipulateWithBCD and DutyManipulateWitDecimal declared
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  02/March/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1262819
** Change Description:  some gip related function moved from src to cfg file
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  01/02/2019
** CDSID             :  razhakes
** Traceability      :  RTC 1262819
** Change Description:  Mgrdiag update for VIP - GIP communication,Structure types are added.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  16/10/2018
** CDSID             :  gdhilipr
** Traceability      :  RTC 1217469
** Change Description:  Memory checksum test(F11E) � VIP,GIP,NAND and NOR
**====================================================================================================================*/
/*======================================================================================================================
** Date              : 20/May/2018
** CDSID             : dkasiman
** Traceability      : RTC-1112314
** Change Description: Initial verion for MeetCdd bookshelf
**=======================================================================================================================*/
/*======================================================================================================================
** Date              : 20/May/2018
** CDSID             : dkasiman
** Traceability      : RTC-1112314
** Change Description: MGRDIAG_INVALID_MODE macro added and other files need to use that macro instead of INVALID_MODE
**=======================================================================================================================*/

#endif /* MGRDIAGCDD_H */
