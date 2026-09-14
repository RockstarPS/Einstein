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
** Name:           Ethernetdiagcdd_cfg.h
**
** Description:    contains Ethernet services
**                
**
**====================================================================================================================*/
#ifndef ETHERNETDIAGCDD_CFG_H
#define ETHERNETDIAGCDD_CFG_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/
#include "Mgrdiagcdd.h"
#include "Mgrdiagcdd_cfg.h"
#include "Rte_CMeetCdd.h"


/*====================================================================================================================
**   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/
#ifdef ETHERNET_SQI_READ
#define cRead_EthernetSQIValueCtrl 	              ((uint32)0xFE00u)
#define cRead_EthernetSQIValue_DataLength         ((uint8)0x0u)
#endif

#ifdef ETHERNET_LINK_STATUS_READ
#define cRead_EthernetLinkStatusCtrl 	          ((uint32)0xFA0Cu)
#define cRead_EthernetLinkStatus_DataLength      ((uint8)0x0u)
#endif

#ifdef ETHERNET_TEST_MODE_IOCTRL
#define cIOC_EthernetTestModeCntrl 	              0xFD1Cu
#define cIOC_EthernetTestModeCntrl_DataLength     0x01u
#endif

#define IOCTRL_STA_ACTION             (3U)
#define IOCTRL_RCTE_ACTION            (0U)

/*======================================================================================================================
** T Y P E  D E F I N I T I O N S
**======================================================================================================================*/
typedef struct
{
	Std_ReturnType (*Read_EthernetSQI) (uint8 *Data,uint8 *ErrorCode);
}Ethernetdiag_SqiReadtype; 


typedef struct
{
	Std_ReturnType (*Read_EthernetLinkStatus) (uint8 *Data,uint8 *ErrorCode);
}Ethernetdiag_LinkStatusReadtype; 

typedef struct
{
	Std_ReturnType (*EthTestModeDiag_STA) (uint8 *Data, uint8 *ErrorCode);
	Std_ReturnType (*EthTestModeDiag_RCTE) (uint8 *ErrorCode);
}EthTestModeDiag_IOCTL;
/*=====================================================================================================================
*  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**===================================================================================================================*/
extern const Ethernetdiag_SqiReadtype Ethernetdiag_SqiReadConfig;
extern const Ethernetdiag_LinkStatusReadtype Ethernetdiag_LinkStatusConfig;

#ifdef ETHERNET_TEST_MODE_IOCTRL
extern const EthTestModeDiag_IOCTL EthTestModeConfig;
#endif
/*=====================================================================================================================
*   P U B L I C
**=====================================================================================================================*/


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
** Date              :  22/August/2022
** CDSID             :  Ajadhav5
** Traceability      :  RTC 
** Change Description:  Initial version of Ethernet DID implementation
**====================================================================================================================*/
#endif


