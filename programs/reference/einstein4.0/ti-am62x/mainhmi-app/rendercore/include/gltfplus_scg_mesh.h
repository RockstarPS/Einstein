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
/// @file gltfplus_scg_mesh.h
///	\brief  gltfplus scg mesh class, contains primitives
#ifndef gltfplus_scg_mesh_h
#define gltfplus_scg_mesh_h
#include "tinygltf_if.h"
#include "gfx3d_scg.h"

//#include "rdf_project.h"
//#include "gltfscg_tinygltf_cubemap_extn.h"

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{

	/// <summary>
	/// gltfplus_scg_mesh contains all the primitives used, gltfplus_scg_mesh will essentially load gltfplus_scg_primitives, 
	/// </summary>
	class gltfplus_scg_mesh : public gfx3d_scg_mesh
	{
	public:
		/// <summary>
		/// constructor
		/// </summary>
		/// <param name="p_mesh"> tinygltf mesh object to be loaded</param>
		/// <param name="p_dsp"> mesh object information will be loaded into p_dsp scg display object</param>
		gltfplus_scg_mesh(tinygltf::Mesh* p_mesh, gfx3d_scg_display * p_dsp);
    };
    /// @}
}

#endif