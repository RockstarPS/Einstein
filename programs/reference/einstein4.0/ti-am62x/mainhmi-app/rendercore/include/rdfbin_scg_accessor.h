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
//  Filename    : rdfbin_scg_accessor.h
//  Description : rdf binary loader scene graph accessor object
//  Created on  : 25-Aug-2021 by ssharm20@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file rdfbin_scg_accessor.h
/// \brief	rdf binary loader scene graph accessor object
#ifndef rdfbin_scg_accessor_h
#define rdfbin_scg_accessor_h
#include "gfx3d_scg.h"
#include "rdfbin_scg_display.h"

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{

    /// <summary>
	/// rdf binary loader scene graph accessor object
	/// </summary>
	class rdfbin_scg_accessor : public gfx3d_scg_accessor
	{
	protected:
    public:
		///  
		///constructor
		///
		///\param p_disp  rdf bin scg display
		///\param p_item to be loaded from rdf binary
		///
		rdfbin_scg_accessor(rdfbin_scg_display * const p_disp, rdfbin_Accessor const * const p_item);
		/// destructor
		virtual ~rdfbin_scg_accessor();
	};

    /// @}
    /// \ingroup Loader
    /// @{

	/// buffer view class for rdf binary project
	class rdfbin_scg_bufferview : public gfx3d_scg_bufferview
    {
    protected:
    public:
		///  
		///constructor
		///
		///\param p_disp : rdf bin scg display
		///\param p_item : bufferview to be loaded from rdf binary
		///
		rdfbin_scg_bufferview(rdfbin_scg_display * const p_disp, rdfbin_BufferView const * const p_item);
		/// destructor
		virtual ~rdfbin_scg_bufferview();
    };
    /// @}
}

#endif