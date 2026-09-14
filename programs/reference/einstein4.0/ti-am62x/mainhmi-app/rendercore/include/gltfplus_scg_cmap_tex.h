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
//  Filename    : gltfplus_scg_cmap_texture.h
//  Description : it is a display class and contains graphics data for cubemap textures
//  Created on  : 25-Jan-2018 by mpandey@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file	gltfplus_scg_cmap_tex.h
///	\brief	it is a display class and contains graphics data for cubemap textures
#ifndef gltfplus_scg_cmap_texture_h
#define gltfplus_scg_cmap_texture_h

#include "gfx3d_scg.h"
#include "rdf_types.h"
#include "tinygltf_if.h"

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{
    
    /// <summary>
	/// loads cubemap if present using tinygltf::Value
	/// </summary>
	class gltfplus_scg_cmap_texture : public gfx3d_scg_cmap_texture
	{
    private:
    public:
		/// constructor 
		gltfplus_scg_cmap_texture(gltfplus_scg_display * p_disp, tinygltf::Value p_image);
	};
    /// @}
}
#endif