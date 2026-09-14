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
//  Filename    : rdf_scg_rtarget.h
//  Description : rdf project loader it contains code related of rdf generated structure
//  Created on  : 24th Jan 2019 by mpandey@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file rdf_scg_rtarget.h
///		 \brief  GFX3D scene graph font object.
#ifndef rdf_scg_font_h
#define rdf_scg_font_h

namespace rendercore_engine 
{
    /// \ingroup Loader
    /// @{

    /// rdf render target class
    class rdf_scg_rtarget : public gfx3d_scg_rtarget
    {
    private:
    public:
		///  
		///constructor
		///
		///\param p_proj : rdf project 
		///\param p_item : target object to retreive data
		///
		rdf_scg_rtarget(rdf_scg_display * const p_disp, rdf_rtarget const * const p_item);
        virtual ~rdf_scg_rtarget();
    };
    /// @}
}

#endif