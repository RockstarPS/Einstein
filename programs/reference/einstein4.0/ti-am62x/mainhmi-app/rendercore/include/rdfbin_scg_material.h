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
//  Filename    : rdfbin_scg_material.h
//  Description : class for rdf binary shader handling.
//  Created on  : 26-Aug-2021 by ssharm20@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  rdf_scg_material.h
///	\brief 	material adaptation for rdf binary loader.
#ifndef rdfbin_scg_material_h
#define rdfbin_scg_material_h

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{
    
    /// rdf bin scg material class, extends gfx scg material
    class rdfbin_scg_material : public gfx3d_scg_material
    {
    public:
		///  
		///constructor
		///
		///\param p_disp : gfx3d scg display
		///\param p_item : rdfbin material to be loaded
		///
        rdfbin_scg_material(gfx3d_scg_display * const p_disp, const int32_t p_item, rdfbin_Display const* const p_rdsp);
    private:
        /// <summary>
        /// sets default uniform data
        /// </summary>
        void set_uniform_default_data(rdfbin_scg_project const* const p_rdfbinProj, const size_t p_udataOffset, const size_t p_size);
        float32_t get_deffloatdata(rdfbin_scg_project const* const p_rdfbinProj, const int32_t p_index) const;
        glm::vec2 get_defvec2data(rdfbin_scg_project const* const p_rdfbinProj, const int32_t p_index) const;
        glm::vec3 get_defvec3data(rdfbin_scg_project const* const p_rdfbinProj, const int32_t p_index) const;
        glm::vec4 get_defvec4data(rdfbin_scg_project const* const p_rdfbinProj, const int32_t p_index) const;
        glm::mat4 get_defmat4data(rdfbin_scg_project const* const p_rdfbinProj, const int32_t p_index) const;
        glm::mat3 get_defmat3data(rdfbin_scg_project const* const p_rdfbinProj, const int32_t p_index) const;
        glm::mat2 get_defmat2data(rdfbin_scg_project const* const p_rdfbinProj, const int32_t p_index) const;
    };
    /// @}
}

#endif