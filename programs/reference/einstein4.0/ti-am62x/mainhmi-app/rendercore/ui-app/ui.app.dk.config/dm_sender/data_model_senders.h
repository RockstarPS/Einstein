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

  @file      ui/ui.hyundai.app/ui.hyundai.dk.config/sources/hmi_app/data_model_senders.hpp
  @author    Atanas Tsekov (atsekov@visteon.com)
  @brief     Declaration of DataModel sender interfaces.
  @date      Sep 15, 2022

****************************************************************************/
#ifndef DATA_MODEL_SENDERS_HPP_
#define DATA_MODEL_SENDERS_HPP_


#include "MainPckg/HelperAPI/HelperAPI.h"
#include "DMsPckg/ButtonsPckg/ButtonsPckg.h"
#include "GlobalDmAccessors/GlobalDmAccessors.h"
namespace visteon
{
    namespace hmi
    {
        namespace DataModel
        {
            void sendWarningACK(ButtonEvent press);
            void sendONSACK(ButtonEvent press);
            void sendSettingEvent(const Menu_feedback_type Menu_ret_val);
            void sendNVM_Baseview(const HMI_BaseViewType base_view);
            void sendHmiCurrentView(const HMI_CurrentViewType current_view);
            void sendNVM_LeftContent(const Left_switching_type left_content_focus);
            void sendHmiReady(const HmiReadyStateType hmiReadyState);
            void sendDooranimStatus(bool anim_status);
            void sendTripResetbtnData(uint16_t T_rst_Bits);

        }
    }
}

#endif //DATA_MODEL_SENDERS_HPP_
