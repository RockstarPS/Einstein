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
//  Filename    : rdf_scg_cmap_text.h
//  Description : it is a display class and contains graphics data for cubemap textures
//  Created on  : 25-Jan-2018 by mpandey@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  rdf_scg_cmap_tex.h
/// \brief		   it is a display class and contains graphics data for cubemap textures
#ifndef rdf_scg_cmap_texture_h
#define rdf_scg_cmap_texture_h

#include "gfx3d_scg.h"
#include "rdf_types.h"

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{

    /// cubemap texture class, extends gfx3d scg cubemap
    class rdf_scg_cmap_texture : public gfx3d_scg_cmap_texture
	{
    private:
    public:
		///  
		///constructor
		///
		rdf_scg_cmap_texture(rdf_scg_display * const p_disp, rdf_cmap_texture const * const p_image);
	};
    /// @}
}
#endif