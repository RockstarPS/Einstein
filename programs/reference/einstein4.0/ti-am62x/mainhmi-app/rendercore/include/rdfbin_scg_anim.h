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
//  Filename    : rdfbin_scg_animation.h
//  Description : animation adaptation for rdf binary loader		
//  Created on  : 3-Sep-2021 by ssharm20@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file rdfbin_scg_anim.h
///	\brief	  animation adaptation for rdf bin loader	
#ifndef rdfbin_scg_anim_h
#define rdfbin_scg_anim_h

#include "gfx3d_scg_anim.h"
#include "rdfbin_scg_display.h"

namespace rendercore_engine
{
    /// \ingroup Loader
    /// @{

    /// <summary>
	/// Holds the handling to load animation date and as well run the animations 
	/// </summary>
	class rdfbin_scg_anim : public gfx3d_scg_anim
	{
	private:
        rdfbin_Animation const * animation;
	public:
		virtual ~rdfbin_scg_anim();
		/// <summary>
		/// Constructor. accepts the tinygltf display as input and then extracts the animation channels in to internal storage.
		/// <param name="p_dsp">rdf_scg_display display</param>
		/// <param name="p_anims">rdf animation object</param>
		/// <param name="p_num_anims">number of animations</param>	
		/// </summary>
		rdfbin_scg_anim(rdfbin_scg_display * const p_dsp, rdfbin_Animation const * const p_anim);
	};
    /// @}
}

#endif