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
//  Filename    : gfx3d_scg_scene.h
//  Description : GFX3D scene graph scene object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_scg_scene.h
/// \brief GFX3D scene graph scene object
#ifndef gfx3d_scg_scene_h
#define gfx3d_scg_scene_h

#include "gfx3d_scg_loadstatus.h"

namespace rendercore_engine
{
    /// \ingroup Engine
    /// @{
    /// <summary>
    /// A display consist of multiple scenes. Each scene is collection of nodes
    /// It helps to organize a projects GUI layouts..
    /// Its possible to load and unload scenes at run time as and when required
    /// e.g. startup scene, main page, overlays etc..
	/// </summary>
	class gfx3d_scg_scene : public gfx3d_scg_node
	{
    private:
        /// <summary>
        /// Holds scene ID or index of this object. 
        /// its an index in to gfx3d_scg_display::scenes
        /// SIZE_MAX or >= gfx3d_scg_display::scenes.size() indicates an invalid value
        /// </summary>
        size_t sceneIndex = static_cast<size_t>(SIZE_MAX);
        rc_sceneload_sts scenesLoadStatus{new gfx3d_LoadStatus}; ///< Load status of the scene. indicates if the loading is done or not
        rc_sceneload_sts scenesUnLoadStatus{ new gfx3d_LoadStatus }; ///< Unload status of the scene. indicates if the unloading is done or not
        bool bActive = false;///< Indicates whether the scene is active. Scene becomes active after its loaded. Only active scenes are rendered.
        /// Scene dirty or has property change flag
        /// A set sets all bits
        /// A clear is performed by display for a camera, so only the bits 
        /// that are valid per camera's cullingMask gets cleared
        /// This is to allow to retain change flag if a scene has multiple cameras.
        size_t sceneDirty = static_cast<size_t>(SIZE_MAX);
        /// <summary>
        /// This holds a list of scripts which have an Update() method. So during the script Update() cycle
        /// only scripts in this list gets serviced..
        /// </summary>
        std::vector<rdf_behaviour *> behaviour_update_method_list;
        /// <summary>
        /// This holds a list of scripts which have an Start() method.
        /// </summary>
        std::vector<rdf_behaviour *> behaviour_start_method_list;
        /// <summary>
        /// List of video players active for this scene
        /// </summary>
        std::vector<gfxVideoPlayer*> behaviour_videoplayer_list;
        /// <summary>
        /// this list acts as a lookup helper to find a node in the scene by its name. 
        /// </summary>
        std::map<std::string, gfx3d_scg_node*> node_Lookup;
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
        mutable std::recursive_mutex data_mutex; ///< to prevent concurrent access to change data
#endif
        std::vector<gfx3d_scg_node*> lights;
    protected:
        /// <summary>
        /// Holds list of animations related to this scene.
        /// </summary>
        std::vector<size_t> animations;
        int32_t assetGroupId = -1;              ///< Resource asset group ID
        uint32_t assetClientId = RC_INVALID_ASSET_CLIENT_ID;    ///< Client Id to access the asset
    public:
        /// <summary>
        /// Constructs an accessor
        /// </summary>
        /// <param name="p_parent"> parent display this accessor belongs to </param>
        /// <param name="p_sceneIndex"> id/index of scene </param>
        gfx3d_scg_scene(gfx3d_scg_display* const p_parent, const size_t p_sceneIndex);															/// virtual destructor
        /// Distructor
        virtual ~gfx3d_scg_scene();
        /// <summary>
        /// Copy Construct not supported
        /// </summary>
        gfx3d_scg_scene(const gfx3d_scg_scene& p_obj) = delete;
        gfx3d_scg_scene& operator=(const gfx3d_scg_scene& p_rhs) = delete;
        /// <summary>
        /// Returns the scene load status as a shared pointer
        /// </summary>
        rc_sceneload_sts GetSceneLoadStatus() const;
        /// <summary>
        /// Returns the scene unload status as a shared pointer
        /// </summary>
        rc_sceneload_sts GetSceneUnLoadStatus() const;
        /// <summary>
        /// Set the scene to active or not. 
        /// Note : strictly for internal use.. use of it might create problems in multi thread case..
        /// </summary>
        void set_active(const bool p_active);
        using gfx3d_scg_node::Load;
        using gfx3d_scg_node::UnLoad;
        /// <summary>
        /// Loads this scene by creating dynamic contents..
        /// </summary>
        /// <param name="p_lrule">resource loading rule</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        virtual bool Load(const MdlResourceLoadRule p_lrule= MdlResourceLoadRule::All);
        /// <summary>
        /// Unloads this scene by deleting dynamic contents..
        /// </summary>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        virtual bool UnLoad();
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
        /// Returns the load priority. TODO : Unused currently
        /// </summary>
        size_t GetLoadPriority() const;
        /// <summary>
        /// Returns the unload priority. TODO : Unused currently
        /// </summary>
        size_t GetUnLoadPriority() const;
        /// <summary>
        /// Returns true if the scene is active
        /// </summary>
        bool IsActive() const;
        /// <summary>
        /// Returns true if the scene is loaded
        /// </summary>
        bool IsLoaded() const;
        /// <summary>
        /// Returns the scene id or index
        /// </summary>
        size_t GetSceneIndex(void) const;
        /// <summary>
        /// Used by gltf loader. Not intended for application programming
        /// </summary>
        /// <param name="p_index">index of the scene</param>
        inline void set_scene_index(const size_t p_index)
        {
            sceneIndex = p_index;
        }
        /// <summary>
        /// Adds a behaviour to the update method service list.
        /// </summary>
        /// <param name="p_behaviour">behaviour to be added</param>
        /// \see gfx3d_scg_scene::behaviour_update_method_list TODO : fix link
        void AddBehaviourUpdateMethod(rdf_behaviour * const p_behaviour);
        /// <summary>
        /// Services the Update() method of all behaviours
        /// </summary>
        void UpdateBehaviours(void);
        /// <summary>
        /// Adds a behaviour to the start method service list.
        /// </summary>
        /// <param name="p_behaviour">behaviour to be added</param>
        /// \see gfx3d_scg_scene::behaviour_start_method_list TODO : fix link
        void AddBehaviourStartMethod(rdf_behaviour * const p_behaviour);
        /// <summary>
        /// Adds a video player instance to the service list.
        /// </summary>
        /// <param name="p_vplayer">pointer to video player</param>
        void AddBehaviourVideoPlayer(gfxVideoPlayer* const p_vplayer);
        /// <summary>
        /// Services the Start() method of all behaviours
        /// </summary>
        void StartBehaviours(void);
        /// <summary>
        /// Lookup a node by its name and return the pointer to it. If there is none found NULL is returned
        /// </summary>
        /// <param name="p_name">name of the node to be looked up</param>
        /// <returns>returns the pointer to node</returns>
        gfx3d_scg_node* GetNode(const std::string p_name) const;
        /// <summary>
        /// Inserts name and node pair in node_lookup
        /// Note:- invoked internally, do not use this in application.
        /// <param name="p_name">name of The node object</param>
        /// <param name="p_node">pointer to node object</param>
        /// </summary>
        void add_node_in_lookup(const std::string p_name, gfx3d_scg_node* const p_node);
        /// <summary>
        /// Sets the scene as dirty / has property changes
        /// </summary>
        void SetDirty(const size_t p_cullingMask);
        /// <summary>
        /// Checks if the scene as dirty / has property changes
        /// Currently any changes in child nodes, meshes, primitives, materials trigger the flag
        /// </summary>
        bool IsDirty(const size_t p_cullingMask) const;
        /// <summary>
        /// Clear the scene as dirty / has property changes flag
        /// </summary>
        void ClearDirty(const size_t p_cullingMask);
        /// <summary>
        /// Adds the light to scenes light list (called internally)
        /// </summary>
        /// <param name="p_lightnode">light node to be added</param>
        void AddToLightsList(gfx3d_scg_node* const p_lightnode);
        /// <summary>
        /// Get the number of lights in the scene
        /// </summary>
        /// <returns></returns>
        size_t GetLightsCount() const;
        /// <summary>
        /// Gets the light at given index of scene's light list
        /// </summary>
        /// <param name="p_index"></param>
        /// <returns></returns>
        gfx3d_scg_node* GetLight(const size_t p_index) const;
        /// <summary>
        /// Set the camera thats currently going to render the scene to the lights
        /// </summary>
        /// <param name="p_camera">Active camera</param>
        void SetLightActiveCamera(gfx3d_scg_camera* p_camera);
    };
    /// @}
}

#endif