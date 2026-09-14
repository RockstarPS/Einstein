//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2022] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
//
// File generated automatically using Visteon DiCore UCL configuration generator 1.3.3
// Date: Tue Oct 01 15:54:36 IST 2024
// User: KRAMESH5
// Gateway: UCL_GW
// Configuration: Platform_Recovery
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.2
//
//---------------------------------------------------------------------------------------------------------------------

#include <UclILAdapter.h>
#include <UclILSched.h>
#include <UclALOs.h>
#include <UclALDebug.h>
#include <UclGen_VmfAdapter.h>
#include <UclGen_VmfAdapterIds.h>
#include <UclVmfMsgQueue.h>

//---------------------------------------------------------------------------------------
// Message indexes inside transmit deployments
//---------------------------------------------------------------------------------------
#define UpdateShortServiceResp_UpdateShortServiceResp_Index    ((uint8)0u)

//---------------------------------------------------------------------------------------
// Message indexes inside receive deployments
//---------------------------------------------------------------------------------------
#define UpdateShortServiceReq_UpdateShortServiceReq_Index    ((uint8)0u)
#define UpdateLongServiceReq_UpdateLongServiceReq_Index    ((uint8)0u)

//---------------------------------------------------------------------------------------
// Transmit deployment indexes
//---------------------------------------------------------------------------------------
#define Tx_UpdateShortServiceResp_Index    ((uint8)0u)

//---------------------------------------------------------------------------------------
// Receive deployment indexes
//---------------------------------------------------------------------------------------
#define Rx_UpdateShortServiceReq_Index    ((uint8)0u)
#define Rx_UpdateLongServiceReq_Index    ((uint8)1u)

//---------------------------------------------------------------------------------------
// Mixed transmit deployment & message indexes 
//---------------------------------------------------------------------------------------
#define Tx_UpdateShortServiceResp_UpdateShortServiceResp_MergedIndex    ((((uint16)Tx_UpdateShortServiceResp_Index) << 8) | ((uint16)UpdateShortServiceResp_UpdateShortServiceResp_Index))

//---------------------------------------------------------------------------------------
// Transmit deployments queue sizes
//---------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------
// Sizes of serialized message types
//---------------------------------------------------------------------------------------
#define UpdateShortServiceResp_BufferSize    ((uint16)73u)

//---------------------------------------------------------------------------------------
// Message buffers
//---------------------------------------------------------------------------------------
static uint8 TxUpdateShortServiceRespBuffer_new[UpdateShortServiceResp_BufferSize] = { 0x00 };

//---------------------------------------------------------------------------------------
// Configuration of queued transmit messages
//---------------------------------------------------------------------------------------
const SUclVmfMsgQueueConfig UclVmfMsgQueueConfig[UclVmfMsgQueueCount] =
{
};

SUclVmfMsgQueueRuntime UclVmfMsgQueueRuntime[UclVmfMsgQueueCount];

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Common callout to retrieve message for transmission.
///
/// @param  pMsgBuff:      Buffer to store the message for transmission
/// @param  pMsgBuff_new:  Buffer that contains the latest data, received from the VMF
/// @param  pMsgBuff_sent: Buffer that contains the latest data, sent to the VIP through the UCL
/// @param  BuffSize:      Size of the message buffers
/// @param  pBytesCopied:  Incremented with number of used bytes
/// @param  returnType:    See enumerator description
/// @param  pUpdated:      Per message update flag
///
/// @return TRUE:  Data is retrieved successfully
///         FALSE: Invalid 'returnType'
///                No new data in case of 'eUclILAdapterDataType_OnChange'
//---------------------------------------------------------------------------------------------------------------------
static uint8 UclCommon_Read_Message(uint8 *pMsgBuff, uint8 *pMsgBuff_new, uint8 *pMsgBuff_sent, const uint16 BuffSize, uint16 *pBytesCopied, const EUclILAdapterDataType returnType, uint8 *pUpdated)
{
    uint8 result = FALSE;
    Ucl_ReturnType memResult = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != *pUpdated)
            {
                memResult = UclALOs_Memcpy(0u, pMsgBuff, pMsgBuff_sent, BuffSize);
                if(UCL_E_OK == memResult)
                {
                    *pBytesCopied += BuffSize;
                    result = TRUE;
                }
            }
            break;

        case eUclILAdapterDataType_Always:        ///< Adapter to return if the data is changed
            *pUpdated = TRUE;
            memResult = UclALOs_Memcpy(0u, pMsgBuff_sent, pMsgBuff_new, BuffSize);
            if(UCL_E_OK == memResult)
            {
                memResult = UclALOs_Memcpy(0u, pMsgBuff, pMsgBuff_sent, BuffSize);
                if(UCL_E_OK == memResult)
                {
                    *pBytesCopied += BuffSize;
                    result = TRUE;
                }
            }
            break;

        case eUclILAdapterDataType_OnChange:          ///< Adapter to return the latest data, if available
            *pUpdated = FALSE;
            memResult = UclALOs_Memcmp(0u, pMsgBuff_sent, pMsgBuff_new, BuffSize);
            if(UCL_E_OK != memResult)
            {
                *pUpdated = TRUE;
                memResult = UclALOs_Memcpy(0u, pMsgBuff_sent, pMsgBuff_new, BuffSize);
                if(UCL_E_OK == memResult)
                {
                    memResult = UclALOs_Memcpy(0u, pMsgBuff, pMsgBuff_sent, BuffSize);
                    if(UCL_E_OK == memResult)
                    {
                        *pBytesCopied += BuffSize;
                        result = TRUE;
                    }
                }
            }
            break;

        default:
            break;
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Will be called by UclVmfProxy when new message is received
///
/// @param  msgIdx:   Message deployment index
/// @param  duIdx:    Message index
/// @param  pPayload: Payload of the message
/// @param  Size:     Size of the message
///
/// @return See UclALOs_Memcpy
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_NotifyNewMessageReceived(uint8 msgIdx, uint8 duIdx, uint8 *pPayload, uint16 Size)
{
    uint8 result = FALSE;
    uint16 buffIndex = ((((uint16)msgIdx) << 8) | ((uint16)duIdx));

    switch (buffIndex) 
    {
        case Tx_UpdateShortServiceResp_UpdateShortServiceResp_MergedIndex: //DbIndex + DuIndex
            result = (UCL_E_OK == UclALOs_Memcpy(0u, TxUpdateShortServiceRespBuffer_new, pPayload, sizeof(TxUpdateShortServiceRespBuffer_new)));
            (void)UclILSched_NotifyMessageUpdate(0u, msgIdx, duIdx, NULL, 0u);    // For OnWrite / OnChange deployments
            break;
    }
    return result;
}

