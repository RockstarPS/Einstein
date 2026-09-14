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
//  Filename    : rdfbin_scg_project.h
//  Description : rdfbin project loader it contains code related of rdf generated structure
//  Created on  : 18th Aug 2021 by ssharm20@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file rdfbin_scg_project.h
///	\brief 	  rdfbin project loader it contains code related of rdf generated structure
#ifndef rdfbin_scg_project_h
#define rdfbin_scg_project_h
#include "gfx3d_scg.h"
#include "rc_rdfbin_type.h"

namespace rendercore_engine 
{
    /// \defgroup Loader Loader Classes
    /// <summary>
    /// classes which support loading of project to rendercore
    /// </summary>
    /// \ingroup Loader
    /// @{

    /// rdf scg project, extended from gfx3d scg project
    class rdfbin_scg_project : public gfx3d_scg_project
	{
	private:
		CHAR8 const* binbytes;
		const rdfbin_Project* rdfBinProj;
		size_t dataLength;
		const rdfbin_script_ibase& iScript;
	public:
		///  
		///constructor
		///\param p_bin_uri : path of bin file
		///\param p_iscript : interface for scripts
		///\param p_respath : path where assets are located 
		///\param p_pfgConfig: configuration interface 
		///
		rdfbin_scg_project(const CHAR8* const p_bin_uri, const rdfbin_script_ibase& p_iscript, const CHAR8* const p_respath = nullptr, const rc_pfm_cfg_ibase& p_pfgConfig = gfx3d_scg_project::getDefaultProjectConfig());
		rdfbin_scg_project& operator= (const rdfbin_scg_project& p_src)=delete;
		//copy construct
		rdfbin_scg_project(const rdfbin_scg_project& p_obj)=delete;
		virtual ~rdfbin_scg_project();
		/// <summary>
		/// Return the point size for the passed font Id from rdf
		/// </summary>
		/// <param name="p_index">index to the font</param>
		/// <returns>point size</returns>
		float32_t GetRdfFontSize(const uint32_t p_index) const;
		/// <summary>
		/// Get bytes loaded from binary file
		/// </summary>
		/// <returns></returns>
		CHAR8 const* GetBytes() const;
		/// For Internal usage to get the float32_t data at a given index
		const float32_t* get_floatData(const int32_t p_index, const size_t p_length) const;
		/// For Internal usage to get the int32_t data at a given index
		const int32_t* get_intData(const int32_t p_index, const size_t p_length) const;
		/// For Internal usage to get the CHAR8 data at a given index
		const CHAR8* get_stringData(const uint32_t p_index, const size_t p_length = 0U) const;
		bool IsValidIndex(const size_t p_index, const size_t p_length) const;
		/// <summary>
		/// Checks if timestamp of scripts matches with the rdfbin project, 
		/// </summary>
		/// <returns>true or false : if timestamp matches</returns>
		bool IsScriptValid() const;
		/// <summary>
		/// Loads the default values to behaviour 'p_rdfBeh'
		/// </summary>
		/// <param name="p_rdfbinBeh">default data source</param>
		/// <param name="p_rdfBeh">target behavior, where the data will be loaded</param>
		void SetCustPropDefaultData(rdfbin_Display const* const p_display, rdfbin_behaviour const* const p_rdfbinBeh, rdf_behaviour* const p_rdfBeh);
		const rdfbin_script_ibase& GetIScript() const;
	};
	/// @}
}

#endif