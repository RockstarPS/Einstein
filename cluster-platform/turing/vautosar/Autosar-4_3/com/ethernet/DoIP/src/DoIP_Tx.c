/********************************************************************************************************************
*                                   C O P Y R I G H T                                                               *
*********************************************************************************************************************
* Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
*                                                                                                                   *
* NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                  *
* Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
* or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
* in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its      *
* rights under all copyright laws to protect this work as a published work, when appropriate.                       *
* Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it  *
* without the written authorization of Visteon Corporation.                                                         *
********************************************************************************************************************/
/*!*****************************************************************************************************************
*   @file DoIP_Tx.c
*   @ingroup DoIP
*   @brief This file implements the DoIP transmit functionality of udp and tcp data.
********************************************************************************************************************/
/********************************************************************************************************************
*  HEADER INCLUDES                                                                                                  *
********************************************************************************************************************/
#include "DoIP.h"
#include "DoIP_Lcfg.h"
#include "SchM_DoIP.h"
#include "DoIP_MemMap.h"
#include "DoIP.h"
#include "PduR_DoIP.h"
#include "DoIP_Internal.h"
/********************************************************************************************************************
*  PRIVATE MACRO DEFINITIONS                                                                                        *
********************************************************************************************************************/
#if (DOIP_USE_VEHICLE_IDENTIFICATION_SYNC_STATUS == STD_ON)
# define DOIP_ACK_VEHICLE_IDENT_LENGTH     33u
#else
# define DOIP_ACK_VEHICLE_IDENT_LENGTH     32u
#endif
#if ( DOIP_ENTITY_STATUS_MAX_BYTE_FIELD_USE == STD_ON )
# define DOIP_ACK_ENTITY_STATE_LENGTH      7u
#else
# define DOIP_ACK_ENTITY_STATE_LENGTH      3u
#endif 
/********************************************************************************************************************
*  PRIVATE VARIABLE AND CONSTANT DECLARATION                                                                        *
********************************************************************************************************************/

/********************************************************************************************************************
*  PRIVATE FUNCTION PROTOTYPES                                                                                      *
********************************************************************************************************************/
#define DOIP_START_SEC_CODE
#include "MemMap.h"
/* #! Udp transmit */
/*!******************************************************************************************************************
* @brief This api is used to process the udp transmit request immediately
* @param[in] ConIdx the DoIP connection Idx
* @param[in] HeaderType the header type
* @param[in] Param the parameter value
* @param[in] CloseSocketReq the request to close socket connection
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_TxUdpTransmitImmediately
(
    DoIP_ConIdxType ConIdx,
    uint16 HeaderType,
    uint16 Param,
    boolean CloseSocketReq
);
/*!******************************************************************************************************************
* @brief This api is used to process the udp transmit request 
* @param[in] ConIdx the DoIP connection Idx
* @param[in] HeaderType the header type
* @param[in] Param the parameter value
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_TxUdpSingleTransmit
(
    DoIP_ConIdxType ConIdx,
    uint16 HeaderType,
    uint16 Param
);
/*!******************************************************************************************************************
* @brief This api is used to process the udp transmit vehicle announcement and identification response 
* @param[in] ConIdx the DoIP connection Idx
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_TxUdpSingleTransmitVehicleAnnounceAndIdentRes(DoIP_ConIdxType ConIdx);
/*!******************************************************************************************************************
* @brief This api is used to process the udp transmit general Negative Ack response 
* @param[in] ConIdx the DoIP connection Idx
* @param[in] HeaderType the header type
* @param[in] NackCode the negative ack code
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_TxUdpSingleTransmitGenNack
(
    DoIP_ConIdxType ConIdx,
    uint16 HeaderType,
    uint8 NackCode
);
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_TxUdpSingleTransmitDiagPowerModeInfoRes
(
    DoIP_ConIdxType ConIdx,
    uint8 DiagPowerMode
);
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_TxUdpSingleTransmitEntityStateRes(DoIP_ConIdxType ConIdx);
#if ( DOIP_OEM_PAYLOAD_TYPE_ENABLED == STD_ON )
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_TxUdpSingleTransmitOemSpecific(DoIP_ConIdxType ConIdx,uint16 HdrTypeOem);
#endif
/*!******************************************************************************************************************
* @brief This api is used to update the generic header to the buffer
* @param[in] HeaderType the header type
* @param[in] HeaderLength the header length 
* @param[out] pBuffer pointer to the header buffer 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_UpdateGenericHeader
(
    uint16 HeaderType,
    uint32 HeaderLength,
    P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) pBuffer
);
/*!******************************************************************************************************************
* @brief This api is used to update the VIN to the buffer
* @param[out] pBuffer pointer to the VIN buffer 
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_UpdateVin(P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) pBuffer) ;
/*!******************************************************************************************************************
* @brief This api is used to update the EID to the buffer
* @param[out] pBuffer pointer to the EID buffer 
* @param[in] ConIdx the DoIP connection Idx
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_UpdateEid
(
    P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) pBuffer,
    DoIP_ConIdxType ConIdx
);
/*!******************************************************************************************************************
* @brief This api is used to update the GID to the buffer
* @param[out] pBuffer pointer to the GID buffer 
* @param[in] ConIdx the DoIP connection Idx
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_UpdateGid
(
    P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) pBuffer,
    DoIP_ConIdxType ConIdx
);
/*!******************************************************************************************************************
* @brief This api is used to update the further action bytes to the buffer
* @param[out] pBuffer pointer to the further action bytes buffer 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_UpdateFurtherAction(P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) pBuffer);
/*!******************************************************************************************************************
* @brief  This api used to process the tranmission of Udp message in main function
* @param[in] ConIdx the DoIP connection Idx
* @param[in] HeaderType the header type
* @param[in] Param the parameter value
* @param[in] CloseSocketReq the request to close socket connection
* @return status of the request E_OK: request accepted E_NOT_OK: request not accepted
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_TxUdpTransmitDelayed
(
    DoIP_ConIdxType ConIdx,
    uint16 HeaderType,
    uint16 Param,
    boolean CloseSocketReq
);
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_UdpTxHandleEntriesVehicleAnnounceAndIdentRes
(
    DoIP_UdpTxCtrlIdxType UdpTxCtrlIdx,
    DoIP_ConIdxType ConIdx
);
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_UdpTxHandleOtherRes
(
    DoIP_UdpTxCtrlIdxType UdpTxCtrlIdx,
    DoIP_ConIdxType ConIdx,
    P2VAR(boolean, AUTOMATIC, DOIP_APPL_VAR) pRemoveList
);
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_UdpTxCloseSocket(DoIP_UdpTxCtrlIdxType UdpTxCtrlIdx);
/* #! tcp tx */

