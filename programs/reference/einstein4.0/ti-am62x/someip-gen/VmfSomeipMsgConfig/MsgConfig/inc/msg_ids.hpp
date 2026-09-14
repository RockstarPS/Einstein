#ifndef MSG_IDS_GAC_HPP
#define MSG_IDS_GAC_HPP

#include <iostream>
#include <vector>
#include <vsomeip/vsomeip.hpp>

#define  msg_eventgroup_id (vsomeip::eventgroup_t) 0x4444
#define  msg_instance_id (vsomeip::instance_t) 0x1

//
// Platform
//
// VIP -> DI, IVI
#define SWC_service_id (vsomeip::service_t) 50
#define SWC_method_id  (vsomeip::method_t)  0
#define SWC_event_id   (vsomeip::event_t)   0x8000 + SWC_method_id


//
// Platform
//
// VIP -> DI, IVI
#define PowerSystemStateReqChange_service_id (vsomeip::service_t) 193
#define PowerSystemStateReqChange_method_id  (vsomeip::method_t)  0
#define PowerSystemStateReqChange_event_id   (vsomeip::event_t)   0x8000 + PowerSystemStateReqChange_method_id


//
// Platform
//
// VIP -> DI,IVI
#define IgnState_service_id (vsomeip::service_t) 64
#define IgnState_method_id  (vsomeip::method_t)  0
#define IgnState_event_id   (vsomeip::event_t)   0x8000 + IgnState_method_id


//
// Platform
//
// VIP -> DI, IVI
#define OAT_service_id (vsomeip::service_t) 54
#define OAT_method_id  (vsomeip::method_t)  8
#define OAT_event_id   (vsomeip::event_t)   0x8000 + OAT_method_id


//
// Platform
//
// VIP -> DI, IVI
#define TT_Status_service_id (vsomeip::service_t) 53
#define TT_Status_method_id  (vsomeip::method_t)  0
#define TT_Status_event_id   (vsomeip::event_t)   0x8000 + TT_Status_method_id


//
// Platform
//
// VIP -> DI, IVI
#define DiagDIDRequest_service_id (vsomeip::service_t) 57
#define DiagDIDRequest_method_id  (vsomeip::method_t)  0
#define DiagDIDRequest_event_id   (vsomeip::event_t)   0x8000 + DiagDIDRequest_method_id


//
// Platform
//
// VIP -> DI, IVI
#define DiagRoutineRequest_service_id (vsomeip::service_t) 57
#define DiagRoutineRequest_method_id  (vsomeip::method_t)  1
#define DiagRoutineRequest_event_id   (vsomeip::event_t)   0x8000 + DiagRoutineRequest_method_id


//
// Platform
//
// VIP -> DI, IVI
#define DiagIOCtrlRequest_service_id (vsomeip::service_t) 57
#define DiagIOCtrlRequest_method_id  (vsomeip::method_t)  2
#define DiagIOCtrlRequest_event_id   (vsomeip::event_t)   0x8000 + DiagIOCtrlRequest_method_id


//
// Platform
//
// VIP -> DI, IVI
#define ConfigRecordExt_service_id (vsomeip::service_t) 55
#define ConfigRecordExt_method_id  (vsomeip::method_t)  3
#define ConfigRecordExt_event_id   (vsomeip::event_t)   0x8000 + ConfigRecordExt_method_id


//
// Platform
//
// VIP -> DI, IVI
#define ConfigRecord_service_id (vsomeip::service_t) 55
#define ConfigRecord_method_id  (vsomeip::method_t)  4
#define ConfigRecord_event_id   (vsomeip::event_t)   0x8000 + ConfigRecord_method_id


//
// Platform
//
// VIP -> DI, IVI
#define PersRecord1byte_service_id (vsomeip::service_t) 55
#define PersRecord1byte_method_id  (vsomeip::method_t)  0
#define PersRecord1byte_event_id   (vsomeip::event_t)   0x8000 + PersRecord1byte_method_id


