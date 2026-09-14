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
// Date: Wed Sep 17 12:27:28 IST 2025
// User: SSRINI28
// Gateway: UCL_GW
// Configuration: Platform
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.10
//
//---------------------------------------------------------------------------------------------------------------------

#include <Ucl_Types.h>
#include <Rte_UclProxyCdd.h>
#include <UclGen_AsrSerialize.h>
#include <UclCmnSerialize.h>

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Serialization of data of type SPowerSystemStateReqChange into provided buffer.
///
/// @param  data:         The data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is serialized correctly
///         UCL_E_NOK:    The data is not serialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnSerialize_SPowerSystemStateReqChange( SPowerSystemStateReqChange *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16Used = 0;

    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->domainId, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->state, &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Serialization of data of type SDisplaySetPower into provided buffer.
///
/// @param  data:         The data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is serialized correctly
///         UCL_E_NOK:    The data is not serialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnSerialize_SDisplaySetPower( SDisplaySetPower *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16Used = 0;

    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint32( data->displayId, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->state, &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Serialization of data of type data_u8_15 into provided buffer.
///
/// @param  data:         The data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is serialized correctly
///         UCL_E_NOK:    The data is not serialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnSerialize_data_u8_15( data_u8_15 data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16ArrayIndex = 0;
    uint16 u16Used = 0;

    for (u16ArrayIndex = 0; (u16ArrayIndex < 15u) && (UCL_E_OK == ret); u16ArrayIndex++)
    {
        ret = UclCmnSerialize_uint8( data[u16ArrayIndex], &(pBuffer[u16Used]), &u16Used );
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Serialization of data of type SRTT_Toggle into provided buffer.
///
/// @param  data:         The data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is serialized correctly
///         UCL_E_NOK:    The data is not serialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnSerialize_SRTT_Toggle( SRTT_Toggle *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16Used = 0;

    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->positions, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->display, &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Serialization of data of type data_u8_2 into provided buffer.
///
/// @param  data:         The data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is serialized correctly
///         UCL_E_NOK:    The data is not serialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnSerialize_data_u8_2( data_u8_2 data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16ArrayIndex = 0;
    uint16 u16Used = 0;

    for (u16ArrayIndex = 0; (u16ArrayIndex < 2u) && (UCL_E_OK == ret); u16ArrayIndex++)
    {
        ret = UclCmnSerialize_uint8( data[u16ArrayIndex], &(pBuffer[u16Used]), &u16Used );
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Serialization of data of type SWarningExtDisplay into provided buffer.
///
/// @param  data:         The data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is serialized correctly
///         UCL_E_NOK:    The data is not serialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnSerialize_SWarningExtDisplay( SWarningExtDisplay *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16Used = 0;

    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->show, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint16( data->warningId, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_data_u8_8( data->dynData, &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Serialization of data of type data_u8_8 into provided buffer.
///
/// @param  data:         The data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is serialized correctly
///         UCL_E_NOK:    The data is not serialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnSerialize_data_u8_8( data_u8_8 data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16ArrayIndex = 0;
    uint16 u16Used = 0;

    for (u16ArrayIndex = 0; (u16ArrayIndex < 8u) && (UCL_E_OK == ret); u16ArrayIndex++)
    {
        ret = UclCmnSerialize_uint8( data[u16ArrayIndex], &(pBuffer[u16Used]), &u16Used );
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Serialization of data of type SWarningDisplay into provided buffer.
///
/// @param  data:         The data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is serialized correctly
///         UCL_E_NOK:    The data is not serialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnSerialize_SWarningDisplay( SWarningDisplay *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16Used = 0;

    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->show, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint16( data->warningId, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_data_u8_8( data->dynData, &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Serialization of data of type SGaugeInfo_2 into provided buffer.
///
/// @param  data:         The data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is serialized correctly
///         UCL_E_NOK:    The data is not serialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnSerialize_SGaugeInfo_2( SGaugeInfo_2 data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16ArrayIndex = 0;
    uint16 u16Used = 0;

    for (u16ArrayIndex = 0; (u16ArrayIndex < 2u) && (UCL_E_OK == ret); u16ArrayIndex++)
    {
        ret = UclCmnSerialize_SGaugeInfo( &(data[u16ArrayIndex]), &(pBuffer[u16Used]), &u16Used );
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Serialization of data of type SGaugeInfo into provided buffer.
///
/// @param  data:         The data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is serialized correctly
///         UCL_E_NOK:    The data is not serialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnSerialize_SGaugeInfo( SGaugeInfo *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16Used = 0;

    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->id, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint16( data->position, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_sint32( data->digitalData, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->unit, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint16( data->dynData, &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Serialization of data of type SGaugeInfo_u32dyn_3 into provided buffer.
///
/// @param  data:         The data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is serialized correctly
///         UCL_E_NOK:    The data is not serialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnSerialize_SGaugeInfo_u32dyn_3( SGaugeInfo_u32dyn_3 data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16ArrayIndex = 0;
    uint16 u16Used = 0;

    for (u16ArrayIndex = 0; (u16ArrayIndex < 3u) && (UCL_E_OK == ret); u16ArrayIndex++)
    {
        ret = UclCmnSerialize_SGaugeInfo_u32dyn( &(data[u16ArrayIndex]), &(pBuffer[u16Used]), &u16Used );
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Serialization of data of type SGaugeInfo_u32dyn into provided buffer.
///
/// @param  data:         The data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is serialized correctly
///         UCL_E_NOK:    The data is not serialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnSerialize_SGaugeInfo_u32dyn( SGaugeInfo_u32dyn *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16Used = 0;

    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->id, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint16( data->position, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint32( data->digitalData, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->unit, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint32( data->dynData, &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Serialization of data of type SShiftInd into provided buffer.
///
/// @param  data:         The data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is serialized correctly
///         UCL_E_NOK:    The data is not serialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnSerialize_SShiftInd( SShiftInd *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16Used = 0;

    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->Shift_Ind_Pos, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->Shift_Ind_BlinkReq, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->Shift_Ind_Up, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->Shift_Ind_Down, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->Shift_Ind_DisplayDecState, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->Shift_Ind_Screen_ShiftType, &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Serialization of data of type SIlluminationData into provided buffer.
///
/// @param  data:         The data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is serialized correctly
///         UCL_E_NOK:    The data is not serialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnSerialize_SIlluminationData( SIlluminationData *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16Used = 0;

    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->data, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->dayStep, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->nightStep, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->daynightStatus, &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

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
/// @brief  Serialization of data of type data_u8_512 into provided buffer.
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
/// @brief  Serialization of data of type SDiagDIDRequest into provided buffer.
///
/// @param  data:         The data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is serialized correctly
///         UCL_E_NOK:    The data is not serialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnSerialize_SDiagDIDRequest( SDiagDIDRequest *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16Used = 0;

    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint16( data->did, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->didType, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint16( data->dataLen, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_data_u8_256( data->data, &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Serialization of data of type data_u8_256 into provided buffer.
///
/// @param  data:         The data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is serialized correctly
///         UCL_E_NOK:    The data is not serialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnSerialize_data_u8_256( data_u8_256 data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16ArrayIndex = 0;
    uint16 u16Used = 0;

    for (u16ArrayIndex = 0; (u16ArrayIndex < 256u) && (UCL_E_OK == ret); u16ArrayIndex++)
    {
        ret = UclCmnSerialize_uint8( data[u16ArrayIndex], &(pBuffer[u16Used]), &u16Used );
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Serialization of data of type SDiagIOCtrlRequest into provided buffer.
///
/// @param  data:         The data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is serialized correctly
///         UCL_E_NOK:    The data is not serialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnSerialize_SDiagIOCtrlRequest( SDiagIOCtrlRequest *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16Used = 0;

    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint16( data->did, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->optionCtrl, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint16( data->dataLen, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_data_u8_256( data->data, &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Serialization of data of type SDiagRoutineRequest into provided buffer.
///
/// @param  data:         The data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is serialized correctly
///         UCL_E_NOK:    The data is not serialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnSerialize_SDiagRoutineRequest( SDiagRoutineRequest *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16Used = 0;

    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint16( data->routineId, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint8( data->routineType, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_uint16( data->dataLen, &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnSerialize_data_u8_256( data->data, &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}


//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Deserialization of data of type SPowerSystemState from provided buffer.
///
/// @param  data:         Pointer to the data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is deserialized correctly
///         UCL_E_NOK:    The data is not deserialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnDeserialize_SPowerSystemState( SPowerSystemState *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16Used = 0;

    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_uint8( &(data->domainId), &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_uint8( &(data->state), &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Deserialization of data of type SPowerExtendShutdownTime from provided buffer.
///
/// @param  data:         Pointer to the data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is deserialized correctly
///         UCL_E_NOK:    The data is not deserialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnDeserialize_SPowerExtendShutdownTime( SPowerExtendShutdownTime *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16Used = 0;

    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_uint8( &(data->domainId), &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_uint32( &(data->timeoutMs), &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Deserialization of data of type SPowerKeepSystemAwake from provided buffer.
///
/// @param  data:         Pointer to the data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is deserialized correctly
///         UCL_E_NOK:    The data is not deserialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnDeserialize_SPowerKeepSystemAwake( SPowerKeepSystemAwake *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16Used = 0;

    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_uint8( &(data->domainId), &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_uint32( &(data->timeoutMs), &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}


//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Deserialization of data of type SHealthDomainHeartbeat from provided buffer.
///
/// @param  data:         Pointer to the data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is deserialized correctly
///         UCL_E_NOK:    The data is not deserialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnDeserialize_SHealthDomainHeartbeat( SHealthDomainHeartbeat *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16Used = 0;

    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_uint8( &(data->domainId), &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_uint32( &(data->seqCnt), &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Deserialization of data of type SHealthDomainFatalError from provided buffer.
///
/// @param  data:         Pointer to the data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is deserialized correctly
///         UCL_E_NOK:    The data is not deserialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnDeserialize_SHealthDomainFatalError( SHealthDomainFatalError *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16Used = 0;

    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_uint8( &(data->domainId), &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_uint32( &(data->compIdx), &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Deserialization of data of type SHealthEventRecord from provided buffer.
///
/// @param  data:         Pointer to the data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is deserialized correctly
///         UCL_E_NOK:    The data is not deserialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnDeserialize_SHealthEventRecord( SHealthEventRecord *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16Used = 0;

    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_uint8( &(data->recordType), &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_uint8( &(data->recordLen), &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_data_u8_8( &(data->recordData), &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Deserialization of data of type data_u8_8 from provided buffer.
///
/// @param  data:         Pointer to the data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is deserialized correctly
///         UCL_E_NOK:    The data is not deserialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnDeserialize_data_u8_8( data_u8_8 *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16ArrayIndex = 0;
    uint16 u16Used = 0;

    for (u16ArrayIndex = 0; (u16ArrayIndex < 8u) && (UCL_E_OK == ret); u16ArrayIndex++)
    {
        ret = UclCmnDeserialize_uint8( &((*data)[u16ArrayIndex]), &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Deserialization of data of type SHealthDumpData from provided buffer.
///
/// @param  data:         Pointer to the data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is deserialized correctly
///         UCL_E_NOK:    The data is not deserialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnDeserialize_SHealthDumpData( SHealthDumpData *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16Used = 0;

    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_uint32( &(data->chunkSize), &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_data_u8_32( &(data->data), &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Deserialization of data of type data_u8_32 from provided buffer.
///
/// @param  data:         Pointer to the data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is deserialized correctly
///         UCL_E_NOK:    The data is not deserialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnDeserialize_data_u8_32( data_u8_32 *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16ArrayIndex = 0;
    uint16 u16Used = 0;

    for (u16ArrayIndex = 0; (u16ArrayIndex < 32u) && (UCL_E_OK == ret); u16ArrayIndex++)
    {
        ret = UclCmnDeserialize_uint8( &((*data)[u16ArrayIndex]), &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}


//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Deserialization of data of type data_u8_256 from provided buffer.
///
/// @param  data:         Pointer to the data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is deserialized correctly
///         UCL_E_NOK:    The data is not deserialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnDeserialize_data_u8_256( data_u8_256 *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16ArrayIndex = 0;
    uint16 u16Used = 0;

    for (u16ArrayIndex = 0; (u16ArrayIndex < 256u) && (UCL_E_OK == ret); u16ArrayIndex++)
    {
        ret = UclCmnDeserialize_uint8( &((*data)[u16ArrayIndex]), &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Deserialization of data of type SDisplayCurrentState from provided buffer.
///
/// @param  data:         Pointer to the data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is deserialized correctly
///         UCL_E_NOK:    The data is not deserialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnDeserialize_SDisplayCurrentState( SDisplayCurrentState *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16Used = 0;

    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_uint32( &(data->displayId), &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_uint8( &(data->state), &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Deserialization of data of type SWarningStatus from provided buffer.
///
/// @param  data:         Pointer to the data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is deserialized correctly
///         UCL_E_NOK:    The data is not deserialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnDeserialize_SWarningStatus( SWarningStatus *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16Used = 0;

    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_uint8( &(data->visible), &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_uint16( &(data->warningId), &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_data_u8_10( &(data->dynData), &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Deserialization of data of type data_u8_10 from provided buffer.
///
/// @param  data:         Pointer to the data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is deserialized correctly
///         UCL_E_NOK:    The data is not deserialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnDeserialize_data_u8_10( data_u8_10 *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16ArrayIndex = 0;
    uint16 u16Used = 0;

    for (u16ArrayIndex = 0; (u16ArrayIndex < 10u) && (UCL_E_OK == ret); u16ArrayIndex++)
    {
        ret = UclCmnDeserialize_uint8( &((*data)[u16ArrayIndex]), &(pBuffer[u16Used]), &u16Used);
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

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Deserialization of data of type SDiagResponse from provided buffer.
///
/// @param  data:         Pointer to the data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is deserialized correctly
///         UCL_E_NOK:    The data is not deserialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnDeserialize_SDiagResponse( SDiagResponse *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16Used = 0;

    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_uint8( &(data->responseCode), &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_uint16( &(data->dataLen), &(pBuffer[u16Used]), &u16Used);
    }
    if ( UCL_E_OK == ret )
    {
        ret = UclCmnDeserialize_data_u8_256( &(data->data), &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

//---------------------------------------------------------------------------------------------------------------------'
/// @brief  Deserialization of data of type data_u8_2 from provided buffer.
///
/// @param  data:         Pointer to the data
/// @param  pBuffer:      Pointer to the beginning of the buffer
/// @param  pBytesCopied: Pointer to uint16 that must be incremented with
///                       the amount of bytes used for the current operation
///
/// @return UCL_E_OK:     The data is deserialized correctly
///         UCL_E_NOK:    The data is not deserialized correctly
//---------------------------------------------------------------------------------------------------------------------'
Ucl_ReturnType UclCmnDeserialize_data_u8_2( data_u8_2 *data, uint8 *pBuffer, uint16 *pBytesCopied )
{
    Ucl_ReturnType ret = UCL_E_OK;
    uint16 u16ArrayIndex = 0;
    uint16 u16Used = 0;

    for (u16ArrayIndex = 0; (u16ArrayIndex < 2u) && (UCL_E_OK == ret); u16ArrayIndex++)
    {
        ret = UclCmnDeserialize_uint8( &((*data)[u16ArrayIndex]), &(pBuffer[u16Used]), &u16Used);
    }

    *pBytesCopied += u16Used;
    return ret;
}

