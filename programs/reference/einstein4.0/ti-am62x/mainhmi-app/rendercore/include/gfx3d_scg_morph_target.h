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
//  Filename    : gfx3d_scg_morph_target.h
//  Description : GFX3D scene graph morph target object.
//  Created on  : 30-Apr-2021 by ssharm20@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_scg_morph_target.h
/// \brief GFX3D scene morph target object.
#ifndef gfx3d_scg_morph_target_h
#define gfx3d_scg_morph_target_h

#include "rc_render_states.h"
#include "gfx3d_scg_material.h"

namespace rendercore_engine
{
    /// <summary>
    /// How morphing is realized. 
    /// Note : Depending on the shader support, the selection is made autoomatically
    /// </summary>
    enum class rc_morphImpn
    {
        /// morph calculations are done in CPU and final vertex buffer is uploaded to GPU
        /// This needs no special handling in the vertex shader
        /// With too many targets and large models, the cpu load will be heavy
        mtiCpu
#if (GLES3_RENDERER >= 30)
        /// when the number of morph targets are limited, we can go or this which offers the least cpu load
        /// morph target vertex buffers are uploaded to GPU as attributes. weight is uploaded as a single dimentional texture
        /// In the vertex shader
        /// <code>
        /// uniform float u_NumWeights;     // Number of weights / texture width
        /// in vec3 a_Position0;
        /// in vec3 a_Position1;
        /// ....
        /// in vec3 a_PositionN;
        /// repeat same for Normals and Tangents
        /// 
        /// To find resultant vertex data
        /// vec3 posin = a_Position;
        /// for (int i = 0; i < int(u_NumWeights); i++)
        /// {
        ///     float tx = float(i);
        ///     tx = (tx + 0.5) / u_NumWeights;
        ///     float bsweight = texture(u_BSWeights, vec2(tx, 0.5)).r;
        ///     if (bsweight > 0.0)
        ///     {
        ///         posin = posin + ((a_Position0 * bsweight) / 100.0F);
        ///         posin = posin + ((a_Position1 * bsweight) / 100.0F);
        ///         ....
        ///         posin = posin + ((a_PositionN * bsweight) / 100.0F);
        ///     }
        /// }
        /// </code>
        /// posin now contains the morph processed position. Similar logic to be extended for other attributes
        ,mtiGpuAttr
        /// In comparison with above, this one creates a target texture at load time with CPU so your loading time 
        /// may have an impact. But run time cpu lod is largly reduced in comparison with mtiCpu
        /// morph target vertex buffers are uploaded to GPU as texture. weight is uploaded as a single dimentional texture
        /// In the vertex shader
        /// <code>
        /// uniform float u_NumWeights;     // Number of weights / texture width
        /// uniform float u_NumVertices;    // Number of vertives or the texture height for a_<attribute>BS
        /// uniform sampler2D a_PositionBS; // position attributes
        /// uniform sampler2D aNormalBS;    // normal attributes
        /// uniform sampler2D a_TangentBS;  // tangent attributes
        /// uniform sampler2D u_BSWeights;  // weights
        /// To find resultant vertex data
        /// vec3 posin = a_Position;
        /// float ty = float(gl_VertexID);
        /// ty = (ty + 0.5) / u_NumVertices;
        /// for (int i = 0; i < int(u_NumWeights); i++)
        /// {
        ///     float tx = float(i);
        ///     tx = (tx + 0.5) / u_NumWeights;
        ///     float bsweight = texture(u_BSWeights, vec2(tx, 0.5)).r;
        ///     if (bsweight > 0.0)
        ///     {
        ///         vec4 bsattr = texture(a_PositionBS, vec2(tx, ty));
        ///         posin = posin + ((bsattr.rgb * bsweight) / 100.0F);
        ///     }
        /// }
        /// </code>
        /// posin now contains the morph processed position. Similar logic to be extended for other attributes
        ,mtiGpuTex
#endif
    };
    /// \ingroup Engine
    /// @{
    /// <summary>
    /// A Morph Target is a morphable Mesh where primitives' attributes are obtained by adding the original 
    /// attributes to a weighted sum of targets attributes.
    /// https://github.com/KhronosGroup/glTF/tree/master/specification/2.0#morph-targets
    /// </summary>

