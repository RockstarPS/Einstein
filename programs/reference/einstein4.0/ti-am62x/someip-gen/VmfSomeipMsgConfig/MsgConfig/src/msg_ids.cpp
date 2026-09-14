#include "msg_ids.hpp"

std::vector<std::pair<vsomeip::service_t, vsomeip::method_t >> MsgIds =
{
	// Platform VIP -> DI, IVI
	{
		SWC_service_id,
		SWC_method_id + 0x8000
	},
	
	// Platform VIP -> DI, IVI
	{
		PowerSystemStateReqChange_service_id,
		PowerSystemStateReqChange_method_id + 0x8000
	},
	
	// Platform VIP -> DI,IVI
	{
		IgnState_service_id,
		IgnState_method_id + 0x8000
	},
	
	// Platform VIP -> DI, IVI
	{
		OAT_service_id,
		OAT_method_id + 0x8000
	},
	
	// Platform VIP -> DI, IVI
	{
		TT_Status_service_id,
		TT_Status_method_id + 0x8000
	},
	
	// Platform VIP -> DI, IVI
	{
		DiagDIDRequest_service_id,
		DiagDIDRequest_method_id + 0x8000
	},
	
	// Platform VIP -> DI, IVI
	{
		DiagRoutineRequest_service_id,
		DiagRoutineRequest_method_id + 0x8000
	},
	
	// Platform VIP -> DI, IVI
	{
		DiagIOCtrlRequest_service_id,
		DiagIOCtrlRequest_method_id + 0x8000
	},
	
	// Platform VIP -> DI, IVI
	{
		ConfigRecordExt_service_id,
		ConfigRecordExt_method_id + 0x8000
	},
	
	// Platform VIP -> DI, IVI
	{
		ConfigRecord_service_id,
		ConfigRecord_method_id + 0x8000
	},
	
	// Platform VIP -> DI, IVI
	{
		PersRecord1byte_service_id,
		PersRecord1byte_method_id + 0x8000
	},
	
	// Platform VIP -> DI
	{
		Odometer_service_id,
		Odometer_method_id + 0x8000
	},
	
	// Platform DI, IVI -> VIP
	{
		PowerSystemState_service_id,
		PowerSystemState_method_id 
	},
	
	// Platform DI, IVI -> VIP
	{
		PowerExtendShutdownTime_service_id,
		PowerExtendShutdownTime_method_id 
	},
	
	// Platform VIP -> DI
	{
		SlowGaugeInfo_service_id,
		SlowGaugeInfo_method_id + 0x8000
	},
	
	// Platform DI, IVI -> VIP
	{
		DiagResponse_service_id,
		DiagResponse_method_id 
	},
	
	// Platform DI, IVI -> VIP
	{
		PersRecord_service_id,
		PersRecord_method_id 
	},
	
	// Program DI -> IVI
	{
		DisplayLayoutIVIRenderReq_service_id,
		DisplayLayoutIVIRenderReq_method_id + 0x8000
	},
	
	// Program DI -> IVI
	{
		PopupStatusMsg_service_id,
		PopupStatusMsg_method_id + 0x8000
	},
	
	// Program DI -> IVI
	{
		UserSelectionMsg_service_id,
		UserSelectionMsg_method_id + 0x8000
	},
	
	// Program DI -> IVI
	{
		PopupErrorMsg_service_id,
		PopupErrorMsg_method_id + 0x8000
	},
	
	// Program VIP -> DI,IVI
	{
		IlluminationControlInitEventData_service_id,
		IlluminationControlInitEventData_method_id + 0x8000
	},
	
	// Program VIP -> DI,IVI
	{
		RideModeCmd_service_id,
		RideModeCmd_method_id + 0x8000
	},
	
	// Program VIP -> DI,IVI
	{
		RideModeTableAllIndex_service_id,
		RideModeTableAllIndex_method_id + 0x8000
	},
	
	// Program VIP -> DI,IVI
	{
		RideModeTableOneIndex_service_id,
		RideModeTableOneIndex_method_id + 0x8000
	},
	
	// Program VIP -> DI,IVI
	{
		DiagDIDSetResponse_service_id,
		DiagDIDSetResponse_method_id + 0x8000
	},
	
	// Program DI -> IVI
	{
		DiagDIDRequestDomain_service_id,
		DiagDIDRequestDomain_method_id + 0x8000
	},
	
	// Program DI -> IVI
	{
		DiagRoutineRequestDomain_service_id,
		DiagRoutineRequestDomain_method_id + 0x8000
	},
	
	// Program DI -> IVI
	{
		DiagIOCtrlRequestDomain_service_id,
		DiagIOCtrlRequestDomain_method_id + 0x8000
	},
	
	// Program VIP -> DI,IVI
	{
		PinStatus_service_id,
		PinStatus_method_id + 0x8000
	},
	
	// Program DI -> DI,IVI
	{
		FactoryPrivacyResetDefaultToIVI_service_id,
		FactoryPrivacyResetDefaultToIVI_method_id + 0x8000
	},
	
	// Program VIP -> DI,IVI
	{
		CalibDataResp_service_id,
		CalibDataResp_method_id + 0x8000
	},
	
	// Program VIP -> DI,IVI
	{
		ETMEntrySubFnExitStatus_service_id,
		ETMEntrySubFnExitStatus_method_id + 0x8000
	},
	
	// Program DI -> IVI
	{
		NavigateToPoi_service_id,
		NavigateToPoi_method_id + 0x8000
	},
	
	// Program VIP -> DI,IVI
	{
		HomeLinkStatus_service_id,
		HomeLinkStatus_method_id + 0x8000
	},
	
	// Program VIP -> DI,IVI
	{
		SBNProgramReq_service_id,
		SBNProgramReq_method_id + 0x8000
	},
	
	// Program VIP -> DI,IVI
	{
		VariantConfigResp_service_id,
		VariantConfigResp_method_id + 0x8000
	},
	
	// Program VIP -> DI,IVI
	{
		ETMStartupMetrics_service_id,
		ETMStartupMetrics_method_id + 0x8000
	},
	
	// Program VIP -> DI,IVI
	{
		SWUpdateResetRequestStatus_service_id,
		SWUpdateResetRequestStatus_method_id + 0x8000
	},
	
	// Program VIP -> DI,IVI
	{
		VoiceNaviRUIWidgetInfo_service_id,
		VoiceNaviRUIWidgetInfo_method_id + 0x8000
	},
	
	// Program VIP -> DI,IVI
	{
		VoiceNaviRUIDistanceToEmpty_service_id,
		VoiceNaviRUIDistanceToEmpty_method_id + 0x8000
	},
	
	// Program VIP -> Di,IVI
	{
		VoiceNaviRUIGearStatus_service_id,
		VoiceNaviRUIGearStatus_method_id + 0x8000
	},
	
	// Program VIP -> DI,IVI
	{
		VoiceNaviRUIFastGuageInfo_service_id,
		VoiceNaviRUIFastGuageInfo_method_id + 0x8000
	},
	
	// Program DI -> IVI
	{
		ETMSoCTemperature_service_id,
		ETMSoCTemperature_method_id + 0x8000
	},
	
	// Program DI -> IVI
	{
		GeneralPurposeHmiData_service_id,
		GeneralPurposeHmiData_method_id + 0x8000
	},
	
	// Program DI,IVI -> VIP
	{
		DiagSnapshotDIDRequest_service_id,
		DiagSnapshotDIDRequest_method_id + 0x8000
	},
	
	// Program DI,IVI -> VIP
	{
		FeatureStatus_service_id,
		FeatureStatus_method_id 
	},
	
	// Program IVI -> DI
	{
		ClusterDisplayControlMsg_service_id,
		ClusterDisplayControlMsg_method_id 
	},
	
	// Program IVI -> DI
	{
		DisplayLayoutEventTrigger_service_id,
		DisplayLayoutEventTrigger_method_id 
	},
	
	// Program IVI -> DI
	{
		DisplayLayoutIVIRenderReadyStatus_service_id,
		DisplayLayoutIVIRenderReadyStatus_method_id 
	},
	
	// Program IVI -> DI
	{
		ShowPopupMsg_service_id,
		ShowPopupMsg_method_id 
	},
	
	// Program IVI -> DI
	{
		RemovePopupMsg_service_id,
		RemovePopupMsg_method_id 
	},
	
	// Program IVI -> DI
	{
		VolumeBarMsg_service_id,
		VolumeBarMsg_method_id 
	},
	
	// Program DI,IVI -> VIP
	{
		IlluminationMCData_service_id,
		IlluminationMCData_method_id 
	},
	
	// Program Di,IVI -> VIP
	{
		RideModeCustomization_service_id,
		RideModeCustomization_method_id 
	},
	
	// Program Di,IVI -> VIP
	{
		RideModeInitStatus_service_id,
		RideModeInitStatus_method_id 
	},
	
	// Program IVI -> DI
	{
		DiagResponseDomain_service_id,
		DiagResponseDomain_method_id 
	},
	
	// Program DI, IVI -> VIP
	{
		EnteredPinDigit_service_id,
		EnteredPinDigit_method_id 
	},
	
	// Program IVI -> VIP
	{
		EnterPinChangeMode_service_id,
		EnterPinChangeMode_method_id 
	},
	
	// Program IVI -> DI
	{
		FactoryPrivacyResetEventTrigger_service_id,
		FactoryPrivacyResetEventTrigger_method_id 
	},
	
	// Program DI,IVI -> DI
	{
		FactoryPrivacyIVIDefaultStatusFromIVI_service_id,
		FactoryPrivacyIVIDefaultStatusFromIVI_method_id 
	},
	
	// Program IVI -> VIP
	{
		CalibData_service_id,
		CalibData_method_id 
	},
	
	// Program IVI -> DI,VIP
	{
		ETMSubFnStatus_service_id,
		ETMSubFnStatus_method_id 
	},
	
	// Program IVI -> DI
	{
		MediaPlayingListMsg_service_id,
		MediaPlayingListMsg_method_id 
	},
	
	// Program IVI -> DI
	{
		WidgetInfofromIVI_service_id,
		WidgetInfofromIVI_method_id 
	},
	
	// Program IVI -> VIP
	{
		HomeLinkReq_service_id,
		HomeLinkReq_method_id 
	},
	
	// Program IVI -> VIP
	{
		VariantConfigData_service_id,
		VariantConfigData_method_id 
	},
	
	// Program IVI -> VIP
	{
		HomeLinkCurrentStatus_service_id,
		HomeLinkCurrentStatus_method_id 
	},
	
	// Program IVI -> VIP
	{
		RegulatorSync_service_id,
		RegulatorSync_method_id 
	},
	
	// Program IVI -> VIP
	{
		VoiceRequest_service_id,
		VoiceRequest_method_id 
	},
	
	// Program IVI -> VIP
	{
		SWUpdateResetRequest_service_id,
		SWUpdateResetRequest_method_id 
	},
	
	// Program IVI -> DI
	{
		NavigationSpeedLimiter_service_id,
		NavigationSpeedLimiter_method_id 
	},
	
	// Program IVI -> VIP
	{
		DiagSnapshotDIDResponse_service_id,
		DiagSnapshotDIDResponse_method_id 
	},
	
	// PlatformDC VIP -> DI,IVI
	{
		CANMessageSpecific1IDs_service_id,
		CANMessageSpecific1IDs_method_id + 0x8000
	},
	
	// PlatformDC VIP -> DI
	{
		RTCUpdateTime_service_id,
		RTCUpdateTime_method_id + 0x8000
	},
	
	// PlatformDC DI -> DI
	{
		RTCUpdateTimeHMI_service_id,
		RTCUpdateTimeHMI_method_id 
	},
	
	// PlatformDC DI -> VIP
	{
		RTCSetTime_service_id,
		RTCSetTime_method_id 
	},
	
	// PlatformDC DI -> VIP
	{
		RTCGetChipTime_service_id,
		RTCGetChipTime_method_id 
	},
	
	// PlatformDC VIP -> DI
	{
		V2DUpdateSourceUniqueIdentifier_service_id,
		V2DUpdateSourceUniqueIdentifier_method_id + 0x8000
	},
	
	// PlatformDC DI -> VIP
	{
		D2VSyncClientUniqueIdentifier_service_id,
		D2VSyncClientUniqueIdentifier_method_id 
	},
	
	// PlatformDC DI, IVI -> VIP
	{
		DiagDIDRequestSet_service_id,
		DiagDIDRequestSet_method_id 
	},
	
	// Platform_DC VIP -> DI,IVI
	{
		AudioControlHandoverRes_service_id,
		AudioControlHandoverRes_method_id + 0x8000
	},
	
	// Platform_DC VIP -> DI,IVI
	{
		AudioDeviceStatus_service_id,
		AudioDeviceStatus_method_id + 0x8000
	},
	
	// Platform_DC VIP -> DI,IVI
	{
		AudioHeartbeatMsg_service_id,
		AudioHeartbeatMsg_method_id + 0x8000
	},
	
	// Platform_DC DI,IVI -> VIP
	{
		AudioControlHandoverReq_service_id,
		AudioControlHandoverReq_method_id 
	},
	
	// Platform_DC DI,IVI -> VIP
	{
		AudioDeviceReset_service_id,
		AudioDeviceReset_method_id 
	},
	
	// Platform_DC DI,IVI -> VIP
	{
		AudioDeviceMute_service_id,
		AudioDeviceMute_method_id 
	},
	
	// Platform_DC DI,IVI -> VIP
	{
		LastModeSettings_service_id,
		LastModeSettings_method_id 
	},
	
	// Recovery DI -> DI
	{
		SwUpdateProgress_service_id,
		SwUpdateProgress_method_id 
	},
	
	// Recovery DI -> DI
	{
		SwUpdateStatus_service_id,
		SwUpdateStatus_method_id 
	},
	
	// Recovery DI -> DI
	{
		SwUpdateComplete_service_id,
		SwUpdateComplete_method_id + 0x8000
	}
	
};
