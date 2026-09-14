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
/// @file gfx3d_scg_font.h
/// @author emanoj1@visteon.com, mpandey@visteon.com
/// @brief GFX3D font object. Holds the property and rasterization of a font object. 
/// @date 11-Sep-2018
/// @copyright © 2019, Visteon Corporation, All Rights Reserved
///////////////////////////////////////////////////////////////////////////////
#ifndef gfx3d_scg_font_h
#define gfx3d_scg_font_h

#include <vector>
#include "gfx3d_scg_types.h"
#include "rc_text_attrib.h"
#include "rc_image_decoder.h"

namespace rendercore_engine
{
    struct scg_font_info
	{
		float32_t point_size = 0.0F;        ///< point size to be used to rasterize this font 
        float32_t baselineOffsetPerc = 0.0F; ///< percentage offset that must be applied to text (range -1.0 to 1.0)
        bool  baselineOffsetSnapToPixels = true; ///< whether the baselineOffsetPerc to be adjusted in pixels or subpixels
        std::string uri;                ///< path to the font file (e.g. ttf file)
		std::string family;             ///< font family name
		MdlFontStyle style = MdlFontStyle::fsNormal;             ///< style to be used.
		MdlFontRenderHint hint = MdlFontRenderHint::rhDefault;   ///< hinting options for the font
    };
    /// \ingroup Internal
    /// @{
    /// eum for pixel formats available
    enum rc_text_pixel_format
    {
        RC_TEXT_PIXFORMAT_4BPP, ///< pix format 4 bits per pixel - Alpha4
        RC_TEXT_PIXFORMAT_8BPP, ///< pix format 8 bits per pixel - Alpha8
        /// pix format 16 bits per pixel / 8bit x 2 channels.
        /// Dual channel to support two colors in text outline effect
        RC_TEXT_PIXFORMAT_RG8,
        RC_TEXT_PIXFORMAT_32BPP ///< pix format 32 bits per pixel (ARGB8888)
    };
    /// Holds the information about a single embedded icon
    struct rc_text_color_icon
    {
        rc_imgDecoderData data; ///< decoded icon png information (width, height, pixels etc)
        uint16_t width;         ///< required icon width (icon scale factor is width/data.width)
        uint16_t height;        ///< required icon height (icon scale factor is height/data.height)
        int16_t  x;             ///< x offset for the icon
        int16_t  y;             ///< y offset for the icon
    };
    /// @}
    /// \ingroup Internal
    /// @{
    /// <summary>	
    /// Output data from text rasterization.
    /// < / summary>	
    struct rc_text_pixels
    {
        /// format - format of the rasterized buffer (currently either 8bit alpha or 4bit alpha buffers)
        rc_text_pixel_format format = rc_text_pixel_format::RC_TEXT_PIXFORMAT_8BPP;
        /// pixels - pointer to pixel buffer
        UCHAR8* pixels = nullptr;
        /// width - width of the pixel buffer
        GLuint width = 0U;
        /// height - height of the pixel buffer
        GLuint height = 0U;
        /// overflow - true if the overflow handling is taken (text doesnot fot in available width), false - text fits in given width
        bool overflow = false;
        /// <summary>
        /// Incase if nothing is rendered to the pixels buffer, it will be true
        /// </summary>
        bool emptyPixels = false;
    };
    /// @}
    /// \ingroup Internal
    /// @{
    /// <summary>	
    /// rc_text_font_metrics captures the params needed for font rendering
    /// < / summary>	
    struct rc_text_font_metrics
    {
        int32_t os2_win_ascent_px = 0;    ///< ascender from 'OS/2' table -> usWinAscent in pixels
        int32_t os2_win_descent_px = 0;   ///< descender from 'OS/2' table -> usWinDescent in pixels
        int32_t os2_ascent_px = 0;        ///< ascender from 'OS/2' table -> sTypoAscender in pixels
        int32_t os2_descent_px = 0;       ///< descender from 'OS/2' table -> sTypoDescender in pixels
        int32_t sCapHeight_px = 0;        ///< Height of uppercase letters in pixels
        int32_t sxHeight_px = 0;          ///< Height of lowercase letters in pixels
        int32_t max_ascender = 0;         ///< Max of (usWinAscent, sTypoAscender in pixels
        int32_t max_descender = 0;        ///< Max of (usWinDescent , sTypoDescender) in pixels
        int32_t line_height = 0;          ///< line height in pixels
        float32_t fmax_ascender = 0.0F;   ///< max_ascender in float32_t pixels
    };
    /// @}
    class rc_text_bound_box
    {
    public:
        float32_t sx = 0.0F; ///< x position of the left most active pixel 
        float32_t sy = 0.0F; ///< y position of the top most active pixel 
        float32_t ex = 0.0F; ///< x position of the right most active pixel
        float32_t ey = 0.0F; ///< y position of the bottom most active pixel
        float32_t exmargin = 0.0F; ///< difference between right most active pixel and the advance x of last character (indicates the transparent margin)
        float32_t eymargin = 0.0F; ///< difference between bottom most active pixel and the height of font (indicates the transparent margin)
        int32_t GetWidth() const; ///< Returns the width of the text box inclusing the left and right margins
        int32_t GetWidth(const rc_textbox_attrib& p_datain) const; ///< width considering alignment
        int32_t GetHeight(const rc_textbox_attrib& p_datain) const;///< height considering alignment
        int32_t GetHeight() const;///< Returns the height of the text box inclusing the left and right margins
        int32_t GetBoundX() const;///< Returns the width of the text bounding box
        int32_t GetBoundY() const;///< Returns the height of the text bounding box
        void Clear();
    };
    struct rc_text_render_char_info
    {
        float32_t top;
        float32_t left;
        float32_t width;
        float32_t height;
        float32_t xadvance;
        float32_t yadvance;
        UCHAR8* bitmap_buffer;
        void* handle;
        uint32_t glyph_id;
        uint32_t bpp;
        uint32_t size;
    };
    struct rc_glyph_info
    {
        uint32_t codepoint = 0U;
        float32_t x_advance = 0.0F;
        float32_t x_drawn = 0.0F;
        float32_t y_advance = 0.0F;
        float32_t x_offset = 0.0F;
        float32_t y_offset = 0.0F;
        float32_t width = 0.0F;
    };

