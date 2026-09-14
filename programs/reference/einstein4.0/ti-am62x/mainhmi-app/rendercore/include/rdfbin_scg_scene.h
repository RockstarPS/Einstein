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
//  Filename    : rdfbin_scg_scene.h
//  Description : scene graph adaptation for rdf binary loader. inherited from base
//  Created on  : 20-Aug-2021 by ssharm20@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file rdfbin_scg_scene.h
///	\brief 	  scene graph adaptation for rdf binary loader. inherited from base.

#ifndef rdfbin_scg_scene_h
#define rdfbin_scg_scene_h

#include "gfx3d_scg.h"
#include "rc_rdfbin_type.h"

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{
    struct rdfbin_Scene;
    /// rdf bin scg scene class, extending gfx3d scg scene
	class rdfbin_scg_scene: public gfx3d_scg_scene
	{
	public:
		///constructor
		///\param p_dsp  gfx3d scg display object
		///\param p_parent  parent node
        rdfbin_scg_scene(gfx3d_scg_display* const p_dsp, const size_t p_node_index, rdfbin_Scene const* const p_scene);
		virtual ~rdfbin_scg_scene();
        virtual bool Load(const MdlResourceLoadRule p_lrule = MdlResourceLoadRule::All) override;
    };
    /// @}
}

#endif