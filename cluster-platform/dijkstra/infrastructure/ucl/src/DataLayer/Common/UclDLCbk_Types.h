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
/// @ingroup UclDL
/// UCL Data Layer Callback Type Definitions
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLDLCBKTYPES_H
#define UCLDLCBKTYPES_H

#include "Ucl_Types.h"
#include "UclDL_Types.h"
#ifdef __cplusplus
extern "C" {
#endif


///
/// @brief Acknowledgment status of the transmitted message
///
typedef enum 
{
    eUclDLAckStatus_Ok,      ///< Transmitted message was successfully acknowledged
    eUclDLAckStatus_Error,   ///< Transmitted message was not successfully acknowledged
    eUclDLAckStatus_Timeout, ///< No acknowledgment was received within the timeout
    eUclDLAckStatus_Last     ///< Guard
} EUclDLAckStatus;

///
/// @brief Status of the received message
///
typedef enum 
{
    eUclDLRxStatus_Ok,      ///< Received message was successfully verified
    eUclDLRxStatus_Error,   ///< Received message with verification failure
    eUclDLRxStatus_Missing, ///< Message not received within time
    eUclDLRxStatus_Last     ///< Guard
} EUclDLRxStatus;

///
/// @brief UclDL Link Status
///
typedef enum 
{
    eUclDLLinkStatus_Down, ///< UclDL Link is Down
    eUclDLLinkStatus_Up,   ///< UclDL Link is Up
    eUclDLLinkStatus_Last  ///< Guard
} EUclDLLinkStatus;

///
/// @brief UclDL Error Status
///
typedef uint8 EUclDLError; 

//MISRA C++-2008 Rule 2-13-4
#define  eUclDLError_FatalError         (EUclDLError) 0x00U  ///< UclDL Fatal Error
#define  eUclDLError_SecurityTSCError   (EUclDLError) 0x01U  ///< UclDL Security Error. TSC violation.
#define  eUclDLError_SecurityCMACError  (EUclDLError) 0x03U  ///< UclDL Security Error. CMAC failed.
#define  eUclDLError_SecurityNegoError  (EUclDLError) 0x02U  ///< UclDL Security Error. Key Negotiation failed.
#define  eUclDLError_Last               (EUclDLError) 0x4U    ///< Guard

#ifdef __cplusplus
}
#endif
#endif //UCLDLCBKTYPES_H
