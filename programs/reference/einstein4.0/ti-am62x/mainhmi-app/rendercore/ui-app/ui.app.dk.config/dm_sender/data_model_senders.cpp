/*************************************************************************
						 Copyright Statement
						VISTEON CONFIDENTIAL

  This is an unpublished work, which contains trade secrets, created in
  2022. Visteon Corporation owns all rights to this work and intends
  to maintain it in confidence to preserve its trade secret status. Visteon
  Corporation reserves the right, under the copyright laws of the United
  States or those of any other country that may have jurisdiction, to
  protect this work as an unpublished copyright work in the event of an
  inadvertent or deliberate unauthorized publication. Visteon Corporation
  also reserves its rights under the copyright laws to protect this work
  as a published work, when appropriate. Those having access to this work
  may not copy it, use it or disclose the information contained in it
  without the written authorization of Visteon Corporation.

  @file      ui/ui.hyundai.app/ui.hyundai.dk.config/sources/dm_sender/data_model_senders.cpp
  @author    Atanas Tsekov (atsekov@visteon.com)
  @brief     Implementation of DataModel sender interfaces.
  @date      Sep 15, 2022

****************************************************************************/
#include "data_model_senders.h"

#include "hmi_app.h"
#include "dk_runtime_hmi_warnings_component.h"
#include "dk_runtime_hmi_settings_component.h"



extern WarningStatus vip_last_received;
extern VRInterruptInfo vip_last_ons_status;

namespace visteon
{
	namespace hmi
	{
		namespace DataModel
		{

			void sendWarningACK(ButtonEvent press)
			{
				WarningStatus ack = vip_last_received;
				ack.dynData[8] = (static_cast<uint8_t>(press.Id) << 4) | static_cast<uint8_t>(press.btn_event);
				gApp.sendWarningStatus(ack);
			}

			void sendONSACK(ButtonEvent press_ons)
			{
				VRInterruptInfo ack_ons = vip_last_ons_status;
				ack_ons.event = (static_cast<uint8_t>(press_ons.Id) << 4) | static_cast<uint8_t>(press_ons.btn_event);
				gApp.sendVRInterruptInfo(ack_ons);
			}


			void sendSettingEvent(const Menu_feedback_type Menu_ret_val)
			{
				SetMenuCmd Set_data;
				Set_data.data.MenuId_e = static_cast<ESetMenuId_t>(Menu_ret_val.MenuId_e);
				Set_data.data.ButtonType_e = static_cast<EButtonIDs_t>(Menu_ret_val.ButtonType_e);
				Set_data.data.ButtonStatus_e = static_cast<EButtonSts_t>(Menu_ret_val.ButtonStatus_e);
				Set_data.data.MenuValue_u32 = static_cast<uint32_t>(Menu_ret_val.MenuValue_u32);
				gApp.sendSetMenuCmd(Set_data);
			}
			void sendNVM_Baseview(const HMI_BaseViewType base_view)
			{
				HmiRetRequest Baseview_val;
				Baseview_val.hmiRetReq[11] = base_view;
				gApp.sendHmiRetRequest(Baseview_val);
			}

			void sendDooranimStatus(bool anim_status)
			{

			}
			void sendNVM_LeftContent(const Left_switching_type left_content_focus)
			{
				constexpr uint8_t MAX_BASEVIEW_VAL = 3U;
				HmiRetRequest Left_content_update;
				for(uint8_t i=0; i<MAX_BASEVIEW_VAL ; i++)
				{
					Left_content_update.hmiRetReq[i] = static_cast<uint8_t>(left_content_focus.Mainmenu[i] - 131073);
				}
				gApp.sendHmiRetRequest(Left_content_update);
			}

			void sendHmiCurrentView(const HMI_CurrentViewType current_view)
			{
				CurrentViewData CurrentViewVal;
				CurrentViewVal.data = current_view;
				gApp.sendCurrentViewData(CurrentViewVal);
			}

			void sendTripResetbtnData(uint16_t T_rst_Bits)
			{
				TripResetCmd TripResetCmdMsg;
				TripResetCmdMsg.tripCmdId = T_rst_Bits;
				gApp.sendTripResetCmd(TripResetCmdMsg);
			}

			void sendHmiReady(const HmiReadyStateType hmiReadyState)
			{
				MainHMIReadyStatus HmiReadyStatus;
				HmiReadyStatus.status = hmiReadyState;
				gApp.sendMainHMIReadyStatus(HmiReadyStatus);
			}

		} // namespace DataModel
	} // namespace hmi
} // namespace visteon
