#include "msg_maps.hpp"

void logMessage(const uint32_t service, uint32_t method, const uint8_t *pData, uint32_t length)
{
	std::stringstream its_header;
	std::stringstream its_message;

	its_header << "received a msg for method msg header["
			<< std::setw(4) << std::setfill('0') << service << "."
			<< std::setw(4) << std::setfill('0') << 1 << "."
			<< std::setw(4) << std::setfill('0') << method << "{vmf_msg_id:" << method << "}" <<  "]";


	its_message << "msg payload (" << std::dec << length << ") [";
	for (uint32_t i = 0; i < length; ++i)
	{
		its_message << std::hex << std::setw(2) << std::setfill('0') << (int) pData[i] << " ";
	}
	its_message << "]";

	std::cout << "UCLSTUB : " << its_header.str() << its_message.str() << std::endl;
}

dk::runtime2::core::msg_map_t VmfMsgMap =
{
	{
		PowerSystemState_service_id * 256 + PowerSystemState_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(PowerSystemState_service_id, PowerSystemState_method_id, m.getData(), m.getSize());
		}
	},
	{
		PowerExtendShutdownTime_service_id * 256 + PowerExtendShutdownTime_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(PowerExtendShutdownTime_service_id, PowerExtendShutdownTime_method_id, m.getData(), m.getSize());
		}
	},
	{
		DiagResponse_service_id * 256 + DiagResponse_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(DiagResponse_service_id, DiagResponse_method_id, m.getData(), m.getSize());
		}
	},
	{
		PersRecord_service_id * 256 + PersRecord_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(PersRecord_service_id, PersRecord_method_id, m.getData(), m.getSize());
		}
	},
	{
		FeatureStatus_service_id * 256 + FeatureStatus_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(FeatureStatus_service_id, FeatureStatus_method_id, m.getData(), m.getSize());
		}
	},
	{
		ClusterDisplayControlMsg_service_id * 256 + ClusterDisplayControlMsg_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(ClusterDisplayControlMsg_service_id, ClusterDisplayControlMsg_method_id, m.getData(), m.getSize());
		}
	},
	{
		DisplayLayoutEventTrigger_service_id * 256 + DisplayLayoutEventTrigger_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(DisplayLayoutEventTrigger_service_id, DisplayLayoutEventTrigger_method_id, m.getData(), m.getSize());
		}
	},
	{
		DisplayLayoutIVIRenderReadyStatus_service_id * 256 + DisplayLayoutIVIRenderReadyStatus_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(DisplayLayoutIVIRenderReadyStatus_service_id, DisplayLayoutIVIRenderReadyStatus_method_id, m.getData(), m.getSize());
		}
	},
	{
		ShowPopupMsg_service_id * 256 + ShowPopupMsg_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(ShowPopupMsg_service_id, ShowPopupMsg_method_id, m.getData(), m.getSize());
		}
	},
	{
		RemovePopupMsg_service_id * 256 + RemovePopupMsg_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(RemovePopupMsg_service_id, RemovePopupMsg_method_id, m.getData(), m.getSize());
		}
	},
	{
		VolumeBarMsg_service_id * 256 + VolumeBarMsg_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(VolumeBarMsg_service_id, VolumeBarMsg_method_id, m.getData(), m.getSize());
		}
	},
	{
		IlluminationMCData_service_id * 256 + IlluminationMCData_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(IlluminationMCData_service_id, IlluminationMCData_method_id, m.getData(), m.getSize());
		}
	},
	{
		RideModeCustomization_service_id * 256 + RideModeCustomization_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(RideModeCustomization_service_id, RideModeCustomization_method_id, m.getData(), m.getSize());
		}
	},
	{
		RideModeInitStatus_service_id * 256 + RideModeInitStatus_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(RideModeInitStatus_service_id, RideModeInitStatus_method_id, m.getData(), m.getSize());
		}
	},
	{
		DiagResponseDomain_service_id * 256 + DiagResponseDomain_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(DiagResponseDomain_service_id, DiagResponseDomain_method_id, m.getData(), m.getSize());
		}
	},
	{
		EnteredPinDigit_service_id * 256 + EnteredPinDigit_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(EnteredPinDigit_service_id, EnteredPinDigit_method_id, m.getData(), m.getSize());
		}
	},
	{
		EnterPinChangeMode_service_id * 256 + EnterPinChangeMode_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(EnterPinChangeMode_service_id, EnterPinChangeMode_method_id, m.getData(), m.getSize());
		}
	},
	{
		FactoryPrivacyResetEventTrigger_service_id * 256 + FactoryPrivacyResetEventTrigger_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(FactoryPrivacyResetEventTrigger_service_id, FactoryPrivacyResetEventTrigger_method_id, m.getData(), m.getSize());
		}
	},
	{
		FactoryPrivacyIVIDefaultStatusFromIVI_service_id * 256 + FactoryPrivacyIVIDefaultStatusFromIVI_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(FactoryPrivacyIVIDefaultStatusFromIVI_service_id, FactoryPrivacyIVIDefaultStatusFromIVI_method_id, m.getData(), m.getSize());
		}
	},
	{
		CalibData_service_id * 256 + CalibData_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(CalibData_service_id, CalibData_method_id, m.getData(), m.getSize());
		}
	},
	{
		ETMSubFnStatus_service_id * 256 + ETMSubFnStatus_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(ETMSubFnStatus_service_id, ETMSubFnStatus_method_id, m.getData(), m.getSize());
		}
	},
	{
		MediaPlayingListMsg_service_id * 256 + MediaPlayingListMsg_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(MediaPlayingListMsg_service_id, MediaPlayingListMsg_method_id, m.getData(), m.getSize());
		}
	},
	{
		WidgetInfofromIVI_service_id * 256 + WidgetInfofromIVI_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(WidgetInfofromIVI_service_id, WidgetInfofromIVI_method_id, m.getData(), m.getSize());
		}
	},
	{
		HomeLinkReq_service_id * 256 + HomeLinkReq_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(HomeLinkReq_service_id, HomeLinkReq_method_id, m.getData(), m.getSize());
		}
	},
	{
		VariantConfigData_service_id * 256 + VariantConfigData_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(VariantConfigData_service_id, VariantConfigData_method_id, m.getData(), m.getSize());
		}
	},
	{
		HomeLinkCurrentStatus_service_id * 256 + HomeLinkCurrentStatus_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(HomeLinkCurrentStatus_service_id, HomeLinkCurrentStatus_method_id, m.getData(), m.getSize());
		}
	},
	{
		RegulatorSync_service_id * 256 + RegulatorSync_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(RegulatorSync_service_id, RegulatorSync_method_id, m.getData(), m.getSize());
		}
	},
	{
		VoiceRequest_service_id * 256 + VoiceRequest_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(VoiceRequest_service_id, VoiceRequest_method_id, m.getData(), m.getSize());
		}
	},
	{
		SWUpdateResetRequest_service_id * 256 + SWUpdateResetRequest_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(SWUpdateResetRequest_service_id, SWUpdateResetRequest_method_id, m.getData(), m.getSize());
		}
	},
	{
		NavigationSpeedLimiter_service_id * 256 + NavigationSpeedLimiter_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(NavigationSpeedLimiter_service_id, NavigationSpeedLimiter_method_id, m.getData(), m.getSize());
		}
	},
	{
		DiagSnapshotDIDResponse_service_id * 256 + DiagSnapshotDIDResponse_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(DiagSnapshotDIDResponse_service_id, DiagSnapshotDIDResponse_method_id, m.getData(), m.getSize());
		}
	},
	{
		RTCUpdateTimeHMI_service_id * 256 + RTCUpdateTimeHMI_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(RTCUpdateTimeHMI_service_id, RTCUpdateTimeHMI_method_id, m.getData(), m.getSize());
		}
	},
	{
		RTCSetTime_service_id * 256 + RTCSetTime_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(RTCSetTime_service_id, RTCSetTime_method_id, m.getData(), m.getSize());
		}
	},
	{
		RTCGetChipTime_service_id * 256 + RTCGetChipTime_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(RTCGetChipTime_service_id, RTCGetChipTime_method_id, m.getData(), m.getSize());
		}
	},
	{
		D2VSyncClientUniqueIdentifier_service_id * 256 + D2VSyncClientUniqueIdentifier_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(D2VSyncClientUniqueIdentifier_service_id, D2VSyncClientUniqueIdentifier_method_id, m.getData(), m.getSize());
		}
	},
	{
		DiagDIDRequestSet_service_id * 256 + DiagDIDRequestSet_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(DiagDIDRequestSet_service_id, DiagDIDRequestSet_method_id, m.getData(), m.getSize());
		}
	},
	{
		AudioControlHandoverReq_service_id * 256 + AudioControlHandoverReq_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(AudioControlHandoverReq_service_id, AudioControlHandoverReq_method_id, m.getData(), m.getSize());
		}
	},
	{
		AudioDeviceReset_service_id * 256 + AudioDeviceReset_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(AudioDeviceReset_service_id, AudioDeviceReset_method_id, m.getData(), m.getSize());
		}
	},
	{
		AudioDeviceMute_service_id * 256 + AudioDeviceMute_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(AudioDeviceMute_service_id, AudioDeviceMute_method_id, m.getData(), m.getSize());
		}
	},
	{
		LastModeSettings_service_id * 256 + LastModeSettings_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(LastModeSettings_service_id, LastModeSettings_method_id, m.getData(), m.getSize());
		}
	},
	{
		SwUpdateProgress_service_id * 256 + SwUpdateProgress_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(SwUpdateProgress_service_id, SwUpdateProgress_method_id, m.getData(), m.getSize());
		}
	},
	{
		SwUpdateStatus_service_id * 256 + SwUpdateStatus_method_id, []( dk::runtime2::core::Deserializer & m )
		{
			logMessage(SwUpdateStatus_service_id, SwUpdateStatus_method_id, m.getData(), m.getSize());
		}
	}
};
