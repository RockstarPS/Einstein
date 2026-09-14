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
// Date: Wed Sep 17 12:27:28 IST 2025
// User: SSRINI28
// Gateway: UCL_GW
// Configuration: Platform
// Project: Einstein4_Platform
// Message Catalogue version : 1.0.10
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
#define UCL_ERROR_NOTIFY
#define UCL_LINK_STATUS

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
#define Gx_PowerSystemState_Tx    mMsgGx( POWERSYSTEMSTATE )
#define Ex_PowerSystemState_Tx    mMsgEx( POWERSYSTEMSTATE )

#define Gx_PowerExtendShutdownTime_Tx    mMsgGx( POWEREXTENDSHUTDOWNTIME )
#define Ex_PowerExtendShutdownTime_Tx    mMsgEx( POWEREXTENDSHUTDOWNTIME )

#define Gx_PowerKeepSystemAwake_Tx    mMsgGx( POWERKEEPSYSTEMAWAKE )
#define Ex_PowerKeepSystemAwake_Tx    mMsgEx( POWERKEEPSYSTEMAWAKE )





#define Gx_HealthDomainHeartbeat_Tx    mMsgGx( HEALTHDOMAINHEARTBEAT )
#define Ex_HealthDomainHeartbeat_Tx    mMsgEx( HEALTHDOMAINHEARTBEAT )

#define Gx_HealthDomainFatalError_Tx    mMsgGx( HEALTHDOMAINFATALERROR )
#define Ex_HealthDomainFatalError_Tx    mMsgEx( HEALTHDOMAINFATALERROR )

#define Gx_HealthEventRecord_Tx    mMsgGx( HEALTHEVENTRECORD )
#define Ex_HealthEventRecord_Tx    mMsgEx( HEALTHEVENTRECORD )

#define Gx_HealthDumpHdrInfo_Tx    mMsgGx( HEALTHDUMPHDRINFO )
#define Ex_HealthDumpHdrInfo_Tx    mMsgEx( HEALTHDUMPHDRINFO )

#define Gx_HealthDumpData_Tx    mMsgGx( HEALTHDUMPDATA )
#define Ex_HealthDumpData_Tx    mMsgEx( HEALTHDUMPDATA )



#define Gx_DisplayCurrentState_Tx    mMsgGx( DISPLAYCURRENTSTATE )
#define Ex_DisplayCurrentState_Tx    mMsgEx( DISPLAYCURRENTSTATE )

#define Gx_EmmcErrorNotifier_Tx    mMsgGx( EMMCERRORNOTIFIER )
#define Ex_EmmcErrorNotifier_Tx    mMsgEx( EMMCERRORNOTIFIER )

#define Gx_WarningDisplayAvailable_Tx    mMsgGx( WARNINGDISPLAYAVAILABLE )
#define Ex_WarningDisplayAvailable_Tx    mMsgEx( WARNINGDISPLAYAVAILABLE )

#define Gx_WarningStatus_Tx    mMsgGx( WARNINGSTATUS )
#define Ex_WarningStatus_Tx    mMsgEx( WARNINGSTATUS )

#define Gx_SafeHMIReadyStatus_Tx    mMsgGx( SAFEHMIREADYSTATUS )
#define Ex_SafeHMIReadyStatus_Tx    mMsgEx( SAFEHMIREADYSTATUS )

#define Gx_MainHMIReadyStatus_Tx    mMsgGx( MAINHMIREADYSTATUS )
#define Ex_MainHMIReadyStatus_Tx    mMsgEx( MAINHMIREADYSTATUS )

#define Gx_UpdateShortServiceResp_Tx    mMsgGx( UPDATESHORTSERVICERESP )
#define Ex_UpdateShortServiceResp_Tx    mMsgEx( UPDATESHORTSERVICERESP )

#define Gx_DiagResponse_Tx    mMsgGx( DIAGRESPONSE )
#define Ex_DiagResponse_Tx    mMsgEx( DIAGRESPONSE )

#define Gx_DLTMessageReadAck_Tx    mMsgGx( DLTMESSAGEREADACK )
#define Ex_DLTMessageReadAck_Tx    mMsgEx( DLTMESSAGEREADACK )

#define Gx_DLTControlMessageRequest_Tx    mMsgGx( DLTCONTROLMESSAGEREQUEST )
#define Ex_DLTControlMessageRequest_Tx    mMsgEx( DLTCONTROLMESSAGEREQUEST )



