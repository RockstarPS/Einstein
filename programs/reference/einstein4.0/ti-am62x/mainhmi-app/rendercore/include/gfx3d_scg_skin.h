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
//  Filename    : gfx3d_scg_skin.h
//  Description : GFX3D scene graph skin object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_scg_skin.h
/// \brief GFX3D scene graph skin object
#ifndef gfx3d_scg_skin_h
#define gfx3d_scg_skin_h

namespace rendercore_engine
{
    /// \ingroup Engine
    /// @{
    /// <summary>
    /// the skin object https://github.com/KhronosGroup/glTF/tree/master/specification/2.0#skins
    /// Note that the skin support is implemented only for OpenGL ES >= V3.0 currently
    /// </summary>
    class gfx3d_scg_skin
	{
	private:
        gfx3d_scg_display * display = nullptr;	///< parent display object
        std::string name;		                ///< name of the skin
        std::vector<int32_t> jointNodeIndexList;///< index of the nodes that form the skeleton
        int32_t invBindMatAccIndex = -1;        ///< index to the accessor for getting inverse bind matrix
        int32_t skeletonRootNodeIndex = -1;     ///< index of the skeleton root node
        bool bLoaded = false;                   ///< true indicates that the skin object is loaded
        std::vector<glm::mat4> invBindMat;      ///< inverse bind matrix (vector size is = jointNodeIndexList size, as each joint node will have one matrix entry)
        std::vector<glm::mat4> calcBoneMat;     ///< storage to keep the calculated bone matrix (vector size is = jointNodeIndexList size)
#if (GLES3_RENDERER >= 30)
        gfx3dTexture2D * tex = nullptr;         ///< the bone matrix is uploaded as a texture to shader, and this holds the texture object
#endif
    public:
        /// <summary>
        /// Constructs a skin object
        /// </summary>
        /// <param name="p_parent"> parent display this accessor belongs to </param>
        gfx3d_scg_skin(gfx3d_scg_display * const p_parent);
        /// Distructor
		virtual ~gfx3d_scg_skin();
        /// <summary>
        /// function to get name of cmap texture
        /// </summary>
        /// <returns>returns name of cmap texture object </returns>
        std::string GetName() const;
        /// <summary>
        /// Set cmap texture's name
        /// </summary>
        /// <param name="p_name"> name of cmap texture of type string </param>
        void SetName(const std::string p_name);
        /// <summary>
        /// Adds a joint node to skin skeleton
        /// </summary>
        void AddJointNodeIndex(const int32_t p_nodeIndex);
        /// <summary>
        /// Sets the accessor index to get the inverse bind matrix data
        /// </summary>
        void SetInverseBindMatAccessorIndex(const int32_t p_index);
        /// <summary>
        /// Sets the skeleton root node index
        /// </summary>
        void SetSkeletonRootNodeIndex(const int32_t p_index);
        /// <summary>
        /// Loads this skin by creating dynamic contents..
        /// </summary>
        /// <param name="p_scene">id of the scene which is requesting this node load</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        bool Load(const size_t p_scene);
        /// <summary>
        /// Unloads this skin by deleting dynamic contents.. if none of the scene uses this skin anymore
        /// </summary>
        /// <param name="p_scene">id of the scene which is requesting this node unload</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        bool UnLoad(const size_t p_scene);
        /// <summary>
        /// Proess the skin and uploads the skin uniforms to the passed material
        /// </summary>
        bool Process(gfx3d_scg_material * const p_mat);
        /// <summary>
        /// Get the parent display object
        /// </summary>
        /// <returns>display object</returns>
        inline gfx3d_scg_display* GetDisplay() const
        {
            return (display);
        }
        /// <summary>
        /// Set the parent display object
        /// </summary>
        /// <param name="p_disp">display object</param>
        inline void SetDisplay(gfx3d_scg_display* const p_disp)
        {
            display = p_disp;
        }
#if !defined(RC_ONLY_RDF)
        /// <summary>
        /// Exists to support multiple gltf loading. invoked internally
        /// so donot call from application code.
        /// </summary>
        /// <param name="p_nodeoffset">offset to be applied to all node indexes</param>
        /// <param name="p_accoffset">offset to be applied to all accessor indexes</param>
        void merge_skin(size_t p_nodeoffset, size_t p_accoffset);
#endif
    };
    /// @}
}

#endif