//
// Platform
//
// VIP -> DI
#define Odometer_service_id (vsomeip::service_t) 54
#define Odometer_method_id  (vsomeip::method_t)  3
#define Odometer_event_id   (vsomeip::event_t)   0x8000 + Odometer_method_id


//
// Platform
//
// DI, IVI -> VIP
#define PowerSystemState_service_id (vsomeip::service_t) 192
#define PowerSystemState_method_id  (vsomeip::method_t)  0
#define PowerSystemState_event_id   (vsomeip::event_t)   0x8000 + PowerSystemState_method_id


//
// Platform
//
// DI, IVI -> VIP
#define PowerExtendShutdownTime_service_id (vsomeip::service_t) 192
#define PowerExtendShutdownTime_method_id  (vsomeip::method_t)  1
#define PowerExtendShutdownTime_event_id   (vsomeip::event_t)   0x8000 + PowerExtendShutdownTime_method_id


//
// Platform
//
// VIP -> DI
#define SlowGaugeInfo_service_id (vsomeip::service_t) 54
#define SlowGaugeInfo_method_id  (vsomeip::method_t)  0
#define SlowGaugeInfo_event_id   (vsomeip::event_t)   0x8000 + SlowGaugeInfo_method_id


//
// Platform
//
// DI, IVI -> VIP
#define DiagResponse_service_id (vsomeip::service_t) 58
#define DiagResponse_method_id  (vsomeip::method_t)  0
#define DiagResponse_event_id   (vsomeip::event_t)   0x8000 + DiagResponse_method_id


//
// Platform
//
// DI, IVI -> VIP
#define PersRecord_service_id (vsomeip::service_t) 56
#define PersRecord_method_id  (vsomeip::method_t)  0
#define PersRecord_event_id   (vsomeip::event_t)   0x8000 + PersRecord_method_id


//
// Program
//
// DI -> IVI
#define DisplayLayoutIVIRenderReq_service_id (vsomeip::service_t) 238
#define DisplayLayoutIVIRenderReq_method_id  (vsomeip::method_t)  1
#define DisplayLayoutIVIRenderReq_event_id   (vsomeip::event_t)   0x8000 + DisplayLayoutIVIRenderReq_method_id


//
// Program
//
// DI -> IVI
#define PopupStatusMsg_service_id (vsomeip::service_t) 232
#define PopupStatusMsg_method_id  (vsomeip::method_t)  0
#define PopupStatusMsg_event_id   (vsomeip::event_t)   0x8000 + PopupStatusMsg_method_id


//
// Program
//
// DI -> IVI
#define UserSelectionMsg_service_id (vsomeip::service_t) 232
#define UserSelectionMsg_method_id  (vsomeip::method_t)  1
#define UserSelectionMsg_event_id   (vsomeip::event_t)   0x8000 + UserSelectionMsg_method_id


//
// Program
//
// DI -> IVI
#define PopupErrorMsg_service_id (vsomeip::service_t) 232
#define PopupErrorMsg_method_id  (vsomeip::method_t)  2
#define PopupErrorMsg_event_id   (vsomeip::event_t)   0x8000 + PopupErrorMsg_method_id


//
// Program
//
// VIP -> DI,IVI
#define IlluminationControlInitEventData_service_id (vsomeip::service_t) 87
#define IlluminationControlInitEventData_method_id  (vsomeip::method_t)  0
#define IlluminationControlInitEventData_event_id   (vsomeip::event_t)   0x8000 + IlluminationControlInitEventData_method_id


//
// Program
//
// VIP -> DI,IVI
#define RideModeCmd_service_id (vsomeip::service_t) 88
#define RideModeCmd_method_id  (vsomeip::method_t)  0
#define RideModeCmd_event_id   (vsomeip::event_t)   0x8000 + RideModeCmd_method_id


