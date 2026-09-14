#ifndef tmwtypes_h
#define tmwtypes_h

/* Matlab Types defined for embedding
 *
 * Jim Mikola
 * Mike Haggerty
 *
 * Visteon Corporation
 * Copyright 2003
 */

#ifndef __TMWTYPES__
#define __TMWTYPES__

#define INT8_T char
typedef INT8_T int8_T;

#define UINT8_T unsigned char
typedef UINT8_T uint8_T;

#define INT16_T short
typedef INT16_T int16_T;

#define UINT16_T unsigned short
typedef UINT16_T uint16_T;

#define INT32_T long
typedef INT32_T int32_T;

#define UINT32_T unsigned long
typedef UINT32_T uint32_T;

#ifdef HMI_ALLOW_64_BIT_TYPES
	#define INT64_T long long
	typedef INT64_T int64_T;

	#define UINT64_T unsigned long long
	typedef UINT64_T uint64_T;
#endif

#define BOOLEAN_T unsigned char
typedef BOOLEAN_T boolean_T;

#define CHARACTER_T char
typedef CHARACTER_T char_T;

#define INTEGER_T int
typedef INTEGER_T int_T;

#define UINTEGER_T unsigned
typedef UINTEGER_T uint_T;

#define BYTE_T unsigned char
typedef BYTE_T byte_T;


#define  MAX_int8_T      ((int8_T)(127))            /* 127  */
#define  MIN_int8_T      ((int8_T)(-128))           /* -128 */
#define  MAX_uint8_T     ((uint8_T)(255))           /* 255  */
#define  MIN_uint8_T     ((uint8_T)(0))
                           
#define  MAX_int16_T     ((int16_T)(32767))         /* 32767 */
#define  MIN_int16_T     ((int16_T)(-32768))        /* -32768 */
#define  MAX_uint16_T    ((uint16_T)(65535))        /* 65535 */
#define  MIN_uint16_T    ((uint16_T)(0))
                           
#define  MAX_int32_T     ((int32_T)(2147483647))    /* 2147483647  */
#define  MIN_int32_T     ((int32_T)(-2147483647-1)) /* -2147483648 */
#define  MAX_uint32_T    ((uint32_T)(0xFFFFFFFFU))  /* 4294967295  */
#define  MIN_uint32_T    ((uint32_T)(0))

#endif  /* __TMWTYPES__ */

#endif /* tmwtypes_h */
