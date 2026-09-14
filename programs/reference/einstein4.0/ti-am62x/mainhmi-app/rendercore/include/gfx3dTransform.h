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
//  Filename    : gfx3dTransform.h
//  Description : GFX3D behaviour object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file gfx3dTransform.h
/// \brief GFX3D transform object

#ifndef gfx3dTransform_h
#define gfx3dTransform_h

namespace rendercore_engine
{
    enum class rc_prmode
    {
        Normal,
        Layouting
    };

    /// \ingroup Engine
    /// @{

    ///<summary>
    ///contains properties required for rendering
    ///</summary>
    class gfx3dTransform
    {
    private:
        size_t cullingmask = static_cast<size_t>(SIZE_MAX);  ///< culling mask for node
        gfx3dTransform& operator= (const gfx3dTransform& p_object);
    protected:
        std::vector<gfx3dTransform*> children = std::vector<gfx3dTransform*>(0U);    ///< childrens of this node
        std::vector<rdf_behaviour*> behaviours = std::vector<rdf_behaviour*>(0U);	///< vector of behaviours
        gfx3d_scg_display* display = nullptr;                 ///< parent display object
        gfx3dTransform* parent = nullptr;				    ///< transform parent
        gfx3dTransform* lscene = nullptr;                   ///< parent scene object;
        std::string name;				                    ///< name of the node
        glm::vec4 scissorrect{0.0F, 0.0F, -1.0F, -1.0F };   ///< scissor rectangle set by user
        glm::vec4 margin{ 0.0F };		                    ///< margin to be applied when the node is part of a layout
        gfx3d_rotation localRotation{ glm::vec4(0.0F, 0.0F, 0.0F, 1.0F) };///< local quat angles
        gfx3d_vec3 localPosition{ 0.0F };		            ///< local position
        gfx3d_vec3 localPivot{ 0.0F };		                ///< local pivot
        gfx3d_vec3 localScale{ 1.0F };			            ///< local scale
        gfx3d_vec3 objectScale{ 1.0F };			            ///< object scale. applied only to the object and not its children.
        gfx3d_vec3 objectPosition{ 0.0F };		            ///< object translation. applied only to the object and not its children.
        gfx3d_vec3 objectPivot{ 0.0F };		                ///< object pivot. applied only to the object and not its children.
        gfx3d_vec3 objectEulerAngles{ 0.0F };	            ///< object rotation. applied only to the object and not its children.
        size_t nodeIndex = static_cast<size_t>(SIZE_MAX);   ///< Node index in gfx3d_scg_display::nodes array
        float32_t objOpacity = 1.0F;                        ///< opacity set for this node.
        float32_t localOpacity = 1.0F;                      ///< calculated opacity for this node considering its parents opacity levels (this value will be uploaded to fragment shader as "uniform float32_t u_Opacity").
        // render_mode properties..						
        mdl_cullMode cullMode = mdl_cullMode::cmUnset;	    ///< culling mode
        mdl_depthTest depthTest = mdl_depthTest::dtUnset;   ///< depth testing 
        mdl_depthWrite depthWrite = mdl_depthWrite::dwUnset;///< depth write
        MdlBlendFactor srcBlendfactor = MdlBlendFactor::bfUnset;///>Color Source Blend Factor
        MdlBlendFactor dstBlendfactor = MdlBlendFactor::bfUnset;///>Color Dst Blend Factor
        MdlBlendFactor aSrcBlendfactor = MdlBlendFactor::bfUnset;///>Alpha Source Blend Factor
        MdlBlendFactor aDstBlendfactor = MdlBlendFactor::bfUnset;///>Alpha Dst Blend Factor
        MdlBlendEquation ablendEquation = MdlBlendEquation::beUnset; ///< GL Alpha blend equation to be used (see glBlendEquationSeperate)
        MdlBlendEquation blendEquation = MdlBlendEquation::beUnset; ///< GL bland equation to be used (see glBlendEquation)
        int32_t flipBookIndex = -1;                     ///< when the flip book index is set the node will start to behave 
        bool visible = true;							///< this node and its childrens are visible when 'true'
                                                        ///< as a flipbook where only the child selected by index being rendered.
                                                        ///< a value -1 (default) means flipbook mode is inactive and all child nodes are rendered
        bool isTouchEnabled = false;					///< true if any one bhv having touch callbacks
        int8_t objectSortOrder = -1;                    ///< controls the render sorting order of the node when rc_rsortType is sortCustom. Valid range is 0 - 127, < 0 indicates the value is unset and follows the parent
        int8_t localSortOrder = -1;                     ///< Calculated render sorting order of the node, derived by applying parent
        gfx3d_4x4mat  model_matrix;		                ///< model matrix used to specify position in 3d world
    public:
        /// constructor 3d transform
        gfx3dTransform(gfx3dTransform* const p_parent);
        gfx3dTransform(const gfx3dTransform& p_object);
        /// <summary>
        /// Returns the owner display for this node 
        /// </summary>
        gfx3d_scg_display* GetDisplay(void) const;
        /// <summary>
        /// Sets the owner display for this node 
        /// </summary>
        void SetDisplay(gfx3d_scg_display* const p_disp);
        /// pre render function
        virtual void pre_render(const gfx3d_4x4mat& p_par_matrix, const bool p_visible, const rc_prmode p_mode, const uint32_t p_depth);
        /// <summary>
        /// prepares the list 
        /// </summary>
        virtual void prepare_rlist(const size_t p_cmask);
        /// <summary>
        /// destructor 3d transform
        /// </summary>
        virtual ~gfx3dTransform();
        /// <summary>
        /// sets the cull mode to given mode
        /// <param name="p_cullMode">cull mode to set</param>
        /// </summary>
        void SetCullMode(const mdl_cullMode p_cullMode);
        /// <summary>
        /// sets the depth test to give test
        /// <param name="p_depthTest">GL depth test to set</param>
        /// </summary>
        void SetDepthTest(const mdl_depthTest p_depthTest);
        /// <summary>
        /// sets the depth write 
        /// <param name="p_depthWrite">GL depth write to set</param>
        /// </summary>
        void SetDepthWrite(const mdl_depthWrite p_depthWrite);
        /// sets the blende mode
        /// <param name="p_blendMode">blend mode to set</param>
        /// </summary>
        void SetBlendMode(const MdlBlendMode p_blendMode);
        /// <summary>
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
        void SetAlphaSrcBlendFactor(const MdlBlendFactor p_ablendFactor);
        /// <summary>
        /// sets the Alpha Dst blend factor
        /// <param name="p_ablendFactor">blend factor to set</param>
        /// </summary>
        void SetAlphaDstBlendFactor(const MdlBlendFactor p_ablendFactor);
        /// <summary>
        /// sets the blende equation
        /// <param name="p_blendMode">blend equation to set</param>
        /// </summary>
        void SetBlendEquation(const MdlBlendEquation p_blendEquation);
        /// <summary>
        /// sets the Alpha Dst blend equation
        /// <param name="p_ablendEquation">blend equation to set</param>
        /// </summary>
        void SetAlphaBlendEquation(const MdlBlendEquation p_ablendEquation);  
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
        /// returns the cull mode
        /// </summary>
        mdl_cullMode GetCullMode(void) const;
        /// <summary>
        /// returns the depth test
        /// </summary>
        mdl_depthTest GetDepthTest(void) const;
        /// <summary>
        /// returns the depth write
        /// </summary>
        mdl_depthWrite GetDepthWrite(void) const;
        /// <summary>
        /// returns the blende mode
        /// </summary>
        MdlBlendMode GetBlendMode(void) const;
        /// <summary>
        /// Gets optional alpha channel blend mode
        /// </summary>
        MdlAlphaBlendMode GetAlphaBlendMode(void) const;
        /// <summary>
        /// returns the Src blende factor
        /// </summary>
        MdlBlendFactor GetSrcBlendFactor(void) const;
        /// <summary>
        /// returns the Dst blende factor
        /// </summary>
        MdlBlendFactor GetDstBlendFactor(void) const;
        /// <summary>
        /// returns the Alpha Srcblende factor
        /// </summary>
        MdlBlendFactor GetAlphaSrcBlendFactor(void) const;
        /// <summary>
        /// returns the Alpha Dst blende factor
        /// </summary>
        MdlBlendFactor GetAlphaDstBlendFactor(void) const;
        /// <summary>
        /// Gets optional alpha channel blend mode
        /// </summary>
        MdlBlendEquation GetAlphaBlendEquation(void) const;
        /// <summary>
        /// Gets the blende equation
        /// </summary>
        MdlBlendEquation GetBlendEquation(void) const;
        /// <summary>
        /// returns behaviours
        /// <param name="p_index">texture format of type MdlImgFormat_E</param>
        /// </summary>
        rdf_behaviour* GetBehaviour(const size_t p_index);
        /// <summary>
        /// returns the number of behaviours
        /// </summary>
        size_t GetNumOfBehaviours(void) const;
        /// <summary>
        /// Adds a behaviour to the list
        /// <param name="p_beh">texture format of type MdlImgFormat_E</param>
        /// </summary>
        int32_t AddBehaviour(rdf_behaviour* const p_beh);
        /// <summary>
        /// sets visible
        /// <param name="p_visible">sets transform visibility</param>
        /// </summary>
        void SetVisible(const bool p_visible);
        /// <summary>
        /// gets the istouchEnabled flag true if any one bhv having touch callbacks
		/// </summary>
        bool GetTouchEnabled(void) const;
        /// <summary>
        /// checks if visible
        /// </summary>
        bool GetVisible(void) const;
        /// <summary>
        /// virtual fn adds an active behavoior to the list (internally invoked, not for application use)
        /// <param name="p_behaviour">texture format of type MdlImgFormat_E</param>
        /// </summary>
        virtual void AddActiveBehaviour(rdf_behaviour* const p_behaviour) = 0;
        /// <summary>
        /// controls whether the node should act as a flip book or not. 
        /// with this API we can flip through the nodes by changing the selected node index
        /// </summary>
        /// <param name="p_index">
        ///   when p_index = -1 : deactivate flipbookmode / all child nodes are rendered
        ///   when p_index  = 0 to < children.size(), only the child node at the index gets rendered. And remaining childs go invisible
        ///   when p_index  >= children.size() all child nodes go invisible
        /// </param>
        void SetFlipbookActiveIndex(const int32_t p_index);
        /// <summary>
        /// Get the flipbook selected node index
        /// </summary>
        /// <returns>returns the selected node index</returns>
        int32_t GetFlipbookActiveIndex(void) const;
        /// <summary>
        /// Returns the children at the passed index. If index is invalid returns NULL
        /// </summary>
        /// <param name="p_index">
        /// Index of the child node to be returned
        /// </param>
        /// <returns>Pointer to child node at passed index. If index is < 0 or >= numof child nodes, then returns NULL </returns>
        gfx3dTransform* GetChild(const int32_t p_index) const;
        /// <summary>
        /// Returns the number of children held by this node
        /// </summary>
        /// <returns>number of childrens (>=0)</returns>
        int32_t GetChildCount(void) const;
        /// <summary>
        /// Gets a float32_t property value by its name. 
        /// property name can be predefined name to nodes internal properties or scripts public properties
        /// predefined names are,
        ///  - "flipBookIndex" : flipBookIndex property of gfx3dTransform \see SetFlipbookActiveIndex()
        ///  - "translateX" : localPosition.x property of gfx3dTransform
        ///  - "translateY" : localPosition.y property of gfx3dTransform
        ///  - "translateZ" : localPosition.z property of gfx3dTransform
        ///  - "visibility" : GetVisible() of gfx3dTransform
        ///  - "rotateX" : localRotation.x property of gfx3dTransform
        ///  - "rotateY" : localRotation.y property of gfx3dTransform
        ///  - "rotateZ" : localRotation.z property of gfx3dTransform
        ///  - "scaleX" : localScale.x property of gfx3dTransform
        ///  - "scaleY" : localScale.y property of gfx3dTransform
        ///  - "scaleZ" : localScale.z property of gfx3dTransform
        /// \attention In case of script public property, the search stopswhen a script 
        /// with the property names is found. So if there are multiple scripts having same 
        /// property names, you cant say to return property from second or a third ... script 
        /// </summary>
        /// <param name="p_prop">Name of the property</param>
        /// <returns>Returns the value of the asked property</returns>
        float32_t GetFloatProperty(const std::string p_prop);
        /// <summary>
        /// Gets an Integer property value by its name. 
        /// </summary>
        /// <param name="p_prop">Name of the property</param>
        /// <returns>Returns the value of the asked property</returns>
        int32_t GetIntProperty(const std::string p_prop);
        /// <summary>
        /// Gets a string property value by its name. 
        /// </summary>
        /// <param name="p_prop">Name of the property</param>
        /// <returns>Returns the value of the asked property</returns>
        rc_string GetStringProperty(const std::string p_prop);
        /// <summary>
        /// Sets a text property value by its name. 
        /// </summary>
        /// <param name="p_prop">Name of the property</param>
        /// <param name="p_val">
        /// value to be set to the property
        /// </param>
        void SetProperty(const std::string p_prop, const rc_wstring p_val);
        /// <summary>
        /// Sets a text property value by its name. 
        /// </summary>
        /// <param name="p_prop">Name of the property</param>
        /// <param name="p_val">
        /// value to be set to the property
        /// </param>
        void SetProperty(const std::string p_prop, const rc_string p_val);
        /// <summary>
        /// Sets a float32_t property value by its name. 
        /// property name can be predefined name to nodes internal properties or scripts public properties
        /// predefined names are,
        ///  - "flipBookIndex" : flipBookIndex property of gfx3dTransform \see SetFlipbookActiveIndex()
        ///  - "translateX" : localPosition.x property of gfx3dTransform
        ///  - "translateY" : localPosition.y property of gfx3dTransform
        ///  - "translateZ" : localPosition.z property of gfx3dTransform
        ///  - "visibility" : GetVisible() of gfx3dTransform
        ///  - "rotateX" : localRotation.x property of gfx3dTransform
        ///  - "rotateY" : localRotation.y property of gfx3dTransform
        ///  - "rotateZ" : localRotation.z property of gfx3dTransform
        ///  - "scaleX" : localScale.x property of gfx3dTransform
        ///  - "scaleY" : localScale.y property of gfx3dTransform
        ///  - "scaleZ" : localScale.z property of gfx3dTransform
        /// \attention  when there are multiple scripts attached and multiple scripts
        /// has same property name, all the scripts with searched property name will be updated
        /// </summary>
        /// <param name="p_prop">Name of the property</param>
        /// <param name="p_val">value to be set to the property</param>
        void SetProperty(const std::string p_prop, const float32_t p_val);
        /// <summary>
        /// Sets an integer property value by its name. 
        /// </summary>
        /// <param name="p_prop">Name of the property</param>
        /// <param name="p_val">value to be set to the property</param>
        void SetProperty(const std::string p_prop, const int32_t p_val);
        /// <summary>
        /// Append a child pointer in children list. 
        /// </summary>
        /// <param name="p_child">pointer to child</param>
        /// <returns>Returns index value of child in list</returns>
        int32_t AddChild(gfx3dTransform* const p_child);
        /// <summary>
        /// clears all child pointers from list 
        /// </summary>
        void RemoveAllChildren();
        /// <summary>
        /// Set child pointer at index p_index. 
        /// </summary>
        /// <param name="p_index">
        /// index at which p_child will be set
        /// </param>
        /// <param name="p_child">
        /// pointer to child
        /// </param>
        /// <returns>Returns index value of child in list</returns>
        int32_t InsertChild(int32_t p_index, gfx3dTransform* const p_child);
        /// <summary>
        /// Gets first occurance of the child pointer. 
        /// </summary>
        /// <param name="p_child">
        /// pointer to child
        /// </param>
        /// <returns>Returns first index where pointer is p_child, -1 if p_child is not in list</returns>
        int32_t GetFirstIndexofChild(gfx3dTransform* const p_child);
        /// <summary>
        /// Removes the child at index p_index and returns the child pointer
        /// </summary>
        /// <param name="p_index">
        /// child index which is tobe removed
        /// </param>
        /// <returns>Returns pointer to child which is removed from the list</returns>
        gfx3dTransform* RemoveChild(const int32_t p_index);
        /// <summary>
        /// Removes the first occurance of child
        /// </summary>
        /// <param name="p_child">
        /// pointer to child
        /// </param>
        /// <returns>Returns pointer to child which is removed from the list, NULL if child is not present</returns>
        gfx3dTransform* RemoveChild(gfx3dTransform* const p_child);
        /// <summary>
        /// Moves self to last position of parents child node list
        /// </summary>
        void MoveToBack();
        /// <summary>
        /// Moves self to index position of parents child node list
        /// <param name="p_index">
        /// position at p_index, if given p_index < 0 sets to first, 
        /// if given p_index greater than total siblings position at last
        /// </param>
        /// </summary>
        void MoveToIndex(const int32_t p_index);
        /// <summary>
        /// Moves selft at front position of parents child node list
        /// </summary>
        void MoveToFront();
        /// <summary>
        /// Returns the scene to which this node instance is attached to
        /// </summary>
        gfx3d_scg_scene* GetScene(void) const;
        /// <summary>
        /// set the renderCore scg scene to the given p_scene.
        /// <param name="p_scene"> scene to set</param>
        /// </summary>
        void SetScene(gfx3d_scg_scene* const p_scene);
        /// <summary>
        /// Returns the calculated opacity for this node.
        /// </summary>
        float32_t GetOpacity() const;
        /// <summary>
        /// Returns the opacity set for this node. Actual opacity maybe calculated at run time considering its parent levels.
        /// </summary>
        float32_t GetObjOpacity() const;
        /// <summary>
        /// Sets the opacity set for this node. Actual opacity maybe calculated at run time considering its parent levels.
        /// </summary>
        void SetObjOpacity(const float32_t p_val);
        ///< Loads all the assets required by this node
        /// <param name="p_scene">id of the scene which is requesting this text node load</param>
        /// <param name="p_depth">depth of the node. used to prevent indefinite recursion</param>
        /// <param name="p_lrule">resource loading rule</param>
        /// <param name="p_visible">visibility of parent node, may affect resource loading depending on p_mode</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        virtual bool Load(const size_t p_scene, const size_t p_depth, const MdlResourceLoadRule p_lrule = MdlResourceLoadRule::All, const bool p_visible = true);
        ///< Un Loads all the assets required by this node
        /// <param name="p_scene">id of the scene which is requesting this text node load</param>
        /// <param name="p_depth">depth of the node. used to prevent indefinite recursion</param>
        /// <returns>returns the unload status true - unloaded / false - not unloaded </returns>
        virtual bool UnLoad(const size_t p_scene, const size_t p_depth);                                                                              ///< Un Loads all the assets required by this node
        /// Validates the child node index for circular reference.. Returns true if it can be added as a child. else returns false
        bool IsChildRecursive(const size_t p_cnode_index) const;
        /// Set node index (internally set..)
        void SetNodeIndex(const size_t p_index);
        /// Get Node index
        size_t GetNodeIndex() const;
        glm::vec3 GetLocalPosition() const;		            ///< local position
        glm::vec3 GetLocalPivot() const;		            ///< local pivot
        glm::vec3 GetLocalEulerAngles() const;	            ///< euler EulerAngles
        glm::vec3 GetLocalScale() const;			            ///< local scale
        float32_t GetLocalPositionX() const;                ///< local position
        float32_t GetLocalPivotX() const;                   ///< local pivot
        float32_t GetLocalEulerAnglesX() const;	                ///< euler EulerAngles
        float32_t GetLocalScaleX() const;			                ///< local scale
        float32_t GetLocalPositionY() const;		                ///< local position
        float32_t GetLocalPivotY() const;                   ///< local pivot
        float32_t GetLocalEulerAnglesY() const;	                ///< euler EulerAngles
        float32_t GetLocalScaleY() const;			                ///< local scale
        float32_t GetLocalPositionZ() const;		                ///< local position
        float32_t GetLocalPivotZ() const;		                ///< local position
        float32_t GetLocalEulerAnglesZ() const;	                ///< euler EulerAngles
        float32_t GetLocalScaleZ() const;			                ///< local scale
        glm::vec3 GetObjectScale() const;			            ///< object scale. applied only to the object and not its children.
        glm::vec3 GetObjectPosition() const;		            ///< object translation. applied only to the object and not its children.
        glm::vec3 GetObjectPivot() const;		            ///< object pivot. applied only to the object and not its children.
        glm::vec3 GetObjectEulerAngles() const;	            ///< object rotation. applied only to the object and not its children.
        glm::vec4 GetLocalQuatAngles() const;                 ///< local quat angles
        glm::vec4 GetMargin() const;                    ///< margin to be applied when the node is part of a layout
        gfx3dTransform* GetParent() const;    	///< transform parent
        gfx3d_scg_node* GetGameObject();   ///< game object representing the transform 
        void SetLocalPosition(const glm::vec3 p_pos);  	///< local position
        void SetLocalPivot(const glm::vec3 p_pivot);  	///< local position
        void SetLocalEulerAngles(const glm::vec3 p_eular);	///< euler rotation
        void SetLocalScale(const glm::vec3 p_scale);	///< local scale
        void SetObjectScale(const glm::vec3 p_scale);			///< object scale. applied only to the object and not its children.
        void SetObjectPosition(const glm::vec3 p_pos);		///< object translation. applied only to the object and not its children.
        void SetObjectPivot(const glm::vec3 p_pivot);		///< object pivot. applied only to the object and not its children.
        void SetObjectEulerAngles(const glm::vec3 p_eular);	///< object rotation. applied only to the object and not its children.
        void SetLocalQuatAngles(const glm::vec4 p_quat);      ///< local quat angles
        void SetMargin(const glm::vec4 p_margin);		        ///< margin to be applied when the node is part of a layout
        void SetParent(gfx3dTransform* const p_parent);		///< transform parent
        void SetLocalPositionX(const float32_t p_pos);	    ///< local X position
        void SetLocalPivotX(const float32_t p_pivot);	    ///< local X pivot
        void SetLocalEulerAnglesX(const float32_t p_eular);	///< euler X rotation
        void SetLocalScaleX(const float32_t p_scale);		///< local X scale
        void SetLocalPositionY(const float32_t p_pos);	    ///< local Y position
        void SetLocalPivotY(const float32_t p_pivot);	    ///< local Y pivot
        void SetLocalEulerAnglesY(const float32_t p_eular);	///< euler Y rotation
        void SetLocalScaleY(const float32_t p_scale);		///< local Y scale
        void SetLocalPositionZ(const float32_t p_pos);	    ///< local Z position
        void SetLocalPivotZ(const float32_t p_pivot);	    ///< local Z pivot
        void SetLocalEulerAnglesZ(const float32_t p_eular);	///< euler Z rotation
        void SetLocalScaleZ(const float32_t p_scale);		///< local Z scale
        /// Updates the objects opacity and visibility settings. And returns true if the object is visible
        /// Parent visibility as parameter. Returns true if object is visible.
        /// <param name="p_visible">Pass the parent nodes visibility to apply to this node and find final visibility</param>
        /// <returns>Returns true if object visible due to  opacity > 0 and visibility </returns>
        bool UpdateObjectVisibility(bool p_visible);
        /// <summary>
        /// function to get Model matrix
        /// </summary>
        /// <returns>returns Model Matrix </returns>
        const gfx3d_4x4mat& GetModelMatrix() const;
        /// <summary>
        /// function to get name
        /// </summary>
        /// <returns>returns name </returns>
        std::string GetName() const;
        /// <summary>
        /// Set node object name
        /// </summary>
        /// <param name="p_name"> name of node </param>
        void SetName(const std::string p_name);
        /// <summary>
        /// Changes the sorting order of the node. Node with larger sort order renders last
        /// Valid range is 0-127 (applicable when gfx3d_scg_camera.GetSortType() is rc_rsortType.sortCustom)
        /// Negative value indicates the sorting is unset and rule is then to follow the parent node
        /// </summary>
        /// <param name="p_sorder">SortOrder</param>
        void SetSortOrder(const int8_t p_sorder);
        /// <summary>
        /// Returns the sorting order
        /// </summary>
        /// <returns>SortOrder</returns>
        int8_t GetSortOrder() const;
        /// <summary>
        /// Returns the deribed sorting order combining parent values.
        /// </summary>
        /// <returns>SortOrder</returns>
        int8_t GetCalculatedSortOrder() const;
        /// <summary>
        /// Sets the scene as dirty / has property changes
        /// </summary>
        void SetDirty();
        /// <summary>
        /// Gets the culling mask for this node. 
        /// \see :SetCullingMask()
        /// </summary>
        size_t GetCullingMask() const;
        /// <summary>
        /// Sets the culling mask for this node. 
        /// Culling mask deides whether a node gets rendered or not
        /// When a camera renders a scene, node is rendered 
        /// if ((GetCullingMask() & gfx3d_scg_camera::GetCullingMask()) != 0)
        /// </summary>
        void SetCullingMask(const size_t p_mask);
        /// <summary>
        /// Specifies the co ordinate space to be used for bounding box calculation
        /// </summary>
        enum class CoordinateSpace
        {
            World,  ///< World
            View,   ///< View 
            NDC,    ///< Normalized Device
            Screen  ///< Screen
        };
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
        virtual bool CalculateBoundingBox(glm::vec4& minBounding, glm::vec4& maxBounding, const bool p_recursive = true, const CoordinateSpace p_coordinateSpace = CoordinateSpace::World, const glm::fmat4x4* matrixToMul = nullptr, const gfx3d_scg_camera* const cameraNode = nullptr, const bool useMargin = false, uint32_t p_recurseLevel = 0U);
    };

    /// @}
}
#endif