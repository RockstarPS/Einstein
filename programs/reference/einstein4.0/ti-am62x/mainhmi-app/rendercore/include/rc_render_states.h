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
//  Filename    : rc_render_states.h
//  Description : custom string class APIs
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file	rc_render_states.h
///	\brief 	holds the render states
#ifndef rc_render_states_h
#define rc_render_states_h

namespace rendercore_engine
{
    /// \ingroup Internal
    /// @{
    class gfx3dTexture2D;
    /// <summary>
    /// Just the renderstates data storage structure
    /// </summary>
    struct rc_rs_data
    {
        mdl_cullMode cullMode = mdl_cullMode::cmUnset;			///< culling mode
        mdl_depthTest depthTest = mdl_depthTest::dtUnset;		///< depth testing
        mdl_depthWrite depthWrite = mdl_depthWrite::dwUnset;	///< depth write
        MdlBlendFactor srcBlendfactor = MdlBlendFactor::bfUnset;///>Color Source Blend Factor
        MdlBlendFactor dstBlendfactor = MdlBlendFactor::bfUnset;///>Color Dst Blend Factor
        MdlBlendFactor aSrcBlendfactor = MdlBlendFactor::bfUnset;///>Alpha Source Blend Factor
        MdlBlendFactor aDstBlendfactor = MdlBlendFactor::bfUnset;///>Alpha Dst Blend Factor
        MdlBlendEquation ablendEquation = MdlBlendEquation::beUnset; ///< GL Alpha blend equation to be used (see glBlendEquationSeperate)
        MdlBlendEquation blendEquation = MdlBlendEquation::beUnset; ///< GL blend equation to be used (see glBlendEquation)
        mdl_windingOrders windingOrder = mdl_windingOrders::woUnset; ///< Winding order of the mesh
        glm::vec4 scissorRect{0.0F, 0.0F, -1.0F, -1.0F };		///< scissor rectangle
        float32_t opacity = 1.0F;                               ///< opacity
    };

    /// @}
    /// \ingroup Internal
    /// @{

