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
/// @file rdfbin_scg_guiskinning.h
/// @author ssharm20@visteon.com
/// @brief GUI skinning control 
/// @date 06-Oct-2021
/// @copyright © 2021, Visteon Corporation, All Rights Reserved
///////////////////////////////////////////////////////////////////////////////
#ifndef rdfbin_scg_guiskinning_h
#define rdfbin_scg_guiskinning_h

#include "gfx3d_scg_types.h"
#include "gfx3d_scg.h"
#include "rc_guiskinning_type.h"

namespace rendercore_engine
{
    /// <summary>
    /// stores the font engine data related with a font
	/// </summary>
    class rdfbin_scg_guiskinning : public gfx3d_scg_guiskinning
	{
    protected:
	private:
    public:
        /// <summary>
        /// Constructs a gui skinning object
        /// </summary>
        /// <param name="p_disp">Parent display object</param>
        /// <returns></returns>
        rdfbin_scg_guiskinning(gfx3d_scg_display* const p_disp, const CHAR8* const p_skinning_uri);
        virtual ~rdfbin_scg_guiskinning();
        /// <summary>
        /// Creates the texture required by skining, if it doesnot exist in scene
        /// </summary>
        /// <param name="p_type">texture type to create</param>
        /// <param name="p_texture">texture id to create</param>
        /// <returns>returns the status true - success / false - failed </returns>
        bool CreateTexture(const rdf_glslDataType p_type, const std::int32_t p_texture) const override;
    };
}


#endif