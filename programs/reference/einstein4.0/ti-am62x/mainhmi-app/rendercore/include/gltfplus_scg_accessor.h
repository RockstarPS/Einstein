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
//  Filename    : gfx3d_scg_accessor.h
//  Description : GFX3D scene graph accessor object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file	 gltfplus_scg_accessor.h
///	\brief	 GFX3D scene graph accessor object
#ifndef gltfplus_scg_accessor_h
#define gltfplus_scg_accessor_h
#include "tinygltf_if.h"

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{

    /// <summary>
	/// Starting point or display of the scene graph
	/// </summary>
	class gltfplus_scg_accessor : public gfx3d_scg_accessor
	{
	protected:
    public:
		/// <summary>
		/// Constructor. accepts the display as input and then extracts the accessors into internal storage.
		/// </summary>
		gltfplus_scg_accessor(gltfplus_scg_display * p_disp, tinygltf::Accessor p_item);
		~gltfplus_scg_accessor();
	};
    /// @}
}
#endif