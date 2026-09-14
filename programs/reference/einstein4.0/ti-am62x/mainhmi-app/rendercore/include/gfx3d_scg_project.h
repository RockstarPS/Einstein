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
/// @file gfx3d_scg_project.h
/// @author emanoj1@visteon.com, mpandey@visteon.com
/// @brief GFX3D scene graph project object (root node) 
/// @date 11-Sep-2018
/// @copyright © 2019, Visteon Corporation, All Rights Reserved
///////////////////////////////////////////////////////////////////////////////
#ifndef gfx3d_scg_project_h
#define gfx3d_scg_project_h

#include "rc_assetgroup.h"

#define RC_INVALID_ASSET_CLIENT_ID (UINT32_MAX)

namespace rendercore_engine
{
	class gfx3d_scg_font;
    class rc_localization;

    /// \ingroup Engine
    /// @{
    /// <summary>
	/// Project class is the root of the scene graph. Project contains a list of displays and fonts used.
	/// </summary>
	class gfx3d_scg_project : public RcMTTasking
	{
	private:
        std::string name;                               ///< Name of the Project 
        std::vector<gfx3d_scg_display*> displays;       ///< List of displays (array of pointer to display nodes)
        std::vector<gfx3d_scg_font*> fonts;             ///< List of fonts (array of pointer to font nodes)
        std::string lresource_path;                     ///< Holds the system directory base path indicating 
                                                        ///< where the resource files are located (such as images, font files,, shader programs)
        RcVersion rdfVersion{ 0,0,0 };                  ///< Specifies the RDF/GLTF+ data file version. This is used for compatibility check with rendercore engine version.
        uint32_t maxThreadCount = 0U;                   ///< Maximum number of threads available
        bool locz_comp_hint = false;                    ///< hints whether the loalization data is gzip compressed or not
        rc_localization* loclzn = nullptr;              ///< Pointer to localization info.
        gfx3d_global_data * globalData = nullptr;       ///< Global data storage for this project instance
        const rc_pfm_cfg_ibase& pfgConfig;              ///< Global configurations (limiting values)
        uint32_t clientId = 0U;                         ///< For Client Id generation
        static MdlCoordSystem coordSys;                 ///< Specifies the co ordinate system (LHS or RHS(default))
        static MdlPositioning scissorPosType;           ///< How the scissor input to be treated (absolute or relative)
        static MdlFontEngine fengine;                   ///< Font engine options for the font
#if !defined(RC_NO_TAR) // needed to build the text rendering library for unity..
        std::unordered_map<std::string, rendercore_engine::rc_tar*> resArchives; ///< Holds the resource tarballs or archives loaded.
#endif
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
        std::recursive_mutex resArchMutex;              ///< mutex to protect all data access by threads
        mutable std::recursive_mutex data_mutex;        ///< to prevent concurrent access to change data within display
        static std::recursive_mutex sdata_mutex;        ///< to prevent concurrent access to change static data within display
#endif
    protected:
        std::map<int32_t, rc_assetgroup> assetGroups;   ///< asset group ID to tar files mapping for the project
        int32_t globalAssetID = static_cast<int32_t>(rc_agcst_e::RC_ASSET_ID_INVALID);    ///< Shared asset id. It will be used to when shared assets such as localizations or skinning are accessed
    public:
        /// <summary>
		/// Constructor for a gfx3d_scg_project class. Base class only performs some data init but it is expected that the
        /// derived class will perform some preperations before a source model gets loaded (e.g. RDF C++ data or gltf+ file)
        /// No time consuming tasks are expected to be performed and that will have to be scheduled in the Load() method.
        /// Example of the data that gets processed include how many textures are there, what are their properties, how many meshes
        /// are there, mesh data, how many materials are there etc. The scene graph will not be constructed at this stage. And it will be
        /// the job of the gfx3d_scg_project::Load method to do that.
		/// </summary>
        gfx3d_scg_project();
        gfx3d_scg_project(const rc_pfm_cfg_ibase& p_pfgConfig);
		/// <summary>
		/// Destructor for a gfx3d_scg_project class.
		/// </summary>
		virtual ~gfx3d_scg_project();
        gfx3d_scg_project& operator= (const gfx3d_scg_project&) = delete;
        gfx3d_scg_project(const gfx3d_scg_project&) = delete;
        /// <summary>
		/// Sets the resource path. The path has to end with a '/'. 
        /// When ever rendercore needs to open a file pointed a uri, it uses the resource path as the base directory. 
        /// <code>
        ///  SetResourcePath("c:/myproject/demo/resources/");   -- windows
        ///  SetResourcePath("/app/myproject/demo/resources/"); -- qnx
        /// </code>
		/// </summary>
		/// <param name="p_path">string which contains the path to resources.</param>
        void SetResourcePath(const std::string p_path);
		/// <summary>
		/// Returns the currently set resource path.
		/// </summary>
		/// <returns>Currently set resource path.</returns>
        std::string GetResourcePath(void);
		/// <summary>
		/// Renders the active scenes of passed display ID to its render target (e.g. window buffer)
		/// </summary>
		/// <param name="p_display">Index of the display to render. If there are 3 displays in project, index will from 0 to 2 </param>
        /// <param name="p_onChange">If false rendering happens on every call. If true then rendering happens only if a change is detected. Refer http://uxcoc.visteon.com/docs/#/rendercore/rendercore On Change Rendering section for more details</param>
        void Render(const size_t p_display, const bool p_onChange);
		/// <summary>
		/// Renders the all active scenes in all displays to its corresponding render targets (e.g. window buffers)
        /// <param name="p_onChange">If false rendering happens on every call. If true then rendering happens only if a change is detected. Refer http://uxcoc.visteon.com/docs/#/rendercore/rendercore On Change Rendering section for more details</param>
        /// </summary>
        void Render(const bool p_onChange = false);
		/// <summary>
		/// Load method creates all the displays & load all the scenes & activates it
        /// Internally invokes gfx3d_scg_display::Create and gfx3d_scg_display::Load
        /// This is probably not very useful real application since you might not want
        /// to load everything at once.
        /// So instead use gfx3d_scg_display::Create and gfx3d_scg_display::LoadScene / gfx3d_scg_display:LoadSceneAsync
		/// </summary>
        bool Load(const MdlAssetLoadMode p_mode, std::shared_ptr<rc_platform_window> p_pwin);
        /// <summary>
        /// Loads the localization data
        /// </summary>
        /// <param name="p_mode">load syncronously or async</param>
        /// <param name="p_flag">0 to (Number of language -1) will restrict loading only to the language index, anyother value loads all the languages</param>
        bool LoadLocalization(const MdlAssetLoadMode p_mode, const uint32_t p_flag);
        /// <summary>
		/// Returns the pointer to the display object at passed index
		/// </summary>
		/// <returns>If the index is valid then returns the pointer to display onject, else returns a NULL pointer</returns>
        gfx3d_scg_display * GetDisplay(const int32_t p_index) const;
        /// <summary>
        /// Add Font to list
        /// </summary>
        /// <param name="p_font">font list</param>
        /// <returns>returns the index of the added font. < 0 indicates error</returns>
        int32_t AddFont(gfx3d_scg_font* const p_font);
		/// <summary>
        /// Add Font to list at specified index
        /// </summary>
        /// <param name="p_font">font list</param>
        /// <param name="p_index">index of font</param>
        /// <returns>returns the index of the added font. < 0 indicates error</returns>
        int32_t AddFont(gfx3d_scg_font* const p_font, const uint32_t p_index);
        /// <summary>
		/// Gets the fonts at index
		/// </summary>
		/// <param name="p_index">index of the font to be returned</param>
		/// <returns>List of fonts available in project class</returns>
		gfx3d_scg_font * GetFont(const size_t p_index) const;
        /// <summary>
        /// Set the co ordinate system followed by the project (either MdlCoordSystem::csRHS or MdlCoordSystem::csLHS)
        /// </summary>
        /// <param name="p_coord">co ordinate system value</param>
        static void SetCoordSystem(const MdlCoordSystem &p_coord);
        /// <summary>
        /// Get the current co ordinate system followed by the project
        /// </summary>
        /// <returns>current co ordinate system</returns>
        static MdlCoordSystem GetCoordSystem(void);
        /// <summary>
        /// Set the RDF/GLTF+ data version in Major.Minor.Patch
        /// </summary>
        /// <param name="p_version">version to be set</param>
        void SetRdfVersion(const RcVersion &p_version);
        /// <summary>
        /// Get the RDF/GLTF+ data version in Major.Minor.Patch
        /// </summary>
        /// <returns>List of fonts available in project class</returns>
        RcVersion GetRdfVersion(void);
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
        /// function to get display count
        /// </summary>
        /// <returns>returns display count </returns>
        size_t GetNumDisplays() const;
        /// <summary>
        /// function to get font count
        /// </summary>
        /// <returns>returns font count </returns>
        size_t GetNumFonts() const;
        /// <summary>
        /// Adds a display in display list and returns it's index
        /// </summary>
        /// <param name="p_display"> pointer to the display </param>
        /// <returns>returns the index of the added font. < 0 indicates error</returns>
        int32_t AddDisplay(gfx3d_scg_display * const p_display);
        /// <summary>
        /// Returns the localization data for the project.
        /// </summary>
        rc_localization* GetLocalization() const;
        /// <summary>
        /// Specify a hint on whether the localization data is gzip compressed or not
        /// And it controls how the localization files will be loaded
        /// If set to true / compressed, then only tries to load *.bin.gz file 
        /// If set to false tries to load first *.bin file and if it does not exist
        /// tries to load *.bin.gz
        /// Must be set before the first call to LoadLocalization() or
        /// gfx3d_scg_project::Load()
        /// </summary>
        /// <param name="p_chint"> hint on compression state </param>
        void SetLoclzonDataCompressionState(const bool p_chint);
        /// <summary>
        /// Sets the maximum number of threads to use.
        /// 0 (default)- Use all cores
        /// 1-N means limit to the number specified
        /// General functionality - 
        ///  - two threads are dedicated by default (main rendering / background).
        ///  - specifying 2 means image deoding will happen in the background thread
        ///  - p_thCount > 2, allocates the remaining to image decoding
        /// Note : Call this API immediately after the project object is created
        /// - its defaulted during project object creatio, so change made prior
        ///   are lost
        /// - its polled during startup / load scene once and later changes will 
        ///   not have any impact.
        /// </summary>
        /// <param name="p_thCount"> specify the number of threds to use </param>
        void SetMaxThreadCount(const uint32_t p_thCount);
        /// <summary>
        /// Gets the maximum number of threads which can be used.
        /// </summary>
        uint32_t GetMaxThreadCount(void);
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
        /// <summary>
        /// Waits until a previous Render() loop is finished(Blocking call). 
        /// This will be useful to synchronize data updates.
        /// Usecase Option 1
        /// thread1()
        /// {
        ///     WaitForRenderDone();
        ///     UpdateAllRendercoreNodesWithData()
        ///     Render();
        /// }
        /// Usecase Option 2
        /// thread1()
        /// {
        ///     if(IsRenderDone())
        ///     {
        ///         UpdateAllRendercoreNodesData();//All rendercore API calls happen here
        ///         Render();
        ///     }
        ///     else
        ///     {
        ///         PrepareforNextFrame();
        ///     }
        /// }
        /// Usecase Option 3
        /// thread1()
        /// {
        ///     dataupdate.wait(); // wait for data update
        ///     Render(); // perform render
        ///     WaitForRenderDone(); //wait until rendering finishes
        ///     renderupdate.notify_one();//notify data thread that its safe to update data
        /// }
        /// thread2()
        /// {
        ///     UpdateAllRendercoreNodesWithData()
        ///     dataupdate.notify_one(); // notify render thread of data updated
        ///     renderupdate.wait(); // wait for rendering to finish
        /// }
        /// </summary>
        void WaitForRenderDone() const;
        /// <summary>
        /// Checks if a previous Render() loop is finished. Useful to synchronize data updates
        /// </summary>
        /// <returns>Returns true if renderloop has finished</returns>
        bool IsRenderDone() const;
#endif
        /// <summary>
        /// Sets how the scissoring rectangle position to be considered. Its a global option to be set once immediately
        /// after the project is created.
        /// MdlPositioning::Absolute (default):- treated same as specified by https://www.khronos.org/registry/OpenGL-Refpages/es2.0/xhtml/glScissor.xml
        /// bottom left of the display is 0,0. And scissor to be set as absolute value for any node
        /// MdlPositioning::Relative :- The passed value is assumed to be a relative scissor rectangle with respect
        /// the node to which the scissor is set. So the scissor also moves along the node.
        /// </summary>
        static void SetScissorPositionType(const MdlPositioning p_type);
        /// <summary>
        /// Gets the scissoring rectangle position type set earlier
        /// </summary>
        static MdlPositioning GetScissorPositionType();
        uint32_t LoadAssetGroup(const int32_t p_assetid);
        void UnLoadAssetGroup(const uint32_t p_clientId, const int32_t p_assetid);
        uint32_t WaitForAssetGroup(const uint32_t p_clientId, const int32_t p_assetid);
        uint32_t LoadGlobalAssetGroup();
        void UnLoadGlobalAssetGroup(const uint32_t p_clientId);
        uint32_t WaitForGlobalAssetGroup(const uint32_t p_clientId);
        uint32_t GenerateAssetClientId();     ///< Generate a client ID for use with AssetGroup Load, Unload, WaitForLoad APIs
        /// <summary>
        /// Return the RC_MTHREADS configuration of the rendercore library
        /// </summary>
        /// <returns>RC_MTHREADS configuration</returns>
        static uint32_t GetProjMthreadsConfig();
        /// <summary>
        /// Return the GLES3_RENDERER configuration of the rendercore library
        /// </summary>
        /// <returns>GLES3_RENDERER configuration</returns>
        static uint32_t GetProjGlesConfig();
        /// <summary>
        /// function to get font engine 
        /// </summary>
        /// <returns>returns font engine of type MdlFontEngine</returns>
        static MdlFontEngine GetFontEngine();
        /// <summary>
        /// Set font Engine if not already set 
        /// </summary>
        /// <param name="p_font_engine">font engine</param>
        static void SetFontEngine(const MdlFontEngine p_font_engine);
        /// <summary>
        /// Gets the material properties associated with this project
        /// </summary>
        /// <returns></returns>
        gfx3d_material_properties* GetMatProperties();
        /// <summary>
        /// Gets the font properties associated with this project
        /// </summary>
        /// <returns></returns>
        gfx3d_font_properties* GetFontProperties();
        /// <summary>
       /// Set default character all fonts
       /// If the given text string has character codes not present in font
       /// file, it will be replaced with this default character
       /// Its default value is Unicode 0xFFFD
       /// </summary>
       /// <param name="p_default_char"> font's default character </param>
        void SetDefaultChar(const char32_t p_defchar);
        /// <summary>
        /// Gets the default character
        /// </summary>
        /// <returns></returns>
        char32_t GetDefaultChar() const;
        /// Add a resource archive to the collection. Opens it and loads its content
        bool AddResourceArchive(const std::string p_uri);
        /// Read a file content from resource archive
        bool RemoveResourceArchive(const std::string p_uri);
        /// Read a file content from resource archive
        const CHAR8* ResourceFileRead(const std::string& p_uri, size_t& p_sizeout);
        /// <summary>
        /// Returns true of the passed resource in tar
        /// </summary>
        /// <param name="p_uri">uri of the resource</param>
        /// <returns>true or false</returns>
        bool IsResourceInTar(const std::string& p_uri);
        /// <summary>
        ///  Returns true if resource file exists..
        /// </summary>
        /// <param name="p_uri">relative path to resource file</param>
        /// <returns>true if resource exists</returns>
        bool ResourceFileExists(const std::string& p_uri);
        /// Pass the pointer that was returned by a previous call to ReseArchiveFileRead()
        /// to mark it as unused. A RemoveResourceArchive() will unload an archive only when 
        /// no files are in use.
        bool ResourceFileFree(const CHAR8* const p_filedata);
        /// To free the archive completely.. Used internally by engine
        void ResourceArchiveFreeAll(void);
        /// <summary>
        /// Gets the currently held platform configurations or limiting values applied
        /// </summary>
        /// <returns>reference to the config object</returns>
        const rc_pfm_cfg_ibase& GetProjectConfig() const;
        /// <summary>
        /// Returns a default project config object
        /// </summary>
        /// <returns></returns>
        static const rc_pfm_cfg_ibase& getDefaultProjectConfig();
        /// <summary>
        /// Returns either user config when available or default configurations from parent object
        /// </summary>
        static const rc_pfm_cfg_ibase& GetProjectConfig(const gfx3d_scg_project* const p_prj);
    };
    /// @}
}


#endif