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
/// @file gfx3d_scg_guiskinning.h
/// @author emanoj1@visteon.com
/// @brief GUI skinning control 
/// @date 11-Sep-2018
/// @copyright © 2019, Visteon Corporation, All Rights Reserved
///////////////////////////////////////////////////////////////////////////////
#ifndef gfx3d_scg_guiskinning_h
#define gfx3d_scg_guiskinning_h

#include "gfx3d_scg_types.h"
#include "rc_guiskinning_type.h"

#define RC_GUISKIN_REQ_ALL (-1) ///< Loads all the skinning info
#define RC_GUISKIN_REQ_DFT (-2) ///< Loads only the default skin 

namespace rendercore_engine
{
    /// <summary>
    /// Stores the properties which are skinned for a node
    /// </summary>
    struct gfx3d_guiskin_node
    {
        glm::vec3 sknScale{FLT_MAX,FLT_MAX, FLT_MAX};
        glm::quat sknQuatRotation{ 0.0F, 0.0F, 0.0F, 1.0F };
        glm::vec3 sknTranslation{ FLT_MAX,FLT_MAX, FLT_MAX };
        float32_t sknObjOpacity=-1.0F;
        int32_t sknFlipBookIndex=-2;
        int32_t sknVisibility=-1;
        int32_t sknNodeIndex = -1;
    };
    /// <summary>
    /// Stores the properties which are skinned for a text node
    /// </summary>
    struct gfx3d_guiskin_text
    {
        glm::vec4 sktDrawColor{ FLT_MAX,FLT_MAX,FLT_MAX,FLT_MAX };
        int32_t sktFontIndex=-1;
        int32_t sktNodeIndex=-1;
        mdl_layoutHalign_E sktHorzAlign = mdl_layoutHalign_E::hUnset;
        mdl_layoutValign_E sktVertAlign = mdl_layoutValign_E::vUnset;
    };
    /// <summary>
    /// Stores the properties which are skinned for a layout node
    /// </summary>
    struct gfx3d_guiskin_layout
    {
        int32_t sklNodeIndex = -1;
        mdl_layoutHalign_E sklHorzAlign = mdl_layoutHalign_E::hUnset;
        mdl_layoutValign_E sklVertAlign = mdl_layoutValign_E::vUnset;
        mdl_layoutDirection_E sklDirection = mdl_layoutDirection_E::dUnset;
    };
    /// <summary>
    /// Stores a single uniform property of skinned material
    /// </summary>
    struct gfx3d_guiskin_uniform
    {
        const CHAR8* skuName = nullptr;				            ///< name of shaderdef data
        rdf_glslDataType skuType = rdf_glslDataType::MDATT_INVD;	///< type of shaderdef data
        GLint skuVGLint = -1;						                ///< storage if type is of int
        float32_t skuFData[4]{0.0F,0.0F,0.0F,0.0F };               ///< incase type float32_t, vec2, vec3 or vec4 data will be stored here
    };
    /// <summary>
    /// Stores the properties of a skinned material
    /// </summary>
    struct gfx3d_guiskin_material
    {
        int32_t skmNodeIndex = -1; ///< node index where the material can be located
        int32_t skmPrimitive = -1; ///< primitive index with in the node. material of this primitive will be skinned
        std::vector<gfx3d_guiskin_uniform> skmUniforms; ///< list of uniforms & its values to be applied to the material
    };
    struct gfx3d_guiskin_camera
    {
        int32_t skcCameraIndex = -1; ///< Camera index
        glm::vec4 skcClearColor{ FLT_MAX,FLT_MAX,FLT_MAX,FLT_MAX };
    };
    /// <summary>
    /// Stores the properties of a skinned primitive
    /// </summary>
    struct gfx3d_guiskin_primitive
    {
        int32_t skpNodeIndex = -1; ///< node index where the material can be located
        int32_t skpPrimitive = -1; ///< primitive index with in the node. material of this primitive will be skinned
        int32_t skpMaterial = -1;  ///< index of the material to be applied to the above primitive
    };
    /// <summary>
    /// stores the font engine data related with a font
	/// </summary>
    class gfx3d_scg_guiskinning
	{
    private:
        friend class gfx3d_scg_guiskinning_MOCK;///< remains to satisfy unit test. TODO : To be removed at a later stage
        gfx3d_scg_display* display = nullptr;   ///< parent display object
        std::int32_t curSkin = -1;              ///< Currently active skin
        std::int32_t nxtSkin = -1;              ///< Next requested skin to be activated  
        float32_t transitionStage = 1.0F;       ///< Indicates the stage of transition. 0.0 indicates start (0%), 1.0 indicated reached target (100%)
        float32_t elapsedTime = 0.0F;           ///< Elapsed time of the transition.
        std::uint32_t numNodes = 0U;            ///< number of nodes skinned
        std::uint32_t numTexts = 0U;            ///< number of Text nodes skinned
        std::uint32_t numLayouts = 0U;          ///< number of Layout nodes skinned
        std::uint32_t numPrimitives = 0U;       ///< number of primitives skinned
        std::uint32_t numMaterials = 0U;        ///< number of materials skinned
        std::uint32_t numCameras = 0U;          ///< number of cameras skinned
        uint32_t assetClientId = RC_INVALID_ASSET_CLIENT_ID;    ///< Client Id to access the asset
        const CHAR8* skinning_uri = nullptr;    ///< uri of the skinning data file
        std::vector<rc_string> skinList;        ///< list of skin names
        rc_guiskinning gui_skinning;            ///< loaded skinning data object
        bool skipTransition = false;            ///< Indicates whether to skip the transitin or not  
        bool skinChanged = true;                ///< Indicates a change in skin for initializing transition
        /// <summary>
        /// Reads float32_t data float32_t data at p_index & requested length from the float32_t data table
        /// </summary>
        /// <param name="p_index">Index of the float32_t data</param>
        /// <param name="p_length">Length of float32_t data to be read</param>
        /// <returns>returns a pointer to float32_t data if request valid, else nullptr</returns>
        float32_t const* get_floatdata(const std::uint32_t p_skin, const std::int32_t p_index, const size_t p_length) const;
        /// <summary>
        /// Reads string data at p_index from the char data table
        /// </summary>
        /// <param name="p_index">Index of the char data</param>
        /// <returns>returns a pointer to string data if request valid, else nullptr</returns>
        CHAR8 const* get_stringdata(const std::uint32_t p_skin, const std::int32_t p_index) const;
        /// <summary>
        /// Searches the given uniform name in the list and returns the index
        /// </summary>
        /// <param name="p_uniform">name of uniform to serach</param>
        /// <param name="p_list">list to be searched</param>
        /// <returns>valid index if uniform present</returns>
        std::uint32_t find_uniform(const CHAR8* const p_uniform, std::vector<gfx3d_guiskin_uniform>& p_list) const;
        /// <summary>
        /// Loads the specified skin
        /// </summary>
        /// <param name="p_skin">skin index to be loaded</param>
        /// <returns>true on success</returns>
        bool load_skin(const uint8_t p_skin);
    public:
        /// <summary>
        /// Constructs a gui skinning object
        /// </summary>
        /// <param name="p_disp">Parent display object</param>
        /// <returns></returns>
        gfx3d_scg_guiskinning(gfx3d_scg_display* const p_disp, const CHAR8* const p_skinning_uri);
        /// <summary>
        /// Dtor, releases the loaded skin objects
        /// </summary>
        virtual ~gfx3d_scg_guiskinning();
        /// <summary>
        /// Process skinning transition and Apply the skinning property 
        /// to the objects if there is a change
        /// </summary>
        /// <param name="p_force">Forces an update if true. Else update if performed only when a skin changes</param>
        void ProcessSkinning(const bool p_force);
        /// <summary>
        /// Sets the skin by index
        /// Requested is accepted (returns true) when a valid skin id is requested and
        /// 1. There is no ongoing transtion is in progress. (i.e. GetSkinTransitionStage() returns 1.0f)
        /// 2. If a transtion for a SkinX is in progress then only SetCurrentSkin(SkinX, true) is accepted to
        ///    cancell the transition and set SkinX as the current skin.
        /// </summary>
        /// <param name="p_skin">Skin id to be activated</param>
        /// <returns>true if skin id is valid & request is taken</returns>
        bool SetCurrentSkin(const std::int32_t p_skin, const bool p_skip_transition = false);
        /// <summary>
        /// Sets the skin by name
        /// Requested is accepted (returns true) when a valid skin id is requested
        /// 1. There is no ongoing transtion is in progress. i.e. GetSkinTransitionStage() returns 1.0f
        /// 2. If a transtion for a SkinX is in progress then only SetCurrentSkin(SkinX, true) is accepted to
        ///    cancell the transition and set SkinX as the current skin.
        /// </summary>
        /// <param name="p_skin">Name of the Skin to be activated</param>
        /// <param name="p_skip_transition">if true the transition is skipped and skin change happens immediate</param>
        /// <returns>true if skin id is valid & request is taken</returns>
        bool SetCurrentSkin(const std::string p_skin, const bool p_skip_transition=false);
        /// <summary>
        /// Get the currently active skin id
        /// </summary>
        /// <returns>current skin id</returns>
        std::int32_t GetCurrentSkin() const;
        /// <summary>
        /// If  a skin transition is ongoing, this API can provide what the % of progress 
        /// on a scale  0.0 to 1.0
        /// 0.0 (in current skin) to 1.0 (reached destination skin)
        /// </summary>
        /// <returns>Return the % position of any ongoing skin transition</returns>
        float32_t GetSkinTransitionStage() const;
        /// <summary>
        /// Apply skinning to node item
        /// </summary>
        /// <param name="p_item">row number of node skin table</param>
        /// <returns>true if properties applied</returns>
        bool ApplyNodeSkinning(const std::uint32_t p_item);
        /// <summary>
        /// Apply skinning to text node item
        /// </summary>
        /// <param name="p_item">row number of text skin table</param>
        /// <returns>true if properties applied</returns>
        bool ApplyTextSkinning(const std::uint32_t p_item);
        /// <summary>
        /// Apply skinning to layout node item
        /// </summary>
        /// <param name="p_item">row number of layout skin table</param>
        /// <returns>true if properties applied</returns>
        bool ApplyLayoutSkinning(const std::uint32_t p_item);
        /// <summary>
        /// Apply skinning to primitive item
        /// </summary>
        /// <param name="p_item">row number of primitive skin table</param>
        /// <returns>true if properties applied</returns>
        bool ApplyPrimitiveSkinning(const std::uint32_t p_item);
        /// <summary>
        /// Apply skinning to material item
        /// </summary>
        /// <param name="p_item">row number of material skin table</param>
        /// <returns>true if properties applied</returns>
        bool ApplyMaterialSkinning(const std::uint32_t p_item);
        /// <summary>
        /// Apply skinning to camera node item
        /// </summary>
        /// <param name="p_item">row number of layout skin table</param>
        /// <returns>true if properties applied</returns>
        bool ApplyCameraSkinning(const std::uint32_t p_item);
        /// <summary>
        /// Returns the animated node skinning property based on transitionStage
        /// transitionStage - 0         : curSkin values 
        /// transitionStage - 1         : nxtSkin values 
        /// transitionStage - 0 < s < 1 : interpolated value between curSkin-nxtSkin 
        /// </summary>
        /// <param name="p_index">row index of node skinning table</param>
        /// <param name="p_prop">refrence property storage, where value to be written</param>
        /// <returns>true if property is updated on to p_prop</returns>
        bool GetAnimatedNodeSkinProperty(const std::uint32_t p_index, gfx3d_guiskin_node& p_prop) const;
        /// <summary>
        /// Returns the animated text node skinning property based on transitionStage
        /// transitionStage - 0         : curSkin values 
        /// transitionStage - 1         : nxtSkin values 
        /// transitionStage - 0 < s < 1 : interpolated value between curSkin-nxtSkin 
        /// </summary>
        /// <param name="p_index">row index of node skinning table</param>
        /// <param name="p_prop">refrence property storage, where value to be written</param>
        /// <returns>true if property is updated on to p_prop</returns>
        bool GetAnimatedTextSkinProperty(const std::uint32_t p_index, gfx3d_guiskin_text& p_prop) const;
        /// <summary>
        /// Returns the animated layout node skinning property based on transitionStage
        /// transitionStage - 0         : curSkin values 
        /// transitionStage - 1         : nxtSkin values 
        /// transitionStage - 0 < s < 1 : interpolated value between curSkin-nxtSkin 
        /// </summary>
        /// <param name="p_index">row index of node skinning table</param>
        /// <param name="p_prop">refrence property storage, where value to be written</param>
        /// <returns>true if property is updated on to p_prop</returns>
        bool GetAnimatedLayoutSkinProperty(const std::uint32_t p_index, gfx3d_guiskin_layout& p_prop) const;
        /// <summary>
        /// Returns the animated primitive skinning property based on transitionStage
        /// transitionStage - 0         : curSkin values 
        /// transitionStage - 1         : nxtSkin values 
        /// transitionStage - 0 < s < 1 : interpolated value between curSkin-nxtSkin 
        /// </summary>
        /// <param name="p_index">row index of primitive skinning table</param>
        /// <param name="p_prop">refrence property storage, where value to be written</param>
        /// <returns>true if property is updated on to p_prop</returns>
        bool GetAnimatedPrimitiveSkinProperty(const std::uint32_t p_index, gfx3d_guiskin_primitive& p_prop) const;
        /// <summary>
        /// Returns the animated material skinning property based on transitionStage
        /// transitionStage - 0         : curSkin values 
        /// transitionStage - 1         : nxtSkin values 
        /// transitionStage - 0 < s < 1 : interpolated value between curSkin-nxtSkin 
        /// </summary>
        /// <param name="p_index">row index of material skinning table</param>
        /// <param name="p_prop">refrence property storage, where value to be written</param>
        /// <returns>true if property is updated on to p_prop</returns>
        bool GetAnimatedMaterialSkinProperty(const std::uint32_t p_index, gfx3d_guiskin_material& p_prop) const;
        /// <summary>
        /// Returns the animated camera skinning property based on transitionStage
        /// transitionStage - 0         : curSkin values 
        /// transitionStage - 1         : nxtSkin values 
        /// transitionStage - 0 < s < 1 : interpolated value between curSkin-nxtSkin 
        /// </summary>
        /// <param name="p_index">row index of camera skinning table</param>
        /// <param name="p_prop">refrence property storage, where value to be written</param>
        /// <returns>true if property is updated on to p_prop</returns>
        bool GetAnimatedCameraSkinProperty(const std::uint32_t p_index, gfx3d_guiskin_camera& p_prop) const;
        /// <summary>
        /// Creates the required texture objects by the skinning
        /// </summary>
        /// <param name="p_matRow">material skinning table row number for which the texture to be created</param>
        /// <returns>true on success</returns>
        bool CreateTexture(const std::int32_t p_matRow) const;
        /// <summary>
        /// Returns the number of skins
        /// </summary>
        /// <returns>total nuber of skins available</returns>
        std::uint32_t GetNumberOfSkins() const;
        /// <summary>
        /// Get the currently active skin name
        /// </summary>
        /// <returns>current skin name</returns>
        std::string GetCurrentSkinName() const;
        /// <summary>
        /// Get the skin name for given skin index
        /// </summary>
        /// <param name="p_index">Index of the skin</param>
        /// <returns>current skin name</returns>
        std::string GetSkinName(const std::int32_t p_index) const;
        /// <summary>
        /// Get a list of available skins names
        /// </summary>
        /// <returns>list of skin names</returns>
        std::vector<rc_string>* GetSkinsList();
        /// <summary>
        /// Return the skin id corresponding to passed skin name
        /// </summary>
        /// <param name="p_name">Name of the skin</param>
        /// <returns>the skin id</returns>
        std::int32_t GetSkinIndex(const std::string p_name) const;
        /// <summary>
        /// Returns the node skinning property for specified skin and specified row index
        /// </summary>
        /// <param name="p_skin">skin table index from where the property to be fetched</param>
        /// <param name="p_index">row index of node skinning table</param>
        /// <param name="p_prop">refrence property storage, where value to be written</param>
        /// <returns>true if property is updated on to p_prop</returns>
        bool GetNodeSkinProperty(const std::uint32_t p_skin, const std::uint32_t p_index, gfx3d_guiskin_node& p_prop) const;
        /// <summary>
        /// Get the node skin property for specified skin and specified row/item 
        /// </summary>
        /// <param name="p_skin">skin id</param>
        /// <param name="p_index">row number/item index</param>
        /// <returns>pointer to node property if valid, else nullptr</returns>
        const rc_guiskin_node* GetNodeSkinProperty(const std::uint32_t p_skin, const std::uint32_t p_index) const;
        /// <summary>
        /// Returns the text node's skinning property for specified skin and specified row index
        /// </summary>
        /// <param name="p_skin">skin table index from where the property to be fetched</param>
        /// <param name="p_index">row index of text node skinning table</param>
        /// <param name="p_prop">refrence property storage, where value to be written</param>
        /// <returns>true if property is updated on to p_prop</returns>
        bool GetTextSkinProperty(const std::uint32_t p_skin, const std::uint32_t p_index, gfx3d_guiskin_text& p_prop) const;
        /// <summary>
        /// Get the text skin property for specified skin and specified row/item 
        /// </summary>
        /// <param name="p_skin">skin id</param>
        /// <param name="p_index">row number/item index</param>
        /// <returns>pointer to text property if valid, else nullptr</returns>
        const rc_guiskin_text* GetTextSkinProperty(const std::uint32_t p_skin, const std::uint32_t p_index) const;
        /// <summary>
        /// Returns the layout node's skinning property for specified skin and specified row index
        /// </summary>
        /// <param name="p_skin">skin table index from where the property to be fetched</param>
        /// <param name="p_index">row index of layout node skinning table</param>
        /// <param name="p_prop">refrence property storage, where value to be written</param>
        /// <returns>true if property is updated on to p_prop</returns>
        bool GetLayoutSkinProperty(const std::uint32_t p_skin, const std::uint32_t p_index, gfx3d_guiskin_layout& p_prop) const;
        /// <summary>
        /// Get the layout skin property for specified skin and specified row/item 
        /// </summary>
        /// <param name="p_skin">skin id</param>
        /// <param name="p_index">row number/item index</param>
        /// <returns>pointer to layout property if valid, else nullptr</returns>
        const rc_guiskin_layout* GetLayoutSkinProperty(const std::uint32_t p_skin, const std::uint32_t p_index) const;
        /// <summary>
        /// Returns the primitive skinning property for specified skin and specified row index
        /// </summary>
        /// <param name="p_skin">skin table index from where the property to be fetched</param>
        /// <param name="p_index">row index of layout node skinning table</param>
        /// <param name="p_prop">refrence property storage, where value to be written</param>
        /// <returns>true if property is updated on to p_prop</returns>
        bool GetPrimitiveSkinProperty(const std::uint32_t p_skin, const std::uint32_t p_index, gfx3d_guiskin_primitive& p_prop) const;
        /// <summary>
        /// Get the primitive skin property for specified skin and specified row/item 
        /// </summary>
        /// <param name="p_skin">skin id</param>
        /// <param name="p_index">row number/item index</param>
        /// <returns>pointer to primitive property if valid, else nullptr</returns>
        const rc_guiskin_primitive* GetPrimitiveSkinProperty(const std::uint32_t p_skin, const std::uint32_t p_index) const;
        /// <summary>
        /// Returns the material skinning property for specified skin and specified row index
        /// </summary>
        /// <param name="p_skin">skin table index from where the property to be fetched</param>
        /// <param name="p_index">row index of layout node skinning table</param>
        /// <param name="p_prop">refrence property storage, where value to be written</param>
        /// <returns>true if property is updated on to p_prop</returns>
        bool GetMaterialSkinProperty(const std::uint32_t p_skin, const std::uint32_t p_index, gfx3d_guiskin_material& p_prop) const;
        /// <summary>
        /// Get the material skin property for specified skin and specified row/item 
        /// </summary>
        /// <param name="p_skin">skin id</param>
        /// <param name="p_index">row number/item index</param>
        /// <returns>pointer to material property if valid, else nullptr</returns>
        const rc_guiskin_material* GetMaterialSkinProperty(const std::uint32_t p_skin, const std::uint32_t p_index) const;
        /// <summary>
        /// Returns the camera skinning property for specified skin and specified row index
        /// </summary>
        /// <param name="p_skin">skin table index from where the property to be fetched</param>
        /// <param name="p_index">row index of layout node skinning table</param>
        /// <param name="p_prop">refrence property storage, where value to be written</param>
        /// <returns>true if property is updated on to p_prop</returns>
        bool GetCameraSkinProperty(const std::uint32_t p_skin, const std::uint32_t p_index, gfx3d_guiskin_camera& p_prop) const;
        /// <summary>
        /// Get the camera skin property for specified skin and specified row/item 
        /// </summary>
        /// <param name="p_skin">skin id</param>
        /// <param name="p_index">row number/item index</param>
        /// <returns>pointer to camera property if valid, else nullptr</returns>
        const rc_guiskin_camera* GetCameraSkinProperty(const std::uint32_t p_skin, const std::uint32_t p_index) const;
        /// <summary>
        /// Returns the transition configuration for current skin to next skin 
        /// </summary>
        /// <returns>rdf_guiskin_transition data if a transition exists, else nullptr</returns>
        const rc_guiskin_transition* GetTransitionConfig() const;
        /// <summary>
        /// Creates the texture required by skining, if it doesnot exist in scene
        /// </summary>
        /// <param name="p_type">texture type to create</param>
        /// <param name="p_texture">texture id to create</param>
        /// <returns>returns the status true - success / false - failed </returns>
        virtual bool CreateTexture(const rdf_glslDataType p_type, const std::int32_t p_texture) const;
        /// <summary>
        /// Loads the requested skin (0 - 255) or all the skins (RC_GUISKIN_REQ_ALL) 
        //  or only the default skin (RC_GUISKIN_REQ_DFT)
        /// </summary>
        /// <param name="p_skin">skin to be loaded. RC_GUISKIN_REQ_ALL means loads all, RC_GUISKIN_REQ_DFT loads only default skin, 0-255 loads the skin id if valid</param>
        /// <returns>returns the load status true - loaded / false - not loaded due to some error</returns>
        bool Load(const int32_t p_skin = RC_GUISKIN_REQ_ALL);
        /// <summary>
        /// Un Loads the requested skin (0-255) or all the skins (RC_GUISKIN_REQ_ALL)
        /// </summary>
        /// <param name="p_skin">material skin row number to create</param>
        /// <returns>returns the unload status true - unloaded / false - not unloaded due to some error</returns>
        bool UnLoad(const int32_t p_skin = RC_GUISKIN_REQ_ALL);
        /// <summary>
        /// Get the color property from specified text property struct
        /// </summary>
        /// <param name="p_text">text property struct</param>
        /// <param name="p_prop">referrence to store the text color property </param>
        /// <returns>true if the property is skinned, else false</returns>
        bool GetTextSkinColor(const std::uint32_t p_skin, const rc_guiskin_text* const p_tdata, glm::vec4& p_prop) const;
        /// <summary>
        /// Get the property for specified skin and specified row/item 
        /// </summary>
        /// <param name="p_skin">skin id</param>
        /// <param name="p_index">row number/item index</param>
        /// <param name="p_prop">referrence to store the text font id property </param>
        /// <returns>true if the property is skinned, else false</returns>
        bool GetTextSkinFontID(const rc_guiskin_text* const p_tdata, int32_t& p_prop) const;
        /// <summary>
        /// Get the property for specified skin and specified row/item 
        /// </summary>
        /// <param name="p_skin">skin id</param>
        /// <param name="p_index">row number/item index</param>
        /// <param name="p_prop">referrence to store the text horizontal layout property </param>
        /// <returns>true if the property is skinned, else false</returns>
        bool GetTextSkinHLayout(const rc_guiskin_text* const p_tdata, mdl_layoutHalign_E& p_prop) const;
        /// <summary>
        /// Get the property for specified skin and specified row/item 
        /// </summary>
        /// <param name="p_skin">skin id</param>
        /// <param name="p_index">row number/item index</param>
        /// <param name="p_prop">referrence to store the text vertical layout property </param>
        /// <returns>true if the property is skinned, else false</returns>
        bool GetTextSkinVLayout(const rc_guiskin_text* const p_tdata, mdl_layoutValign_E& p_prop) const;
        /// <summary>
        /// Get the property for specified skin and specified row/item 
        /// </summary>
        /// <param name="p_skin">skin id</param>
        /// <param name="p_index">row number/item index</param>
        /// <param name="p_prop">referrence to store the node eular rotation property </param>
        /// <returns>true if the property is skinned, else false</returns>
        bool GetNodeSkinRotation(const std::uint32_t p_skin, const rc_guiskin_node* const p_ndata, glm::quat& p_prop) const;
        /// <summary>
        /// Get the property for specified skin and specified row/item 
        /// </summary>
        /// <param name="p_skin">skin id</param>
        /// <param name="p_index">row number/item index</param>
        /// <param name="p_prop">referrence to store the node translation property </param>
        /// <returns>true if the property is skinned, else false</returns>
        bool GetNodeSkinTranslation(const std::uint32_t p_skin, const rc_guiskin_node* const p_ndata, glm::vec3& p_prop) const;
        /// <summary>
        /// Get the property for specified skin and specified row/item 
        /// </summary>
        /// <param name="p_skin">skin id</param>
        /// <param name="p_index">row number/item index</param>
        /// <param name="p_prop">referrence to store the node scale property </param>
        /// <returns>true if the property is skinned, else false</returns>
        bool GetNodeSkinScale(const std::uint32_t p_skin, const rc_guiskin_node* const p_ndata, glm::vec3& p_prop) const;
        /// <summary>
        /// Get the property for specified skin and specified row/item 
        /// </summary>
        /// <param name="p_skin">skin id</param>
        /// <param name="p_index">row number/item index</param>
        /// <param name="p_prop">referrence to store the node opacity property </param>
        /// <returns>true if the property is skinned, else false</returns>
        bool GetNodeSkinOpacity(const rc_guiskin_node* const p_ndata, float32_t& p_prop) const;
        /// <summary>
        /// Get the property for specified skin and specified row/item 
        /// </summary>
        /// <param name="p_skin">skin id</param>
        /// <param name="p_index">row number/item index</param>
        /// <param name="p_prop">referrence to store the node flip book index property </param>
        /// <returns>true if the property is skinned, else false</returns>
        bool GetNodeSkinFlipbook(const rc_guiskin_node* const p_ndata, int32_t& p_prop) const;
        /// <summary>
        /// Get the property for specified skin and specified row/item 
        /// </summary>
        /// <param name="p_skin">skin id</param>
        /// <param name="p_index">row number/item index</param>
        /// <param name="p_prop">referrence to store the node visibility property </param>
        /// <returns>true if the property is skinned, else false</returns>
        bool GetNodeSkinVisibility(const rc_guiskin_node* const p_ndata, int32_t& p_prop) const;
        /// <summary>
        /// Get the property for specified skin and specified row/item 
        /// </summary>
        /// <param name="p_skin">skin id</param>
        /// <param name="p_index">row number/item index</param>
        /// <param name="p_prop">referrence to store the horizontal alignment property for layout node</param>
        /// <returns>true if the property is skinned, else false</returns>
        bool GetLayoutSkinHLayout(const rc_guiskin_layout* const p_ldata, mdl_layoutHalign_E& p_prop) const;
        /// <summary>
        /// Get the property for specified skin and specified row/item 
        /// </summary>
        /// <param name="p_skin">skin id</param>
        /// <param name="p_index">row number/item index</param>
        /// <param name="p_prop">referrence to store the vertical alignment property for layout node</param>
        /// <returns>true if the property is skinned, else false</returns>
        bool GetLayoutSkinVLayout(const rc_guiskin_layout* const p_ldata, mdl_layoutValign_E& p_prop) const;
        /// <summary>
        /// Get the property for specified skin and specified row/item 
        /// </summary>
        /// <param name="p_skin">skin id</param>
        /// <param name="p_index">row number/item index</param>
        /// <param name="p_prop">referrence to store the direction property for layout node</param>
        /// <returns>true if the property is skinned, else false</returns>
        bool GetLayoutSkinEdirection(const rc_guiskin_layout* const p_ldata, mdl_layoutDirection_E& p_prop) const;
        /// <summary>
        /// Sets the parent display object
        /// </summary>
        /// <param name="p_parent">parent display object</param>
        void SetParent(gfx3d_scg_display* const p_parent);
        /// <summary>
        /// Returns the parent display object
        /// </summary>
        /// <returns>display</returns>
        gfx3d_scg_display* GetParent() const;
    };
}


#endif