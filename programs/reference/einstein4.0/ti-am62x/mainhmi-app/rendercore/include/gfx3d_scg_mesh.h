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
//  Filename    : gfx3d_scg_mesh.h
//  Description : GFX3D scene graph mesh object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_scg_mesh.h
/// \brief GFX3D scene graph mesh object
#ifndef gfx3d_scg_mesh_h
#define gfx3d_scg_mesh_h

namespace rendercore_engine
{
    /// \ingroup Engine
    /// @{
    /// <summary>
	/// A collection of 3d elements (primitives)
	/// </summary>
	class gfx3d_scg_mesh
	{
    protected:
        gfx3d_scg_display  * display = nullptr;			///< display object
    private:
        gfx3dTransform* parent = nullptr;               ///< Parent node object
        /// Bounding box min value
        glm::vec4 boundingBoxMin{ FLT_MAX, FLT_MAX, FLT_MAX, 1.0F };
        /// Bounding box max value
        glm::vec4 boundingBoxMax{ -FLT_MAX, -FLT_MAX, -FLT_MAX, 1.0F };
        std::vector <gfx3d_scg_primitive *> primitives; ///< list of primitives that are part of this mesh
        rc_flag sceneLoadedMask;                        ///< indicates for which scenes loaded this object. Used to decide how many are using
        // parentBbox kept here due to 8.x.x script dependancy. ideally this could have be in node
        gfx3dMeshBBox parentBbox;                       ///< holds the bounding box of the parent node
        bool isBoundingBoxCalulated = false;            ///< indicates that bounding box for this mesh is calculated or not.
        bool bLoaded = false;                           ///< if true indicates that the buffer is loaded
        bool visible = true;                            ///< this mesh is rendered only when 'true'
        gfx3d_scg_mesh& operator= (const gfx3d_scg_mesh& p_object);
        mutable gfx3dMesh* dynamicMesh = nullptr;
    public:
        const gfx3dMeshBBox& GetBBox();
        /// Return the minimum bounding box
        const glm::vec4& GetBBoxMin() const;
        /// Return the maximum bounding box
        const glm::vec4& GetBBoxMax() const;
        /// <summary>
        /// Sets the bounding box for the mesh
        /// </summary>
        /// <param name="p_min">min bound</param>
        /// <param name="p_max">max bound</param>
        void SetBBox(const glm::vec4& p_min, const glm::vec4& p_max);
        /// <summary>
        /// Constructs a mesh object
        /// </summary>
        /// <param name="p_dsp"> parent display this accessor belongs to </param>
        gfx3d_scg_mesh(gfx3d_scg_display* const p_dsp);
        /// Copy construct.
        gfx3d_scg_mesh(gfx3d_scg_mesh & p_obj);
		/// destructor		
		virtual ~gfx3d_scg_mesh();
        /// <summary>
        /// Pre render operations for the mesh (rendercore private).
        /// </summary>
        void pre_render();
        /// <summary>
        /// adds the mesh to renderlist if its visible.
        /// </summary>
        /// <param name="p_node">parent node of this mesh</param>
        void prepare_rlist(gfx3d_scg_node* const p_node);
        /// <summary>
        /// Loads this mesh by creating dynamic contents..
        /// </summary>
        /// <param name="p_scene">id of the scene which is requesting this mesh load</param>
        /// <param name="p_visible">visibility of parent node, may affect resource loading depending on p_mode</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        bool Load(const size_t p_scene, const bool p_visible=true);
        /// <summary>
        /// Unloads this mesh by deleting dynamic contents.. if none of the scene uses this mesh anymore
        /// </summary>
        /// <param name="p_scene">id of the scene which is requesting this node unload</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        bool UnLoad(const size_t p_scene);
        /// adds the passed primitive to this mesh
        void AddPrimitive(gfx3d_scg_primitive* const p_prim);
		/// returns the number of primitives in this mesh
        size_t GetPrimitivesCount() const;
		/// returns the primitives at given index	
        gfx3d_scg_primitive *GetPrimitive(const int32_t p_index) const;
        /// returns the weight at given index	
        float32_t GetWeight(const int32_t p_index) const;
        /// <summary>
        /// Sets the weight for given index
        /// </summary>
        bool SetWeight(const int32_t p_index, const float32_t p_weight);
        /// <summary>
		/// calculates bounding box of mesh
		/// for each primitive check max and  min vertices returns bounding box
		/// <param name="p_force">p_force true calculate always, else ignores if already calculated</param>
		/// </summary>
		void CalculateBoundingBox(const bool p_force = false);
        /// <summary>
        /// Get pointer to parent display
        /// </summary>
        /// <returns>returns pointer to parent display </returns>
        gfx3d_scg_display* GetDisplay() const;
        /// <summary>
        /// Sets the parent display
        /// <param name="p_parent">pointer to display</param>
        /// </summary>
        void SetDisplay(gfx3d_scg_display* const p_val);
        /// <summary>
        /// Get pointer to parent node
        /// </summary>
        /// <returns>returns pointer to parent display </returns>
        gfx3dTransform* GetParent() const;
        /// <summary>
        /// Sets the parent node
        /// <param name="p_parent">pointer to display</param>
        /// </summary>
        void SetParent(gfx3dTransform* const p_val);
        /// <summary>
        /// Check if bounding box is calculated
        /// </summary>
        /// <returns>returns true if bounding box is calculated </returns>
        bool GetIsBoundingBoxCalulated() const;
        /// <summary>
        /// sets the mesh visible ('true') or invisible ('false')
        /// Also sets the dirty flag when the visibility toggles 
        /// TODO : text node is using this to control rendering when there is empty text. So application control of this
        /// property for text node wont work.
        /// </summary>
        /// <param name="p_visible">Sets the visibility</param>
        void SetVisible(const bool p_visible);
        /// checks if mesh is visible
        bool IsVisible(void) const;
        /// <summary>
        /// Sets the scene as dirty / has property changes
        /// </summary>
        void SetDirty();
        /// <summary>
        /// clears the dynamic mesh
        /// </summary>
        void Clear();
        /// <summary>
        /// sets UV for dynamic mesh
        /// </summary>
        /// <param name="p_data">pointer to UV data</param>
        /// <param name="p_length">size of UV data</param>
        /// <param name="p_uvset">UV set index</param>
        void SetUV(const glm::vec2* const p_data, const size_t p_length, const size_t p_uvset = 0U) const;
        /// <summary>
        /// sets vertices for dynamic mesh
        /// </summary>
        /// <param name="p_data">pointer to vertex data</param>
        /// <param name="p_length">size of vertex data</param>
        void SetVertices(const glm::vec3* const p_data, const size_t p_length);
        /// <summary>
        /// sets normals for dynamic mesh
        /// </summary>
        /// <param name="p_data">pointer to nomral data</param>
        /// <param name="p_length">size of nomral data</param>
        void SetNormals(const glm::vec3* const p_data, const size_t p_length);
        /// <summary>
        /// sets color data for dynamic mesh
        /// </summary>
        /// <param name="p_data">pointer to color data</param>
        /// <param name="p_length">size of color data</param>
        void SetColors(const glm::vec4* const p_data, const size_t p_length);
        /// <summary>
        /// sets indices for dynamic mesh
        /// </summary>
        /// <param name="p_data">pointer to index data</param>
        /// <param name="p_length">size of index data</param>
        void SetTriangles(const int32_t* const p_data, const size_t p_length);
    };
    /// @}
}

#endif