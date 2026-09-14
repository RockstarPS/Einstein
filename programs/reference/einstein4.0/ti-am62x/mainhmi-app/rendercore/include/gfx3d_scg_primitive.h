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
//  Filename    : gfx3d_scg_primitive.h
//  Description : GFX3D scene graph primitive object.
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_scg_primitive.h
/// \brief GFX3D scene graph primitive object.
#ifndef gfx3d_scg_primitive_h
#define gfx3d_scg_primitive_h

#include "rc_render_states.h"
#include "gfx3d_scg_material.h"

namespace rendercore_engine
{
    /// \ingroup Engine
    /// @{
    /// <summary>
    /// Primitive represents a drawable element / geometry
    /// https://github.com/KhronosGroup/glTF/tree/master/specification/2.0#meshes
    /// </summary>
    class gfx3d_scg_primitive
    {
    private:
        GLuint poid = 0U;                       ///< material program object id to detect changed material.
        rc_uniform_map::iterator URefEnd;      ///< indicates end of uniform list in material. Used to check validity
        rc_uniform_map::iterator MMatrixURef;  ///< Reference to model matrix uniform in material
        rc_uniform_map::iterator MVPMatrixURef;///< Reference to model-view-proj matrix uniform in material
        rc_uniform_map::iterator NMatrixURef;  ///< Reference to normal matrix uniform in material
        rc_uniform_map::iterator MMatrixIURef; ///< Reference to model matrix inverse uniform in material
        rc_uniform_map::iterator OpacityURef;  ///< Reference to node opacity uniform in material
        rc_uniform_map::iterator CameraURef;   ///< Reference to camera position uniform in material
        rc_uniform_map::iterator VMatrixIURef; ///< Reference to view matrix inverse uniform in material
        rc_uniform_map::iterator NVMatrixIURef; ///< Reference to (view matrix inverse * Normal matrix) uniform in material
        rc_uniform_map::iterator TimeURef;     ///< Reference to time uniform in material
        rc_uniform_map::iterator MVMatrixURef; ///< Reference to model-view matrix uniform in material
        rc_uniform_map::iterator VMatrixURef;  ///< Reference to view matrix uniform in material
        rc_uniform_map::iterator PMatrixURef;  ///< Reference to projection matrix uniform in material
        /// indicates for which scenes loaded this object. 
        /// Used to decide how many are using it & unload only when no one uses
        rc_flag sceneLoadedMask;
        bool bflipWindingOrder = false;		///< flip the winding order of the mesh
        bool proceduralMesh = false;        ///< true indicates mesh data is loaded by the script and therefore statc loading is disabled
        gfx3d_scg_material* material = nullptr;///< material for the primitive
        void update_uniform_ref(void);
        gfx3d_scg_primitive& operator= (const gfx3d_scg_primitive& p_src);
    protected:
        gfx3d_scg_display* display = nullptr;			///< owner display object			
        gfx3d_scg_mesh* parent = nullptr;   ///< parent mesh object
        rc_rs_data rsData;                  ///< render state data for the primitive
        int32_t indices_accessor_idx = -1;		///< if the primitive uses an indxed buffer, then index to the accessor which can provide the data
        int32_t position_accessor_idx = -1;		///< position data accessor index. Used by bounding box calculation
        bool indexbuffer = false;			///< its a index buffer for the primitive (true) else a array buffer (false)
        bool vertexdataValid = false;		///< stores a valid vertex data?
        bool bLoaded = false;              ///< if true indicates that the buffer is loaded
        /// <summary>
        /// Holds index buffer informaton
        /// </summary>
        struct
        {
            GLuint glbuff_id = 0U;          ///< gl buffer id
            GLenum mode = 0U;               ///< gl mode in glDrawElements
            GLsizei count = 0;              ///< gl count in glDrawElements
            GLenum type = 0U;               ///< gl type in glDrawElements
            const void* offset = nullptr;   ///< when multiple index buffers are combined to a single gl buffer, an offset is needed to specify the start of index buffer
        }vindex;
        /// stores mode and count for the primitive
        struct
        {
            GLenum mode = 0U;        ///< gl mode in glDrawArrays
            GLsizei count = 0;      ///< gl count in glDrawArrays
        }varray;
        /// maps the attributes name and accessor index to the attribute data
        std::map<std::string, GLint> attributesMap;
        rc_primMorphTargets* morphing = nullptr;
    public:
        /// <summary>
        /// returns the material object
        /// </summary>
        gfx3d_scg_material* GetMaterial(void) const;
        /// <summary>
        /// Sets a new material to primitive. Returns true if new material is set.
        /// Its the responsibility of caller to free/delete
        /// the currently set material after SetMaterial call returns true.
        /// e.g.
        /// curmat = GetMaterial();
        /// if(SetMaterial(newmaterial))
        /// {
        ///    if(curmat != nullptr)
        ///    {
        ///       delete curmat;
        ///    }
        /// }
        /// TODO : need to handle releasing of material and allow setting nullptr
        /// </summary>
        bool SetMaterial(gfx3d_scg_material* const p_material);
        /// <summary>
        /// Construct a primitive object
        /// </summary>
        gfx3d_scg_primitive(gfx3d_scg_display* const p_dsp);
        /// Copy construct
        gfx3d_scg_primitive(const gfx3d_scg_primitive& p_obj);
        /// <summary>
        /// Copies all vertex attribute data from this object to the p_dest gfx3d_scg_primitive
        /// </summary>
        /// <param name="p_dest">destination gfx3d_scg_primitive</param>
        void CopyVertexAttributes(gfx3d_scg_primitive * const p_dest) const;
        /// Distructor
        virtual ~gfx3d_scg_primitive();
        /// <summary>
        /// renders the primitive
        /// \see rendercore_engine::gfx3d_scg_node::render()
        /// </summary>
        virtual void render(gfx3d_scg_node* const p_node);
        /// <summary>
        /// called before render
        /// \see rendercore_engine::gfx3d_scg_node::pre_render()
        /// </summary>
        virtual void pre_render();
        /// <summary>
        /// called before render
        /// \see rendercore_engine::gfx3d_scg_node::prepare_rlist()
        /// </summary>
        void prepare_rlist(gfx3d_scg_node* const p_node);
        /// <summary>
        /// loads the primitive by creating dynamic contents (materials & vertex data)
        /// </summary>
        /// <param name="p_scene">id of the scene which is requesting this node load</param>
        /// <param name="p_visible">visibility of parent node, may affect resource loading depending on p_mode</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        bool Load(const size_t p_scene, const bool p_visible = true);
        /// <summary>
        /// Unloads this node by deleting dynamic contents.. if none of the scene uses this node anymore
        /// </summary>
        /// <param name="p_scene">id of the scene which is requesting this node unload</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        bool UnLoad(const size_t p_scene);
        /// <summary>
        /// Get Data 
        /// </summary>
        /// <param name="p_accessor_idx"> accessor index</param>
        /// <param name="p_adata"> pointer to accessor data</param>
        /// <returns>true if data has been loaded in p_adata param</returns>
        bool GetData(const GLint p_accessor_idx, gfx3d_scg_accessor_data* const p_adata) const;
        /// <summary>
        /// Set cull mode
        /// </summary>
        /// <param name="p_cullMode"> cull mode of type mdl_cullMode</param>
        void SetCullMode(const mdl_cullMode p_cullMode);
        /// <summary>
        /// Set blend mode
        /// </summary>
        /// <param name="p_blendMode"> blend mode of type MdlBlendMode </param>
        /// <param name="p_aBlendMode"> optional alpha channel blend control </param>
        /// <param name="p_blendMode"> optional blend equation control </param>
        void SetBlendMode(const MdlBlendMode p_blendMode, const MdlAlphaBlendMode p_aBlendMode = MdlAlphaBlendMode::abmBlendUseDst, const MdlBlendEquation p_blendEquation = MdlBlendEquation::beAdd);
        /// <summary>
        /// Set depth test
        /// </summary>
        /// <param name="p_depthTest"> depth test </param>
        void SetDepthTest(const mdl_depthTest p_depthTest);
        /// <summary>
        /// Set depthwrite
        /// </summary>
        /// <param name="p_depthWrite"> depthwrite true or false </param>
        void SetDepthWrite(const mdl_depthWrite p_depthWrite);
        /// <summary>
        /// function to get position accessor index
        /// </summary>
        /// <returns>returns position accessor index </returns>     
        int32_t GetPositionAccessorIndex() const;
        /// <summary>
        /// function to get whether index is in buffer
        /// </summary>
        /// <returns>returns true if primitive uses an index buffer </returns>
        bool IsIndexbuffer() const;
        /// <summary>
        /// function to get wether vertex data is valid or not
        /// </summary>
        /// <returns>returns true if vertex data is valid </returns>
        bool IsVertexdataValid() const;
        /// <summary>
        /// function to Set wether vertex data is valid or not
        /// </summary>
        void SetVertexdataValid(const bool p_valid);
        /// <summary>
        /// Sets the application created index buffer information to primitive class
        /// </summary>
        /// <param name="glbuff_id">buffer ID</param>
        /// <param name="mode">Specifies what kind of primitives to render</param>
        /// <param name="count">Specifies the number of elements to be rendered</param>
        /// <param name="type">Specifies the type of the values in indices</param>
        void SetIndexBuffer(const GLuint p_glbuff_id, const GLenum p_mode, const GLsizei p_count, const GLenum p_type, const void* const p_offset = nullptr);
        /// <summary>
        /// Sets the application created array buffer information to primitive class
        /// </summary>
        /// <param name="mode">Specifies what kind of primitives to render</param>
        /// <param name="count">Specifies the number of indices to be rendered</param>
        void SetArrayBuffer(const GLenum p_mode, const GLsizei p_count);
        /// <summary>
        /// Returns the render state for this primitive.
        /// </summary>
        /// <returns>returns render state </returns>
        const rc_rs_data& GetRenderState(void) const;
        /// <summary>
        /// Request to flip the winding order of the mesh or not
        /// </summary>
        /// <param name="p_wo">true or false</param>
        void FlipWindingOrder(const bool p_flip);
        /// <summary>
        /// Specify the mesh as a procedural/dynamic mesh (true) or not (false)
        /// </summary>
        /// <param name="p_state">true or false</param>
        void SetProceduralMesh(const bool p_state);
        inline int32_t GetIndicesAccessorIdx() const
        {
            return(indices_accessor_idx);
        }
        inline int32_t GetPositionAccessorIdx() const
        {
            return(position_accessor_idx);
        }
        inline void set_indices_accessor_idx(const int32_t p_val)
        {
            indices_accessor_idx = p_val;
        }
        inline void set_position_accessor_idx(const int32_t p_val)
        {
            position_accessor_idx = p_val;
        }
        /// <summary>
        /// Get pointer to parent display
        /// </summary>
        /// <returns>returns pointer to parent display </returns>
        gfx3d_scg_display* GetDisplay() const;
        /// <summary>
        /// Sets the parent display of this camera
        /// <param name="p_parent">pointer to display</param>
        /// </summary>
        void SetDisplay(gfx3d_scg_display* const p_val);
        /// <summary>
        /// Returns the parent primitive of the material
        /// </summary>
        gfx3d_scg_mesh* GetParent() const;
        /// <summary>
        /// Sets the parent primitive of this material
        /// <param name="p_parent">pointer to display</param>
        /// </summary>
        void SetParent(gfx3d_scg_mesh* const p_val);
#if !defined(RC_ONLY_RDF)
        /// <summary>
        /// Exists to support multiple gltf loading. Donot invoke this from application
        /// </summary>
        /// <param name="p_accsize">shifts index of attribute accessor by p_accsize</param>
        void merge_primitive(const size_t p_accsize);
#endif
        /// <summary>
        /// Set base accessor of the given attribute
        /// </summary>
        /// <param name="p_attribName"></param>
        /// <param name="p_baseAccIndex"></param>
        void SetBaseAccr(const std::string& p_attribName, const int32_t p_baseAccIndex);
        /// <summary>
        /// Sets the morph object
        /// </summary>
        /// <param name="p_morph"> morph object</param>
        void SetMorphing(rc_primMorphTargets* const p_morph);
        /// <summary>
        /// Returns the morph object
        /// </summary>
        /// <returns>morph object</returns>
        rc_primMorphTargets* GetMorphing() const;
        /// <summary>
        /// Sets the scene as dirty / has property changes
        /// </summary>
        void SetDirty();
    };
    /// @}
}

#endif
