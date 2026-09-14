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
//  Filename    : gfx3d_scg_material.h
//  Description : Wrapper Class for the gltf PBR shader handling 
//  Created on  : 10-Aug-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_scg_material.h
/// \brief Wrapper Class for the gltf PBR shader handling 

#ifndef gfx3d_scg_material_h
#define gfx3d_scg_material_h

#include <map>
#include "gfx3dTexture2D.h"
namespace rendercore_engine
{
    /// \ingroup Engine
    /// @{
    ///<summary>
	/// material class, contains shader objects.
	///</summary>
	class gfx3d_scg_material : public gfx3d_scg_mem_obj
    {
    protected:
        std::string name;								///< name of the material
        gfx3d_scg_display * display = nullptr;            ///< the parent display object
        gfx3d_scg_primitive* parent = nullptr;          ///< the parent primitive object
        CHAR8 const* lvertShader = nullptr;				///< path to vertex shader file
        CHAR8 const* lfragShader = nullptr;				///< path to fragment shader file
        CHAR8 const* lbProgram = nullptr;               ///< path to program binary file
        size_t lvertShaderLength = 0U;					///< shader length
        size_t lfragShaderLength = 0U;					///< shader length
        uint32_t uid = 0U;							    ///< uid for material
        uint32_t vs_uid = RC_MAT_INVALID_SHADER_ID;		///< unique ID for vertex shader.. same id is generated for vertex shaders with same source
        uint32_t fs_uid = RC_MAT_INVALID_SHADER_ID;		///< unique ID for fargment shader.. same id is generated for fargment shaders with same source
        uint32_t po_uid = RC_MAT_INVALID_SHADER_ID;		///< unique ID for the program... same id is generated if same vertex & fragment shaders are used in another material
        GLenum shaderBinaryFormat = 0U;                  ///< binary shader format
        MdlBlendFactor srcBlendfactor = MdlBlendFactor::bfUnset;///>Color Source Blend Factor
        MdlBlendFactor dstBlendfactor = MdlBlendFactor::bfUnset;///>Color Dst Blend Factor
        MdlBlendFactor aSrcBlendfactor = MdlBlendFactor::bfUnset;///>Alpha Source Blend Factor
        MdlBlendFactor aDstBlendfactor = MdlBlendFactor::bfUnset;///>Alpha Dst Blend Factor
        MdlBlendEquation ablendEquation = MdlBlendEquation::beUnset; ///< GL Alpha blend equation to be used (see glBlendEquationSeperate)
        MdlBlendEquation blendEquation = MdlBlendEquation::beUnset; ///< GL bland equation to be used (see glBlendEquation)
        bool isShaderUri = true;						///< shader uri
        void setProgramObject(const GLuint p_po); ///< Sets the gl program object (currently exist for unit test purpose.., not intended for usage)
        void setPSUID(const uint32_t p_uid); ///< Set the program shader UID (currently exist for unit test purpose.., not intended for usage)
    private:
        GLuint  lpo = 0U;						///< storage for linked shader program object for this material..
        rc_attribute_map glslAttributeData;		///< attribute data 
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
        std::recursive_mutex data_mutex; ///< mutex to protect all data access by threads
#endif
        /// <summary>
        /// builds the shader and returns the GL shader program object.
        /// </summary>
        /// <returns>returns shader object </returns>
        void build_shader(rc_glslProgramObj& p_progShader);
        /// <summary>
        /// builds the default shader and returns the GL shader program object.
        /// </summary>
        /// <returns>returns shader object </returns>
        void build_defshader(rc_glslProgramObj& p_progShader);
        /// <summary>
        /// Returns a default texture to be used if the texture object is found invalid in the material
        /// </summary>
        /// <returns>returns gl texture object </returns>
        GLuint GetDefaultTexture() const;
        /// <summary>
        /// Returns a default texture to be used if the cubemap texture object is found invalid in the material
        /// </summary>
        /// <returns>returns gl texture object </returns>
        GLuint GetDefaultCubeMapTexture() const;
        gfx3d_scg_material& operator= (const gfx3d_scg_material& p_object);
        /// <summary>
        /// Returns a valid that can be used. If the p_id is < RC_MAT_INVALID_SHADER_ID,
        /// the returned value is also p_id. If RC_MAT_INVALID_SHADER_ID is passed
        /// then the next unused ID from 0x80000000 - 0x0xFFFFFFFC range is returned
        /// incase of any failure RC_MAT_INVALID_SHADER_ID is returned
        /// </summary>
        /// <param name="p_id">input ID</param>
        /// <returns>translated ID if possible. RC_MAT_INVALID_SHADER_ID indicates a failure</returns>
        uint32_t generate_shader_id(const uint32_t p_id) const ;
        rc_flag sceneLoadedMask;                        ///< indicates for which scenes loaded this object. Used to decide how many are using
        gfx3d_material_properties* GetProjectMatProperty() const;
    protected:
        mdl_cullMode cullMode = mdl_cullMode::cmUnset;	///< culling mode for material
        rc_uniform_map glslUniformData;		///< Currently active Uniforms & its data to glsl shader
        rc_uniform_map glslUniformDefData;  ///< Default values for Uniform data
    public:
        /// <summary>
        /// Constructs a material
        /// </summary>
        /// <param name="p_disp"> parent display this accessor belongs to </param>
        /// <param name="p_uid"> ID of the material, make sure  all instances of the same material has same ID </param>
        gfx3d_scg_material(gfx3d_scg_display * const p_disp, const int32_t p_uid);
        /// Copy construct
        gfx3d_scg_material(const gfx3d_scg_material& p_obj);
        /// Distructor
        virtual ~gfx3d_scg_material();
        /// <summary>
        /// Returns the name of the material
        /// </summary>
        const std::string& GetName() const;
        /// <summary>
        /// Sets the name of the material
        /// </summary>
        void SetName(const std::string p_name);
        /// <summary>
        /// Returns the parent display of the material
        /// </summary>
        gfx3d_scg_display* GetDisplay() const;
        /// <summary>
        /// Sets the parent display of this material
        /// <param name="p_parent">pointer to display</param>
        /// </summary>
        void SetDisplay(gfx3d_scg_display* const p_val);
        /// <summary>
        /// Returns the parent primitive of the material
        /// </summary>
        gfx3d_scg_primitive* GetParent() const;
        /// <summary>
        /// Sets the parent primitive of this material
        /// <param name="p_parent">pointer to display</param>
        /// </summary>
        void SetParent(gfx3d_scg_primitive* const p_val);
        /// <summary>
        /// Returns the vertex shader unique ID
        /// </summary>
        GLuint GetVSUID() const;
        /// <summary>
        /// Returns the fragment shader unique ID
        /// </summary>
        GLuint GetFSUID() const;
        /// <summary>
        /// Returns the program shader unique ID
        /// </summary>
        GLuint GetPSUID() const;
        /// <summary>
        /// Returns the unique ID for the material
        /// </summary>
        GLuint GetUID() const;
        /// <summary>
        /// Returns the Vertex shader string (IsShaderStringUri - false) or URI/path (IsShaderStringUri - true) for the material. 
        /// </summary>
        CHAR8 const* GetVertexShader() const;
        /// <summary>
        /// Returns the Vertex shader string length. 
        /// </summary>
        size_t GetVertShaderLength() const;
        /// <summary>
        /// Returns the Fragment shader string (IsShaderStringUri - false) or URI/path (IsShaderStringUri - true) for the material. 
        /// </summary>
        CHAR8 const* GetFragmentShader() const;
        /// <summary>
        /// Returns the Fragment shader string length. 
        /// </summary>
        size_t GetFragShaderLength() const;
        /// <summary>
        /// Returns true if the fragment/vertex shader string points to file path/URI. If false then its pointing to shader file content as ascii char array
        /// </summary>
        bool IsShaderStringUri() const;
        /// <summary>
        /// Returns the Program Binary URI/path for the material. 
        /// </summary>
        CHAR8 const* GetProgramBinaryShader() const;
        /// <summary>
        /// Returns the size of default uniforms data array for the material. 
        /// </summary>
        size_t GetUniformDefDataSize() const;
        /// <summary>
        /// Returns the size of attribute data array for the material. 
        /// </summary>
        size_t GetAttributeDataSize() const;
        /// <summary>
        /// Returns the default uniforms data for the passed unifrom name. 
        /// </summary>
        const rc_glslUniformData * GetUniformDefData(const std::string &p_uniform) const;
        /// <summary>
        /// Returns the default uniforms data for the passed unifrom name. 
        /// </summary>
        const rc_glslUniformData * GetUniformData(const std::string& p_uniform) const;
        /// <summary>
        /// Returns the attribute data for the passed attribute name. 
        /// </summary>
        const rc_glslAttributeData* GetAttributeData(const std::string& p_attribute) const;
        /// <summary>
        /// Returns a start iterator to attribute data. 
        /// </summary>
        rc_attribute_map::iterator GetAttributeDataIterator();
        /// <summary>
        /// Clears all the attribute data from list.
        /// </summary>
        void ClearAttributeData();
        /// <summary>
        /// Returns a start iterator to uniform data. 
        /// </summary>
        rc_uniform_map::iterator GetUniformDataIterator();
        /// <summary>
        /// Returns a start iterator to default uniform data. 
        /// </summary>
        rc_uniform_map::iterator GetUniformDefDataIterator();
        /// <summary>
        /// Returns attribute data iterator end()
        /// </summary>
        rc_attribute_map::iterator GetAttributeDataIteratorEnd();
        /// <summary>
        /// Returns default uniform data iterator end()
        /// </summary>
        rc_uniform_map::iterator GetUniformDefDataIteratorEnd();
        /// <summary>
        /// Returns the gl program object. 
        /// </summary>
        GLuint GetProgramObject() const;
        /// <summary>
        /// upload all predefined attributes to gl
        /// <returns>returns true if all attributes are uploaded</returns>
        /// </summary>
        bool uploadAttributes(void);
        /// <summary>
        /// Uploads all predefined uniforms
        /// <returns>returns true if success </returns>
        /// </summary>
        bool uploadUniforms(void);
        /// <summary>
        /// Generates the shader if not created yet and activates it
        /// <returns>returns true if success </returns>
        /// <param name="p_scene"> scene which is requesting this shader </param>
        /// <param name="p_visible">visibility of parent node, affects texture loading</param>
        /// </summary>
        bool loadShader(const size_t p_scene, const bool p_visible=true, const bool p_sync = false);
        /// <summary>
        /// Uploads attributes & uniforms. invokes uploadAttributes & uploadUniforms
        /// </summary>
        void upload(void);
        virtual void SetFloat(const std::string p_uniform, const float32_t p_val);				///< uniform gets float32_t
        virtual float32_t GetFloat(const std::string p_uniform);							///< uniform sets int
        virtual void SetInt(const std::string p_uniform, const int32_t p_val);					///< uniform gets int
        virtual int32_t GetInt(const std::string p_uniform);								///< uniform sets a vector2
        virtual void SetVector(const std::string p_uniform, const glm::vec2 p_val);			///< uniform sets a vector3
        virtual void SetColor(const std::string p_uniform, const glm::vec4 p_val);			///< uniform sets a Color
        virtual glm::vec2 GetVec2(const std::string p_uniform);                       ///< uniform gets Vector2
        virtual glm::vec3 GetVec3(const std::string p_uniform);                       ///< uniform gets Vector3
        virtual glm::vec4 GetVec4(const std::string p_uniform);                       ///< uniform gets Vector4
        virtual glm::vec4 GetColor(const std::string p_uniform);                      ///< uniform gets Color
        gfx3dTexture2D * GetTexture(const std::string p_uniform);                     ///< gets sampler2d associated with the uniform.
        virtual void SetVector(const std::string p_uniform, const glm::vec3 p_val);			///< uniform sets a vector4
        virtual void SetVector(const std::string p_uniform, const glm::vec4 p_val);			///< uniform sets a mat4
        virtual void SetMatrix(const std::string p_uniform, const glm::mat4 p_val);			///< uniform sets a mat3
        virtual void SetMatrix(const std::string p_uniform, const glm::mat3 p_val);			///< uniform sets a mat2
        virtual void SetMatrix(const std::string p_uniform, const glm::mat2 p_val);			///< uniform sets texture
        void SetMatrixInv(const std::string p_dstuniform, const std::string p_srcuniform);  ///< sets the inverse matrix of p_srcuniform to p_dstuniform
        void SetMatrixInv(const std::string p_uniform, const glm::mat2 p_val);              ///< sets the inverse matrix of p_val to p_uniform
        void SetMatrixInv(const std::string p_uniform, const glm::mat3 p_val);              ///< sets the inverse matrix of p_val to p_uniform
        void SetMatrixInv(const std::string p_uniform, const glm::mat4 p_val);              ///< sets the inverse matrix of p_val to p_uniform
        virtual void SetTexture(const std::string p_uniform, gfx3dTexture2D * const p_val);	///< uniform sets sampler2d
        /// sets attribute data
        void set_attrib(const std::string p_attrib, const GLuint p_glabuffer_id, const GLint size, const GLenum type, const GLboolean normalized, const GLsizei stride, const void * const pointer);
        void set_attrib(const std::string p_attrib, const rc_glslAttributeData& p_data);
        /// <summary>
        /// Loads this material by creating dynamic contents (shader objects)..
        /// </summary>
        /// <param name="p_scene">id of the scene which is requesting this node load</param>
        /// <param name="p_visible">visibility of parent node, affects resource loading</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        virtual bool Load(const size_t p_scene, const bool p_visible=true, const bool p_sync = false);
        /// <summary>
        /// Unloads this node by deleting dynamic contents.. if none of the scene uses this node anymore
        /// </summary>
        /// <param name="p_scene">id of the scene which is requesting this node unload</param>
        /// <returns>returns the load status, true - unloaded / false - loaded </returns>
        virtual bool UnLoad(const size_t p_scene);
        /// <summary>
        /// Sets default values to uniforms present in the material
        /// </summary>
        void Create(void);
        /// <summary>
        /// Start creating gl texture objects from decoded image data
        /// gets a gl texture object for the passed gltf texture index and 
        /// set the filter & wrap mode settings 
        /// This call is made while uploading the uniforms, so texture objects
        /// will have to be created synchronously..
        /// </summary>
        GLuint update_texture(rc_glslUniformData& p_data);
        /// <summary>
        /// This call happens during the material creation..
        /// issues a load texture object request (issue command to start decoding of images)
        /// Texture creation will be requested to happen asynchronously in background
        /// </summary>
        void load_texture(const size_t p_scene, rc_glslUniformData& p_data, const bool p_sync = false);
        /// gets the cull mode for material
		mdl_cullMode GetCullMode(void) const;
        /// gets the cull mode for material
        void SetCullMode(const mdl_cullMode p_cullmode);
        ///gets the blend mode for materials
        MdlBlendMode GetBlendMode(void) const;
        ///Sets the blend mode for materials
        void SetBlendMode(const MdlBlendMode p_blend);
        /// <summary>
        /// Gets the Src blend Factor 
        /// </summary>
        MdlBlendFactor GetSrcBlendFactor(void) const;
        /// <summary>
        /// Gets the Dst blend Factor 
        /// </summary>
        MdlBlendFactor GetDstBlendFactor(void) const;
        /// <summary>
        /// Gets the Alpha Src blend Factor 
        /// </summary>
        MdlBlendFactor GetAlphaSrcBlendFactor(void) const;
        /// <summary>
        /// Gets the Alpha Dst blend Factor 
        /// </summary>
        MdlBlendFactor GetAlphaDstBlendFactor(void) const;
        /// <summary>
        /// Sets the Src blend Factor 
        /// <param name="p_blendFactor">blend factor to set</param>
        /// </summary>
        void SetSrcBlendFactor(const MdlBlendFactor p_blendFactor);
        /// <summary>
        /// Sets the Dst blend Factor 
        /// <param name="p_blendFactor">blend factor to set</param>
        /// </summary>
        void SetDstBlendFactor(const MdlBlendFactor p_blendFactor);
        /// <summary>
        /// Sets the Alpha Src blend Factor 
        /// <param name="p_blendFactor">blend factor to set</param>
        /// </summary>
        void SetAlphaSrcBlendFactor(const MdlBlendFactor p_blendFactor);
        /// <summary>
        /// Sets the Alpha Dst blend Factor 
        /// <param name="p_blendFactor">blend factor to set</param>
        /// </summary>
        void SetAlphaDstBlendFactor(const MdlBlendFactor p_blendFactor);
        /// sets optional alpha channel blend mode
        /// <param name="p_blendMode">blend mode to set</param>
        /// </summary>
        void SetAlphaBlendMode(const MdlAlphaBlendMode p_blendMode);
        /// <summary>
        /// sets optional alpha channel blend mode
        /// <param name="p_blendMode">blend mode to set</param>
        /// </summary>
        void SetAlphaBlendEquation(const MdlBlendEquation p_blendEquation);
        /// <summary>
        /// sets the blende equation
        /// <param name="p_blendMode">blend equation to set</param>
        /// </summary>
        void SetBlendEquation(const MdlBlendEquation p_blendEquation);
        /// <summary>
        /// Gets optional alpha channel blend mode
        /// </summary>
        MdlAlphaBlendMode GetAlphaBlendMode(void) const;
        /// <summary>
        /// Gets optional alpha channel blend mode
        /// </summary>
        MdlBlendEquation GetAlphaBlendEquation(void) const;
        /// <summary>
        /// Gets the blende equation
        /// </summary>
        MdlBlendEquation GetBlendEquation(void) const;
        /// Get the end of the uniform map
        rc_uniform_map::iterator GetUniformEndIterator();
        /// Get a reference to uniform location so that it can then directly be write it later without name lookup
        rc_uniform_map::iterator GetUniformIterator(const std::string p_uniform);
        /// uniform gets float32_t
        void SetFloat(const rc_uniform_map::iterator& p_loc, const float32_t p_val);
        /// uniform sets int
        float32_t GetFloat(const rc_uniform_map::iterator& p_loc);
        /// uniform gets int
        void SetInt(const rc_uniform_map::iterator& p_loc, const int32_t p_val);
        /// uniform sets a vector2
        int32_t GetInt(const rc_uniform_map::iterator& p_loc);
        /// uniform sets a vector3
        void SetVector(const rc_uniform_map::iterator& p_loc, const glm::vec2& p_val);
        /// uniform sets a Color
        void SetColor(const rc_uniform_map::iterator& p_loc, const glm::vec4& p_val);
        /// uniform gets Vector2
        glm::vec2 GetVec2(const rc_uniform_map::iterator& p_loc);
        /// uniform gets Vector3
        glm::vec3 GetVec3(const rc_uniform_map::iterator& p_loc);
        /// uniform gets Vector4
        glm::vec4 GetVec4(const rc_uniform_map::iterator& p_loc);
        /// uniform gets Color
        glm::vec4 GetColor(const rc_uniform_map::iterator& p_loc);
        /// gets sampler2d associated with the uniform.
        gfx3dTexture2D * GetTexture(const rc_uniform_map::iterator& p_loc);
        /// uniform sets a vector4
        void SetVector(const rc_uniform_map::iterator& p_loc, const glm::vec3& p_val);
        /// uniform sets a mat4
        void SetVector(const rc_uniform_map::iterator& p_loc, const glm::vec4& p_val);
        /// uniform sets a mat3
        void SetMatrix(const rc_uniform_map::iterator& p_loc, const glm::mat4& p_val);
        /// uniform sets a mat2
        void SetMatrix(const rc_uniform_map::iterator& p_loc, const glm::mat3& p_val);
        /// uniform sets texture
        void SetMatrix(const rc_uniform_map::iterator& p_loc, const glm::mat2& p_val);
        /// sets the inverse matrix of p_srcuniform to p_dstuniform
        void SetMatrixInv(const rc_uniform_map::iterator itdst, const rc_uniform_map::iterator itsrc);
        /// sets the inverse matrix of p_val to p_uniform
        void SetMatrixInv(const rc_uniform_map::iterator& p_loc, const glm::mat2& p_val);
        /// sets the inverse matrix of p_val to p_uniform
        void SetMatrixInv(const rc_uniform_map::iterator& p_loc, const glm::mat3& p_val);
        /// sets the inverse matrix of p_val to p_uniform
        void SetMatrixInv(const rc_uniform_map::iterator& p_loc, const glm::mat4& p_val);
        /// uniform sets sampler2d by rendercore_engine::gfx3dTexture2D
        void SetTexture(const rc_uniform_map::iterator& p_loc, gfx3dTexture2D * const p_val);
        /// adds child material to this object (no function here, added for extension to gfx3d_scg_material_group)
        virtual int32_t AddChildren(gfx3d_scg_material * const p_material);
        /// <summary>
        /// This exists for the IMGUI.
        /// </summary>
        /// <returns>loaded flag</returns>
        rc_flag get_scene_loaded_mask() const;
        /// <summary>
        /// Memmory object unload function.
        /// </summary>
        /// <returns>unloaded flag</returns>
        bool MemMonitorObjUnload(void);
        /// Returns the total number of material instances active
        /// </summary>
        /// <returns>total number of material instances</returns>
        size_t GetMatInstaces();
        /// <summary>
        /// Sets the scene as dirty / has property changes
        /// </summary>
        void SetDirty();
    };
    /// @}
}

#endif//gfx3d_scg_material_h