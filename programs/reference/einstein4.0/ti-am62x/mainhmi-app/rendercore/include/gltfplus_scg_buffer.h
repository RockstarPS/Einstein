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
//  Filename    : gltfplus_scg_buffer.h
//  Description : creates buffer from tinygltf
//  Created on  : 10-Apr-2019 by amorwal@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gltfplus_scg_buffer.h
///	\brief creates buffer from tinygltf
#ifndef gltfplus_scg_buffer_h
#define gltfplus_scg_buffer_h

#include "gfx3d_scg.h"
#include "gltfplus_scg_display.h"

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{
    
    /// <summary>
	/// gltfplus scene graph buffer object
	/// </summary>
	class gltfplus_scg_buffer : public gfx3d_scg_buffer
	{
	protected:
	public:
		/// <summary>
		/// Constructor. accepts the gltfplus display as input and then extracts the buffer information into internal storage.
		/// </summary>
		/// <param name="p_disp">gltfplus display</param>
		/// <param name="p_item">tinygltf buffer</param>
		gltfplus_scg_buffer(gltfplus_scg_display * p_disp, tinygltf::Buffer p_item);
		~gltfplus_scg_buffer();
	};
    /// @}
};
#endif