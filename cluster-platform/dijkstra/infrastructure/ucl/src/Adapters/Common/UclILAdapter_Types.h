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
/// @file
/// @ingroup UclILAdapter
/// UCL Adapter Layer Type Definitions
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLILADAPTERTYPES_H
#define UCLILADAPTERTYPES_H

#include "Ucl_Types.h" //MISRA C++-2008 Rule 16-0-1

#ifdef __cplusplus
extern "C" {
#endif


///
/// @brief UCL Transmit Adapter Data Retrieve Type
///
typedef enum {
    eUclILAdapterDataType_Retry,       ///< Adapter to return backup data
    eUclILAdapterDataType_OnChange,    ///< Adapter to return if the data is changed
    eUclILAdapterDataType_Always,      ///< Adapter to return the latest data, if available
    eUclILAdapterDataType_SendOnInit,  ///< Adapter to send the default value on Init
    eUclILAdapterDataType_Last         ///< Guard
} EUclILAdapterDataType;

///
/// @brief Adapter function for transmit signals
///
typedef uint8 (*TUclTxSignalAdapterFunc)(uint8 *pBuffer, uint16 *pBytesCopied, EUclILAdapterDataType returnType);

///
/// @brief Adapter function for transmit messages
///
typedef uint8 (*TUclTxMessageAdapterFunc)(uint8 *pBuffer, uint16 *pBytesCopied, EUclILAdapterDataType returnType);

///
/// @brief Adapter function for receive signals
///
typedef uint8 (*TUclRxSignalAdapterFunc)(uint8 *pBuffer, uint16 Size);

///
/// @brief Adapter function for receive messages
///
typedef uint8 (*TUclRxMessageAdapterFunc)(uint8 *pBuffer, uint16 Size);

#ifdef __cplusplus
}
#endif
#endif //UCLILADAPTERTYPES_H
