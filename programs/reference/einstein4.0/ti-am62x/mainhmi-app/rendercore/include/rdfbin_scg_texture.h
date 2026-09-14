///////////////////////////////////////////////////////////////////////////////
//
//                     CONFIDENTIAL VISTEON CORPORATION
//
// This is an unpublished work of authorship, which contains trade secrets,
// created in 2021. Visteon Corporation owns all rights to this work and
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
//  Filename    : rdfbin_scg_texture.h
//  Description : it contains graphics data for textures
//  Created on  : 25-Aug-2021 by ssharm20@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  rdfbin_scg_texture.h
/// \brief		   it contains graphics data for textures
#ifndef rdfbin_scg_texture_h
#define rdfbin_scg_texture_h

#include "rc_rdfbin_type.h"
#include "gfx3d_scg.h"

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{
    
    /// texture class, extends gfx3d scg texture
    class rdfbin_scg_texture : public gfx3d_scg_texture
	{
    private:
    public:
		///constructor
		rdfbin_scg_texture(rdfbin_scg_display * const p_disp, rdfbin_Texture const * const p_image);
	};
    /// @}
}
#endif