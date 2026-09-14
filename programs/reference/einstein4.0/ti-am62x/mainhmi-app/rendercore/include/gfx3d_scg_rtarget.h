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
//  Filename    : gfx3d_scg_rtarget.h
//  Description : GFX3D scene graph render target object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_scg_rtarget.h
/// \brief GFX3D scene graph render target object
#ifndef gfx3d_scg_rtarget_h
#define gfx3d_scg_rtarget_h

namespace rendercore_engine
{
    class rc_fbo_target;
    /// \ingroup Engine
    /// @{
    /// <summary>
    /// A render target specifies where the rendering output to be directed to.
    /// Currently there can be two kinds of render targets possible
    /// 1. Render to a Window buffer
    /// 2. Render to a Frame Buffer Object (FBO / Off screen rendering)
    /// Currently the render targets are only decided at camera level. i.e. 
    /// the camera specifies a render target ID and the rendering will then 
    /// be set to appropriate destination.
    /// In order to make a group of nodes to be rendered to an offscreen buffer,
    /// user needs to create a camera and the set its culling mask such that
    /// it selects only the group of nodes. This Camera need to specify that its
    /// using an offscreen render target.
	/// </summary>
    class gfx3d_scg_rtarget
	{
	private:
        std::string name;				///< name of the render target
        glm::vec2 pos{ 0.0F, 0.0F };	///< position of the render target
        glm::vec2 dim{ 0.0F, 0.0F };	///< dimensions of the render target
        uint32_t msaa_level = 0U;	///< msaa level 
        rtColorDepthE colorSize = rtColorDepthE::wcColor32bpp; ///< color depth for rt
        uint32_t depth_size = 24U;	///< depth size for rt
        gfx3d_scg_display* display;		///< parent object
        MdlRTtype_E rt_type = MdlRTtype_E::rttWindowBuffer; ///< render target type
        int32_t tex_index = -1;             ///< incase  rt_type == MdlRTtype_E::rttFBO, then this 
                                        ///< indicates the index to the gfx3d_scg_display::textures[] 
                                        ///< array which holds the texture information for FBO
                                        ///< For other cases, its value is not used.
        bool rtDirty = false;           ///<Indicate if any scenes in RT is dirty or not
    public:
		/// constructor
        gfx3d_scg_rtarget(gfx3d_scg_display* const p_parent);
		/// virtual destructor
		virtual ~gfx3d_scg_rtarget();
        /// <summary>
        /// function to get render target object name
        /// </summary>
        /// <returns>returns render target object name of type string</returns>
        std::string GetName() const;
        /// <summary>
        /// Set render target object name
        /// </summary>
        /// <param name="p_name"> render target object name </param>
        void SetName(const std::string p_name);
        /// <summary>
        /// function to get render target position
        /// </summary>
        /// <returns>returns render target position </returns>
        glm::vec2 GetPosition() const;
        /// <summary>
        /// Set render target position
        /// </summary>
        /// <param name="p_pos"> render target position </param>
        void SetPosition(const glm::vec2 p_pos);
        /// <summary>
        /// function to get render target dimention
        /// </summary>
        /// <returns>returns render target dimention </returns>
        glm::vec2 GetDimension() const;
        /// <summary>
        /// Set render target dimension
        /// </summary>
        /// <param name="p_dim"> render target dimension </param>
        void SetDimension(const glm::vec2 p_dim);
        /// <summary>
        /// function to get render target msaa level
        /// </summary>
        /// <returns>returns render target msaa level </returns>
        uint32_t GetMsaaLevel() const;
        /// <summary>
        /// Set render target fbo msaa level
        /// </summary>
        /// <param name="p_msaa_level"> render target msaa level </param>
        void SetMsaaLevel(const uint32_t p_msaa_level);
        /// <summary>
        /// function to get render target color size
        /// </summary>
        /// <returns>returns render target color size </returns>
        rtColorDepthE GetColorSize() const;
        /// <summary>
        /// Set render target color size
        /// </summary>
        /// <param name="p_colorSize"> render target color size </param>
        void SetColorSize(const rtColorDepthE p_colorSize);
        /// <summary>
        /// function to get render target fbo depth size
        /// </summary>
        /// <returns>returns render depth size </returns>
        uint32_t GetDepthSize() const;
        /// <summary>
        /// Set render target depth size
        /// </summary>
        /// <param name="p_depth_size"> render target depth size </param>
        void SetDepthSize(const uint32_t p_depth_size);
        /// <summary>
        /// function to get pointer to parent display
        /// </summary>
        /// <returns>returns pointer to parent display </returns>
        gfx3d_scg_display* GetParent() const;
        /// <summary>
        /// Set parent display for this render target
        /// </summary>
        /// <param name="p_dp"> pointer to parent display </param>
		void SetParent(gfx3d_scg_display * const p_dp);
        /// <summary>
        /// function to get render target type
        /// </summary>
        /// <returns>returns render target type </returns>
        MdlRTtype_E GetRtType() const;
        /// <summary>
        /// Set render target type
        /// </summary>
        /// <param name="p_rt_type"> render target type </param>
        void SetRtType(const MdlRTtype_E p_rt_type);
        /// <summary>
        /// Set render target Dirty Flag
        /// </summary>
        void SetRtDirty();
        /// <summary>
        /// Clears render target Dirty Flag
        /// </summary>
        void ClearRtDirty();
        /// <summary>
        /// Function to get render target Dirty Flag
        /// </summary>
        /// <returns"> returns the Dirty flag of render target  </param>
        bool IsRtDirty()const;
        /// <summary>
        /// function to get render target texture index for fbo
        /// </summary>
        /// <returns>returns render target texture index for fbo </returns>
        int32_t GetTexureIndex() const;
        /// <summary>
        /// Set render target texture id
        /// </summary>
        /// <param name="p_tex_index"> render target texture id </param>
        void SetTexureIndex(const int32_t p_tex_index);
        /// <summary>
        /// Returns the GL format information for the render target
        /// </summary>
        /// <returns>returns RCglImgFormatMap </returns>
        const RCglImgFormatMap * GetGLFormatInfo() const;
    };
    /// @}
}


#endif