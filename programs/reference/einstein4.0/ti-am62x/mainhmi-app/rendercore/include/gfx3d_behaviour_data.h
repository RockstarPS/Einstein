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
//  Filename    : gfx3d_behaviour_data.h
//  Description : GFX3D behaviour custom data object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_behaviour_data.h
/// \brief GFX3D behaviour object
#ifndef gfx3d_behaviour_data_h
#define gfx3d_behaviour_data_h

namespace rendercore_engine
{
    /// \defgroup Internal Internal Classes
    /// <summary>
    /// support classes of rendercore engine
    /// </summary>

    /// \ingroup Internal
    /// @{

    /// <summary>
    /// Defines a custom property value.
    /// </summary>
    class rdf_propValue
    {
    public:
        int32_t ival = 0;                                 ///< prop value int 
        uint32_t uival = 0U;                              ///< prop value unsigned int
        float32_t fltval[4] = { 0.0F, 0.0F, 0.0F, 0.0F }; ///< prop value float32_t, vec2,vec3,vec4
        std::string sval;	                              ///< prop value string
        rdf_propValue();
    };

    /// @}
    /// \ingroup Internal
    /// @{

    /// <summary>
    /// Defines a custom property entry in rdf_behaviour
    /// </summary>
    class rdf_behData
    {
    public:
        mdl_cPropType type;								///< prop type
        rdf_propValue def;								///< prop value
        rdf_behData();									///< constructor
        explicit rdf_behData(const uint32_t p_val);	    ///< constructor for uint type data
        explicit rdf_behData(const float32_t p_val);	///< constructor for float32_t type data
        rdf_behData(const glm::vec2 p_val);				///< constructor for vector type data
        rdf_behData(const glm::vec3 p_val);				///< constructor for vector type data
        rdf_behData(const glm::vec4 p_val);				///< constructor for vector type data
        rdf_behData(const std::string p_val);			///< constructor for vector type data
        rdf_behData(const mdl_cPropType p_type, const int32_t p_val);	 ///< constructor for p_type data
        rdf_behData(const mdl_cPropType p_type, const std::string p_val);///< constructor for p_type data
    };

    /// @}
}
#endif