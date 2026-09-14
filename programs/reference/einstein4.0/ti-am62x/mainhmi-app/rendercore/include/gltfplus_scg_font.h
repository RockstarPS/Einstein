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
//  Created on  : 24th Jan 2019 by mpandey@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gltfplus_scg_font.h
///	\brief gltfplus project loader it contains code related of rdf generated structure
#ifndef gltfplus_scg_font_h
#define gltfplus_scg_font_h

#include "gltfplus_scg_project.h"
#include "gltfplus_scg_display.h"
#include "gfx3d_scg.h"
#include "tinygltf_if.h"

namespace rendercore_engine 
{
    /// \ingroup Loader
    /// @{

    /// <summary>
	/// gltfplus_scg_font loads information about TTF fonts, information may contain name of the family, font size, font style etc.
	/// </summary>
	class gltfplus_scg_font : public gfx3d_scg_font
    {
    private:
        MdlFontStyle getStyleFromString(std::string str);
		MdlFontRenderHint getHintFromString(std::string str);
	public:
		/// <summary>
		/// Constructor. accepts the gltfplus project as input and then extracts the font information from tinygltf::Value.
		/// <param name="p_proj">gltfplus project</param>
		/// <param name="p_font">tinygltf font</param>
		/// </summary>
		gltfplus_scg_font(gltfplus_scg_project * p_proj, tinygltf::Value * p_font);
		virtual ~gltfplus_scg_font();
		static MdlFontEngine getFEngineFromString(std::string str);
	};
    /// @}
}

#endif