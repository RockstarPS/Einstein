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
  @author    Atanas Tsekov (atsekov@visteon.com)
  @brief     Declaration of ResourceLoader class.
  @date      Jun 14, 2022

****************************************************************************/
#ifndef RESOURCELOADER_HPP_
#define RESOURCELOADER_HPP_

#include <vector>
#include <string>
#include <cstddef>

namespace rendercore_engine
{
	class gfx3d_scg_display;
}

namespace resource_loader
{
	enum class LoadStrat
	{
		Async = 0,
		Sync
	};

	enum class LoadRule
	{
		OnDemand = 0,
		All
	};

	void startLoading(const size_t scene_index, const LoadStrat strategy, const LoadRule rule);
}

#endif /* RESOURCELOADER_HPP_ */
