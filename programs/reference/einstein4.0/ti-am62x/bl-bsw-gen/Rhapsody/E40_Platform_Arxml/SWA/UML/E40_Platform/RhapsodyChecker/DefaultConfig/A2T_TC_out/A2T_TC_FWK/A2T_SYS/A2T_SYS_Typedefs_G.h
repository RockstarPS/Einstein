#ifndef __A2T_SYS_Typedefs_G_h__
#define __A2T_SYS_Typedefs_G_h__
#ifndef _QAC_
// *********************************************************************************************************************
// Company:             Johnson Controls Inc.
// ---------------------------------------------------------------------------------------------------------------------
// Copyright:           This software is JCI property.
//                      Duplication or disclosure without JCI written authorization is prohibited.
// ---------------------------------------------------------------------------------------------------------------------
// Project:             E40_Platform
// Language:            C
// ---------------------------------------------------------------------------------------------------------------------
// This file contains package types definition
// ---------------------------------------------------------------------------------------------------------------------
// Generated on Tue Aug 06 13:07:41 IST 2024 by the JCI UML Generation chain from the "E40_Platform" model.
// ---------------------------------------------------------------------------------------------------------------------
// Entity:              A2T_SYS (DesignUnit)
// Description:         None
// Owner:               A2T_TC_FWK (Package)
// ---------------------------------------------------------------------------------------------------------------------
// Rhapsody version:    9.0.1
// Generator version:   V3.0.27
// Generator date:      11/12/2014 12:04:26,40
// ---------------------------------------------------------------------------------------------------------------------
// PVCS section start
// PVCS Log:
// $Log: $
// PVCS section end
// *********************************************************************************************************************
#endif // #ifndef _QAC_

// ---------------------------------------------------------------------------------------------------------------------
//                                                   Types definition
// ---------------------------------------------------------------------------------------------------------------------

// Typedef type boolean
#ifndef A2T_TypesProtection_boolean
#define A2T_TypesProtection_boolean
// ---------------------------------------------------------------------------------------------------------------------
// 1-bit, 0- FALSE, othersize TRUE
// ---------------------------------------------------------------------------------------------------------------------
typedef unsigned char boolean;
#define tboolean boolean
#endif

// Typedef type boolean_Ref
#ifndef A2T_TypesProtection_boolean_Ref
#define A2T_TypesProtection_boolean_Ref
typedef boolean* boolean_Ref;
#define tboolean_Ref boolean_Ref
#endif

// Typedef type float32
#ifndef A2T_TypesProtection_float32
#define A2T_TypesProtection_float32
// ---------------------------------------------------------------------------------------------------------------------
// 32-bit floating point
// ---------------------------------------------------------------------------------------------------------------------
typedef float float32;
#define tfloat32 float32
#endif

// Typedef type float32_Ref
#ifndef A2T_TypesProtection_float32_Ref
#define A2T_TypesProtection_float32_Ref
typedef float32* float32_Ref;
#define tfloat32_Ref float32_Ref
#endif

// Typedef type float64
#ifndef A2T_TypesProtection_float64
#define A2T_TypesProtection_float64
// ---------------------------------------------------------------------------------------------------------------------
// 64-bit floating point
// ---------------------------------------------------------------------------------------------------------------------
typedef double float64;
#define tfloat64 float64
#endif

// Typedef type float64_Ref
#ifndef A2T_TypesProtection_float64_Ref
#define A2T_TypesProtection_float64_Ref
typedef float64* float64_Ref;
#define tfloat64_Ref float64_Ref
#endif

// Typedef type sint16
#ifndef A2T_TypesProtection_sint16
#define A2T_TypesProtection_sint16
// ---------------------------------------------------------------------------------------------------------------------
// 16-bit signed integer
// ---------------------------------------------------------------------------------------------------------------------
typedef short sint16;
#define tsint16 sint16
#endif