    class rc_text_shaper_info
    {
    private:
        std::vector<rc_glyph_info> tinfo;
        bool rtl_flag;
        rc_text_bound_box bouding_box;
    public:
        inline rc_text_shaper_info()
        {
            rtl_flag = false;
        }
        inline void SetRtlFlag(const bool p_val)
        {
            rtl_flag = p_val;
        }
        inline bool GetRtlFlag() const
        {
            return(rtl_flag);
        }
        inline void SetGlyphCount(const uint32_t p_val)
        {
            const size_t fl_tmp = static_cast<size_t>(p_val);
            tinfo.resize(fl_tmp);
        }
        inline uint32_t GetGlyphCount() const
        {
            const uint32_t fl_tmp = static_cast<uint32_t>(tinfo.size());
            return(fl_tmp);
        }
        inline void SetBoudingBox(const rc_text_bound_box p_val)
        {
            bouding_box = p_val;
        }
        inline const rc_text_bound_box& GetBoudingBox() const
        {
            return(bouding_box);
        }
        inline void SetCodePoint(const size_t p_index, const uint32_t p_val)
        {
            if (p_index >= tinfo.size())
            {
                tinfo.resize(p_index + 1U);
            }
            if (p_index < tinfo.size())
            {
                tinfo[p_index].codepoint = p_val;
            }
        }
        inline void SetXAdvance(const size_t p_index, const float32_t p_val)
        {
            if (p_index >= tinfo.size())
            {
                tinfo.resize(p_index + 1U);
            }
            if (p_index < tinfo.size())
            {
                tinfo[p_index].x_advance = p_val;
            }
        }
        inline void SetYAdvance(const size_t p_index, const float32_t p_val)
        {
            if (p_index >= tinfo.size())
            {
                tinfo.resize(p_index + 1U);
            }
            if (p_index < tinfo.size())
            {
                tinfo[p_index].y_advance = p_val;
            }
        }
        inline void SetXOffset(const size_t p_index, const float32_t p_val)
        {
            if (p_index >= tinfo.size())
            {
                tinfo.resize(p_index + 1U);
            }
            if (p_index < tinfo.size())
            {
                tinfo[p_index].x_offset = p_val;
            }
        }
        inline void SetYOffset(const size_t p_index, const float32_t p_val)
        {
            if (p_index >= tinfo.size())
            {
                tinfo.resize(p_index + 1U);
            }
            if (p_index < tinfo.size())
            {
                tinfo[p_index].y_offset = p_val;
            }
        }
        inline void SetXDrawn(const size_t p_index, const float32_t p_val)
        {
            if (p_index >= tinfo.size())
            {
                tinfo.resize(p_index + 1U);
            }
            if (p_index < tinfo.size())
            {
                tinfo[p_index].x_drawn = p_val;
            }
        }
        inline void SetWidth(const size_t p_index, const float32_t p_val)
        {
            if (p_index >= tinfo.size())
            {
                tinfo.resize(p_index + 1U);
            }
            if (p_index < tinfo.size())
            {
                tinfo[p_index].width = p_val;
            }
        }
        inline uint32_t GetCodePoint(const size_t p_index) const
        {
            uint32_t fl_val;
            if (p_index < tinfo.size())
            {
                fl_val = tinfo[p_index].codepoint;
            }
            else
            {
                RcDebugErrorLogId(rc_error_logId::elFontCodePointOverIndexing);
                fl_val = 0U;
            }
            return(fl_val);
        }
        inline float32_t GetXAdvance(const size_t p_index) const
        {
            float32_t fl_val;
            if (p_index < tinfo.size())
            {
                fl_val = tinfo[p_index].x_advance;
            }
            else
            {
                RcDebugErrorLogId(rc_error_logId::elFontXAdvanceOverIndexing);
                fl_val = 0.0F;
            }
            return(fl_val);
        }
        inline float32_t GetYAdvance(const size_t p_index) const
        {
            float32_t fl_val;
            if (p_index < tinfo.size())
            {
                fl_val = tinfo[p_index].y_advance;
            }
            else
            {
                RcDebugErrorLogId(rc_error_logId::elFontYAdvanceOverIndexing);
                fl_val = 0.0F;
            }
            return(fl_val);
        }
        inline float32_t GetXOffset(const size_t p_index) const
        {
            float32_t fl_val;
            if (p_index < tinfo.size())
            {
                fl_val = tinfo[p_index].x_offset;
            }
            else
            {
                RcDebugErrorLogId(rc_error_logId::elFontXOffsetOverIndexing);
                fl_val = 0.0F;
            }
            return(fl_val);
        }
        inline float32_t GetYOffset(const size_t p_index) const
        {
            float32_t fl_val;
            if (p_index < tinfo.size())
            {
                fl_val = tinfo[p_index].y_offset;
            }
            else
            {
                RcDebugErrorLogId(rc_error_logId::elFontYOffsetOverIndexing);
                fl_val = 0.0F;
            }
            return(fl_val);
        }
        inline float32_t GetXDrawn(const size_t p_index) const
        {
            float32_t fl_val;
            if (p_index < tinfo.size())
            {
                fl_val = tinfo[p_index].x_drawn;
            }
            else
            {
                RcDebugErrorLogId(rc_error_logId::elFontXDrawnOverIndexing);
                fl_val = 0.0F;
            }
            return(fl_val);
        }
        inline float32_t GetWidth(const size_t p_index) const
        {
            float32_t fl_val;
            if (p_index < tinfo.size())
            {
                fl_val = tinfo[p_index].width;
            }
            else
            {
                RcDebugErrorLogId(rc_error_logId::elFontWidthOverIndexing);
                fl_val = 0.0F;
            }
            return(fl_val);
        }
        bool InsertGlyphInfo(const size_t p_index, const rc_text_render_char_info& p_val);
    };

