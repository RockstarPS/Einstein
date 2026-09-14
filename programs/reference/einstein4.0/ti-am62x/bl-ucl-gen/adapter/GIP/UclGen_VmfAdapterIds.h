//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2022] Visteon Corporation
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
//---------------------------------------------------------------------------------------------------------------------
//
// File generated automatically using Visteon DiCore UCL configuration generator 1.3.3
// Date: Tue Oct 01 15:54:36 IST 2024
// User: KRAMESH5
// Gateway: UCL_GW
// Configuration: Platform_Recovery
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.2
//
//---------------------------------------------------------------------------------------------------------------------
#ifndef UCLGEN_VMFADAPTERIDS_H
#define UCLGEN_VMFADAPTERIDS_H

#ifdef __cplusplus
extern "C"
{
#endif


//---------------------------------------------------------------------------------------------------------------------
// Manually configurable section for enabling or disabling the following parameters
// USE_DK_RUNTIME   - switch between VMF only and Dijkstra Runtime format of the generated Group Ids and Event Ids,
//                    depending on the used configuration
// UCL_ERROR_NOTIFY - trigger notification for errors
// UCL_LINK_STATUS  - trigger notification for changes in the communication link
//---------------------------------------------------------------------------------------------------------------------
/// Start of user code : Manually configurable section for file UclGen_VmfAdapterIds.h

#define USE_DK_RUNTIME
// #define UCL_ERROR_NOTIFY
// #define UCL_LINK_STATUS

/// End of user code
//---------------------------------------------------------------------------------------------------------------------


#ifdef USE_DK_RUNTIME

#include <dk_runtime_messages.h>

#ifdef __cplusplus
#define mMsgGx( message )               static_cast <uint8_t> ((DK_MSG_##message) >> 8U)
#define mMsgEx( message )               static_cast <uint8_t> ((DK_MSG_##message) & 0xFFU)
#else
#define mMsgGx( message )               (uint8_t)((DK_MSG_##message) >> 8)
#define mMsgEx( message )               (uint8_t)((DK_MSG_##message) & 0xFF)
#endif

#else

#include <vmf_gen_messages.h>

#define mMsgGx( message )               VMF_MSG_##message##_GX
#define mMsgEx( message )               VMF_MSG_##message##_EX

#endif


//---------------------------------------------------------------------------------------------------------------------
// Tx messages - group & event identifiers
//---------------------------------------------------------------------------------------------------------------------
#define Gx_UpdateShortServiceResp_Tx    mMsgGx( UPDATESHORTSERVICERESP )
#define Ex_UpdateShortServiceResp_Tx    mMsgEx( UPDATESHORTSERVICERESP )



//---------------------------------------------------------------------------------------------------------------------
// Rx messages - group & event identifiers
//---------------------------------------------------------------------------------------------------------------------
#define Gx_UpdateShortServiceReq_Rx    mMsgGx( UPDATESHORTSERVICEREQ )
#define Ex_UpdateShortServiceReq_Rx    mMsgEx( UPDATESHORTSERVICEREQ )

#define Gx_UpdateLongServiceReq_Rx    mMsgGx( UPDATELONGSERVICEREQ )
#define Ex_UpdateLongServiceReq_Rx    mMsgEx( UPDATELONGSERVICEREQ )


//---------------------------------------------------------------------------------------------------------------------
// Status notifications - group & event identifiers
//---------------------------------------------------------------------------------------------------------------------
#ifdef  UCL_ERROR_NOTIFY
#define Gx_Ucl_Error_Notify_Rx    mMsgGx( UCLERRORNOTIFY )
#define Ex_Ucl_Error_Notify_Rx    mMsgEx( UCLERRORNOTIFY )
#endif

#ifdef UCL_LINK_STATUS
#define Gx_Ucl_Link_Status_Rx    mMsgGx( UCLLINKSTATUS )
#define Ex_Ucl_Link_Status_Rx    mMsgEx( UCLLINKSTATUS )
#endif



#ifdef __cplusplus
}
#endif

#endif //UCLGEN_VMFADAPTERIDS_H

