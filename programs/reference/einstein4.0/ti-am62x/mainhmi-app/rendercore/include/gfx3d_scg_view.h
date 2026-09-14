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
//  Filename    : gfx3d_scg_view.h
//  Description : GFX3D scene graph camera object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_scg_view.h
/// \brief GFX3D scene graph camera object
#ifndef gfx3d_scg_view_h
#define gfx3d_scg_view_h

namespace rendercore_engine
{
    /// \ingroup Engine
    /// @{
    /// <summary>
	/// Holds the camera configuration for the scene graph. Camera is attached to a gfx3d_scg_node class
 	/// </summary>
	class gfx3d_scg_view
	{
	private:
		gfx3d_vec3 cam_position;	///< camera position
        glm::vec3 eye{ 0.0F, 0.0F, -1.0F };    ///< eye position
        glm::vec3 lookat{ 0.0F };	            ///< where to look
        glm::vec3 up_vec{ 0.0F, 1.0F, 0.0F };	///< up vector
        float32_t pitch = 0.0F;			///< pitch of the view cam
		float32_t roll = 0.0F;			///< roll for the view cam
		float32_t translate = 0.0F;		///< translation used by the view cam
        float32_t epitch = 0.0F;		///< editor pitch of the view cam
        float32_t eroll = 0.0F;			///< editor roll for the view cam
        float32_t etranslate = 0.0F;	///< editor translation used by the view cam
        bool lookatLH = false;      ///< lookat should result in a Left handed view matrix or Right handed (default)
        bool valid = false;			///< checks is view is valu
#if defined(RC_CAMVIEW_EDITOR_SUPPORT)
        gfx3d_4x4mat editviewMatrix;///< view matrix set by an editor (for debug purpose)
        gfx3d_4x4imat matrix;		///< resultant view 4x4 matrix
#endif
        gfx3d_4x4imat viewMatrix;	///< object view matrix based on user configuration
    public:
        /// constructs a camera view object
		gfx3d_scg_view();
		/// returns the resultant view matrix (product of viewMatrix & editviewMatrix)
        const gfx3d_4x4imat& GetMatrix(void) const;
		/// <summary>
		/// Sets the view matrix and updates the camera position
		/// </summary>
		/// <param name="p_mat">view or model matrix of the camera</param>
		/// <param name="p_inverse">if view matrix is passed p_inverse to be set false, if model matrix is passed p_inverse = true</param>
		void set_matrix(const gfx3d_4x4mat& p_mat, const bool p_inverse = false);
		/// returns the camera position
		const gfx3d_vec3 &get_cam_position(void) const;
		/// sets the camera position 
        void set_cam_position(const glm::vec3 &p_pos);
		/// checks if view is valid
		bool IsValid(void) const;
        /// resets the properties of the view to its default
        void Reset(void);
        /// Called after the render cycle for the camera. Used to clear changed flags
        void done(void);
		/// <summary>
		/// Sets the View matrix based on glm::lookAt operation
		/// <param name="p_eye">eye location as a vec3, default vec3(0.0, 0.0, -1.0)</param>
		/// <param name="p_lookat">lookat location as a vec3, default to origin vec3(0.0, 0.0, 0.0)</param>
		/// <param name="p_up_vec">up vector as a vec3, default to Y up vec3(0.0, 1.0, 0.0)</param>
        /// <param name="p_force">Force a view matrix calculation. Normally its done only when eye/lookat or up vector changes</param>
        /// <returns>true if the view matrix is updated</returns>
        /// </summary>
		bool set_viewLookAt(const glm::vec3 p_eye, const glm::vec3 p_lookat, const glm::vec3 p_up_vec, const bool p_force = false);
		/// <summary>
		/// Sets the View matrix based on the Pitch, Roll and Translate values provided
        /// <returns>true if the view matrix is updated</returns>
        /// </summary>
		bool set_view(const float32_t p_pitch, const float32_t p_roll, const float32_t p_translate);
        /// set this view as valid
        void SetValid(const bool p_valid);
        /// Get the object viewMatrix. 
        const gfx3d_4x4imat& GetViewMatrix() const;
        /// Set the object viewMatrix
        void SetViewMatrix(const gfx3d_4x4imat& p_viewMatrix);
#if defined(RC_CAMVIEW_EDITOR_SUPPORT)
        /// sets the editor view, based on the Pitch, Roll and Translate values provided
        /// returns true if the editor view is updated
        bool set_editor_view(const float32_t p_pitch, const float32_t p_roll, const float32_t p_translate);
        /// <summary>
        ///  Gets the Pitch, Roll and Translate values of editor view
        /// </summary>
        /// <returns>editor view</returns>
        glm::vec3 get_editor_view() const;
        /// Get the editviewMatrix. 
        const gfx3d_4x4mat& GetEditviewMatrix() const;
        /// Set the editviewMatrix
        void SetEditviewMatrix(const gfx3d_4x4mat& p_editviewMatrix);
#endif
        /// Get camera position
        gfx3d_vec3 GetCameraPosition() const;
        /// Set camera position
        void SetCameraPosition(const gfx3d_vec3 p_cam_position);
        /// Get pitch
        float32_t GetPitch() const;
        /// Set pitch
        void SetPitch(const float32_t p_pitch);
        /// Get roll
        float32_t GetRoll() const;
        /// Set roll
        void SetRoll(const float32_t p_roll);
        /// Get translate
        float32_t GetTranslate() const;
        /// Set translate
        void SetTranslate(const float32_t p_translate);
        /// Get eye
        glm::vec3 GetEye() const;
        /// Set eye
        void SetEye(const glm::vec3 p_eye);
        /// Get lookat
        glm::vec3 GetLookat() const;
        /// Set lookat
        void SetLookat(const glm::vec3 p_lookat);
        /// Get up vector
        glm::vec3 GetUpVector() const;
        /// Set Up vector
        void SetUpVector(const glm::vec3 p_up_vec);
        /// True if Left Handed Lookat view matrix is calculated by set_viewLookAt
        /// False if Right Handed Lookat view matrix is calculated by set_viewLookAt
        bool IsLeftHandLookAt() const;
        /// Set to True if Left Handed Lookat view matrix must be calculated by set_viewLookAt
        /// Note : If this valus is changed at run time, new view matrix will be calculated 
        /// only when thereis a change to last set SetEye(), SetUpVector() or SetLookat()
        /// set_viewLookAt must be invoked with force option to make the change immediate
        void SetLeftHandLookAt(const bool p_lookatLH);
    };
    /// @}
}

#endif