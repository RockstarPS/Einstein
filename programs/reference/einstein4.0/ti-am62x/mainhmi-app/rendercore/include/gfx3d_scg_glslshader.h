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
//  Filename    : gfx3d_scg_glslshader.h
//  Description : Wrapper Class for the gltf PBR shader handling 
//  Created on  : 10-Aug-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_scg_glslshader.h
/// \brief Wrapper Class for the gltf PBR shader handling 
#ifndef gfx3d_scg_glslshader_h
#define gfx3d_scg_glslshader_h

namespace rendercore_engine
{
    class gfx3dTexture2D;
    /// <summary>	
    /// Texture data structure encapsulates the params needed for texture rendering
    /// < / summary>	
    class rc_glslTexture
    {
    protected:
        gfx3dTexture2D* tex2d = nullptr; ///< rendercore_engine::gfx3dTexture2D object to support the unity GetTexture()
    public:
        rc_glslTexture& operator= (const rc_glslTexture& p_object);
        rc_glslTexture(const rc_glslTexture& p_object);
        rc_glslTexture();
        ~rc_glslTexture();
        void SetTexture2D(const gfx3dTexture2D * const p_tex); ///< Extract the texture object and samplers from passed p_tex save internally. Later UpdateTexture2d() will be using the same
        inline gfx3dTexture2D* GetTex2d() const ///< returns the tex2d object 
        {
            return(tex2d);
        }
        GLuint GetTextureObject() const;
        GLenum GetTextureTarget() const;
    };
    /// <summary>	
    /// Attribute data structure encapsulates the params needed for texture rendering
    /// < / summary>	
    class  rc_glslAttributeData
    {
    private:
        std::string name;			    ///<name of the attrib
        GLint location = -1;		    ///< location of the shader in GPU
        bool location_valid = false;    ///< is the location valid?
        GLuint gl_abuffer_id = 0U;		///< GL array buffer 
        GLint size = 0;				    ///< size of the attribute
        GLenum type = static_cast<GLenum>(GL_INVALID_ENUM);	        ///< type of the attribute 
        GLenum shaderType = static_cast<GLenum>(GL_INVALID_ENUM);	///< type of the attribute in shaderType
        GLboolean normalized = static_cast<GLboolean>(GL_FALSE);	///< is attribute normalized
        GLsizei stride = static_cast< GLsizei>(0);			        ///< size of the stride
        const void* pointer = nullptr;	///< pointer to the attribute data
    public:
        bool set_attrib(const std::string& p_attrib, const GLuint p_glarray_buffer, const GLint p_size, const GLenum p_type, const GLboolean p_normalized, const GLsizei p_stride, const void* const p_pointer);
        bool set_attrib(const std::string& p_attrib, const rc_glslAttributeData& p_src);
        bool upload_attribute(const GLuint p_lpo);
        inline void set_location(const GLint p_loc, const GLenum p_type)
        {
            location = p_loc;
            shaderType = p_type;
            location_valid = true;
        }
        inline void set_location_valid(const bool p_val)
        {
            location_valid = p_val;
        }
        inline bool get_location_valid() const
        {
            return(location_valid);
        }
        inline const std::string& get_attrib_name() const
        {
            return(name);
        }
        inline void set_attrib_name(const std::string& p_val)
        {
            name = p_val;
        }
        inline GLint get_location() const
        {
            return (location);
        }
        inline void set_location(const GLint p_val)
        {
            location = p_val;
        }
        inline GLenum get_shader_type() const
        {
            return(shaderType);
        }
        inline GLuint get_glarray_buffer() const///< GL array buffer 
        {
            return(gl_abuffer_id);
        }
        inline GLint get_size() const///< size of the attribute
        {
            return(size);
        }
        inline GLenum get_type() const///< type of the attribute 
        {
            return(type);
        }
        inline GLboolean get_normalized() const///< is attribute normalized
        {
            return(normalized);
        }
        inline GLsizei get_stride() const///< size of the stride
        {
            return(stride);
        }
        inline const void* get_pointer() const///< pointer to the attribute data
        {
            return(pointer);
        }
        /// <summary>
        ///  Exists to support the UT..
        /// </summary>
        bool operator==(const rc_glslAttributeData& p_rhs) const;
    };
    /// <summary>
    /// data structure to store shader uniforms / attributes
    /// </summary>
    class rc_glslUniformValue : public rc_glslTexture
    {
    public:
        // All active uniform variables defined in a program object are initialized to 0
        // when the program object is linked successfully
        // https://registry.khronos.org/OpenGL-Refpages/gl4/html/glUniform.xhtml
        // So keeping default as 0 in our storage to allow upload uniforms only when there
        // is a change in value
        GLfloat vGLfloat = 0.0F;  ///< float32_t value
        glm::mat4 vmat4{ 0.0F };  ///< mat4
        glm::mat3 vmat3{ 0.0F };  ///< mat3
        glm::mat2 vmat2{ 0.0F };  ///< mat2
        glm::vec2 vvec2{ 0.0F };  ///< vec2
        glm::vec3 vvec3{ 0.0F };  ///< vec3
        glm::vec4 vvec4{ 0.0F };  ///< vec4
        GLint vGLint = 0;	      ///< int
        /// default constructor, initalizes internal data
        inline rc_glslUniformValue() : rc_glslTexture()
        {
        }
        virtual inline ~rc_glslUniformValue()
        {
        }
    };
    /// <summary>
    /// Class to hold the attribute/uniform name, its data type and value. multiple constructors are provided
    /// to set the type automatically based on passed value type
    /// </summary>
    class rc_glslUniformData
    {
    private:
        std::string name;			///<name of the attrib
        GLenum shaderType;			///<type read from the shader program
        rdf_glslDataType type;	    ///<type stored by rendercore..
        rc_glslUniformValue value;	///< vec, mat or float32_t values
        GLint location;				///< location of the shader in GPU
        GLint texUnit;              ///< texture unit used if this is a S2D or C2D
        bool location_valid;		///< is the location valid?
        GLint activeTexIndex;       ///< if the current type is S2D or C2D, hold the currently active & loaded texture index
    public:
        bool set_tu(const int32_t p_val);
        inline int32_t get_tu() const
        {
            return(texUnit);
        }
        inline void set_location(const GLint p_loc, const GLenum p_type)
        {
            location = p_loc;
            shaderType = p_type;
            location_valid = true;
        }
        inline void set_location_valid(const bool p_val)
        {
            location_valid = p_val;
        }
        inline bool get_location_valid() const
        {
            return(location_valid);
        }
        inline const std::string& get_attrib_name() const
        {
            return(name);
        }
        inline void set_attrib_name(const std::string& p_val)
        {
            name = p_val;
        }
        inline GLint get_location() const
        {
            return (location);
        }
        inline void set_location(const GLint p_val)
        {
            location = p_val;
        }
        inline rdf_glslDataType get_attrib_type() const
        {
            return(type);
        }
        inline void set_attrib_type(const rdf_glslDataType p_type)
        {
            type = p_type;
        }
        inline GLenum get_shader_type() const
        {
            return(shaderType);
        }
        inline void set_shader_type(const GLenum p_type)
        {
            shaderType = p_type;
        }
        inline const rc_glslUniformValue& get_attrib_value() const
        {
            return(value);
        }
        inline GLuint get_texture_object() const
        {
            return (value.GetTextureObject());
        }
        inline GLenum get_texture_target() const
        {
            return (value.GetTextureTarget());
        }
        inline bool set_float(const float32_t p_val)
        {
            bool fl_sts;
            if(rc_fisEqual(value.vGLfloat, p_val) == false)
            {
                value.vGLfloat = p_val;
                fl_sts = true;
            }
            else
            {
                fl_sts = false;
            }
            return(fl_sts);
        }
        inline float32_t get_float() const
        {
            return(value.vGLfloat);
        }
        inline bool set_int(const int32_t p_val)
        {
            bool fl_sts;
            if (value.vGLint != p_val)
            {
                value.vGLint = p_val;
                fl_sts = true;
            }
            else
            {
                fl_sts = false;
            }
            return(fl_sts);
        }
        inline int32_t get_int() const
        {
            return(value.vGLint);
        }
        inline bool set_vec2(const glm::vec2 p_val)
        {
            bool fl_sts;
            if (value.vvec2 != p_val)
            {
                value.vvec2 = p_val;
                fl_sts = true;
            }
            else
            {
                fl_sts = false;
            }
            return(fl_sts);
        }
        inline glm::vec2 get_vec2() const
        {
            return(value.vvec2);
        }
        inline bool set_vec3(const glm::vec3 p_val)
        {
            bool fl_sts;
            if (value.vvec3 != p_val)
            {
                value.vvec3 = p_val;
                fl_sts = true;
            }
            else
            {
                fl_sts = false;
            }
            return(fl_sts);
        }
        inline glm::vec3 get_vec3() const
        {
            return(value.vvec3);
        }
        inline bool set_vec4(const glm::vec4 p_val)
        {
            bool fl_sts;
            if (value.vvec4 != p_val)
            {
                value.vvec4 = p_val;
                fl_sts = true;
            }
            else
            {
                fl_sts = false;
            }
            return(fl_sts);
        }
        inline glm::vec4 get_vec4() const
        {
            return(value.vvec4);
        }
        inline bool set_mat4(const glm::mat4& p_val)
        {
            bool fl_sts;
            if (value.vmat4 != p_val)
            {
                value.vmat4 = p_val;
                fl_sts = true;
            }
            else
            {
                fl_sts = false;
            }
            return(fl_sts);
        }
        bool set_mat3(const glm::mat3& p_val);
        bool set_mat2(const glm::mat2& p_val);
        inline const glm::mat4& get_mat4() const
        {
            return(value.vmat4);
        }
        inline const glm::mat3& get_mat3() const
        {
            return(value.vmat3);
        }
        inline const glm::mat2& get_mat2() const
        {
            return(value.vmat2);
        }
        bool set_mat4inv(const rc_glslUniformData& p_src);
        bool set_mat2inv(const glm::mat2& p_val);
        bool set_mat3inv(const glm::mat3& p_val);
        bool set_mat4inv(const glm::mat4& p_val);
        inline gfx3dTexture2D* get_texture2d() const
        {
            return(value.GetTex2d());
        }
        // MISRA_TRIAGE:
        // CID : 20324439        
        // Checker : MISRA C++-2008 7-1-2 
        // comments: prototype mismatch
        inline void set_texture2d(gfx3dTexture2D* const p_val)
        {
            value.SetTexture2D(p_val);
        }
        inline bool set_vec2x(const float32_t p_val)
        {
            bool fl_sts;
            if (rc_fisEqual(value.vvec2.x, p_val) == false)
            {
                value.vvec2.x = p_val;
                fl_sts = true;
            }
            else
            {
                fl_sts = false;
            }
            return (fl_sts);
        }
        inline bool set_vec2y(const float32_t p_val)
        {
            bool fl_sts;
            if (rc_fisEqual(value.vvec2.y, p_val) == false)
            {
                value.vvec2.y = p_val;
                fl_sts = true;
            }
            else
            {
                fl_sts = false;
            }
            return (fl_sts);
        }
        inline bool set_vec3x(const float32_t p_val)
        {
            bool fl_sts;
            if (rc_fisEqual(value.vvec3.x, p_val) == false)
            {
                value.vvec3.x = p_val;
                fl_sts = true;
            }
            else
            {
                fl_sts = false;
            }
            return (fl_sts);
        }
        inline bool set_vec3y(const float32_t p_val)
        {
            bool fl_sts;
            if (rc_fisEqual(value.vvec3.y, p_val) == false)
            {
                value.vvec3.y = p_val;
                fl_sts = true;
            }
            else
            {
                fl_sts = false;
            }
            return (fl_sts);
        }
        inline bool set_vec3z(const float32_t p_val)
        {
            bool fl_sts;
            if (rc_fisEqual(value.vvec3.z, p_val) == false)
            {
                value.vvec3.z = p_val;
                fl_sts = true;
            }
            else
            {
                fl_sts = false;
            }
            return (fl_sts);
        }
        inline bool set_vec4x(const float32_t p_val)
        {
            bool fl_sts;
            if (rc_fisEqual(value.vvec4.x, p_val) == false)
            {
                value.vvec4.x = p_val;
                fl_sts = true;
            }
            else
            {
                fl_sts = false;
            }
            return (fl_sts);
        }
        inline bool set_vec4y(const float32_t p_val)
        {
            bool fl_sts;
            if (rc_fisEqual(value.vvec4.y, p_val) == false)
            {
                value.vvec4.y = p_val;
                fl_sts = true;
            }
            else
            {
                fl_sts = false;
            }
            return (fl_sts);
        }
        inline bool set_vec4z(const float32_t p_val)
        {
            bool fl_sts;
            if (rc_fisEqual(value.vvec4.z, p_val) == false)
            {
                value.vvec4.z = p_val;
                fl_sts = true;
            }
            else
            {
                fl_sts = false;
            }
            return (fl_sts);
        }
        inline bool set_vec4w(const float32_t p_val)
        {
            bool fl_sts;
            if (rc_fisEqual(value.vvec4.w, p_val) == false)
            {
                value.vvec4.w = p_val;
                fl_sts = true;
            }
            else
            {
                fl_sts = false;
            }
            return (fl_sts);
        }
        GLint update_location(const GLuint p_lpo);
        void upload_uniform(const GLint p_loc);
        /// constructor for mat4 data
        rc_glslUniformData(const std::string pattribName, const glm::mat4 pvmat, const GLint plocation = -1, const bool plocation_valid = false);
        /// constructor for mat3 data
        rc_glslUniformData(const std::string pattribName, const glm::mat3 pvmat, const GLint plocation = -1, const bool plocation_valid = false);
        /// constructor for mat2 data
        rc_glslUniformData(const std::string pattribName, const glm::mat2 pvmat, const GLint plocation = -1, const bool plocation_valid = false);
        /// constructor for vec2 data
        rc_glslUniformData(const std::string pattribName, const glm::vec2 pvec, const GLint plocation = -1, const bool plocation_valid = false);
        /// constructor for vec3 data
        rc_glslUniformData(const std::string pattribName, const glm::vec3 pvec, const GLint plocation = -1, const bool plocation_valid = false);
        /// constructor for vec4 data
        rc_glslUniformData(const std::string pattribName, const glm::vec4 pvec, const GLint plocation = -1, const bool plocation_valid = false);
        /// constructor for float32_t data
        rc_glslUniformData(const std::string pattribName, const GLfloat pfloat, const GLint plocation = -1, const bool plocation_valid = false);
        /// constructor for integer data
        rc_glslUniformData(const std::string pattribName, const GLint pint, const GLint plocation = -1, const bool plocation_valid = false);
        /// constructor for  int data
        rc_glslUniformData(const std::string pattribName, const GLint pint, const rdf_glslDataType ptype, const GLint plocation = -1, const bool plocation_valid = false);
        /// <summary>
        /// Sets the active texture index
        /// </summary>
        /// <param name="p_disp">parent display of this material data</param>
        /// <param name="p_sceneid">Currently active Scene id</param>
        /// <param name="p_index">index of the active texture</param>
        /// <param name="p_sync">true - load synchronously, false - loads in background</param>
        void SetActiveTexIndex(const gfx3d_scg_display* const p_disp, const size_t p_sceneid, const GLint p_index, const bool p_sync);
    };
    using rc_uniform_map = std::map<std::string, rc_glslUniformData>;
    using rc_attribute_map = std::map<std::string, rc_glslAttributeData>;
    /// \ingroup Engine
    /// @{
	///<summary>
	/// Data structure to keep a track of a shader object usage count
    /// and use it for unloading when nobody uses it
	///</summary>
	class rc_glslObj
    {
    private:
        size_t count = 0U;  ///< number of materials using the shader program object
        GLuint sid = 0U;    ///< shader program object
    protected:
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
        std::recursive_mutex data_mutex; ///< mutex to protect all data access by threads
#endif
        inline rc_glslObj& operator=(const rc_glslObj& p_rhs)
        {
            if (&p_rhs != this)
            {
                count = p_rhs.count;
                sid = p_rhs.sid;
            }
            return(*this);
        }
        inline rc_glslObj& operator=(const rc_glslObj&& p_rhs)
        {
            if (&p_rhs != this)
            {
                count = p_rhs.count;
                sid = p_rhs.sid;
            }
            return(*this);
        }
        static GLuint compile_glslshader(const std::string& p_matname, const GLenum p_type, const GLchar* const* const p_source, const GLint p_length);
    public:
        inline bool UnLoad(void)
        {
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
            const std::unique_lock<std::recursive_mutex> fl_lock(data_mutex);
#endif
            if (count > 0U)
            {
                count--;
            }
            return(count == 0U);
        }
        inline void set_shdrobj_id(const GLuint p_sid)
        {
            sid = p_sid;
        }
        inline GLuint get_shdrobj_id() const
        {
            return(sid);
        }
        inline rc_glslObj(const rc_glslObj& p_src)
        {
            *this = p_src;
        }
        inline rc_glslObj(const rc_glslObj&& p_src)
        {
            *this = p_src;
        }
        inline rc_glslObj()
        {
        }
        inline virtual ~rc_glslObj()
        {
        }
        inline void Load()
        {
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
            const std::unique_lock<std::recursive_mutex> fl_lock(data_mutex);
#endif
            count++;
        }
    };
    enum class rc_glslShaderType
    {
        Vertex,
        Fragment,
        Total
    };
    class rc_glslShaderObj : public rc_glslObj
    {
    private:
        inline rc_glslShaderObj& operator=(const rc_glslShaderObj& p_rhs)
        {
            if (this != &p_rhs)
            {
                rc_glslObj::operator=(p_rhs);
            }
            return(*this);
        }
    public:
        bool unload_vertshader(bool p_force);
        inline rc_glslShaderObj& operator=(const rc_glslShaderObj&& p_rhs)
        {
            if (this != &p_rhs)
            {
                rc_glslObj::operator=(std::move(p_rhs));
            }
            return(*this);
        }
        inline rc_glslShaderObj(const rc_glslShaderObj& p_src) : rc_glslObj(p_src)
        {
            *this = p_src;
        }
        inline rc_glslShaderObj() : rc_glslObj()
        {
        }
        virtual inline ~rc_glslShaderObj()
        {
        }
        GLuint CompileShader(const std::string& p_matname, const GLenum p_type, const GLchar* const* const p_source, const GLint p_length);
        GLuint GetGLObjID();
    };
    struct rc_glslUniform
    {
        std::string name;               ///<Uniform Name
        GLenum shaderType;				///<type read from the shader program
        GLint location;					///< location of the shader in GPU
    };
    class rc_glslAttribute
    {
    public:
        GLenum shaderType;				///<type read from the shader program
        GLint location;					///< location of the shader in GPU
        inline rc_glslAttribute(const GLenum p_shaderType, const GLint p_location)
        {
            shaderType = p_shaderType;
            location = p_location;
        }
    };
    using rc_attr_loc_map = std::map<std::string, rc_glslAttribute>;
    class rc_glslProgramObj : public rc_glslObj
    {
    private:
        rc_uniform_map glslUniforms;
        rc_attr_loc_map glslAttributes;
        void read_uniforms_info(const std::string& p_matname);
        void read_attributes_info(const std::string& p_matname);
        inline rc_glslProgramObj& operator=(const rc_glslProgramObj& p_rhs)
        {
            if (&p_rhs != this)
            {
                rc_glslObj::operator=(p_rhs);
                glslUniforms = p_rhs.glslUniforms;
                glslAttributes = p_rhs.glslAttributes;
            }
            return(*this);
        }
    public:
        inline rc_glslProgramObj& operator=(const rc_glslProgramObj&& p_rhs)
        {
            if (&p_rhs != this)
            {
                rc_glslObj::operator=(std::move(p_rhs));
                glslUniforms = p_rhs.glslUniforms;
                glslAttributes = p_rhs.glslAttributes;
            }
            return(*this);
        }
        inline rc_glslProgramObj(const rc_glslProgramObj& p_src) : rc_glslObj(p_src)
        {
            *this = p_src;
        }
        inline rc_glslProgramObj(const rc_glslProgramObj&& p_src) : rc_glslObj(p_src)
        {
            *this = p_src;
        }
        inline rc_glslProgramObj() : rc_glslObj()
        {
        }
        virtual inline ~rc_glslProgramObj()
        {
        }
        GLuint CreateBinaryShader(const std::string& p_matname, const CHAR8* const p_buffer, size_t p_size, const uint32_t p_shaderBinaryFormat);
        GLuint LinkShader(const std::string& p_matname, rc_glslShaderObj& p_VertShader, rc_glslShaderObj& p_FragShader);
        const rc_uniform_map& GetUniformData();
        const rc_attr_loc_map& GetAttributeData();
        GLuint GetGLObjID();
        bool upload_uniform(rc_glslUniformData& p_ufmData);
    };
    /// @}
}

#endif//gfx3d_scg_material_h