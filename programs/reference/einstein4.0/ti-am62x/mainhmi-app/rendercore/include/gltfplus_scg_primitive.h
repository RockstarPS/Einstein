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
/// @file	gltfplus_scg_primitive.h
///	\brief	GLTF primitive adaptation for tiny gltf. 

#ifndef rdf_scg_primitive_h
#define rdf_scg_primitive_h

#include "gfx3d_scg.h"
#include "gltfplus_scg_mesh.h"
#include "tinygltf_if.h"

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{

	/// <summary>
	/// in gltf structure primitive is a part of mesh we fetch primitive information from tinygltf::Model.
	/// </summary>
	class gltfplus_scg_primitive : public gfx3d_scg_primitive
	{
	public:
		/// <summary>
		/// Constructor. accepts the gltfplus display, primitive, and model as input, then extracts the primitive information into tinygltf::primitive.
		/// If materials are present alongside primitives, we also fetch that information and store it inside gltfplus_scg_material
		/// <param name="p_dsp">gltfplus display</param>
		/// <param name="p_prim">tinygltf primitive</param>
		/// </summary>
		gltfplus_scg_primitive(gfx3d_scg_display * p_dsp, tinygltf::Primitive * p_prim);
    };
    /// @}
}

#endif