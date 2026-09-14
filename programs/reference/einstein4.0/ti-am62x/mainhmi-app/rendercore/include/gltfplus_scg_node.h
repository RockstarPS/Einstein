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
//  Filename    : tinygltf_scg_node.h
//  Description : GLTF scene graph adaptation for tiny gltf. inherited from base
//  scenegraph classes and data parsed and loaded from tiny gltf data structures
//  Created on  : 10-Aug-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gltfplus_scg_node.h
///	\brief GLTF scene graph adaptation for tiny gltf. inherited from base
///  scenegraph classes and data parsed and loaded from tiny gltf data structures

#ifndef gltfplus_scg_node_h
#define gltfplus_scg_node_h

#include "tinygltf_if.h"
#include "gfx3d_scg.h"
//#include "gltfscg_tinygltf_anim.h"
//#include "gltfscg_tinygltf_cubemap_extn.h"

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{
    
    /// <summary>
	/// The glTF asset can define nodes, that is, the objects comprising the scene to render.
	/// nodes can have multiple children.
	/// </summary>
	class gltfplus_scg_node : public gfx3d_scg_node
	{
    public:
		/// <summary>
		/// constructor
		/// <param name="p_node">tiny gltf node</param>
		/// <param name="p_dsp">renderCore display object</param>
		/// <param name="p_parent">renderCore parent object</param>
		/// </summary>
		gltfplus_scg_node(const size_t p_node_index, gfx3d_scg_display * p_dsp, gfx3d_scg_node * p_parent);
		/// <summary>
		/// destructor
		/// </summary>
		~gltfplus_scg_node();
		/// <summary>
		/// loads the renderCore behaviors
		/// <param name="p_model">tiny gltf model</param>
		/// <param name="p_dsp">renderCore display object</param>
		/// <param name="p_extras">extra information about the behaviors</param>
		/// <param name="p_dest">destination node</param>
		/// </summary>
        static void LoadBehaviours(tinygltf::Model * p_model, gfx3d_scg_display * p_dsp, tinygltf::Value * p_extras, gfx3d_scg_node * p_dest);
		/// <summary>
		/// loads the custom renderCore properties stored in extra vars
		/// <param name="p_extras">extra information about the behaviors</param>
		/// <param name="p_node">node into which extra information is being loaded</param>
		/// </summary>
		static void LoadRendercoreProperties(tinygltf::Value * p_extras, gfx3d_scg_node* p_node);
    };

	/// gltfplus 3d text node
	class gltfplus3d_text_node : public gfx3d_scg_3dtext_node
	{
    public:
		/// <summary>
		/// constructor
		/// <param name="p_node">tiny gltf node</param>
		/// <param name="p_dsp">renderCore display object</param>
		/// <param name="p_parent">renderCore parent object</param>
		/// </summary>
		gltfplus3d_text_node(const size_t p_node_index, gfx3d_scg_display * p_dsp, gfx3d_scg_node * p_parent);
    };
    /// @}
}

#endif