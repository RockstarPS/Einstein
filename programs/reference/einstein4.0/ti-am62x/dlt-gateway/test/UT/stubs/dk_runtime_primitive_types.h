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

#ifndef PRIMITIVE_TYPES_H
#define PRIMITIVE_TYPES_H

#include <cstdint>
#include <typeinfo>

typedef unsigned long				_GCC_ATTR_ALIGN_u32t;
typedef signed long					_GCC_ATTR_ALIGN_32t;
typedef _GCC_ATTR_ALIGN_u32t		_Uint32t;
typedef _GCC_ATTR_ALIGN_32t			_Int32t;

typedef signed short				_GCC_ATTR_ALIGN_16t;
typedef unsigned short				_GCC_ATTR_ALIGN_u16t;
typedef _GCC_ATTR_ALIGN_u16t		_Uint16t;
typedef _GCC_ATTR_ALIGN_16t			_Int16t;

typedef signed char					_GCC_ATTR_ALIGN_8t;
typedef unsigned char				_GCC_ATTR_ALIGN_u8t;
typedef _GCC_ATTR_ALIGN_u8t			_Uint8t;
typedef _GCC_ATTR_ALIGN_8t			_Int8t;

typedef uint8_t byte_t;
typedef bool bool_t;
typedef float float32_t;
typedef double float64_t;
typedef char char8_t;

#endif //PRIMITIVE_TYPES_H
