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
** Name:           Commdiagcdd_cfg.h
**
** Description:    Contains configurable parameters for Communication related services
**                
**
**====================================================================================================================*/
#ifndef COMMDIAGCDD_CFG_H
#define COMMDIAGCDD_CFG_H

/*====================================================================================================================
** INCLUDE FILES
**===================================================================================================================*/
#include "Mgrdiagcdd_cfg.h"
#include "Mgrdiagcdd.h"
/*====================================================================================================================
**   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/
#ifdef COMM_BUS_VERIFICATION_TEST
#define COMM_DATA_TX  ((uint8)0xA5)
#define COMM_DATA_RX  ((uint8)0xDC)
#define COMM_DATA_TX_LENGTH  ((uint8)1)


#define COMM_BUS_ID	   ((uint8)0)
#define COMM_TX_CONFIG_ID ((uint8)12)


#define MSG_RCVD																	((uint8)1U)
#define MSG_NOT_RCVD																((uint8)0U)

#define MSG_TXTD																	((uint8)1U)
#define MSG_NOT_TXTD																((uint8)0U)

#define COMMBUSRCTYPE 																((uint8)2U)

#define COMM_TIMER_ELAPSE_VAL		((uint8)200)
#endif  
/*======================================================================================================================
** T Y P E  D E F I N I T I O N S
**======================================================================================================================*/
#ifdef COMM_BUS_VERIFICATION_TEST

typedef PduIdType Comm_config_ID;
typedef PduInfoType Comm_Signal_info;

typedef struct
{
	Std_ReturnType (*CommDiag_TxCbk) (void);
	Std_ReturnType (*CommDiag_RxCbk) (void);
	void (*CommDiag_ClrRxTxInfo)(void);
	Std_ReturnType (*CommDiag_TxMsg) (Comm_config_ID Comm_tx_msg_config_ID,const Comm_Signal_info* Comm_Tx_Sig_Info);
}CommDiag_Comm_Bus_Msg;
#endif

#ifdef SERIAL_COMM_PARAMETER
// typedef struct
// {
// 	Std_ReturnType (*SerialCommunication_STA) (uint8 *Data, uint8 *ErrorCode);
// 	Std_ReturnType (*SerialCommunication_RCTE)(uint8 *ErrorCode);
// }SerialCommunicationConfigType;
#endif

FUNC(void, CANTP_CODE) CommMcan_TxConfirmation(PduIdType TxPduId);
FUNC(void, CANTP_CODE) CommMcan_RxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) PduInfoPtr);
/*=====================================================================================================================
*  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**===================================================================================================================*/
#ifdef COMM_BUS_VERIFICATION_TEST
extern const CommDiag_Comm_Bus_Msg CommDiag_Bus_Msg_Config;
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
** Date              :  13/05/2020
** CDSID             :  dkasiman
** Traceability      :  RTC 880204
** Change Description:  Communication bus verification test service addition.
**====================================================================================================================*/

#endif


