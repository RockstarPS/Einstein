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
//  Filename    : gltfplus_scg_material.h
//  Description : types required for the render core data format.
//  Created on  : 02-Jan-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file   gltfplus_scg_material.h
///	\brief	types required for the render core data format.
#ifndef gltfplus_scg_material_h
#define gltfplus_scg_material_h

#include "gfx3d_scg.h"

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{

    /// <summary>
    /// gltfplus material class, extends gfx3d scg material class
    /// If primitives have materials then this class is used to store that information.
    /// Based on the information contained within gltf model materials will load appropriate shaders.
    /// </summary>
    class gltfplus_scg_material : public gfx3d_scg_material
    {
    public:
		/// <summary>
		/// Constructor. accepts the gltfplus display as an input and then extracts the image information from tinygltf::Material.
		/// <param name="p_disp">gltfplus display</param>
		/// <param name="p_item">tinygltf Material</param>
		/// </summary>
		gltfplus_scg_material(gfx3d_scg_display *p_disp, tinygltf::Material * p_item, int32_t p_uid, const std::string& p_defines);
        ~gltfplus_scg_material();
		/// set float32_t uniform
		void SetFloat(const std::string p_uniform, const float32_t p_val) override;
		/// get uniform
        float32_t GetFloat(const std::string p_uniform) override;
        static void RenderEnvironment(gfx3d_scg_display* p_disp, const rendercore_engine::float32_t p_rot, const glm::mat4& p_vp);
        static void SetEnvironment(gfx3d_scg_display* p_disp, std::string p_env);
        static void Reset(gfx3d_scg_project* const p_prj);
    private:
        void generate_materials(tinygltf::Material * p_mat, const std::string& p_defines);
        GLuint GetSO(std::map<std::string, GLuint> * p_map, std::string p_id);
#ifndef __QNX660__
        bool process_KHR_texture_transform_extn(const tinygltf::Value& p_tex, int32_t& p_texcord, const std::string& p_uform);
        bool process_KHR_texture_transform(const tinygltf::Value& p_tex, int32_t& p_texcord, const std::string& p_uform);
        bool process_KHR_texture_transform_extn(const tinygltf::ExtensionMap& p_ext, int32_t& p_texcord, const std::string& p_uform);
        bool process_KHR_materials_sheen(tinygltf::Material* const p_mat, std::string& p_defines);
        bool process_KHR_materials_clearcoat(tinygltf::Material* const p_mat, std::string& p_defines);
        bool process_KHR_materials_ior(tinygltf::Material* const p_mat, std::string& p_defines);
        bool process_KHR_materials_specular(tinygltf::Material* const p_mat, std::string& p_defines);
        bool process_KHR_materials_transmission(tinygltf::Material* const p_mat, std::string& p_defines);
        bool process_KHR_materials_unlit(tinygltf::Material* const p_mat, std::string& p_defines);
        bool process_KHR_materials_volume(tinygltf::Material* const p_mat, std::string& p_defines);
        bool process_KHR_lights_punctual(tinygltf::Material* const p_mat, std::string& p_defines);
#endif
    };
    /// @}
}

#endif