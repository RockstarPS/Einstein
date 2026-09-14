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
//  Filename    : gltfscg_tinygltf_anim.h
//  Description : animation adaptation for tiny GLTF data. Inherited from the
//  base anim class and data loaded by parsing tiny gltf data structures		
//  Created on  : 10-Aug-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gltfplus_scg_anim.h
///	\brief animation adaptation for tiny GLTF data. Inherited from the
/// base anim class and data loaded by parsing tiny gltf data structures
#ifndef gltfplus_scg_anim_h
#define gltfplus_scg_anim_h

#include "gfx3d_scg_anim.h"
#include "rdf_types.h"

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{

    /// <summary>
	/// Holds the handling to load animation date and as well run the animations 
	/// </summary>
	class gltfplus_scg_anim : public gfx3d_scg_anim
	{
	private:
        tinygltf::Animation * animation;
	public:
        ~gltfplus_scg_anim();
		/// <summary>
		/// Constructor. accepts the tinygltf display as input and then extracts the animation channels in to internal storage.
		/// </summary>
		gltfplus_scg_anim(gltfplus_scg_display * p_root, tinygltf::Animation * p_anim);
	};
    /// @}
}

#endif