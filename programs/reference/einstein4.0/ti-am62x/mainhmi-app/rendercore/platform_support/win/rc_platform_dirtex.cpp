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
//  Filename    : rc_platform_dirtex.cpp
//  Description : Platform specific direct texture implementation.
//                Modify as per requirement
//  Created on  : 04-Jul-2022 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#include "gfx3d_scg.h"
#include "rc_platform_dirtex.h"
#include "rc_gles_vivextns.h"

namespace rendercore_engine
{
    MdlImgFormat_E RcGetDirectTextureFormat(const MdlImgFormat_E p_reqFormat)
    {
        return(p_reqFormat);
    }
    GLenum RcGetDirectTextureTarget()
    {
        return(static_cast<GLenum>(GL_TEXTURE_2D));
    }
    bool RcCreateDirectTexture(rc_dir_texture& p_dtex)
    {
        p_dtex.handle = nullptr;
        p_dtex.pixels = nullptr;
        return(false);
    }
    bool RcLockDirectTexture(rc_dir_texture& p_dtex)
    {
        (void)p_dtex;
        return(false);
    }
    bool RcInvalidateDirectTexture(rc_dir_texture& p_dtex)
    {
        (void)p_dtex;
        return(false);
    }
    bool RcDeleteDirectTexture(rc_dir_texture& p_dtex)
    {
        (void)p_dtex;
        return(false);
    }
}
