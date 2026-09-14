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
** Name:           Resetsleepdiagcdd.h
**
** Description:    contains function prototypes for Reset and Sleep services
**
**
**====================================================================================================================*/
#ifndef RESETSLEEPDIAGCDD_H
#define RESETSLEEPDIAGCDD_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/
#include "Mgrdiagcdd_cfg.h"
#ifdef RESETDIAG_MODULE_ENABLE
#include "Mgrdiagcdd.h"
/*====================================================================================================================
**   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/

/*======================================================================================================================
** T Y P E  D E F I N I T I O N S
**======================================================================================================================*/

/*=====================================================================================================================
 *  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
 **===================================================================================================================*/

/*=====================================================================================================================
 *   P U B L I C
 **=====================================================================================================================*/
void ResetSleepdiag_Init(void);

#ifdef SLEEPMODEENABLE
Std_ReturnType Resetsleepdiag_SleepingMode_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Resetsleepdiag_SleepingMode_RCStop(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Resetsleepdiag_SleepingMode_RCStatus(uint8 *Data, uint8 *ErrorCode);
void Manuf_Sleep_Task(void);
#endif

#ifdef WDRSTENABLE
Std_ReturnType Resetsleepdiag_WDReset_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Resetsleepdiag_WDReset_RCStop(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Resetsleepdiag_WDReset_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef RSTCNTRREADINGENABLE
Std_ReturnType Resetsleepdiag_ResetCounters_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Resetsleepdiag_ResetCounters_Write(uint8 *Data, uint8 *ErrorCode);
#endif

/*#if SWRSTENABLE
Std_ReturnType Resetsleepdiag_SWReset(uint8 *Data, uint8 *ErrorCode);
#endif*/

#if defined(SWRSTENABLE) || defined(WDRSTENABLE)
void ResetDiag_Periodic(void);
#endif

#ifdef RESETSLEEPDIAG_ODOMETER_RESET
Std_ReturnType Resetsleepdiag_odometer_Reset(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef LOWQCURRENTENABLE
Std_ReturnType ResetSleepdiag_Get_LowQCurrent_Sleep_Status(ELowQCurrentSleepStatus *Data);
Std_ReturnType ResetSleepdiag_SetLowQCurrent(ELowQCurrentSleepStatus *Data);

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
** Date              :  16/05/2022
** CDSID             :  ddanecha
** Traceability      :  RTC 1632871, 1655512, 1660171
** Change Description:  SetLowQCurrent interface is updated to support configuration interface
** 						Datatype updated for GetLowQCurrent
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  06/06/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1126958
** Change Description:  removed extern keyword for function prototypes,comments updated
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  31/05/2018
** CDSID             :  athiyag2
** Traceability      :  RTC 1126958
** Change Description:  included conditional compilation of features,removed SW Reset RC Stop and status functions
                        as SW Reset is not routine control type.
**====================================================================================================================*/
/*=====================================================================================================================
** Date              : 23/05/2018
** CDSID             : athiyag2
** Traceability      : RTC 1113499
** Change Description: Initial version - ResetSleepDiagCdd Implementation for Turing Bookshelf.
**====================================================================================================================*/
#endif
#endif
