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
//  Filename    : rendercore_engine::gfx3dTexture2D.h
//  Description : Texture2D object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file	gfx3dTexture2D.h
///	\brief 		Texture2D object
#ifndef gfx3dTexture2D_h
#define gfx3dTexture2D_h

#include <memory>
#include <mutex>

namespace rendercore_engine
{
    /// \ingroup Engine
    /// @{
    class gfx3dTexture2DData;
    ///<summary>
    ///class describing parameters for textures.
    ///</summary>
    class gfx3dTexture2D
    {
    private:
        std::shared_ptr<gfx3dTexture2DData> data{ nullptr };
    public:
        gfx3dTexture2D() = delete;
        bool operator== (const gfx3dTexture2D& p_object) const;
        bool operator!= (const gfx3dTexture2D& p_object) const;
        gfx3dTexture2D& operator= (const gfx3dTexture2D& p_object);
        gfx3dTexture2D(const gfx3dTexture2D& p_object);
        ///constructor 
        gfx3dTexture2D(gfx3d_scg_display * const p_display);
        ///constructor specifying witdht nd height
        gfx3dTexture2D(gfx3d_scg_display* const p_display, const GLuint p_width, const GLuint p_height, const MdlImgFormat_E p_format = MdlImgFormat_E::ifUnset, const bool p_mipmap = false);
        gfx3dTexture2D(gfx3d_scg_display* const p_display, const GLuint p_width, const MdlImgFormat_E p_format = MdlImgFormat_E::ifUnset, const bool p_mipmap = false);
        virtual ~gfx3dTexture2D();
        /// <summary>
        /// loads the raw pixel data in to texture object
        /// </summary>
        /// <param name="p_data">pixel data pointer</param>
        /// <param name="p_size">size of pixel data array</param>
        virtual void LoadRawTextureData(const CHAR8* const p_data, const int32_t p_size);
        /// <summary>
        /// Same as LoadRawTextureData(CHAR8 * p_data, int p_size)
        /// </summary>
        /// <param name="p_data">pixel data pointer</param>
        /// <param name="p_size">size of pixel data array</param>
        virtual void LoadRawTextureData(const uint8_t* const p_data, const int32_t p_size);
        /// <summary>
        /// Same as LoadRawTextureData(CHAR8 * p_data, int p_size)
        /// </summary>
        /// <param name="p_data">pixel data pointer</param>
        /// <param name="p_size">size of pixel data array</param>
        void LoadRawTextureData(std::nullptr_t const p_data, const int32_t p_size);
        ///<summary>
        /// decodes the file content passed and loads in to texture object
        /// Pass relative path to load an asset from resource tar.
        ///</summary>					
        virtual bool LoadImage(const std::string p_file_path);
        /// <summary>
        /// Tries to decode the image directly to a Direct Texture
        /// if available, else performs a normal GL texture load.
        /// </summary>
        /// <param name="p_uri">Uri to the image</param>
        /// <returns>true on success</returns>
        bool LoadImageDirect(const std::string& p_uri);
        /// <summary>
        /// Loads the Image asyncronously in a background thread.
        /// Be aware that if a scene loading is in progress, the background thread may be loaded. In such cases
        /// It might affect the loading of image.
        /// </summary>
        /// <param name="p_file_path">Relative path to asset in tar</param>
        /// <returns>true on success</returns>
        virtual bool LoadImageAsyc(const std::string p_file_path);
        ///<summary>
        /// load image from raw data, the image data is assumed to be dynamic allocation and will be freed after 
        /// image creation. This API specifically exists for use inside the c# scripts.
        ///</summary>					
        virtual bool LoadImage(const MdlRdAllBytes p_bytes);
        /// <summary>
        /// Load the images from passed data 
        /// Data shall be of .png, .jpg or .ktx files. Any other format is not supported
        /// and behaviour is untested.
        /// Note: p_bytes will not be freed by LoadImage() after the creation
        /// </summary>
        /// <param name="p_bytes">Pointer to a memory with png, jpg or ktx image data</param>
        /// <param name="p_length">Length of the buffer in bytes</param>
        /// <returns></returns>
        virtual bool LoadImage(const CHAR8* const p_bytes, const size_t p_length);
        ///<summary>
        /// loads a raw image pixel data in memory p_pixels with specified p_format 
        ///</summary>					
        virtual bool LoadRawImage(const UCHAR8 * const p_pixels, const MdlImgFormat_E p_format);
        ///<summary>
        /// returns a texture object
        ///</summary>					
        virtual GLuint GetTexObj(void) const;
        ///<summary>
        /// Sets GL texture object
        ///</summary>					
        virtual void SetTexObj(const GLuint p_to);
        ///<summary>
        /// Gets GL texture target. 0U means its unset
        /// Valid values are GL_TEXTURE_2D, GL_TEXTURE_CUBE_MAP, GL_TEXTURE_EXTERNAL_OES
        ///</summary>					
        GLenum GetTexTarget(void) const;
        ///<summary>
        /// Sets GL texture target
        /// Valid values are GL_TEXTURE_2D, GL_TEXTURE_CUBE_MAP, GL_TEXTURE_EXTERNAL_OES
        ///</summary>					
        void SetTexTarget(const GLenum p_target);
        /// <summary>
        /// Unloads the texture by releasing texture memory if there are no active users
        /// if there are active users, deteaches this texture and resets its data to default
        /// </summary>
        /// <param name="p_force">forcefully release the texture object</param>
        /// <returns>true if texture unloaded</returns>
        virtual bool UnLoad(const bool p_force = false);
        /// <summary>
        /// function to return texture filter Mode
        /// </summary>
        /// <returns>returns texture filter mode</returns>
        MdlTextFilter_E GetFilterMode() const;
        /// <summary>
        /// function to return texture filter Mode
        /// </summary>
        /// <returns>returns texture MIN filter mode</returns>
        MdlTextFilter_E GetMinFilterMode();
        /// <summary>
        /// function to return texture MAG filter Mode
        /// </summary>
        /// <returns>returns texture filter mode</returns>
        MdlTextFilter_E GetMagFilterMode();
        /// <summary>
        /// Set texture MAG filter mode
        /// </summary>
        /// <param name="p_mode">texture filter mag filter mode of type MdlTextFilter_E</param>
        void SetMagFilterMode(const MdlTextFilter_E p_mode);
        /// <summary>
        /// Set texture MAG filter mode
        /// </summary>
        /// <param name="p_mode">texture filter mag filter mode of type MdlTextFilter_E</param>
        void SetMinFilterMode(const MdlTextFilter_E p_mode);
        /// <summary>
        /// Set texture filter mode
        /// </summary>
        /// <param name="p_filterMode">texture filter mode of type MdlTextFilter_E</param>
        void SetFilterMode(MdlTextFilter_E p_filterMode);
        /// <summary>
        /// function to return texture wrap Mode
        /// </summary>
        /// <returns>returns texture wrap mode</returns>
        MdlTextWrap_E GetWrapMode() const;
        /// <summary>
        /// function to return texture wrap Mode
        /// </summary>
        /// <returns>returns Texture U coordinate wrapping mode</returns>
        MdlTextWrap_E GetWrapModeU() const;
        /// <summary>
        /// function to return texture wrap Mode
        /// </summary>
        /// <returns>returns Texture V coordinate wrapping mode</returns>
        MdlTextWrap_E GetWrapModeV() const;
        /// <summary>
        /// function to return texture wrap Mode
        /// </summary>
        /// <returns>returns Texture W coordinate wrapping mode</returns>
        MdlTextWrap_E GetWrapModeW() const;
        /// <summary>
        /// Set texture wrap mode
        /// </summary>
        /// <param name="p_wrapMode">texture wrap mode of type MdlTextWrap_E</param>
        void SetWrapMode(const MdlTextWrap_E p_wrapMode);
        /// <summary>
        /// Set texture wrap mode
        /// </summary>
        /// <param name="p_wrapMode">texture U coordinate wrap mode of type MdlTextWrap_E</param>
        void SetWrapModeU(const MdlTextWrap_E p_wrapMode);
        /// <summary>
        /// Set texture wrap mode
        /// </summary>
        /// <param name="p_wrapMode">texture V coordinate wrap mode of type MdlTextWrap_E</param>
        void SetWrapModeV(const MdlTextWrap_E p_wrapMode);
        /// <summary>
        /// Set texture wrap mode
        /// </summary>
        /// <param name="p_wrapMode">texture W coordinate wrap mode of type MdlTextWrap_E</param>
        void SetWrapModeW(const MdlTextWrap_E p_wrapMode);
        /// <summary>
        /// function to return texture format
        /// </summary>
        /// <returns>returns format</returns>
        MdlImgFormat_E GetFormat() const;
        /// <summary>
        /// Set texture format
        /// </summary>
        /// <param name="p_format">texture format of type MdlImgFormat_E</param>
        void SetFormat(const MdlImgFormat_E p_format);
        /// <summary>
        /// function to return texture width
        /// </summary>
        /// <returns>returns width</returns>
        int32_t GetWidth() const;
        /// <summary>
        /// Set texture width
        /// </summary>
        /// <param name="p_width">texture width</param>
        void SetWidth(const int32_t p_width);
        /// <summary>
        /// function to return texture height
        /// </summary>
        /// <returns>returns height</returns>
        int32_t GetHeight() const;
        /// <summary>
        /// Set texture height
        /// </summary>
        /// <param name="p_height">texture height</param>
        void SetHeight(const int32_t p_height);
        /// Set texture size
        /// </summary>
        /// <param name="p_size">texture size</param>
        void SetSize(const int32_t p_size);
        /// <summary>
        /// function to return texture size
        /// </summary>
        /// <returns>returns size</returns>
        int32_t GetSize() const;
        /// Set texture Stride in pixels/line
        /// </summary>
        /// <param name="p_size">texture Stride</param>
        void SetStride(const int32_t p_size);
        /// <summary>
        /// function to return texture Stride in pixels/line
        /// </summary>
        /// <returns>returns Stride</returns>
        int32_t GetStride() const;
        /// Set AnisoLevel for texture (valid range 1-16, 1 = aniso off)
        void SetAnisoLevel(const int32_t p_level);
        /// Get AnisoLevel of texture
        int32_t GetAnisoLevel() const;
        /// <summary>
        /// Returns the maxium supported aniso level by this texture 2D
        /// </summary>
        /// <returns></returns>
        static uint32_t GetMaxAnisoLevel();
        /// Set Unpack Alignment of texture
        void SetUnpackAlignment(const GLint p_align);
        /// Returns the aniso level to be applied to the GL texture
        /// returns an interpolated value which maps the SetAnisoLevel() range to 
        /// 1 - GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT
        /// 0  value returned means aniso filter is not supported
        GLint GetGLAnisoLevel() const;
        /// <summary>
        ///  Sets the texture as SRGB encoded (true) or linear (false)
        /// </summary>
        /// <param name="p_srgb">SRGB encoded (true) or linear (false)</param>
        void SetSRGB(const bool p_srgb);
        /// <summary>
        /// SRGB encoding flag
        /// </summary>
        /// <returns>SRGB encoded (true) or linear (false)</returns>
        bool IsSRGB() const;
        /// <summary>
        /// Does the inital setup. Must be called before calls to LoadRawCubemapImage
        /// </summary>
        /// <param name="p_maxmiplevel">number of mip levels needed (0 - 255)</param>
        void LoadRawCubemapBegin(const size_t p_maxmiplevel);
        /// <summary>
        /// Must be called to cleanup after all calls to LoadRawCubemapImage
        /// </summary>
        void LoadRawCubemapEnd() const;
        /// <summary>
        /// Loads a single face and mipmap level for a cubemap texture
        /// Seq must be
        /// Load Raw Cubemap Begin 
        ///   loop {Load Raw Cubemap Images}
        /// Load Raw Cubemap End
        /// </summary>
        /// <param name="p_face">faces 0 to 5 to be loaded (0=POSITIVE_X0, 1=NEGATIVE_X, 
        /// 2=POSITIVE_Y, 3=NEGATIVE_Y, 4=POSITIVE_Z, 5=NEGATIVE_Z)</param>
        /// <param name="p_mip">mipmap level to load</param>
        /// <param name="p_texinfo">Information about the texture data to be loaded</param>
        bool LoadRawCubemapImage(const size_t p_face, const size_t p_mip, const rcTextureInfo& p_texinfo);
        ///<summary>
        /// decodes the file content passed and loads in to cubemap texture object
        /// Pass relative path to load an asset from resource tar.
        /// Curretly only ktx files with face count of 6, mip levels 0 to N, array size 1 only is accepted
        ///</summary>					
        /// <param name="p_file_path">ktx image file to be loaded</param>
        /// <returns>true on success</returns>
        bool LoadCubemapImage(const std::string p_file_path);
        /// <summary>
        /// Returns the total users of this texture so far.
        /// == 1 - means the texture is not used anywhere and only held by this object
        ///  > 1 means copies of this texture are held by other objects (e.g scg materials, scg textures)
        /// </summary>
        /// <returns>counter indicating the active Load() calls for this texture</returns>
        uint32_t GetUsageInstanceCounter() const;
        /// <summary>
        /// Returns the calculated GPU memory usage for this texture
        /// </summary>
        /// <returns>GPU memory usage</returns>
        uint32_t GetGpuMemSize() const;
        /// <summary>
        /// Returns the currently set resource path.
        /// </summary>
        /// <returns>Currently set resource path.</returns>
        std::string GetResourcePath(void);
    };
}
/// @}
#endif