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
//  Filename    : rdf_scg_skin.h
//  Description : GLTF scene graph adaptation for tiny gltf. inherited from base
//  scenegraph classes and data parsed and loaded from tiny gltf data structures
//  Created on  : 10-Aug-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file rdf_scg_skin.h
///	\brief 	  GLTF scene graph adaptation for tiny gltf. inherited from base
///	\brief 		scenegraph classes and data parsed and loaded from tiny gltf data structures

#ifndef rdf_scg_skin_h
#define rdf_scg_skin_h

#include "rdf_types.h"

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{
    
    /// rdf scg node class, extending gfx3d scg node
	class rdf_scg_skin : public gfx3d_scg_skin
	{
	public:
		///constructor
		///\param p_disp  gfx3d scg display object
		///\param p_rdfskin  rdf skin data
        rdf_scg_skin(const rdf_skin* const p_rdfskin, rdf_scg_display* const p_disp);
    };
    /// @}
}

#endif