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
//  Filename    : rc_platform_dirtex.h
//  Description : Platform specific direct texture implementation.
//  Created on  : 04-Jul-2022 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_platform_dirtex_h
#define rc_platform_dirtex_h

namespace rendercore_engine
{
    struct rc_dt_handle;
    /// <summary>
    /// Holds the information about the direct texture.
    /// for more information refer rendercore_engine::RcGetDirectTextureTarget()
    /// </summary>
    struct rc_dir_texture
    {
        rc_dt_handle * handle = nullptr;    ///< Handle of the direct texture
        UCHAR8* pixels = nullptr;   ///< pointer to texture pixel data in memory (virtual)
        int32_t width = 0;          ///< width in pixels 
        int32_t height = 0;         ///< height in pixels
        int32_t stride = 0;         ///< number of bytes per row
        MdlImgFormat_E format = MdlImgFormat_E::ifUnset;    ///< format of the texture
    };
    /// <summary>
    /// Returns the nearest supported texture format mapping for a required format
    /// </summary>
    /// <param name="p_reqFormat">requesting format</param>
    /// <returns>supported format</returns>
    MdlImgFormat_E RcGetDirectTextureFormat(const MdlImgFormat_E p_reqFormat);
    /// <summary>
    /// Texture target to be used for this direct texture
    /// </summary>
    /// <returns>Texture target</returns>
    GLenum RcGetDirectTextureTarget();
    /// <summary>
    /// Creates the direct texture with requested information
    ///   Inputs
    ///     p_dtex.width    - required width of the direct texture
    ///     p_dtex.height   - required height of the direct texture
    ///     p_dtex.stride   - required stride of the direct texture
    ///     p_dtex.format   - required format of the direct texture
    ///   Output
    ///     p_dtex.handle   - a handle to the direct texture for future manipulations
    ///     p_dtex.pixels   - pointer to pixel data (virtual memory) which application access
    /// </summary>
    /// <param name="p_dtex">input and output of the request</param>
    /// <returns>true if success</returns>
    bool RcCreateDirectTexture(rc_dir_texture& p_dtex);
    /// <summary>
    /// UnLocks the texture data for write, so that application can change the data,
    /// Must be called before accessing p_dtex.pixels, after call to RcInvalidateDirectTexture
    /// </summary>
    /// <param name="p_dtex">direct texture info</param>
    bool RcLockDirectTexture(rc_dir_texture& p_dtex);
    /// <summary>
    /// Locks/Invalidate the texture data, so that changes done by application,
    /// (i.e. filling the texture pixel data in to p_dtex.pixels) can be reflected 
    /// </summary>
    /// <param name="p_dtex">direct texture info</param>
    /// <returns>true if success</returns>
    bool RcInvalidateDirectTexture(rc_dir_texture& p_dtex);
    /// <summary>
    /// Deletes the direct textre
    /// </summary>
    /// <param name="p_dtex">direct texture info</param>
    /// <returns>true if success</returns>
    bool RcDeleteDirectTexture(rc_dir_texture& p_dtex);
}
#endif
