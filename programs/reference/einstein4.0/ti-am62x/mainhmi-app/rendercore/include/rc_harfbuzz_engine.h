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
//  Filename    : rc_hb_text_engine.h
//  Description : Creat final 2D text buffer
//  Created on  : 22-Feb-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file	 rc_hb_text_engine.h
///	\brief	 Creat final 2D text buffer
#ifndef RC_HARFBUZZ_ENGINE_H
#define RC_HARFBUZZ_ENGINE_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include <map>
#include <utility>
#include "gfx3d_scg_font.h"

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/

/*============================================================================
** D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/
// MISRA_TRIAGE:
// CID : 18189011    
// Checker : MISRA C++-2008 7-3-1 
// comments: cant be put inside namespace
struct FT_GlyphRec_;
namespace rendercore_engine
{
	class ft_engine_state;
	class hb_shaping_engine;
	/// rendercore class for handling text
	class rc_harfbuzz_engine : public gfx3d_scg_font
	{
	protected:
		/// load give font with size, hint and style
		bool LoadExt() override;
		/// unload the font from font engine
		void UnLoadExt() override;
		/// Set the URI 
		void SetURIExt(const std::string p_uri) override;
	private:
		void * rc_faceid;
		FT_GlyphRec_ * outline_glyph = nullptr;
	public:
		///constructor
		rc_harfbuzz_engine(gfx3d_scg_project* const p_proj);
		rc_harfbuzz_engine(const gfx3d_scg_font* const p_base);
		virtual ~rc_harfbuzz_engine();
	    bool GetTextShapingInfo(rc_lbpara* const p_line, rc_text_shaper_info& p_text_shaping_info) override;
		bool GetCharRenderInfo(const uint32_t p_char, const bool p_is_char, rc_text_render_char_info& p_text_render_info, const uint8_t p_outlineWidth) override;
		bool CharRenderInfoDone(const rc_text_render_char_info& p_text_render_info) const override;
	};
	rc_hbfe_global_state* CreateHbGlobalStateInstance(gfx3d_scg_project* const p_project);
	void DistroyHbGlobalStateInstance(rc_hbfe_global_state* const p_state);
}
#endif

