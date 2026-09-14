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
//  Filename    : rdf_scg_display.h
//  Description : it is a display class and contains graphics data for display
//  Created on  : 25-Jan-2018 by mpandey@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file rdf_scg_display.h
/// \brief 		  it is a display class and contains graphics data for display
#ifndef rdf_scg_display_h
#define rdf_scg_display_h

#include "rdf_types.h"
#include "rdf_scg_node.h"
#include "rdf_scg_project.h"

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{

    /// rdf display class extending gfx3d scg display
	class rdf_scg_display : public gfx3d_scg_display
	{
    private:
        rdf_display const * config;	///< config for rdf_dsplay
        size_t LookupScene(const std::string p_sceneName) override;
    public:
		///  
		///constructor
		///
		rdf_scg_display(rdf_scg_project * const p_proj, rdf_display const * const p_display);
        virtual ~rdf_scg_display();
		/// returns the display 
		rdf_display const * GetDisplay(void) const;
        /// loads the scene
        void CreateScene(const size_t p_index) override;
        /// <summary>
        /// Creates the animation nodes for the all anims.
        /// </summary>
        void CreateAnim() override;
        /// <summary>
        /// Creates the animation nodes for the requested id/index.
        /// </summary>
        /// <param name="p_index">index of animation to load</param>
        void CreateAnim(const size_t p_index) override;
        /// For Internal usage to get the float32_t data at a given index
        float32_t const * get_node_floatdata(const int32_t p_index, const size_t p_length) const;
    };
    /// @}
}

#endif