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
//  Filename    : gfx3d_scg_cmap_texture.h
//  Description : GFX3D scene graph cube map object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_scg_cmap_texture.h
/// \brief GFX3D scene graph cube map object
#ifndef gfx3d_scg_cmap_texture_h
#define gfx3d_scg_cmap_texture_h

namespace rendercore_engine
{
    /// \ingroup Engine
    /// @{
    /// <summary>
	/// cubemap texture object
	/// </summary>
	class gfx3d_scg_cmap_texture : public  gfx3d_scg_mem_obj
	{
	private:
        gfx3d_scg_display* display;  ///< parent object display
        std::string name;	        ///< name of cmap
        int32_t sampler = -1;		///< sampler for the cmap, an index in to gfx3d_scg_display::samplers
        int32_t source = -1;		
        /// skybox -: right, an index in to gfx3d_scg_display::images
        ///  OR
        /// index to a single cubemap ktx file (which can contain all faces, mipmaps etc.)
        /// In this single image case, only posx_rgt_img will have index to the gfx3d_scg_display::images[].
        /// remaining negx_lft_img .. negz_bck_img will have -1 
        int32_t posx_rgt_img = -1;
        int32_t negx_lft_img = -1;	///< skybox -: left, an index in to gfx3d_scg_display::images 
        int32_t posy_top_img = -1;	///< skybox -: top, an index in to gfx3d_scg_display::images 
        int32_t negy_btm_img = -1;	///< skybox -: bottom, an index in to gfx3d_scg_display::images 
        int32_t posz_frt_img = -1;	///< skybox -: front, an index in to gfx3d_scg_display::images 
        int32_t negz_bck_img = -1;	///< skybox -: back, an index in to gfx3d_scg_display::images 
        gfx3dTexture2D * tex = nullptr;   ///< holds the texture 2D object, which holds the gl texture object
        int32_t get_image_id(const size_t p_index) const; ///< return the gfx3d_scg_image index corresponding face id
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
        WTAsyncTask lLoadAsyncSts{ nullptr };   ///< asynchronous texture loading status
        mutable std::recursive_mutex data_mutex;///< mutex to protect all data access by threads
#endif
        /// <summary>
        /// Creates the GL texture incase not created yet. Returns true if a text ure is created
        /// If not created or texture already exists returns false
        /// <returns>returns true if a GL command was performed to create. If texture is already created or failure, returns false </returns>
        /// </summary>
        bool create_tex_obj(const size_t p_scene);
    public:
        gfx3d_scg_cmap_texture() = delete;
        /// <summary>
        /// Constructs a cubemap texture
        /// </summary>
        /// <param name="p_parent"> parent display this accessor belongs to </param>
        gfx3d_scg_cmap_texture(gfx3d_scg_display* const p_parent);
        /// Distructor
        virtual ~gfx3d_scg_cmap_texture();
        /// <summary>
        /// Loads this node by creating dynamic contents..
        /// </summary>
        /// <param name="p_scene">id of the scene which is requesting this node load</param>
        /// <param name="p_sync">true - load synchronously, false - loads in background</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        bool Load(const size_t p_scene, const bool p_sync = false);
        /// <summary>
        /// Unloads this node by deleting dynamic contents.. if none of the scene uses this node anymore
        /// </summary>
        /// <param name="p_scene">id of the scene which is requesting this node unload</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        bool UnLoad(const size_t p_scene);
        /// <summary>
        /// creates the cubemap gl texture object. May block until the image decoding are over
        /// returns a texture 2d
        /// </summary>
        gfx3dTexture2D * update_tex_obj(const size_t p_scene);
        /// <summary>
        /// Returns the cubemap texture GL texture ID
        /// </summary>
        /// <returns>returns GL texture ID 0 is invalid, > 0 is valid </returns>
        GLuint GetTexObj(void) const;
        /// <summary>
        /// Returns the texture2D (internally holds the GL texture) object
        /// </summary>
        gfx3dTexture2D* GetTexure2D(void);
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
        /// function to get image index for skybox -: right
        /// </summary>
        /// <returns>returns image index for skybox -: right </returns>
        int32_t GetPositiveXRightImage() const;
        /// <summary>
        /// Set image index for skybox -: right
        /// </summary>
        /// <param name="p_posx_rgt_img"> image index for skybox -: right </param>
        void SetPositiveXRightImage(const int32_t p_posx_rgt_img);
        /// <summary>
        /// function to get image index for skybox -: left
        /// </summary>
        /// <returns>returns image index for skybox -: left </returns>
        int32_t GetNegativeXLeftImage() const;
        /// <summary>
        /// Set image index for skybox -: left
        /// </summary>
        /// <param name="p_negx_lft_img"> image index for skybox -: left</param>
        void SetNegativeXLeftImage(const int32_t p_negx_lft_img);
        /// <summary>
        /// function to get image index for skybox -: top
        /// </summary>
        /// <returns>returns image index for skybox -: top </returns>
        int32_t GetPositiveYTopImgage() const;
        /// <summary>
        /// Set image index for skybox -: top
        /// </summary>
        /// <param name="p_posy_top_img"> image index for skybox -: top </param>
        void SetPositiveYTopImgage(const int32_t p_posy_top_img);
        /// <summary>
        /// function to get image index for skybox -: bottom
        /// </summary>
        /// <returns>returns image index for skybox -: bottom </returns>
        int32_t GetNegativeYBottomImage() const;
        /// <summary>
        /// Set image index for skybox -: bottom
        /// </summary>
        /// <param name="p_negy_btm_img"> image index skybox -: bottom </param>
        void SetNegativeYBottomImage(const int32_t p_negy_btm_img);
        /// <summary>
        /// function to get image index for skybox -: front
        /// </summary>
        /// <returns>returns image index for skybox -: front </returns>
        int32_t GetPositiveZFrontImage() const;
        /// <summary>
        /// Set image index for skybox -: front
        /// </summary>
        /// <param name="p_posz_frt_img"> image index for skybox -: front </param>
        void SetPositiveZFrontImage(const int32_t p_posz_frt_img);
        /// <summary>
        /// function to get image index for skybox -: back
        /// </summary>
        /// <returns>returns image index for skybox -: back </returns>
        int32_t GetNegativegZBackImage() const;
        /// <summary>
        /// Set image index for skybox -: back
        /// </summary>
        /// <param name="p_negz_bck_img"> image index for skybox -: back </param>
        void SetNegativegZBackImage(const int32_t p_negz_bck_img);
        /// <summary>
        /// function to get pointer to parent display
        /// </summary>
        /// <returns>returns pointer to parent display </returns>
        gfx3d_scg_display* GetParent() const;
        /// <summary>
        /// Sets the parent display of this camera
        /// <param name="p_disp">pointer to display</param>
        /// </summary>
        void SetParent(gfx3d_scg_display* const p_disp);
        /// <summary>
        /// Returns the total users of this texture so far.
        /// </summary>
        /// <returns>counter indicating the active Load() calls for this texture</returns>
        uint32_t GetUsageInstanceCounter() const;
        /// <summary>
        /// function to get image index for skybox
        /// </summary>
        /// <returns>returns image index for skybox </returns>
        int32_t GetSourceImage() const;
        /// <summary>
        /// Set image index for skybox
        /// </summary>
        /// <param name="p_negz_bck_img"> image index for skybox </param>
        void SetSourceImage(const int32_t p_img);
        /// <summary>
        /// Memmory object unload function.
        /// </summary>
        /// <returns>unloaded flag</returns>
        bool MemMonitorObjUnload();
    };
    /// @}
}


#endif