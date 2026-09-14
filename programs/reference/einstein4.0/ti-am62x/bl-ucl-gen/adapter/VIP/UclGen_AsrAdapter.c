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

#include <Rte_UclProxyCdd.h>
#include <UclILAdapter.h>
#include <UclILSched.h>
#include <UclCmnSerialize.h>
#include <UclGen_AsrSerialize.h>
#include <UclGen_AsrAdapter.h>
#include <string.h>

//---------------------------------------------------------------------------------------
// Message indexes inside transmit deployments
//---------------------------------------------------------------------------------------
#define UpdateShortServiceReq_UpdateShortServiceReq_Index    ((uint8)0u)
#define UpdateLongServiceReq_UpdateLongServiceReq_Index    ((uint8)0u)

//---------------------------------------------------------------------------------------
// Transmit deployment indexes
//---------------------------------------------------------------------------------------
#define Tx_UpdateShortServiceReq_Index    ((uint8)0u)
#define Tx_UpdateLongServiceReq_Index    ((uint8)1u)

//---------------------------------------------------------------------------------------------------------------------
// Comparison of types
//---------------------------------------------------------------------------------------------------------------------
static boolean UclGenCompare_SUpdateShortServiceReq(SUpdateShortServiceReq *data1, SUpdateShortServiceReq *data2);
static boolean UclGenCompare_SUpdateLongServiceReq(SUpdateLongServiceReq *data1, SUpdateLongServiceReq *data2);

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Compare of data of type SUpdateShortServiceReq.
///
/// @param  data1:         First data for comparison
/// @param  data2:         Second data for comparison
///
/// @return TRUE:     The data is identical
///         FALSE:    The data is not identical
//---------------------------------------------------------------------------------------------------------------------
static boolean UclGenCompare_SUpdateShortServiceReq(SUpdateShortServiceReq *data1, SUpdateShortServiceReq *data2)
{
    boolean result = TRUE;

    if (FALSE != result)
    {
        result = (data1->msgId == data2->msgId);
    }
    if (FALSE != result)
    {
        result = (data1->msgSize == data2->msgSize);
    }
    if (FALSE != result)
    {
        result = (data1->memoryType == data2->memoryType);
    }
    if (FALSE != result)
    {
        result = (data1->memoryCmd == data2->memoryCmd);
    }
    if (FALSE != result)
    {
        result = (data1->sid == data2->sid);
    }
    if (FALSE != result)
    {
        result = (data1->length == data2->length);
    }
    if (FALSE != result)
    {
        result = (0 == memcmp(data1->data, data2->data, sizeof(data_u8_64)));
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
/// @brief  Compare of data of type SUpdateLongServiceReq.
///
/// @param  data1:         First data for comparison
/// @param  data2:         Second data for comparison
///
/// @return TRUE:     The data is identical
///         FALSE:    The data is not identical
//---------------------------------------------------------------------------------------------------------------------
static boolean UclGenCompare_SUpdateLongServiceReq(SUpdateLongServiceReq *data1, SUpdateLongServiceReq *data2)
{
    boolean result = TRUE;

    if (FALSE != result)
    {
        result = (data1->msgId == data2->msgId);
    }
    if (FALSE != result)
    {
        result = (data1->msgSize == data2->msgSize);
    }
    if (FALSE != result)
    {
        result = (data1->memoryType == data2->memoryType);
    }
    if (FALSE != result)
    {
        result = (data1->memoryCmd == data2->memoryCmd);
    }
    if (FALSE != result)
    {
        result = (data1->sid == data2->sid);
    }
    if (FALSE != result)
    {
        result = (data1->length == data2->length);
    }
    if (FALSE != result)
    {
        result = (0 == memcmp(data1->data, data2->data, sizeof(data_u8_2048)));
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
// Callouts for received messages
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout on reception of message UpdateShortServiceResp. Deserialize received buffer and publish data to the RTE.
///
/// @param  pMsgBuff: Data received
/// @param  Size:     Number of bytes
///
/// @return TRUE:  Data is deserialized and published to the RTE
///         FALSE: Not enough data 
///                Deserialization error 
///                RTE write error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Send_UpdateShortServiceResp(uint8 *pMsgBuff, uint16 Size)
{
    uint16 u16BytesConsumed = 0u;
    SUpdateShortServiceResp sUpdateShortServiceRespLocal;
    uint8 result = FALSE;
  
    if(Size >= UpdateShortServiceResp_BufferSize)
    {
        result = (UCL_E_OK == UclCmnDeserialize_SUpdateShortServiceResp(&(sUpdateShortServiceRespLocal), pMsgBuff, &u16BytesConsumed));
        if(FALSE != result)
        {
            result = (uint8)(E_OK == Rte_Write_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(&sUpdateShortServiceRespLocal));
        }
    }

    return result;
}


//---------------------------------------------------------------------------------------------------------------------
// Transmited messages
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message UpdateShortServiceReq
//---------------------------------------------------------------------------------------------------------------------
void OnDre_UpdateShortServiceReq(void)
{
    UclILSched_NotifyMessageUpdate( 0u, Tx_UpdateShortServiceReq_Index, UpdateShortServiceReq_UpdateShortServiceReq_Index, NULL, 0);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message UpdateShortServiceReq
//---------------------------------------------------------------------------------------------------------------------
static const SUpdateShortServiceReq sUpdateShortServiceReqStatic_Initializer = {.msgId = 0, .msgSize = 0, .memoryType = 0, .memoryCmd = 0, .sid = 0, .length = 0, .data = 0};
static SUpdateShortServiceReq sUpdateShortServiceReqStatic = {.msgId = 0, .msgSize = 0, .memoryType = 0, .memoryCmd = 0, .sid = 0, .length = 0, .data = 0};

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: UpdateShortServiceReq
///
/// @param  pMsgBuff:     Buffer to store serialized message
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return TRUE:  Data is retrieved and serialized successfully
///         FALSE: Invalid 'returnType'
///                Serialization failure
///                No new data in case of 'eUclILAdapterDataType_OnChange'
///                RTE communication error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_UpdateShortServiceReq(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    SUpdateShortServiceReq sUpdateShortServiceReqLocal;
    uint8 result = FALSE;
    Std_ReturnType resultRte = E_OK;
    static uint8 updated = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != updated )
            {
                result = (UCL_E_OK == UclCmnSerialize_SUpdateShortServiceReq(&(sUpdateShortServiceReqStatic), pMsgBuff, pBytesCopied));
            }
            break;
            
        case eUclILAdapterDataType_OnChange:        ///< Adapter to return if the data is changed
            updated = FALSE;
            resultRte = Rte_Read_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&sUpdateShortServiceReqLocal);
            if(E_OK == resultRte)
            {
                boolean compare = UclGenCompare_SUpdateShortServiceReq(&(sUpdateShortServiceReqLocal), &(sUpdateShortServiceReqStatic));
                if(FALSE == compare)
                {
                    updated = TRUE;
                    sUpdateShortServiceReqStatic = sUpdateShortServiceReqLocal;    // signal update only
                    result = (UCL_E_OK == UclCmnSerialize_SUpdateShortServiceReq(&(sUpdateShortServiceReqStatic), pMsgBuff, pBytesCopied));
                }
            }
            break;
            
        case eUclILAdapterDataType_Always:          ///< Adapter to return the latest data, if available
            updated = TRUE;
            resultRte = Rte_Read_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&sUpdateShortServiceReqLocal);
            if(E_OK == resultRte)
            {
                sUpdateShortServiceReqStatic = sUpdateShortServiceReqLocal;    // signal update only
                result = (UCL_E_OK == UclCmnSerialize_SUpdateShortServiceReq(&(sUpdateShortServiceReqStatic), pMsgBuff, pBytesCopied));
            }
            break;

        default:
            break;
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Runnable activated on DRE for message UpdateLongServiceReq
//---------------------------------------------------------------------------------------------------------------------
void OnDre_UpdateLongServiceReq(void)
{
    UclILSched_NotifyMessageUpdate( 0u, Tx_UpdateLongServiceReq_Index, UpdateLongServiceReq_UpdateLongServiceReq_Index, NULL, 0);
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Data for message UpdateLongServiceReq
//---------------------------------------------------------------------------------------------------------------------
static const SUpdateLongServiceReq sUpdateLongServiceReqStatic_Initializer = {.msgId = 0, .msgSize = 0, .memoryType = 0, .memoryCmd = 0, .sid = 0, .length = 0, .data = 0};
static SUpdateLongServiceReq sUpdateLongServiceReqStatic = {.msgId = 0, .msgSize = 0, .memoryType = 0, .memoryCmd = 0, .sid = 0, .length = 0, .data = 0};

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Callout to retrieve message for transmission.
///         Message: UpdateLongServiceReq
///
/// @param  pMsgBuff:     Buffer to store serialized message
/// @param  pBytesCopied: Incremented with number of used bytes
/// @param  returnType:   See enumerator description
///
/// @return TRUE:  Data is retrieved and serialized successfully
///         FALSE: Invalid 'returnType'
///                Serialization failure
///                No new data in case of 'eUclILAdapterDataType_OnChange'
///                RTE communication error
//---------------------------------------------------------------------------------------------------------------------
uint8 UclGen_Read_UpdateLongServiceReq(uint8 *pMsgBuff, uint16 *pBytesCopied, EUclILAdapterDataType returnType)
{
    SUpdateLongServiceReq sUpdateLongServiceReqLocal;
    uint8 result = FALSE;
    Std_ReturnType resultRte = E_OK;
    static uint8 updated = FALSE;

    switch(returnType)
    {
        case eUclILAdapterDataType_Retry:           ///< Adapter to return backup data
            if(FALSE != updated )
            {
                result = (UCL_E_OK == UclCmnSerialize_SUpdateLongServiceReq(&(sUpdateLongServiceReqStatic), pMsgBuff, pBytesCopied));
            }
            break;
            
        case eUclILAdapterDataType_OnChange:        ///< Adapter to return if the data is changed
            updated = FALSE;
            resultRte = Rte_Read_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&sUpdateLongServiceReqLocal);
            if(E_OK == resultRte)
            {
                boolean compare = UclGenCompare_SUpdateLongServiceReq(&(sUpdateLongServiceReqLocal), &(sUpdateLongServiceReqStatic));
                if(FALSE == compare)
                {
                    updated = TRUE;
                    sUpdateLongServiceReqStatic = sUpdateLongServiceReqLocal;    // signal update only
                    result = (UCL_E_OK == UclCmnSerialize_SUpdateLongServiceReq(&(sUpdateLongServiceReqStatic), pMsgBuff, pBytesCopied));
                }
            }
            break;
            
        case eUclILAdapterDataType_Always:          ///< Adapter to return the latest data, if available
            updated = TRUE;
            resultRte = Rte_Read_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&sUpdateLongServiceReqLocal);
            if(E_OK == resultRte)
            {
                sUpdateLongServiceReqStatic = sUpdateLongServiceReqLocal;    // signal update only
                result = (UCL_E_OK == UclCmnSerialize_SUpdateLongServiceReq(&(sUpdateLongServiceReqStatic), pMsgBuff, pBytesCopied));
            }
            break;

        default:
            break;
    }

    return result;
}

//---------------------------------------------------------------------------------------------------------------------
/// @brief  Initialization of static variables
//---------------------------------------------------------------------------------------------------------------------
void UclGen_AsrAdapterInit(void)
{
    sUpdateShortServiceReqStatic = sUpdateShortServiceReqStatic_Initializer;
    sUpdateLongServiceReqStatic = sUpdateLongServiceReqStatic_Initializer;
}

//---------------------------------------------------------------------------------------------------------------------
// Status notifications
//---------------------------------------------------------------------------------------------------------------------
void UclGen_Adapter_ErrorNotification(uint8 DLInst, sint32 ErrorCode) 
{
    (void)Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(DLInst, ErrorCode);
}

void UclGen_Adapter_LinkStatusChanged(uint8 DLInst, sint32 Status) 
{
    (void)Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(DLInst, Status);
}

void UclGen_Adapter_MessageTransmitStatus(uint16 MsgId, sint32 Status) 
{
    switch (MsgId)
    {
    }
}

void UclGen_Adapter_ReceiveMissingStatus(uint16 MsgId, sint32 Status) 
{
    switch (MsgId)
    {
    }
}

