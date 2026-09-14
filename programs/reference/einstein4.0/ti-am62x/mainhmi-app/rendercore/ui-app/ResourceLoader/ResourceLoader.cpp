/*************************************************************************
						 Copyright Statement
						VISTEON CONFIDENTIAL

  This is an unpublished work, which contains trade secrets, created in
  20202019. Visteon Corporation owns all rights to this work and intends
  to maintain it in confidence to preserve its trade secret status. Visteon
  Corporation reserves the right, under the copyright laws of the United
  States or those of any other country that may have jurisdiction, to
  protect this work as an unpublished copyright work in the event of an
  inadvertent or deliberate unauthorized publication. Visteon Corporation
  also reserves its rights under the copyright laws to protect this work
  as a published work, when appropriate. Those having access to this work
  may not copy it, use it or disclose the information contained in it
  without the written authorization of Visteon Corporation.

  @file      ui.core/ui.rendercore.proxy/src/rc_interface/ResourceLoader.cpp
  @author    Atanas Tsekov (atsekov@visteon.com)
  @brief     Implementation of ResourceLoader class.
  @date      Jun 14, 2022

****************************************************************************/
#include "ResourceLoader.hpp"
#include "rc_utils.h"
#include "rdf_types.h"

namespace resource_loader
{
	void startLoading(const size_t scene_index, const LoadStrat strategy, const LoadRule rule)
	{
		rcore_engine_app::getDisplay()->CreateScene(scene_index);
		if (rcore_engine_app::getDisplay()->GetSceneLoadStatus(scene_index) != rendercore_engine::rcScreenLoadSts::Loaded)
		{
			constexpr size_t  UI_INITIAL_SCENE = static_cast<size_t>(1);
			if (UI_INITIAL_SCENE < scene_index)
			{
				rendercore_engine::gfx3d_scg_node* const scene = rcore_engine_app::getDisplay()->GetScene(scene_index);
				if (scene != nullptr)
				{
					rendercore_engine::gfx3d_scg_node* const scene_node = dynamic_cast<rendercore_engine::gfx3d_scg_node*>(scene->GetChild(0));
					for (int32_t node_index = 0; node_index < scene_node->GetChildCount(); node_index++)
					{
						rendercore_engine::gfx3d_scg_node* const camNode = dynamic_cast<rendercore_engine::gfx3d_scg_node*>(scene_node->GetChild(node_index));
						if (camNode != nullptr)
						{
							rendercore_engine::gfx3d_scg_camera* cam = dynamic_cast<rendercore_engine::gfx3d_scg_camera*>(camNode->GetCamera());
							if (cam != nullptr)
							{
								cam->SetActive(false);
							}
						}
					}
				}
			}

			const auto rc_load_rule = (rule == LoadRule::All) ? rendercore_engine::MdlResourceLoadRule::All : rendercore_engine::MdlResourceLoadRule::OnDemand;
			const auto loadStrat = (strategy == LoadStrat::Sync) ? rendercore_engine::MdlAssetLoadMode::Synchronous : rendercore_engine::MdlAssetLoadMode::Asynchronous;
			rcore_engine_app::getDisplay()->SetResourceLoadRule(rc_load_rule);
			rcore_engine_app::getDisplay()->LoadScene(scene_index, rendercore_engine::MdlSceneLoadMode::Additive, loadStrat);
		}
	}
}

