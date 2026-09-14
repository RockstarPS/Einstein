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
//  Filename    : gfx3d_scg_light.h
//  Description : GFX3D scene graph light object
//  Created on  : 19-Oct-2022 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_scg_light.h
/// \brief GFX3D scene graph light object
#ifndef gfx3d_scg_light_h
#define gfx3d_scg_light_h

namespace rendercore_engine
{
    /// \ingroup Engine
    /// @{
    /// <summary>
    /// Light types https://github.com/KhronosGroup/glTF/tree/main/extensions/2.0/Khronos/KHR_lights_punctual
    /// </summary>
    enum class rc_matlighttype
    {
        ltDirectional = 0,
        ltPoint = 1,
        ltSpot = 2
    };
    /// <summary>
    /// Light object https://github.com/KhronosGroup/glTF/tree/main/extensions/2.0/Khronos/KHR_lights_punctual
    /// <example>
    /// To use lights in shader, prepare the uniform declarations as below.
    /// This will make the engine to upload the lights to the shader
    /// struct Light
    /// {
    ///    vec3 direction;     // direction of light
    ///    float range;        // range of light
    ///    vec3 color;         // color of light
    ///    float intensity;    // intesity of light
    ///    vec3 position;      // position of light
    ///    float innerConeCos; // cos(falloff start angle)
    ///    float outerConeCos; // cos(falloff end angle)
    ///    int type;           // Directional = 0, Point = 1, Spot = 2
    /// };
    /// uniform Light u_Lights[RC_MAX_LIGHTS_COUNT];    // lights array. Set RC_MAX_LIGHTS_COUNTfrom 1 to Numner of required lights
    /// uniform int u_LightsCount;                      // number of lights uploaded by engine
    /// </example>
    /// </summary>
    class gfx3d_scg_light
    {
    private:
        std::string name;       ///< name of the light
        size_t cullingMask;     ///< mask used for culling objects (gfx3d_scg_light::cullingMask & gfx3d_scg_node::cullingMask) determines if this light is used on the node
        float32_t range;        ///< Distance cutoff after which lights intensity reaches zero. Range supported only for point and spot light
        float32_t intensity;    ///< Brightness of light. 
        float32_t innerCone;    ///< Falloff start angle in radians from centre of 'spot' light 
        float32_t outerCone;    ///< Falloff end angle in radians from centre of 'spot' light 
        glm::vec3 direction;    ///< Direction of light. Derived from light's attached node
        glm::vec3 color;        ///< RGB color value of light
        glm::vec3 position;     ///< Position of the light. Derived from light's attached node
        glm::vec3 mvposition;   ///< Model-View-Position of the light for godot std material. Derived from light's attached node
        glm::vec3 mvdirection;  ///< Model-View-Direction of light. Derived from light's attached node
        rc_matlighttype type;   ///< Type of light
        bool visible;           ///< Light is visible or not.
        float32_t attenuation;  ///< godot property
        float32_t specular_amount;///< godot property
        float32_t size;         ///< godot property
        float32_t cone_attenuation;///< godot property
        bool shadowEnabled = true;

