/*************************************************************************
						 Copyright Statement
						VISTEON CONFIDENTIAL

  This is an unpublished work, which contains trade secrets, created in
  2020. Visteon Corporation owns all rights to this work and intends
  to maintain it in confidence to preserve its trade secret status. Visteon
  Corporation reserves the right, under the copyright laws of the United
  States or those of any other country that may have jurisdiction, to
  protect this work as an unpublished copyright work in the event of an
  inadvertent or deliberate unauthorized publication. Visteon Corporation
  also reserves its rights under the copyright laws to protect this work
  as a published work, when appropriate. Those having access to this work
  may not copy it, use it or disclose the information contained in it
  without the written authorization of Visteon Corporation.

  @file      ui.core/ui.rendercore.proxy/inc/rc_interface/ResourceLoader.hpp
  @author    Palani Kullu (kpalani@visteon.com)
  @brief     Declaration of ResourceLoader class.
  @date      Jun 14, 2022

****************************************************************************/
#ifndef RCOREENGINEAPP_HPP_
#define RCOREENGINEAPP_HPP_

#include <vector>
#include <string>
#include <cstddef>

namespace rendercore_engine
{
	class gfx3d_scg_display;
}

class MainHMIInterface
{
public:
	MainHMIInterface();
	~MainHMIInterface();

  static MainHMIInterface* instance;

  static MainHMIInterface* getInstance() {
        if (instance == nullptr) {
            instance = new MainHMIInterface();
            printf("singleton pattern\n");
        }
        return instance;
  }

  int32_t speedValue_S32;
  int32_t tachoValue_S32;
  bool airbagWarn_sts_bool;
  bool fuelLidWarn_sts_bool;
  uint8_t gearPostion_U8;
  uint8_t tt_mask[15];
  uint8_t powerState;

  int32_t GetSpeedData(void);
  int32_t GetTachoData(void);
  uint8_t GetPowerState(void);
  void SetSpeedData(int32_t);
  void SetTachoData(int32_t);

  void SetAirbagWarn(uint8_t);
  void SetFuelLidWarn(uint8_t);

  void SetGearPosition(uint8_t);

  void SetTT_data(uint8_t arr[15]); 

  void SetPowerState(uint8_t);
};

#endif /* RCOREENGINEAPP_HPP_ */
