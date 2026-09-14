///////////////////////////////////////////////////////////////////////////////
//
//                     CONFIDENTIAL VISTEON CORPORATION
//
// This is an unpublished work of authorship, which contains trade secrets,
// created in 2018. Visteon Corporation owns all rights to this work and
// intends to maintain it in confidence to preserve its trade secret status.
// Visteon Corporation reserves the right, under the copyright laws of the
// United States or those of any other country that may have jurisdiction,
// to protect this work as an unpublished work, in the event of an
// inadvertent or deliberate unauthorized publication. Visteon Corporation
// also reserves its rights under all copyright laws to protect this work as
// a published work, when appropriate. Those having access to this work may
// not copy it, use it, modify it or disclose the information contained in
// it without the written authorization of Visteon Corporation.
//
//  Filename    : rc_imgui_performance_hud.h
//  Description : 
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "rc_imgui.h"
#include <map>

namespace rendercore_engine
{
	class gfx3d_scg_material_group;

	/// \ingroup Internal
/// @{

	class rc_imgui_control_editor : public rc_imgui_window
	{
		int id;
		gfx3d_scg_display* display;
		int window_flags;
		bool visible;
		float32_t windowSizeY;
		std::string windowTitle;
		bool resetToDefaultLayout = true;

		void ShowEditorMainWindow();

		struct NodeProperties
		{
			bool valueBool;
			int valueInt;
			float32_t value[4];		//max supported for 4 float32_t values
			float32_t dragSpeed;
			float32_t min;
			float32_t max;
			std::string propertyName;
			std::string propertyNickName;
			std::string typeName;
			std::string controlNodeName;
			MdlTargetPath_E targetPath;
			gfx3d_scg_node* node;
			gfx3d_scg_material_group* mat;

			bool slider = true;

			void UpdateValue();
			NodeProperties() :node(nullptr), mat(nullptr) {}
		};

		std::map<std::string, std::vector<NodeProperties>> nodePropertiesMap;

	public:
		rc_imgui_control_editor(int p_id, gfx3d_scg_display* p_display);
		virtual ~rc_imgui_control_editor();

		virtual void Render() override;
		virtual void SetVisible(bool p_value) override;
		virtual bool GetVisible() override;
		virtual int32_t GetId() override;
	};

	/// @}
}
