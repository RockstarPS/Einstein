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
//  Filename    : rdf_scg_layout.h
//  Description :  3d layout node for scg where data from gltf will be loaded
//  Created on  : 26-11-2019 by amorwal@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  rdf_scg_layout.h
///	\brief 	    3d layout node for scg where data from gltf will be loaded

#ifndef rdf_scg_layout_h
#define rdf_scg_layout_h

#include "rdf_scg_node.h"

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{

    /// <summary>	rdf scg layout node. 
	/// The layout node loaded will be stored in rdf_layout
	/// </summary>
	class rdf_scg_layout: public gfx3d_scg_layout
	{
    private:
        int32_t lnodeIndex = -1;
    protected:
        ///< Loads all the assets required by this node
        /// <param name="p_scene">id of the scene which is requesting this text node load</param>
        /// <param name="p_depth">depth of the node. used to prevent indefinite recursion</param>
        /// <param name="p_lrule">resource loading rule</param>
        /// <param name="p_visible">visibility of parent node, may affect resource loading depending on p_mode</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        virtual bool Load(const size_t p_scene, const size_t p_depth, const MdlResourceLoadRule p_lrule = MdlResourceLoadRule::All, const bool p_visible = true) override;       ///< Loads all the dynamic assets required by this node
    public:
		/// constructor
		rdf_scg_layout(const int32_t p_node_index, rdf_scg_display* const p_dsp, gfx3d_scg_node * const p_parent);
        virtual ~rdf_scg_layout();
	};
    /// @}
}

#endif