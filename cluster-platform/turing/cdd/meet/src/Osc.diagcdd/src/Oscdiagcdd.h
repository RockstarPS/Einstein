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
** Name:           Oscdiagcdd.h
**
** Description:
**
**
**====================================================================================================================*/
#ifndef OSCDIAGCDD_H
#define OSCDIAGCDD_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/
#include "Std_Types.h"
#include "Oscdiagcdd_cfg.h"
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
#ifdef OSCDIAG_QUARTZ_CORRECTION
Std_ReturnType Oscdiag_Quartz_Correction_Read(uint8 *Data, const uint8 *ErrorCode);
Std_ReturnType Oscdiag_Quartz_Correction_Write(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef OSCDIAG_QUARTZ_CONTROL
Std_ReturnType Oscdiag_Quartz_Control_ShortTermAdjustment(const uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Oscdiag_Quartz_Control_ReturnControlToECU(uint8 *ErrorCode);
#endif

#ifdef OSCDIAG_CLOCKVALUE_ENABLE
Std_ReturnType Oscdiag_ClockValue_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Oscdiag_ClockValue_Write(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef OSCDIAG_CLOCK_MONITORING
Std_ReturnType Oscdiag_clock_Monitoring_RC_Start(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef OSCDIAG_QUARTZ_CRYSTAL_LOAD_CAPACITANCE_FUSE_ACCESS
Std_ReturnType Oscdiag_Quartz_Load_Capacitance_Fuse_Access_Read(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Oscdiag_Quartz_Load_Capacitance_Fuse_Access_Write(uint8 *Data, uint8 *ErrorCode);
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
** Change Description:  Clock value read and write interfaces are added.
**====================================================================================================================*/
/*======================================================================================================================
** Date              : 23/May/2018
** CDSID             : dkasiman
** Traceability      : RTC-1111915
** Change Description: Initial verion for MeetCdd bookshelf - Osc diag services
**=======================================================================================================================*/
/*======================================================================================================================
** Date              : 5/Jun/2018
** CDSID             : dkasiman
** Traceability      : RTC-1111915
** Change Description: Review comments fix - Osc diag services
**=======================================================================================================================*/
#endif /* OSCDIAGCDD_H */
