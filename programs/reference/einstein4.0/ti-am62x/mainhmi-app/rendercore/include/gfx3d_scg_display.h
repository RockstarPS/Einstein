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
/// @file gfx3d_scg_display.h
/// @author emanoj1@visteon.com, mpandey@visteon.com
/// @brief GFX3D display object. 
/// A display in rendercore is a collection of scenes. It may not be represeting 
/// a physical display always. It may represent a hardware plane or a window.
/// All active scenes in the display are rendered to the rendertarget configured
/// for the display.
/// Rendercore uses gltf V2.0 as a base standard for 3D data. Infact an extended 
/// gltf called gltf+ remains as the base. Its recomended to understand the
/// gltf specification available at https://github.com/KhronosGroup/glTF/tree/master/specification/2.0
/// and the gltf+ extensions available at https://git.visteon.com/gui/rendercore.maya.plugin/blob/master/docs/gltf+.md
/// @date 11-Sep-2018
/// @copyright © 2019, Visteon Corporation, All Rights Reserved
///////////////////////////////////////////////////////////////////////////////
#ifndef gfx3d_scg_display_h
#define gfx3d_scg_display_h

#include <memory>
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
#include <thread>
#include <mutex>
#endif
#include "gfx3d_scg_loadstatus.h"
#include "workerthread.h"
#include "rc_error_codes.h"
#ifdef RC_CHRONO_FEATURE
#include "rc_physics_engine.h"
#endif

namespace rendercore_engine
{
    /// \ingroup Engine
    /// @{

