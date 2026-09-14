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
//  Filename    : rdfbin_scg_primitive.h
//  Description : primitive adaptation for rdf bin loader primitives
//  Created on  : 30-Aug-2021 by ssharm20@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file rdfbin_scg_primitive.h
///	\brief 	  primitive adaptation for rdf bin loader primitives
#ifndef rdfbin_scg_primitive_h
#define rdfbin_scg_primitive_h

#include "gfx3d_scg.h"

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{
    
    /// rdf bin scg primitive class, extends gfx3d scg primitive
	class rdfbin_scg_primitive : public gfx3d_scg_primitive
	{
	public:
		///  
		///constructor
		///
		rdfbin_scg_primitive(rdfbin_scg_display* const p_disp, rdfbin_Primitive const * const p_prim);
    };
    /// @}
}

#endif