//
// Program
//
// VIP -> DI,IVI
#define RideModeTableAllIndex_service_id (vsomeip::service_t) 88
#define RideModeTableAllIndex_method_id  (vsomeip::method_t)  1
#define RideModeTableAllIndex_event_id   (vsomeip::event_t)   0x8000 + RideModeTableAllIndex_method_id


//
// Program
//
// VIP -> DI,IVI
#define RideModeTableOneIndex_service_id (vsomeip::service_t) 88
#define RideModeTableOneIndex_method_id  (vsomeip::method_t)  2
#define RideModeTableOneIndex_event_id   (vsomeip::event_t)   0x8000 + RideModeTableOneIndex_method_id


//
// Program
//
// VIP -> DI,IVI
#define DiagDIDSetResponse_service_id (vsomeip::service_t) 57
#define DiagDIDSetResponse_method_id  (vsomeip::method_t)  3
#define DiagDIDSetResponse_event_id   (vsomeip::event_t)   0x8000 + DiagDIDSetResponse_method_id


//
// Program
//
// DI -> IVI
#define DiagDIDRequestDomain_service_id (vsomeip::service_t) 235
#define DiagDIDRequestDomain_method_id  (vsomeip::method_t)  0
#define DiagDIDRequestDomain_event_id   (vsomeip::event_t)   0x8000 + DiagDIDRequestDomain_method_id


//
// Program
//
// DI -> IVI
#define DiagRoutineRequestDomain_service_id (vsomeip::service_t) 235
#define DiagRoutineRequestDomain_method_id  (vsomeip::method_t)  1
#define DiagRoutineRequestDomain_event_id   (vsomeip::event_t)   0x8000 + DiagRoutineRequestDomain_method_id


//
// Program
//
// DI -> IVI
#define DiagIOCtrlRequestDomain_service_id (vsomeip::service_t) 235
#define DiagIOCtrlRequestDomain_method_id  (vsomeip::method_t)  2
#define DiagIOCtrlRequestDomain_event_id   (vsomeip::event_t)   0x8000 + DiagIOCtrlRequestDomain_method_id


//
// Program
//
// VIP -> DI,IVI
#define PinStatus_service_id (vsomeip::service_t) 90
#define PinStatus_method_id  (vsomeip::method_t)  0
#define PinStatus_event_id   (vsomeip::event_t)   0x8000 + PinStatus_method_id


//
// Program
//
// DI -> DI,IVI
#define FactoryPrivacyResetDefaultToIVI_service_id (vsomeip::service_t) 237
#define FactoryPrivacyResetDefaultToIVI_method_id  (vsomeip::method_t)  0
#define FactoryPrivacyResetDefaultToIVI_event_id   (vsomeip::event_t)   0x8000 + FactoryPrivacyResetDefaultToIVI_method_id


//
// Program
//
// VIP -> DI,IVI
#define CalibDataResp_service_id (vsomeip::service_t) 236
#define CalibDataResp_method_id  (vsomeip::method_t)  4
#define CalibDataResp_event_id   (vsomeip::event_t)   0x8000 + CalibDataResp_method_id


//
// Program
//
// VIP -> DI,IVI
#define ETMEntrySubFnExitStatus_service_id (vsomeip::service_t) 236
#define ETMEntrySubFnExitStatus_method_id  (vsomeip::method_t)  5
#define ETMEntrySubFnExitStatus_event_id   (vsomeip::event_t)   0x8000 + ETMEntrySubFnExitStatus_method_id


//
// Program
//
// DI -> IVI
#define NavigateToPoi_service_id (vsomeip::service_t) 232
#define NavigateToPoi_method_id  (vsomeip::method_t)  3
#define NavigateToPoi_event_id   (vsomeip::event_t)   0x8000 + NavigateToPoi_method_id