    /// \ingroup Engine
    /// @{
    /// <summary>
    /// stores the font engine data related with a font
	/// </summary>
    class gfx3d_scg_font
	{
    protected:
        gfx3d_scg_project * parent = nullptr; ///< parent object of this font node. It will be pointing to the project
        GLuint height = 0U;                  ///< Height of font in pixels
        float32_t linespace = 0.0F;          ///< Linespace for font
        rc_text_font_metrics metrics;       ///< Font Metrics
        scg_font_info font_info;            ///< Font configurations
        std::string name;                   ///< Name of the font
        bool bLoaded = false;              ///< true indicates the font is loaded
	private:
        void Get_text_width(rc_lbpara* const p_line, rc_text_shaper_info& p_text_shape_info, const rc_textbox_attrib& p_datain);
        virtual bool LoadExt(void);
        virtual void UnLoadExt(void);
        bool Get_display_string(const rc_textbox_attrib& p_datain, rc_text_shaper_info& p_shape_info_ptr);
        UCHAR8* renderBuffer = nullptr;
        size_t renderBufferLength = 0U;	
        /// Chooses the height calculation method to be used for fonts
        MdlFontHeightCalc_E fontHeightCalcMthd = MdlFontHeightCalc_E::fhUseMaxOfTypoAndWin;
        gfx3d_scg_font& operator= (const gfx3d_scg_font& p_src);
        /// <summary>
        /// Renders the text
        /// </summary>
        /// <param name="p_datain">text attributes</param>
        /// <param name="p_text_pixout">out - output pixel buffer</param>
        /// <param name="p_bouding_box">out - bounding box of rendered text</param>
        /// <param name="p_icons">out - list of icons and its properties if present</param>
        /// <param name="p_text_shape_info">shaping info for the text</param>
        /// <returns></returns>
        bool createTextTexture(const rc_textbox_attrib& p_datain, const rc_text_shaper_info& p_text_shape_infoin, rc_text_pixels& p_text_pixout, std::vector<rc_text_color_icon>* const p_icons);
        gfx3d_font_properties* GetFontProperty();
    public:
        static const char16_t append_character = u'\x2026';    ///< Append character (ellipses)
        static const char16_t invalid_character = u'\xFFFE';   ///< Invalid character id. These are skipped
		/// <summary>
		/// Constructor for a gfx3d_scg_font class. Accepts the parent project as a parameter and writes this to parent property
        //  Loads default values for the properties and creates an instance of a text engine  (rc_text_engine)
		/// </summary>
		gfx3d_scg_font(gfx3d_scg_project* const p_proj);
        gfx3d_scg_font(const gfx3d_scg_font* const p_obj);
        gfx3d_scg_font(const gfx3d_scg_font& p_obj);
		/// <summary>
		/// Destructor for a gfx3d_scg_font class.
		/// </summary>
		virtual ~gfx3d_scg_font();
		/// <summary>
		/// Loads the font object by loading the ttf file and settingup the rasterizer ready to accept draw requests.
        /// Also its expected that gfx3d_scg_font be inherited and a custom class loads the properties (e.g. uri, point_size etc..) in its override Load
        /// method before invoking the base Load method.
		/// </summary>
        bool Load(void);
        /// virtual unload font
        void UnLoad(void);
        /// <summary>
        /// Resizes the font inline (i.e. in the call)..
        /// </summary>
        /// <param name="p_pt_size">point size to be applied for this font object..</param>
        /// <returns>returns true if the SetSize was successful, false if unsuccessfull or same size</returns>
        bool Resize(const float32_t p_pt_size);
        /// <summary>
        /// Set font Point Size for the font. This call only updates the property and no real resize operation happens.
        /// So this is primarily useful only during construction of the font object, so that the property can be updated
        /// with default value. And a Load() will apply this to the font. 
        /// For runtime change of point size, rather use Resize() api
        /// </summary>
        /// <param name="p_point_size">Font Point Size of type float32_t</param>
        void SetPointSize(const float32_t p_point_size);
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
        /// function to get pointer to parent project
        /// </summary>
        /// <returns>returns pointer to parent project </returns>
        gfx3d_scg_project *GetParent() const;
        /// <summary>
        /// Set pointer to parent project
        /// </summary>
        /// <param name="p_parent">pointer to parent project</param>
        void SetParent(gfx3d_scg_project * const p_parent);
        /// <summary>
        /// Returns font point Size
        /// </summary>
        /// <returns>Font Point Size</returns>
        float32_t GetPointSize() const;
        /// <summary>
        /// function to get font uri of type string
        /// </summary>
        /// <returns>returns font uri of image </returns>
        std::string GetURI() const;
        /// <summary>
        /// Set image uri
        /// </summary>
        /// <param name="p_uri"> image uri </param>
        void SetURI(const std::string p_uri);
        /// <summary>
        /// Set font uri
        /// </summary>
        /// <param name="p_uri"> font uri </param>
        virtual void SetURIExt(const std::string p_uri);
        /// <summary>
        /// function to return font family
        /// </summary>
        /// <returns>returns font family</returns>
        std::string GetFamily() const;
        /// <summary>
        /// Set font family
        /// </summary>
        /// <param name="p_family">Font family of type String</param>
        void SetFamily(const std::string p_family);
        /// <summary>
        /// function to get font style
        /// </summary>
        /// <returns>returns the font style</returns>
        MdlFontStyle GetStyle() const;
        /// <summary>
        /// Set font Style
        /// </summary>
        /// <param name="p_style">Font Style of type MdlFontStyle</param>
        void SetStyle(const MdlFontStyle p_style);
        /// <summary>
        /// function to get font hint
        /// </summary>
        /// <returns>returns font hint</returns>
        MdlFontRenderHint GetHint() const;
        /// <summary>
        /// Set font hint 
        /// </summary>
        /// <param name="p_hint">hint of type MdlFontRenderHint</param>
		void SetHint(const MdlFontRenderHint p_hint);
        /// <summary>
        /// Set Baseline Offset Percentage value to be applied
        /// </summary>
        /// <param name="p_hint">percentage value in range -1.0 to 1.0</param>
        void SetBaselineOffsetPercentage(const float32_t p_val);
        /// <summary>
        /// Returns Baseline Offset Percentage value applied
        /// </summary
        /// <returns>percentage value set currently in range -1.0 to 1.0</returns>
        float32_t GetBaselineOffsetPercentage() const;
        /// <summary>
        /// Set Baseline Offset Percentage value snap to pixels or not
        /// When set offset will change 1 pixel resolution only, else at float32_t values
        /// </summary>
        /// <param name="p_hint">true to snap else false</param>
        void SetBaselineOffsetSnapToPixels(const bool p_snap);
        /// <summary>
        /// Get the current BaselineOffsetSnapToPixels setting
        /// </summary
        /// <returns>true if snap to pixels is set</returns>
        bool IsBaselineOffsetSnapToPixels() const;
        /// <summary>
        /// Returns Baseline Offset in pixels. Converted from value set via SetBaselineOffsetPercentage()
        /// </summary
        /// <returns>baseline offset in pixels</returns>
        float32_t GetBaselineOffsetInPixels(void) const;
        ///virtual render text
        virtual bool Render(const rc_textbox_attrib& p_datain, rc_text_pixels& p_text_pixout, rc_text_bound_box& p_bouding_box, std::vector<rc_text_color_icon> * const p_icons = nullptr);
        /// <summary>
        /// Returns the bounding box of passed string with currently set font configuration
        /// </summary>
        /// <param name="p_text">String to measure</param>
        /// <param name="p_charSpacing">intercharacrer spacing to be considered</param>
        /// <returns>The bounding box of string</returns>
        rc_text_bound_box  MeasureString(const rc_mlstring& p_text, const rc_textbox_attrib& p_datain);
        /// <summary>
        /// Returns the bounding box of passed string with currently set font configuration
        /// p_datain.charSpacing and p_datain.oflowMode
        /// Also limits the text width to the p_datain.bboxWidthPx 
        /// </summary>
        /// <param name="p_datain">textbox configuration</param>
        /// <param name="p_charSpacing"></param>
        /// <returns></returns>
        rc_text_bound_box  MeasureString(const rc_textbox_attrib& p_datain);
        ///get height 
        GLuint GetHeight();
        ///get linespace 
        float32_t GetLineSpacing() const;
        /// <summary>
        /// sets linespace of font in pixels
        /// </summary>
        /// <returns></returns>
        void SetLineSpacing(const float32_t p_linespace);
        /// <summary>
        /// function to get font metrics object (Note : May not reflect latest font property changes until Load() is performed. Object reflects last loaded values)
        /// <returns>returns rc_text_font_metrics object</returns>
        /// </summary>
        rc_text_font_metrics* GetMetrics(void);
        /// <summary>
        /// Returns the fonts default character code
        /// </summary>
        /// <returns>returns font's default character </returns>
        char32_t GetDefaultChar();
        /// <summary>
        /// Set default character all fonts
        /// If the given text string has character codes not present in font
        /// file, it will be replaced with this default character
        /// Its default value is Unicode 0xFFFD
        /// </summary>
        /// <param name="p_default_char"> font's default character </param>
        void SetDefaultChar(const char32_t p_default_char);
        /// <summary>
        /// Returns the shaper output for the given textbox
        /// </summary>
        /// <param name="p_string">input string to be shaped</param>
        /// <param name="p_text_shaping_info">storage for shaping result</param>
        /// <param name="p_datain">textbox attributes</param>
        /// <returns>true on success</returns>
        virtual bool GetTextShapingInfo(const rc_mlstring& p_string, rc_text_shaper_info& p_text_shaping_info, const rc_textbox_attrib& p_datain);
        /// <summary>
        /// Returns the shaper output for the given textbox
        /// </summary>
        /// <param name="p_string">input string to be shaped</param>
        /// <param name="p_text_shaping_info">storage for shaping result</param>
        virtual bool GetTextShapingInfo(rc_lbpara* const p_line, rc_text_shaper_info& p_text_shaping_info);
        /// <summary>
        /// Returns the rasterized char
        /// </summary>
        /// <param name="p_char">char code to be rasterized</param>
        /// <param name="p_is_char">if p_char is unicode then pass true. If its glyph id pass false</param>
        /// <param name="p_text_render_info">storage for rasterization result</param>
        /// <param name="p_outlineWidth">width of outline if applicable</param>
        /// <returns></returns>
        virtual bool GetCharRenderInfo(const uint32_t p_char, const bool p_is_char, rc_text_render_char_info& p_text_render_info, const uint8_t p_outlineWidth);
        /// <summary>
        /// Freeup the CharRenderInfo after the usage
        /// </summary>
        /// <param name="p_text_render_info">result received by a previous call to GetCharRenderInfo</param>
        virtual bool CharRenderInfoDone(const rc_text_render_char_info& p_text_render_info) const;
        /// <summary>
        /// Returns the base direction of text based on bidi algo
        /// </summary>
        /// <param name="p_string">input text to get the base direction </param>
        /// <returns>return the bidi base direction of text </returns>
        static mdl_textBidiDir_E GetBaseDirection(const std::u16string& p_string);
        /// <summary>
        /// Gets the current font height calculation method employed
        /// </summary>
        /// <returns>MdlFontHeightCalc_E</returns>
        MdlFontHeightCalc_E GetFontHeightCalcMethod() const;
        /// <summary>
        /// Sets the current font height calculation method to be employed
        /// Please note that the MdlFontHeightCalc_E to be set only at the start
        /// API is not designed for continuous changes during run time
        /// </summary>
        /// <param name="p_method">MdlFontHeightCalc_E</param>
        void SetFontHeightCalcMethod(const MdlFontHeightCalc_E p_method);
        /// <summary>
        /// Perform glyph metrics updation on the shaper output (GetTextShapingInfo)
        /// Gets the character render info for each glyphs and updates them to rc_text_shaper_info
        /// Finnaly updates the text bounding box to rc_text_shaper_info
        /// </summary>
        /// <param name="p_text_shape_info">storage for shaping result</param>
        /// <param name="p_datain">textbox attributes</param>
        void UpdateTextCharRenderInfo(rc_text_shaper_info& p_text_shape_info, const rc_textbox_attrib& p_datain);
        /// <summary>
        /// Return the extended pixels needed for the render buffer.
        /// Currently by default a 1 pixel margin is applied around the text and on top an 
        /// extended margin is applied to all sides of the buffer based on p_outlineWidth
        /// </summary>
        /// <param name="p_outlineWidth">Outline width in pixels</param>
        /// <returns></returns>
        static size_t GetRenderBufferMargin(size_t p_outlineWidth);
    };
    /// @}
	
}


#endif