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
//  Filename    : gltfplus_scg_layout.h
//  Description : types required for the render core data format.
//  Created on  : 02-Jan-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file   gltfplus_scg_material.h
///	\brief	types required for the render core data format.
#ifndef gltfplus_scg_layout_h
#define gltfplus_scg_layout_h

#include "gfx3d_scg.h"
#include "tinygltf_if.h"

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{

    /// <summary>
    /// layout class defining the arrangement of grouped nodes
    /// </summary>
    class gltfplus_scg_layout: public gfx3d_scg_layout
	{
	private:
		tinygltf::Node  * node;				///< node object from tiny gltf
		/// <summary>
		/// loads the extra layouts information
		/// <param name="p_extras">tinygltf extra var from which margin information will be retrieved</param>
		/// </summary>
		void loadLayoutInformation(tinygltf::Value* p_extras);
		/// <summary>
		/// loads the margin property for layouts
		/// <param name="p_extras">tinygltf extra var from which margin information will be retrieved</param>
		/// </summary>
		glm::vec4  loadMarginProperty(tinygltf::Value* p_extras);
	public:
		/// <summary>
		/// constructor
		/// <param name="p_node">tiny gltf node</param>
		/// <param name="p_dsp">renderCore display object</param>
		/// <param name="p_parent">renderCore parent object</param>
		/// </summary>
		gltfplus_scg_layout(size_t p_node_index, gfx3d_scg_display * p_dsp, gfx3d_scg_node * p_parent);
	};
    /// @}
};

#endif