//
// Program
//
// VIP -> DI,IVI
#define HomeLinkStatus_service_id (vsomeip::service_t) 236
#define HomeLinkStatus_method_id  (vsomeip::method_t)  9
#define HomeLinkStatus_event_id   (vsomeip::event_t)   0x8000 + HomeLinkStatus_method_id


//
// Program
//
// VIP -> DI,IVI
#define SBNProgramReq_service_id (vsomeip::service_t) 236
#define SBNProgramReq_method_id  (vsomeip::method_t)  8
#define SBNProgramReq_event_id   (vsomeip::event_t)   0x8000 + SBNProgramReq_method_id


//
// Program
//
// VIP -> DI,IVI
#define VariantConfigResp_service_id (vsomeip::service_t) 236
#define VariantConfigResp_method_id  (vsomeip::method_t)  7
#define VariantConfigResp_event_id   (vsomeip::event_t)   0x8000 + VariantConfigResp_method_id


//
// Program
//
// VIP -> DI,IVI
#define ETMStartupMetrics_service_id (vsomeip::service_t) 236
#define ETMStartupMetrics_method_id  (vsomeip::method_t)  6
#define ETMStartupMetrics_event_id   (vsomeip::event_t)   0x8000 + ETMStartupMetrics_method_id


//
// Program
//
// VIP -> DI,IVI
#define SWUpdateResetRequestStatus_service_id (vsomeip::service_t) 236
#define SWUpdateResetRequestStatus_method_id  (vsomeip::method_t)  12
#define SWUpdateResetRequestStatus_event_id   (vsomeip::event_t)   0x8000 + SWUpdateResetRequestStatus_method_id


//
// Program
//
// VIP -> DI,IVI
#define VoiceNaviRUIWidgetInfo_service_id (vsomeip::service_t) 242
#define VoiceNaviRUIWidgetInfo_method_id  (vsomeip::method_t)  0
#define VoiceNaviRUIWidgetInfo_event_id   (vsomeip::event_t)   0x8000 + VoiceNaviRUIWidgetInfo_method_id


//
// Program
//
// VIP -> DI,IVI
#define VoiceNaviRUIDistanceToEmpty_service_id (vsomeip::service_t) 242
#define VoiceNaviRUIDistanceToEmpty_method_id  (vsomeip::method_t)  1
#define VoiceNaviRUIDistanceToEmpty_event_id   (vsomeip::event_t)   0x8000 + VoiceNaviRUIDistanceToEmpty_method_id


//
// Program
//
// VIP -> Di,IVI
#define VoiceNaviRUIGearStatus_service_id (vsomeip::service_t) 242
#define VoiceNaviRUIGearStatus_method_id  (vsomeip::method_t)  2
#define VoiceNaviRUIGearStatus_event_id   (vsomeip::event_t)   0x8000 + VoiceNaviRUIGearStatus_method_id


//
// Program
//
// VIP -> DI,IVI
#define VoiceNaviRUIFastGuageInfo_service_id (vsomeip::service_t) 242
#define VoiceNaviRUIFastGuageInfo_method_id  (vsomeip::method_t)  3
#define VoiceNaviRUIFastGuageInfo_event_id   (vsomeip::event_t)   0x8000 + VoiceNaviRUIFastGuageInfo_method_id


//
// Program
//
// DI -> IVI
#define ETMSoCTemperature_service_id (vsomeip::service_t) 236
#define ETMSoCTemperature_method_id  (vsomeip::method_t)  13
#define ETMSoCTemperature_event_id   (vsomeip::event_t)   0x8000 + ETMSoCTemperature_method_id


//
// Program
//
// DI -> IVI
#define GeneralPurposeHmiData_service_id (vsomeip::service_t) 232
#define GeneralPurposeHmiData_method_id  (vsomeip::method_t)  4
#define GeneralPurposeHmiData_event_id   (vsomeip::event_t)   0x8000 + GeneralPurposeHmiData_method_id


