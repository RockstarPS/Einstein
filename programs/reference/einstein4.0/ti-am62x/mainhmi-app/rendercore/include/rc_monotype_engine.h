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
//  Filename    : rc_text_engine.h
//  Description : Creat final 2D text buffer
//  Created on  : 22-Feb-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file	 rc_text_engine.h
///	\brief	 Creat final 2D text buffer
#ifndef RC_MONOTYPE_ENGINE_H
#define RC_MONOTYPE_ENGINE_H

/*============================================================================
** I N C L U D E   F I L E S
**==========================================================================*/
#include <map>
#include <utility>
#include "gfx3d_scg.h"

/*============================================================================
** T Y P E   D E F I N I T I O N S
**==========================================================================*/

/*============================================================================
** D A T A   A C C E S S   S E R V I C E S
**==========================================================================*/

/*============================================================================
** E N T R Y   P O I N T S
**==========================================================================*/
namespace rendercore_engine
{
	class rc_mtfe_global_state;
	/// \ingroup Internal
    /// @{

    /// rendercore class for handling text
	class rc_monotype_engine : public gfx3d_scg_font
	{
		///Monotype specific implementation
	private:
		uint16_t dflt_glyphID = 0U;							///< glyph id for default character
		char32_t dflt_char = static_cast<char32_t>(0xFFFD);	///< temporarily hold the default char. base property is with project class
		rc_mtfe_global_state* s_instance = nullptr;			///< temporarily hold the global state. ownership of this is with gfx3d_font_properties class
	protected:
		/// load give font with size, hint and style
		bool LoadExt(void) override;
		/// unload the font from font engine
		void UnLoadExt(void) override;
	public:
		///constructor
		rc_monotype_engine(gfx3d_scg_project* const p_proj);
		rc_monotype_engine(const gfx3d_scg_font* const p_base);
		virtual ~rc_monotype_engine();
		bool GetTextShapingInfo(rc_lbpara* const p_line, rc_text_shaper_info& p_text_shaping_info) override;
		bool GetCharRenderInfo(const uint32_t p_char, const bool p_is_char, rc_text_render_char_info& p_text_render_info, const uint8_t p_outlineWidth) override;
		bool CharRenderInfoDone(const rc_text_render_char_info& p_text_render_info) const override;
	};
    /// @}
	/// <summary>
	/// Create the fonts global state object. Created once for a project object
	/// </summary>
	/// <param name="p_project">project object for which the global state to be created.</param>
	/// <returns>pointer to object</returns>
	rc_mtfe_global_state* CreateMtGlobalStateInstance(gfx3d_scg_project* const p_project);
	/// <summary>
	/// Delete the blobal data pbject
	/// </summary>
	/// <param name="p_state">pointer to global data</param>
	void DistroyMtGlobalStateInstance(rc_mtfe_global_state* const p_state);
}

#endif
