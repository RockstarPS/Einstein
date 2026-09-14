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
//  Filename    : rdfbin_scg_font.h
//  Description : rdf binary generated font
//  Created on  : 24th Aug 2021 by ssharm20@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  rdfbin_scg_font.h
///	\brief 	   rdf binary font
#ifndef rdfbin_scg_font_h
#define rdfbin_scg_font_h

#include "rdfbin_scg_project.h"

namespace rendercore_engine 
{
    /// \ingroup Loader
    /// @{

    /// font class for rdf binary, extending gfx3d scg font class
    class rdfbin_scg_font : public gfx3d_scg_font
    {
    public:
		///  
		///constructor
		///
		///\param p_proj : rdf bin project 
		///\param p_font : loads the font
		///
		rdfbin_scg_font(rdfbin_scg_project * const p_proj);
        void LoadData(rdfbin_Font const* const p_font);
        virtual ~rdfbin_scg_font();
    };
    /// @}
}

#endif