//
// Program
//
// VIP -> DI,IVI
#define DiagSnapshotDIDRequest_service_id (vsomeip::service_t) 57
#define DiagSnapshotDIDRequest_method_id  (vsomeip::method_t)  5
#define DiagSnapshotDIDRequest_event_id   (vsomeip::event_t)   0x8000 + DiagSnapshotDIDRequest_method_id


//
// Program
//
// DI,IVI -> VIP
#define FeatureStatus_service_id (vsomeip::service_t) 74
#define FeatureStatus_method_id  (vsomeip::method_t)  1
#define FeatureStatus_event_id   (vsomeip::event_t)   0x8000 + FeatureStatus_method_id


//
// Program
//
// IVI -> DI
#define ClusterDisplayControlMsg_service_id (vsomeip::service_t) 231
#define ClusterDisplayControlMsg_method_id  (vsomeip::method_t)  0
#define ClusterDisplayControlMsg_event_id   (vsomeip::event_t)   0x8000 + ClusterDisplayControlMsg_method_id


//
// Program
//
// IVI -> DI
#define DisplayLayoutEventTrigger_service_id (vsomeip::service_t) 238
#define DisplayLayoutEventTrigger_method_id  (vsomeip::method_t)  0
#define DisplayLayoutEventTrigger_event_id   (vsomeip::event_t)   0x8000 + DisplayLayoutEventTrigger_method_id


//
// Program
//
// IVI -> DI
#define DisplayLayoutIVIRenderReadyStatus_service_id (vsomeip::service_t) 238
#define DisplayLayoutIVIRenderReadyStatus_method_id  (vsomeip::method_t)  2
#define DisplayLayoutIVIRenderReadyStatus_event_id   (vsomeip::event_t)   0x8000 + DisplayLayoutIVIRenderReadyStatus_method_id


//
// Program
//
// IVI -> DI
#define ShowPopupMsg_service_id (vsomeip::service_t) 233
#define ShowPopupMsg_method_id  (vsomeip::method_t)  0
#define ShowPopupMsg_event_id   (vsomeip::event_t)   0x8000 + ShowPopupMsg_method_id


//
// Program
//
// IVI -> DI
#define RemovePopupMsg_service_id (vsomeip::service_t) 233
#define RemovePopupMsg_method_id  (vsomeip::method_t)  1
#define RemovePopupMsg_event_id   (vsomeip::event_t)   0x8000 + RemovePopupMsg_method_id


//
// Program
//
// IVI -> DI
#define VolumeBarMsg_service_id (vsomeip::service_t) 234
#define VolumeBarMsg_method_id  (vsomeip::method_t)  0
#define VolumeBarMsg_event_id   (vsomeip::event_t)   0x8000 + VolumeBarMsg_method_id


//
// Program
//
// DI,IVI -> VIP
#define IlluminationMCData_service_id (vsomeip::service_t) 86
#define IlluminationMCData_method_id  (vsomeip::method_t)  0
#define IlluminationMCData_event_id   (vsomeip::event_t)   0x8000 + IlluminationMCData_method_id


//
// Program
//
// Di,IVI -> VIP
#define RideModeCustomization_service_id (vsomeip::service_t) 89
#define RideModeCustomization_method_id  (vsomeip::method_t)  1
#define RideModeCustomization_event_id   (vsomeip::event_t)   0x8000 + RideModeCustomization_method_id


//
// Program
//
// Di,IVI -> VIP
#define RideModeInitStatus_service_id (vsomeip::service_t) 89
#define RideModeInitStatus_method_id  (vsomeip::method_t)  2
#define RideModeInitStatus_event_id   (vsomeip::event_t)   0x8000 + RideModeInitStatus_method_id


//
// Program
//
// IVI -> DI
#define DiagResponseDomain_service_id (vsomeip::service_t) 57
#define DiagResponseDomain_method_id  (vsomeip::method_t)  4
#define DiagResponseDomain_event_id   (vsomeip::event_t)   0x8000 + DiagResponseDomain_method_id


