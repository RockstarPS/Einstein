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
//  Filename    : gfx3d_scg_node.h
//  Description : GFX3D scene graph node object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_scg_node.h
/// \brief GFX3D scene graph node object
#ifndef gfx3d_scg_node_h
#define gfx3d_scg_node_h

#include "gfx3d_behaviour.h"

namespace rendercore_engine
{
    /// \ingroup Engine
    /// @{

    /// <summary>
	/// Base class for the scene graph. A node is a collection of meshes
    /// and/or child nodes
    /// Other type of node such as label, layout inherit from a node
	/// </summary>
	class gfx3d_scg_node : public gfx3dTransform
	{
    protected:
        /// objects model matrix. node matrix applied with 
        /// objectScale, Translation & Rotation. objectMareix is applied only
        /// to this object & not its children.
        glm::fmat4x4 obj_matrix{ 1.0F };
        gfx3d_4x4mat  node_matrix;	    ///< node matrix from engine. This will be applied to childrens
        uint32_t uid = 0U;           ///< unique identifier for the node object
        virtual void addToRenderList(const size_t p_cmask);  ///< decide node need to be in render list
    private:
		gfx3d_scg_mesh * meshObj = nullptr;///< mesh for the node. if there is no mesh (null), its just a container
        gfx3d_scg_skin* skinObj = nullptr;///< pointer to skin data, if available.
        rc_flag sceneLoadedMask;        ///< indicates for which scenes loaded this object. Used to decide how many are using
        /// <summary>
        /// camera index for mesh, if the index is a valid index to gfx3d_scg_display::cameras,
        /// this nodes model matrix is used for View matrix, and the camera is also considered
        /// as attached to scene graph and participates in rendering.
        /// \see rendercore_engine::gfx3d_scg_camera::SetCameraNode()
        /// </summary>
        size_t cameraIndex = static_cast<size_t>(SIZE_MAX);
        size_t lightIndex = static_cast<size_t>(SIZE_MAX); ///< index to gfx3d_scg_display::lights[]
        size_t cullingmask = static_cast<size_t>(SIZE_MAX);  ///< culling mask for node
        glm::fmat3x3 norm_matrix{ 1.0F };///< normal matrix used for lights calc
        glm::fmat4x4 mvp_matrix{ 1.0F };///< model view projection matrix
        glm::fmat4x4 mv_matrix{ 1.0F };	///< model view matrix
        size_t skinIndex = static_cast<size_t>(SIZE_MAX);    ///< If the node has an associated skin, then index to the gfx3d_scg_display::skins array
        mdl_windingOrders ff_mode = mdl_windingOrders::woCCW;		///< winding order of the mesh
        bool bLoaded = false;          ///< if true indicates that the buffer is loaded
        bool bDirty = false;           ///< indicates if the model matrix requires recalculation or not.
        gfxVideoPlayer* vidPlayerObj = nullptr;         ///< video player object
#ifdef RC_CHRONO_FEATURE
        bool bParticleNode = false;     ///< Indicates if the node is to be used as particle node.
#endif
    public:
        /// <summary>
        /// Returns the current attached mesh object
        /// </summary>
        gfx3d_scg_mesh * GetMesh(void) const;
        /// <summary>
        /// Sets the passed mesh as current attached mesh object
        /// </summary>
        void SetMesh(gfx3d_scg_mesh* const p_mesh);
        /// <summary>
        /// Returns the current material used by the primitive at passed index p_index
        /// If the index is invalid >= number of primitives or < 0, it returns null
        /// </summary>
        gfx3d_scg_material * GetMaterial(const int32_t p_index) const;
        /// <summary>
        /// Constructs a node
        /// </summary>
        /// <param name="p_parent"> parent display this accessor belongs to </param>
        gfx3d_scg_node(gfx3d_scg_node* const p_parent);
        /// <summary>
        /// Copy Constructs a node
        /// </summary>
        gfx3d_scg_node(const gfx3d_scg_node& p_object);
        /// Performs a shallow copy..
        gfx3d_scg_node& operator=(const gfx3d_scg_node& p_rhs) = delete;
        /// Distructor
        virtual ~gfx3d_scg_node();
        /// <summary>
        /// load node based on index
        /// When a RDF or gltf loader class creates an instance of a node at
        /// node id/index (p_node_index) in input RDF or gltf data, it invokes
        /// the create method to update the lookup tables of owner display
        /// class
        /// Calls gfx3d_scg_display::add_node_in_lookup and gfx3d_scg_display::AddNode
        /// </summary>
        void Create(const int32_t p_node_index = -1);
        /// <summary>
        /// Loads this node by creating dynamic contents..
        /// Note that Unload to be called only from GlBgndOpTask thread context
        /// </summary>
        /// <param name="p_scene">id of the scene which is requesting this node load</param>
        /// <param name="p_depth">depth of the node. used to prevent indefinite recursion</param>
        /// <param name="p_lrule">resource loading rule</param>
        /// <param name="p_visible">visibility of parent node, may affect resource loading depending on p_mode</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        virtual bool Load(const size_t p_scene, const size_t p_depth, const MdlResourceLoadRule p_lrule= MdlResourceLoadRule::All, const bool p_visible=true) override;                                                                       ///< Loads all the assets required by this node
        /// <summary>
        /// Unloads this node by deleting dynamic contents.. if none of the scene uses this node anymore
        /// Note that Unload to be called only from GlBgndOpTask thread context
        /// </summary>
        /// <param name="p_scene">id of the scene which is requesting this node unload</param>
        /// <param name="p_depth">depth of the node. used to prevent indefinite recursion</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        virtual bool UnLoad(const size_t p_scene, const size_t p_depth) override;                                                                     ///< Un Loads all the assets required by this node
        /// <summary>
        /// Pre render is performed before the camera render() loop
        /// pre render is called once for entire scenegraph and each node
        /// gets one call per frame.
        /// Here model matrix, opacity and any generic (camera independant) calculations are performed
        /// </summary>
        /// <param name="p_par_matrix"> parents model matrix, gets multiplied with own  </param>
        /// <param name="p_visible"> parent visible or not  </param>
        virtual void pre_render(const gfx3d_4x4mat& p_par_matrix, const bool p_visible, const rc_prmode p_mode, const uint32_t p_depth) override;
        /// <summary>
        /// in each camera render() loop, prepare_rlist is perforned to 
        /// create a list of primitives which are seen by the camera (camera culling mask test passes)
        /// This method recursively performs on this nodes childrens
        /// </summary>
        /// <param name="p_cmask"> active camera culling mask to get '&' with own</param>
        void prepare_rlist(const size_t p_cmask) override;
        /// <summary>
        /// Renders the passed primitive by initiating GL calls
        /// </summary>
        virtual void render(gfx3d_scg_primitive * const p_prim);
        /// <summary>
        /// Updates a float32_t property value to custom property in a behaviour or material used by this node
        /// if(isUniform)Iterates through all primitives of this nodes mesh, and sets uniform of each material
        /// </summary>
        /// <param name="propertyName"> name of the property </param>
        /// <param name="value"> value to be set</param>
        /// <param name="isUniform"> true - its a uniform, false - its a custom property </param>
        /// <param name="p_relative"> true - relative update, value gets added to current property value , false - absolute update, value overwrites current property value </param>
        void UpdateAnimatingProperty(const std::string& propertyName, const GLfloat p_value, const bool isUniform, const bool p_relative);
        /// <summary>
        /// Updates a float32_t property value to morphtarget state in this node
        /// Iterates through all primitives of this nodes mesh
        /// </summary>
        /// <param name="propertyName"> name of the property </param>
        /// <param name="value"> value to be set</param>
        /// <param name="p_relative"> true - relative update, value gets added to current property value , false - absolute update, value overwrites current property value </param>
        void UpdateAnimatingMorphTarget(const std::string& propertyName, const float32_t p_value, const bool p_relative);
        /// <summary>
        /// Updates a Vector2 property value to custom property in a behaviour or material used by this node
        /// if(isUniform)Iterates through all primitives of this nodes mesh, and sets uniform of each material
        /// </summary>
        /// <param name="propertyName"> name of the property </param>
        /// <param name="value"> value to be set</param>
        /// <param name="isUniform"> true - its a uniform, false - its a custom property </param>
        /// <param name="p_relative"> true - relative update, value gets added to current property value , false - absolute update, value overwrites current property value </param>
        void UpdateAnimatingProperty(const std::string& propertyName, const glm::vec2& p_value, const bool isUniform, const bool p_relative);
        /// <summary>
        /// Updates a Vector3 property value to custom property in a behaviour or material used by this node
        /// if(isUniform)Iterates through all primitives of this nodes mesh, and sets uniform of each material
        /// </summary>
        /// <param name="propertyName"> name of the property </param>
        /// <param name="value"> value to be set</param>
        /// <param name="isUniform"> true - its a uniform, false - its a custom property </param>
        /// <param name="p_relative"> true - relative update, value gets added to current property value , false - absolute update, value overwrites current property value </param>
        void UpdateAnimatingProperty(const std::string& propertyName, const  glm::vec3& p_value, const bool isUniform, const bool p_relative);
        /// <summary>
        /// Updates a Vector4 property value to custom property in a behaviour or material used by this node
        /// if(isUniform)Iterates through all primitives of this nodes mesh, and sets uniform of each material
        /// </summary>
        /// <param name="propertyName"> name of the property </param>
        /// <param name="value"> value to be set</param>
        /// <param name="isUniform"> true - its a uniform, false - its a custom property </param>
        /// <param name="p_relative"> true - relative update, value gets added to current property value , false - absolute update, value overwrites current property value </param>
        void UpdateAnimatingProperty(const std::string& propertyName, const glm::vec4& p_value, const bool isUniform, const bool p_relative);
        /// <summary>
        /// Adds the passed behaviour to list of active behaviours only if
        /// the behaviour has a Start() or Update() entry point
        /// </summary>
        void AddActiveBehaviour(rdf_behaviour * const p_behaviour) override;
		/// <summary>
		/// calculates bounding box returns min and max 
		/// calculates based on matrix model_matrix 
		/// <param name="p_recursive">if true will calulate with child bounding box</param>
		/// <param name="minBounding">passed by reference, filled with valid minBounding</param>
		/// <param name="maxBounding">passed by reference, filled with valid maxBounding</param>
		/// <param name="p_recursive">if true will calulate with child bounding box</param>
		/// <param name="p_coordinateSpace">CoordinateSpace value //World-calculate in world space //View-calculate in view space //NDC-calculate in NDC //Screen-calulcate in screen coordinate</param>
		/// <returns>returns true if calulated properly else false</returns>
		/// usage, to calulate layout x,y,z,width,height,depth 
		/// glm::vec4 minBounding = glm::vec4(std::numeric_limits<float32_t>::max());
		/// glm::vec4 maxBounding = glm::vec4(std::numeric_limits<float32_t>::lowest()); //-FLT_MAX
		/// bool retVal = CalculateBoundingBox(minBounding, maxBounding);
		/// x = minBounding[0];
		/// y = minBounding[1];
		/// z = minBounding[2];
		/// width = maxBounding[0] - minBounding[0];
		/// height = maxBounding[1] - minBounding[1];
		/// depth = maxBounding[2] - minBounding[2];
		/// </summary>
		bool CalculateBoundingBox(glm::vec4 &minBounding, glm::vec4 &maxBounding, const bool p_recursive = true, const CoordinateSpace p_coordinateSpace = CoordinateSpace::World, const glm::fmat4x4 * matrixToMul = nullptr, const gfx3d_scg_camera * const cameraNode = nullptr, const bool useMargin = false, uint32_t p_recurseLevel = 0U) override;
        /// <summary>
        /// Gets the winding order to be used for this nodes primitives
        /// </summary>
        GLenum GetFFMode() const;
        /// <summary>
        /// Gets the camera index value
        /// </summary>
        size_t GetCameraIndex() const;
        /// <summary>
        /// Sets the camera index value
        /// </summary>
        void SetCameraIndex(const GLint p_cameraIndex);
        /// <summary>
        /// Gets the light index value
        /// </summary>
        size_t GetLightIndex() const;
        /// <summary>
        /// Get the light data pointer for this node if its a light node. i.e LightIndex is valid
        /// </summary>
        gfx3d_scg_light* GetLight() const;
        /// <summary>
        /// Sets the light index value
        /// </summary>
        void SetLightIndex(const GLint p_lightIndex);
        /// <summary>
        /// function to get Node matrix
        /// </summary>
        /// <returns>returns Model Matrix </returns>
        const gfx3d_4x4mat& GetNodeMatrix() const;
        /// <summary>
        /// function to get object matrix. Objet matrix is (model TRS combined with object TRS)
        /// Its useful when a Label object needs to be repositioned acording to its 
        /// alignment without affecting its childrens.
        /// The model matrix is passed to its children, so updating object TRS only affects
        /// this node
        /// \see gfx3dTransform::objectEulerAngles
        /// \see gfx3dTransform::objectPosition
        /// \see gfx3dTransform::objectScale
        /// </summary>
        /// <returns>returns object matrix </returns>
        const glm::fmat4x4& GetObjMatrix() const;
        /// <summary>
        /// function to get normal matrix
        /// </summary>
        /// <returns>returns normal matrix</returns>
        const glm::fmat3x3& GetNormMatrix() const;
        /// <summary>
        /// function to get MVP matrix
        /// </summary>
        /// <returns>returns MVP matrix </returns>
        const glm::fmat4x4& GetMvpMatrix() const;
        /// <summary>
        /// function to get MV matrix
        /// </summary>
        /// <returns>returns MV matrix </returns>
        const glm::fmat4x4& GetMvMatrix() const;
        /// <summary>
        /// Set object matrix
        /// </summary>
        /// <param name="p_matrix"> object matrix </param>
        void SetObjMatrix(const glm::fmat4x4 &p_matrix);
        /// Set skin index (internally set..)
        void SetSkinIndex(const size_t p_index);
        /// Get skin index
        size_t GetSkinIndex() const;
        /// if a skin attached, then performs the bone matrix calculations
        bool ProcessSkin(gfx3d_scg_material * const p_mat);
        /// <summary>
        /// Get an instance of a behaviour attached to this node. If none attached, then creates 
        /// an instance and returns it. (Its added for the purpose to satisfy mel scripts..)
        /// </summary>
        /// <returns></returns>
        rdf_behaviour* GetBehaviourInstance();
        /// <summary>
        /// finds a node by the node name and returns the same
        /// use this for getting access to another node.
        /// \attention name lookup is always costly since string comparisons are involved.
        /// \param p_name : string to be searched
        /// \return node pointer if one exist else null pointer
        /// /// </summary>
        gfx3d_scg_node* Find(const rc_string p_name);
        /// <summary>
        /// Returns true if this node and all of its parents are in visible state
        /// </summary>
        bool GetActiveInHierarchy() const;
        /// returns a script/behaviour component attached to this node by its ID..
        /// if there are multiple scripts with same id, then first script instance is returned.
        rdf_behaviour* GetCompBehaviour(const size_t p_cid);
        /// Checks if all node configurations are valid to decide if the script
        /// to be executed or not..
        /// \attention this API is internally invoked and not designed for invocation by application
        bool isValid(void) const;
        /// node is set active (true) or invactive (false) using this fn
        /// internally modifies the nodes visibility and therefore inactive means the
        /// node will not be rendered
        void SetActive(const bool p_active);
        /// returns the camera which renders this node
        /// Its possible to then access the camera properties such as, clear color etc..
        gfx3d_scg_camera* GetCamera();
        /// <summary>
        /// Returns the children at the passed index. If index is invalid returns NULL
        /// </summary>
        /// <param name="p_index">
        /// Index of the child node to be returned
        /// </param>
        /// <returns>Pointer to child node at passed index. If index is < 0 or >= numof child nodes, then returns NULL </returns>
        gfx3d_scg_node* GetChildAsNode(int32_t ix);
        /// <summary>
        /// Returns the parent of the current node
        /// </summary>
        gfx3d_scg_node* GetParentAsNode();
        /// <summary>
        /// Returns the current node as the textnode
        /// </summary>
        gfx3d_scg_3dtext_node* GetAsTextNode();
        /// <summary>
        /// Returns true if node is visible.
        /// </summary>
        /// <returns>true or false</returns>
        bool GetActive() const;
        /// <summary>
        /// Creates and adds a video player object if not already done
        /// </summary>
        /// <returns>Pointer to the video player object</returns>
        gfxVideoPlayer* AddCompVideoPlayer();
        /// <summary>
        /// Get the pointer to video player object if one exists
        /// </summary>
        /// <returns>Pointer to the video player object or null</returns>
        gfxVideoPlayer* GetCompVideoPlayer() const;
#ifdef RC_CHRONO_FEATURE
        /// Node is a prticle node to be used for particle rendering
        /// </summary>
        /// <param name="val"></param>
        void SetParticleNode(bool val);
#endif
    private:
#ifdef RC_CHRONO_FEATURE
        /// <summary>
        /// If partcle system is available, render the particles by translating the particle node
        /// </summary>
        void RenderParticles(gfx3d_scg_primitive* const p_prim);
#endif
    };
    /// @}
}

#endif