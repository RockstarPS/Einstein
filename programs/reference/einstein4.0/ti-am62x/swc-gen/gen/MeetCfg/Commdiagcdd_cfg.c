/*=================================================================================================================
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
**==================================================================================================================
**
** Name:           Iocalibdiagcdd_cfg.c
**
** Description:    contains configurable functions to call RTE /API for each service
**                 
**
**===================================================================================================================*/

#ifndef COMMDIAGCDD_CFG_C
#define COMMDIAGCDD_CFG_C

/*====================================================================================================================
**                 I N C L U D E   F I L E S
**===================================================================================================================*/

#include "Commdiagcdd_cfg.h"
#include "Mgrdiagcdd.h"
#include "Mgrdiagcdd_cfg.h"
#include <CanSM_Cfg.h> 
//#include "Cdd_Mcan_Cbk.h"


/*====================================================================================================================
**   I N T E R N A L   M A C R O   D E F I N I T I O N S
**===================================================================================================================*/

/*=====================================================================================================================
**  T Y P E    D E C L A R A T I O N S 
**====================================================================================================================*/
#ifdef COMM_BUS_VERIFICATION_TEST
static Std_ReturnType CommDiag_TxCbk_Read(void);
static Std_ReturnType CommDiag_RxCbk_Read(void);
static void CommDiag_ClearTxRxInfo(void);
static Std_ReturnType CommDiag_Tx_Msg(Comm_config_ID Comm_tx_msg_config_ID,const Comm_Signal_info* Comm_Tx_Sig_Info);
#endif

/*=====================================================================================================================
**  C O N S T A N T    A N D   V A R I A B L E S    D E C L A R A T I O N S
**====================================================================================================================*/

#ifdef COMM_BUS_VERIFICATION_TEST
const CommDiag_Comm_Bus_Msg CommDiag_Bus_Msg_Config = 
{
	&CommDiag_TxCbk_Read,&CommDiag_RxCbk_Read,&CommDiag_ClearTxRxInfo,&CommDiag_Tx_Msg,
};
#endif

#ifdef SERIAL_COMM_PARAMETER
// const SerialCommunicationConfigType SerialCommunicationConfig = 
// {
// 	&CommDiag_SerialCommuication_STA, &CommDiag_SerialCommuication_RCTE,
// };
#endif

#ifdef COMM_BUS_VERIFICATION_TEST
static uint8 l_msg_rcvd_U8 = MSG_NOT_RCVD;
static uint8 l_msg_txtd_U8  = MSG_NOT_TXTD;
#endif
/*=====================================================================================================================
**
** Function Name    :  CanIf_Transmit
**
** Visibility       :  Public 
**
** Description      :  calls API to send the CAN message. 
**                      
** Invocation       :  CommDiag_Tx_Msg
**
** Inputs           :  Data[in]:Message config ID and message information
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit(PduIdType CanTxPduId, P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_MSG_VAR) PduInfoPtr);

/*=====================================================================================================================
**
** Function Name    :  CommMcan_RxIndication
**
** Visibility       :  Public 
**
** Description      :  Indication CAN receive message callback. 
**                      
** Invocation       :  From CAN module
**
** Inputs           :  Data[in]:Message config ID and message information
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
FUNC(void, CANTP_CODE) CommMcan_RxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) PduInfoPtr)
{
	(void)RxPduId;
	(void)PduInfoPtr;
/* 	if(COMM_DATA_RX == *(PduInfoPtr->SduDataPtr))
	{
		l_msg_rcvd_U8 = MSG_RCVD;
	}
	else
	{
		
	} */
}

/*=====================================================================================================================
**
** Function Name    :  CommMcan_TxConfirmation
**
** Visibility       :  Public 
**
** Description      :  Indication CAN trasmit message callback. 
**                      
** Invocation       :  From CAN module
**
** Inputs           :  Data[in]:Message config ID
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
FUNC(void, CANTP_CODE) CommMcan_TxConfirmation(PduIdType TxPduId)
{
	(void)TxPduId;
   //l_msg_txtd_U8  = MSG_TXTD;
}

/*=====================================================================================================================
**  PRIVATE
**====================================================================================================================*/

#ifdef COMM_BUS_VERIFICATION_TEST
/*=====================================================================================================================
**
** Function Name    :  CommDiag_RxCbk_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read the reception status of the message. 
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_LeftSwitchBacklight_Read
**
** Inputs           :  Data[Out]:Left switch board backlight Calibrated value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType CommDiag_RxCbk_Read(void)
{

	return l_msg_rcvd_U8;
}

/*=====================================================================================================================
**
** Function Name    :  CommDiag_TxCbk_Read
**
** Visibility       :  Private 
**
** Description      :  calls API to read the transmission status of the message
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_LeftSwitchBacklight_Write
**
** Inputs           :  Data[In]:Left switch board backlight Calibrated value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType CommDiag_TxCbk_Read(void)
{
	return l_msg_txtd_U8; 
}

/*=====================================================================================================================
**
** Function Name    :  CommDiag_ClearTxRxInfo
**
** Visibility       :  Private 
**
** Description      :  calls API to clear TX and Rx mesaage status 
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_RightSwitchBacklight_Read
**
** Inputs           :  Data[Out]:Right switch board backlight Calibrated value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static void CommDiag_ClearTxRxInfo(void)
{
   l_msg_rcvd_U8 = MSG_NOT_RCVD;
   l_msg_txtd_U8  = MSG_NOT_TXTD;
}

/*=====================================================================================================================
**
** Function Name    :  CommDiag_Tx_Msg
**
** Visibility       :  Private 
**
** Description      :  calls API to write Right switch board backlight luminosity 
**                      
** Invocation       :  Iocalib.diagcdd, Function:Iocalibdiag_RightSwitchBacklight_Write
**
** Inputs           :  Data[In]:Right switch board backlight Calibrated value
**
** Outputs          :  E_OK : Success
**					   E_NOT_OK: Fail
**
** Critical Section : Yes/No
**
**====================================================================================================================*/
static Std_ReturnType CommDiag_Tx_Msg(Comm_config_ID Comm_tx_msg_config_ID,const Comm_Signal_info* Comm_Tx_Sig_Info)
{
	Std_ReturnType ret = E_NOT_OK;
    ret = CanIf_Transmit(Comm_tx_msg_config_ID,Comm_Tx_Sig_Info);
	return ret;
}
#endif

/*=====================================================================================================================
**  for each change to this file, be sure to record:                     
**  1.  who made the change and when the change was made                 
**  2.  why the change was made and the intended result                
**  Following block needs to be repeated for each change
**====================================================================================================================*/
/*=====================================================================================================================
**   Note: In the traceability column we need to trace back to the Design Doc.
**   For the initial version it is traced to the Design Document section.     
**   For further changes it shall trace to the source of the change which may
**   be SPSS/SCR/Defect details(Defect may be Testing/validation defect)/Any  
**   other reason                                                             
**====================================================================================================================*/
/*=====================================================================================================================
** Date              :  13/05/2020
** CDSID             :  dkasiman
** Traceability      :  RTC 880204
** Change Description:  Communication bus verification test service addition.
**====================================================================================================================*/

#endif