//
// Program
//
// DI, IVI -> VIP
#define EnteredPinDigit_service_id (vsomeip::service_t) 90
#define EnteredPinDigit_method_id  (vsomeip::method_t)  1
#define EnteredPinDigit_event_id   (vsomeip::event_t)   0x8000 + EnteredPinDigit_method_id


//
// Program
//
// IVI -> VIP
#define EnterPinChangeMode_service_id (vsomeip::service_t) 90
#define EnterPinChangeMode_method_id  (vsomeip::method_t)  2
#define EnterPinChangeMode_event_id   (vsomeip::event_t)   0x8000 + EnterPinChangeMode_method_id


//
// Program
//
// IVI -> DI
#define FactoryPrivacyResetEventTrigger_service_id (vsomeip::service_t) 236
#define FactoryPrivacyResetEventTrigger_method_id  (vsomeip::method_t)  0
#define FactoryPrivacyResetEventTrigger_event_id   (vsomeip::event_t)   0x8000 + FactoryPrivacyResetEventTrigger_method_id


//
// Program
//
// DI,IVI -> DI
#define FactoryPrivacyIVIDefaultStatusFromIVI_service_id (vsomeip::service_t) 236
#define FactoryPrivacyIVIDefaultStatusFromIVI_method_id  (vsomeip::method_t)  2
#define FactoryPrivacyIVIDefaultStatusFromIVI_event_id   (vsomeip::event_t)   0x8000 + FactoryPrivacyIVIDefaultStatusFromIVI_method_id


//
// Program
//
// IVI -> VIP
#define CalibData_service_id (vsomeip::service_t) 93
#define CalibData_method_id  (vsomeip::method_t)  1
#define CalibData_event_id   (vsomeip::event_t)   0x8000 + CalibData_method_id


//
// Program
//
// IVI -> DI,VIP
#define ETMSubFnStatus_service_id (vsomeip::service_t) 239
#define ETMSubFnStatus_method_id  (vsomeip::method_t)  0
#define ETMSubFnStatus_event_id   (vsomeip::event_t)   0x8000 + ETMSubFnStatus_method_id


//
// Program
//
// IVI -> DI
#define MediaPlayingListMsg_service_id (vsomeip::service_t) 234
#define MediaPlayingListMsg_method_id  (vsomeip::method_t)  1
#define MediaPlayingListMsg_event_id   (vsomeip::event_t)   0x8000 + MediaPlayingListMsg_method_id


//
// Program
//
// IVI -> DI
#define WidgetInfofromIVI_service_id (vsomeip::service_t) 234
#define WidgetInfofromIVI_method_id  (vsomeip::method_t)  2
#define WidgetInfofromIVI_event_id   (vsomeip::event_t)   0x8000 + WidgetInfofromIVI_method_id


//
// Program
//
// IVI -> VIP
#define HomeLinkReq_service_id (vsomeip::service_t) 236
#define HomeLinkReq_method_id  (vsomeip::method_t)  10
#define HomeLinkReq_event_id   (vsomeip::event_t)   0x8000 + HomeLinkReq_method_id


//
// Program
//
// IVI -> VIP
#define VariantConfigData_service_id (vsomeip::service_t) 93
#define VariantConfigData_method_id  (vsomeip::method_t)  2
#define VariantConfigData_event_id   (vsomeip::event_t)   0x8000 + VariantConfigData_method_id


//
// Program
//
// IVI -> VIP
#define HomeLinkCurrentStatus_service_id (vsomeip::service_t) 236
#define HomeLinkCurrentStatus_method_id  (vsomeip::method_t)  11
#define HomeLinkCurrentStatus_event_id   (vsomeip::event_t)   0x8000 + HomeLinkCurrentStatus_method_id


//
// Program
//
// IVI -> VIP
#define RegulatorSync_service_id (vsomeip::service_t) 93
#define RegulatorSync_method_id  (vsomeip::method_t)  3
#define RegulatorSync_event_id   (vsomeip::event_t)   0x8000 + RegulatorSync_method_id