/* #! tcp queue */
/*!******************************************************************************************************************
* @brief  This api used to add the tcp transmit data to the tcp queue
* @param[in] TcpConIdx the tcp connection idx
* @param[in] HeaderType the header type
* @param[in] Param1 the first parameter
* @param[in] Param2 the second parameter
* @param[in] Param3 the third parameter
* @param[in] DataPtr the pointer to the buffer size
* @return status of the request BUFREQ_E_OK:request accepted BUFREQ_E_NOT_OK: request not accepted
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_TxTcpQueueAdd
(
    DoIP_TcpConIdxType TcpConIdx,
    uint16 HeaderType,
    uint16 Param1,
    uint16 Param2,
    uint8  Param3,
    P2VAR(uint8,AUTOMATIC,DOIP_APPL_DATA) DataPtr
);
/*!******************************************************************************************************************
* @brief  This api used to add the tcp general nack transmit data to the tcp queue
* @param[in] TxTcpQueueElementIdx the tx tcp queue element idx
* @param[in] TcpConIdx the tcp connection idx
* @param[in] NackCode the nack code
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_TxTcpQueueAddGenNack
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    uint8 NackCode
);
/*!******************************************************************************************************************
* @brief  This api used to add the tcp routing activation response tx data to the tcp queue
* @param[in] TxTcpQueueElementIdx the tx tcp queue element idx
* @param[in] TcpConIdx the tcp connection idx
* @param[in] TesterAddr the tester addr
* @param[in] AckCode the Ack code
* @param[in] TesterIdx the tester Idx
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_TxTcpQueueAddRoutingActivationRes
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    uint16 TesterAddr,
    uint8 AckCode,
    DoIP_TesterIdxType TesterIdx
);
/*!******************************************************************************************************************
* @brief  This api used to add the tcp alive check req tx data to the tcp queue
* @param[in] TxTcpQueueElementIdx the tx tcp queue element idx
* @param[in] TcpConIdx the tcp connection idx
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_TxTcpQueueAddAliveCheckReq
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx
);
/*!******************************************************************************************************************
* @brief  This api used to add the tcp diag req tx data to the tcp queue
* @param[in] TxTcpQueueElementIdx the tx tcp queue element idx
* @param[in] TcpConIdx the tcp connection idx
* @param[in] ChannelIdx the channel idx
* @param[in] Length the data length
* @param[in] DataPtr the pointer to the data buffer
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_TxTcpQueueAddDiagReq
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    DoIP_ChannelIdxType ChannelIdx,
    PduLengthType Length,
    P2VAR(uint8,AUTOMATIC,DOIP_APPL_DATA) DataPtr
);
/*!******************************************************************************************************************
* @brief  This api used to add the tcp diag ack tx data to the tcp queue
* @param[in] TxTcpQueueElementIdx the tx tcp queue element idx
* @param[in] TcpConIdx the tcp connection idx
* @param[in] EcuAddr the ECU address
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_TxTcpQueueAddDiagAck
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    uint16 EcuAddr
);
/*!******************************************************************************************************************
* @brief  This api used to add the tcp diag nack tx data to the tcp queue
* @param[in] TxTcpQueueElementIdx the tx tcp queue element idx
* @param[in] TcpConIdx the tcp connection idx
* @param[in] EcuAddr the ECU address
* @param[in] TesterAddr the tester address
* @param[in] NackCode the nack code
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_TxTcpQueueAddDiagNack
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    uint16 EcuAddr,
    uint16 TesterAddr,
    uint8 NackCode
);
/*!******************************************************************************************************************
* @brief  This api used to add the tcp oem tx data to the tcp queue
* @param[in] TxTcpQueueElementIdx the tx tcp queue element idx
* @param[in] TcpConIdx the tcp connection idx
* @param[in] OemHeaderType the oem header type
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_TxTcpQueueAddOem
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    uint16 OemHeaderType
);

/*!******************************************************************************************************************
* @brief  This api used to handle the copying of tcp tx header data to the queue 
* @param[in] TxTcpQueueElementIdx the tcp queue element idx
* @param[in] TcpConIdx the tcp conncetion idx
* @param[in] PduInfoPtr the pointer to the pdu info
* @param[out] AvailableDataPtr the pointer to available buffer
* @param[out] IsHeaderCopied the pointer to header copied status 
* @return status request BUFREQ_E_OK: request accepted BUFREQ_E_NOT_OK: request not accepted 
********************************************************************************************************************/
DOIP_LOCAL FUNC(BufReq_ReturnType, DOIP_CODE) DoIP_TxTcpQueueCopyHeader
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) AvailableDataPtr,
    P2VAR(boolean, AUTOMATIC, DOIP_APPL_VAR) IsHeaderCopied
);
/*!******************************************************************************************************************
* @brief  This api used to handle the copying of tcp tx data to the queue 
* @param[in] TxTcpQueueElementIdx the tcp queue element idx
* @param[in] TcpConIdx the tcp conncetion idx
* @param[in] PduInfoPtr the pointer to the pdu info
* @param[out] AvailableDataPtr the pointer to available buffer
* @param[in] IsHeaderCopied header copied status 
* @return status request BUFREQ_E_OK: request accepted BUFREQ_E_NOT_OK: request not accepted 
********************************************************************************************************************/
DOIP_LOCAL FUNC(BufReq_ReturnType, DOIP_CODE) DoIP_TxTcpQueueCopyData
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) AvailableDataPtr,
    boolean IsHeaderCopied
);
/*!******************************************************************************************************************
* @brief  This api used to handle the copying of tcp tx diag data to the queue 
* @param[in] TxTcpQueueElementIdx the tcp queue element idx
* @param[in] TcpConIdx the tcp conncetion idx
* @param[in] PduInfoPtr the pointer to the pdu info
* @param[out] AvailableDataPtr the pointer to available buffer
* @param[in] IsHeaderCopied header copied status 
* @return status request BUFREQ_E_OK: request accepted BUFREQ_E_NOT_OK: request not accepted 
********************************************************************************************************************/
DOIP_LOCAL FUNC(BufReq_ReturnType, DOIP_CODE) DoIP_TxTcpQueueCopyDiagReq
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) AvailableDataPtr,
    boolean IsHeaderCopied
);
/*!******************************************************************************************************************
* @brief  This api used to handle the copying of tcp If tx diag data to the queue 
* @param[in] TxTcpQueueElementIdx the tcp queue element idx
* @param[in] TcpConIdx the tcp conncetion idx
* @param[in] PduInfoPtr the pointer to the pdu info
* @param[out] AvailableDataPtr the pointer to available buffer
* @param[in] IsHeaderCopied header copied status 
* @return status request BUFREQ_E_OK: request accepted BUFREQ_E_NOT_OK: request not accepted 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_TxTcpQueueCopyDiagReqIf
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) AvailableDataPtr,
    boolean IsHeaderCopied
);
/*!******************************************************************************************************************
* @brief  This api used to handle the copying of tcp Tp tx diag data to the queue 
* @param[in] TxTcpQueueElementIdx the tcp queue element idx
* @param[in] TcpConIdx the tcp conncetion idx
* @param[in] PduInfoPtr the pointer to the pdu info
* @param[out] AvailableDataPtr the pointer to available buffer
* @param[in] IsHeaderCopied header copied status 
* @return status request BUFREQ_E_OK: request accepted BUFREQ_E_NOT_OK: request not accepted 
********************************************************************************************************************/
DOIP_LOCAL FUNC(BufReq_ReturnType, DOIP_CODE) DoIP_TxTcpQueueCopyDiagReqTp
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) AvailableDataPtr,
    boolean IsHeaderCopied
);
/*!******************************************************************************************************************
* @brief  This api used to handle the copying of tcp Tp tx diag ack to the queue 
* @param[in] TxTcpQueueElementIdx the tcp queue element idx
* @param[in] TcpConIdx the tcp conncetion idx
* @param[in] PduInfoPtr the pointer to the pdu info
* @param[out] AvailableDataPtr the pointer to available buffer
* @param[in] IsHeaderCopied header copied status 
* @return status request BUFREQ_E_OK: request accepted BUFREQ_E_NOT_OK: request not accepted 
********************************************************************************************************************/
DOIP_LOCAL FUNC(BufReq_ReturnType, DOIP_CODE) DoIP_TxTcpQueueCopyDiagAck
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) AvailableDataPtr,
    boolean IsHeaderCopied
);
#if (DOIP_OEM_PAYLOAD_TCP_BUFFER_SIZE > 0U)
/*!******************************************************************************************************************
* @brief  This api used to handle the copying of tcp Tp tx oem specific data to the queue 
* @param[in] TxTcpQueueElementIdx the tcp queue element idx
* @param[in] TcpConIdx the tcp conncetion idx
* @param[in] PduInfoPtr the pointer to the pdu info
* @param[out] AvailableDataPtr the pointer to available buffer
* @param[in] IsHeaderCopied header copied status 
* @return status request BUFREQ_E_OK: request accepted BUFREQ_E_NOT_OK: request not accepted 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_TxTcpQueueCopyOemSpecific
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) AvailableDataPtr,
    boolean IsHeaderCopied
);
#endif

#define DOIP_STOP_SEC_CODE
#include "MemMap.h"

/********************************************************************************************************************
*  #! PUBLIC FUNCTION IMPLEMENTATION                                                                                *
********************************************************************************************************************/
#define DOIP_START_SEC_CODE
#include "MemMap.h"
/* #! Udp transmit */
/********************************************************************************************************************
* @brief This api is used to process the udp transmit request
********************************************************************************************************************/
FUNC(Std_ReturnType, DOIP_CODE) DoIP_TxUdpTransmit
(
    DoIP_ConIdxType ConIdx,
    uint16 HeaderType,
    uint16 Param,
    boolean CloseSocketReq
)
{
    Std_ReturnType RetVal;
    /* Try to tranmis data immediately */
    RetVal = DoIP_TxUdpTransmitImmediately(ConIdx, HeaderType, Param, CloseSocketReq);
    /* if tx not successful then update in the queue */
    if (RetVal == E_NOT_OK )
    {
        RetVal = DoIP_TxUdpTransmitDelayed(ConIdx, HeaderType, Param, CloseSocketReq);
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief This api is used to process the udp delayed transmit 
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_TxUdpCtrlHandler(void)
{
    boolean RemoveUdpTx = FALSE;
    DoIP_ConIdxType ConIdx;
    DoIP_UdpTxCtrlIdxType UdpTxCtrlIdx;
    /* process delayed request */
    for(UdpTxCtrlIdx = 0u;UdpTxCtrlIdx < DoIP_CfgGetNumOfUdpTxCtrl();UdpTxCtrlIdx++)
    {
        ConIdx = DoIP_UdpTxCtrlGetConIdx(UdpTxCtrlIdx);
        if (ConIdx != DoIP_CfgGetNumOfConnection())
        {
            if (DoIP_ConCtrlGetSoConMode(ConIdx) == SOAD_SOCON_ONLINE)
            {
                if (DoIP_UdpTxCtrlGetTxHeaderType(UdpTxCtrlIdx) == DOIP_HEADER_TYPE_VEHICLE_ANNOUNCEMENT)
                {
                    /* Handle vehicle announcement */
                    DoIP_UdpTxHandleEntriesVehicleAnnounceAndIdentRes(UdpTxCtrlIdx,ConIdx);
                }
                else
                {
                    /* Handle other response */
                    DoIP_UdpTxHandleOtherRes(UdpTxCtrlIdx, ConIdx,&RemoveUdpTx);
                }
            }
            else
            {
                /* SoCon closed , so remove pending Udp tx */
                RemoveUdpTx = TRUE;
            }
            /* remove Udp tx */
            if (RemoveUdpTx == TRUE)
            {
                #if ( DOIP_OEM_PAYLOAD_TYPE_ENABLED == STD_ON )
                if (DoIP_UdpTxCtrlGetTxHeaderType(UdpTxCtrlIdx) == DOIP_HEADER_TYPE_OEM_SPECIFIC )
                {
                    DoIP_OemPayloadCtrlSetUdpBufferLength(0u);
                }
                #endif
                /* Close socket , remove tx */
                DoIP_UdpTxCloseSocket(UdpTxCtrlIdx);
                DoIP_UdpTxCtrlSetConIdx(UdpTxCtrlIdx, DoIP_CfgGetNumOfConnection());
            }
        }
    }
}
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_UdpTxHandleEntriesVehicleAnnounceAndIdentRes
(
    DoIP_UdpTxCtrlIdxType UdpTxCtrlIdx,
    DoIP_ConIdxType ConIdx
)
{   
    /* process vehicle announce delay timer */
    if (DoIP_UdpTxCtrlGetTxFirstParam(UdpTxCtrlIdx) > 0u)
    {
        DoIP_UdpTxCtrlDecTxFirstParam(UdpTxCtrlIdx);
        if (DoIP_UdpTxCtrlGetTxFirstParam(UdpTxCtrlIdx) == 0)
        {
            if (DoIP_TxUdpSingleTransmit(ConIdx,DOIP_HEADER_TYPE_VEHICLE_ANNOUNCEMENT,DOIP_UNUSED_PARAM) != E_OK)
            {
                /* retry if transmission failed */
                DoIP_UdpTxCtrlIncTxFirstParam(UdpTxCtrlIdx);
                DoIP_UdpTxCtrlDecTxRetryCount(UdpTxCtrlIdx);
                if (DoIP_UdpTxCtrlGetTxRetryCount(UdpTxCtrlIdx) == 0u)
                {
                    DoIP_UdpTxCtrlSetConIdx(UdpTxCtrlIdx,DoIP_CfgGetNumOfConnection());
                }
            }
            else
            {
                /* decrement repetition count */
                if (DoIP_UdpTxCtrlGetTxSecondParam(UdpTxCtrlIdx) > 0u)
                {
                    DoIP_UdpTxCtrlDecTxSecondParam(UdpTxCtrlIdx);
                    if (DoIP_UdpTxCtrlGetTxSecondParam(UdpTxCtrlIdx) > 0U)
                    {
                        /* reload announce interval timer for next vehicle announcement messages */
                        DoIP_UdpTxCtrlSetTxFirstParam(UdpTxCtrlIdx, DOIP_VEHICLE_ANNOUNCEMENT_INTERVAL);
                    }
                    else
                    {
                        /* Close socket , remove tx */
                        if (ConIdx < DoIP_CfgGetNumOfTcpUdpConnection())
                        {
                            DoIP_UdpTxCloseSocket(UdpTxCtrlIdx);
                        }
                        DoIP_UdpTxCtrlSetConIdx(UdpTxCtrlIdx,DoIP_CfgGetNumOfConnection());
                    }
                }
            }
        }
    }
}
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_UdpTxHandleOtherRes
(
    DoIP_UdpTxCtrlIdxType UdpTxCtrlIdx,
    DoIP_ConIdxType ConIdx,
    P2VAR(boolean, AUTOMATIC, DOIP_APPL_VAR) pRemoveList
)
{
    if (E_OK != DoIP_TxUdpSingleTransmit(ConIdx,DoIP_UdpTxCtrlGetTxHeaderType(UdpTxCtrlIdx),
                                        DoIP_UdpTxCtrlGetTxSecondParam(UdpTxCtrlIdx)))
    {
        if (DoIP_UdpTxCtrlGetTxRetryCount(UdpTxCtrlIdx) > 0)
        {
            DoIP_UdpTxCtrlDecTxRetryCount(UdpTxCtrlIdx);
            if (DoIP_UdpTxCtrlGetTxRetryCount(UdpTxCtrlIdx)==0U)
            {
                *pRemoveList = TRUE; 
            }
        }
    }
    else
    {
        *pRemoveList = TRUE;
    }
}
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_UdpTxCloseSocket(DoIP_UdpTxCtrlIdxType UdpTxCtrlIdx)
{
    DoIP_ConIdxType ConIdx;
    boolean CloseSocket=TRUE;
    DoIP_UdpTxCtrlIdxType LocalUdpTxCtrlIdx;
    /* process close socket */
    ConIdx = DoIP_UdpTxCtrlGetConIdx(UdpTxCtrlIdx);
    if (ConIdx != DoIP_CfgGetNumOfConnection() && (TRUE == DoIP_ConCtrlGetSoConCloseReq(ConIdx)))
    {
        /* check if no other pending request */
        for(LocalUdpTxCtrlIdx = 0u;LocalUdpTxCtrlIdx < DoIP_CfgGetNumOfUdpTxCtrl(); LocalUdpTxCtrlIdx++)
        {
            if ((LocalUdpTxCtrlIdx != UdpTxCtrlIdx) && 
                (DoIP_UdpTxCtrlGetConIdx(LocalUdpTxCtrlIdx) == DoIP_UdpTxCtrlGetConIdx(UdpTxCtrlIdx)))
            {
                CloseSocket = FALSE;
                break;
            }
        }
        /* if no other pending tx, then close the socket */
        if (CloseSocket == TRUE)
        {
            DoIP_SoConClose(ConIdx);
        }
    }
}
/* #! tcp tx */
/********************************************************************************************************************
* @brief  This api used to transmit the tcp data
********************************************************************************************************************/
FUNC(Std_ReturnType, DOIP_CODE) DoIP_TxTcpTransmit
(
    DoIP_TcpConIdxType TcpConIdx,
    uint16 HeaderType,
    uint16 Param1,
    uint16 Param2,
    uint8  Param3,
    P2VAR(uint8,AUTOMATIC,DOIP_APPL_DATA) DataPtr,
    boolean CloseSocketReq
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    
    DoIP_EnterCriticalSection();
    if ((DoIP_ConCtrlGetSoConMode(TcpConIdx) == SOAD_SOCON_ONLINE) && 
       (DoIP_ConCtrlGetSoConCloseReq(TcpConIdx) == FALSE))
    {
        /* update to Tx Queue */
        RetVal = DoIP_TxTcpQueueAdd(TcpConIdx, HeaderType, Param1, Param2, Param3, DataPtr);
        if (RetVal == E_OK)
        {
            if (CloseSocketReq == TRUE)
            {
                DoIP_ConCtrlSetSoConCloseReq(TcpConIdx,TRUE);
            }
        }
    }
    DoIP_ExitCriticalSection();
    
    if (RetVal == E_OK)
    {
        /* Start transmission of Tx queue. */
        DoIP_TxTcpQueueTransmitElement(TcpConIdx);
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief  This api used to handle the copying of tcp tx data to the queue 
********************************************************************************************************************/
FUNC(BufReq_ReturnType, DOIP_CODE) DoIP_TxTcpQueueCopy
(
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_CONST) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) AvailableDataPtr
)
{
    PduInfoType  *pMsgPduInfo;
    PduLengthType TxBytesCopied;
    PduLengthType HeaderBufferLength;
    boolean IsHeaderCopied = FALSE;
    BufReq_ReturnType RetVal = BUFREQ_E_NOT_OK;
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx;
    
    TxBytesCopied = DoIP_TcpConCtrlGetTxBytesCopied(TcpConIdx);
    TxTcpQueueElementIdx = DoIP_TcpConCtrlGetTxTcpQueueElementIdx(TcpConIdx);
    HeaderBufferLength = DoIP_TxTcpQueueElementCtrlGetHeaderBufferLength(TxTcpQueueElementIdx);
    pMsgPduInfo = &DoIP_TxTcpQueueElementCtrlGetTxTcpPduInfo(TxTcpQueueElementIdx);
    
    DoIP_EnterCriticalSection();
    
    if ((DoIP_TcpConCtrlGetTxTpSessionActive(TcpConIdx) == TRUE) &&
        (DoIP_TcpConCtrlGetTxTpCancelReq(TcpConIdx) == FALSE))
    {
        if (((PduInfoPtr->SduLength != 0U) && 
            (PduInfoPtr->SduLength <= DoIP_TcpConCtrlGetTxLastBufferSize(TcpConIdx))) || 
            (PduInfoPtr->SduLength == 0U))
        {
            if (DoIP_TcpConCtrlGetRoutingActivationState(TcpConIdx) == DOIP_ROUTING_ACTIVATION_STATE_ACTIVATED)
            {
                DoIP_TcpConCtrlSetInactiveTimeCount(TcpConIdx,0U);
            }
            /* copy header */
            if (TxBytesCopied < HeaderBufferLength)
            {
                RetVal = DoIP_TxTcpQueueCopyHeader(TxTcpQueueElementIdx,TcpConIdx,PduInfoPtr,
                                                        AvailableDataPtr,&IsHeaderCopied);
            }
            else
            {
                RetVal = BUFREQ_OK;
            }
            /* copy data */
            if ((RetVal == BUFREQ_OK) && 
                (HeaderBufferLength <= TxBytesCopied) && (HeaderBufferLength <= pMsgPduInfo->SduLength))
            {
                RetVal = DoIP_TxTcpQueueCopyData(TxTcpQueueElementIdx,TcpConIdx,PduInfoPtr,
                                                                AvailableDataPtr,IsHeaderCopied);
                RetVal = BUFREQ_OK;
            }
        }
    }
    DoIP_ExitCriticalSection();
    return RetVal;
}
/********************************************************************************************************************
* @brief  This api used to remove the tx element from the tcp queue
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_TxTcpQueueRemoveElement
(
    DoIP_TcpConIdxType TcpConIdx,
    Std_ReturnType Result
)
{
    DoIP_ChannelIdxType ChannelIdx = DoIP_CfgGetNumOfChannel();
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx;
   
    DoIP_EnterCriticalSection();
    if (DoIP_TcpConCtrlGetTxTcpCtrlQueueLevel(TcpConIdx) > 0u)
    {
        TxTcpQueueElementIdx = DoIP_TcpConCtrlGetTxTcpQueueElementIdx(TcpConIdx);
        ChannelIdx = DoIP_TxTcpQueueElementCtrlGetChannelIdx(TxTcpQueueElementIdx);
        /* Reset header buffer length */
        DoIP_TxTcpQueueElementCtrlSetHeaderBufferLength(TxTcpQueueElementIdx,0u);
        /* update queue */
        DoIP_TcpConCtrlDecTxTcpCtrlQueueLevel(TcpConIdx);
        DoIP_TcpConCtrlIncTxTcpQueueElementIdx(TcpConIdx);
        if (DoIP_TcpConCtrlGetTxTcpQueueElementIdx(TcpConIdx) > DoIP_TcpConCfgGetTcpTxQueueElementSize(TcpConIdx))
        {
            /* do wrap around */
            DoIP_TcpConCtrlSetTxTcpQueueElementIdx(TcpConIdx,0u);
        }
        #if (DOIP_OEM_PAYLOAD_TCP_BUFFER_SIZE > 0U)
        if (DoIP_OemPayloadCtrlGetTcpBufferConIdx() == TcpConIdx)
        {
            /* Reset status */
            DoIP_OemPayloadCtrlSetTcpBufferConIdx(DoIP_CfgGetNumOfConnection());
            DoIP_OemPayloadCtrlSetTcpBufferLength(0u);
            DoIP_OemPayloadCtrlSetTcpBufferReqTx(FALSE);
        }
        #endif
        /* Reset tp session */
        DoIP_TcpConCtrlSetTxTpSessionActive(TcpConIdx,FALSE);
        DoIP_TcpConCtrlSetTxBytesCopied(TcpConIdx,0u);
        if (ChannelIdx != DoIP_CfgGetNumOfChannel())
        {
            /* Reset channel status */
            DoIP_ChannelCtrlCfgSetTxLength(ChannelIdx,0u);
            DoIP_TxTcpQueueElementCtrlSetChannelIdx(TxTcpQueueElementIdx,DoIP_CfgGetNumOfChannel());
        }
    }
    /* Notify upper layer about the result */
    if (ChannelIdx != DoIP_CfgGetNumOfChannel())
    {
        if (DoIP_ChannelCfgGetApiType(ChannelIdx) == DOIP_API_TYPE_IF)
        {
            PduR_DoIPIfTxConfirmation(DoIP_ChannelCfgGetTxConfId(ChannelIdx));
        }
        else
        {
            PduR_DoIPTpTxConfirmation(DoIP_ChannelCfgGetTxConfId(ChannelIdx), Result);
        }
    }
}
/********************************************************************************************************************
* @brief  This api used to handle the transmission of queue element 
* @param[in] TcpConIdx the tcp conncetion idx
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_TxTcpQueueTransmitElement(DoIP_TcpConIdxType TcpConIdx)
{
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx;
    PduInfoType  *pMsgPduInfo;
    PduInfoType TxPduInfo;
    boolean DoTransmit=FALSE;
    
    DoIP_EnterCriticalSection();
    if (DoIP_TcpConCtrlGetTxTpSessionActive(TcpConIdx) == FALSE)
    {
        TxTcpQueueElementIdx = DoIP_TcpConCtrlGetTxTcpQueueElementIdx(TcpConIdx);
        pMsgPduInfo = &DoIP_TxTcpQueueElementCtrlGetTxTcpPduInfo(TxTcpQueueElementIdx);
        /* lock tp session */
        DoIP_TcpConCtrlSetTxTpSessionActive(TcpConIdx,TRUE);
        if (DoIP_TcpConCtrlGetTxTcpCtrlQueueLevel(TcpConIdx) > 0u)
        {
            /* update info */
            TxPduInfo.SduDataPtr = pMsgPduInfo->SduDataPtr;
            TxPduInfo.SduLength = pMsgPduInfo->SduLength;
            DoTransmit = TRUE;
        }
        else
        {
            /* release tp session */
            DoIP_TcpConCtrlSetTxTpSessionActive(TcpConIdx,FALSE);
        }
    }
    DoIP_ExitCriticalSection();
    /* trigger transmit */
    if (DoTransmit == TRUE)
    {
        if (SoAd_TpTransmit(DoIP_ConCfgGetTxPduId(TcpConIdx), &TxPduInfo) != E_OK)
        {
            /* release tp session */
            DoIP_TcpConCtrlSetTxTpSessionActive(TcpConIdx,FALSE);
        }
    }
}
/********************************************************************************************************************
* @brief  This api used to handle the tcp queue pending transmit
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_TxTcpQueueHandleTransmit(void)
{
    DoIP_TcpConIdxType TcpConIdx;
    
    for (TcpConIdx=0u;TcpConIdx < DoIP_CfgGetNumOfTcpConnection();TcpConIdx++)
    {
        if (DoIP_ConCtrlGetSoConMode(TcpConIdx) == SOAD_SOCON_ONLINE)
        {
            if (DoIP_TcpConCtrlGetTxTcpCtrlQueueLevel(TcpConIdx) > 0u)
            {
                DoIP_TxTcpQueueTransmitElement(TcpConIdx);
            }
        }
    }
}
/********************************************************************************************************************
* @brief  This api used to complete the tcp transmit data 
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_TxTcpFinishTransmit(DoIP_TcpConIdxType TcpConIdx)
{
    if (DoIP_TcpConCtrlGetTxTpHeaderType(TcpConIdx) != DOIP_HEADER_TYPE_INVALID)
    {
        /* transmit pending bytes */
        (void)DoIP_TxTcpTransmit(TcpConIdx,DoIP_TcpConCtrlGetTxTpHeaderType(TcpConIdx),
                DoIP_TcpConCtrlGetTxTpFirstParam(TcpConIdx),DoIP_TcpConCtrlGetTxTpSecondParam(TcpConIdx),
                DoIP_TcpConCtrlGetTxTpThirdParam(TcpConIdx),NULL_PTR,DoIP_TcpConCtrlGetTxTpCloseSocketReq(TcpConIdx));
        DoIP_TcpConCtrlSetTxTpHeaderType(TcpConIdx,DOIP_HEADER_TYPE_INVALID);
    }
}
/********************************************************************************************************************
* @brief  This api used to prepare tcp data for transmission
********************************************************************************************************************/
FUNC(void, DOIP_CODE) DoIP_TxTcpPrepareTransmit
(
    DoIP_TcpConIdxType TcpConIdx,
    uint16 HeaderType,
    uint16 Param1,
    uint16 Param2,
    uint8  Param3,
    boolean CloseSocketReq
)
{
    if(DoIP_TcpConCtrlGetTxTpHeaderType(TcpConIdx) == DOIP_HEADER_TYPE_INVALID)
    {
        DoIP_TcpConCtrlSetTxTpHeaderType(TcpConIdx,HeaderType);
        DoIP_TcpConCtrlSetTxTpFirstParam(TcpConIdx,Param1);
        DoIP_TcpConCtrlSetTxTpSecondParam(TcpConIdx,Param2);
        DoIP_TcpConCtrlSetTxTpThirdParam(TcpConIdx,Param3);
        DoIP_TcpConCtrlSetTxTpCloseSocketReq(TcpConIdx,CloseSocketReq);
    }
}
/********************************************************************************************************************
*  #! PRIVATE FUNCTION IMPLEMENTATION                                                                               *
********************************************************************************************************************/
/********************************************************************************************************************
* @brief This api is used to process the udp transmit request immediately
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_TxUdpTransmitImmediately
(
    DoIP_ConIdxType ConIdx,
    uint16 HeaderType,
    uint16 Param,
    boolean CloseSocketReq
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    boolean ResPending = FALSE;
    DoIP_UdpTxCtrlIdxType UdpTxCtrlIdx;
    
    /* Send msg immediately except Vehicle announcement */
    if(HeaderType != DOIP_HEADER_TYPE_VEHICLE_ANNOUNCEMENT)
    {
        RetVal = DoIP_TxUdpSingleTransmit(ConIdx, HeaderType, Param);
    }

    if (RetVal == E_OK)
    {
#if ( DOIP_OEM_PAYLOAD_TYPE_ENABLED == STD_ON )
        /* Clear Udp buffer length if the Header type is OEM specific */
        if (HeaderType == DOIP_HEADER_TYPE_OEM_SPECIFIC)
        {
            DoIP_OemPayloadCtrlSetUdpBufferLength(0U);
        }
#endif
        /* if msg transmit success , then check for the pending response */
        for (UdpTxCtrlIdx = 0U;UdpTxCtrlIdx < DoIP_CfgGetNumOfUdpConnection();UdpTxCtrlIdx++)
        {
            if (ConIdx == DoIP_UdpTxCtrlGetConIdx(UdpTxCtrlIdx))
            {
                ResPending = TRUE;
                break;
            }
        }
        
        if (CloseSocketReq == TRUE)
        {
            if(ResPending == TRUE)
            {
                /* set the close req to process in main function */
                DoIP_ConCtrlSetSoConCloseReq(ConIdx,CloseSocketReq);
            }
            else
            {
                /* request to close the SoCon */
                DoIP_SoConClose(ConIdx);
            }
        }
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief This api is used to process the udp transmit request 
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_TxUdpSingleTransmit
(
    DoIP_ConIdxType ConIdx,
    uint16 HeaderType,
    uint16 Param
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    switch(HeaderType)
    {
        /*! Handle vehicle Announcement transmission */
        case DOIP_HEADER_TYPE_VEHICLE_ANNOUNCEMENT:
            RetVal = DoIP_TxUdpSingleTransmitVehicleAnnounceAndIdentRes(ConIdx);
            break;
        case DOIP_HEADER_TYPE_GEN_NACK:
            RetVal = DoIP_TxUdpSingleTransmitGenNack(ConIdx, HeaderType, (uint8)Param);
            break;
        case DOIP_HEADER_TYPE_DIAG_POWER_MODE_INFO_RES:
            RetVal = DoIP_TxUdpSingleTransmitDiagPowerModeInfoRes(ConIdx, (uint8)Param);
            break;
        case DOIP_HEADER_TYPE_ENTITY_STATE_RES:
            RetVal = DoIP_TxUdpSingleTransmitEntityStateRes(ConIdx);
            break;
        #if ( DOIP_OEM_PAYLOAD_TYPE_ENABLED == STD_ON )
        case DOIP_HEADER_TYPE_OEM_SPECIFIC:
        {
            RetVal = DoIP_TxUdpSingleTransmitOemSpecific(ConIdx, Param);
            break;
        }
        #endif
        default:
            break;
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief This api is used to process the udp transmit vehicle announcement and identification response 
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_TxUdpSingleTransmitVehicleAnnounceAndIdentRes(DoIP_ConIdxType ConIdx)
{
    PduInfoType PduInfo;
    PduLengthType Offset;
    Std_ReturnType RetVal = E_OK;
    #if (DOIP_USE_VEHICLE_IDENTIFICATION_SYNC_STATUS == STD_ON)
    Std_ReturnType VinStatus = E_OK;
    #endif
    uint8 Payload[DOIP_GENERIC_HEADER_LENGTH+DOIP_ACK_VEHICLE_IDENT_LENGTH];
    
    /* update generic header */
    DoIP_UpdateGenericHeader(DOIP_HEADER_TYPE_VEHICLE_ANNOUNCEMENT,DOIP_ACK_VEHICLE_IDENT_LENGTH,&Payload[0]);
    /* update VIN */
    Offset = DOIP_GENERIC_HEADER_LENGTH;
    #if (DOIP_USE_VEHICLE_IDENTIFICATION_SYNC_STATUS == STD_ON)
    VinStatus = DoIP_UpdateVin(&Payload[Offset]);
    #else
    (void)DoIP_UpdateVin(&Payload[Offset]);
    #endif
    Offset += DOIP_VIN_LENGTH;
    /* update addr */
    Payload[Offset] = (uint8)(DOIP_LOGICAL_ADDRESS >> 8u);
    Payload[Offset+1u] = (uint8)(DOIP_LOGICAL_ADDRESS);
    Offset += DOIP_LOGICAL_ADDRESS_LENGTH;
    /* Update EID */
    RetVal |= DoIP_UpdateEid(&Payload[Offset],ConIdx);
    Offset += DOIP_EID_LENGTH;
    /* Update GID */
    RetVal |= DoIP_UpdateGid(&Payload[Offset],ConIdx);
    Offset += DOIP_GID_LENGTH;
    /* Update further action bytes */
    DoIP_UpdateFurtherAction(&Payload[Offset]);
#if (DOIP_USE_VEHICLE_IDENTIFICATION_SYNC_STATUS == STD_ON)
    Offset++;
    if (VinStatus !=E_OK) /* && (DoIP_GidInSync != TRUE) */
    {
        /* VIN/GID sync not succcessful */
        Payload[Offset] = 0x10u;
    }
    else
    {
        /* VIN/GID sync succcessful */
        Payload[Offset] = 0x10u;
    }
#endif
    PduInfo.SduLength = DOIP_GENERIC_HEADER_LENGTH+DOIP_ACK_VEHICLE_IDENT_LENGTH;
    PduInfo.SduDataPtr = &Payload[0];
#if (DOIP_USE_MAC_ADDRESS_FOR_IDENTIFICATION == STD_ON)
    if (RetVal == E_OK)
#endif
    {
        /* Request to transmit the data */
        RetVal |= SoAd_IfTransmit(DoIP_ConCfgGetTxPduId(ConIdx),&PduInfo);;
    }        
    return RetVal;
}
/********************************************************************************************************************
* @brief This api is used to process the udp transmit general Negative Ack response 
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_TxUdpSingleTransmitGenNack
(
    DoIP_ConIdxType ConIdx,
    uint16 HeaderType,
    uint8 NackCode
)
{
    Std_ReturnType RetVal=E_NOT_OK;
    PduInfoType PduInfo;
    uint8 Payload[9u]={0};
    /* update header */
    DoIP_UpdateGenericHeader(HeaderType,1u,&Payload[0]);
    /*update Nack code */
    Payload[8] = NackCode;
    PduInfo.SduLength = DOIP_GENERIC_HEADER_LENGTH;
    PduInfo.SduDataPtr = &Payload[0];
    /* Request to transmit the data*/
    RetVal = SoAd_IfTransmit(DoIP_ConCfgGetTxPduId(ConIdx),&PduInfo);
    return RetVal;
}
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_TxUdpSingleTransmitDiagPowerModeInfoRes
(
    DoIP_ConIdxType ConIdx,
    uint8 DiagPowerMode
)
{
    Std_ReturnType RetVal;
    PduInfoType PduInfo;
    uint8 Payload[9u] = {0u};
    /* update header */
    DoIP_UpdateGenericHeader(DOIP_HEADER_TYPE_DIAG_POWER_MODE_INFO_RES,1u,&Payload[0]);
    /* update power mode */
    Payload[8] = DiagPowerMode;
    PduInfo.SduLength  = DOIP_GENERIC_HEADER_LENGTH + 1u;
    PduInfo.SduDataPtr = &Payload[0];
    /* Request to transmit the data*/
    RetVal = SoAd_IfTransmit(DoIP_ConCfgGetTxPduId(ConIdx),&PduInfo);
    return RetVal;
}
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_TxUdpSingleTransmitEntityStateRes(DoIP_ConIdxType ConIdx)
{
    Std_ReturnType RetVal;
    PduInfoType PduInfo;
    DoIP_ConIdxType LocalConIdx;
# if ( DOIP_ENTITY_STATUS_MAX_BYTE_FIELD_USE == STD_ON )
    uint8 Payload[15u] = { 0u };
# else
    uint8 data[11u] = { 0u };
# endif 
    /* update header */
    DoIP_UpdateGenericHeader(DOIP_HEADER_TYPE_ENTITY_STATE_RES,DOIP_ACK_ENTITY_STATE_LENGTH,&Payload[0]);
    /* update payload */
    Payload[8] = DOIP_NODE_TYPE;
    /* TODO: remove n + 1 socket of each addr */
    Payload[9] = DoIP_CfgGetNumOfTcpConnection() - DoIP_CfgGetNumOfLocalAddr();
    Payload[10] = 0u;
    /* update open TCP_DATA socket (of all addr). */
    for (LocalConIdx = 0u; LocalConIdx < DoIP_CfgGetNumOfTcpUdpConnection();LocalConIdx++ )
    {
        if (DoIP_ConCtrlGetSoConMode(LocalConIdx) == SOAD_SOCON_ONLINE)
        {
            Payload[10]++;
        }
    }
    # if ( DOIP_ENTITY_STATUS_MAX_BYTE_FIELD_USE == STD_ON )
    /* update max data size to message buffer */
    Payload[10] = (uint8)(DOIP_MAX_REQUEST_BYTES >>24u);
    Payload[11] = (uint8)(DOIP_MAX_REQUEST_BYTES >>16u);
    Payload[12] = (uint8)(DOIP_MAX_REQUEST_BYTES >>8u);
    Payload[13] = (uint8)(DOIP_MAX_REQUEST_BYTES);
    # endif
    PduInfo.SduLength  = DOIP_GENERIC_HEADER_LENGTH + DOIP_ACK_ENTITY_STATE_LENGTH;
    PduInfo.SduDataPtr = &Payload[0];
    /* Request to transmit the data*/
    RetVal = SoAd_IfTransmit(DoIP_ConCfgGetTxPduId(ConIdx),&PduInfo);
    return RetVal;
}
#if ( DOIP_OEM_PAYLOAD_TYPE_ENABLED == STD_ON )
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_TxUdpSingleTransmitOemSpecific(DoIP_ConIdxType ConIdx,uint16 HdrTypeOem)
{
    Std_ReturnType RetVal;
    PduInfoType PduInfo;
    /* update header */
    DoIP_UpdateGenericHeader(HdrTypeOem,
                            DoIP_OemPayloadCtrlGetUdpBufferLength()-DOIP_GENERIC_HEADER_LENGTH,
                            &DoIP_OemPayloadUdpBuffer[0]);
    PduInfo.SduLength  = DoIP_OemPayloadCtrlGetUdpBufferLength();
    PduInfo.SduDataPtr = &DoIP_OemPayloadUdpBuffer[0];
    /* Request to transmit the data*/
    RetVal = SoAd_IfTransmit(DoIP_ConCfgGetTxPduId(ConIdx),&PduInfo);
    return RetVal;
}
#endif
/********************************************************************************************************************
* @brief This api is used to update the generic header to the buffer
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_UpdateGenericHeader
(
    uint16 HeaderType,
    uint32 HeaderLength,
    P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) pBuffer
)
{
    pBuffer[0] = DOIP_PROTOCOL_VERSION_2012;
    pBuffer[1] = DOIP_PROTOCOL_INV_VERSION_2012;
    pBuffer[2] = (uint8)(HeaderType >> 8u);
    pBuffer[3] = (uint8)(HeaderType);
    pBuffer[4] = (uint8)(HeaderLength >> 24u);
    pBuffer[5] = (uint8)(HeaderLength >> 16u);
    pBuffer[6] = (uint8)(HeaderLength >> 8u);
    pBuffer[7] = (uint8)(HeaderLength);
}
/********************************************************************************************************************
* @brief This api is used to update the VIN to the buffer
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_UpdateVin(P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) pBuffer) 
{
    Std_ReturnType RetVal=E_NOT_OK;
    uint8 VinBuffer[DOIP_VIN_LENGTH] = {0U};
    /*! Get Vin from app */
    if(DoIP_CfgGetUserGetVinCallbackFn(&VinBuffer[0U]) == E_OK)
    {
        DoIP_UtilMemCopy(pBuffer,&VinBuffer[0],DOIP_VIN_LENGTH);
        RetVal = E_OK;
    }
    else
    {
        /* copy invalid pattern */
        DoIP_UtilMemSet(pBuffer,DOIP_VIN_INVALIDITY_PATTERN,DOIP_VIN_LENGTH);
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief This api is used to update the EID to the buffer
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_UpdateEid
(
    P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) pBuffer,
    DoIP_ConIdxType ConIdx
)
{
    Std_ReturnType RetVal = E_OK;
#if (DOIP_USE_MAC_ADDRESS_FOR_IDENTIFICATION == STD_ON)
    uint8 PhysAddrBuffer[DOIP_PHYS_ADDR_LENGTH];
#endif 

#if (DOIP_USE_MAC_ADDRESS_FOR_IDENTIFICATION == STD_ON )
    if(SoAd_GetPhysAddr(DoIP_ConCtrlGetSoConIdx(ConIdx),&PhysAddrBuffer[0]) == E_OK)
    {
        /* Copy mac address to target buffer . */
        DoIP_UtilMemCopy(pBuffer,&PhysAddrBuffer[0],DOIP_PHYS_ADDR_LENGTH);
    }
    else
    {
        RetVal = E_NOT_OK;
    }
#else
    DoIP_UtilMemCopy(pBuffer,&DoIP_CfgEid[0],DOIP_EID_LENGTH);
    DOIP_DUMMY_STATEMENT(ConIdx);
#endif
    return RetVal;
}
/********************************************************************************************************************
* @brief This api is used to update the GID to the buffer
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_UpdateGid
(
    P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) pBuffer,
    DoIP_ConIdxType ConIdx
)
{
    Std_ReturnType RetVal = E_OK;
#if ((DOIP_VIN_GID_MASTER == STD_OFF) || (DOIP_USE_EID_AS_GID == STD_OFF))
#if (DOIP_GID_VALUE_CONFIGURED == STD_OFF)
    uint8 GidBuffer[DOIP_GID_LENGTH] = {0U};
#endif
#endif

#if (DOIP_VIN_GID_MASTER == STD_ON) && (DOIP_USE_EID_AS_GID == STD_ON)
    RetVal = DoIP_UpdateEid(pBuffer,ConIdx);
#else
    #if (DOIP_GID_VALUE_CONFIGURED == STD_ON)
    /* update value from configuration */
    DoIP_UtilMemCopy(pBuffer,&DoIP_CfgGid[0],DOIP_GID_LENGTH);
    #else
    if(DoIP_CfgGetUserGetGidCallbackFn(&GidBuffer[0]) == E_OK)
    {
        /* Copy GID to target buffer */
        DoIP_UtilMemCopy(pBuffer,&GidBuffer[0],DOIP_GID_LENGTH);
    }
    else
    {
        DoIP_UtilMemSet(pBuffer,DOIP_GID_INVALIDITY_PATTERN,DOIP_GID_LENGTH);
    }
    #endif
    DOIP_DUMMY_STATEMENT(ConIdx);
#endif
    return RetVal;
}
/********************************************************************************************************************
* @brief This api is used to update the further action bytes to the buffer
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_UpdateFurtherAction(P2VAR(uint8, AUTOMATIC, DOIP_APPL_VAR) pBuffer)
{
    uint8 FurtherActionVal = 0U;
    DoIP_TesterIdxType TesterIdx;
    DoIP_RoutingActivationIdxType RoutingActivationIdx;
    
    #if (DOIP_FURTHER_ACTION_BYTE_CALLBACK_SUPPORT == STD_ON)
    if (DoIP_CfgGetUserFurtherActionByteCallbackFn((DoIP_FurtherActionByteType *)&FurtherActionVal) != E_OK)
    #endif
    {
        FurtherActionVal = 0x00u; /* No further action required */
        for(TesterIdx=0U; TesterIdx < DoIP_CfgGetNumOfTester() ; TesterIdx++)
        {
            /* If routing activation required is configured for Tester , check the routing activation completed */
            if (DoIP_TesterCfgGetIsRoutingActivationRequired(TesterIdx) == TRUE)
            {
                if (DoIP_TesterCtrlGetTcpConIdx(TesterIdx) == DoIP_CfgGetNumOfTcpConnection())
                {
                    /* Routing activation required . */
                    FurtherActionVal = 0x10u; 
                }
                else
                {
                    RoutingActivationIdx = DoIP_TesterCfgGetRoutingActivationIdx(TesterIdx);
                    if(DoIP_RoutingActivationCfgGetActivationNumber(RoutingActivationIdx) != 0xE0u)
                    {
                        /* Routing activation required */
                        FurtherActionVal = 0x10u; 
                    }
                }
                if (FurtherActionVal == 0x10u)
                {
                    break;
                }
            }
        }
    }
    /* update further action value */
    *pBuffer = FurtherActionVal;
}
/********************************************************************************************************************
* @brief  This api used to process the tranmission of Udp message in main function
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_TxUdpTransmitDelayed
(
    DoIP_ConIdxType ConIdx,
    uint16 HeaderType,
    uint16 Param,
    boolean CloseSocketReq
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    DoIP_UdpTxCtrlIdxType UdpTxCtrlIdx;

    for(UdpTxCtrlIdx = 0u;UdpTxCtrlIdx<DoIP_CfgGetNumOfUdpTxCtrl();UdpTxCtrlIdx++)
    {
        /* check for tx ctrl*/
        if (DoIP_UdpTxCtrlGetConIdx(UdpTxCtrlIdx) == DoIP_CfgGetNumOfConnection())
        {
            /* Update the param to process in main function */
            DoIP_UdpTxCtrlSetConIdx(UdpTxCtrlIdx,ConIdx);
            DoIP_UdpTxCtrlSetTxHeaderType(UdpTxCtrlIdx,HeaderType);
            DoIP_UdpTxCtrlSetTxRetryCount(UdpTxCtrlIdx,DOIP_UDP_MAX_RETRY_COUNT);
            if (HeaderType == DOIP_HEADER_TYPE_VEHICLE_ANNOUNCEMENT)
            {
                /* Update wait timer value for the vehicle announcement header */ 
                DoIP_UdpTxCtrlSetTxFirstParam(UdpTxCtrlIdx,DOIP_INITIAL_VEHICLE_ANNOUNCEMENT_TIME);
            }
            DoIP_UdpTxCtrlSetTxSecondParam(UdpTxCtrlIdx,Param);
            /* update close requeset */
            if (CloseSocketReq == TRUE)
            {
                DoIP_ConCtrlSetSoConCloseReq(ConIdx,TRUE);
            }
            RetVal = E_OK;
            break;
        }
    }
    return RetVal;
}
/* #! tcp tx */
/* #! tcp queue */
/********************************************************************************************************************
* @brief  This api used to add the tcp transmit data to the tcp queue
********************************************************************************************************************/
DOIP_LOCAL FUNC(Std_ReturnType, DOIP_CODE) DoIP_TxTcpQueueAdd
(
    DoIP_TcpConIdxType TcpConIdx,
    uint16 HeaderType,
    uint16 Param1,
    uint16 Param2,
    uint8  Param3,
    P2VAR(uint8,AUTOMATIC,DOIP_APPL_DATA) DataPtr
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    DoIP_TxTcpQueueElementIdxType TcpTxQueueElementIdx;
    DoIP_TcpTxQueueIdxType TxTcpCtrlQueueLevel;
    
    TcpTxQueueElementIdx = DoIP_TcpConCtrlGetTxTcpQueueElementIdx(TcpConIdx);
    TxTcpCtrlQueueLevel = DoIP_TcpConCtrlGetTxTcpCtrlQueueLevel(TcpConIdx);
    
    if (TxTcpCtrlQueueLevel < DoIP_TcpConCfgGetTcpTxQueueElementSize(TcpConIdx))
    {
        /* Handle wrap around */
        if ((TcpTxQueueElementIdx+TxTcpCtrlQueueLevel) >= DoIP_TcpConCfgGetTcpTxQueueElementSize(TcpConIdx))
        {
            TcpTxQueueElementIdx = (TxTcpCtrlQueueLevel-
                                (DoIP_TcpConCfgGetTcpTxQueueElementSize(TcpConIdx)-TcpTxQueueElementIdx));
        }
        else
        {
            TcpTxQueueElementIdx += TxTcpCtrlQueueLevel;
        }
        
        /* process header type */
        switch(HeaderType)
        {
            case DOIP_HEADER_TYPE_GEN_NACK:
                DoIP_TxTcpQueueAddGenNack(TcpTxQueueElementIdx, TcpConIdx, (uint8)Param1);
                break;
            case DOIP_HEADER_TYPE_ROUT_ACTIV_RES:
                DoIP_TxTcpQueueAddRoutingActivationRes(TcpTxQueueElementIdx, TcpConIdx, Param1, (uint8)Param2, Param3);
                break;
            case DOIP_HEADER_TYPE_ALIVE_CHECK_REQ:
                DoIP_TxTcpQueueAddAliveCheckReq(TcpTxQueueElementIdx, TcpConIdx);
                break;
            case DOIP_HEADER_TYPE_DIAG_REQ:
                DoIP_TxTcpQueueAddDiagReq(TcpTxQueueElementIdx,TcpConIdx,(DoIP_ChannelIdxType)Param1,(PduLengthType)Param2, DataPtr); 
                break;
            case DOIP_HEADER_TYPE_DIAG_ACK:
                DoIP_TxTcpQueueAddDiagAck(TcpTxQueueElementIdx, TcpConIdx, Param1);
                break;
            case DOIP_HEADER_TYPE_DIAG_NACK:
                DoIP_TxTcpQueueAddDiagNack(TcpTxQueueElementIdx, TcpConIdx, Param1, Param2, Param3);
                break;
            #if ( DOIP_OEM_PAYLOAD_TYPE_ENABLED == STD_ON )
            case DOIP_HEADER_TYPE_OEM_SPECIFIC:
                DoIP_TxTcpQueueAddOem(TcpTxQueueElementIdx, TcpConIdx, Param1);
                break;
            #endif 
            default:
                break;
        }
        /* Increment queue level */
        DoIP_TcpConCtrlSetTxTcpCtrlQueueLevel(TcpConIdx,TxTcpCtrlQueueLevel+1u);
        RetVal = E_OK;
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief  This api used to add the tcp general nack transmit data to the tcp queue
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_TxTcpQueueAddGenNack
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    uint8 NackCode
)
{
    uint8 * pTxHeaderBuffer;
    
    pTxHeaderBuffer = &DoIP_TxHeaderBuffer[DoIP_TcpConCfgGetTxHeaderBufferStartIdx(TcpConIdx)];
    /* update generic header */
    DoIP_UpdateGenericHeader(DOIP_HEADER_TYPE_GEN_NACK,DOIP_GEN_HDR_NACK_CODE_LENGTH,pTxHeaderBuffer);
    /* update NACK code */
    pTxHeaderBuffer[DOIP_GENERIC_HEADER_LENGTH] = NackCode;
    /* Update transmit message struct */
    DoIP_TxTcpQueueElementCtrlSetHeaderBufferLength(TxTcpQueueElementIdx,
                                        (DOIP_GENERIC_HEADER_LENGTH + DOIP_GEN_HDR_NACK_CODE_LENGTH));
    DoIP_TxTcpQueueElementCtrlSetTxTcpPduInfoLength(TxTcpQueueElementIdx,
                                        (DOIP_GENERIC_HEADER_LENGTH + DOIP_GEN_HDR_NACK_CODE_LENGTH));
    DoIP_TxTcpQueueElementCtrlSetTxTcpPduInfoSduDataPtr(TxTcpQueueElementIdx,pTxHeaderBuffer);
}
/********************************************************************************************************************
* @brief  This api used to add the tcp routing activation response tx data to the tcp queue
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_TxTcpQueueAddRoutingActivationRes
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    uint16 TesterAddr,
    uint8 AckCode,
    DoIP_TesterIdxType TesterIdx
)
{
    uint8 * pTxHeaderBuffer;
    PduLengthType BufferIdx;
    DoIP_RoutingActivationIdxType RoutingActivationIdx;
    
    BufferIdx = DOIP_GENERIC_HEADER_LENGTH;
    RoutingActivationIdx = DoIP_TcpConCtrlGetRoutingActivationIdx(TcpConIdx);    
    pTxHeaderBuffer = &DoIP_TxHeaderBuffer[DoIP_TcpConCfgGetTxHeaderBufferStartIdx(TcpConIdx)];
    /* update Tester address */
    pTxHeaderBuffer[BufferIdx] = (uint8)(TesterAddr >> 8u);
    pTxHeaderBuffer[BufferIdx+1u] = (uint8)TesterAddr;
    BufferIdx += DOIP_ADDR_LENGTH;
    /* update DoIP src address */
    pTxHeaderBuffer[BufferIdx] = (uint8)(DOIP_LOGICAL_ADDRESS >> 8u);
    pTxHeaderBuffer[BufferIdx+1u] = (uint8)DOIP_LOGICAL_ADDRESS;
    BufferIdx += DOIP_ADDR_LENGTH;
    pTxHeaderBuffer[BufferIdx] = AckCode;
    BufferIdx += 1u;
    pTxHeaderBuffer[BufferIdx] = 0U;
    pTxHeaderBuffer[BufferIdx+1u] = 0U;
    pTxHeaderBuffer[BufferIdx+2u] = 0U;
    pTxHeaderBuffer[BufferIdx+3u] = 0U;
    BufferIdx += 4u;
    /* update header */
    if ((TesterIdx == DoIP_CfgGetNumOfTester()) || ( TesterAddr != DoIP_TcpConCtrlGetTesterAddr(TcpConIdx)))
    {
        /* update generic header for unknown tester */
        DoIP_UpdateGenericHeader(DOIP_HEADER_TYPE_ROUT_ACTIV_RES, DOIP_ROUT_ACTIV_ACK_MIN_LENGTH, pTxHeaderBuffer);
    }
    else if ((RoutingActivationIdx != DoIP_CfgGetNumOfRoutingActivation()) || 
             ((DoIP_TcpConCtrlGetRoutingActivationState(TcpConIdx) != DOIP_ROUTING_ACTIVATION_STATE_ACTIVATED) ||
             ((DoIP_RoutingActivationCfgGetAuthReqLength(RoutingActivationIdx) == 0U) &&
             (DoIP_RoutingActivationCfgGetConfReqLength(RoutingActivationIdx) == 0U))))
    {
        /* update generic header for unknown routing activation */
        DoIP_UpdateGenericHeader(DOIP_HEADER_TYPE_ROUT_ACTIV_RES, DOIP_ROUT_ACTIV_ACK_MIN_LENGTH, pTxHeaderBuffer);
    }
    else
    {
        uint32 OemSpecRes = DoIP_RoutingActivationCtrlGetOemResponse();
        DoIP_UpdateGenericHeader(DOIP_HEADER_TYPE_ROUT_ACTIV_RES,DOIP_ROUT_ACTIV_ACK_MAX_LENGTH,pTxHeaderBuffer);
        pTxHeaderBuffer[BufferIdx] = (uint8)(OemSpecRes >> 24u);
        pTxHeaderBuffer[BufferIdx+1u] = (uint8)(OemSpecRes >> 16u);
        pTxHeaderBuffer[BufferIdx+2u] = (uint8)(OemSpecRes >> 8u);
        pTxHeaderBuffer[BufferIdx+3u] = (uint8)(OemSpecRes);
        BufferIdx+=4u;
    }
    /* Update transmit message struct */
    DoIP_TxTcpQueueElementCtrlSetHeaderBufferLength(TxTcpQueueElementIdx,BufferIdx);
    DoIP_TxTcpQueueElementCtrlSetTxTcpPduInfoLength(TxTcpQueueElementIdx,BufferIdx);
    DoIP_TxTcpQueueElementCtrlSetTxTcpPduInfoSduDataPtr(TxTcpQueueElementIdx,pTxHeaderBuffer);
}
/********************************************************************************************************************
* @brief  This api used to add the tcp alive check req tx data to the tcp queue
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_TxTcpQueueAddAliveCheckReq
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx
)
{
    uint8 * pTxHeaderBuffer;
    
    pTxHeaderBuffer = &DoIP_TxHeaderBuffer[DoIP_TcpConCfgGetTxHeaderBufferStartIdx(TcpConIdx)];
     /* update alive check header */
    DoIP_UpdateGenericHeader(DOIP_HEADER_TYPE_ALIVE_CHECK_REQ,0U,pTxHeaderBuffer);
    /* Update transmit message struct */
    DoIP_TxTcpQueueElementCtrlSetHeaderBufferLength(TxTcpQueueElementIdx,DOIP_GENERIC_HEADER_LENGTH);
    DoIP_TxTcpQueueElementCtrlSetTxTcpPduInfoLength(TxTcpQueueElementIdx,DOIP_GENERIC_HEADER_LENGTH);
    DoIP_TxTcpQueueElementCtrlSetTxTcpPduInfoSduDataPtr(TxTcpQueueElementIdx,pTxHeaderBuffer);
}
/********************************************************************************************************************
* @brief  This api used to add the tcp diag req tx data to the tcp queue
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_TxTcpQueueAddDiagReq
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    DoIP_ChannelIdxType ChannelIdx,
    PduLengthType Length,
    P2VAR(uint8,AUTOMATIC,DOIP_APPL_DATA) DataPtr
)
{
    DoIP_EcuAddrType EcuAddr;
    DoIP_TesterIdxType TesterIdx;
    DoIP_TesterAddrType TesterAddr;
    uint8 * pTxHeaderBuffer;
    PduLengthType BufferIdx;
    
    BufferIdx = DOIP_GENERIC_HEADER_LENGTH;
    EcuAddr  = DoIP_ChannelCfgGetEcuAddr(ChannelIdx);
    TesterIdx = DoIP_TcpConCtrlGetTesterIdx(TcpConIdx);
    TesterAddr = DoIP_TesterCfgGetTesterAddr(TesterIdx);
    pTxHeaderBuffer = &DoIP_TxHeaderBuffer[DoIP_TcpConCfgGetTxHeaderBufferStartIdx(TcpConIdx)];
    
    if (DOIP_API_TYPE_IF == DoIP_ChannelCfgGetApiType(ChannelIdx))
    {
        DoIP_UtilMemCopy(&DoIP_TxIfBuffer[DoIP_ChannelCfgGetTxIfBufferStartIdx(ChannelIdx)],DataPtr,Length);
    }
    /* update header for Diag Req */
    DoIP_UpdateGenericHeader(DOIP_HEADER_TYPE_DIAG_REQ,(DOIP_DIAG_HDR_LENGTH+Length),pTxHeaderBuffer);
    /* update Ecu addr */
    pTxHeaderBuffer[BufferIdx] = (uint8)(EcuAddr >> 8u);
    pTxHeaderBuffer[BufferIdx+1u] = (uint8)EcuAddr;
    BufferIdx += DOIP_ADDR_LENGTH;
    if (TesterAddr == DOIP_ADDR_ANY)
    {
        pTxHeaderBuffer[BufferIdx] = (uint8)(DoIP_TcpConCtrlGetTesterAddr(TcpConIdx) >> 8u);
        pTxHeaderBuffer[BufferIdx+1u] = (uint8)DoIP_TcpConCtrlGetTesterAddr(TcpConIdx);
    }
    else
    {
        pTxHeaderBuffer[BufferIdx] = (uint8)(TesterAddr >> 8u);
        pTxHeaderBuffer[BufferIdx+1u] = (uint8)TesterAddr;
    }
    BufferIdx += DOIP_ADDR_LENGTH;
    /* Update transmit message struct */
    DoIP_TxTcpQueueElementCtrlSetHeaderBufferLength(TxTcpQueueElementIdx,BufferIdx);
    DoIP_TxTcpQueueElementCtrlSetTxTcpPduInfoLength(TxTcpQueueElementIdx,(BufferIdx+Length));
    DoIP_TxTcpQueueElementCtrlSetChannelIdx(TxTcpQueueElementIdx,ChannelIdx);
    
    if (DOIP_API_TYPE_IF == DoIP_ChannelCfgGetApiType(ChannelIdx))
    {
        DoIP_TxTcpQueueElementCtrlSetTxTcpPduInfoSduDataPtr(TxTcpQueueElementIdx,DataPtr);
    }
    else
    {
        DoIP_TxTcpQueueElementCtrlSetTxTcpPduInfoSduDataPtr(TxTcpQueueElementIdx,pTxHeaderBuffer);
    }
}
/********************************************************************************************************************
* @brief  This api used to add the tcp diag ack tx data to the tcp queue
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_TxTcpQueueAddDiagAck
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    uint16 EcuAddr
)
{
    uint8 * pTxHeaderBuffer;
    DoIP_TesterIdxType TesterIdx;
    DoIP_TesterAddrType TesterAddr;
    PduLengthType NegativeAckOffset;
    PduLengthType BufferIdx;
    
    BufferIdx = DOIP_GENERIC_HEADER_LENGTH;
    TesterIdx = DoIP_TcpConCtrlGetTesterIdx(TcpConIdx);
    TesterAddr = DoIP_TesterCfgGetTesterAddr(TesterIdx);
    pTxHeaderBuffer = &DoIP_TxHeaderBuffer[DoIP_TcpConCfgGetTxHeaderBufferStartIdx(TcpConIdx)];
    NegativeAckOffset = DoIP_TesterCtrlGetNegativeAckOffset(TesterIdx);
    
    if (DoIP_TesterCfgGetNumOfDiagAckNackRespBytes(TesterIdx) > 0U)
    {
        DoIP_UpdateGenericHeader(DOIP_HEADER_TYPE_DIAG_ACK,
                                (DOIP_DIAG_MSG_ACK_LENGTH+NegativeAckOffset),pTxHeaderBuffer);
    }
    else
    {
        DoIP_UpdateGenericHeader(DOIP_HEADER_TYPE_DIAG_ACK,DOIP_DIAG_MSG_ACK_LENGTH,pTxHeaderBuffer);
    }
    /* update Ecu addr */
    pTxHeaderBuffer[BufferIdx] = (uint8)(EcuAddr >> 8u);
    pTxHeaderBuffer[BufferIdx+1u] = (uint8)EcuAddr;
    BufferIdx += DOIP_ADDR_LENGTH;
    if (TesterAddr == DOIP_ADDR_ANY)
    {
        pTxHeaderBuffer[BufferIdx] = (uint8)(DoIP_TcpConCtrlGetTesterAddr(TcpConIdx) >> 8u);
        pTxHeaderBuffer[BufferIdx+1u] = (uint8)DoIP_TcpConCtrlGetTesterAddr(TcpConIdx);
    }
    else
    {
        pTxHeaderBuffer[BufferIdx] = (uint8)(TesterAddr >> 8u);
        pTxHeaderBuffer[BufferIdx+1u] = (uint8)TesterAddr;
    }
    BufferIdx += DOIP_ADDR_LENGTH;
    pTxHeaderBuffer[BufferIdx] = DOIP_DIAG_MSG_RES_CODE_ACK;
    BufferIdx+=1u;
    /* Update transmit message struct */
    DoIP_TxTcpQueueElementCtrlSetHeaderBufferLength(TxTcpQueueElementIdx,BufferIdx);
    DoIP_TxTcpQueueElementCtrlSetTxTcpPduInfoSduDataPtr(TxTcpQueueElementIdx,pTxHeaderBuffer);
    if (DoIP_TesterCfgGetNumOfDiagAckNackRespBytes(TesterIdx) > 0U)
    {
        DoIP_TxTcpQueueElementCtrlSetTxTcpPduInfoLength(TxTcpQueueElementIdx,(NegativeAckOffset+BufferIdx));
    }
    else
    {
        DoIP_TxTcpQueueElementCtrlSetTxTcpPduInfoLength(TxTcpQueueElementIdx,BufferIdx);
    }
}
/********************************************************************************************************************
* @brief  This api used to add the tcp diag nack tx data to the tcp queue
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_TxTcpQueueAddDiagNack
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    uint16 EcuAddr,
    uint16 TesterAddr,
    uint8 NackCode
)
{
    uint8 * pTxHeaderBuffer;
    PduLengthType BufferIdx;
    DoIP_TesterIdxType TesterIdx;
    PduLengthType NegativeAckOffset=0U;
    
    BufferIdx = DOIP_GENERIC_HEADER_LENGTH;
    TesterIdx = DoIP_TcpConCtrlGetTesterIdx(TcpConIdx);
    pTxHeaderBuffer = &DoIP_TxHeaderBuffer[DoIP_TcpConCfgGetTxHeaderBufferStartIdx(TcpConIdx)];
    
    if (TesterIdx != DoIP_CfgGetNumOfTester())
    {
        NegativeAckOffset = DoIP_TesterCtrlGetNegativeAckOffset(TesterIdx);
        DoIP_UpdateGenericHeader(DOIP_HEADER_TYPE_DIAG_ACK,
                                    (DOIP_DIAG_MSG_ACK_LENGTH+NegativeAckOffset),pTxHeaderBuffer);
    }
    else
    {
        DoIP_UpdateGenericHeader(DOIP_HEADER_TYPE_DIAG_ACK,DOIP_DIAG_MSG_ACK_LENGTH,pTxHeaderBuffer);
    }
    /* update Ecu addr */
    pTxHeaderBuffer[BufferIdx] = (uint8)(EcuAddr >> 8u);
    pTxHeaderBuffer[BufferIdx+1u] = (uint8)EcuAddr;
    BufferIdx += DOIP_ADDR_LENGTH;
    /* update Ecu addr */
    pTxHeaderBuffer[BufferIdx] = (uint8)(TesterAddr >> 8u);
    pTxHeaderBuffer[BufferIdx+1u] = (uint8)TesterAddr;
    BufferIdx += DOIP_ADDR_LENGTH;
    /* update Nack Code */
    pTxHeaderBuffer[BufferIdx] = NackCode;
    BufferIdx += 1u;
    /* Update transmit message struct */
    DoIP_TxTcpQueueElementCtrlSetHeaderBufferLength(TxTcpQueueElementIdx,BufferIdx);
    DoIP_TxTcpQueueElementCtrlSetTxTcpPduInfoSduDataPtr(TxTcpQueueElementIdx,pTxHeaderBuffer);
    if (DoIP_TesterCfgGetNumOfDiagAckNackRespBytes(TesterIdx) > 0U)
    {
        DoIP_TxTcpQueueElementCtrlSetTxTcpPduInfoLength(TxTcpQueueElementIdx,(NegativeAckOffset+BufferIdx));
    }
    else
    {
        DoIP_TxTcpQueueElementCtrlSetTxTcpPduInfoLength(TxTcpQueueElementIdx,BufferIdx);
    }
}
/********************************************************************************************************************
* @brief  This api used to add the tcp oem tx data to the tcp queue
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_TxTcpQueueAddOem
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    uint16 OemHeaderType
)
{
    uint8 * pTxHeaderBuffer;
    PduLengthType OemTcpBufferLength=0U;
    
    pTxHeaderBuffer = &DoIP_TxHeaderBuffer[DoIP_TcpConCfgGetTxHeaderBufferStartIdx(TcpConIdx)];
    OemTcpBufferLength = DoIP_OemPayloadCtrlGetTcpBufferLength();
    /* update Oem header */
    DoIP_UpdateGenericHeader(OemHeaderType,OemTcpBufferLength,pTxHeaderBuffer);
    /* Update transmit message struct */
    DoIP_TxTcpQueueElementCtrlSetHeaderBufferLength(TxTcpQueueElementIdx,DOIP_GENERIC_HEADER_LENGTH);
    DoIP_TxTcpQueueElementCtrlSetTxTcpPduInfoLength(TxTcpQueueElementIdx,
                                                    (DOIP_GENERIC_HEADER_LENGTH+OemTcpBufferLength));
    DoIP_TxTcpQueueElementCtrlSetTxTcpPduInfoSduDataPtr(TxTcpQueueElementIdx,pTxHeaderBuffer);
}

