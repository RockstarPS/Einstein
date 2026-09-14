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
** Name:           Ethdiagcdd.h
**
** Description:    Contains function prototypes ethernet related services
**
**
**====================================================================================================================*/
#ifndef ETHDIAGCDD_H
#define ETHDIAGCDD_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/
#include "Mgrdiagcdd.h"
#include "Mgrdiagcdd_cfg.h"

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
#ifdef ETHERNET_SQI_READ
Std_ReturnType Ethernet_diag_read_SQI(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef ETHERNET_LINK_STATUS_READ
Std_ReturnType Ethernet_diag_read_Link_Status(uint8 *Data, uint8 *ErrorCode);
#endif

#ifdef ETHERNET_TEST_MODE_IOCTRL
Std_ReturnType Ethdiag_EthTestModeControl_STA(uint8 *Data, uint8 *ErrorCode);
Std_ReturnType Ethdiag_EthTestModeControl_RCTE(uint8 *ErrorCode);
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
** Date              :  23/08/2022
** CDSID             :  Ajadhav5
** Traceability      :
** Change Description:  Ethernet test service addition.
**====================================================================================================================*/
#endif