// Typedef type sint16_Ref
#ifndef A2T_TypesProtection_sint16_Ref
#define A2T_TypesProtection_sint16_Ref
typedef sint16* sint16_Ref;
#define tsint16_Ref sint16_Ref
#endif

// Typedef type sint32
#ifndef A2T_TypesProtection_sint32
#define A2T_TypesProtection_sint32
// ---------------------------------------------------------------------------------------------------------------------
// 32-bit signed integer
// ---------------------------------------------------------------------------------------------------------------------
typedef long sint32;
#define tsint32 sint32
#endif

// Typedef type sint32_Ref
#ifndef A2T_TypesProtection_sint32_Ref
#define A2T_TypesProtection_sint32_Ref
typedef sint32* sint32_Ref;
#define tsint32_Ref sint32_Ref
#endif

// Typedef type sint64
#ifndef A2T_TypesProtection_sint64
#define A2T_TypesProtection_sint64
// ---------------------------------------------------------------------------------------------------------------------
// 64-bit signed integer, signed long long
// Some compilers map long long to 32-bit long.
// ---------------------------------------------------------------------------------------------------------------------
typedef long sint64;
#define tsint64 sint64
#endif

// Typedef type sint64_Ref
#ifndef A2T_TypesProtection_sint64_Ref
#define A2T_TypesProtection_sint64_Ref
typedef sint64* sint64_Ref;
#define tsint64_Ref sint64_Ref
#endif

// Typedef type sint8
#ifndef A2T_TypesProtection_sint8
#define A2T_TypesProtection_sint8
// ---------------------------------------------------------------------------------------------------------------------
// 8-bit signed integer
// ---------------------------------------------------------------------------------------------------------------------
typedef char sint8;
#define tsint8 sint8
#endif

// Typedef type sint8_Ref
#ifndef A2T_TypesProtection_sint8_Ref
#define A2T_TypesProtection_sint8_Ref
typedef sint8* sint8_Ref;
#define tsint8_Ref sint8_Ref
#endif

// Typedef type uint16
#ifndef A2T_TypesProtection_uint16
#define A2T_TypesProtection_uint16
// ---------------------------------------------------------------------------------------------------------------------
// 16-bit unsigned integer
// ---------------------------------------------------------------------------------------------------------------------
typedef unsigned short uint16;
#define tuint16 uint16
#endif

// Typedef type uint16_Ref
#ifndef A2T_TypesProtection_uint16_Ref
#define A2T_TypesProtection_uint16_Ref
typedef uint16* uint16_Ref;
#define tuint16_Ref uint16_Ref
#endif

// Typedef type uint32
#ifndef A2T_TypesProtection_uint32
#define A2T_TypesProtection_uint32
// ---------------------------------------------------------------------------------------------------------------------
// 32-bit unsigned integer
// ---------------------------------------------------------------------------------------------------------------------
typedef unsigned long uint32;
#define tuint32 uint32
#endif

// Typedef type uint32_Ref
#ifndef A2T_TypesProtection_uint32_Ref
#define A2T_TypesProtection_uint32_Ref
typedef uint32* uint32_Ref;
#define tuint32_Ref uint32_Ref
#endif

// Typedef type uint64
#ifndef A2T_TypesProtection_uint64
#define A2T_TypesProtection_uint64
// ---------------------------------------------------------------------------------------------------------------------
// 64-bit unsigned integer, unsigned long long
// Some compilers map long long to 32-bit long.
// ---------------------------------------------------------------------------------------------------------------------
typedef long uint64;
#define tuint64 uint64
#endif

// Typedef type uint64_Ref
#ifndef A2T_TypesProtection_uint64_Ref
#define A2T_TypesProtection_uint64_Ref
typedef uint64* uint64_Ref;
#define tuint64_Ref uint64_Ref
#endif

// Typedef type uint8
#ifndef A2T_TypesProtection_uint8
#define A2T_TypesProtection_uint8
// ---------------------------------------------------------------------------------------------------------------------
// 8-bit unsigned integer
// ---------------------------------------------------------------------------------------------------------------------
typedef unsigned char uint8;
#define tuint8 uint8
#endif

