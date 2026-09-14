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

  @file      ui.core/ui.rendercore.proxy/inc/rc_utils.h
  @author    Atanas Tsekov (atsekov@visteon.com)
  @brief     Declaration of RenderCore utilities.
  @date      Jun 21, 2022

****************************************************************************/
#ifndef RC_UTILS_H_
#define RC_UTILS_H_

#include <string>
#include <vector>

namespace rendercore_engine
{
	class gfx3d_scg_display;
}


namespace rcore_engine_app
{
	extern bool userQuit;
	extern rendercore_engine::gfx3d_scg_display* m_display;
	rendercore_engine::gfx3d_scg_display* getDisplay();
	int32_t rendercoreMain(void);
}

#endif /* RC_UTILS_H_ */