    /// <summary>
    /// Holds a single attributes and its targets
    /// e.g. "a_Position" atribute :- basedata, {target1, target2, ...}
    /// </summary>
    class rc_primMorphAttrib
    {
    private:
        GLuint  glMorphBuffer = 0U;         ///< GL buffer handle for the attribute
        int32_t baseAccIndex = -1;          ///< Base attributedata accessor index
        CHAR8* outbuffer = nullptr;         ///< Storage to keep this attribute's processed vertex data
        std::vector<int32_t> mtargAccIndex; ///< Morph target accessor index attributedata
#if (GLES3_RENDERER >= 30)
        gfx3dTexture2D* tex = nullptr;      ///< MT attributes are uploaded via this texture
#endif
    protected:
        /// <summary>
        /// Returns the base accessor data for attribute represented by this object
        /// gltf "primitives" -> "attributes" -> "POSITION" for example 
        /// </summary>
        /// <param name="p_disp">parent display object</param>
        /// <param name="p_data">location to store the accessor data</param>
        /// <returns>true on success</returns>
        bool get_basedata(const gfx3d_scg_display* const p_disp, gfx3d_scg_accessor_data& p_data) const;
        /// <summary>
        /// Returns the target accessor data for attribute represented by this object
        /// gltf "primitives" -> "targets[p_index]" -> "POSITION" for example 
        /// </summary>
        /// <param name="p_disp">parent display object</param>
        /// <param name="p_index">index of the target (state ID)</param>
        /// <param name="p_data">location to store the accessor data</param>
        /// <returns>true on success</returns>
        bool get_tgetdata(const gfx3d_scg_display* const p_disp, const size_t p_index, gfx3d_scg_accessor_data& p_data) const;
        /// <summary>
        /// Loads the accessors needed by this attribute object for cpu based morphing
        /// </summary>
        /// <param name="p_disp">parent display object</param>
        /// <param name="p_scene">parent scene index</param>
        void load_attrib_cpu(const gfx3d_scg_display* const p_disp, const size_t p_scene);
        /// <summary>
        /// Loads the accessors needed by this attribute object for shader based morphing
        /// </summary>
        /// <param name="p_disp">parent display object</param>
        /// <param name="p_scene">parent scene index</param>
        void load_attrib_gpu(const gfx3d_scg_display* const p_disp, const size_t p_scene, gfx3d_scg_material* const p_material, const std::string& p_attribname, const rc_morphImpn p_imp);
        /// <summary>
        /// Unloads the accessors needed by this attribute object
        /// </summary>
        /// <param name="p_attrib"></param>
        /// <returns></returns>
        void unload_attrib(const gfx3d_scg_display* const p_disp, const size_t p_scene);
        /// <summary>
        /// Sets the total number of targets. Resizes the storage to accept set_morph_targetaccr
        /// </summary>
        /// <param name="p_numTargets">number of morph targets</param>
        void set_attrib_num_targets(const size_t p_numTargets);
        /// <summary>
        /// Store the accessor index for base attribute
        /// </summary>
        /// <param name="p_baseAccIndex">index to accessor</param>
        void set_attrib_base_accr(const int32_t p_baseAccIndex);
        /// <summary>
        /// Store the accessor index for the specified morph target attribute
        /// </summary>
        /// <param name="p_index">morph target index or state ID</param>
        /// <param name="p_accIndex">index to accessor</param>
        void set_attrib_mtarget_accr(const size_t p_index, const int32_t p_accIndex);
        /// <summary>
        /// Calculate the morphed attribute data and upload them to gl buffer object and material
        /// </summary>
        /// <param name="p_attrib">name of the attribute which this object holds</param>
        /// <param name="p_disp">parent display object</param>
        /// <param name="p_material">material to which processed data to be uploaded</param>
        /// <param name="p_weights">list of weights per morph target (to be of same size as previously set via set_num_targets())</param>
        void process_attrib_cpu(const std::string& p_attrib, const gfx3d_scg_display* const p_disp, gfx3d_scg_material* const p_material, std::vector<float32_t>& p_weights);
        /// <summary>
        /// upload MT attributes to material
        /// </summary>
        /// <param name="p_attrib">name of the attribute which this object holds</param>
        /// <param name="p_disp">parent display object</param>
        /// <param name="p_material">material to which processed data to be uploaded</param>
        /// <param name="p_weights">list of weights per morph target (to be of same size as previously set via set_num_targets())</param>
        void process_attrib_gpu(const std::string& p_attrib, const gfx3d_scg_display* const p_disp, gfx3d_scg_material* const p_material, std::vector<float32_t>& p_weights, const rc_morphImpn p_imp);
        friend class rc_primMorphTargets;
    public:
        /// <summary>
        /// Constructs an attribute of morph target
        /// </summary>
        rc_primMorphAttrib(gfx3d_scg_display* const p_display);
        rc_primMorphAttrib& operator= (const rc_primMorphAttrib& p_src);
        //copy construct
        rc_primMorphAttrib(const rc_primMorphAttrib& p_obj);
        /// <summary>
        /// Destructor  
        /// </summary>
        virtual ~rc_primMorphAttrib(void);
    };
    /// <summary>
    /// Holds complete morph target list for all attributes
    /// </summary>
    class rc_primMorphTargets
    {
    private:
        std::map<std::string, size_t>  stateToTargetMap; ///< morph state name to target list index mapping.
        std::vector<float32_t> weights;                  ///< weight for each target / state    
        bool bChanged;                                   ///< true means the weight is changed and a recalculation is needed
        rc_morphImpn morphProcImp;                       ///< use the cpu or gpu for MT
        rc_primMorphTargets& operator= (const rc_primMorphTargets& p_src);
        std::map<std::string, rc_primMorphAttrib> mtAttrDataMap;  ///< attribute to morph data mapping
        gfx3d_scg_display* display = nullptr;            ///< parent display
#if (GLES3_RENDERER >= 30)
        gfx3dTexture2D * tex = nullptr;                  ///< MT attributes are uploaded via this texture
#endif
    public:
        /// <summary>
        /// constructs moprh target object
        /// </summary>
        rc_primMorphTargets(gfx3d_scg_display * const p_display);
        /// Copy construct
        rc_primMorphTargets(const rc_primMorphTargets& p_obj);
        /// <summary>
        /// Destructor
        /// </summary>
        virtual ~rc_primMorphTargets();
        /// <summary>
        /// Sets the total number of targets available. USed to resize internal storages
        /// </summary>
        /// <param name="p_numTargets">number of targets</param>
        void SetNumTargets(const size_t p_numTargets);
        /// <summary>
        /// Set the morph target state name for each target
        /// </summary>
        /// <param name="p_index">target index or state ID</param>
        /// <param name="p_stateName">name of state</param>
        void SetStateName(const size_t p_index, const std::string& p_stateName);
        /// <summary>
        /// Store the accessor index for base attribute
        /// </summary>
        /// <param name="p_attribName">name of attribute (a_Position ..."")</param>
        /// <param name="p_baseAccIndex">index to accessor</param>
        void SetBaseAccr(const std::string& p_attribName, const int32_t p_baseAccIndex);
        /// <summary>
        /// Store the accessor index for morph target attribute
        /// </summary>
        /// <param name="p_index">morph target index or the state ID</param>
        /// <param name="p_attribName">name of attribute (a_Position ..."")</param>
        /// <param name="p_baseAccIndex">index to accessor</param>
        void SetMorphTargetAccrs(const size_t p_index, const std::string& p_attribName, const int32_t p_mtAccIndex);
        /// <summary>
        /// Sets the weight for the morph target
        /// </summary>
        /// <param name="p_index">morph target index or the state ID</param>
        /// <param name="p_weight">weight % in 0.0 to 100.0 range</param>
        /// <returns>true on success</returns>
        bool SetWeight(const size_t p_index, const float32_t p_weight);
        /// <summary>
        /// Gets the stateID corresponding to the passed state name
        /// </summary>
        /// <param name="p_state">name of morph target state</param>
        /// <returns>index or the state ID</returns>
        int32_t GetStateID(const std::string& p_state) const;
        /// <summary>
        /// Gets the state name corresponding to the passed state ID or index
        /// </summary>
        /// <param name="p_state">morph target state ID or index</param>
        /// <returns>state name</returns>
        std::string GetStateName(const int32_t p_state) const;
        /// <summary>
        /// Returns the currently stored weight fr specified morph target state ID
        /// </summary>
        /// <param name="p_index">morph target state ID</param>
        /// <returns>currently stored weight (0 - 100%)</returns>
        float32_t GetWeight(const size_t p_index) const;
        /// <summary>
        /// Returns the total number of morph targets
        /// </summary>
        /// <returns>total number of morph targets</returns>
        size_t GetNumTargets() const;
        /// <summary>
        /// Loads all accessors needed by morph target. Create the gl buffer object
        /// </summary>
        /// <param name="p_disp">parent display</param>
        /// <param name="p_scene">parent scene</param>
        void Load(gfx3d_scg_display* const p_disp, const size_t p_scene, gfx3d_scg_material* const p_material);
        /// <summary>
        /// UnLoads all accessors needed by morph target and deletes gl buffer object
        /// </summary>
        /// <param name="p_disp">parent display</param>
        /// <param name="p_scene">parent scene</param>
        void UnLoad(gfx3d_scg_display* const p_disp, const size_t p_scene);
        /// <summary>
        /// Periodic process API to perform morphing. Performed when ever there is a change in weight value
        /// </summary>
        /// <param name="p_disp">parent display</param>
        /// <param name="p_material">material to which the changed value to be applied</param>
        void Process(gfx3d_scg_display* const p_disp, gfx3d_scg_material* const p_material);
        /// <summary>
        /// Returns true if the weights are changed and a recalculation is needed
        /// </summary>
        /// <returns>true or false</returns>
        bool IsChanged() const;
    };
    /// @}
}

#endif