/********************************************************************************************************************
* @brief  This api used to handle the copying of tcp tx header data to the queue 
********************************************************************************************************************/
DOIP_LOCAL FUNC(BufReq_ReturnType, DOIP_CODE) DoIP_TxTcpQueueCopyHeader
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) AvailableDataPtr,
    P2VAR(boolean, AUTOMATIC, DOIP_APPL_VAR) IsHeaderCopied
)
{
    uint8 * pTxHeaderBuffer;
    BufReq_ReturnType RetVal = BUFREQ_OK;
    PduLengthType HeaderBufferLength;
    PduLengthType TxBytesCopied;
    DoIP_TcpConIdxType RoutActTcpConIdx;
    DoIP_GenericHeaderType GenericHeader={0};

    pTxHeaderBuffer = &DoIP_TxHeaderBuffer[DoIP_TcpConCfgGetTxHeaderBufferStartIdx(TcpConIdx)];
    HeaderBufferLength = DoIP_TxTcpQueueElementCtrlGetHeaderBufferLength(TxTcpQueueElementIdx); 
    TxBytesCopied = DoIP_TcpConCtrlGetTxBytesCopied(TcpConIdx);
    
    if (PduInfoPtr->SduLength != 0U)
    {
        /* copy header data */
        if (PduInfoPtr->SduLength  <= (HeaderBufferLength - TxBytesCopied))
        {
            DoIP_UtilMemCopy(PduInfoPtr->SduDataPtr,&pTxHeaderBuffer[TxBytesCopied],PduInfoPtr->SduLength);
            /* update bytes copied */
            TxBytesCopied += PduInfoPtr->SduLength;
            DoIP_TcpConCtrlSetTxBytesCopied(TcpConIdx,TxBytesCopied);
            if (TxBytesCopied == HeaderBufferLength)
            {            
                DOIP_UtilExtractGenericHeader(&GenericHeader,pTxHeaderBuffer);
                /* check for routing activation response */
                RoutActTcpConIdx = DoIP_RoutingActivationCtrlGetTcpConIdx();
                if ((GenericHeader.HeaderType == DOIP_HEADER_TYPE_ROUT_ACTIV_RES) &&
                    (RoutActTcpConIdx != DoIP_CfgGetNumOfTcpConnection()) &&
                    (DoIP_TcpConCtrlGetRoutingActivationState(RoutActTcpConIdx) != DOIP_ROUTING_ACTIVATION_STATE_CONF_PENDING))
                {
                    /* Reset routing status */
                    DoIP_RoutingActivationCtrlSetTcpConIdx(DoIP_CfgGetNumOfTcpConnection());
                    DoIP_RoutingActivationCtrlSetAliveCheckCount(0U);
                }
                *IsHeaderCopied = TRUE;
            }
        }
        else
        {
            /* Invalid length */
            RetVal = BUFREQ_E_NOT_OK;
        }
    }
    
    if (RetVal == BUFREQ_OK)
    {
        *AvailableDataPtr = HeaderBufferLength - TxBytesCopied;
        DoIP_TcpConCtrlSetTxLastBufferSize(TcpConIdx,*AvailableDataPtr);
    }
    return RetVal;    
}
/********************************************************************************************************************
* @brief  This api used to handle the copying of tcp tx data to the queue 
********************************************************************************************************************/
DOIP_LOCAL FUNC(BufReq_ReturnType, DOIP_CODE) DoIP_TxTcpQueueCopyData
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) AvailableDataPtr,
    boolean IsHeaderCopied
)
{
    BufReq_ReturnType RetVal;
    uint8 *pTxHeaderBuffer;
    DoIP_GenericHeaderType GenericHeader={0};
    
    pTxHeaderBuffer = &DoIP_TxHeaderBuffer[DoIP_TcpConCfgGetTxHeaderBufferStartIdx(TcpConIdx)];
    DOIP_UtilExtractGenericHeader(&GenericHeader,pTxHeaderBuffer);
    
    if (GenericHeader.HeaderType == DOIP_HEADER_TYPE_DIAG_REQ)
    {
        RetVal = DoIP_TxTcpQueueCopyDiagReq(TxTcpQueueElementIdx,TcpConIdx,PduInfoPtr,AvailableDataPtr,IsHeaderCopied);
    }
    else if ((GenericHeader.HeaderType  == DOIP_HEADER_TYPE_DIAG_ACK) ||
              (GenericHeader.HeaderType  == DOIP_HEADER_TYPE_DIAG_NACK))
    {
        RetVal = DoIP_TxTcpQueueCopyDiagAck(TxTcpQueueElementIdx,TcpConIdx,PduInfoPtr,AvailableDataPtr,IsHeaderCopied); 
    }
    else 
    {
        #if (DOIP_OEM_PAYLOAD_TCP_BUFFER_SIZE > 0U)
        DoIP_TxTcpQueueCopyOemSpecific(TxTcpQueueElementIdx,TcpConIdx,PduInfoPtr,AvailableDataPtr,IsHeaderCopied);
        #endif 
        RetVal = BUFREQ_OK;
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief  This api used to handle the copying of tcp tx diag data to the queue 
********************************************************************************************************************/
DOIP_LOCAL FUNC(BufReq_ReturnType, DOIP_CODE) DoIP_TxTcpQueueCopyDiagReq
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) AvailableDataPtr,
    boolean IsHeaderCopied
)
{
    BufReq_ReturnType RetVal;
    DoIP_ChannelIdxType ChannelIdx;
    
    ChannelIdx = DoIP_TxTcpQueueElementCtrlGetChannelIdx(TxTcpQueueElementIdx);
    if (DoIP_ChannelCfgGetApiType(ChannelIdx) == DOIP_API_TYPE_IF)
    {
        DoIP_TxTcpQueueCopyDiagReqIf(TxTcpQueueElementIdx,TcpConIdx,PduInfoPtr,AvailableDataPtr,IsHeaderCopied); 
        RetVal = BUFREQ_OK;
    }
    else
    {
        RetVal = DoIP_TxTcpQueueCopyDiagReqTp(TxTcpQueueElementIdx,TcpConIdx,PduInfoPtr,
                                                                AvailableDataPtr,IsHeaderCopied); 
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief  This api used to handle the copying of tcp If tx diag data to the queue 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_TxTcpQueueCopyDiagReqIf
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) AvailableDataPtr,
    boolean IsHeaderCopied
)
{
    PduInfoType  *pMsgPduInfo;
    PduLengthType TxBytesCopied;
    DoIP_ChannelIdxType ChannelIdx;
    
    ChannelIdx = DoIP_TxTcpQueueElementCtrlGetChannelIdx(TxTcpQueueElementIdx);
    pMsgPduInfo = &DoIP_TxTcpQueueElementCtrlGetTxTcpPduInfo(TxTcpQueueElementIdx);    
    TxBytesCopied = DoIP_TcpConCtrlGetTxBytesCopied(TcpConIdx);
    
    if ((PduInfoPtr->SduLength != 0U) && (IsHeaderCopied == FALSE))
    {
        /* copy remaining header */
        DoIP_UtilMemCopy(PduInfoPtr->SduDataPtr,
                         &DoIP_TxIfBuffer[DoIP_ChannelCfgGetTxIfBufferStartIdx(ChannelIdx)],PduInfoPtr->SduLength);
        TxBytesCopied+=PduInfoPtr->SduLength;
        DoIP_TcpConCtrlSetTxBytesCopied(TcpConIdx,TxBytesCopied);
    }
    /* update AvailableDataPtr */
    *AvailableDataPtr = pMsgPduInfo->SduLength - TxBytesCopied;
    DoIP_TcpConCtrlSetTxLastBufferSize(TcpConIdx,*AvailableDataPtr);
}
/********************************************************************************************************************
* @brief  This api used to handle the copying of tcp Tp tx diag data to the queue 
********************************************************************************************************************/
DOIP_LOCAL FUNC(BufReq_ReturnType, DOIP_CODE) DoIP_TxTcpQueueCopyDiagReqTp
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) AvailableDataPtr,
    boolean IsHeaderCopied
)
{
    BufReq_ReturnType RetVal;
    PduInfoType const * pLocalPduInfo;
    PduInfoType  LocalPduInfo;
    PduLengthType TxBytesCopied;
    DoIP_ChannelIdxType ChannelIdx;
    
    ChannelIdx = DoIP_TxTcpQueueElementCtrlGetChannelIdx(TxTcpQueueElementIdx);
    TxBytesCopied = DoIP_TcpConCtrlGetTxBytesCopied(TcpConIdx);
    pLocalPduInfo = PduInfoPtr;
    
    if (IsHeaderCopied == TRUE)
    {
        LocalPduInfo.SduLength = 0U;
        LocalPduInfo.SduDataPtr = NULL_PTR;
        pLocalPduInfo = &LocalPduInfo;
    }
    /* Invoke upper layer CopyTxData to get available buffer or copying. */
    RetVal = PduR_DoIPTpCopyTxData(DoIP_ChannelCfgGetTxConfId(ChannelIdx),pLocalPduInfo,NULL_PTR,AvailableDataPtr);
    
    if (DoIP_TcpConCtrlGetTxTcpQueueElementIdx(TcpConIdx) == 0U)
    {
        /* copy failed */
        RetVal = BUFREQ_E_NOT_OK;
    }
    if (RetVal == BUFREQ_OK)
    {
        DoIP_TcpConCtrlSetTxLastBufferSize(TcpConIdx,*AvailableDataPtr);
        if ((pLocalPduInfo->SduLength !=0U) || (PduInfoPtr->SduLength == 0U))
        {
            DoIP_TcpConCtrlSetTxBytesCopied(TcpConIdx,TxBytesCopied+pLocalPduInfo->SduLength);
        }
    }
    else
    {
        /* Close connection if buffer request failed */
        DoIP_ConCtrlSetSoConCloseReq(TcpConIdx,TRUE);
        DoIP_SoConClose(TcpConIdx);
        RetVal = BUFREQ_E_NOT_OK;
    }
    return RetVal;
}
/********************************************************************************************************************
* @brief  This api used to handle the copying of tcp Tp tx diag ack to the queue 
********************************************************************************************************************/
DOIP_LOCAL FUNC(BufReq_ReturnType, DOIP_CODE) DoIP_TxTcpQueueCopyDiagAck
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) AvailableDataPtr,
    boolean IsHeaderCopied
)
{
    PduInfoType  *pMsgPduInfo;
    PduLengthType TxBytesCopied;
    DoIP_TesterIdxType TesterIdx;
    BufReq_ReturnType RetVal=BUFREQ_OK;
    
    pMsgPduInfo = &DoIP_TxTcpQueueElementCtrlGetTxTcpPduInfo(TxTcpQueueElementIdx);
    TxBytesCopied = DoIP_TcpConCtrlGetTxBytesCopied(TcpConIdx);
    TesterIdx = DoIP_TcpConCtrlGetTesterIdx(TcpConIdx);
    /* copy data */
    if ((PduInfoPtr->SduLength != 0u) && (IsHeaderCopied == FALSE))
    {
        DoIP_UtilMemCopy(PduInfoPtr->SduDataPtr,
                        &DoIP_DiagNAckBuffer[DoIP_TesterCfgGetDiagNackBufferStartIdx(TesterIdx)+TxBytesCopied],
                        PduInfoPtr->SduLength);
        TxBytesCopied += PduInfoPtr->SduLength;
        DoIP_TcpConCtrlSetTxBytesCopied(TcpConIdx,TxBytesCopied);
        if (TxBytesCopied == pMsgPduInfo->SduLength)
        {
            /* Reset offset if all data are copied to lower layer buffer */
            DoIP_TesterCtrlSetNegativeAckOffset(TesterIdx,0u);
        }
    }
    /* update AvailableDataPtr */
    *AvailableDataPtr = pMsgPduInfo->SduLength - TxBytesCopied;
    DoIP_TcpConCtrlSetTxLastBufferSize(TcpConIdx,*AvailableDataPtr);
    return RetVal;
}

