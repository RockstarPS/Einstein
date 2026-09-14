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
//  Filename    : rdfbin_scg_node.h
//  Description : scene graph node adaptation for rdf bin loader
//  Created on  : 1-Sep-2021 by ssharm20@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file rdfbin_scg_node.h
///	\brief 	  scene graph node adaptation for rdf bin loader

#ifndef rdfbin_scg_node_h
#define rdfbin_scg_node_h

#include "gfx3d_scg.h"
#include "rdfbin_scg_display.h"
#include "rc_rdfbin_type.h"
namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{
    struct rdfbin_Display;
    struct rdfbin_Node;
    //const rc_behaviour_getinst RcRdfBinGetBehaviourGetinst(const uint32_t p_scriptIndex);

    /// rdf bin scg node class, extending gfx3d scg node
	class rdfbin_scg_node: public gfx3d_scg_node
	{
    private:
        int32_t lnodeIndex;
	protected:
	public:
		///constructor
		///\param p_dsp  gfx3d scg display object
		///\param p_parent  parent node
		rdfbin_scg_node(const int32_t p_node_index, rdfbin_scg_display* const p_dsp, gfx3d_scg_node * const p_parent);
		virtual ~rdfbin_scg_node();
        ///< Loads all the assets required by this node
        /// <param name="p_scene">id of the scene which is requesting this text node load</param>
        /// <param name="p_depth">depth of the node. used to prevent indefinite recursion</param>
        /// <param name="p_lrule">resource loading rule</param>
        /// <param name="p_visible">visibility of parent node, may affect resource loading depending on p_mode</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        virtual bool Load(const size_t p_scene, const size_t p_depth, const MdlResourceLoadRule p_lrule = MdlResourceLoadRule::All, const bool p_visible = true) override;       ///< Loads all the dynamic assets required by this node
    };
    /// @}
}

#endif