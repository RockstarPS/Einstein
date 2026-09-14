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
//  Filename    : gfx3d_scg_anim_node.h
//  Description : holds the animation configurations for a node
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_scg_anim_node.h
/// \brief holds the animation configurations for a node
#ifndef gfx3d_scg_anim_node_h
#define gfx3d_scg_anim_node_h

namespace rendercore_engine
{
    class keyframe;
    class gfx3d_scg_accessor_data;
    /// \ingroup Engine
    /// @{
    /// <summary>
    /// Holds the animation key frame configuration data
    /// Each keyframe data holds a input keys and output keys, interpolation etc.
    /// </summary>
    struct KeyFrameConf
    {
        std::string propertyName;                                       ///< incase type==MdlTargetPath_E::atpCustomProp or MdlTargetPath_E::atpUniform, then this is the name of the property
        MdlAnimInterpol_E interpolation = MdlAnimInterpol_E::aiStep;    ///< interpolation to be used for this keyframe
        MdlTargetPath_E type = MdlTargetPath_E::atpInvalid;             ///< target property this keyframe will control 
        int32_t accessor_input = -1;                                        ///< accessor ID to keyframe input values
        int32_t accessor_output = -1;                                       ///< accessor ID to keyframe output values
    };
    /// <summary>
	/// Holds an animation key frame data for a Node. i.e. one animNode controls properties of a gfx3d_scg_node in
    /// scene graph.
	/// </summary>
    /// \see MdlTargetPath_E
    class animNode
	{
	private:
        /// <summary>
        /// pointer to scenegraph node, this animation will control
        /// </summary>
        gfx3d_scg_node* associateNode = nullptr;
        gfx3d_scg_display* display = nullptr;  ///< display parent object
        /// <summary>
		/// Holds the loaded keyframe input value. This will be used with corresponding kfdata_out to interpolate
        /// and find the animated property value for the node when the animation is playing.
		/// </summary>
		std::vector<const keyframe *> kfdata_in; 
        /// <summary>
        /// Holds the loaded keyframe output value. This will be used with corresponding kfdata_in to interpolate
        /// and find the animated property value for the node when the animation is playing.
        /// </summary>
        std::vector<const keyframe *> kfdata_out;
        /// <summary>
        /// Holds the previous data to generate relative animation
        /// </summary>
        std::vector<glm::vec4> prev_kfdata_out;
        /// <summary>
        /// Holds the keyframe data configuration. Used to load data in to kfdata_in and kfdata_out when ever Load() is 
        /// invoked.
        /// </summary>
        std::vector<KeyFrameConf> kfdata_conf;
        /// <summary>
		/// Holds the maximum input key value for this node. (indicates how long this animation will run)
		/// </summary>
		GLfloat maxkeyin = 0.0F;
        bool bLoaded = false;                  ///< if true indicates that the animation is loaded
    public:
        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="p_display"> parent display this accessor belongs to </param>
        animNode(gfx3d_scg_display * const p_display);
        /// Distructor
        ~animNode();
        /// <summary>
        /// get the maximum input key value for the animation object
        /// </summary>
        /// <returns>returns the maximum key input </returns>
        GLfloat GetMaxKeyin(void) const;
        /// <summary>
		/// Adds a input keyframe for this animation.
		/// After the keyframe is saved, the maximum key value is updated to maxkeyin
		/// </summary>
        /// <param name="p_propertyName">animated property name</param>
        /// <param name="p_ptype">animated property type</param>
		/// <param name="p_accessor">accessor which holds the input key data buffer</param>
		void SetKfIn(const std::string p_propertyName, const MdlTargetPath_E p_ptype, gfx3d_scg_accessor* const p_accessor);
		/// <summary>
		/// Adds the output key for the passed animated property type.
		/// </summary>
        /// <param name="p_propertyName">animated property name</param>
        /// <param name="p_ptype">animated property type</param>
        /// <param name="p_accessor">accessor which holds the input key data buffer</param>
        /// <param name="p_interpolation">interpolation to be used</param>
        void SetKfOut(const std::string p_propertyName, const MdlTargetPath_E p_ptype, gfx3d_scg_accessor* const p_accessor, const MdlAnimInterpol_E p_interpolation);
        /// <summary>
        /// Adds a input keyframe for this animation by gfx3d_scg_accessor_data.
        /// After the keyframe is saved, the maximum key value is updated to maxkeyin
        /// </summary>
        /// <param name="p_accessor">accessor data which holds the input key data buffer</param>
        void SetKfIn(const gfx3d_scg_accessor_data* const p_accessor);
        /// <summary>
        /// Adds the output key for the passed animated property type by gfx3d_scg_accessor_data.
        /// </summary>
        /// <param name="p_propertyName">animated property name</param>
        /// <param name="p_ptype">animated property type</param>
        /// <param name="p_ip">interpolation to be used</param>
        /// <param name="p_accessor">accessor data which holds the input key data buffer</param>
        void SetKfOut(const std::string p_propertyName, const MdlTargetPath_E p_ptype, const MdlAnimInterpol_E p_ip, const gfx3d_scg_accessor_data* const p_accessor);
        /// <summary>
		/// Runs the animation logic for given tick and calculates the animated node values (scale/rotation/translation)
        /// <param name="p_nodeIndex">node index which this animation shall control (sets AssociateNode)</param>
        /// <param name="p_tick">current tick value</param>
		/// </summary>
		void run_anim(const int32_t p_nodeIndex, const GLfloat p_tick, const bool p_relative);
        /// <summary>
        /// function to get associated node (node which this animation controls)
        /// </summary>
        /// <returns>returns pointer to associated node </returns>
        gfx3d_scg_node* GetAssociateNode() const;
        /// <summary>
        /// Set pointer to associated node (node which this animation controls)
        /// </summary>
        /// <param name="p_associateNode"> pointer to associated node</param>
		void SetAssociateNode(gfx3d_scg_node* const p_associateNode);
        /// <summary>
        /// Get the number of keyframes in this animation
        /// </summary>
        /// <returns>returns key frame data count </returns>
        size_t GetKFInDataCount() const;
        /// <summary>
        /// Get the number of keyframes in this animation
        /// </summary>
        /// <returns>returns key frame data count </returns>
        size_t GetKFOutDataCount() const;
        /// <summary>
        /// Get the keyframes data (API exist for debug purpose..)
        /// </summary>
        bool GetKFOutData(const int32_t p_index, const CHAR8** const p_output_data, size_t& p_output_count, MdlTargetPath_E& p_animType, MdlAnimInterpol_E& p_interpolation) const;
        /// <summary>
        /// Get the keyframes data (API exist for debug purpose..)
        /// </summary>
        bool GetKFInData(const int32_t p_index, const CHAR8** const p_input_data, size_t& p_input_count, std::string& p_propertyName, int32_t& p_componentType) const;
        /// <summary>
        /// Loads this node by creating dynamic contents..
        /// </summary>
        /// <param name="p_scene">id of the scene which is requesting this node load</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        bool Load(const size_t p_scene);
        /// <summary>
        /// Unloads this node by deleting dynamic contents.. if none of the scene uses this node anymore
        /// </summary>
        /// <param name="p_scene">id of the scene which is requesting this node unload</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        bool UnLoad(const size_t p_scene);
        /// <summary>
        /// Create a keyframe data config and add it to the kfdata_conf[] list.
        /// </summary>
        /// <param name="p_type">property type the keyframe controls</param>
        /// <param name="p_propertyName">name of the property if type is a custom or uniform type</param>
        /// <param name="p_accessor_input">keyframe input key data acessor</param>
        /// <param name="p_accessor_output">keyframe output key data acessor</param>
        /// <param name="p_interpolation">interpolation to be used</param>
        void Create(const MdlTargetPath_E p_type, const std::string p_propertyName, const int32_t p_accessor_input, const int32_t p_accessor_output, const MdlAnimInterpol_E p_interpolation);
        /// <summary>
        /// Returns true if loaded
        /// </summary>
        /// <returns>true - loaded / false - unloaded </returns>
        bool IsLoaded() const;
        /// <summary>
        /// function to get pointer to parent display
        /// </summary>
        /// <returns>returns pointer to parent display </returns>
        gfx3d_scg_display* GetDisplay() const;
        /// <summary>
        /// Set pointer to parent display
        /// </summary>
        /// <param name="p_parent"> pointer to parent display</param>
        void SetDisplay(gfx3d_scg_display* const p_parent);
#if !defined(RC_ONLY_RDF)
        /// <summary>
        /// Exists to support multiple gltf loading. invoked internally
        /// so donot call from application code.
        /// </summary>
        /// <param name="p_accoffset">offset to be applied to all accessor indexes</param>
        void merge_anim(size_t p_accoffset);
#endif
    };
    /// @}
}

#endif