#if (DOIP_OEM_PAYLOAD_TCP_BUFFER_SIZE > 0U)
/********************************************************************************************************************
* @brief  This api used to handle the copying of tcp Tp tx oem specific data to the queue 
********************************************************************************************************************/
DOIP_LOCAL FUNC(void, DOIP_CODE) DoIP_TxTcpQueueCopyOemSpecific
(
    DoIP_TxTcpQueueElementIdxType TxTcpQueueElementIdx,
    DoIP_TcpConIdxType TcpConIdx,
    P2CONST(PduInfoType, AUTOMATIC, DOIP_APPL_VAR) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DOIP_APPL_VAR) AvailableDataPtr,
    boolean IsHeaderCopied
)
{
    PduInfoType  *pMsgPduInfo;
    PduLengthType TxBytesCopied;
    
    pMsgPduInfo = &DoIP_TxTcpQueueElementCtrlGetTxTcpPduInfo(TxTcpQueueElementIdx);
    TxBytesCopied = DoIP_TcpConCtrlGetTxBytesCopied(TcpConIdx);
    
    /* copy data */
    if ((PduInfoPtr->SduLength != 0u) && (IsHeaderCopied == FALSE))
    {
        DoIP_UtilMemCopy(PduInfoPtr->SduDataPtr,
                &DoIP_OemPayloadTcpBuffer[TxBytesCopied-
                                        DoIP_TxTcpQueueElementCtrlGetHeaderBufferLength(TxTcpQueueElementIdx)],
                PduInfoPtr->SduLength);
        TxBytesCopied += PduInfoPtr->SduLength;
        DoIP_TcpConCtrlSetTxBytesCopied(TcpConIdx,TxBytesCopied);
        if (TxBytesCopied == pMsgPduInfo->SduLength)
        {
            /* If all data copied */
            DoIP_OemPayloadCtrlSetTcpBufferLength(0u);
            DoIP_OemPayloadCtrlSetTcpBufferReqTx(FALSE);
            DoIP_OemPayloadCtrlSetTcpBufferConIdx(DoIP_CfgGetNumOfConnection());
        }
    }
    /* update AvailableDataPtr */
    *AvailableDataPtr = pMsgPduInfo->SduLength - TxBytesCopied;
    DoIP_TcpConCtrlSetTxLastBufferSize(TcpConIdx,*AvailableDataPtr);
}
#endif
#define DOIP_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************************************************
*                                 END OF FILE                                                                      *
********************************************************************************************************************/
/*******************************************************************************************************************
*   For each change to this file, be sure to record:                                                               *
*      1.  who made the change and when the change was made                                                        *
*      2.  why the change was made and the intended result                                                         *
*   Following block needs to be repeated for each change                                                           *
*******************************************************************************************************************/
/*!*****************************************************************************************************************
*  @date    29-Dec-2023
*  @version 1.0.0
*  @author  pchinnat
*  @brief   Traceability - AUTOSAR 4.3 version initial implementation 
*******************************************************************************************************************/

