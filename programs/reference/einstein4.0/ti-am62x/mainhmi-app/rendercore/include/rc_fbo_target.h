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
//  Filename    : rc_fbo_target.h
//  Description : Implementation for Destination renderbuffer as FBO
//  Created on  : 19-JUNE-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_fbo_target_h
#define rc_fbo_target_h

namespace rendercore_engine
{
    /// \ingroup Internal
    /// @{

    /// extending rc_generic_ws to support a render to FBO than a render to window buffer
    class rc_fbo_target : public rc_generic_ws
    {
    private:
        GLuint fbo = 0U; ///< hold the opengl frame buffer object handle for non msa
        GLuint dbo = 0U; ///< hold the opengl depth buffer object handle
#if (GLES3_RENDERER >= 30)
        GLuint msaafbo = 0U;   ///< hold the opengl frame buffer object handle for msaa
        GLuint msaarbcbo = 0U; ///< hold the opengl color buffer object handle for msaa
#endif
        gfx3dTexture2D * tex = nullptr;     ///< Holds the texture object for the FBO render target
        gfx3d_scg_rtarget * rt = nullptr;   ///< render target for the FBO
    public:
        /// <summary>
        /// Distructor. Cleans up the object
        /// </summary>
        virtual ~rc_fbo_target();
        /// <summary>
        /// Constructor for FBO render target. Creates a FBO render target object
        /// </summary>
        /// <param name="p_parent">parent display object for the render target</param>
        rc_fbo_target(gfx3d_scg_display * const p_parent);
        /// <summary>
        /// Currently does nothing..
        /// </summary>
        /// <returns>returns true if the update was successful</returns>
        bool Update(void) override;
        /// <summary>
        /// Opens the FBO render target by creating necessaru opengl handles and 
        /// initializing the FBO for rendering..
        /// </summary>
        /// <param name="p_id">render target index (gfx3d_scg_display::rtargets) to be used for initialization</param>
        /// <returns>returns true if successful</returns>
        bool Open(const size_t p_id) override;
        /// <summary>
        /// Currently does nothing..
        /// </summary>
        /// <returns>returns true if successful</returns>
        bool Close(void) override;
        /// <summary>
        /// Activates the FBO render target, so that all rendercalls are directed to it
        /// </summary>
        /// <returns>returns true if successful</returns>
        bool MakeCurrent(void) override;
        /// <summary>
        /// Deactivates the FBO render target, so that render calls are not directed to it
        /// </summary>
        /// <param name="p_changed">true indicates buffer has changes and a swap is necessary</param>
        /// <returns>returns true if successful</returns>
        bool Swap(const bool p_changed) override;
    };
    /// @}
}
#endif
