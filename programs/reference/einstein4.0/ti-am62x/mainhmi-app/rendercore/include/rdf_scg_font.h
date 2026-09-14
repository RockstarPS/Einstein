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
//  Filename    : rdf_scg_font.h
//  Description : rdf project loader it contains code related of rdf generated structure
//  Created on  : 24th Jan 2019 by mpandey@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  rdf_scg_font.h
///	\brief 	   rdf project loader it contains code related of rdf generated structure
#ifndef rdf_scg_font_h
#define rdf_scg_font_h

#include "rdf_scg_project.h"
#include "gfx3d_scg.h"

namespace rendercore_engine 
{
    /// \ingroup Loader
    /// @{

    /// font class for rdf, extending gfx3d scg font class
    class rdf_scg_font : public gfx3d_scg_font
    {
    private:
    public:
		///  
		///constructor
		///
		///\param p_proj : rdf project 
		///\param p_font : loads the font
		///
		rdf_scg_font(rdf_scg_project * const p_proj);
        void LoadData(rdf_font const* const p_font);
        virtual ~rdf_scg_font();
    };
    /// @}
}

#endif