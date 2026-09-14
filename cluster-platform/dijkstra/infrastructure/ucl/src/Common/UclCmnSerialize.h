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
#ifndef UCLCMNSERIALIZE_H
#define UCLCMNSERIALIZE_H
#ifdef __cplusplus
extern "C"
{
#endif

#include "Ucl_Types.h"

#define UCLCMNSERIALIZE_FL_NAN (0x40000000u)
#define UCLCMNSERIALIZE_FL_PINF (0x20000000u)
#define UCLCMNSERIALIZE_FL_NINF (0x10000000u)
#define UCLCMNSERIALIZE_FL_MASK (0xE0000000u)

Ucl_ReturnType UclCmnSerialize_uint8(uint8 data, uint8 *pBuffer, uint16 *pBytesCopied);
Ucl_ReturnType UclCmnSerialize_boolean(uint8 data, uint8 *pBuffer, uint16 *pBytesCopied);
Ucl_ReturnType UclCmnSerialize_uint16(uint16 data, uint8 *pBuffer, uint16 *pBytesCopied);
Ucl_ReturnType UclCmnSerialize_uint32(uint32 data, uint8 *pBuffer, uint16 *pBytesCopied);
Ucl_ReturnType UclCmnSerialize_uint64(uint64 data, uint8 *pBuffer, uint16 *pBytesCopied);
Ucl_ReturnType UclCmnSerialize_sint8(sint8 data, uint8 *pBuffer, uint16 *pBytesCopied);
Ucl_ReturnType UclCmnSerialize_sint16(sint16 data, uint8 *pBuffer, uint16 *pBytesCopied);
Ucl_ReturnType UclCmnSerialize_sint32(sint32 data, uint8 *pBuffer, uint16 *pBytesCopied);
Ucl_ReturnType UclCmnSerialize_sint64(sint64 data, uint8 *pBuffer, uint16 *pBytesCopied);
Ucl_ReturnType UclCmnSerialize_float32(float32 data, uint8 *pBuffer, uint16 *pBytesCopied);
Ucl_ReturnType UclCmnSerialize_float64(float64 data, uint8 *pBuffer, uint16 *pBytesCopied);

Ucl_ReturnType UclCmnDeserialize_uint8(uint8 *data, uint8 *pBuffer, uint16 *pBytesConsumed);
Ucl_ReturnType UclCmnDeserialize_boolean(uint8 *data, uint8 *pBuffer, uint16 *pBytesConsumed);
Ucl_ReturnType UclCmnDeserialize_uint16(uint16 *data, uint8 *pBuffer, uint16 *pBytesConsumed);
Ucl_ReturnType UclCmnDeserialize_uint32(uint32 *data, uint8 *pBuffer, uint16 *pBytesConsumed);
Ucl_ReturnType UclCmnDeserialize_uint64(uint64 *data, uint8 *pBuffer, uint16 *pBytesConsumed);
Ucl_ReturnType UclCmnDeserialize_sint8(sint8 *data, uint8 *pBuffer, uint16 *pBytesConsumed);
Ucl_ReturnType UclCmnDeserialize_sint16(sint16 *data, uint8 *pBuffer, uint16 *pBytesConsumed);
Ucl_ReturnType UclCmnDeserialize_sint32(sint32 *data, uint8 *pBuffer, uint16 *pBytesConsumed);
Ucl_ReturnType UclCmnDeserialize_sint64(sint64 *data, uint8 *pBuffer, uint16 *pBytesConsumed);
Ucl_ReturnType UclCmnDeserialize_float32(float32 *data, uint8 *pBuffer, uint16 *pBytesConsumed);
Ucl_ReturnType UclCmnDeserialize_float64(float64 *data, uint8 *pBuffer, uint16 *pBytesConsumed);

#ifdef __cplusplus
}
#endif
#endif //UCLCMNSERIALIZE_H
