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
//  Filename    : gfx3d_scg_texture.h
//  Description : GFX3D scene graph texture object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_scg_texture.h
/// \brief GFX3D scene graph texture object
#ifndef gfx3d_scg_texture_h
#define gfx3d_scg_texture_h

namespace rendercore_engine
{
    /// \ingroup Engine
    /// @{
    /// <summary>
	/// contains the data releated to textures used in the engine
    /// https://github.com/KhronosGroup/glTF/tree/master/specification/2.0#textures
	/// </summary>
	class gfx3d_scg_texture : public  gfx3d_scg_mem_obj
	{
	private:
        std::string name;			///< name of the texture
        gfx3d_scg_display* display;	///< parent display class of the texture
        int32_t sampler;			///< index/id of gfx3d_scg_sampler to be used for this texture 
        int32_t source;				///< index/id of source gfx3d_scg_image to be used for this texture
        gfx3dTexture2D * tex = nullptr;///< holds the texture 2D object, which holds the gl texture object
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
        WTAsyncTask lLoadAsyncSts{ nullptr }; ///< asynchronous texture loading status
        mutable std::recursive_mutex data_mutex;      ///< mutex to protect all data access by threads
#endif
        /// <summary>
        /// Creates the GL texture incase not created yet. Returns true if a text ure is created
        /// If not created or texture already exists returns false
        /// <returns>returns true if a GL command was performed to create. If texture is already created or failure, returns false </returns>
        /// </summary>
        bool create_tex_obj(const size_t p_scene);
    public:
        gfx3d_scg_texture() = delete;
        /// <summary>
        /// Constructs an empty texture object
        /// </summary>
        /// <param name="p_disp"> parent display this accessor belongs to </param>
        gfx3d_scg_texture(gfx3d_scg_display * const p_disp);
        /// <summary>
        /// Constructs a texture object with specified source image and sampler
        /// <param name="p_disp"> parent display this accessor belongs to </param>
        /// <param name="p_sampler"> index to the sampler to be used </param>
        /// <param name="p_source"> index to the source to be used </param>
        /// </summary>
        gfx3d_scg_texture(gfx3d_scg_display * const p_disp, const int32_t p_sampler, const int32_t p_source);
        /// Distructor
        virtual ~gfx3d_scg_texture();
        /// <summary>
        /// Loads this texture by creating dynamic contents..
        /// Note : Please make sure that every Load() calls has a matching UnLoad() call
        /// If not the unload handling of the texture will not work on UnLoad().
        /// </summary>
        /// <param name="p_scene">id of the scene which is requesting this node load</param>
        /// <param name="p_sync">true - load synchronously, false - loads in background</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        bool Load(const size_t p_scene, const bool p_sync = false);
        /// <summary>
        /// Unloads this texture by deleting dynamic contents.. if no one uses this anymore
        /// Usage is tracked by counting number of Load() calls. Every call to UnLoad() decrements
        /// the counter, so if the Load and UnLoad calls are matched thne counter reaches 0
        /// and the last UnLoad call will free up this texture.
        /// Note : Please make sure that every Load() calls has a matching UnLoad() call
        /// If not the unload handling of the texture will not work on UnLoad().
        /// </summary>
        /// <param name="p_scene">id of the scene which is requesting this node unload</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        bool UnLoad(const size_t p_scene);
        /// <summary>
        /// Creates the GL texture incase not created yet and returns a texture 2d.
        /// </summary>
        gfx3dTexture2D* update_tex_obj(const size_t p_scene);
        /// <summary>
        /// Returns the GL texture object
        /// </summary>
        GLuint GetTexObj(void) const;
        /// <summary>
        /// Returns the texture2D (internally holds the GL texture) object
        /// </summary>
        gfx3dTexture2D * GetTexure2D(void);
        /// <summary>
        /// Creates a texture for an offscreen / FBO render target. 
        /// <param name="p_rt">pointer to render target, to read the texture configurations</param>
        /// <param name="p_force">p_force=true makes a recreate even if gl texture object already exists</param>
        /// </summary>
        void LoadRTTex(const gfx3d_scg_rtarget * const p_rt, const bool p_force=false);
        /// <summary>
        /// function to get name of texture
        /// </summary>
        /// <returns>returns name of texture object </returns>
        std::string GetName() const;
        /// <summary>
        /// Set texture's name
        /// </summary>
        /// <param name="p_name"> name of texture of type string </param>
        void SetName(const std::string p_name);
        /// <summary>
        /// function to get sampler index
        /// </summary>
        /// <returns>returns sampler index </returns>
        int32_t GetSampler() const;
        /// <summary>
        /// Set unique id for buffer object
        /// </summary>
        /// <param name="p_sampler"> Sampler index </param>
        void SetSampler(const int32_t p_sampler);
        /// <summary>
        /// function to get source index
        /// </summary>
        /// <returns>returns source index </returns>
        int32_t GetSource() const;
        /// <summary>
        /// Set source index
        /// </summary>
        /// <param name="p_source"> source index </param>
        void SetSource(const int32_t p_source);
        /// <summary>
        /// function to get pointer to parent display
        /// </summary>
        /// <returns>returns pointer to parent display </returns>
        gfx3d_scg_display* GetParent() const;
        /// <summary>
        /// function to get pointer to parent display
        /// </summary>
        /// <returns>returns pointer to parent display </returns>
        gfx3d_scg_display* GetDisplay() const;
        /// <summary>
        /// Sets the parent display of this camera
        /// <param name="p_disp">pointer to display</param>
        /// </summary>
        void SetDisplay(gfx3d_scg_display* const p_disp);
        /// <summary>
        /// Returns the total users of this texture so far.
        /// </summary>
        /// <returns>counter indicating the active Load() calls for this texture</returns>
        uint32_t GetUsageInstanceCounter() const;
        /// Set AnisoLevel for texture (valid range 1-16, 1 = aniso off)
        void SetAnisoLevel(const int32_t p_level);
        /// Get AnisoLevel of texture
        int32_t GetAnisoLevel() const;
        /// <summary>
        /// Memmory object unload function.
        /// </summary>
        /// <returns>unloaded flag</returns>
        bool MemMonitorObjUnload();
    };
    /// @}
}
#endif