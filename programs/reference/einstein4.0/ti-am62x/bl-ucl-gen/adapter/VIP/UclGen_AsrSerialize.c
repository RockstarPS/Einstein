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

#include <Ucl_Types.h>
#include <Rte_UclProxyCdd.h>
#include <UclGen_AsrSerialize.h>
#include <UclCmnSerialize.h>

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Serialization of data of type SUpdateShortServiceReq into provided buffer.
///
/// @param  data:         The data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is serialized correctly
///         UCL_E_NOK:    The data is not serialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnSerialize_SUpdateShortServiceReq( SUpdateShortServiceReq *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16Used = 0;

    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint16( data->msgId, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint16( data->msgSize, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->memoryType, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->memoryCmd, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->sid, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint32( data->length, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_data_u8_64( data->data, &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Serialization of data of type data_u8_64 into provided buffer.
///
/// @param  data:         The data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is serialized correctly
///         UCL_E_NOK:    The data is not serialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnSerialize_data_u8_64( data_u8_64 data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16ArrayIndex = 0;
    uint16 u16Used = 0;

    for (u16ArrayIndex = 0; (u16ArrayIndex < 64u) && (UCL_E_OK == ret); u16ArrayIndex++)
    {
        ret = UclCmnSerialize_uint8( data[u16ArrayIndex], &(pBuffer[u16Used]), &u16Used );
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Serialization of data of type SUpdateLongServiceReq into provided buffer.
///
/// @param  data:         The data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is serialized correctly
///         UCL_E_NOK:    The data is not serialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnSerialize_SUpdateLongServiceReq( SUpdateLongServiceReq *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16Used = 0;

    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint16( data->msgId, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint16( data->msgSize, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->memoryType, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->memoryCmd, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->sid, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint32( data->length, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_data_u8_2048( data->data, &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Serialization of data of type data_u8_2048 into provided buffer.
///
/// @param  data:         The data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is serialized correctly
///         UCL_E_NOK:    The data is not serialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnSerialize_data_u8_2048( data_u8_2048 data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16ArrayIndex = 0;
    uint16 u16Used = 0;

    for (u16ArrayIndex = 0; (u16ArrayIndex < 2048u) && (UCL_E_OK == ret); u16ArrayIndex++)
    {
        ret = UclCmnSerialize_uint8( data[u16ArrayIndex], &(pBuffer[u16Used]), &u16Used );
    }

    *pBytesCopied += u16Used;
    return ret;
}


//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Deserialization of data of type SUpdateShortServiceResp from provided buffer.
///
/// @param  data:         Pointer to the data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is deserialized correctly
///         UCL_E_NOK:    The data is not deserialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnDeserialize_SUpdateShortServiceResp( SUpdateShortServiceResp *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16Used = 0;

    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_uint16( &(data->msgId), &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_uint16( &(data->msgSize), &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_uint8( &(data->sid), &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_uint16( &(data->length), &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_uint8( &(data->responseCode), &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_uint8( &(data->NRC), &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_data_u8_64( &(data->data), &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Deserialization of data of type data_u8_64 from provided buffer.
///
/// @param  data:         Pointer to the data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is deserialized correctly
///         UCL_E_NOK:    The data is not deserialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnDeserialize_data_u8_64( data_u8_64 *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16ArrayIndex = 0;
    uint16 u16Used = 0;

    for (u16ArrayIndex = 0; (u16ArrayIndex < 64u) && (UCL_E_OK == ret); u16ArrayIndex++)
    {
        ret = UclCmnDeserialize_uint8( &((*data)[u16ArrayIndex]), &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}


