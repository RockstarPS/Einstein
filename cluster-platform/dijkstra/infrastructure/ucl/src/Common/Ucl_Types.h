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
/// @defgroup UclCmn
/// @brief UCL Common Libraries and Utilities
/// @file
/// @ingroup UclCmn
/// UCL Types and Error Codes
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCL_TYPES_H
#define UCL_TYPES_H

#if !defined(STD_TYPES_H) && !defined(TYPES_H) && !defined(PLATFORM_TYPES_H_)
    typedef unsigned char uint8;
    typedef unsigned short uint16;
    #if defined(__LP64__) || defined(__ILP32__)
        typedef unsigned int uint32;
        typedef signed int sint32;
    #else
        typedef unsigned long uint32;
        typedef signed long sint32;
    #endif
    typedef signed char sint8;
    typedef signed short sint16;
    typedef float float32;
    typedef double float64;
    typedef unsigned long long uint64;
    typedef signed long long sint64;

    #ifndef FALSE
        #define FALSE 0U
    #endif

    #ifndef TRUE
        #define TRUE 1U
    #endif

#endif
typedef char char8;

#ifndef NULL
    #define NULL ((void *)0)
#endif

#ifndef NULL_PTR
    #define NULL_PTR ((void *)0)
#endif

typedef sint32 Ucl_ReturnType;
///
/// @brief Requested operation completed successfully
///
#define UCL_E_OK ((Ucl_ReturnType) 0)
///
/// @brief Requested operation failed
///
#define UCL_E_NOK ((Ucl_ReturnType) -1)
///
/// @brief Requested operation cannot be done due to Invalid State
///
#define UCL_E_INVALID_STATE ((Ucl_ReturnType) -2)
///
/// @brief Requested operation cannot be done due to Invalid Arguments
///
#define UCL_E_INVALID_ARGS ((Ucl_ReturnType) -3)
///
/// @brief Resource Busy
///
#define UCL_E_BUSY ((Ucl_ReturnType) -4)
///
/// @brief Buffer Full Error
///
#define UCL_E_BUFFER_FULL ((Ucl_ReturnType) -5)
///
/// @brief Requested Operation is not supported
///
#define UCL_E_NOT_SUPPORTED ((Ucl_ReturnType) -6)
///
/// @brief Fatal error has happened
///
#define UCL_E_FATAL ((Ucl_ReturnType) -7)
///
/// @brief Security Violation. Time Synchronized Counter mismatch
///
#define UCL_E_SEC_TSC ((Ucl_ReturnType) -8)
///
/// @brief Security Violation. CMAC mismatch
///
#define UCL_E_SEC_CMAC ((Ucl_ReturnType) -9)
///
/// @brief Security Violation. Key negotiation failed
///
#define UCL_E_SEC_NEGO ((Ucl_ReturnType) -10)
///
/// @brief UCL Message transmit request is pending
///
#define UCL_E_MSG_PENDING ((Ucl_ReturnType) -25)
///
/// @brief Expected UCL Message is not received within timeout
///
#define UCL_E_MSG_MISSING ((Ucl_ReturnType) -26)
///
/// @brief UCL Message is acknowledged by the remote peer
///
#define UCL_E_MSG_ACK ((Ucl_ReturnType) -27)
///
/// @brief UCL Message is negatively acknowledged by the remote peer
///
#define UCL_E_MSG_NACK ((Ucl_ReturnType) -28)
///
/// @brief UCL Message acknowledgement is not received within timeout
///
#define UCL_E_MSG_ACK_TMO ((Ucl_ReturnType) -29)
///
/// @brief UCL Link Up
///
#define UCL_E_LINK_UP ((Ucl_ReturnType) -50)
///
/// @brief UCL Link Down
///
#define UCL_E_LINK_DOWN ((Ucl_ReturnType) -51)
///
/// @brief UCL Adapter Write Data Loss
///
#define UCL_E_DATA_LOSS ((Ucl_ReturnType) -52)
/// @brief UCL FD Queue Empty
///
#define UCL_E_FD_Q_EMPTY ((Ucl_ReturnType) -70)
/// @brief UCL FD Queue Full
///
#define UCL_E_FD_Q_FULL ((Ucl_ReturnType) -71)

/// @brief Notify Data loss
///
#define UCL_NOTIFY_DATA_LOSS  ((Ucl_ReturnType) -72)

#endif //UCL_TYPES_H
