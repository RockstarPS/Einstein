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
//  Filename    : gfx3d_scg_material_group.h
//  Description : Wrapper Class for the gltf material group. This holds the 
//                references to all instances of a material						
//  Created on  : 10-Aug-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_scg_material_group.h
/// \brief Wrapper Class for the gltf material group. This holds the 
/// references to all instances of a material

#ifndef gfx3d_scg_material_group_h
#define gfx3d_scg_material_group_h

namespace rendercore_engine
{
    /// \ingroup Engine
    /// @{
	/// <summary>
    /// The graphics 3D scg material group.  
	/// a material can be used by multiple primitives. So a parent material
    /// keeps track of the instances and if anyone tries to update a material
    /// property of parent class, then all childs are updated..
	/// </summary>
    class gfx3d_scg_material_group : public gfx3d_scg_material
    {
    private:
        ///< child materials of this group
        std::vector<gfx3d_scg_material *> childrens;
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
        mutable std::recursive_mutex data_mutex; ///< mutex to protect all data access by threads
#endif
    public:
        /// Distructor
        virtual ~gfx3d_scg_material_group(void);
        /// <summary>
        /// Constructs a material group
        /// </summary>
        /// <param name="p_disp"> parent display this accessor belongs to </param>
        gfx3d_scg_material_group(gfx3d_scg_display * const p_disp);
		/// set float32_t to passed uniforms. Sets value to all available child materials
        void SetFloat(const std::string p_uniform, const float32_t p_val) override;
		/// get float32_t value from first material of group
        float32_t GetFloat(const std::string p_uniform) override;
		/// set int to passed uniforms. Sets value to all available child materials
        void SetInt(const std::string p_uniform, const int32_t p_val) override;									
		/// get int from first material of group
        int32_t GetInt(const std::string p_uniform) override;
		/// set vec2 to passed uniforms. Sets value to all available child materials
        void SetVector(const std::string p_uniform, const glm::vec2 p_val) override;
		/// set vec3 to passed uniforms. Sets value to all available child materials
        void SetVector(const std::string p_uniform, const glm::vec3 p_val) override;
		/// set vec4 to passed uniforms. Sets value to all available child materials
        void SetVector(const std::string p_uniform, const glm::vec4 p_val) override;
		/// set mat4 to passed uniforms. Sets value to all available child materials
        void SetMatrix(const std::string p_uniform, const glm::mat4 p_val) override;
		/// set mat3 to passed uniforms. Sets value to all available child materials
        void SetMatrix(const std::string p_uniform, const glm::mat3 p_val) override;
		/// set mat2 to passed uniforms. Sets value to all available child materials
        void SetMatrix(const std::string p_uniform, const glm::mat2 p_val) override;
		/// set texture to passed uniforms. Sets value to all available child materials
        void SetTexture(const std::string p_uniform, gfx3dTexture2D * const p_val) override;
        /// Adds passed material to list and return its index
        int32_t AddChildren(gfx3d_scg_material * const p_material) override;
        /// Get the count of child materials in list
        size_t GetChildCount() const;
        /// Get the child at index from materials list
        gfx3d_scg_material* GetChild(const size_t p_index);

    };
    /// @}
}

#endif//gfx3d_scg_material_h