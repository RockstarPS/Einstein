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
//  Filename    : rc_png_decoder.h
//  Description : PNG decoder APIs
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file rc_image_decoder.h
///	\brief		PNG decoder APIs
#ifndef rc_png_decoder_h
#define rc_png_decoder_h

#include <memory>

namespace rendercore_engine
{
    /// \ingroup Internal
    /// @{

    /// result of the image decoding
    class rc_imgDecoderData
    {
    private:
        /// indicating an offset from where actual pixel data starts. 
        /// Its a special case for ktx images where there is no decoding involved and 
        /// points to an offset in to same source 'buffer' data itself.
        /// in this case pixels = &buffer[0] and offPixels = &buffer[offset to pixels]
        const CHAR8* offPixels = nullptr;
        const CHAR8* pixels = nullptr; ///< pointer to pixel data. if offPixels is not null it takes precedance
        GLsizei width = 0;      ///< width in pixels
        GLsizei height = 0;     ///< height in pixels
        GLsizei stride = 0;     ///< pixels per horizontal line
        GLsizei size = 0;       ///< incase of compressed pixels, indicates the size
        MdlImgFormat_E format = MdlImgFormat_E::ifUnset; ///< format of the pixel data
        GLint alignment = 1;    ///< unpack alignment
    public:
        inline GLsizei GetWidth() const
        {
            return(width);
        }
        inline GLsizei GetHeight() const
        {
            return(height);
        }
        inline GLsizei GetStride() const
        {
            return(stride);
        }
        inline GLsizei GetSize() const
        {
            return(size);
        }
        inline MdlImgFormat_E GetFormat() const
        {
            return(format);
        }
        inline GLint  GetAlignment() const
        {
            return(alignment);
        }
        inline const CHAR8* GetPixels() const
        {
            const CHAR8* fl_pix;
            if (offPixels != nullptr)
            {
                fl_pix = offPixels;
            }
            else
            {
                fl_pix = pixels;
            }
            return(fl_pix);
        }
        inline const CHAR8* GetBaseData() const
        {
            return(pixels);
        }
        inline void SetBaseData(const CHAR8* const p_data)
        {
            pixels = p_data;
            offPixels = nullptr;
        }
        inline void SetOffPixels(const CHAR8* const p_data)
        {
            offPixels = p_data;
        }
        inline const CHAR8* GetOffPixels() const
        {
            return(offPixels);
        }
        inline void SetWidth(const GLsizei p_value)
        {
            width = p_value;
        }
        inline void SetHeight(const GLsizei p_value)
        {
            height = p_value;
        }
        inline void SetStride(const GLsizei p_value)
        {
            stride = p_value;
        }
        inline void SetSize(const GLsizei p_value)
        {
            size = p_value;
        }
        inline void SetFormat(const MdlImgFormat_E p_value)
        {
            format = p_value;
        }
        inline void SetAlignment(const GLint p_value)
        {
            alignment = p_value;
        }
    };
    /// @}
    /// \ingroup Internal
    /// @{
    /// When rc_imgDecoderData::offset > 0, the rc_imgDecoderData::pixels will be same as input buffer
    /// Its a special case for ktx images where there is no decoding is necessary and no memory allocations
    /// are made for it.
    std::unique_ptr<rc_imgDecoderData> decode_from_memory(const UCHAR8 * const p_buffer, const ulong_t p_length); ///< decodes image data in passed memory and returns the result
    std::unique_ptr<rc_imgDecoderData> decode_from_file(const CHAR8* const p_filepath); ///< decodes image data in passed file and returns the result
    /// @}
    /// <summary>
    /// Internal data used by rc_png_decoder
    /// </summary>
    class rc_png_decdata;
    /// <summary>
    /// PNG decoder class. Can be used for one time decoding of PNG in to 
    /// user specified memory.
    /// </summary>
    class rc_png_decoder : public rc_imgDecoderData
    {
    private:
        gfx3d_scg_display* display = nullptr;
        /// <summary>
        /// Internal data to manage the decoding
        /// </summary>
        std::unique_ptr<rc_png_decdata> ddata;
        /// <summary>
        /// Storage for raw PNG data (will be freed after decode)
        /// </summary>
        const CHAR8* rawbytes = nullptr;
        /// <summary>
        /// Initialize the decoding, read the header information
        /// </summary>
        /// <param name="p_buffer">pointer to png data in memory</param>
        /// <param name="p_length">length in bytes of the p_buffer memory</param>
        void setup(const CHAR8* const p_buffer, const size_t p_length);
    public:
        /// <summary>
        /// Constructs the png decoder and decodes the header to load
        /// height, width, stride and format information
        /// </summary>
        /// <param name="p_buffer">pointer to memory which has the png data</param>
        /// <param name="p_length">length of the p_buffer in bytes</param>
        rc_png_decoder(const CHAR8* const p_buffer, const size_t p_length);
        /// <summary>
        /// Constructs the png decoder and decodes the header to load
        /// height, width, stride and format information
        /// </summary>
        /// <param name="p_filepath">path to the png file in resources</param>
        rc_png_decoder(const CHAR8* const p_filepath, gfx3d_scg_display * const p_display);
        /// <summary>
        /// Dtor
        /// </summary>
        ~rc_png_decoder();
        /// <summary>
        /// Decodes the png and writes the raw data to passed p_dstbuffer
        /// Note : to be called only once after ctor.
        ///        Second call onwards, does nothing and returns false
        /// </summary>
        /// <param name="p_dstbuffer">destination memory where the decoded pixels are written</param>
        /// <param name="p_dstlength">length of the destination buffer in bytes</param>
        /// <param name="p_dstformat">format of the destination buffer</param>
        /// <returns>true on success</returns>
        bool DecodeToMemory(UCHAR8* const p_dstbuffer, const size_t p_dstlength, const MdlImgFormat_E p_dstformat);
    };

}
#endif