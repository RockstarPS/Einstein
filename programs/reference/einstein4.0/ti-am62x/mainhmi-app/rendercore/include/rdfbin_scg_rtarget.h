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
//  Filename    : rdfbin_scg_rtarget.h
//  Description : rdf bin render target
//  Created on  : 25th Aug 2021 by ssharm20@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file rdfbin_scg_rtarget.h
///		 \brief  render target for rdf bin loader.
#ifndef rdfbin_scg_rtarget_h
#define rdfbin_scg_rtarget_h

#include "gfx3d_scg.h"

namespace rendercore_engine 
{
    /// \ingroup Loader
    /// @{

    /// rdf binary render target class
    class rdfbin_scg_rtarget : public gfx3d_scg_rtarget
    {
    private:
    public:
		///  
		///constructor
		///
		///\param p_proj : rdf bin project 
		///\param p_item : target object to retreive data
		///
		rdfbin_scg_rtarget(rdfbin_scg_display * const p_disp, rdfbin_RenderTarget const * const p_item);
        virtual ~rdfbin_scg_rtarget();
    };
    /// @}
}

#endif