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
//  Filename    : gfx3d_scg_image.h
//  Description : GFX3D scene graph image object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_scg_image.h
/// \brief GFX3D scene graph image object
#ifndef gfx3d_scg_image_h
#define gfx3d_scg_image_h

#include "rc_image_decoder.h"
#include <memory>

namespace rendercore_engine
{
    /// \ingroup Engine
    /// @{
    /// <summary>
    /// gfx3d_scg_image class encapsules a image object
    /// https://github.com/KhronosGroup/glTF/tree/master/specification/2.0#images
    /// image object can be specified in three ways
    /// 1. with a fullpath to an image file (supported extensions are *.png, *.jpg or *.ktx)
    /// 2. with a buffer view (supported extensions are *.png, *.jpg *.ktx, or raw pixels)
    ///    in this scenario buffer = NULL and bufferView >= 0 pointing to a valid buffer view
    ///    mimeType specifies the kind of file content in the bufferview (ieJpeg, iePng, ieKtx, ieRawPixels)
    /// 3. with a buffer pointer (supported extensions are *.png, *.jpg *.ktx, or raw pixels)
    ///    in this scenario buffer != NULL and bufferView < 0. 
    ///    mimeType specifies the kind of file content in the buffer(ieJpeg, iePng, ieKtx, ieRawPixels)
    /// 4. fullpath is empty, bufferView < 0, buffer = NULL and the mimeType = ieRenderToTex
    ///    This indicates a offscreen buffer used a render to texture. Not supported yet & TODO
	/// </summary>
    class gfx3d_scg_image
    {
    private:
        const CHAR8* buffer = nullptr;	///< raw encoded data (data kind will be specified by  MdlImgEncoding_E mimeType)
        gfx3d_scg_display* display;		///< parent display object
        std::string name;				///< name of the image
        std::string uri;				///< uri/ path of image	file
        rc_imgDecoderData img_data;     ///< decoded image information
        size_t buffer_length = 0U;	    ///< raw encoded data buffer length in bytes
        MdlImgEncoding_E mimeType = MdlImgEncoding_E::ieUnset;		///< image encoding type
        int32_t bufferView = -1;		///< index to a bufferview object (gfx3d_scg_display::bufferViews) incase the image data is to be fetched from a bufferview.  -1 means invalid bufferview & use 'uri'
        rc_flag sceneLoadedMask;        ///< indicates for which scenes loaded this object. Used to decide how many are using
        bool bLoaded = false;           ///< indicates whether the Load() has been done for this image
        bool srgb = false;              ///<    Linear (false) or SRGB (true) encoded
#if RC_MTHREADS != 0
        std::recursive_mutex data_mutex;///< mutex to protect all data access by threads
#endif
    public:
        /// <summary>
        /// Constructs an image object
        /// </summary>
        /// <param name="p_parent"> parent display this image belongs to </param>
        gfx3d_scg_image(gfx3d_scg_display* const p_parent);
        /// <summary>
        /// sets the image data, 
        /// p_width - width of the image 
        /// p_height - height 
        /// p_component - RGBA component
        /// p_pixels - data for the image
        /// </summary>
        void SetImageData(const int32_t p_width, const int32_t p_height, const MdlImgFormat_E p_component, const CHAR8* const p_pixels);
        /// Distructor
        virtual ~gfx3d_scg_image();
        /// <summary>
        /// Loads this node by creating dynamic contents..
        /// </summary>
        /// <param name="p_scene">id of the scene which is requesting this node load</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        virtual bool Load(const size_t p_scene);
        /// <summary>
        /// Unloads this node by deleting dynamic contents.. if none of the scene uses this node anymore
        /// </summary>
        /// <param name="p_scene">id of the scene which is requesting this node unload</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        virtual bool UnLoad(const size_t p_scene);
        /// <summary>
        /// Returns the raw pixel data for this image. May block until decoding is complete if multi thread is enabled.
        /// </summary>
        /// <returns>returns pointer to image data </returns>
        virtual const CHAR8* GetPixels(void);
        /// <summary>
        /// frees the currenmt pixel memory and sets the new one. The p_pixels has to be
        /// from a dynamic memory as the gfx3d_scg_image class will free it when no longer needed
        /// Note that there may be wait loops involved for finishing ongoing decode operations
        /// </summary>
        /// <param name="p_pixels">pointer to a dynamically allocated pixel data</param>
        void SetPixels(const CHAR8* const p_pixels);
        /// <summary>
        /// Gets the bufferview data incase this image uses a bufferview as its source (bufferView>=0)
        /// </summary>
        /// <param name="p_buffer">storage to write the pointer to buffer</param>
        /// <param name="p_length">storage to write the length of buffer</param>
        void GetRawBuffer(const CHAR8** const p_buffer, size_t * const p_length);
        /// <summary>
        /// Decodes the image data to raw pixel data
        /// </summary>
        virtual void Decode(void);
        /// <summary>
        /// Set image object name
        /// </summary>
        /// <param name="p_name"> image object name </param>
        void SetName(const std::string p_name);
        /// <summary>
        /// function to get image name
        /// </summary>
        /// <returns>returns image name of type string</returns>
        std::string GetName() const;
        /// <summary>
        /// Set image uri
        /// </summary>
        /// <param name="p_uri,"> image uri </param>
        void SetURI(const std::string p_uri);
        /// <summary>
        /// function to get image uri of type string
        /// </summary>
        /// <returns>returns image uri of image </returns>
        std::string GetURI() const;
        /// <summary>
        /// Set image mime type
        /// </summary>
        /// <param name="p_mimeType"> image mime type </param>
        void SetMIMEType(const MdlImgEncoding_E p_mimeType);
        /// <summary>
        /// function to get image mime type
        /// </summary>
        /// <returns>returns image mimetype of image </returns>
        MdlImgEncoding_E GetMIMEType() const;
        /// <summary>
        /// Gets the compressed image size
        /// </summary>
        /// <returns>compressed size </returns>
        GLsizei GetCompressedImageSize() const;
        /// <summary>
        /// Set image bufferview index
        /// </summary>
        /// <param name="p_bufferView"> image bufferview index</param>
        void SetBufferView(const int32_t p_bufferView);
        /// <summary>
        /// function to get image bufferview index
        /// </summary>
        /// <returns>returns image bufferview index </returns>
        int32_t GetBufferView() const;
        /// <summary>
        /// Set buffer data pointer
        /// </summary>
        /// <param name="p_buffer"> image buffer data pointer</param>
        void SetBuffer(const CHAR8* const p_buffer);
        /// <summary>
        /// function to image of start of buffer
        /// </summary>
        /// <returns>returns pointer image buffer </returns>
        const CHAR8* GetBuffer() const;
        /// <summary>
        /// Set image buffer length
        /// </summary>
        /// <param name="p_buffer_length"> image buffer length</param>
        void SetBufferLength(const size_t p_buffer_length);
        /// <summary>
        /// function to get image buffer length
        /// </summary>
        /// <returns>returns image buffer length </returns>
        size_t GetBufferLength() const;
        /// <summary>
        /// Set image width
        /// </summary>
        /// <param name="p_width"> image width</param>
        void SetWidth(const int32_t p_width);
        /// <summary>
        /// function to get image width
        /// </summary>
        /// <returns>returns image width </returns>
        GLsizei GetWidth() const;
        /// <summary>
        /// Set image height
        /// </summary>
        /// <param name="p_height"> image height</param>
        void SetHeight(const int32_t p_height);
        /// <summary>
        /// function to get image Height
        /// </summary>
        /// <returns>returns image height </returns>
        GLsizei GetHeight() const;
        /// <summary>
        /// function to get format of the image
        /// </summary>
        /// <returns>returns format of the image </returns>
        MdlImgFormat_E GetFormat() const;
        /// <summary>
        /// Set the pixel format of image
        /// </summary>
        /// <param name="p_component"> pixel format of image</param>
        void SetFormat(const MdlImgFormat_E p_format);
        /// <summary>
        /// function to get parent/display pointer
        /// </summary>
        /// <returns>returns pointer to parent/display pointer </returns>
        gfx3d_scg_display* GetParent() const;
        /// <summary>
        /// function to get parent/display pointer
        /// </summary>
        /// <returns>returns pointer to parent/display pointer </returns>
        gfx3d_scg_display* GetDisplay() const;
        /// <summary>
        /// Sets the parent display of this camera
        /// <param name="p_disp">pointer to display</param>
        /// </summary>
        void SetDisplay(gfx3d_scg_display* const p_disp);
        /// <summary>
        /// Gets the stride in pixels
        /// </summary>
        /// <returns>returns the stride in pixels </returns>
        GLsizei GetStride() const;
        /// <summary>
        /// Gets the unpack alignment for image
        /// </summary>
        /// <returns>returns the unpack alignment </returns>
        GLint GetUnpackAlignment() const;
        /// <summary>
        /// Sets the unpack alignment for image
        /// </summary>
        //// <param name="p_align"> unpack alignment for image</param>
        void SetUnpackAlignment(const GLint p_align);
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
        /// Gets the maximum number of threads which can be used.
        /// </summary>
        uint32_t GetMaxThreadCount(void);
    };
    /// @}
}
#endif