//---------------------------------------------------------------------------------------------------------------------
// Rx messages - group & event identifiers
//---------------------------------------------------------------------------------------------------------------------
#define Gx_PowerSystemStateReqChange_Rx    mMsgGx( POWERSYSTEMSTATEREQCHANGE )
#define Ex_PowerSystemStateReqChange_Rx    mMsgEx( POWERSYSTEMSTATEREQCHANGE )

#define Gx_HealthDumpGetHdr_Rx    mMsgGx( HEALTHDUMPGETHDR )
#define Ex_HealthDumpGetHdr_Rx    mMsgEx( HEALTHDUMPGETHDR )

#define Gx_HealthDumpGetData_Rx    mMsgGx( HEALTHDUMPGETDATA )
#define Ex_HealthDumpGetData_Rx    mMsgEx( HEALTHDUMPGETDATA )

#define Gx_DisplaySetPower_Rx    mMsgGx( DISPLAYSETPOWER )
#define Ex_DisplaySetPower_Rx    mMsgEx( DISPLAYSETPOWER )

#define Gx_TT_Status_Rx    mMsgGx( TT_STATUS )
#define Ex_TT_Status_Rx    mMsgEx( TT_STATUS )

#define Gx_RTT_Toggle_Rx    mMsgGx( RTT_TOGGLE )
#define Ex_RTT_Toggle_Rx    mMsgEx( RTT_TOGGLE )

#define Gx_FRTT_Status_Rx    mMsgGx( FRTT_STATUS )
#define Ex_FRTT_Status_Rx    mMsgEx( FRTT_STATUS )

#define Gx_RTT_Icon_Rx    mMsgGx( RTT_ICON )
#define Ex_RTT_Icon_Rx    mMsgEx( RTT_ICON )

#define Gx_RTT_Status_Rx    mMsgGx( RTT_STATUS )
#define Ex_RTT_Status_Rx    mMsgEx( RTT_STATUS )

#define Gx_WarningExtDisplay_Rx    mMsgGx( WARNINGEXTDISPLAY )
#define Ex_WarningExtDisplay_Rx    mMsgEx( WARNINGEXTDISPLAY )

#define Gx_WarningDisplay_Rx    mMsgGx( WARNINGDISPLAY )
#define Ex_WarningDisplay_Rx    mMsgEx( WARNINGDISPLAY )

#define Gx_SlowGaugeInfo_Rx    mMsgGx( SLOWGAUGEINFO )
#define Ex_SlowGaugeInfo_Rx    mMsgEx( SLOWGAUGEINFO )

#define Gx_FastGaugeInfo_Rx    mMsgGx( FASTGAUGEINFO )
#define Ex_FastGaugeInfo_Rx    mMsgEx( FASTGAUGEINFO )

#define Gx_ShiftPosIndStatus_Rx    mMsgGx( SHIFTPOSINDSTATUS )
#define Ex_ShiftPosIndStatus_Rx    mMsgEx( SHIFTPOSINDSTATUS )

#define Gx_IlluminationData_Rx    mMsgGx( ILLUMINATIONDATA )
#define Ex_IlluminationData_Rx    mMsgEx( ILLUMINATIONDATA )

#define Gx_UpdateShortServiceReq_Rx    mMsgGx( UPDATESHORTSERVICEREQ )
#define Ex_UpdateShortServiceReq_Rx    mMsgEx( UPDATESHORTSERVICEREQ )

#define Gx_UpdateLongServiceReq_Rx    mMsgGx( UPDATELONGSERVICEREQ )
#define Ex_UpdateLongServiceReq_Rx    mMsgEx( UPDATELONGSERVICEREQ )

#define Gx_DiagDIDRequest_Rx    mMsgGx( DIAGDIDREQUEST )
#define Ex_DiagDIDRequest_Rx    mMsgEx( DIAGDIDREQUEST )

#define Gx_DiagIOCtrlRequest_Rx    mMsgGx( DIAGIOCTRLREQUEST )
#define Ex_DiagIOCtrlRequest_Rx    mMsgEx( DIAGIOCTRLREQUEST )

#define Gx_DiagRoutineRequest_Rx    mMsgGx( DIAGROUTINEREQUEST )
#define Ex_DiagRoutineRequest_Rx    mMsgEx( DIAGROUTINEREQUEST )

#define Gx_DLTMessageReadRequest_Rx    mMsgGx( DLTMESSAGEREADREQUEST )
#define Ex_DLTMessageReadRequest_Rx    mMsgEx( DLTMESSAGEREADREQUEST )

#define Gx_DLTControlMessageReponse_Rx    mMsgGx( DLTCONTROLMESSAGEREPONSE )
#define Ex_DLTControlMessageReponse_Rx    mMsgEx( DLTCONTROLMESSAGEREPONSE )


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

