///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2017] Visteon Corporation
/// All Rights Reserved.
///
/// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
/// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
/// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
/// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
/// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
/// under all copyright laws to protect this work as a published work, when appropriate.
/// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
/// without the written authorization of Visteon Corporation.
///
///---------------------------------------------------------------------------------------------------------------------
#include "UclALOs.h"
#include "UclCmnRingBuffer.h"

Ucl_ReturnType UclCmnRingBuffer_Initialize ( SUclCmnRingBuffer *pRB, uint8 *pBuffer, uint16 size )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ( ( NULL != pRB ) && ( NULL != pBuffer ) && ( 0u < size ) )
    {
        pRB->pBuffer = pBuffer;
        pRB->BufferSize = size;
        pRB->ReadIndex = 0;
        pRB->WriteIndex = 0;
        pRB->FillCount = 0;

        Ret = UclALOs_Memset ( 0, pBuffer, 0xFF, size );
    }

    return Ret;
}

Ucl_ReturnType UclCmnRingBuffer_Reset ( SUclCmnRingBuffer *pRB )
{
    Ucl_ReturnType Ret = UCL_E_NOK;

    if ( ( NULL != pRB ) && ( NULL != pRB->pBuffer ) )
    {
        pRB->ReadIndex = 0;
        pRB->WriteIndex = 0;
        pRB->FillCount = 0;

        Ret = UclALOs_Memset ( 0, pRB->pBuffer, 0xFF, pRB->BufferSize );
    }

    return Ret;
}

Ucl_ReturnType UclCmnRingBuffer_Write ( SUclCmnRingBuffer *pRB, uint8 *pBuffer, uint16 size )
{
    Ucl_ReturnType Ret = UCL_E_BUFFER_FULL;
    uint16 it = 0;
    uint16 wi = 0;

    /* Check if we have enough space */
    if ( size < ( pRB->BufferSize - pRB->FillCount ) )
    {
        wi = pRB->WriteIndex;

        /* Copy data */
        for ( it = 0u; it < size; it++ )
        {
            pRB->pBuffer[wi] = pBuffer[it];
            wi = ( wi + 1u ) % pRB->BufferSize;
        }

        /* Update the fill count and write index */
        pRB->WriteIndex = wi;
        pRB->FillCount += size;

        Ret = UCL_E_OK;
    }

    return Ret;
}

Ucl_ReturnType UclCmnRingBuffer_Read ( SUclCmnRingBuffer *pRB, uint8 *pBuffer, uint16 *pSize )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint16 BuffLen = 0;
    uint16 MsgLen = 0;
    uint16 FillCnt = 0;
    uint16 it = 0;
    uint16 ri = 0;

    BuffLen = *pSize;
    FillCnt = pRB->FillCount;

    *pSize = 0;

    /* Check if buffer is empty */
    if ( FillCnt != 0u )
    {
        if ( BuffLen < FillCnt )
        {
            MsgLen = BuffLen;
        }
        else
        {
            MsgLen = FillCnt;
        }

        ri = pRB->ReadIndex;

        /* Copy data */
        for ( it = 0u; ( it < MsgLen ); it++ )
        {
            pBuffer[it] = pRB->pBuffer[ri];
            ri = ( ri + 1u ) % pRB->BufferSize;
        }

        pRB->ReadIndex = ri;
        pRB->FillCount -= MsgLen;

        *pSize = MsgLen;

        Ret = UCL_E_OK;
    }

    return Ret;
}

Ucl_ReturnType UclCmnRingBuffer_Poll ( SUclCmnRingBuffer *pRB, uint8 *pBuffer, uint16 *pSize )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint16 BuffLen = 0;
    uint16 MsgLen = 0;
    uint16 FillCnt = 0;
    uint16 it = 0;
    uint16 ri = 0;

    BuffLen = *pSize;
    FillCnt = pRB->FillCount;

    *pSize = 0;

    /* Check if buffer is empty */
    if ( FillCnt != 0u )
    {
        if ( BuffLen < FillCnt )
        {
            MsgLen = BuffLen;
        }
        else
        {
            MsgLen = FillCnt;
        }

        ri = pRB->ReadIndex;

        /* Copy data */
        for ( it = 0u; ( it < MsgLen ); it++ )
        {
            pBuffer[it] = pRB->pBuffer[ri];
            ri = ( ri + 1u ) % pRB->BufferSize;
        }

        *pSize = MsgLen;

        Ret = UCL_E_OK;
    }

    return Ret;
}

Ucl_ReturnType UclCmnRingBuffer_ReadFrame ( SUclCmnRingBuffer *pRB, uint8 delim, uint8 *pBuffer, uint16 *pSize )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint16 BuffLen = 0;
    uint16 FillCnt = 0;
    uint16 it = 0;
    uint16 ri = 0;

    BuffLen = *pSize;
    FillCnt = pRB->FillCount;

    *pSize = 0;
    ;

    /* Check if buffer is empty */
    if ( FillCnt != 0u )
    {
        ri = pRB->ReadIndex;

        /* Check the first byte */
        if ( delim == pRB->pBuffer[ri] )
        {
            pBuffer[it] = pRB->pBuffer[ri];
            ri = ( ri + 1u ) % pRB->BufferSize;

            /* Copy data */
            for ( it = 1u; ( ( it < BuffLen ) && ( it < FillCnt ) ); it++ )
            {
                pBuffer[it] = pRB->pBuffer[ri];

                /* Check if we have the complete frame */
                if ( delim == pBuffer[it] )
                {
                    /* Clear the message */
                    pRB->pBuffer[pRB->ReadIndex] = 0xFFu;
                    pRB->pBuffer[ri] = 0xFFu;

                    ri = ( ri + 1u ) % pRB->BufferSize;
                    pRB->ReadIndex = ri;
                    pRB->FillCount -= ( it + 1u );

                    *pSize = ( it + 1u );
                    Ret = UCL_E_OK;
                    break;
                }

                ri = ( ri + 1u ) % pRB->BufferSize;
            }
        }
        else
        {
            /* Unexpected. Seek to next Start of Frame? Reset Buffer? */
            ( void ) UclCmnRingBuffer_Reset ( pRB );
        }
    }

    return Ret;
}

Ucl_ReturnType UclCmnRingBuffer_GetFillCnt ( SUclCmnRingBuffer *pRB, uint16 *pSize )
{	
	*pSize = pRB->FillCount;
	
	return UCL_E_OK;
}
 
Ucl_ReturnType UclCmnRingBuffer_IndexedRead ( SUclCmnRingBuffer *pRB, uint8 *pBuffer, uint16 *pSize, uint16 Index )
{
    Ucl_ReturnType Ret = UCL_E_NOK;
    uint16 BuffLen = 0;
    uint16 MsgLen = 0;
    uint16 FillCnt = 0;
    uint16 it = 0;
    uint16 ri = 0;

    BuffLen = *pSize;
    FillCnt = pRB->FillCount;

    *pSize = 0;

    /* Check if read index fits in fill count limit */
    if ( Index < FillCnt )
    {
        if ( BuffLen < FillCnt )
        {
            MsgLen = BuffLen;
        }
        else
        {
            MsgLen = FillCnt;
        }

        ri = ( pRB->ReadIndex + Index ) % pRB->BufferSize;

        /* Copy data */
        for ( it = 0u; ( it < MsgLen ); it++ )
        {
            pBuffer[it] = pRB->pBuffer[ri];
            ri = ( ri + 1u ) % pRB->BufferSize;
        }

        *pSize = MsgLen;

        Ret = UCL_E_OK;
    }

    return Ret;
}