    /// <summary>
    /// Holds the states of scene loading..
    /// </summary>
    enum class rcScreenLoadSts
    {
        Unloaded,       ///< indicates that the scene is in unloaded state
        Unloading,      ///< indicates that the scene is unloading state (only when multi thread support is present)
        Loading,        ///< indicates that the scene is loading state (only when multi thread support is present)
        Loaded,         ///< indicates that the scene is in loaded state
        Invalid         ///< indicates an error condition
    };
    class gfx3d_scg_depths
    {
    private:
        uint32_t setSceneDepth = 0U;              ///< Used to track recursive child processing by SetScene()
        uint32_t ccSceneDepth = 0U;               ///< Used to track recursive child processing by the copy constructor
        uint32_t sceneCtorDepth = 0U;             ///< Used to track recursive child processing by scene graph construction
    public:
        inline void SetSceneDepth(uint32_t p_val)
        {
            setSceneDepth = p_val;
        }
        inline void SetCCSceneDepth(uint32_t p_val)
        {
            ccSceneDepth = p_val;
        }
        inline void SetCtorSceneDepth(uint32_t p_val)
        {
            sceneCtorDepth = p_val;
        }
        inline uint32_t EnterScene()
        {
            return ++setSceneDepth;
        }
        inline void ExitScene()
        {
            --setSceneDepth;
        }
        inline uint32_t EnterCCScene()
        {
            return ++ccSceneDepth;
        }
        inline void ExitCCScene()
        {
            --ccSceneDepth;
        }
        inline uint32_t EnterCtorScene()
        {
            return ++sceneCtorDepth;
        }
        inline void ExitCtorScene()
        {
            --sceneCtorDepth;
        }
    };
    /// <summary>
	/// Encapsules all the assets required for a display in the rendercore project
	/// </summary>
	class gfx3d_scg_display : public rcErrorReport, public gfx3d_scg_depths
	{
    private:
        /// <summary>
        /// unique identifier for the display object
        /// holds the index of the display, used for identifying the window.
        /// </summary>
        size_t uid = 0U;
        /// <summary>
        /// XY position for the display in pixels
        /// </summary>
        glm::vec2 pos{ 0.0F };
        /// <summary>
        /// Width & Height of the display in pixels
        /// </summary>
        glm::vec2 dim{ 0.0F };
        /// <summary>
        /// describes current elapsed time since start
        /// </summary>
        rc_time timeLine;
        /// <summary>
        /// Index to a rendertarget in rtargets. Render target configuration decides
        /// display size, color depth, MSAA depth size etc for the wndow buffer
	    /// </summary>
        size_t render_target = static_cast<size_t>(SIZE_MAX);
        /// <summary>
        /// List of available rendertargets for this display
        /// </summary>
        std::vector<gfx3d_scg_rtarget *> rtargets;
        /// <summary>
        /// List of accessors available for this display.
	    /// </summary>
        std::vector<gfx3d_scg_accessor *> accessors;    
        /// <summary>
        /// List of bufferViews available for this display.
	    /// </summary>
        std::vector<gfx3d_scg_bufferview *> bufferViews;
        /// <summary>
        /// List of buffers available for this display.
	    /// </summary>
        std::vector<gfx3d_scg_buffer *> buffers;
        /// <summary>
        /// Holds all animations available for this display.
	    /// </summary>
		std::vector <gfx3d_scg_anim *> anims;
        /// <summary>
        /// List of materials
        /// It is possible that a Material (gfx3d_scg_material) can get used by multiple primitives (gfx3d_scg_primitive)
        /// If we would like to make a uniform update to all the primitives sharing same material, then its necessary
        /// to keep a track of those material instances. materials is for that. Each index of this materials array
        /// holds a material group. The material group has the list of instanced material
        /// i.e. if we have 10 materials in the project, then materials array will have a size of 10 as well
        /// each index will then have a material group class, which will hold reference to the material instances. So at index 0
        /// we have a list of all instanced of Material0 and so on..
        /// materials, mat_Lookup and matNameToIdMap are always kept in sync
	    /// </summary>
        std::map<size_t, gfx3d_scg_material_group *> materials;
        /// <summary>
        /// This is just another variation of the materials array. This provides a look up by name option. i.e. we can look up all 
        /// material instances for a material named "car_shader_mat" for example..
        /// materials, mat_Lookup and matNameToIdMap are always kept in sync
	    /// </summary>
        std::map<std::string, gfx3d_scg_material_group *> mat_Lookup;
        /// <summary>
        /// This is just another variation of the materials array. This provides a way to get the index of the material from its name
        /// materials, mat_Lookup and matNameToIdMap are always kept in sync
	    /// </summary>
        std::map <std::string, size_t> matNameToIdMap;
        /// <summary>
        /// Holds all the textures used by this display. A gfx3d_scg_material will be referencing a texture
	    /// </summary>
        std::vector<gfx3d_scg_texture *> textures;
        /// <summary>
        /// Holds all the cube map textures used by this display. A gfx3d_scg_material will be referencing a cube map texture
	    /// </summary>
        std::vector<gfx3d_scg_cmap_texture *> cmap_textures;
        /// <summary>
        /// Holds all the images used by this display. gfx3d_scg_texture will be referencing a image.
	    /// </summary>
        std::vector<gfx3d_scg_image *> images;
        /// <summary>
        /// Holds all the texture samplers used by this display. gfx3d_scg_texture and gfx3d_scg_cmap_texture will be referencing a sampler.
	    /// </summary>
        std::vector<gfx3d_scg_sampler *> samplers;
        /// <summary>
        /// Holds all the cameras used by this display. gfx3d_scg_node will be referencing a camera object
	    /// </summary>
        std::vector<gfx3d_scg_camera *> cameras;
        /// <summary>
        /// Holds an ordered list of camers according to camera render order
        /// </summary>
        std::vector<size_t> orderedCameraIndexes;
        /// <summary>
        /// If the cameras list has changed or a camera render order is changed, then
        /// this flag is set to true indicate that orderedCameras list needs a re calculation
        /// </summary>
        bool bcamOrderChanged = true;
        /// <summary>
        /// Indicates if a new scene is loaded
        /// </summary>
        bool bscenesLoaded = false;
        /// <summary>
        ///< Indicates if the display is dirty and rerender is necessary
        /// </summary>
        bool dispDirty = true;
        /// <summary>
        /// Holds all the skins. TODO : this is yet to be implemented.
	    /// </summary>
        std::vector<gfx3d_scg_skin *> skins;
        /// <summary>
        /// This list holds all the scenes present in this display. A scene is a collection of gfx3d_scg_node following a hierarchical order
	    /// </summary>
        std::vector<gfx3d_scg_scene *> scenes;
        /// <summary>
        /// This list holds all the load status for scenes present in this display.
        /// </summary>
        std::vector<rcScreenLoadSts> sceneLoadStatus;
        /// <summary>
        /// this list acts as a lookup helper to find the node by an index. When ever a node is instanced and attached to the scene hierarchy, its reference
        /// gets added to nodes list as well. So later if someone wants to lookup a node by its index, this nodes array helps to do that.
	    /// </summary>
        std::vector<gfx3d_scg_node*> nodes;
        /// <summary>
        /// List of lights in the project display object
        /// </summary>
        std::vector<gfx3d_scg_light*> lights;
        /// <summary>
        /// this list acts as a lookup helper to find a node in the scene by its name. 
	    /// </summary>
        std::map<std::string, gfx3d_scg_node*> node_Lookup;
        /// <summary>
        /// Handle to a platform window. A platform window is primarily refers to an EGL context where the OpenGL calls can render to.
	    /// </summary>
        rc_generic_ws* window = nullptr;
        /// <summary>
        /// Currently active camera or the camera that is getting rendered (for internal usage)
	    /// </summary>
		size_t activeCameraIndex = static_cast<size_t>(SIZE_MAX);
        /// <summary>
        /// Currently active scene or the scene that is getting rendered (for internal usage)
        /// </summary>
        size_t activeSceneIndex = static_cast<size_t>(SIZE_MAX);
        /// <summary>
        /// This list holds the renderlist. i.e. list of primitives as batches
        /// each batch contains a set of opeque and transparent nodes.
        /// each batch is created based on render states. When the render state changes
        /// a new batch is created in list.
        /// </summary>
        gfx3d_render_list render_list;
        /// <summary>
        /// Points to the parent, which is always a project node
	    /// </summary>
        gfx3d_scg_project * parent = nullptr;		
		rc_input * touchHandler = nullptr;	///< touchHandler pointer 	
#ifdef RC_CHRONO_FEATURE
        rc_physics_engine* physicsEngine = nullptr;   ///< Physics engine pointer
#endif
		/// <summary>
		/// state of the display object
		/// </summary>
		volatile enum class rcDispSts
        {
            Off, ///< indicates that the display is Off state
            Init,///< indicates that the display is initializing (or progressing to On), this state is valid only if multithreading is enabled
            On   ///< indicates that the display initialization is completed & display is ready
        }dispStatus = rcDispSts::Off; ///< rcDispSts object
        /// Specify how the scenes shall manage loading of resources
        MdlResourceLoadRule resourceLoadRule = MdlResourceLoadRule::OnDemand;
        bool bLoaded = false; ///< if true indicates that the display is loaded
        gfx3d_scg_guiskinning* guiSkinning = nullptr;   ///< Pointer to GUI skinning object
        bool isSkinningLoaded = false;                  ///< indicates if skinning data is loaded. 
        gfx3dTexture2D * screenGrabTex2d = nullptr;     ///< Stores the screen grab 
        bool screenGrabReq = false;                     ///< true indicates a screen grab request. And at end of the rendering a grab of the framebuffer is copied to screenGrabTex2d
        rc_render_states renderStates{};                ///< render states specific to this project
        std::string name;               ///< Name of the display
        bool borderLess = false;        ///< A borderless window to be created or not.
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
        WTAsyncTask lRenderAsyncSts{ nullptr }; ///< render task status
        WTAsyncTask lCreateAsyncSts{ nullptr }; ///< display create task status
        mutable std::recursive_mutex data_mutex; ///< to prevent concurrent access to change data within display
        mutable std::recursive_mutex ldsts_mutex;///< to prevent concurrent access to change load status of a scene
#else
        /// <summary>
        /// Used to keep all scene UnLoad requests. Scene unload in single threaded library
        /// cant be performed inline, since if an own script tries to unload a scene
        /// the script object itself will get deleted in the operation and its
        /// dangerous. So all unload requests are buffered and executed when its safe
        /// </summary>
        bool sceneULTaskListActive = false;
        std::map<size_t, std::function<void()>> sceneUnloadtasks;
#endif
        gfx3d_scg_memory_monitor* memoryMonitor = nullptr;
        /// <summary>
        /// Identify the scenes which has a load/unload request issued
        /// Create a list of sorted priority list for the load/unload requests 
        /// returns active scene as a bit mask (bit0 set indicates, scene 0 is active ..)
        /// updates p_load_priolist with the list of priorities provided for the load/unload
        /// </summary>
        bool get_scene_active_scenes_list(std::vector<size_t>& p_active_scenes);
        /// <summary>
        /// prepare the cameras for rendering..
        /// sort the cameras based on their render order in to orderedCameras list
        /// rendering will run the cameras in the sorted order.
        /// lest render order values makes the camera render first.. larger values render last
        /// </summary>
        void prepare_cameras();
        /// <summary>
        /// Sets the load status for passed scene
        /// </summary>
        void setSceneLoadStatus(const size_t p_sceneIndex, const rcScreenLoadSts p_sts);
        /// <summary>
        /// Pushback to a std::vector object with exception handling
        /// <param name="p_list">vector object to which item to be added</param>
        /// <param name="p_obj">object that needs to be added</param>
        /// <returns>-1 if object couldnot be added. else returns the index of abject in p_list</returns>
        /// </summary>
        template<class ObjT>
        inline int32_t pushbackStdVectorObject(std::vector<ObjT>& p_list, const ObjT& p_obj)
        {
            int32_t fl_index = -1;
            try
            {
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
                const std::unique_lock<std::recursive_mutex> fl_lock2(data_mutex);
#endif
                p_list.push_back(p_obj);
                fl_index = static_cast<int32_t>(p_list.size()) - 1;
            }
            catch (...)
            {
                // TODO : Unexpected, report failure.. 
                RcDebugErrorLogId(rc_error_logId::elDispPushBackFailedforList);
            }
            return(fl_index);
        }
        /// <summary>
        /// add item at specified index to a std::vector object with exception handling
        /// <param name="p_index">index at which the object to be placed</param>
        /// <param name="p_object">object that needs to be added</param>
        /// <param name="p_list">vector object to which item to be added</param>
        /// <returns>-1 if object couldnot be added. else the p_index is returned</returns>
        /// </summary>
        template <class ObjT>
        inline bool resizeStdVectorObject(const size_t p_size, std::vector<ObjT>& p_list)
        {
            bool fl_sts = false;
            const size_t fl_csize = p_list.size();
            if (fl_csize != p_size)
            {
                try
                {
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
                    const std::unique_lock<std::recursive_mutex> fl_lock2(data_mutex);
#endif
                    p_list.resize(p_size);
                    fl_sts = true;
                }
                catch (...)
                {
                    // TODO : Unexpected, report failure.. 
                    RcDebugErrorLogId(rc_error_logId::elDispResizeFailedforList);
                }
            }
            return(fl_sts);
        }
        /// <summary>
        /// resize a std::vector object with exception handling
        /// <param name="p_size">new size</param>
        /// <param name="p_list">vector object to which item to be added</param>
        /// <returns>true if resized, false if not</returns>
        /// </summary>
        template <class ObjT>
        inline int32_t addatStdVectorObject(const size_t p_index, const ObjT& p_object, std::vector<ObjT>& p_list)
        {
            int32_t fl_sts = -1;
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
            const std::unique_lock<std::recursive_mutex> fl_lock2(data_mutex);
#endif
            const size_t fl_sindex = p_list.size();
            if (p_index >= p_list.size())
            {
                (void)resizeStdVectorObject((p_index + 1U), p_list);
            }
            const size_t fl_eindex = p_list.size();
            if (p_index < fl_eindex)
            {
                // initialize the extended range with null..
                // as defensive coding..
                // TODO : its value initialized.. is it required?
                for (size_t i = fl_sindex; i < fl_eindex; i++)
                {
                    p_list[p_index] = nullptr;
                }
                p_list[p_index] = p_object;
                fl_sts = static_cast<int32_t>(p_index);
            }
            return fl_sts;
        }
    protected:
        /// Sets the current elapsed time (internally invoked)
        void SetTime(const float32_t p_time);
        /// Resource buffering mode while creating scenegraph objects..
        MdlResourceFetch resourceFetching = MdlResourceFetch::Delayed;
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
        std::recursive_mutex load_mutex; ///< to prevent concurrent Load and Unload Scene requests
#endif
    public:
        /// <summary>
        /// Creates the scenegrapgh for the requested scene id/index.
        /// Actual create is done by inherited loader classes for RDF / GLTF
        /// </summary>
        /// <param name="p_index">index of scene to load</param>
        virtual void CreateScene(const size_t p_index);
        /// <summary>
        /// Creates the animation nodes for all animations.
        /// </summary>
        virtual void CreateAnim();
        /// <summary>
        /// Creates the animation nodes for the requested id/index.
        /// Actual create is done by inherited loader classes for RDF / GLTF
        /// </summary>
        /// <param name="p_index">index of animation to load</param>
        virtual void CreateAnim(const size_t p_index);
        /// <summary>
		/// Constructor for a gfx3d_scg_display class. Base class only performs some data init but it is expected that the
        /// derived class will perform some preperations before a source model gets loaded (e.g. RDF C++ data or gltf+ file)
        /// No time consuming tasks are expected to be performed and that will have to be scheduled in the Create() method.
		/// </summary>
		gfx3d_scg_display(gfx3d_scg_project* const p_proj);
		/// <summary>
		/// Destructor for a gfx3d_scg_display class.
		/// </summary>
		virtual ~gfx3d_scg_display();
        gfx3d_scg_display& operator= (const gfx3d_scg_display&) = delete;
        gfx3d_scg_display(const gfx3d_scg_display&) = delete;
        /// <summary>
		/// Returns the culling mask to be used. Basically this is returned from the active camera thats getting
        /// rendered currently. This culling mask gets ANDed with nodes culling mask to determine if a node needs 
        /// to get rendered or not.
		/// </summary>
		/// <returns>returns the current culling mask</returns>
        size_t GetCullingMask(void) const;
		/// <summary>
		/// Lookup a node by its name and return the pointer to it. If there is none found NULL is returned
		/// </summary>
		/// <param name="p_name">name of the node to be looked up</param>
		/// <returns>returns the pointer to node</returns>
		gfx3d_scg_node * GetNode(const std::string p_name);
        /// <summary>
        /// Lookup a node by its name in active scenes and return the pointer to it, if found. 
        ///  - Pointer from first scene which has the node is returned
        ///  - If there is none found NULL is returned
        /// </summary>
        /// <param name="p_name">name of the node to be looked up</param>
        /// <returns>returns the pointer to node</returns>
        gfx3d_scg_node* GetNodeFromScenes(const std::string p_name);
		/// <summary>
		/// Lookup a node by its index and return the pointer to it. If there is none found NULL is returned
		/// </summary>
		/// <param name="p_index">Index of the node to be looked up</param>
		/// <returns>returns the pointer to node</returns>
        gfx3d_scg_node * GetNode(const int32_t p_index);
		/// <summary>
		/// Set the position (p_x, p_y) for the project
		/// </summary>
		/// <param name="p_x">new x position for project</param>
		/// <param name="p_y">new y position for project</param>
		/// \see rendercore_engine::gfx3d_scg_project::SetPosition()
		void SetPosition(const float32_t p_x, const float32_t p_y);
		/// <summary>
		/// Set the position (pos) of the display window
		/// </summary>
		/// <param name="p_pos">new dposition (p_pos) of the display window</param>
		/// \see rendercore_engine::gfx3d_scg_project::SetPosition()
		void SetPosition(const glm::vec2 p_pos);
        /// <summary>
		/// Set the dimension (p_width, p_height) for the display
		/// </summary>
		/// <param name="p_width">new width for the project</param>
		/// <param name="p_height">new height for the project</param>
		/// \see rendercore_engine::gfx3d_scg_project::SetDimension()
		void SetDimension(const float32_t p_width, const float32_t p_height);
		/// <summary>
		/// Set the dimension (p_dim) for the display
		/// </summary>
		/// <param name="p_dim">new dimensions for the project</param>
		/// \see rendercore_engine::gfx3d_scg_project::SetDimension()
		void SetDimension(const glm::vec2 p_dim);
        /// <summary>
        /// Get the position (pos) for the project
        /// <returns>returns the position of the display window</returns>
        /// </summary>
        glm::vec2 GetPosition() const;
        /// <summary>
        /// Get the dimension (p_dim) for the display
        /// </summary>
        /// <returns>returns the dimetion width & height of the display</returns>
        /// \see rendercore_engine::gfx3d_scg_project::SetDimension()
        glm::vec2 GetDimension(void) const;
        /// <summary>
		/// pre render loop for the display. Does preperation work
		/// </summary>
		void pre_render(const std::vector<size_t>& p_active_scenes);
        /// <summary>
		/// render loop for the display. Does pre_render and then render work
        /// <param name="p_onChange">If false rendering happens on every call. If true then rendering happens only if a change is detected. Refer http://uxcoc.visteon.com/docs/#/rendercore/rendercore On Change Rendering section for more details</param>
        /// </summary>
		void render(const bool p_onChange);
		/// <summary>
		/// Returns the font at passed index. Returns NULL if the index is invalid
		/// </summary>
		/// <param name="p_index">font index to be retrived</param>
		/// <returns>returns the font pointer</returns>
		gfx3d_scg_font* GetFont(const size_t p_index) const;
		/// <summary>
		/// Returns the maximum animation time for all animations.
		/// </summary>
		/// <returns>maximum keyin for all animations</returns>
		GLfloat GetMaxAnimKeyin(void) const;
		/// <summary>
		/// Returns the camera parameters of the active OpenGL camera.
		/// </summary>
		/// <returns>pointer to camera</returns>
		gfx3d_scg_camera * GetActiveCamera(void) const;
		/// <summary>
		/// Select the camera at passed index as Active and also returns pointer to it
		/// </summary>
		/// <param name="p_index">camera index to be set as active</param>
		/// <returns>pointer to camera</returns>
        gfx3d_scg_camera * SetActiveCamera(const size_t p_idx, const MdlRenderPassStage p_rpstage);
		/// <summary>
		/// Check if the camera at passed index is Active or not
		/// </summary>
		/// <param name="p_index">camera index to be set as active</param>
		/// <returns>returns true if passed camera index is the currently active camera</returns>
        bool IsActiveCamera(const size_t p_index) const;
        /// <summary>
        /// If any of the cameras render order is changed or a new camera is added/removed in scene
        /// this API sets a flag to indicate that a new camera render sequence to be derived.
        /// Call to this API is managed internally so its not necessary for an application
        /// to call this API.
        /// </summary>
        void SetCameraOrderChanged();
		/// <summary>
		/// Returns the camera at passed index
		/// </summary>
		/// <param name="p_index">camera index to be retreived</param>
		/// <returns>pointer to camera</returns>
        gfx3d_scg_camera * GetCamera(const size_t p_idx) const;
		/// <summary>
		/// Adds the material instance to the materal group (material_group) at the passed material index
		/// </summary>
		/// <param name="p_mat_index">material index</param>
		/// <param name="p_material">material instance pointer</param>
        void AddMaterialInstance(const size_t p_mat_index, gfx3d_scg_material* const p_material);
		/// <summary>
		/// Gets the material instance at the passed index
		/// </summary>
		/// <param name="p_matIndex">material index</param>
		/// <returns>pointer to material</returns>
        gfx3d_scg_material * GetMaterial(const int32_t p_matIndex) const;
		/// <summary>
		/// Gets the material group by material name
		/// </summary>
		/// <param name="p_name">name of material</param>
		/// <returns>pointer to material group</returns>
        gfx3d_scg_material_group * GetMaterial(const std::string p_name) const;
        /// <summary>
        /// Gets the total number of materials in the list
        /// </summary>
        /// <returns>returns total number of materials</returns>
        size_t GetNumOfMaterials(void) const;
		/// <summary>
		/// call to register the user vent callback to receive mouse, touch and key events..
        /// call after the display is opened, else will return false..
        /// </summary>
		/// <param name="p_uevnt_cb">pointer to callback function</param>
		/// <returns>true if the call is success</returns>
		bool RegisterUserEventCb(IRcWinUserEventCbSp p_uevnt_cb);
		/// <summary>
		/// Creates the display by performing creation of native window and EGL contexts
        /// required for the display
        /// </summary>
        /// <param name="p_pwin">platform window handle</param>
        virtual void Create(std::shared_ptr<rc_platform_window> p_pwin);
        /// <summary>
        /// To be invoked when a native window change is detected by application
        /// Triggers new EGL surface creation for the new native window.
        /// Notes:-
        /// 1. rc_platform_window::GetNativeWindow() will be invoked
        /// to read the new native window, so application must ensure to return the
        /// new native window
        /// 2. This is a blocking call and returns after the window change is completed
        /// </summary>
        void OnNativeWindowChange(void);
        /// <summary>
        /// Loads all the assets required for all the scenes in the display
        /// Note: to be invoked after a Create(). 
        ///       For individual scene by scene loading use LoadScene / LoadSceneAsync instead
        ///       a load request is honoured only if the scene is in rcScreenLoadSts::Unloaded state
        /// </summary>
        /// <param name="p_mode">load mode selection sync or async</param>
        /// <returns>true if the call is success</returns>
        bool Load(const MdlAssetLoadMode p_mode);
        /// <summary>
        /// Unloads all the assets used by all the scenes in the display
        /// Note: For individual scene by scene unloading use UnloadScene or UnloadSceneAsync instead
        ///       a unload request is honoured only if the scene is in rcScreenLoadSts::Loaded state
        /// </summary>
        void UnLoad(void);
        /// <summary>
        /// Loads all the animations in the display. This is invoked internally if 
        /// bool Load(MdlAssetLoadMode p_mode) API is used.
        /// </summary>
        void LoadAnims(void) const;
        /// <summary>
        /// Load the specified animation in the display by its ID.
        /// </summary>
        /// <param name="p_sceneIndex">scene id/index which requires the animation</param>
        /// <param name="p_animIndex">animation id/index to be loaded</param>
        void LoadAnim(size_t p_sceneIndex, const size_t p_animIndex) const;
        /// <summary>
        /// UnLoads all the animations in the display. This is invoked internally if 
        /// void UnLoad(void) API is used.
        /// </summary>
        void UnLoadAnims(void) const;
        /// <summary>
        /// UnLoad the specified animation in the display by its ID.
        /// </summary>
        /// <param name="p_sceneIndex">scene id/index which requires the animation</param>
        /// <param name="p_animIndex">animation id/index to be loaded</param>
        void UnLoadAnim(size_t p_sceneIndex, const size_t p_animIndex) const;
        /// <summary>
        /// Loads specified scene by name
        /// Note: to be invoked after a Create(). 
        ///       a load request is honoured only if the scene is in rcScreenLoadSts::Unloaded state
        /// </summary>
        /// <param name="p_sceneName">scene name</param>
        /// <param name="p_mode">load mode selection single or additive</param>
        /// <param name="p_assetMode">asset mode selection sync or async</param>
        void LoadScene(const std::string p_sceneName, const MdlSceneLoadMode p_mode = MdlSceneLoadMode::Single, const MdlAssetLoadMode p_assetMode = MdlAssetLoadMode::Synchronous);
        /// <summary>
        /// Loads specified scene by its id / index
        /// Note: to be invoked after a Create(). 
        ///       a load request is honoured only if the scene is in rcScreenLoadSts::Unloaded state
        /// </summary>
        /// <param name="p_sceneIndex">scene id/index</param>
        /// <param name="p_sceneMode">load mode selection single or additive</param>
        /// <param name="p_assetMode">asset mode selection sync or async</param>
        void LoadScene(const size_t p_sceneIndex, const MdlSceneLoadMode p_sceneMode = MdlSceneLoadMode::Single, const MdlAssetLoadMode p_assetMode = MdlAssetLoadMode::Synchronous);
        /// <summary>
        /// Loads specified scene by name asynchronously (valid only when multi thread is enabled, else its sync)
        /// Note: to be invoked after a Create(). 
        ///       a load request is honoured only if the scene is in rcScreenLoadSts::Unloaded state
        /// </summary>
        /// <param name="p_sceneName">scene name</param>
        /// <param name="p_mode">load mode selection single or additive</param>
        /// <returns>rc_sceneload_sts object to track the loading status by caller</returns>
        rc_sceneload_sts LoadSceneAsync(const std::string p_sceneName, const MdlSceneLoadMode p_mode = MdlSceneLoadMode::Single);
        /// <summary>
        /// Loads specified scene by its id/index asynchronously (valid only when multi thread is enabled, else its sync)
        /// Note: to be invoked after a Create(). 
        ///       a load request is honoured only if the scene is in rcScreenLoadSts::Unloaded state
        /// </summary>
        /// <param name="p_sceneIndex">scene id/index</param>
        /// <param name="p_mode">load mode selection single or additive</param>
        /// <returns>rc_sceneload_sts object to track the loading status by caller</returns>
        rc_sceneload_sts LoadSceneAsync(const size_t p_sceneIndex, const MdlSceneLoadMode p_mode = MdlSceneLoadMode::Single);
        /// <summary>
        /// Un Loads specified scene by its name asynchronously (valid only when multi thread is enabled, else its sync)
        /// Note: to be invoked after a Create(). 
        ///       a unload request is honoured only if the scene is in rcScreenLoadSts::Loaded state
        /// </summary>
        /// <param name="p_sceneName">scene name</param>
        /// <returns>rc_sceneload_sts object to track the loading status by caller</returns>
        rc_sceneload_sts UnloadSceneAsync(const std::string p_sceneName);
        /// <summary>
        /// Un Loads specified scene by its id / index asynchronously (valid only when multi thread is enabled, else its sync)
        /// Note: to be invoked after a Create(). 
        ///       a unload request is honoured only if the scene is in rcScreenLoadSts::Loaded state
        /// </summary>
        /// <param name="p_sceneIndex">scene id/index</param>
        /// <returns>rc_sceneload_sts object to track the loading status by caller</returns>
        rc_sceneload_sts UnloadSceneAsync(const size_t p_sceneIndex);
        /// <summary>
        /// Un Loads specified scene by its name sync/async-hronously (valid only when multi thread is enabled, else its sync)
        /// Note: to be invoked after a Create(). 
        ///       a unload request is honoured only if the scene is in rcScreenLoadSts::Loaded state
        ///       May throw std::bad_alloc exception
        /// </summary>
		/// <param name="p_sceneIndex">scene name</param>
		/// <param name="p_mode">asset load mode</param>
		/// <returns>rc_sceneload_sts object to track the loading status by caller</returns>
        rc_sceneload_sts UnloadScene(const size_t p_sceneIndex, const MdlAssetLoadMode p_mode);
        /// <summary>
        /// looks up the scene by its name and returns its id/index (implemented by inherited rdf/gltf loader class)
        /// </summary>
        /// <param name="p_sceneName">scene name</param>
        /// <returns>id/index of the scene</returns>
        virtual size_t LookupScene(const std::string p_sceneName);
        /// <summary>
		/// Uniform Set APIs for material. 
        /// Uses the material group and sets the uniform to all instances of material. (geta reflected to all instances)
		/// </summary>
		/// <param name="p_mat_index">index of the material to set</param>
		/// <param name="p_uniform">name of the uniform to set</param>
		/// <param name="p_value">value to be set to the uniform</param>
		void MatSet(const size_t p_mat_index, const std::string p_uniform, const float64_t p_value);
		/// <summary>
		/// Uniform Set APIs for material. 
        /// Uses the material group and sets the uniform to all instances of material. (geta reflected to all instances)
		/// </summary>
		/// <param name="p_mat_index">index of the material to set</param>
		/// <param name="p_uniform">name of the uniform to set</param>
		/// <param name="p_value">value to be set to the uniform</param>
        void MatSet(const size_t p_mat_index, const std::string p_uniform, const float32_t p_value);
		/// <summary>
		/// Uniform Set APIs for material. 
        /// Uses the material group and sets the uniform to all instances of material. (geta reflected to all instances)
		/// </summary>
		/// <param name="p_mat_index">index of the material to set</param>
		/// <param name="p_uniform">name of the uniform to set</param>
		/// <param name="p_value">value to be set to the uniform</param>
        void MatSet(const size_t p_mat_index, const std::string p_uniform, const int32_t p_value);
		/// <summary>
		/// Uniform Set APIs for material. 
        /// Uses the material group and sets the uniform to all instances of material. (geta reflected to all instances)
		/// </summary>
		/// <param name="p_mat_index">index of the material to set</param>
		/// <param name="p_uniform">name of the uniform to set</param>
		/// <param name="p_value">value to be set to the uniform</param>
        void MatSet(const size_t p_mat_index, const std::string p_uniform, const glm::vec2 p_value);
		/// <summary>
		/// Uniform Set APIs for material. 
        /// Uses the material group and sets the uniform to all instances of material. (geta reflected to all instances)
		/// </summary>
		/// <param name="p_mat_index">index of the material to set</param>
		/// <param name="p_uniform">name of the uniform to set</param>
		/// <param name="p_value">value to be set to the uniform</param>
        void MatSet(const size_t p_mat_index, const std::string p_uniform, const glm::vec3 p_value);
		/// <summary>
		/// Uniform Set APIs for material. 
        /// Uses the material group and sets the uniform to all instances of material. (geta reflected to all instances)
		/// </summary>
		/// <param name="p_mat_index">index of the material to set</param>
		/// <param name="p_uniform">name of the uniform to set</param>
		/// <param name="p_value">value to be set to the uniform</param>
        void MatSet(const size_t p_mat_index, const std::string p_uniform, const glm::vec4 p_value);
		/// <summary>
		/// Uniform Set APIs for material. 
        /// Uses the material group and sets the uniform to all instances of material. (geta reflected to all instances)
		/// </summary>
		/// <param name="p_mat_name">name of the material to set</param>
		/// <param name="p_uniform">name of the uniform to set</param>
		/// <param name="p_value">value to be set to the uniform</param>
        void MatSet(const std::string p_mat_name, const std::string p_uniform, const float32_t p_value);
		/// <summary>
		/// Uniform Get APIs by material index. 
        /// Returns the value from the first material in the material group
		/// </summary>
		/// <param name="p_mat_index">index of the material to set</param>
		/// <param name="p_uniform">name of the uniform to set</param>
		/// <returns>current value held by the uniform</returns>
        float32_t MatGet(const size_t p_mat_index, const std::string p_uniform) const;
		/// <summary>
		/// Uniform Get APIs by material index. 
        /// Returns the value from the first material in the material group
		/// </summary>
		/// <param name="p_mat_index">index of the material to set</param>
		/// <param name="p_uniform">name of the uniform to set</param>
		/// <returns>current value held by the uniform</returns>
        glm::vec2 MatGetv2(const size_t p_mat_index, const std::string p_uniform) const;
		/// <summary>
		/// Uniform Get APIs by material index. 
        /// Returns the value from the first material in the material group
		/// </summary>
		/// <param name="p_mat_index">index of the material to set</param>
		/// <param name="p_uniform">name of the uniform to set</param>
		/// <returns>current value held by the uniform</returns>
        glm::vec3 MatGetv3(const size_t p_mat_index, const std::string p_uniform) const;
		/// <summary>
		/// Uniform Get APIs by material index. 
        /// Returns the value from the first material in the material group
		/// </summary>
		/// <param name="p_mat_index">index of the material to set</param>
		/// <param name="p_uniform">name of the uniform to set</param>
		/// <returns>current value held by the uniform</returns>
        glm::vec4 MatGetv4(const size_t p_mat_index, const std::string p_uniform) const;
		/// <summary>
		/// Uniform Get APIs by material index. 
        /// Returns the value from the first material in the material group
		/// </summary>
		/// <param name="p_mat_index">index of the material to set</param>
		/// <param name="p_uniform">name of the uniform to set</param>
		/// <returns>current value held by the uniform</returns>
        int32_t MatGeti(const size_t p_mat_index, const std::string p_uniform) const;
		/// <summary>
		/// Uniform Get APIs by material index. 
        /// Returns the value from the first material in the material group
		/// </summary>
		/// <param name="p_mat_index">index of the material to set</param>
		/// <param name="p_uniform">name of the uniform to set</param>
		/// <returns>current value held by the uniform</returns>
        float64_t MatGetd(const size_t p_mat_index, const std::string p_uniform) const;
		/// <summary>
		/// Uniform Get APIs by material name. 
        /// Returns the value from the first material in the material group
		/// </summary>
		/// <param name="p_mat_name">name of the material to set</param>
		/// <param name="p_uniform">name of the uniform to set</param>
		/// <returns>current value held by the uniform</returns>
        float32_t MatGet(const std::string p_mat_name, const std::string p_uniform) const;
		/// <summary>
		/// Uniform Get APIs by material name. 
        /// Returns the value from the first material in the material group
		/// </summary>
		/// <param name="p_mat_name">name of the material to set</param>
		/// <param name="p_uniform">name of the uniform to set</param>
		/// <returns>current value held by the uniform</returns>
        glm::vec2 MatGetv2(const std::string p_mat_name, const std::string p_uniform) const;
		/// <summary>
		/// Uniform Get APIs by material name. 
        /// Returns the value from the first material in the material group
		/// </summary>
		/// <param name="p_mat_name">name of the material to set</param>
		/// <param name="p_uniform">name of the uniform to set</param>
		/// <returns>current value held by the uniform</returns>
        glm::vec3 MatGetv3(const std::string p_mat_name, const std::string p_uniform) const;
		/// <summary>
		/// Uniform Get APIs by material name. 
        /// Returns the value from the first material in the material group
		/// </summary>
		/// <param name="p_mat_name">name of the material to set</param>
		/// <param name="p_uniform">name of the uniform to set</param>
		/// <returns>current value held by the uniform</returns>
        glm::vec4 MatGetv4(const std::string p_mat_name, const std::string p_uniform) const;
		/// <summary>
		/// Uniform Get APIs by material name. 
        /// Returns the value from the first material in the material group
		/// </summary>
		/// <param name="p_mat_name">name of the material to set</param>
		/// <param name="p_uniform">name of the uniform to set</param>
		/// <returns>current value held by the uniform</returns>
        int32_t MatGeti(const std::string p_mat_name, const std::string p_uniform) const;
		/// <summary>
		/// Uniform Get APIs by material name. 
        /// Returns the value from the first material in the material group
		/// </summary>
		/// <param name="p_mat_name">name of the material to set</param>
		/// <param name="p_uniform">name of the uniform to set</param>
		/// <returns>current value held by the uniform</returns>
        float64_t MatGetd(const std::string p_mat_name, const std::string p_uniform) const;
		/// <summary>
		/// Returns the freerunning timer value in seconds
		/// </summary>
		/// <returns>elapsed timer value in seconds</returns>
        float32_t GetFRTimerValue(void) const;
		/// <summary>
		/// Returns the freerunning timer count in milliseconds
		/// </summary>
		/// <returns>elapsed timer count in milliseconds</returns>
        uint64_t GetFRTimerCountMS(void) const;
		/// <summary>
		/// Returns the current fps
		/// </summary>
		/// <returns>returns fps</returns>
        float32_t GetFps(void) const;
        /// <summary>
        /// Returns the average fps
        /// </summary>
        /// <returns>returns fps</returns>
        float32_t GetAverageFps(void) const;
		/// <summary>
		/// Returns the average frame duration
		/// </summary>
		/// <returns>returns fl_frame_duration</returns>
		float32_t GetFrameDuration(void) const;
		/// <summary>
		/// Returns the number of frames rendered so far
		/// </summary>
		/// <returns>returns frame count</returns>
        uint64_t GetFrameCounter(void) const;
		// need to move this to animation controller
		/// <summary>
		/// Find animation by name
		/// <param name="p_animName">name of animation</param>
		/// </summary>
		gfx3d_scg_anim *FindAnimation(const std::string p_animName, const size_t p_arrachedNode=SIZE_MAX) const;
        /// <summary>
        /// Sets the display uid
        /// <param name="p_uid">id to be set for the display</param>
        /// </summary>
        void SetUID(const size_t p_uid);
        /// <summary>
        /// Gets the display uid
        /// </summary>
        size_t GetUID() const;
        /// <summary>
        /// Set platform window for this display
        /// <param name="p_window">pointer to the window</param>
        /// </summary>
        void SetWindow(rc_generic_ws* const p_window);
        /// <summary>
        /// Set platform window for this display
        /// </summary>
        rc_generic_ws* GetWindow(void) const;
        /// <summary>
        /// Set parent project pointer
        /// <param name="p_parent">pointer to the parent project</param>
        /// </summary>
        void SetParent(gfx3d_scg_project* const p_parent);
        /// <summary>
        /// Get pointer to parent project
        /// </summary>
        /// <returns>Pointer to parent project</returns>
        gfx3d_scg_project* GetParent() const;
        /// <summary>
        /// Set render target index
        /// <param name="p_render_target">render target index</param>
        /// </summary>
        void SetRenderTarget(const size_t p_render_target);
        /// <summary>
        /// Get render target index
        /// </summary>
        /// <returns>Returns the render target index</returns>
        size_t GetRenderTarget() const;
        /// <summary>
        /// Add a rendertarget in List of rendertargets available for this display
        /// <param name="p_rt">pointer to a render target</param>
        /// </summary>
        /// <returns>returns render target index</returns>
        int32_t AddRenderTarget(gfx3d_scg_rtarget * const p_rt);
        /// <summary>
        /// Add a accessor in List of accessors
        /// <param name="p_accessor">pointer to a accessor</param>
        /// </summary>
        /// <returns>returns accessor index</returns>
        int32_t AddAccessor(gfx3d_scg_accessor * const p_accessor);
        /// <summary>
        /// Add a buffer in List of buffers
        /// <param name="p_buffer">pointer to a buffer</param>
        /// </summary>
        /// <returns>returns buffer index</returns>
        int32_t AddBuffer(gfx3d_scg_buffer * const p_buffer);
        /// <summary>
        /// Add a bufferView in List of bufferViews
        /// <param name="p_bufferView">pointer to a bufferView</param>
        /// </summary>
        /// <returns>returns bufferView index</returns>
        int32_t AddBufferView(gfx3d_scg_bufferview * const p_bufferView);
        /// <summary>
        /// Add a camera in List of cameras
        /// <param name="p_camera">pointer to a camera</param>
        /// </summary>
        /// <returns>returns camera index</returns>
        int32_t AddCamera(gfx3d_scg_camera * const p_camera);
        /// <summary>
        /// Add a image in List of images
        /// <param name="p_image">pointer to a image</param>
        /// </summary>
        /// <returns>returns image index</returns>
        int32_t AddImage(gfx3d_scg_image * const p_image);
        /// <summary>
        /// Add a sampler in List of samplers
        /// <param name="p_sampler">pointer to a sampler</param>
        /// </summary>
        /// <returns>returns sampler index</returns>
        int32_t AddSampler(gfx3d_scg_sampler * const p_sampler);
        /// <summary>
        /// Add a texture in List of textures
        /// <param name="p_texture">pointer to a texture</param>GetAnimations()
        /// </summary>
        /// <returns>returns texture index</returns>
        int32_t AddTexture(gfx3d_scg_texture * const p_texture);
        /// <summary>
        /// Add a cubemap texture in List of cubemap textures
        /// <param name="p_texture">pointer to a cubemap texture</param>
        /// </summary>
        /// <returns>returns cmap texture index</returns>
        int32_t AddCmapTexture(gfx3d_scg_cmap_texture * const p_texture);
        /// <summary>
        /// Add a animation in List of animations
        /// <param name="p_anim">pointer to a anim data</param>
        /// </summary>
        /// <returns>returns anim index</returns>
        int32_t AddAnimation(gfx3d_scg_anim* const p_anim);
        /// <summary>
        /// Add a skin to List of skins
        /// <param name="p_skin">pointer to a skin data</param>
        /// </summary>
        /// <returns>returns added skin index</returns>
        int32_t AddSkin(gfx3d_scg_skin * const p_skin);
        /// <summary>
        /// Add a light to List of lights
        /// <param name="p_light">pointer to a light data</param>
        /// </summary>
        /// <returns>returns added light index</returns>
        int32_t AddLight(gfx3d_scg_light* const p_light);
        /// <summary>
        /// Add a nodes in List of nodes
        /// <param name="p_node">pointer to a node data</param>
        /// </summary>
        /// <returns>returns node index</returns>
        int32_t AddNode(gfx3d_scg_node* const p_node);
        /// <summary>
        /// Add a primitive in render list
        /// <param name="p_node">pointer to node</param>
        /// <param name="p_prim">pointer to primitive</param>
        /// </summary>
        /// <returns>returns true on success</returns>
        bool AddToRenderList(gfx3d_scg_node* const p_node, gfx3d_scg_primitive* const p_prim);
        /// <summary>
        /// Add an empty node in render list (used only for touch enabled node).
        /// <param name="p_node">pointer to node</param>
        /// </summary>
        /// <returns>returns true on success</returns>
        bool AddToRenderList(gfx3d_scg_node* const p_node);
        /// <summary>
        /// Add a rendertarget in List of rendertargets available for this display
        /// <param name="p_index">index at which pointer will be added in the list</param>
        /// <param name="p_rt">pointer to a render target</param>
        /// </summary>
        /// <returns>returns render target index</returns>
        int32_t AddRenderTarget(const size_t p_index, gfx3d_scg_rtarget* const p_render_target);
        /// <summary>
        /// Add a accessor in List of accessors
        /// <param name="p_index">index at which pointer will be added in the list</param>
        /// <param name="p_accessor">pointer to a accessor</param>
        /// </summary>
        /// <returns>returns accessor index</returns>
        int32_t AddAccessor(const size_t p_index, gfx3d_scg_accessor* const p_accessor);
        /// <summary>
        /// Add a animation in List of animations
        /// <param name="p_index">index at which pointer will be added in the list</param>
        /// <param name="p_anim">pointer to a animation</param>
        /// </summary>
        /// <returns>returns animation index</returns>
        int32_t AddAnimation(const size_t p_index, gfx3d_scg_anim* const p_anim);
        /// <summary>
        /// Add a buffer in List of buffers
        /// <param name="p_index">index at which pointer will be added in the list</param>
        /// <param name="p_buffer">pointer to a buffer</param>
        /// </summary>
        /// <returns>returns buffer index</returns>
        int32_t AddBuffer(const size_t p_index, gfx3d_scg_buffer * const p_buffer);
        /// <summary>
        /// Add a bufferview in List of bufferviews
        /// <param name="p_index">index at which pointer will be added in the list</param>
        /// <param name="p_bufferView">pointer to a bufferview</param>
        /// </summary>
        /// <returns>returns bufferView index</returns>
        int32_t AddBufferView(const size_t p_index, gfx3d_scg_bufferview * const p_bufferView);
        /// <summary>
        /// Add a camera in List of cameras
        /// <param name="p_index">index at which pointer will be added in the list</param>
        /// <param name="p_camera">pointer to a camera</param>
        /// </summary>
        /// <returns>returns camera index</returns>
        int32_t AddCamera(const size_t p_index, gfx3d_scg_camera * const p_camera);
        /// <summary>
        /// Add a image in List of images
        /// <param name="p_index">index at which pointer will be added in the list</param>
        /// <param name="p_image">pointer to a image</param>
        /// </summary>
        /// <returns>returns image index in image list</returns>
        int32_t AddImage(const size_t p_index, gfx3d_scg_image * const p_image);
        /// <summary>
        /// Add a sampler in List of samplers
        /// <param name="p_index">index at which pointer will be added in the list</param>
        /// <param name="p_sampler">pointer to a sampler</param>
        /// </summary>
        /// <returns>returns sampler index in sampler list</returns>
        int32_t AddSampler(const size_t p_index, gfx3d_scg_sampler * const p_sampler);
        /// <summary>
        /// Add a texture in List of textures
        /// <param name="p_index">index at which pointer will be added in the list</param>
        /// <param name="p_texture">pointer to a texture</param>
        /// </summary>
        /// <returns>returns texture index in texture list</returns>
        int32_t AddTexture(const size_t p_index, gfx3d_scg_texture * const p_texture);
        /// <summary>
        /// Add a cubemap texture in List of cubemap textures
        /// <param name="p_index">index at which pointer will be added in the list</param>
        /// <param name="p_texture">pointer to a cmap texture</param>
        /// </summary>
        /// <returns>returns cubemap texture index in cubemap texture list</returns>
        int32_t AddCmapTexture(const size_t p_index, gfx3d_scg_cmap_texture * const p_cmap_texture);
        /// <summary>
        /// Add a scene in List of scenes
        /// <param name="p_index">index at which pointer will be added in the list</param>
        /// <param name="p_scene">pointer to a scene</param>
        /// </summary>
        /// <returns>returns scene index in scenes list</returns>
        int32_t AddScene(const size_t p_index, gfx3d_scg_scene * const p_scene);
        /// <summary>
        /// Add a node in List of nodes
        /// <param name="p_index">index at which pointer will be added in the list</param>
        /// <param name="p_node">pointer to a node</param>
        /// </summary>
        /// <returns>returns node index in nodes list</returns>
        int32_t AddNode(const size_t p_index, gfx3d_scg_node * const p_node);
        /// <summary>
        /// Add a skin to List of skins at specified index
        /// <param name="p_index">index at which pointer will be added in the list</param>
        /// <param name="p_skin">pointer to a skin data</param>
        /// </summary>
        /// <returns>returns added skin index</returns>
        int32_t AddSkin(const size_t p_index, gfx3d_scg_skin * const p_skin);
        /// <summary>
        /// Add a light to List of lights at specified index
        /// <param name="p_index">index at which pointer will be added in the list</param>
        /// <param name="p_skin">pointer to a light data</param>
        /// </summary>
        /// <returns>returns added skin index</returns>
        int32_t AddLight(const size_t p_index, gfx3d_scg_light* const p_light);
        /// <summary>
        /// Resizes the scene count of scenes List
        /// <param name="p_size">size to resize the list</param>
        /// </summary>
        void ResizeRenderTarget(const size_t p_size);
        /// <summary>
        /// Resizes the accessor count of accessors List
        /// <param name="p_size">size to resize the list</param>
        /// </summary>
        void ResizeAccessorList(const size_t p_size);
        /// <summary>
        /// Resizes the animation count of animation List
        /// <param name="p_size">size to resize the list</param>
        /// </summary>
        void ResizeAnimationsList(const size_t p_size);
        /// <summary>
        /// Resizes the buffer count of buffers List
        /// <param name="p_size">size to resize the list</param>
        /// </summary>
        void ResizeBufferList(const size_t p_size);
        /// <summary>
        /// Resizes the bufferview count of bufferview List
        /// <param name="p_size">size to resize the list</param>
        /// </summary>
        void ResizeBufferViewList(const size_t p_size);
        /// <summary>
        /// Resizes the texture count of textures List
        /// <param name="p_size">size to resize the list</param>
        /// </summary>
        void ResizeTextureList(const size_t p_size);
        /// <summary>
        /// Resizes the image count of images List
        /// <param name="p_size">size to resize the list</param>
        /// </summary>
        void ResizeImageList(const size_t p_size);
        /// <summary>
        /// Resizes the sampler count of samplers List
        /// <param name="p_size">size to resize the list</param>
        /// </summary>
        void ResizeSamplerList(const size_t p_size);
        /// <summary>
        /// Resizes the camera count of cameras List
        /// <param name="p_size">size to resize the list</param>
        /// </summary>
        void ResizeCameraList(const size_t p_size);
        /// <summary>
        /// Resizes the skin count of skins List
        /// <param name="p_size">size to resize the list</param>
        /// </summary>
        void ResizeSkinList(const size_t p_size);
        /// <summary>
        /// Resizes the light count of lights List
        /// <param name="p_size">size to resize the list</param>
        /// </summary>
        void ResizeLightList(const size_t p_size);
        /// <summary>
        /// Resizes the cmaptexture count of cmaptextures List
        /// <param name="p_size">size to resize the list</param>
        /// </summary>
        void ResizeCmapTextureList(const size_t p_size);
        /// <summary>
        /// Resizes the node count of nodes List
        /// <param name="p_size">size to resize the list</param>
        /// </summary>
        void ResizeNodeList(const size_t p_size);
        /// <summary>
        /// Resizes the scene count of scenes List
        /// <param name="p_size">size to resize the list</param>
        /// </summary>
        void ResizeSceneList(const size_t p_size);
        /// <summary>
        /// Get number of scenes in display
        /// </summary>
        /// <returns>returns scene count in scenes</returns>
        size_t GetSceneSize() const;
        /// <summary>
        /// Get number of render targets in display
        /// <returns>returns render targets count in display</returns>
        /// </summary>
        size_t GetRenderTargetsSize(void) const;
        /// <summary>
        /// Get number of Accessors in display
        /// <returns>returns Accessors count in display</returns>
        /// </summary>
        size_t GetAccessorsSize(void) const;
        /// <summary>
        /// Get number of Buffers in display
        /// <returns>returns Buffers count in display</returns>
        /// </summary>
        size_t GetBuffersSize(void) const;
        /// <summary>
        /// Get number of BufferViews in display
        /// <returns>returns BufferViews count in display</returns>
        /// </summary>
        size_t GetBufferViewsSize(void) const;
        /// <summary>
        /// Get number of Textures in display
        /// <returns>returns Textures count in display</returns>
        /// </summary>
        size_t GetTexturesSize(void) const;
        /// <summary>
        /// Get number of Images in display
        /// <returns>returns Images count in display</returns>
        /// </summary>
        size_t GetImagesSize(void) const;
        /// <summary>
        /// Get number of Samplers in display
        /// <returns>returns Samplers count in display</returns>
        /// </summary>
        size_t GetSamplersSize(void) const;
        /// <summary>
        /// Get number of Cameras in display
        /// <returns>returns Cameras count in display</returns>
        /// </summary>
        size_t GetCamerasSize(void) const;
        /// <summary>
        /// Get number of Skins in display
        /// <returns>returns Skins count in display</returns>
        /// </summary>
        size_t GetSkinsSize(void) const;
        /// <summary>
        /// Get number of Lights in display
        /// <returns>returns Light count in display</returns>
        /// </summary>
        size_t GetLightsSize(void) const;
        /// <summary>
        /// Get number of CmapTextures in display
        /// <returns>returns CmapTextures count in display</returns>
        /// </summary>
        size_t GetCmapTexturesSize(void) const;
        /// <summary>
        /// Get number of Nodes in display
        /// <returns>returns Nodes count in display</returns>
        /// </summary>
        size_t GetNodesSize(void) const;
        /// <summary>
        /// Get number of Materials in display
        /// <returns>returns Materials count in display</returns>
        /// </summary>
        size_t GetMaterialsSize(void) const;
		/// <summary>
		/// Get number of Animations in display
		/// <returns>returns Animations count in display</returns>
		/// </summary>
		size_t GetAnimationsSize(void) const;
        /// <summary>
        /// function to get scene in List of scenes 
        /// <param name="p_index">index from which pointer will be retrieved</param>
        /// </summary>
        /// <returns>returns pointer to scene node</returns>
        gfx3d_scg_scene * GetScene(const size_t p_index) const;
        /// <summary>
        /// function to get accessor in List of accessors 
        /// <param name="p_index">index from which pointer will be retrieved</param>
        /// </summary>
        /// <returns>returns pointer to accessor node</returns>
        gfx3d_scg_accessor * GetAccessor(const int32_t p_index) const;
        /// <summary>
        /// function to get Animation in List of Animations 
        /// <param name="p_index">index from which pointer will be retrieved</param>
        /// </summary>
        /// <returns>returns pointer to accessor node</returns>
        gfx3d_scg_anim * GetAnimation(const int32_t p_index) const;
        /// <summary>
        /// function to get bufferView in List of bufferViews 
        /// <param name="p_index">index from which pointer will be retrieved</param>
        /// </summary>
        /// <returns>returns pointer to bufferView node</returns>
        gfx3d_scg_bufferview * GetBufferView(const int32_t p_index) const;
        /// <summary>
        /// function to get Sampler in List of bufferViews 
        /// <param name="p_index">index from which pointer will be retrieved</param>
        /// </summary>
        /// <returns>returns pointer to sampler node</returns>
        gfx3d_scg_sampler* GetSampler(const int32_t p_index) const;
        /// <summary>
        /// function to get buffer in List of buffers 
        /// <param name="p_index">index from which pointer will be retrieved</param>
        /// </summary>
        /// <returns>returns pointer to buffer node</returns>
        gfx3d_scg_buffer* GetBuffer(const int32_t p_index) const;
        /// <summary>
        /// function to get Image in List of images 
        /// <param name="p_index">index from which pointer will be retrieved</param>
        /// </summary>
        /// <returns>returns pointer to image node</returns>
        gfx3d_scg_image * GetImage(const int32_t p_index) const;
        /// <summary>
        /// function to get render Target in List of rtargets
        /// <param name="p_index">index from which pointer will be retrieved</param>
        /// </summary>
        /// <returns>returns pointer to render target </returns>
        gfx3d_scg_rtarget * GetRenderTarget(const size_t p_index) const;
        /// <summary>
        /// function to get texture in List of textures
        /// <param name="p_index">index from which pointer will be retrieved</param>
        /// </summary>
        /// <returns>returns pointer to texture </returns>
        gfx3d_scg_texture * GetTexture(const int32_t p_index) const;
        /// <summary>
        /// function to get cmap texture in List of cmaptextures
        /// <param name="p_index">index from which pointer will be retrieved</param>
        /// </summary>
        /// <returns>returns pointer to cmaptexture </returns>
        gfx3d_scg_cmap_texture * GetCmapTexture(const int32_t p_index) const;
        /// <summary>
        /// function to get skin in List of skins[]
        /// <param name="p_index">index from which pointer will be retrieved</param>
        /// </summary>
        /// <returns>returns pointer to skin </returns>
        gfx3d_scg_skin * GetSkin(const int32_t p_index) const;
        /// <summary>
        /// function to get light in List of lights[]
        /// <param name="p_index">index from which pointer will be retrieved</param>
        /// </summary>
        /// <returns>returns pointer to light </returns>
        gfx3d_scg_light* GetLight(const int32_t p_index) const;
        /// <summary>
        /// Inserts name and node pair in node_lookup 
        /// <param name="p_name">name of The node object</param>
        /// <param name="p_node">pointer to node object</param>
        /// </summary>
        void add_node_in_lookup(const std::string p_name, gfx3d_scg_node* const p_node);
        /// <summary>
        ///< Returns the renderlist. (Used for Unit Test purpose)
        /// </summary>
        gfx3d_render_list& GetRenderList();
        /// <summary>
        /// Returns the input handler
        /// </summary>
		rc_input * GetInputHandler() const;
        /// <summary>
        /// Sets the pitch/roll/translate for all cameras.
        /// \see rendercore_engine::gfx3d_scg_camera::SetEditorView()
        /// </summary>
        void SetEditorView(const float32_t p_pitch, const float32_t p_roll, const float32_t p_translate) const;
        /// <summary>
        /// Returns the scene thats getting rendered now. SIZE_MAX if none of the scene is rendered now..
        /// This is transitionary in nature and for interal consumption
        /// </summary>
        size_t GetActiveSceneId(void) const;
        /// <summary>
        /// Check the load state of the a scene by its ID
        /// </summary>
        /// <param name="p_sceneIndex">scene index / id</param>
        /// <returns>rcScreenLoadSts</returns>
        rcScreenLoadSts GetSceneLoadStatus(const size_t p_sceneIndex) const;
        /// <summary>
        /// When multi threading is enabled, the EGL context is owned by render threads.
        /// if the application wish to make some gl calls, then it has to be executed by
        /// the GL threads. This API allows to submit a gl operation to the gl thread
        /// </summary>
        /// <param name="p_task">task to be submitted to gl thread</param>
        void DoSyncGlOperation(const std::function<void()>& p_task) const;
        /// <summary>
        /// Get the current resource load mode
        /// <returns>Resource loading mode</returns>
        /// </summary>
        MdlResourceLoadRule GetResourceLoadRule() const;
        /// <summary>
        /// Set the current resource load rule to be used while loading a scene
        /// <param name="p_lrule">Rule to be set</param>
        /// </summary>
        void SetResourceLoadRule(const MdlResourceLoadRule p_lrule);
        /// <summary>
        /// Gets the Resource Fetching mode selected.
        /// </summary>
        MdlResourceFetch GetResourceFetching() const;
        /// <summary>
        /// Sets the Resource Fetching mode selected.
        /// </summary>
        void SetResourceFetching(const MdlResourceFetch p_fmode);
        /// <summary>
        /// Set the GUI skinning object
        /// </summary>
        /// <param name="p_skinning">skinning object</param>
        void SetGuiSkinning(gfx3d_scg_guiskinning* const p_skinning);
        /// <summary>
        /// Returns the GUI skinning object
        /// </summary>
        /// <returns>Pointer to skinning object</returns>
        gfx3d_scg_guiskinning* GetGuiSkinning(void) const;
        /// <summary>
        /// Checks if there are any changes in properties of display object that may trigger a rendering
        /// Currently Camara change, scene load/unload, localization language changes triggers dirty flag
        /// </summary>
        /// <returns>true if there are property changes</returns>
        bool IsDirty() const;
        /// <summary>
        /// Sets the display as dirty / properties changed.
        /// </summary>
        void SetDirty();
        /// <summary>
        /// Clears the dirty / property change flag for the display
        /// </summary>
        void ClearDirty();
        /// <summary>
        /// Enables the memory monitor for the display
        /// </summary>
        void EnableMemMonitor();
        /// <summary>
        /// Disables the memory monitor for the display
        /// </summary>
        void DisableMemMonitor();
        /// <summary>
        /// Get instance of memory monitor for this display
        /// </summary>
        gfx3d_scg_memory_monitor* GetMemMonitor(void) const;
        /// <summary>
        /// Add memory object to memory monitor instance if monitor is active
        /// Returns if Object is added
        /// </summary>
        rc_MOAddStatus AddMemMonitorObject(gfx3d_scg_mem_obj* const p_mem_obj, const uint32_t p_gpu_size, const uint32_t p_heap_size);
        /// <summary>
        /// Remove memory object to memory monitor instance if monitor is active
        /// </summary>
        void RemoveMemMonitorObject(gfx3d_scg_mem_obj* const p_mem_obj);
        /// Schedules current framebuffer content grab to passed texture 2D object.
        /// The p_tex2d will be updated at the end of current render cycle
        /// Note : Immadiate use of the texture may not work. After calling ScheduleFrameGrab, wait for
        /// one render() cycle to make sure the content is updated to p_tex2d
        /// </summary>
        /// <param name="p_tex2d">A texture 2D object to which the image to be loaded</param>
        /// <returns>true on success</returns>
        bool ScheduleFrameGrab(gfx3dTexture2D* const p_tex2d);
        /// <summary>
        /// Sets the border style of window created by this display
        /// </summary>
        /// <returns>false means with border, true means borderless</returns>
        void SetBorderLessWindow(const bool p_value);
        /// <summary>
        /// Checks the borderless property of this display's window
        /// </summary>
        bool IsBorderLessWindow() const;
        /// <summary>
        /// Sets the title for the window created by this display
        /// </summary>
        void SetDisplayTitle(const std::string& p_value);
        /// <summary>
        /// Get the title of this display's window
        /// </summary>
        const std::string& GetDisplayTitle() const;
#ifdef RC_CHRONO_FEATURE
        /// Returne the physics engine instance
        rc_physics_engine* GetPhysicsEngine();
        /// Initalizes the physics engine with required collision type
        void InitializeCollisionType(SystemType_E type);
#endif
        /// <summary>
        /// Returns the currently set resource path.
        /// </summary>
        /// <returns>Currently set resource path.</returns>
        std::string GetResourcePath(void);
        /// <summary>
        /// Gets the maximum number of threads which can be used.
        /// </summary>
        uint32_t GetMaxThreadCount(void);
        /// Read a file content from resource archive
        const CHAR8* ResourceFileRead(const std::string& p_uri, size_t& p_sizeout);
        /// Pass the pointer that was returned by a previous call to ReseArchiveFileRead()
        /// to mark it as unused. A RemoveResourceArchive() will unload an archive only when 
        /// no files are in use.
        bool ResourceFileFree(const CHAR8* const p_filedata);
        /// <summary>
        /// Returns true of the passed resource in tar
        /// </summary>
        /// <param name="p_uri">uri of the resource</param>
        /// <param name=""></param>
        /// <returns></returns>
        /// <returns>true or false</returns>
        bool IsResourceInTar(const std::string& p_uri);
        /// <summary>
        /// Gets the current time
        /// </summary>
        const rc_time& GetTime(void) const;
        /// <summary>
        /// Returns the current project configurations from parent object
        /// </summary>
        /// <param name=""></param>
        /// <returns></returns>
        const rc_pfm_cfg_ibase& GetProjectConfig() const;
        /// <summary>
        /// Returns either user config when available or default configurations from parent object
        /// </summary>
        static const rc_pfm_cfg_ibase& GetProjectConfig(const gfx3d_scg_display * const p_disp);
        /// <summary>
        /// Gets the render state of the project associated with this display
        /// </summary>
        /// <param name=""></param>
        /// <returns></returns>
        rc_render_states& GetRenderStates(void);
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
        /// <summary>
        /// Waits until a previous render() loop is finished(Blocking call). Useful to synchronize data updates
        /// </summary>
        void WaitForRenderDone() const;
        /// <summary>
        /// Checks if a previous render() loop is finished. Useful to synchronize data updates
        /// </summary>
        /// <returns>Returns true if renderloop has finished</returns>
        bool IsRenderDone() const;
#endif
#if !defined(RC_ONLY_RDF)
        /// <summary>
        /// Exists to support multiple gltf loading. 
        /// Note: Do not use this API!!! 
        /// </summary>
        /// <param name="p_src">source display</param>
        void merge_display(gfx3d_scg_display* const p_src);
#endif
    };
    /// @}
}

#endif