//---------------------------------------------------------------------------------------------------------------------
// Callouts for transmit messages
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message UpdateShortServiceResp
//---------------------------------------------------------------------------------------------------------------------
static uint8 TxUpdateShortServiceRespBuffer_sent[UpdateShortServiceResp_BufferSize] = { 0x00 };
static uint8 iS_UpdateShortServiceRespBuffer_updated = FALSE;

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: UpdateShortServiceResp
///
/// @param  pMsgBuff:     Buffer to store the message for transmission
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return See UclCommon_Read_Message
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_UpdateShortServiceResp(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    return UclCommon_Read_Message(pMsgBuff, TxUpdateShortServiceRespBuffer_new, TxUpdateShortServiceRespBuffer_sent, sizeof(TxUpdateShortServiceRespBuffer_sent), pBytesCopied, returnType, &iS_UpdateShortServiceRespBuffer_updated);
}

//---------------------------------------------------------------------------------------------------------------------
// Callouts for received messages
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message UpdateShortServiceReq. Send message content to VMF server.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Message added to transmit queue
///         FALSE: See CUclVmfProxy::addVmfMsgToTxQueue 
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_UpdateShortServiceReq(uint8 *pMsgBuff, uint16 Size)
{
    return UclVmfProxy_AddVmfMsgToTxQueue(Gx_UpdateShortServiceReq_Rx, Ex_UpdateShortServiceReq_Rx, pMsgBuff, Size);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message UpdateLongServiceReq. Send message content to VMF server.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Message added to transmit queue
///         FALSE: See CUclVmfProxy::addVmfMsgToTxQueue 
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_UpdateLongServiceReq(uint8 *pMsgBuff, uint16 Size)
{
    return UclVmfProxy_AddVmfMsgToTxQueue(Gx_UpdateLongServiceReq_Rx, Ex_UpdateLongServiceReq_Rx, pMsgBuff, Size);
}


//---------------------------------------------------------------------------------------------------------------------
// Status notifications
//---------------------------------------------------------------------------------------------------------------------
void UclGen_Adapter_ErrorNotification(uint8 DLInst, sint32 ErrorCode) 
{
    LOGI(0u, "UclGen", "ErrorNotification %d, %d", DLInst, ErrorCode);
#ifdef UCL_ERROR_NOTIFY
	UclVmfProxy_AddVmfMsgToTxQueue(Gx_Ucl_Error_Notify_Rx, Ex_Ucl_Error_Notify_Rx, (uint8 *)(&ErrorCode), sizeof(ErrorCode));
#endif
}

void UclGen_Adapter_LinkStatusChanged(uint8 DLInst, sint32 Status) 
{
    LOGI(0u, "UclGen", "LinkStatusChanged %d, %d", DLInst, Status);
#ifdef UCL_LINK_STATUS
	UclVmfProxy_AddVmfMsgToTxQueue(Gx_Ucl_Link_Status_Rx, Ex_Ucl_Link_Status_Rx, (uint8 *)(&Status), sizeof(Status));
#endif
}

void UclGen_Adapter_MessageTransmitStatus(uint16 MsgId, sint32 Status) 
{
    LOGI(0u, "UclGen", "MessageTransmitStatus 0x%02x, %d", MsgId, Status);
    switch (MsgId)
    {
    }
}

void UclGen_Adapter_ReceiveMissingStatus(uint16 MsgId, sint32 Status) 
{
    LOGI(0u, "UclGen", "ReceiveMissingStatus 0x%02x, %d", MsgId, Status);
    switch (MsgId)
    {
    }
}

