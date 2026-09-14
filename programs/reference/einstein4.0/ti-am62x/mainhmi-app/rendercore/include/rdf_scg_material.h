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
//  Filename    : rdf_scg_material.h
//  Description : types required for the render core data format.
//  Created on  : 02-Jan-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  rdf_scg_material.h
///	\brief 	   types required for the render core data format.
#ifndef rdf_scg_material_h
#define rdf_scg_material_h

#include "gfx3d_scg.h"

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{
    
    /// rdf scg material class, extends gfx scg material
    class rdf_scg_material : public gfx3d_scg_material
    {
    public:
		///  
		///constructor
		///
		///\param p_disp : gfx3d scg display
		///\param p_item : rdf material to be loaded
		///
        rdf_scg_material(gfx3d_scg_display * const p_disp, const int32_t p_item, rdf_display const* const p_rdsp);
    private:
        /// <summary>
        /// sets default uniform data
        /// </summary>
        void set_uniform_default_data(rdf_shaderDefData const* const p_udata, const size_t p_size);
        rdf_material const * matDef = nullptr;
        const float32_t* defVectorData = nullptr;
        uint32_t defVectorDataSize = 0U;
        float32_t get_deffloatdata(const int32_t p_index) const;
        glm::vec2 get_defvec2data(const int32_t p_index) const;
        glm::vec3 get_defvec3data(const int32_t p_index) const;
        glm::vec4 get_defvec4data(const int32_t p_index) const;
        glm::mat4 get_defmat4data(const int32_t p_index);
        glm::mat3 get_defmat3data(const int32_t p_index);
        glm::mat2 get_defmat2data(const int32_t p_index);
    };
    /// @}
}

#endif