        int32_t shadowSize = 1024;  ///< size of shadow map, width=height=shadowSize
        GLuint depth_map_fbo = 0;
        gfx3d_scg_texture* depth_map_texture = nullptr;
        gfx3d_scg_material* depth_buffer_mat = nullptr;
        glm::fmat4x4 vp_matrix{ 1.0F };///< view projection matrix
    public:
        gfx3d_scg_light();
        ~gfx3d_scg_light();
        /// <summary>
        /// Get the name of light
        /// </summary>
        /// <returns>name of light</returns>
        std::string GetName() const;
        /// <summary>
        /// Get the direction of light
        /// </summary>
        /// <returns>direction of light</returns>
        glm::vec3 GetDirection() const;
        /// <summary>
        /// Get the light color
        /// </summary>
        /// <returns>rgb color</returns>
        glm::vec3 GetColor() const;
        /// <summary>
        /// Gets the position of the light
        /// </summary>
        /// <returns>position of light</returns>
        glm::vec3 GetPosition() const;
        /// <summary>
        /// Attenuation of the light (godot property)
        /// </summary>
        /// <returns>range</returns>
        float32_t GetAttenuation() const;
        /// <summary>
        /// SpecularAmount of the light (godot property)
        /// </summary>
        /// <returns>range</returns>
        float32_t GetSpecularAmount() const;
        /// <summary>
        /// Size of the light (godot property)
        /// </summary>
        /// <returns>range</returns>
        float32_t GetSize() const;
        /// <summary>
        /// ConeAttenuation of the light (godot property)
        /// </summary>
        /// <returns>range</returns>
        float32_t GetConeAttenuation() const;
        /// <summary>
        /// Range of the light
        /// </summary>
        /// <returns>range</returns>
        float32_t GetRange() const;
        /// <summary>
        /// Intensity of the light
        /// </summary>
        /// <returns>intensity</returns>
        float32_t GetIntensity() const;
        /// <summary>
        /// Falloff start angle for spot light
        /// </summary>
        /// <returns>angle in radiance</returns>
        float32_t GetInnerCone() const;
        /// <summary>
        /// Falloff end angle for spot light
        /// </summary>
        /// <returns>angle in radiance</returns>
        float32_t GetOuterCone() const;
        /// <summary>
        /// Type of the light
        /// </summary>
        /// <returns>type</returns>
        rc_matlighttype GetType() const;
        /// <summary>
        /// Attenuation of the light (godot property)
        /// </summary>
        /// <returns>range</returns>
        void SetAttenuation(const float32_t p_pval);
        /// <summary>
        /// SpecularAmount of the light (godot property)
        /// </summary>
        /// <returns>range</returns>
        void SetSpecularAmount(const float32_t p_pval);
        /// <summary>
        /// Size of the light (godot property)
        /// </summary>
        /// <returns>range</returns>
        void SetSize(const float32_t p_pval);
        /// <summary>
        /// ConeAttenuation of the light (godot property)
        /// </summary>
        /// <returns>range</returns>
        void SetConeAttenuation(const float32_t p_pval);
        /// <summary>
        /// Set the name of light
        /// </summary>
        /// <param name="p_name">light name to set</param>
        void SetName(const std::string& p_name);
        /// <summary>
        /// Sets the position of the light. Called internally during pre_render stage 
        /// </summary>
        /// <param name="p_position">position xyz value to set</param>
        void SetPosition(const glm::vec3& p_position);
        /// <summary>
        /// Sets the direction of the light. Called internally during pre_render stage 
        /// </summary>
        /// <param name="p_direction">direction xyz value to set</param>
        void SetDirection(const glm::vec3& p_direction);
        /// <summary>
        /// Sets the color of the light.
        /// </summary>
        /// <param name="p_direction">rgb color value to set</param>
        void SetColor(const glm::vec3& p_color);
        /// <summary>
        /// Sets the range of the light.
        /// </summary>
        /// <param name="p_range">range value to set</param>
        void SetRange(const float32_t p_range);
        /// <summary>
        /// Sets the intensity of the light.
        /// </summary>
        /// <param name="p_intensity">intensity value to set</param>
        void SetIntensity(const float32_t p_intensity);
        /// <summary>
        /// Sets the start falloff angle of the light.
        /// </summary>
        /// <param name="p_innerCone">angle in radiance</param>
        void SetInnerCone(const float32_t p_innerCone);
        /// <summary>
        /// Sets the end falloff angle of the light.
        /// </summary>
        /// <param name="p_outerCone">angle in radiance</param>
        void SetOuterCone(const float32_t p_outerCone);
        /// <summary>
        /// Sets the type of the light.
        /// </summary>
        /// <param name="p_type">type of the light</param>
        void SetType(const rc_matlighttype p_type);
        /// <summary>
        /// Uploads the uniform values of the light.
        /// This is called internally during render stage
        /// </summary>
        /// <param name="p_index">index of the light</param>
        /// <param name="p_mat">material to which uniforms to be uploaded</param>
        /// <returns>true on success</returns>
        bool UploadUniforms(const size_t p_index, gfx3d_scg_material* const p_mat);
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
        /// Returns true if node is visible.
        /// </summary>
        /// <returns>true or false</returns>
        bool get_active() const;
        /// <summary>
        /// Sets node visibility.
        /// </summary>
        void set_active(const bool p_active);
        /// <summary>
        /// Sets the camera currently active and rendering
        /// </summary>
        /// <param name="p_camera">pointer to camera</param>
        void SetActiveCamera(gfx3d_scg_camera* p_camera);

        bool IsCastShadow() const;

        void SetCastShadow(const bool p_value);

        void ActivateShadowPass(gfx3d_scg_display* p_display, gfx3d_scg_scene* p_scene);

        void DeactivateShadowPass(gfx3d_scg_display* p_display, gfx3d_scg_scene* p_scene);

        gfx3d_scg_texture* get_depth_map_texture() const;

        void set_vp_matrix(const glm::fmat4x4& p_value);

    };
    /// @}
}

#endif