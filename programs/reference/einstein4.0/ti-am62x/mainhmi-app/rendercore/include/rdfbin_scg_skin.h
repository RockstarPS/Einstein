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
//  Filename    : rdfbin_scg_skin.h
//  Description : rdf bin loader scene graph skin object
//  Created on  : 1-Sep-2021 by ssharm20@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file rdfbin_scg_skin.h
///	\brief 	  rdf bin loader scene graph skin object

#ifndef rdfbin_scg_skin_h
#define rdfbin_scg_skin_h

#include "rc_rdfbin_type.h"
#include "gfx3d_scg.h"

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{
    
    /// rdf bin scg skin class, extending gfx3d scg skin
	class rdfbin_scg_skin : public gfx3d_scg_skin
	{
	public:
		///constructor
		///\param p_disp  gfx3d scg display object
		///\param p_rdfskin  rdf skin data
        rdfbin_scg_skin(const rdfbin_Skin* const p_rdfskin, rdfbin_scg_display* const p_disp);
    };
    /// @}
}

#endif