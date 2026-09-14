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
** Name:           Commdiagcdd.h
**
** Description:    Contains function prototypes Communication related services
**
**
**====================================================================================================================*/
#ifndef COMMDIAGCDD_H
#define COMMDIAGCDD_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/
#include "Mgrdiagcdd.h"
#include "Mgrdiagcdd_cfg.h"

#ifdef COMMCONTROLDIAG_CXPITEST_ROUTINE
Std_ReturnType Commdiag_CxpiCddcontroldiag_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Commdiag_CxpiCddcontroldiag_RCStop(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Commdiag_CxpiCddcontroldiag_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef COMMCONTROLDIAG_MCANTEST_ROUTINE
Std_ReturnType Commdiag_Mcancontroldiag_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Commdiag_Mcancontroldiag_RCStop(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Commdiag_Mcancontroldiag_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef COMMCONTROLDIAG_GIPTEST_ROUTINE
Std_ReturnType Commdiag_GIPcontroldiag_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Commdiag_GIPcontroldiag_RCStop(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Commdiag_GIPcontroldiag_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef MM_CAN_TEST_ENABLE
Std_ReturnType Commdiag_Mmcan_Read(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef COMMDIAGCDD_I2C_TEST_ENABLE
Std_ReturnType Commdiag_I2C_Test_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Commdiag_I2C_Test_RCStop(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Commdiag_I2C_Test_RCStatus(uint8 *Data, uint8 *ErrorCode);
#endif
#ifdef COMDIAG_MODULE_ENABLE
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
#ifdef COMM_BUS_VERIFICATION_TEST
Std_ReturnType Comm_Bus_Verification_Test_RCStart(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Comm_Bus_Verification_Test_RCStatus(uint8 *Data, uint8 *ErrorCode);
void Comm_Bus_Periodic_Function(void);
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
** Date              :  13/05/2020
** CDSID             :  dkasiman
** Traceability      :  RTC 880204
** Change Description:  Communication bus verification test service addition.
**====================================================================================================================*/
#endif
#endif
