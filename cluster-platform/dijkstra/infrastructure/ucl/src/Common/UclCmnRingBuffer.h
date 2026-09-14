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
#ifndef UCLCMNRINGBUFFER_H
#define UCLCMNRINGBUFFER_H

#include "Ucl_Types.h"

typedef struct
{
    uint8 *pBuffer;
    uint16 BufferSize;
    uint16 ReadIndex;
    uint16 WriteIndex;
    uint16 FillCount;
} SUclCmnRingBuffer;

Ucl_ReturnType UclCmnRingBuffer_Initialize ( SUclCmnRingBuffer *pRB, uint8 *pBuffer, uint16 size );
Ucl_ReturnType UclCmnRingBuffer_Reset ( SUclCmnRingBuffer *pRB );
Ucl_ReturnType UclCmnRingBuffer_Write ( SUclCmnRingBuffer *pRB, uint8 *pBuffer, uint16 size );
Ucl_ReturnType UclCmnRingBuffer_Read ( SUclCmnRingBuffer *pRB, uint8 *pBuffer, uint16 *pSize );
Ucl_ReturnType UclCmnRingBuffer_ReadFrame ( SUclCmnRingBuffer *pRB, uint8 delim, uint8 *pBuffer, uint16 *pSize );
Ucl_ReturnType UclCmnRingBuffer_Poll ( SUclCmnRingBuffer *pRB, uint8 *pBuffer, uint16 *pSize );
Ucl_ReturnType UclCmnRingBuffer_GetFillCnt ( SUclCmnRingBuffer *pRB, uint16 *pSize );
Ucl_ReturnType UclCmnRingBuffer_IndexedRead ( SUclCmnRingBuffer *pRB, uint8 *pBuffer, uint16 *pSize, uint16 Index );

#endif //UCLCMNRINGBUFFER_H
