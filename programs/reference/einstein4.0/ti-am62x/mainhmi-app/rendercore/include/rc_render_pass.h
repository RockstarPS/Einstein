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
//  Filename    : rc_render_pass.h
//  Description : Implementation for renderpass
//  Created on  : 19-JUNE-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_render_pass_h
#define rc_render_pass_h

namespace rendercore_engine
{
    class rc_render_pass
    {
    private:
        gfx3d_scg_display* display = nullptr;                  ///< Parent display for this renderpass
        rc_generic_ws* rt = nullptr;                           ///< render target for the camera, derived from gfx3d_scg_camera::render_target (it can be a window buffer or offscreen FBO)
        size_t render_target = static_cast<size_t>(SIZE_MAX);  ///< Render target to be used for this camera. Its an index to gfx3d_scg_display::rtargets 
        gfx3d_scg_material* material = nullptr;                ///< material override for the renderpass
    public:
        ~rc_render_pass();
        rc_render_pass(gfx3d_scg_display* const p_display);
        /// <summary>
        /// Gets the render target for camera
        /// </summary>
        /// <returns>returns the render target index for this camera</returns>
        size_t GetRenderTarget(void) const;
        /// <summary>
        /// Sets the render target for camera
        /// </summary>
        /// <param name="p_render_target">index to gfx3d_scg_display::rtargets[] array</param>
        void SetRenderTarget(const size_t p_render_target);
        /// <summary>
        /// returns the rendertarget buffer object for this camera 
        /// <returns>returns pointer to rc_generic_ws</returns>
        /// </summary>
        rc_generic_ws* GetRt() const;
        /// <summary>
        /// Sets the rendertarget buffer object for this camera 
        /// <param name="p_rt">pointer to rc_generic_ws</param>
        /// </summary>
        void SetRt(rc_generic_ws* const p_rt);
        gfx3d_scg_display* GetParent() const;
        void SetParent(gfx3d_scg_display* const p_parent);
        /// <summary>
        /// returns the material object
        /// </summary>
        gfx3d_scg_material* GetMaterial(void) const;
        /// <summary>
        /// Sets a new material to primitive. Returns true if new material is set.
        /// Note : SetMaterial deletes the currently set material before updating the new material
        /// </summary>
        bool SetMaterial(gfx3d_scg_material* const p_material);
        /// <summary>
        /// Setups the renderpass for rendering
        /// </summary>
        /// <returns></returns>
        bool activate();
        /// <summary>
        /// Cleanups after the rendering completes
        /// </summary>
        bool done();
        bool update_dimension(glm::vec4& fl_vewport) const;
        bool Load(const size_t p_scene, const bool p_visible);
        bool UnLoad(const size_t p_scene);
        void render_quad();
    };
}
#endif
