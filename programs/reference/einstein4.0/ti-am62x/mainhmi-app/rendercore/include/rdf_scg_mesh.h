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
//  Filename    : rdf_scg_mesh.h
//  Description : mesh adaptation for tiny gltf. 
//  Created on  : 10-Aug-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  rdf_scg_mesh.h
///	\brief 	   mesh adaptation for tiny gltf. 
#ifndef rdf_scg_mesh_h
#define rdf_scg_mesh_h

#include "gfx3d_scg.h"

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{

    /// rdf scg mesh class, extending gfx3d scg mesh class 
	class rdf_scg_mesh : public gfx3d_scg_mesh
	{
	public:
		//MatExtnCubemap cmap;
		///  
		///constructor
		///
		rdf_scg_mesh(const int32_t p_mesh_index, rdf_scg_display* const p_dsp);
    private:
    };
    /// @}
}

#endif