    /// <summary>
    /// handles the renderstates and helps to set the state to GL while rendering the primitive
    /// </summary>
    class rc_render_states
    {
    private:
        bool drawCallMade;
        rc_rs_data rsData;					///< Next Render State Data
        rc_rs_data rsDataCur;				///< Currently active Render State Data. This is used to detect whether there is a change with new user request
        mutable GLint maxAnisoLevel;        ///< Maximum allowed level.
        struct TexUnitInfo
        {
            GLuint target = 0U;
            GLuint texObj = 0U;
            MdlTextFilter_E minF = MdlTextFilter_E::tfUnset;
            MdlTextFilter_E magF = MdlTextFilter_E::tfUnset;
            MdlTextWrap_E wrapU = MdlTextWrap_E::twUnset;
            MdlTextWrap_E wrapV = MdlTextWrap_E::twUnset;
            GLint aniso = 0;
        };
        std::vector<TexUnitInfo> texUnits;
        GLuint pgmObj = 0U;
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
        mutable std::recursive_mutex data_mutex;                    ///<    mutex to protect all data access by threads
#endif
        /// <summary>
        /// Checks if filter properties for the passed texture and unit is changed or not 
        /// Updates the texture filter settings to requested unit storage, if its not already set
        /// </summary>
        /// <param name="p_isTUCur">p_cur_tex_unit is already active or not</param>
        /// <param name="p_cur_tex_unit"texture unit requested></param>
        /// <param name="p_target">texture target</param>
        /// <param name="p_tex">gfx3dTexture2D object</param>
        /// <returns>true if value was already set and this api didnot perform any actions. false if value was unset and api perform actions to set the values to texture unit.</returns>
        bool is_texfilter_current(const GLuint p_cur_tex_unit, const GLuint p_target, gfx3dTexture2D* const p_tex);
        /// <summary>
        /// Apply opengl texture filter
        /// </summary>
        void apply_texfilter(const GLuint p_cur_tex_unit);
    public:
        /// <summary>
        /// ctor
        /// </summary>
        rc_render_states();
        /// <summary>
        /// Resets the render states to default. Its done when a rendering is started
        /// </summary>
        void reset(const rc_rs_data& p_rstates);
        /// <summary>
        /// Saves the currently set render state to padded rc_rs_data pointer. 
        /// This is done push the state to stack before new data is set while iterating the scene graph
        /// i.e. when a child node is exited and returned to the parent level, we have to restore the
        /// parent level renderstates.
        /// <code>
        /// save();
        /// enterchild();
        /// restore();
        /// </code>
        /// </summary>
        /// <param name="p_data">pointer to a data storage where the current render states can be written</param>
        void save(rc_rs_data& p_data) const;
        /// <summary>
        /// Restores previously saved render state  
        /// This is done pop the state from stack after a child node is processed while iterating the scene graph
        /// i.e. when a child node is exited and returned to the parent level, we have to restore the
        /// parent level renderstates.
        /// </summary>
        /// <param name="p_data">pointer to a data storage from where the render states can be read</param>
        void restore(const rc_rs_data& p_data);
        /// <summary>
        /// Applies the passed renderstates to OpenGL.
        /// </summary>
        /// <param name="p_data">pointer to a data storage from where the render states can be read</param>
        void apply(const rc_rs_data& p_data);
        /// <summary>
        /// Sets the cullmode
        /// </summary>
        /// <param name="p_cullMode">cull mode to be set</param>
        void SetCullMode(const mdl_cullMode p_cullMode);
        /// <summary>
        /// Sets the depths test
        /// </summary>
        /// <param name="p_depthTest">depths test to be set</param>
        void SetDepthTest(const mdl_depthTest p_depthTest);
        /// <summary>
        /// Sets the depth write
        /// </summary>
        /// <param name="p_depthWrite">depth write to be set</param>
        void SetDepthWrite(const mdl_depthWrite p_depthWrite);
        /// <summary>
        /// Sets the blend mode
        /// </summary>
        /// <param name="p_blendMode">blend mode to be set</param>
        void SetBlendMode(const MdlBlendMode p_blendMode);
        /// <summary>
        /// Sets the blend blendFactor
        /// </summary>
        /// <param name="p_blendFactor">Color blend Factor to be set</param>
        void SetSrcBlendFactor(const MdlBlendFactor p_blendFactor);
        /// <summary>
        /// Sets the blendFactor
        /// </summary>
        /// <param name="p_blendFactor">Color blend factor to be set</param>
        void SetDstBlendFactor(const MdlBlendFactor p_blendFactor);
        /// <summary>
        /// Sets the Alpha blendFactor
        /// </summary>
        /// <param name="p_blendFactor">Alpha Src blend factor to be set</param>
        void SetAlphaSrcBlendFactor(const MdlBlendFactor p_blendFactor);
        /// <summary>
        /// Sets the blendFactor 
        /// </summary>
        /// <param name="p_blendFactor">Alpha Dst blend Factor to be set</param>
        void SetAlphaDstBlendFactor(const MdlBlendFactor p_blendFactor);
        /// <summary>
        /// Sets the scissor rectangle
        /// </summary>
        /// <param name="scissorrect">scissor rectangle to be set</param>
        void SetScissorRect(const glm::vec4 &scissorRect);
        /// <summary>
        /// Gets the scissor rectangle
        /// </summary>
        /// <returns>return scissor rectangle</returns>
        glm::vec4 GetScissorRect() const;
        /// <summary>
        /// Set status that a draw call has been issues in current render cycle
        /// </summary>
        void SetDrawCallMade(void);
        /// <summary>
        /// Gets the cullmode setting
        /// </summary>
        /// <returns>return cull mode</returns>
        mdl_cullMode GetCullMode(void) const;
        /// <summary>
        /// Gets the depth test setting
        /// </summary>
        /// <returns>return depth test</returns>
        mdl_depthTest GetDepthTest(void) const;
        /// <summary>
        /// Gets the depth write setting
        /// </summary>
        /// <returns>return depth write</returns>
        mdl_depthWrite GetDepthWrite(void) const;
        /// Gets the blend mode setting
        /// </summary>
        /// <returns>return blend mode</returns>
        MdlBlendMode GetBlendMode(void) const;
        /// <summary>
        /// Gets the Color Source blend mode Factor
        /// </summary>
        /// <returns>return blend mode</returns>
        MdlBlendFactor GetSrcBlendFactor(void);
        /// <summary>
        /// Gets the Color Dst blend mode Factor
        /// </summary>
        /// <returns>return blend mode</returns>
        MdlBlendFactor GetDstBlendFactor(void);
        /// <summary>
        /// Gets the Alpha Source blend mode Factor
        /// </summary>
        /// <returns>return blend mode</returns>
        MdlBlendFactor GetAlphaSrcBlendFactor(void);
        /// <summary>
        /// Gets the Alpja Dst blend mode Factor
        /// </summary>
        /// <returns>return blend mode</returns>
        MdlBlendFactor GetAlphaDstBlendFactor(void);
        /// <summary>
        /// Check whether a draw call has been issues in current render cycle
        /// </summary>
        /// <returns>return true if a draw call has been made</returns>
        bool IsDrawCallMade(void) const;
        /// <summary>
        /// Get the current opacity level of the mesh
        /// </summary>
        /// <returns>return opacity value</returns>
        float32_t GetOpacity(void) const;
        /// <summary>
        /// Set the current opacity level for the mesh
        /// </summary>
        /// <param name="p_val">opacity value to be set</param>
        void SetOpacity(const float32_t p_val);
        /// <summary>
        /// sets optional alpha channel blend mode
        /// <param name="p_blendMode">blend mode to set</param>
        /// </summary>
        void SetAlphaBlendMode(const MdlAlphaBlendMode p_blendMode);
        /// <summary>
        /// Gets optional alpha channel blend mode
        /// </summary>
        MdlAlphaBlendMode GetAlphaBlendMode(void) const;
        /// <summary>
        /// sets optional alpha channel blend equation
        /// <param name="p_ablendEquation">optionla Alpha blend equation to set</param>
        /// </summary>
        void SetAlphaBlendEquation(const MdlBlendEquation p_ablendEquation);
        /// <summary>
        /// sets the blende equation
        /// <param name="p_blendMode">blend equation to set</param>
        /// </summary>
        void SetBlendEquation(const MdlBlendEquation p_blendEquation);
        /// <summary>
        /// Gets the blende equation
        /// </summary>
        MdlBlendEquation GetBlendEquation(void) const;
        /// <summary>
        /// Sets the winding order for the mesh
        /// </summary>
        /// <param name="p_windingOrder">winding order</param>
        void SetWindingOrder(const mdl_windingOrders p_windingOrder);
        /// <summary>
        /// Returns the maximum supported Aniso level
        /// </summary>
        /// <returns>Aniso level</returns>
        GLint GetMaxAnisoLevel() const;
        /// <summary>
        /// Sets the maximum supported Aniso level (just for UT)
        /// </summary>
        /// <param name="p_val">Aniso level</param>
        void SetMaxAnisoLevel(const GLint p_val);
        /// <summary>
        /// Performs BindTexture, Texture filter, wrap and aniso settings on change basis. To save on duplicate GL calls
        /// </summary>
        void setup_texture(const GLuint p_cur_tex_unit, const GLuint p_target, const GLuint p_texObj, gfx3dTexture2D* const p_tex, const bool p_force);
        /// <summary>
        /// Performs BindTexture
        /// Check if the given texture is the current binded to the texture unit. To save on duplicate GL calls
        /// </summary>
        /// <param name="p_cur_tex_unit">requested texture unit</param>
        /// <param name="p_target">required target type</param>
        /// <param name="p_texObj"><required texture object/param>
        /// <returns>true if the textureunit has passed target and textobj set already</returns>
        bool set_texture_unit(const GLuint p_cur_tex_unit, const GLuint p_target, const GLuint p_texObj, const bool p_force = false);
        /// <summary>
        /// Set the active program object
        /// </summary>
        /// <param name="p_pgmObj">shader rogram object</param>
        void set_current_pgm(GLuint p_pgmObj);
        /// <summary>
        /// Get the active program object
        /// </summary>
        GLuint get_current_pgm();
    };
    /// @}
}

#endif