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
/// @file  gltfplus_scg_project.h
///	\brief gltfplus project loader it contains code related of rdf generated structure
#ifndef gltfplus_scg_project_h
#define gltfplus_scg_project_h

#include "gfx3d_scg.h"
#include "tinygltf_if.h"

namespace rendercore_engine 
{
    /// \ingroup Loader
    /// @{
    
    /// <summary>
	/// gltfplus_scg_project parse gltf and , extract model which will be used to fetch other data structures from the model
	/// </summary>
	class gltfplus_scg_project: public gfx3d_scg_project
	{
	public:
		/// constructor
		gltfplus_scg_project(unsigned long bufsize,const CHAR8* p_buffer=NULL, const rc_pfm_cfg_ibase& p_pfgConfig = gfx3d_scg_project::getDefaultProjectConfig());
		gltfplus_scg_project(const CHAR8* p_gltfpath, const rc_pfm_cfg_ibase& p_pfgConfig = gfx3d_scg_project::getDefaultProjectConfig());
		gltfplus_scg_project();
        ~gltfplus_scg_project();
		tinygltf::Model* GetGltfModel();
		void LoadGltf(const std::string& p_path, const MdlAssetLoadMode p_mode = MdlAssetLoadMode::Synchronous);
		static glm::vec2 GetPlayerConfigDim(const size_t p_display);
		static bool GetPlayerConfigOverrideAspect(const size_t p_display);
	private:
        tinygltf::Model * model;
		void add_gltf();
		void load_font_property();
		void load_player_config();
	};
    /// @}
}

#endif