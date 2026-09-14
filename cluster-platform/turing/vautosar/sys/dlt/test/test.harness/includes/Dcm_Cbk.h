/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2016. Visteon Corporation owns all rights to           *
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
#ifndef DCM_CBK_H
#define DCM_CBK_H
/*****************************************************************************
 *  File Name         :  Dcm_Cbk.h                                                *
 *  Module Short Name :  DiagMgr                                               *
 *  VOBName           :                                                       *
 *  Author            : msavariy                                              *
 *  Description       : This file contains the Diagnostics request and        *
 *                       response handling functionlities.                    *
 *                                                                            *
 * Organization     :  Driver Information Software Section,                   *
 *                     Visteon Software Operation                             *
 *                     Visteon Corporation                                    *
 *                                                                            *
 * ---------------------------------------------------------------------------*
 * Compiler Name    :  GHS                                                    *
 * Target Hardware  :                                                         *
 *                                                                            *
 ******************************************************************************/
/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/

# include "Dcm_Types.h"

/*****************************************************************************
 *                                 Type Declarations                          *
 ******************************************************************************/

/*****************************************************************************
 *                                Globally  accessed Variable Declarations    *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

/*****************************************************************************
 *                                 Locally used Variable Declarations         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

/*****************************************************************************
 *                   Functions                                                *
 ******************************************************************************/

#ifndef DCM_C
#define EXTERN extern
#else
#define EXTERN
#endif

/* Callback Notifications */
/**************************************************************************
 Function name   : BufReq_ReturnType Dcm_CopyRxData
 Arguments       : PduIdType DcmRxPduId, const PduInfoType* info, PduLengthType* bufferSizePtr
 Return type     : BufReq_ReturnType
 Description     : This function is called to provide the received data of an I-PDU segment (N-PDU)
 to the upper layer.
 **************************************************************************/
EXTERN BufReq_ReturnType Dcm_CopyRxData(PduIdType DcmRxPduId, const PduInfoType *info, PduLengthType *bufferSizePtr);

/**************************************************************************
 Function name   : BufReq_ReturnType Dcm_StartOfReception
 Arguments       : PduIdType DcmRxPduId, const PduInfoType* info, PduLengthType TpSduLength, PduLengthType* bufferSizePtr
 Return type     : BufReq_ReturnType
 Description     : This function is called to indicate the start of new diag request.
 **************************************************************************/
EXTERN BufReq_ReturnType Dcm_StartOfReception(PduIdType DcmRxPduId, const PduInfoType *info, PduLengthType TpSduLength,
        PduLengthType *bufferSizePtr);

/**************************************************************************
 Function name   : void Dcm_TpRxIndication
 Arguments       : PduIdType DcmRxPduId, Std_ReturnType result
 Return type     : void
 Description     : This function is called to indicate whether the transmission was successful or not.
 **************************************************************************/
EXTERN void Dcm_TpRxIndication(PduIdType DcmRxPduId, Std_ReturnType result);

/**************************************************************************
 Function name   : BufReq_ReturnType Dcm_CopyTxData
 Arguments       : PduIdType DcmRxPduId, const PduInfoType* info, RetryInfoType* retry, PduLengthType* availableDataPtr
 Return type     : BufReq_ReturnType
 Description     : This function is called to acquire the transmit data of an I-PDU segment.
 **************************************************************************/

EXTERN BufReq_ReturnType Dcm_CopyTxData(PduIdType DcmRxPduId, const PduInfoType *info, RetryInfoType *retry,
                                        PduLengthType *availableDataPtr);

/**************************************************************************
 Function name   : void Dcm_TpTxConfirmation
 Arguments       : PduIdType DcmRxPduId, Std_ReturnType result
 Return type     : void
 Description     : the result indicates whether the diag response
 transmission was successful or not.
 **************************************************************************/

EXTERN void Dcm_TpTxConfirmation(PduIdType DcmTxPduId, Std_ReturnType result);

/**************************************************************************
 Function name   : void Dcm_TxConfirmation
 Arguments       : PduIdType DcmRxPduId, Std_ReturnType result
 Return type     : void
 Description     : the result indicates whether the diag response
 transmission was successful or not.
 **************************************************************************/

EXTERN void Dcm_TxConfirmation(PduIdType TxPduId);

/**************************************************************************
 Function name   : void Dcm_ComM_NoComModeEntered
 Arguments       : uint8 NetworkId
 Return type     : void
 Description     : This call informs the Dcm module about a ComM mode change to
 COMM_NO_COMMUNICATION.
 **************************************************************************/

EXTERN void Dcm_ComM_NoComModeEntered(uint8 NetworkId);

/**************************************************************************
 Function name   : void Dcm_ComM_SilentComModeEntered
 Arguments       : uint8 NetworkId
 Return type     : void
 Description     : This call informs the Dcm module about a ComM mode change to
 COMM_SILENT_COMMUNICATION.
 **************************************************************************/
EXTERN void Dcm_ComM_SilentComModeEntered(uint8 NetworkId);

/**************************************************************************
 Function name   : void Dcm_ComM_FullComModeEntered
 Arguments       : uint8 NetworkId
 Return type     : void
 Description     : This call informs the Dcm module about a ComM mode change to
 COMM_FULL_COMMUNICATION.
 **************************************************************************/

EXTERN void Dcm_ComM_FullComModeEntered(uint8 NetworkId);

#undef EXTERN
#endif

/*****************************************************************************
 *     End of File
 *
 *******************************************************************************/
/****************************************************************************
 *   for each change to this file, be sure to record:                        *
 *      1.  who made the change and when the change was made                 *
 *      2.  why the change was made and the intended result                  *
 *   Following block needs to be repeated for each change                    *
 *****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 22-Feb-2015                                            */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      :                                                       */
/*Change Description: Datadesign And Framework implemented, Initial Version */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 18-Jan-2022                                           */
/*Version           :                                                       */
/*By                : iiliev1                                               */
/*Traceability      : Rtc#1560389                                           */
/*Change Description: DCM and DEM Autosar 4.2.2 Migration                   */
/*--------------------------------------------------------------------------*/
