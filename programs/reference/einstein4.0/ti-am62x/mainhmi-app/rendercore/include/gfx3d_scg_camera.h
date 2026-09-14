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
//  Filename    : gfx3d_scg_camera.h
//  Description : GFX3D scene graph camera object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_scg_camera.h
/// \brief GFX3D scene graph camera object
#ifndef gfx3d_scg_camera_h
#define gfx3d_scg_camera_h

namespace rendercore_engine
{
    class gfx3d_scg_scene;
    /// \ingroup Engine
    /// @{
    /// <summary>
	/// Holds the camera configuration for the scene graph. 
    /// Rendercore runs a renderloop for each camera in the scene. Cameras will be sorted based on their
    /// gfx3d_scg_camera::renderOrder. A low render order value camera is rendered first 
    /// A Camera must be attached to a gfx3d_scg_node (gfx3d_scg_node::cameraIndex) in the scenegraph 
    /// to consider it as an active camera and the inturn the renderloop to consider it for rendering
 	/// </summary>
	class gfx3d_scg_camera
	{
    protected:
        gfx3d_scg_display* display = nullptr;                        ///< parent display
        size_t cullingMask = static_cast<size_t>(SIZE_MAX);         ///< mask used for culling objects gfx3d_scg_camera::cullingMask & gfx3d_scg_node::cullingMask determines if a node is seen by camera
        CameraClearFlags clearFlags = CameraClearFlags::Nothing;	///< indicated what to clear when the camera start rendering. 
        virtual GLbitfield perform_clear(const GLbitfield p_clearFlag) const;                               ///< perform a custom clear action. return true to indicate action done, false action not performed
    private:
        // render_mode properties..
        gfx3d_scg_node* node = nullptr;                        ///< scene graph node to which this camera is attached to. Camera is rendered only if attached and the node is visible
        glm::vec4 viewport{ 0.0F, 0.0F, -1.0F, -1.0F };        ///< user requested viewport settings.
        gfx3d_4x4mat projMatrix;            ///< projection matrix
        glm::vec4 backgroundColor{ 0.0F };  ///< background color of the camera. When gfx3d_scg_camera::clearFlags == CameraClearFlags::SolidColor or ColorAndDepth this value will be used to clear
        std::map<MdlRenderPassStage, rc_render_pass> renderPasses; ///< Render passes for this camera
        /// <summary>
        /// Default camera view configuration. It holds the view matrix and camera position
        /// This will be updated prior to a camera in the display gets rendered. 
        /// </summary>
        gfx3d_scg_view view;
        float32_t clearDepthValue = 1.0F;	///< clear depth value. . When gfx3d_scg_camera::clearFlags == CameraClearFlags::Depth || SolidColor or ColorAndDepth  this value will be used to clear
        float32_t xmag = 0.0F;				///< x for orthographic
        float32_t ymag = 0.0F;				///< y for orthographic
        float32_t fieldOfView = 0.0F;		///< this decides how many things will be shown in the scene
        float32_t nearClipPlane = 0.0F;	    ///< near plane
        float32_t farClipPlane = 0.0F;		///< far plane
        float32_t aspect = 1.0F;			///< aspect ratio w/h
        int32_t renderOrder = -1;		    ///< render order for game objects assigned with camera
        rc_rs_data rstates;                 ///< render states for the camera
        rc_rsortType sortType = rc_rsortType::sortAuto; ///< Sorting methods for the nodes rendered by this camera
		bool valid = false;				    ///< is valid
        bool orthographic = false;		    ///< is the camera orthographic
        /// <summary>
        /// camera is active (default) or not. Only active camera is rendered
        /// </summary>
        bool active = true;             
        bool dirUp = false;
        bool dirty = false;
        bool enableDepthPrePass = false;
    public:
        /// <summary>
        /// Constructs a camera
        /// </summary>
        /// <param name="p_parent"> parent display this accessor belongs to </param>
        gfx3d_scg_camera(gfx3d_scg_display* const p_parent);
        /// Distructor
        virtual ~gfx3d_scg_camera();
        gfx3d_scg_camera& operator= (const gfx3d_scg_camera&) = delete;
        gfx3d_scg_camera(const gfx3d_scg_camera&) = delete;
        /// <summary>
		/// set the field of view for the camera and generate the Projection matrix. 
		/// <param name="pyfov">field of view in radians</param>
		/// <param name="paspectRatio">Aspect ratio (Width / Height), default 1.0 if not provided</param>
		/// <param name="pznear">zNear clip, default to 0.01 if not provided</param>
		/// <param name="pzfar">zFar clip, default to 10000.0 if not provided</param>
		/// </summary>
		void SetPerspective(const float32_t pyfov, const float32_t paspectRatio, const float32_t pznear, const float32_t pzfar);
        /// <summary>
        /// set the field of view for the camera and generate the Projection matrix. 
        /// <param name="pyfov">field of view in degrees</param>
        /// <param name="paspectRatio">Aspect ratio (Width / Height), default 1.0 if not provided</param>
        /// <param name="pznear">zNear clip, default to 0.01 if not provided</param>
        /// <param name="pzfar">zFar clip, default to 10000.0 if not provided</param>
        /// </summary>
        void SetPerspectiveDFov(const float32_t pyfov, const float32_t paspectRatio, const float32_t pznear, const float32_t pzfar);
        /// <summary>
		/// set camera with orthographic Projection matrix. 
		/// <param name="xmag">x box side</param>
		/// <param name="ymag">y box side</param>
		/// <param name="pznear">zNear clip</param>
		/// <param name="pzfar">zFar clip</param>
		/// </summary>
		void SetOrthographic(const float32_t pxmag, const float32_t pymag, const float32_t pznear, const float32_t pzfar);
		/// <summary>
		/// checks for validity. 
        /// <returns>returns true - valid projection / false - invalid </returns>
        /// </summary>
		bool IsValid(void) const;
		/// <summary>
		/// sets camera render order(use >= 0). lower value makes the camera render first
        /// <param name="value">render order value</param>
        /// </summary>
		void SetRenderOrder(const int32_t value);
		/// <summary>
		/// sets the culling mask to the value. 
        /// <param name="value">camera culling mask value</param>
        /// </summary>
		void SetCullingMask(const size_t value);
		/// <summary>
		/// returns the current culling mask. 
        /// <returns>returns culling mask </returns>
        /// </summary>
        size_t GetCullingMask() const;
		/// <summary>
		/// Set camera clear flags. 
        /// <param name="p_flag">camera clear flag</param>
        /// </summary>
		void SetClearFlags(const CameraClearFlags p_flag);
        /// <summary>
        /// Get camera clear flags. 
        /// </summary>
        CameraClearFlags GetClearFlags() const;
        /// <summary>
		/// Set the background clear color value for the framebuffer. 
        /// <param name="color">camera clear color value in rgba </param>
        /// </summary>
		void SetBackgroundColor(const glm::vec4 p_color);
        /// <summary>
        /// Get the currently set background clear color value for the framebuffer. 
        /// <returns>returns clear color value </returns>
        /// </summary>
        glm::vec4 GetBackgroundColor() const;
		/// <summary>
		/// Set the depth clear value for the framebuffer. 
        /// <param name="value">camera clear depth buffer value </param>
        /// </summary>
		void SetDepthValue(const float32_t value);
        /// <summary>
        /// Get the currently set depth clear value for the framebuffer. 
        /// </summary>
        float32_t GetDepthValue() const;
        /// <summary>
		/// returns the render order. 
        /// <returns>returns depth clear value </returns>
		/// </summary>
		int32_t GetRenderOrder() const;
		/// <summary>
		/// activates the camera for rendering. 
        /// this is an internal api called before rendering loops starts
        /// <returns>returns true - sucess / false - failed </returns>
		/// </summary>
		bool activate(const MdlRenderPassStage p_stage = MdlRenderPassStage::rsNormalRendering);
        /// <summary>
        /// Returns true if camera can render
        /// </summary>
        bool CanRender(void);
        /// <summary>
        /// this api notifies the camera that rendering with the camera is done. 
        /// this is an internal api called after the activate() and rendering loops are completed.
        /// </summary>
        void done(const MdlRenderPassStage p_stage = MdlRenderPassStage::rsNormalRendering);
		/// <summary>
		/// sets the cull mode for camera. 
        /// <param name="p_cullMode">cull mode </param>
		/// </summary>
		void SetCullMode(const mdl_cullMode p_cullMode);
		/// <summary>
		/// set depth test. 
        /// <param name="p_depthTest">depth test </param>
        /// </summary>
		void SetDepthTest(const mdl_depthTest p_depthTest);
		/// <summary>
		/// depth write could be one of these--> dwFalse, dwTrue, dwUnset
        /// <param name="p_depthWrite">depth write </param>
        /// </summary>
		void SetDepthWrite(const mdl_depthWrite p_depthWrite);
        /// <summary>
        /// sets the blend mode
        /// <param name="p_blendMode">blend mode </param>
        /// </summary>
        void SetBlendMode(const MdlBlendMode p_blendMode);
        /// sets optional alpha channel blend mode
        /// <param name="p_blendMode">blend mode to set</param>
        /// </summary>
        void SetAlphaBlendMode(const MdlAlphaBlendMode p_blendMode);
        /// <summary>
        /// sets the Color Source blend factor
        /// <param name="p_blendFactor">blend factor to set</param>
        /// </summary>
        void SetSrcBlendFactor(const MdlBlendFactor p_blendFactor);
        /// <summary>
        /// sets the Color Dst blend factor
        /// <param name="p_blendFactor">blend factor to set</param>
        /// </summary>
        void SetDstBlendFactor(const MdlBlendFactor p_blendFactor);
        /// <summary>
        /// sets the Alpha Source blend factor
        /// <param name="p_ablendFactor">blend factor to set</param>
        /// </summary>
        void SetAlphaSrcBlendFactor(const MdlBlendFactor p_blendFactor);
        /// <summary>
        /// sets the Alpha Dst blend factor
        /// <param name="p_ablendFactor">blend factor to set</param>
        /// </summary>
        void SetAlphaDstBlendFactor(const MdlBlendFactor p_blendFactor);
        /// <summary>
        /// sets optional alpha channel blend mode
        /// <param name="p_ablendEquation">blend mode to set</param>
        /// </summary>
        void SetAlphaBlendEquation(const MdlBlendEquation p_blendEquation);
        /// <summary>
        /// sets the blende equation
        /// <param name="p_blendMode">blend equation to set</param>
        /// </summary>
        void SetBlendEquation(const MdlBlendEquation p_blendEquation);
        /// <summary>
		/// returns the cull mode for the camera
        /// <returns>returns cull mode </returns>
		/// </summary>
		mdl_cullMode GetCullMode(void) const;
		/// <summary>
		/// returns depth test for camera
        /// <returns>returns depth test </returns>
        /// </summary>
        mdl_depthTest GetDepthTest(void) const;
		/// <summary>
		/// returns depth write for camera
        /// <returns>returns depth write </returns>
        /// </summary>
        mdl_depthWrite GetDepthWrite(void) const;
        /// <summary>
        /// returns the blend mode for camera
        /// <returns>returns blend mode </returns>
        /// </summary>
        MdlBlendMode GetBlendMode(void) const;
        /// <summary>
        /// Gets optional alpha channel blend mode
        /// </summary>
        MdlAlphaBlendMode GetAlphaBlendMode(void) const;
        /// <summary>
        /// Gets optional alpha channel blend mode
        /// </summary>
        MdlBlendEquation GetAlphaBlendEquation(void) const;
		/// <summary>
		/// returns the Src blend Factor for camera
        /// <returns>returns blend factor </returns>
        /// </summary>
        MdlBlendFactor GetSrcBlendFactor(void) const;
		/// <summary>
		/// returns the Dst blend Factor for camera
        /// <returns>returns blend Factor</returns>
        /// </summary>
        MdlBlendFactor GetDstBlendFactor(void) const;
		/// <summary>
		/// returns the Src Alpha blend Factor for camera
        /// <returns>returns blend factor </returns>
        /// </summary>
        MdlBlendFactor GetAlphaSrcBlendFactor(void) const;
		/// <summary>
		/// returns the Dst Alpha blend Factor for camera
        /// <returns>returns blend factor </returns>
        /// </summary>
        MdlBlendFactor GetAlphaDstBlendFactor(void) const;
        /// <summary>
        /// Gets the blende equation
        /// </summary>
        MdlBlendEquation GetBlendEquation(void) const;
        /// <summary>
        /// Gets the render target for camera
        /// </summary>
        /// <returns>returns the render target index for this camera</returns>
        size_t GetRenderTarget(const MdlRenderPassStage p_stage = MdlRenderPassStage::rsNormalRendering) const;
        /// <summary>
        /// Sets the render target for camera
        /// </summary>
        /// <param name="p_render_target">index to gfx3d_scg_display::rtargets[] array</param>
        void SetRenderTarget(const size_t p_render_target, const MdlRenderPassStage p_stage = MdlRenderPassStage::rsNormalRendering);
		/// <summary>
		/// set the viewport for camera. Same as glViewport, bottom left is start x,y
        /// <param name="p_viewport">iviewport value x, y, width, height</param>
        /// </summary>
		void SetViewport(const glm::vec4 &p_viewport);
		/// <summary>
		/// returns the viewport of camera. 
        /// <returns>returns the camera view port</returns>
		/// </summary>
        glm::vec4  GetViewport(const MdlRenderPassStage p_stage = MdlRenderPassStage::rsNormalRendering) const;
        /// <summary>
        /// returns the rendertarget buffer object for this camera 
        /// <returns>returns pointer to rc_generic_ws</returns>
        /// </summary>
        rc_generic_ws* GetRt(const MdlRenderPassStage p_stage = MdlRenderPassStage::rsNormalRendering) const;
        /// <summary>
        /// Sets the rendertarget buffer object for this camera 
        /// <param name="p_rt">pointer to rc_generic_ws</param>
        /// </summary>
        void SetRt(rc_generic_ws* const p_rt, const MdlRenderPassStage p_stage = MdlRenderPassStage::rsNormalRendering);
        /// <summary>
        /// returns the parent display of this camera
        /// <returns>returns pointer to gfx3d_scg_display</returns>
        /// </summary>
        gfx3d_scg_display * GetParent() const;
        /// <summary>
        /// Sets the parent display of this camera
        /// <param name="p_parent">pointer to display</param>
        /// </summary>
        void SetParent(gfx3d_scg_display * const p_parent);
        /// <summary>
        /// Sets the camera projection as valid state
        /// <param name="p_valid">valid status</param>
        /// </summary>
        void SetValid(const bool p_valid);
        /// <summary>
        /// returns the camera x mag value
        /// <returns>returns camera x mag</returns>
        /// </summary>
        float32_t GetXmag() const;
        /// <summary>
        /// Sets the camera x mag value
        /// <param name="p_xmag">x mag value</param>
        /// </summary>
        void SetXmag(const float32_t p_xmag);
        /// <summary>
        /// returns the camera y mag value
        /// <returns>returns camera y mag</returns>
        /// </summary>
        float32_t GetYmag() const;
        /// <summary>
        /// Sets the camera y mag value
        /// <param name="p_ymag">y mag value</param>
        /// </summary>
        void SetYmag(const float32_t p_ymag);
        /// <summary>
        /// returns the mat4 camera / projection matrix. 
        /// <returns>returns pointer to gfx3d_4x4mat </returns>
        /// </summary>
        const gfx3d_4x4mat& GetProjMatrix() const;
        /// <summary>
        /// sets the mat4 camera / projection matrix. 
        /// <param name="p_mat">pointer to gfx3d_4x4mat data</param>
        /// </summary>
        void SetProjMatrix(const gfx3d_4x4mat& p_mat);
        /// <summary>
        /// Check if the camera is Orthographic
        /// <returns>returns  true if Orthographic camera</returns>
        /// </summary>
        bool IsOrthographic() const;
        /// <summary>
        /// Sets the camera as ortho or prespective(only the flag is written, projection matrix stays as is)
        /// <param name="p_orthographic">true - ortho, false - prespective</param>
        /// </summary>
        void SetIsOrthographic(const bool p_orthographic);
        /// <summary>
        /// Gets the camera FOV in radians
        /// <returns>returns fov</returns>
        /// </summary>
        float32_t GetFieldOfView() const;
        /// <summary>
        /// Sets the camera FOV in radians
        /// <param name="p_fieldOfView">fov</param>
        /// </summary>
        void SetFieldOfView(const float32_t p_fieldOfView);
        /// <summary>
        /// Sets the camera FOV in degrees
        /// <param name="p_fieldOfView">fov</param>
        /// </summary>
        void SetdFieldOfView(const float32_t p_fieldOfView);
        /// <summary>
        /// Gets the camera near clip
        /// <returns>returns near clip</returns>
        /// </summary>
        float32_t GetNearClipPlane() const;
        /// <summary>
        /// Sets the camera near clip
        /// <param name="p_nearClipPlane">near clip</param>
        /// </summary>
        void SetNearClipPlane(const float32_t p_nearClipPlane);
        /// <summary>
        /// Gets the camera far clip
        /// <returns>returns far clip</returns>
        /// </summary>
        float32_t GetFarClipPlane() const;
        /// <summary>
        /// Sets the camera far clip
        /// <param name="p_farClipPlane">far clip</param>
        /// </summary>
        void SetFarClipPlane(const float32_t p_farClipPlane);
        /// <summary>
        /// Gets the camera aspect ratio
        /// <returns>returns aspect ratio</returns>
        /// </summary>
        float32_t GetAspect() const;
        /// <summary>
        /// Sets the camera aspect ratio
        /// <param name="p_aspect">aspect ratio</param>
        /// </summary>
        void SetAspect(const float32_t p_aspect);
        /// <summary>
        /// Gets camera active status
        /// <returns>returns true if camera active</returns>
        /// </summary>
        bool GetActive() const;
        /// <summary>
        /// Sets the camera as active
        /// <param name="p_active">true - camera is active</param>
        /// </summary>
        void SetActive(const bool p_active);
        /// <summary>
        /// Recalculate the Projection matrix
        /// </summary>
        void Recalculate();
        /// <summary>
        /// Sets the scenegraph node to which this camera to be attached
        /// <param name="p_node">pointer to node</param>
        /// </summary>
        void SetCameraNode(gfx3d_scg_node* const p_node);
        /// <summary>
        /// Makes the parent node for this camera null if the node owns the camera
        /// </summary>
        void DetachCameraFromScene();
        /// <summary>
        /// Gets scenegraph node to which the camera is attached to
        /// <returns>returns gfx3d_scg_node pointer</returns>
        /// </summary>
        gfx3d_scg_node * GetCameraNode() const;
        /// <summary>
        /// Sets the view matrix
        /// <param name="p_vm">pointer to view matrix</param>
        /// </summary>
        void SetViewMatrix(const gfx3d_4x4mat& p_vm);
        /// <summary>
        /// Sets the model matrix of camera node. Inverse of this will be
        /// then set as View matrix
        /// <param name="p_vm">pointer to model matrix</param>
        /// </summary>
        void SetModelMatrix(const gfx3d_4x4mat& p_cm);
        /// <summary>
        /// Sets the camera position
        /// <param name="p_pos">camera position</param>
        /// </summary>
        void SetCamPosition(const glm::vec3& p_pos);
        /// <summary>
        /// Gets camera view matrix
        /// <returns>returns view matrix</returns>
        /// </summary>
        const gfx3d_4x4imat& GetViewMatrix() const;
        /// <summary>
        /// Gets camera position
        /// <returns>returns camera position</returns>
        /// </summary>
        const glm::vec3& GetCamPosition() const;
        /// <summary>
        /// Gets the previously set camera up vector (SetUpVector)
        /// <returns>returns camera up vector</returns>
        /// </summary>
        glm::vec3 GetUpVector() const;
        /// <summary>
        /// Sets the camera up vector and inturn sets the view matrix
        /// based on previously SetCamPosition & SetLookatVector
        /// </summary>
        void SetUpVector(const glm::vec3& p_up_vector);
        /// <summary>
        /// Gets the previously set camera loook at vector (SetLookatVector)
        /// <returns>returns camera loook at vector</returns>
        /// </summary>
        glm::vec3 GetLookatVector() const;
        /// <summary>
        /// Sets the camera target look at vector and inturn sets the view matrix
        /// based on previously SetCamPosition & SetUpVector
        /// </summary>
        void SetLookatVector(const glm::vec3& p_target);
        /// <summary>
        /// Sets the view matrix based on previously 
        /// passed camera eye, target, up vectors
        /// </summary>
        /// <param name="p_eye">camera/eye location as a vec3</param>
        /// <param name="p_target">lookat location as a vec3</param>
        /// <param name="p_up">up vector as a vec3</param>
        /// <param name="p_force">Force a view matrix calculation. Normally its done only when eye/lookat or up vector changes</param>
        void SetLookAt(const glm::vec3& p_eye, const glm::vec3& p_target, const glm::vec3& p_up, const bool p_force = false);
        /// True if Left Handed Lookat view matrix is calculated by set_viewLookAt
        /// False if Right Handed Lookat view matrix is calculated by set_viewLookAt
        bool IsLeftHandLookAt() const;
        /// Set to True if Left Handed Lookat view matrix must be calculated by set_viewLookAt
        void SetLeftHandLookAt(const bool p_lookatLH);
        /// <summary>
        /// Gets the scene in which this camera is attached
        /// <returns>returns scene</returns>
        /// </summary>
        gfx3d_scg_scene * GetScene() const;
        /// <summary>
        /// Update the camera objects by loading data from data model (rdf or gltf). 
        /// The actual loading will be done by inherited class Create override method.
        /// <param name="p_cam_index">camera id or index (>= 0)</param>
        /// </summary>
        virtual void Create(const int32_t p_cam_index) const;
        /// <summary>
        /// Returns true if Y is pointing up
        /// </summary>
        bool GetIsProjYUp() const;
        /// <summary>
        /// Set scissor rectangle
        /// <param name="rect">scissor rect to set</param>
        /// </summary>
        void SetScissorRect(const glm::vec4& rect);
        /// <summary>
        /// returns the scissor rectangle set by application
        /// </summary>
        glm::vec4 GetScissorRect() const;
        /// <summary>
        /// Set the sorting type
        /// </summary>
        /// <param name="p_sortType">rc_rsortType type.</param>
        void SetSortType(const rc_rsortType p_sortType);
        /// <summary>
        /// Get the sorting type
        /// </summary>
        rc_rsortType GetSortType() const;
        /// <summary>
        /// Convert the passed screen co-ordinate to world co ordinate
        /// </summary>
        /// <param name="p_pos">co-ordinate in screen space</param>
        /// <returns>world co ordinate</returns>
        glm::vec3 ScreenToWorldPoint(const glm::vec3& p_pos) const;
        /// <summary>
        /// Unloads the FBO rendertargets attached to this camera
        /// TODO : If there are multiple cameras attached to same FBO, the 
        /// Unload doesnot considers it and unlods the FBO. Even though there
        /// is no functional impact as the next render of a camera will load the
        /// FBO if it needs. But it will add an extra overhead of unnecessary 
        /// deletion and creation of FBO
        /// </summary>
        /// <returns>true on success</returns>
        bool UnLoad(const size_t p_scene = -1);
        /// <summary>
        /// Loads the camera object.
        /// </summary>
        /// <param name="p_scene">Scene which requests this load</param>
        /// <param name="p_visible">visibility flag for the calling node to decide if camera to load the assets or not</param>
        /// <returns>true on success</returns>
        bool Load(const size_t p_scene, const bool p_visible);
#if defined(RC_CAMVIEW_EDITOR_SUPPORT)
        /// <summary>
        /// Sets the editor view. i.e. if an editor wants to manipulate the view on top of what is set by the scene
        /// <param name="p_pitch">camera pitch</param>
        /// <param name="p_roll">camera roll</param>
        /// <param name="p_translate">camera position</param>
        /// <returns>returns true on success</returns>
        /// </summary>
        bool SetEditorView(const float32_t p_pitch, const float32_t p_roll, const float32_t p_translate);
        /// <summary>
        ///  Gets the Pitch, Roll and Translate values of editor view
        /// </summary>
        /// <returns>editor view</returns>
        glm::vec3 GetEditorView() const;
#endif
        /// <summary>
        /// returns the material object
        /// </summary>
        gfx3d_scg_material* GetMaterial(const MdlRenderPassStage p_stage = MdlRenderPassStage::rsNormalRendering) const;
        /// <summary>
        /// Sets a new material to primitive. Returns true if new material is set.
        /// Note : SetMaterial deletes the currently set material before updating the new material
        /// </summary>
        bool SetMaterial(gfx3d_scg_material* const p_material, const MdlRenderPassStage p_stage = MdlRenderPassStage::rsNormalRendering);
        /// <summary>
        /// Retunrs the sorted list of renderpasses available for this Camera
        /// </summary>
        /// <returns></returns>
        std::vector<MdlRenderPassStage> GetRenderPasses() const;
        /// <summary>
        /// Perform post processing (rendering) for the camera. Rendering is performed only if passed stage is a post process stage
        /// </summary>
        /// <param name="p_stage">post process stage id</param>
        void PostProcess(const MdlRenderPassStage p_rpstage);
    };
    /// @}
}

#endif