//
// Program
//
// IVI -> VIP
#define VoiceRequest_service_id (vsomeip::service_t) 240
#define VoiceRequest_method_id  (vsomeip::method_t)  0
#define VoiceRequest_event_id   (vsomeip::event_t)   0x8000 + VoiceRequest_method_id


//
// Program
//
// IVI -> VIP
#define SWUpdateResetRequest_service_id (vsomeip::service_t) 192
#define SWUpdateResetRequest_method_id  (vsomeip::method_t)  4
#define SWUpdateResetRequest_event_id   (vsomeip::event_t)   0x8000 + SWUpdateResetRequest_method_id


//
// Program
//
// IVI -> DI
#define NavigationSpeedLimiter_service_id (vsomeip::service_t) 241
#define NavigationSpeedLimiter_method_id  (vsomeip::method_t)  0
#define NavigationSpeedLimiter_event_id   (vsomeip::event_t)   0x8000 + NavigationSpeedLimiter_method_id


//
// Program
//
// IVI -> VIP
#define DiagSnapshotDIDResponse_service_id (vsomeip::service_t) 58
#define DiagSnapshotDIDResponse_method_id  (vsomeip::method_t)  2
#define DiagSnapshotDIDResponse_event_id   (vsomeip::event_t)   0x8000 + DiagSnapshotDIDResponse_method_id


//
// PlatformDC
//
// VIP -> DI,IVI
#define CANMessageSpecific1IDs_service_id (vsomeip::service_t) 85
#define CANMessageSpecific1IDs_method_id  (vsomeip::method_t)  0
#define CANMessageSpecific1IDs_event_id   (vsomeip::event_t)   0x8000 + CANMessageSpecific1IDs_method_id


//
// PlatformDC
//
// VIP -> DI
#define RTCUpdateTime_service_id (vsomeip::service_t) 199
#define RTCUpdateTime_method_id  (vsomeip::method_t)  13
#define RTCUpdateTime_event_id   (vsomeip::event_t)   0x8000 + RTCUpdateTime_method_id


//
// PlatformDC
//
// DI -> DI
#define RTCUpdateTimeHMI_service_id (vsomeip::service_t) 199
#define RTCUpdateTimeHMI_method_id  (vsomeip::method_t)  4
#define RTCUpdateTimeHMI_event_id   (vsomeip::event_t)   0x8000 + RTCUpdateTimeHMI_method_id


//
// PlatformDC
//
// DI -> VIP
#define RTCSetTime_service_id (vsomeip::service_t) 199
#define RTCSetTime_method_id  (vsomeip::method_t)  7
#define RTCSetTime_event_id   (vsomeip::event_t)   0x8000 + RTCSetTime_method_id


//
// PlatformDC
//
// DI -> VIP
#define RTCGetChipTime_service_id (vsomeip::service_t) 199
#define RTCGetChipTime_method_id  (vsomeip::method_t)  12
#define RTCGetChipTime_event_id   (vsomeip::event_t)   0x8000 + RTCGetChipTime_method_id


//
// PlatformDC
//
// VIP -> DI
#define V2DUpdateSourceUniqueIdentifier_service_id (vsomeip::service_t) 184
#define V2DUpdateSourceUniqueIdentifier_method_id  (vsomeip::method_t)  2
#define V2DUpdateSourceUniqueIdentifier_event_id   (vsomeip::event_t)   0x8000 + V2DUpdateSourceUniqueIdentifier_method_id


//
// PlatformDC
//
// DI -> VIP
#define D2VSyncClientUniqueIdentifier_service_id (vsomeip::service_t) 183
#define D2VSyncClientUniqueIdentifier_method_id  (vsomeip::method_t)  3
#define D2VSyncClientUniqueIdentifier_event_id   (vsomeip::event_t)   0x8000 + D2VSyncClientUniqueIdentifier_method_id


