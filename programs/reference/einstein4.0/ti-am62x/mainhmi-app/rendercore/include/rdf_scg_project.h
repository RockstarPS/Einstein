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
//  Filename    : rdf_scg_project.h
//  Description : rdf project loader it contains code related of rdf generated structure
//  Created on  : 24th Jan 2019 by mpandey@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file rdf_scg_project.h
///	\brief 	  rdf project loader it contains code related of rdf generated structure
#ifndef rdf_scg_project_h
#define rdf_scg_project_h

#include "rdf_types.h"

namespace rendercore_engine 
{
    /// \defgroup Loader Loader Classes
    /// <summary>
    /// classes which support loading of project to rendercore
    /// </summary>

    /// \ingroup Loader
    /// @{

    /// rdf scg project, extended from gfx3d scg project
    class rdf_scg_project : public gfx3d_scg_project
	{
	private:
		const rdf_project* rdfProj;
	public:
		///  
		///constructor
		///
		///\param p_proj : rdf project 
		///\param p_respath : path of gltf file 
		///
		rdf_scg_project(const rdf_project * const p_proj, const CHAR8* const p_respath = nullptr, const rc_pfm_cfg_ibase& p_pfgConfig = gfx3d_scg_project::getDefaultProjectConfig());
		/// <summary>
		/// Return the point size for the passed font Id from rdf
		/// </summary>
		/// <param name="p_index">index to the font</param>
		/// <returns>point size</returns>
		float32_t GetRdfFontSize(const uint32_t p_index) const;
	};
    /// @}
}

#endif