// Typedef type uint8_Ref
#ifndef A2T_TypesProtection_uint8_Ref
#define A2T_TypesProtection_uint8_Ref
typedef uint8* uint8_Ref;
#define tuint8_Ref uint8_Ref
#endif

// Language type cFalse
#ifndef A2T_TypesProtection_cFalse
#define A2T_TypesProtection_cFalse
#define cFalse  ((boolean)(0==1))
#endif

// Language type cTrue
#ifndef A2T_TypesProtection_cTrue
#define A2T_TypesProtection_cTrue
#define cTrue   ((boolean)(1==1))
#endif

// Language type UNREFERENCED_PARAMETER
#ifndef A2T_TypesProtection_UNREFERENCED_PARAMETER
#define A2T_TypesProtection_UNREFERENCED_PARAMETER
#define UNREFERENCED_PARAMETER(x) ((void)x)
#ifdef _QAC_
// QAC warnings justification; warning 3112: " This statement has no side-effect - it can be removed."
#pragma PRQA_MACRO_MESSAGES_OFF "UNREFERENCED_PARAMETER",3112
#endif // #ifdef _QAC_
#endif

// Typedef type EventID
#ifndef A2T_TypesProtection_EventID
#define A2T_TypesProtection_EventID
// ---------------------------------------------------------------------------------------------------------------------
// This is the event identifier.
// ---------------------------------------------------------------------------------------------------------------------
typedef uint16 EventID;
#define tEventID EventID
#endif

// Structure type Event
#ifndef A2T_TypesProtection_Event
#define A2T_TypesProtection_Event
// ---------------------------------------------------------------------------------------------------------------------
// Event structure
// ---------------------------------------------------------------------------------------------------------------------
typedef struct _Event_tag {
//  ID of the event
    EventID ID;
} Event;
#define tEvent Event
#endif

// Typedef type Event_Ref
#ifndef A2T_TypesProtection_Event_Ref
#define A2T_TypesProtection_Event_Ref
// ---------------------------------------------------------------------------------------------------------------------
// Reference to an event
// ---------------------------------------------------------------------------------------------------------------------
typedef Event* Event_Ref;
#define tEvent_Ref Event_Ref
#endif

// Enumeration type BOOL_TYPE
#ifndef A2T_TypesProtection_BOOL_TYPE
#define A2T_TypesProtection_BOOL_TYPE
// ---------------------------------------------------------------------------------------------------------------------
// Type for boolean compilation directive
// ---------------------------------------------------------------------------------------------------------------------
typedef enum {
    DBG_TRUE,
    DBG_FALSE
} BOOL_TYPE;
#define eDBG_TRUE DBG_TRUE
#define eDBG_FALSE DBG_FALSE
#define tBOOL_TYPE BOOL_TYPE
#endif

// Language type TRUE
#ifndef A2T_TypesProtection_TRUE
#define A2T_TypesProtection_TRUE
// ---------------------------------------------------------------------------------------------------------------------
// BOOL_TYPE value used by compilation directive
// ---------------------------------------------------------------------------------------------------------------------
#define TRUE   cTrue
#endif

// Language type FALSE
#ifndef A2T_TypesProtection_FALSE
#define A2T_TypesProtection_FALSE
// ---------------------------------------------------------------------------------------------------------------------
// BOOL_TYPE value used by compilation directive
// ---------------------------------------------------------------------------------------------------------------------
#define FALSE   cFalse
#endif

// Language type cNumberOfBitsPerByte
#ifndef A2T_TypesProtection_cNumberOfBitsPerByte
#define A2T_TypesProtection_cNumberOfBitsPerByte
#define cNumberOfBitsPerByte ((uint8)(0x08))
#endif

