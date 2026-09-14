//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2017] Visteon Corporation
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

#ifndef BYTE_ORDER_H
#define BYTE_ORDER_H

#define DK_LITTLE_ENDIAN 1234u
#define DK_BIG_ENDIAN 4321u

#define DK_FLOAT_SERIALIZE_STRING 0u
#define DK_FLOAT_SERIALIZE_DIRECT 1u
#define DK_FLOAT_SERIALIZE_SPLIT 2u

#define DK_SERIALIZE_FL_NAN (0x40000000u)
#define DK_SERIALIZE_FL_PINF (0x20000000u)
#define DK_SERIALIZE_FL_NINF (0x10000000u)
#define DK_SERIALIZE_FL_MASK (0xE0000000u)
#define DK_FRAC_MAX 9223372036854775807LL /* 2**63 - 1 */

#ifndef DK_BYTE_ORDER
#define DK_BYTE_ORDER DK_LITTLE_ENDIAN
#endif

#ifndef DK_FLOAT_SERIALIZE
#define DK_FLOAT_SERIALIZE DK_FLOAT_SERIALIZE_DIRECT
#endif

#if DK_BYTE_ORDER == DK_LITTLE_ENDIAN

#define DK_BYTES_TO_WORD(x0, x1) (uint16_t((x0) << 8 | (x1)))
#define DK_BYTES_TO_LONG(x0, x1, x2, x3) (uint32_t((x0) << 24 | (x1) << 16 | (x2) << 8 | (x3)))
#define DK_BYTES_TO_LONGLONG(x0, x1, x2, x3, x4, x5, x6, x7)                                              \
	(uint64_t((uint64_t)(x0) << 56 | (uint64_t)(x1) << 48 | (uint64_t)(x2) << 40 | (uint64_t)(x3) << 32 | \
			  (uint64_t)(x4) << 24 | (uint64_t)(x5) << 16 | (uint64_t)(x6) << 8 | (uint64_t)(x7)))

#define DK_WORDS_TO_LONG(x0, x1) (uint32_t((x0) << 16 | (x1)))

#define DK_WORD_BYTE0(x) (uint8_t((x)&0xFF))
#define DK_WORD_BYTE1(x) (uint8_t((x) >> 8))

#define DK_LONG_BYTE0(x) (uint8_t((x)&0xFF))
#define DK_LONG_BYTE1(x) (uint8_t(((x) >> 8) & 0xFF))
#define DK_LONG_BYTE2(x) (uint8_t(((x) >> 16) & 0xFF))
#define DK_LONG_BYTE3(x) (uint8_t(((x) >> 24) & 0xFF))

#define DK_LL_BYTE0(x) (uint8_t((x)&0xFF))
#define DK_LL_BYTE1(x) (uint8_t(((x) >> 8) & 0xFF))
#define DK_LL_BYTE2(x) (uint8_t(((x) >> 16) & 0xFF))
#define DK_LL_BYTE3(x) (uint8_t(((x) >> 24) & 0xFF))
#define DK_LL_BYTE4(x) (uint8_t(((x) >> 32) & 0xFF))
#define DK_LL_BYTE5(x) (uint8_t(((x) >> 40) & 0xFF))
#define DK_LL_BYTE6(x) (uint8_t(((x) >> 48) & 0xFF))
#define DK_LL_BYTE7(x) (uint8_t(((x) >> 56) & 0xFF))

#define DK_LONG_WORD0(x) (uint16_t((x)&0xFFFF))
#define DK_LONG_WORD1(x) (uint16_t(((x) >> 16) & 0xFFFF))

#elif DK_BYTE_ORDER == DK_BIG_ENDIAN

#define DK_BYTES_TO_WORD(x0, x1) (uint16_t((x1) << 8 | (x0)))
#define DK_BYTES_TO_LONG(x0, x1, x2, x3) (uint32_t((x3) << 24 | (x2) << 16 | (x1) << 8 | (x0)))
#define DK_BYTES_TO_LONGLONG(x0, x1, x2, x3, x4, x5, x6, x7)                                              \
	(uint64_t((uint64_t)(x7) << 56 | (uint64_t)(x6) << 48 | (uint64_t)(x5) << 40 | (uint64_t)(x4) << 32 | \
			  (uint64_t)(x3) << 24 | (uint64_t)(x2) << 16 | (uint64_t)(x1) << 8 | (uint64_t)(x0)))

#define DK_WORD_BYTE0(x) (uint8_t((x) >> 8))
#define DK_WORD_BYTE1(x) (uint8_t((x)&0xFF))

#define DK_LONG_BYTE0(x) (uint8_t(((x) >> 24) & 0xFF))
#define DK_LONG_BYTE1(x) (uint8_t(((x) >> 16) & 0xFF))
#define DK_LONG_BYTE2(x) (uint8_t(((x) >> 8) & 0xFF))
#define DK_LONG_BYTE3(x) (uint8_t(((x)) & 0xFF))

#define DK_LL_BYTE0(x) (uint8_t(((x) >> 56) & 0xFF))
#define DK_LL_BYTE1(x) (uint8_t(((x) >> 48) & 0xFF))
#define DK_LL_BYTE2(x) (uint8_t(((x) >> 40) & 0xFF))
#define DK_LL_BYTE3(x) (uint8_t(((x) >> 32) & 0xFF))
#define DK_LL_BYTE4(x) (uint8_t(((x) >> 24) & 0xFF))
#define DK_LL_BYTE5(x) (uint8_t(((x) >> 16) & 0xFF))
#define DK_LL_BYTE6(x) (uint8_t(((x) >> 8) & 0xFF))
#define DK_LL_BYTE7(x) (uint8_t(((x)) & 0xFF))

#define DK_LONG_WORD0(x) (uint16_t((((x) >> 16) & 0xFFFF))
#define DK_LONG_WORD1(x) (uint16_t(((x) & 0xFFFF))

#else
#error "DK_BYTE_ORDER_DK not defined"
#endif //DK_BYTE_ORDER_DK

#endif //BYTE_ORDER_H
