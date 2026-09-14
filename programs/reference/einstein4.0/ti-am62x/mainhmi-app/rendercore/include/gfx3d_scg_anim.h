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
//  Filename    : gfx3d_scg_anim.h
//  Description : generic animation class which can be inherited
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_scg_anim.h
/// \brief generic animation class which can be inherited
#ifndef gfx3d_scg_anim_h
#define gfx3d_scg_anim_h

#include "rc_flag.h"

namespace rendercore_engine
{
    /// \ingroup Engine
    /// @{
    /// <summary>
	/// Holds the handling to load animation data and as well run the animations 
	/// \see MdlTargetPath_E
	/// </summary>
	class gfx3d_scg_anim
	{
	private:
        std::vector<std::string> aliasNames;    ///< list of aliasNames
        rc_flag sceneLoadedMask;         ///< indicates for which scenes the animations are loaded
                                         ///< Since animations are loaded scene by scene.. 
                                         ///< It may be possible that animation may be controlling  
                                         ///< nodes from another scene which are not loaded yet.. 
		GLfloat lastUpdatetime = 0.0F;   ///< internal data to hold the last time stamp
        bool bLoaded = false;           ///< if true indicated this animation is loaded
        bool animRunning = false;        ///< flag used internally to mark the running state of an animation
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
        std::recursive_mutex data_mutex; ///< mutex to protect all data access by threads
#endif
        void run_time_anim(const GLfloat p_tick);///< run the animation to passed time tick
        void run_property_anim();          ///< runs the animation to a linked property value
    protected:
        std::string name;				        ///< name of the animation		
        size_t attachedNode = static_cast<size_t>(SIZE_MAX);         ///< node to which this animation is attached
        gfx3d_scg_node* driverNode = nullptr;	///< if set to valid node then animation is property based animation. The animation timeline is then controlled by a property from this node (dirverProperty)
        gfx3d_scg_display* display = nullptr;	///< display parent object
        std::map<int32_t, animNode*> lnodesdicry;   ///< Holds the key value mapping table : [animated node index, the animation data]
        std::vector<rdf_behaviour*> associateBehaviours; ///< list contains all the the scripts which is commanding this animation. This is kept for invoking the callbacks.. 
        std::string driverPropertyName = "";	///< for property based animation which property linked
        GLfloat playbackSpeed = 1.0F;		    ///< Playback speed multiplication factor
        GLfloat position = 0.0F;		        ///< Current time position of animation
        GLfloat stopInSpeed = 0.0F;		        ///< when animation is stopped, at what speed it should reach start or end
        GLfloat maxkeyin = 0.0F;                ///< Holds the maximum duration of all animations combined
        MdlAnimationState_E playstate = MdlAnimationState_E::asStopped;		        ///< Current play state of animation
		MdlAnimationState_E previousPlaystate = MdlAnimationState_E::asStopped;     ///< Previous play state of animation
		MdlAnimationPlaybackMode_E playback = MdlAnimationPlaybackMode_E::apmNormal;///< Playback mode of animation
		int32_t repeatCount = 1;				///< Repeat cout of animation, 0=runs infinite, else number of times animation to run
		int32_t currentPlayCount = 0;			///< Current playback run count (animation stops when currentPlayCount reaches repeatCount)
        int32_t driverNodeId = -1;	            ///< if set to >=0, animation is property based animation, linked to dirverProperty with node id set
        bool resetToStart = false;		        ///< when animation is stopped or completed should it reset to start
        bool autoPlay = false;			        ///< should auto play animation when launched
        bool relative = false;                  ///< false : absolute value animation. Run relative to current property to reach target.
        /// <summary>
		/// Update animation to current position value (gfx3d_scg_anim::position)
		/// </summary>
		void UpdateToPosition();
    public:
		/// <summary>
		/// Runs all the animation channels for the passed tick.
		/// mainly the tick value is comaped against each entery in the key in data table. And identifiy its location between two enttries
		/// Once the two entries are identified the depending on how far the tick is positioned from the identified start index, a % is
		/// calculated. And the key out table is then interpolated with the equivalant index and the out put value is determined.
		/// Output data us saved for usage by render routines.
		/// <param name="p_tick">time tick value</param>
        /// <param name="p_active_scenes">list of active scenes. only animations which are part of active scenes are played</param>
        /// </summary>
		void run_allanim(const GLfloat p_tick, const std::vector<size_t>& p_active_scenes);
		/// <summary>
		/// Constructor. accepts the tinygfx3d model as input and then extracts the animation channels in to internal storage.
		/// </summary>
		gfx3d_scg_anim();
		/// <summary>
		/// Destructor.
		/// </summary>
		virtual ~gfx3d_scg_anim();
		/// <summary>
		/// Get the animated node for the passed node index. Called by render loop to override the property based on animation.
		/// If the property is not animated, returns NULL
		/// <param name="p_node">node index for which animated property value is required</param>
		/// <returns>Returns animated property node if available, else returns NULL</returns>
		/// </summary>
		animNode * GetAnimNode(const int32_t p_node) const;
		/// <summary>
		/// Get the maximum duration required by all animation tracks
		/// <returns>Returns maximum duration required by all animation tracks</returns>
		/// </summary>
		GLfloat GetMaxKeyin(void) const;
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
        /// Returns true if this animation is loaded for atleast one scene
        /// <returns>Returns true / false</returns>
        /// </summary>
        bool IsLoaded() const;
        /// <summary>
        /// Returns true if this animation is loaded for passed scene
        /// <param name="p_scene">id of the scene</param>
        /// <returns>Returns true / false</returns>
        /// </summary>
        bool IsLoaded(const size_t p_scene) const;
        /// <summary>
		/// Set current animation to position and update animation to position value given 
		/// </summary>
		/// <param name="p_position">node index for which animated property value is required</param>
		/// <returns>Returns true if able to resume animation, else false</returns>
		bool SetPosition(const GLfloat p_position, const bool p_force = false);
		/// <summary>
		/// Start the animation  
        /// <param name="p_rdf_behaviour">if this function is invoked from a script, pointer to script to provide a callback on animation status change</param>
        /// <param name="p_resetToStart">when animation completed, should animation reset to start or end position</param>
        /// <returns>Returns true if able to start animation, else false(maybe already playing)</returns>
		/// </summary>
		bool Start(rdf_behaviour* const p_rdf_behaviour=nullptr, const bool p_resetToStart = false);
		/// <summary>
        /// Stop the animation at starting or ending frame depending on p_resetToStart
        /// Function Stop with resetToStart flag is deprecated, will be remove in later release
        /// instead use bool Stop(GLfloat p_stopInSpeed = 0.0f)
		/// <param name="p_resetToStart">when stopped should animation set to start (true) or end (false)</param>
        /// <param name="p_stopInSpeed">speed at which remaining animation time to be played to completion</param>
        /// <returns>Returns true if able to stop animation, else false</returns>
		/// </summary>
		bool Stop(const bool p_resetToStart, const GLfloat p_stopInSpeed = 0.0F);
        /// <summary>
        /// Stop the animation at starting or ending frame depending on p_resetToStart set while starting the animation
        /// <param name="p_stopInSpeed">speed at which remaining animation time to be played to completion</param>
        /// <returns>Returns true if able to stop animation, else false</returns>
        /// </summary>
        bool Stop(const GLfloat p_stopInSpeed = 0.0F);
		/// <summary>
        /// <summary>
        /// Abort the animation inline at current position. Can issue a Start immediately after Abort.
        /// <returns>Returns true if able to abort animation, else false</returns>
        /// </summary>
        bool Abort();
        /// <summary>
		/// Pause the animation  
		/// <returns>Returns true if able to pause animation, else false</returns>
		/// </summary>
		bool Pause();
		/// <summary>
		/// Resume the animation  
		/// <returns>Returns true if able to resume animation, else false</returns>
		/// </summary>
		bool Resume();
		/// <summary>
		/// Set animation play back mode to value
		/// <param name="p_playback">playmode to set</param>
		/// </summary>
		void SetPlaybackMode(const MdlAnimationPlaybackMode_E p_playback);
		/// <summary>
		/// Set repeat counter, how many times animation should play
		/// <param name="p_value">number of times to play, 0 means infinite</param>
		/// </summary>
		void SetRepeatCount(const int32_t p_value);
		/// <summary>
		/// Set animation speed at which need to play. 1.0 = normal, 2.0 = 2 times faster 
		/// <param name="p_value">animation speed</param>
		/// </summary>
		void SetPlaybackSpeed(const GLfloat p_value);
		/// <summary>
		/// Check if animation is playing
		/// <returns>Returns true if playing, else false</returns>
		/// </summary>
		bool IsPlaying() const;
		/// <summary>
		/// Check if animation is paused
		/// </summary>
		bool IsPaused() const;
        /// <summary>
        /// function to get state of animation
        /// </summary>
        /// <returns>returns state of animation </returns>
        MdlAnimationState_E GetPlaystate() const;
        /// <summary>
        /// function to get playback mode
        /// </summary>
        /// <returns>returns playback mode </returns>
        MdlAnimationPlaybackMode_E GetPlaybackMode() const;
        /// <summary>
        /// function to get value repeat cout of animation, 0=run infinite, else run of times animation to run
        /// </summary>
        /// <returns>returns repeat cout of animation, 0=run infinite, else run of times animation to run </returns>
        int32_t GetRepeatCount() const;
        /// <summary>
        /// function to get current playback run count
        /// </summary>
        /// <returns>returns current playback run count </returns>
        int32_t GetCurrentPlayCount() const;
        /// <summary>
        /// function to get current playback speed
        /// </summary>
        /// <returns>returns current playback speed </returns>
        GLfloat GetPlaybackSpeed() const;
        /// <summary>
        /// function to get position of the animation
        /// </summary>
        /// <returns>returns position of the animation </returns>
        GLfloat GetPosition() const;
        /// <summary>
        /// function to get value when animation is stopped or completed should it reset to start
        /// </summary>
        /// <returns>returns pointer to data buffer </returns>
        bool GetResetToStart() const;
        /// <summary>
        /// function to get value when animation is stopped, at what speed it should reach start or end
        /// </summary>
        /// <returns>returns stop in speed value </returns>
        GLfloat GetStopInSpeed() const;
        /// <summary>
        /// function to get pointer to parent display
        /// </summary>
        /// <returns>returns pointer to parent display </returns>
        gfx3d_scg_display* GetParent() const;
        /// <summary>
        /// Set pointer to parent display
        /// </summary>
        /// <param name="p_parent"> pointer to parent display</param>
        void SetParent(gfx3d_scg_display* const p_parent);
        /// <summary>
        /// Property based animation (animation timeline is controlled by a property than timer), set the
        /// node which owns the property
        /// </summary>
        /// <param name="p_node"> property owner node</param>
		void SetDriverNode(gfx3d_scg_node* const p_node);
        /// <summary>
        /// Get the ID of the node which owns the property for Property based animation
        /// (animation timeline is controlled by a property than timer)
        /// </summary>
        /// <returns>returns id of the driver node </returns>
        int32_t GetDriverID() const;
        /// <summary>
        /// Get the Pointer of the node which owns the property for Property based animation
        /// (animation timeline is controlled by a property than timer)
        /// </summary>
        /// <returns>returns pointer of the driver node </returns>
        gfx3d_scg_node *GetDriverNode() const;
        /// <summary>
        /// Get the property name which controls a property based animation
        /// (animation timeline is controlled by a property than timer)
        /// </summary>
        /// <returns>returns name of the property </returns>
        std::string GetDriverPropertyName() const;
        /// <summary>
        /// Get the animation clip id to object mapping table
        /// </summary>
        /// <returns>returns the animation clip id to node mapping </returns>
        std::map<int32_t, animNode *> *GetAnimNodeMap();
        /// <summary>
        /// Creates an anim node object for the passed node if it doesnot exist already.
        /// Returns the existing anim node or newly created one
        /// Returns nullptr if p_nodeindex < 0 or p_nodeindex >= RcGetMaxNumberOfNodes()
        /// </summary>
        /// <param name="p_nodeindex">target node index where the animation to be applied</param>
        /// <returns>animation node object</returns>
        animNode* CreateAnimNode(const int32_t p_nodeindex);
        void SetName(const std::string p_name); ///< sets name of the animation
        std::string GetName() const; ///< return name of the animation	 
        void AddAliasName(const std::string& p_name); ///< add to alias name list
        size_t GetNumOfAliasNames() const;    ///< returns count of alias name
        std::string GetAliasName(const int32_t p_index);     ///< returns alias name at p_index, if not found returns empty string
        bool IsNameMatches(const std::string p_name) const;   ///< return true if name or one of alias name matches
        bool IsAutoPlay() const; ///< return if auto play animation is set
        void SetAutoPlay(const bool p_value); ///< should auto play animation when launched	 
        void SetRelative(const bool p_value); ///< if false (default) absolute values are written by animation player. if true properties are written relatively from current value to reach destination
        bool IsRelative() const;    ///< tests if the player is in relative (true) or absolute (false) mode.
        size_t GetAttachedNodeId() const; ///< Returns the node to which this animation is attached
        void remove_behaviour(rdf_behaviour* const p_beh);///< Removes the passed behaviour from callback list (internally invoked)
#if !defined(RC_ONLY_RDF)
        /// <summary>
        /// Exists to support multiple gltf loading. invoked internally
        /// so donot call from application code.
        /// </summary>
        /// <param name="p_nodeoffset">offset to be applied to all node indexes</param>
        /// <param name="p_accoffset">offset to be applied to all accessor indexes</param>
        void merge_anim(size_t p_nodeoffset, size_t p_accoffset);
#endif
	};
    /// @}
}

#endif