// Typedef type Std_ReturnType
#ifndef A2T_TypesProtection_Std_ReturnType
#define A2T_TypesProtection_Std_ReturnType
typedef uint8 Std_ReturnType;
#define tStd_ReturnType Std_ReturnType
#endif

// Typedef type SysReturnType
#ifndef A2T_TypesProtection_SysReturnType
#define A2T_TypesProtection_SysReturnType
// ---------------------------------------------------------------------------------------------------------------------
// Platform dependent integer type, representing enumerator of possible status codes of the executed function call
// ---------------------------------------------------------------------------------------------------------------------
typedef uint8 SysReturnType;
#define tSysReturnType SysReturnType
#endif

// Language type SysReturn_Fail
#ifndef A2T_TypesProtection_SysReturn_Fail
#define A2T_TypesProtection_SysReturn_Fail
#define SysReturn_Fail ((SysReturnType)0x01)
#endif

// Language type SysReturn_Ok
#ifndef A2T_TypesProtection_SysReturn_Ok
#define A2T_TypesProtection_SysReturn_Ok
#define SysReturn_Ok ((SysReturnType)0x00)
#endif

// Language type SysReturn_Wait
#ifndef A2T_TypesProtection_SysReturn_Wait
#define A2T_TypesProtection_SysReturn_Wait
#define SysReturn_Wait ((SysReturnType)0x82)
#endif

// Language type E_OK
#ifndef A2T_TypesProtection_E_OK
#define A2T_TypesProtection_E_OK
#define E_OK ((Std_ReturnType)0x00)
#endif

// Language type E_NOT_OK
#ifndef A2T_TypesProtection_E_NOT_OK
#define A2T_TypesProtection_E_NOT_OK
#define E_NOT_OK ((Std_ReturnType)0x01)
#endif

// Language type mIsSysReturnOk
#ifndef A2T_TypesProtection_mIsSysReturnOk
#define A2T_TypesProtection_mIsSysReturnOk
#define mIsSysReturnOk(SysReturn)    ((SysReturn&0xBF)==0x00)
#endif

// Language type mIsSysReturnFail
#ifndef A2T_TypesProtection_mIsSysReturnFail
#define A2T_TypesProtection_mIsSysReturnFail
#define mIsSysReturnFail(SysReturn)    ((SysReturn&0xBF)!=0x00)
#endif

// Language type mIsSysReturnWait
#ifndef A2T_TypesProtection_mIsSysReturnWait
#define A2T_TypesProtection_mIsSysReturnWait
#define mIsSysReturnWait(SysReturn)    (((SysReturn&0x82)!=0x00) && ((SysReturn&0x3C)==0x00))
#endif

// Language type TypeMinMaxDefines
#ifndef A2T_TypesProtection_TypeMinMaxDefines
#define A2T_TypesProtection_TypeMinMaxDefines
// ---------------------------------------------------------------------------------------------------------------------
// Defines for int types min/max values.
// Similar to limits.h C stdlib.
// ---------------------------------------------------------------------------------------------------------------------
#define cUint8Max    ((uint8)0xFF)

#define cUint16Max    ((uint16)0xFFFF)    

#define cUint32Max    ((uint32)0XFFFFFFFF)

#define cSint8Min    ((sint8)0X80)
#define cSint8Max    ((sint8)0x7F)

#define cSint16Min    ((sint16)0x8000)
#define cSint16Max    ((sint16)0x7FFF)

#define cSint32Min    ((sint32)0x80000000)
#define cSint32Max    ((sint32)0x7FFFFFFF)
#endif

// Language type AS_STD_TYPES_PROTECTION
#ifndef A2T_TypesProtection_AS_STD_TYPES_PROTECTION
#define A2T_TypesProtection_AS_STD_TYPES_PROTECTION
#define COMPILER_H
#define PLATFORM_TYPES_H
#endif

// *********************************************************************************************************************
//                                                   End of file body
// *********************************************************************************************************************
#endif // #define __A2T_SYS_Typedefs_G_h__
