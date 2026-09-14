///////////////////////////////////////////////////////////////////////////////
//
//                     CONFIDENTIAL VISTEON CORPORATION
//
// This is an unpublished work of authorship, which contains trade secrets,
// created in 2022. Visteon Corporation owns all rights to this work and
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
//  Filename    : rdfbin_scg_light.h
//  Description : rdfbin light loader object
//  Created on  : 23-Nov-2022 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  rdfbin_scg_light_h.h
///	\brief 	   rdfbin light loader object 
#ifndef rdfbin_scg_light_h
#define rdfbin_scg_light_h

#include "gfx3d_scg.h"

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{

    /// rdf scg light class, extending gfx3d scg light class 
	class rdfbin_scg_light : public gfx3d_scg_light
	{
	public:
        rdfbin_scg_light(const rdfbin_Light* const p_lightdata, const rdfbin_scg_display* const p_dsp);
    private:
    };
    /// @}
}

#endif