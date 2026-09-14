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
** Name:           ShareDiagcdd.h
**
** Description:
**
**
**====================================================================================================================*/
#ifndef SHAREDIAGCDD_H
#define SHAREDIAGCDD_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/
#include "Std_Types.h"

typedef enum
{
    program = 1,
    blockErase,
    read,
    idle,
} t_command;

typedef struct
{
    uint8 *pRAMBuff;
    uint32 pAddrToProgram;
    uint32 pAddrToErase;
    uint32 Size;
    uint32 speedup;
    t_command command;
    t_command nextcommand;
} argumentBuffer_t;

typedef argumentBuffer_t *argumentBuffer_p;

#define SHAREDIAG_ROUNDUP_VALUE(Value) \
    ((uint16)(((((Value) + 1U) + ((SHAREDIAG_GRANULARITY_BYTES)-1U)) / (SHAREDIAG_GRANULARITY_BYTES)) * (SHAREDIAG_GRANULARITY_BYTES)))

#define SHAREDIAG_MIRROR_VALID(Index) \
    ((*(uint8 *)(NVMMirrors[Index])) != SHAREDIAG_ERASED_VALUE)

#define SHAREDIAG_GET_NEXT_MIRROR(x) ((uint8)((x) + (uint8)1) % (uint8)2)

#define SHAREDIAG_NVM_FIRST_FLASH(Index) \
    ((*(uint8 *)(NVMMirrors[Index])) == SHAREDIAG_FIRST_FLASH)

/*====================================================================================================================
** FUNCTION DECLARATIONS
**===================================================================================================================*/

void ShareDiag_PreInit(void);
void ShareDiag_Init(void);

#ifdef SHAREDIAG_SERVICE_ENABLE_1
Std_ReturnType ShareDiag_Read_Service_1(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType ShareDiag_Write_Service_1(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef SHAREDIAG_SERVICE_ENABLE_2
Std_ReturnType ShareDiag_Read_Service_2(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType ShareDiag_Write_Service_2(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef SHAREDIAG_SERVICE_ENABLE_3
Std_ReturnType ShareDiag_Read_Service_3(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType ShareDiag_Write_Service_3(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef SHAREDIAG_SERVICE_BOOT_READ
void Shareddiag_ReadBootVersion(uint8 *pBuffer);
#endif
#endif
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
** Change Description:  Upddated identation.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  24/01/2020
** CDSID             :  dkasiman
** Traceability      :  RTC 1380314
** Change Description:  Coverity/Misra fix.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  27/Mar/2019
** CDSID             :  MGANAPAT
** Traceability      :  RTC 1303833
** Change Description: Read boot version function added
**====================================================================================================================*/