//
// PlatformDC
//
// DI, IVI -> VIP
#define DiagDIDRequestSet_service_id (vsomeip::service_t) 58
#define DiagDIDRequestSet_method_id  (vsomeip::method_t)  1
#define DiagDIDRequestSet_event_id   (vsomeip::event_t)   0x8000 + DiagDIDRequestSet_method_id


//
// Platform_DC
//
// VIP -> DI,IVI
#define AudioControlHandoverRes_service_id (vsomeip::service_t) 92
#define AudioControlHandoverRes_method_id  (vsomeip::method_t)  0
#define AudioControlHandoverRes_event_id   (vsomeip::event_t)   0x8000 + AudioControlHandoverRes_method_id


//
// Platform_DC
//
// VIP -> DI,IVI
#define AudioDeviceStatus_service_id (vsomeip::service_t) 92
#define AudioDeviceStatus_method_id  (vsomeip::method_t)  1
#define AudioDeviceStatus_event_id   (vsomeip::event_t)   0x8000 + AudioDeviceStatus_method_id


//
// Platform_DC
//
// VIP -> DI,IVI
#define AudioHeartbeatMsg_service_id (vsomeip::service_t) 92
#define AudioHeartbeatMsg_method_id  (vsomeip::method_t)  2
#define AudioHeartbeatMsg_event_id   (vsomeip::event_t)   0x8000 + AudioHeartbeatMsg_method_id


//
// Platform_DC
//
// DI,IVI -> VIP
#define AudioControlHandoverReq_service_id (vsomeip::service_t) 91
#define AudioControlHandoverReq_method_id  (vsomeip::method_t)  0
#define AudioControlHandoverReq_event_id   (vsomeip::event_t)   0x8000 + AudioControlHandoverReq_method_id


//
// Platform_DC
//
// DI,IVI -> VIP
#define AudioDeviceReset_service_id (vsomeip::service_t) 91
#define AudioDeviceReset_method_id  (vsomeip::method_t)  1
#define AudioDeviceReset_event_id   (vsomeip::event_t)   0x8000 + AudioDeviceReset_method_id


//
// Platform_DC
//
// DI,IVI -> VIP
#define AudioDeviceMute_service_id (vsomeip::service_t) 91
#define AudioDeviceMute_method_id  (vsomeip::method_t)  2
#define AudioDeviceMute_event_id   (vsomeip::event_t)   0x8000 + AudioDeviceMute_method_id


//
// Platform_DC
//
// DI,IVI -> VIP
#define LastModeSettings_service_id (vsomeip::service_t) 91
#define LastModeSettings_method_id  (vsomeip::method_t)  3
#define LastModeSettings_event_id   (vsomeip::event_t)   0x8000 + LastModeSettings_method_id


//
// Recovery
//
// DI -> DI
#define SwUpdateProgress_service_id (vsomeip::service_t) 235
#define SwUpdateProgress_method_id  (vsomeip::method_t)  0
#define SwUpdateProgress_event_id   (vsomeip::event_t)   0x8000 + SwUpdateProgress_method_id


//
// Recovery
//
// DI -> DI
#define SwUpdateStatus_service_id (vsomeip::service_t) 235
#define SwUpdateStatus_method_id  (vsomeip::method_t)  1
#define SwUpdateStatus_event_id   (vsomeip::event_t)   0x8000 + SwUpdateStatus_method_id


//
// Recovery
//
// DI -> DI
#define SwUpdateComplete_service_id (vsomeip::service_t) 236
#define SwUpdateComplete_method_id  (vsomeip::method_t)  0
#define SwUpdateComplete_event_id   (vsomeip::event_t)   0x8000 + SwUpdateComplete_method_id



extern std::vector<std::pair<vsomeip::service_t, vsomeip::method_t >> MsgIds;

#endif  //MSG_IDS_GAC_HPP
