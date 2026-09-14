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
//  Filename    : gfx3d_scg_node.h
//  Description : GFX3D scene graph node object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_scg_node.h
/// \brief GFX3D scene graph node object
#ifndef gfx3d_scg_3dtext_node_h
#define gfx3d_scg_3dtext_node_h

#include "gfx3d_behaviour.h"
#include "rc_text_attrib.h"
#include <deque>

namespace rendercore_engine
{
    /// \ingroup Internal
    /// @{
    /// <summary>
    /// Holds the rasterized texture and its margins. One instance per line will be maintained
    /// </summary>
    class gfx3d_text_ltexture
    {
    public:
        gfx3dTexture2D* tex = nullptr;      ///< Pointer to the 2D texture which holds the rasterized image
        float32_t offsetLeft = 0.0F;        ///< left side margin in pixels applicable for the texture
        float32_t offsetTop = 0.0F;         ///< top side margin in pixels applicable for the texture
        float32_t offsetRight = 0.0F;       ///< right side margin in pixels applicable for the texture
        float32_t offsetBottom = 0.0F;      ///< bottom side margin in pixels applicable for the texture
        /// <summary>
        /// Incase the text has color icons (special case for monotype), it holds a 
        /// list of icons and its positioning..
        /// </summary>
        std::vector<rc_text_color_icon> icons;
    };
    /// <summary>
    /// Local storage for retainig last loaded font data within text class to detect any changes to font properties that may affect
    /// text rendering
    /// </summary>
    struct gfx3d_text_font_info
    {
        std::string uri;                                         ///< path to the font file (e.g. ttf file)
        MdlFontStyle style = MdlFontStyle::fsNormal;             ///< style to be used.
        MdlFontRenderHint hint = MdlFontRenderHint::rhDefault;   ///< hinting options for the font
        float32_t line_height = 0.0F;                            ///< Local storage for the font line height which is retrived from font after loading of font. Value is stored in pre-render stage for usage during render stage
    };
    /// @}
    /// \ingroup Engine
    /// @{
    /// <summary>
	/// Text / Label node class. Rasterizes a text string and maps it to a quad.
    /// Manages the font, alignment, draw color and overflow mode of the text
	/// </summary>
    class gfx3d_scg_3dtext_node : public gfx3d_scg_node
    {
    private:
        std::vector<gfx3d_scg_node*> iconNodes;         ///< Pointer to color icon nodes
        rc_localization* loczn = nullptr;               ///< Pointer to localization data
        gfx3d_scg_font* font = nullptr;                 ///< current font object used by the text node
        rc_lbtext textLines;                            ///< Text string for each line
        std::vector <gfx3d_text_ltexture> textureLines; ///< Rasterized texture for each lines
        glm::vec4 textColor{ 1.0F };        		    ///< color of the text
        glm::vec4 effectColor{ 1.0F };        		    ///< color of the effect text
        rc_text_pixels output_obj;                      ///<holds the rasterized text object
        rc_textbox_attrib conf;                         ///<text box properties specific to rasterizing & multiline processing
        rc_wstring text;						        ///< text to be printed
        gfx3d_text_font_info fontInfo;                  ///< Local storage for the font info to determine change to font object.
        float32_t lineSpacing = 0.0F;                   ///< extra spacing added to the line spacing provided by font data
        float32_t size = 0.0F;                          ///< text font point size
        float32_t baselineOffPix = 0.0F;                ///< stored font baseline offset from pre_render() for render() loop
        GLuint font_height = 0U;                        ///< stored font height from pre_render() for render() loop
        uint8_t font_index = static_cast<uint8_t>(UINT8_MAX);			///<font indexing
        uint8_t lineCount = 1U;                  ///< number of lines to be rendered out of the GetTotalLineCount() avaialable
        uint8_t startLine = 0U;                  ///< start line index from where the rendering starts
        uint8_t renderedLineCount = 0U;          ///< calculated value at run time indicating number of lines rendered
        uint8_t curLanguage = 0U;                ///< Current language used by text node.
        bool is_textupdated = true;				 ///<is active when the text has been updated and requires a rasterization
        bool is_matupdated = true;				 ///<is active when the text material proeprties has been updated, in this case there is no rasterization is required.
        bool swapAlignment = false;              ///< Swaps the left and right alignment based on language
        bool lineBreakSingleLine = false;        ///< if true applies line breaking rule for single line text as well
        /// <summary>
        /// Calculates the bounding box for the whole text (single or multiline texts)
        /// </summary>
        /// <param name="p_halign">horizontal alignment of the text box</param>
        /// <param name="p_valign">vertical alignment of the text box</param>
        /// <param name="p_exact">if set the bounding box of the texture within text box is returned. If clear the bounding box of textbox</param>
        /// <param name="p_bound">Returned bounding box (p_bound.x=x,p_bound.y=y,p_bound.z=width,p_bound.w=height)</param>
        /// <returns></returns>
        bool get_layout_bound(const mdl_layoutHalign_E p_halign, const mdl_layoutValign_E p_valign, const bool p_exact, glm::vec4& p_bound) const;
        /// <summary>
        /// Calculates the bounding box for a single line of text. Bounding box retunr will be exact bound of the 
        /// rasterized texture drawn inside the textbox
        /// </summary>
        /// <param name="p_line">Line number (0 to N)</param>
        /// <param name="p_halign">horizontal alignment of the text box</param>
        /// <param name="p_valign">vertical alignment of the text box</param>
        /// <param name="p_bound">Returned bounding box (p_bound.x=x,p_bound.y=y,p_bound.z=width,p_bound.w=height)</param>
        /// <returns>true if success. false if failed. On failure p_bound wont be updated</returns>
        bool get_line_bound(const size_t p_line, const mdl_layoutHalign_E p_halign, const mdl_layoutValign_E p_valign, glm::vec4& p_lbound) const;
        /// <summary>
        /// Calculates the horizontal bound of the texture with in the textbox
        /// p_bound.z to be loaded with the textbox width in pixels, else the results are invalid.
        /// </summary>
        /// <param name="p_line">Line number (0 to N)</param>
        /// <param name="p_halign">horizontal alignment of the text box</param>
        /// <param name="p_bound">Returned bounding box (p_bound.x=x,p_bound.z=width)</param>
        /// <returns>true if success. false if failed. On failure p_bound wont be updated</returns>
        bool get_hbound(const size_t p_line, const mdl_layoutHalign_E p_halign, glm::vec4& p_lbound) const;
        /// <summary>
        /// Calculates the vertical bound of the texture with in the textbox
        /// p_bound.w to be loaded with the textbox height in pixels, else the results are invalid.
        /// </summary>
        /// <param name="p_line">Line number (0 to N)</param>
        /// <param name="p_valign">vertical alignment of the text box</param>
        /// <param name="p_bound">Returned bounding box (p_bound.y=y,p_bound.w=height)</param>
        /// <returns>true if success. false if failed. On failure p_bound wont be updated</returns>
        bool get_vbound(const size_t p_line, const mdl_layoutValign_E p_valign, glm::vec4& p_lbound) const;
        /// <summary>
        /// Cleanup the icons memory
        /// </summary>
        /// <param name="p_icons">icon array to cleanup</param>
        void clear_coloricons(std::vector<rc_text_color_icon>& p_icons) const;
        /// <summary>
        /// Perform pre rendering for icons. Create nodes and setup XY, scale 
        /// Note :- multiline is not suported so p_line is always 0 for now
        /// </summary>
        /// <param name="p_line">line number of the icon</param>
        void prerender_coloricons(const size_t p_line);
        /// <summary>
        /// Sets the line offset for icon. All icons in the specified line
        /// will be repositioned
        /// Note :- multiline is not suported so p_line is always 0 for now
        ///         same for xoff and yoff
        /// </summary>
        /// <param name="p_line">line number of the icon</param>
        /// <param name="p_xoff">line x offset</param>
        /// <param name="p_yoff">line y offset</param>
        void setxy_coloricons(const size_t p_line, const float32_t p_xoff, const float32_t p_yoff);
        /// <summary>
        /// Hides all icon nodes by turning off visibility
        /// </summary>
        void hideall_coloricons();
        /// <summary>
        /// Re loads the font object for this text
        /// </summary>
        void reload_font();
        /// <summary>
        /// Re sizes the font if the size has changed
        /// </summary>
        void resize_font();
        /// Distroy all text textures
        /// </summary>
        void destroyTextureLines();
    public:
        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="p_parent">parent node</param>
        gfx3d_scg_3dtext_node(gfx3d_scg_node* const p_parent);
        /// Copy construct
        gfx3d_scg_3dtext_node(const gfx3d_scg_3dtext_node& p_obj);
        /// Performs a shallow copy..
        gfx3d_scg_3dtext_node& operator=(const gfx3d_scg_3dtext_node& p_rhs) = delete;
        /// <summary>
        /// Distructor
        /// </summary>
        virtual ~gfx3d_scg_3dtext_node();
        /// <summary>
        /// Pre render operations for the text node (rendercore private).
        /// </summary>
        /// <param name="p_par_matrix">parent transformation matrix</param>
        /// <param name="p_visible">parent is visible or not</param>
        virtual void pre_render(const gfx3d_4x4mat& p_par_matrix, const bool p_visible, const rc_prmode p_mode, const uint32_t p_depth) override;
        /// <summary>
        /// renders the text node (rendercore private).
        /// </summary>
        /// <param name="p_prim">text node primitive</param>
        virtual void render(gfx3d_scg_primitive* const p_prim) override;
        /// <summary>
        /// Returns true if any text property has been changed (Unit Test API)
        /// </summary>
        /// <returns>returns true if updates pending</returns>
        bool GetIsTextUpdated() const;
        /// <summary>
        /// Returns true if any text material property has been changed (Unit Test API)
        /// </summary>
        /// <returns>returns true if updates pending</returns>
        bool GetIsMatUpdated() const;
        /// <summary>
        /// Set the text string value to be rendered by this text node
        /// The string is assumed to be utf16 encoded if char16_t size is 2bytes OR 32bit unicode if char16_t size is >= 4bytes
        /// </summary>
        /// <param name="p_text"> text as a wide string / std::u16string</param>		
        void SetText(const rc_wstring& p_text);
        void SetText(const rc_wstring&& p_text);
        /// <summary>
        /// Set the text string value to be rendered by this text node
        /// The string is assumed to be utf8 encoded and will be decoded to a wide string
        /// its more efficient set a wide string than string, since there is no conversion step involved
        /// </summary>
        /// <param name="p_text"> text as a string / std::string</param>		
        void SetText(const rc_string& p_text);
        void SetText(const rc_string&& p_text);
        /// <summary>
        /// Get the current text string value rendered by this text node
        /// The string is utf16 encoded if char16_t size is 2bytes OR 32bit unicode if char16_t size is >= 4bytes
        /// </summary>
        /// <returns>returns text as a wide string / std::u16string </returns>
        rc_wstring GetText() const;
        /// <summary>
        /// Set font id to be used by this text node. Font id is the index in to gfx3d_scg_project::fonts array
        /// </summary>
        /// <param name="p_fontIndex"> text font id</param>
        void SetFontIndex(size_t p_fontIndex);
        /// <summary>
        /// Get font id used by this text node. Font id is the index in to gfx3d_scg_project::fonts array
        /// </summary>
        /// <returns>returns font id </returns>
        size_t GetFontIndex() const;
        /// <summary>
        /// Get pointer to font used by this text node.
        /// </summary>
        /// <returns>returns font</returns>
        gfx3d_scg_font* GetFont() const;
        /// <summary>
        /// Set horizontal alignment e.g. left/right/center of the text
        /// </summary>
        /// <param name="p_horzAlign"> horizontal alignment</param>
        void SetHorizontalAlignment(const mdl_layoutHalign_E p_horzAlign);
        /// <summary>
        /// Get the horizontal alignment
        /// </summary>
        /// <returns>returns horizontal alignment </returns>        
        mdl_layoutHalign_E GetHorizontalAlignment() const;
        /// <summary>
        /// Set text overflow mode clip/ellipsis of type mdl_textOverflowMode_E
        /// </summary>
        /// <param name="p_oflowMode"> text overflow mode</param>
        void SetTextOverFlowMode(const mdl_textOverflowMode_E p_oflowMode);
        /// <summary>
        /// Get text overflow mode clip/ellipsis of type mdl_textOverflowMode_E
        /// </summary>
        /// <returns>returns overflow mode </returns>
        mdl_textOverflowMode_E GetTextOverFlowMode() const;
        /// <summary>
        /// Set Verticle alignment as top/center/bottom
        /// </summary>
        /// <param name="p_vertAlign">Vertical alignment</param>
        void SetVerticalAlignment(const mdl_layoutValign_E p_vertAlign);
        /// <summary>
        /// Get the Verticle alignment as top/center/bottom
        /// </summary>
        /// <returns>returns Vertical alignment </returns>
        mdl_layoutValign_E GetVerticalAlignment() const;
        /// <summary>
        /// function to get if text is updated (internal usage)
        /// </summary>
        /// <returns>returns true if text is updated, false otherwise </returns>
        bool IsUpdated() const;
        /// <summary>
        /// Set true if text is updated, false otherwise. Setting to true forces rasterizing the text again.
        /// </summary>
        /// <param name="p_is_updated"> true if text need an update </param>
        void SetUpdated(const bool p_is_updated);
        /// <summary>
        /// Returns the currently used rendercore_engine::gfx3dTexture2D object of the text node (Unit Test APIs)
        /// the rasterized text is held by rendercore_engine::gfx3dTexture2D object..
        /// </summary>
        /// <returns>returns pointer to rendercore_engine::gfx3dTexture2D</returns>
        gfx3dTexture2D* GetTexture(const size_t p_line = 0) const;
        /// <summary>
        /// function to get 3d font text color
        /// </summary>
        /// <returns>returns 3d font text color </returns>
        glm::vec4 GetColor() const;
        /// <summary>
        /// Set text color 
        /// </summary>
        /// <param name="p_color"> color of text as glm::vec4 for RGBA value </param>
        void SetColor(const glm::vec4 p_color);
        /// <summary>
        /// Set text font point size
        /// This call only updates the property and no real resize operation happens until the next render loop runs.
        /// Incase the intension is make the size change immediate.. use ReSize() instead.
        /// </summary>
        /// <param name="p_size"> text font point size of type float32_t </param>
        void SetSize(const float32_t p_size);
        /// <summary>
        /// Set text font point size inline, so the MeasureString() apis will return with new point size
        /// Note : 
        ///  1. ReSize() has no effect if a SetSize has been issued earlier for the same size
        ///     (i.e SetSize(12.3f); followed by ReSize(12.3f) will not set the point size inline.
        ///      Sequencing is important.)
        ///  2. Resize is ignored if the font is invalid. i.e. SetFontIndex() sets an invalid index
        ///     and GetFont() is returning a null pointer
        /// </summary>
        /// <param name="p_size"> text font point size of type float32_t </param>
        void ReSize(const float32_t p_size);
        /// <summary>
        /// function to get render target color size
        /// </summary>
        /// <returns>returns 3d text font point size </returns>
        float32_t GetSize() const;
        /// <summary>
        /// Set 3d text node's bounding box width
        /// </summary>
        /// <param name="p_bboxWidthPx"> bounding box width of type int </param>
        void SetBoundingBoxWidth(const uint32_t p_bboxWidthPx);
        /// <summary>
        /// function to get bounding box width of type int
        /// </summary>
        /// <returns>returns bounding box width of type int </returns>
        uint32_t GetBoundingBoxWidth() const;
        /// <summary>
        /// Set 3d text node's bounding box height
        /// </summary>
        /// <param name="p_bboxHeightPx"> bounding box height of type int </param>
        void SetBoundingBoxHeight(const uint32_t p_bboxHeightPx);
        /// <summary>
        /// function to get bounding box height of type int
        /// </summary>
        /// <returns>returns bounding box height of type int </returns>
        uint32_t GetBoundingBoxHeight() const;
        /// <summary>
        /// Set space between characters
        /// </summary>
        /// <param name="p_charSpacePx"> space between character of type int </param>
        void SetCharacterSpace(const int32_t p_charSpacePx);
        /// <summary>
        /// Get space between characters
        /// </summary>
        /// <returns>returns space between characters </returns>
        int32_t GetCharacterSpace(void) const;
        /// <summary>
        /// Set multiline text wrap mode
        /// </summary>
        /// <param name="p_wrap">  </param>
        void SetWordWrap(const mdl_mlWordWrap_E p_wrap);
        /// <summary>
        /// Get multiline text wrap mode
        /// </summary>
        /// <returns>returns multiline text wrap mode </returns>
        mdl_mlWordWrap_E GetWordWrap(void) const;
        /// <summary>
        /// Get the current word break settings
        /// </summary>
        /// <returns>WordBreak setting</returns>
        mdl_mlWordBreak_E GetWordBreak() const;
        /// <summary>
        /// Sets the current work break settings
        /// </summary>
        /// <param name="p_wbreak">WordBreak setting</param>
        void SetWordBreak(const mdl_mlWordBreak_E p_wbreak);
        /// <summary>
        /// Set multiline text line count that are allowed to be rendered.
        /// </summary>
        /// <param name="p_lineCount">  </param>
        void SetLineCount(size_t p_lineCount);
        /// <summary>
        /// Get multiline text line count
        /// </summary>
        /// <returns>returns multiline text line count </returns>
        size_t GetLineCount(void) const;
        /// <summary>
        /// Get total number of lines available for the multiline input text.
        /// </summary>
        /// <returns>returns total number of lines available for the multiline </returns>
        size_t GetTotalLineCount(void) const;
        /// <summary>
        /// Set starting line number at which the rendering should start.
        /// </summary>
        /// <param name="p_startLine">  </param>
        void SetStartLine(size_t p_startLine);
        /// <summary>
        /// Get multiline text starting line number
        /// </summary>
        /// <returns>returns the starting line number </returns>
        size_t GetStartLine(void) const;
        /// <summary>
        /// Set controlling spacing between rendered lines.
        /// </summary>
        /// <param name="p_lineSpacing">  </param>
        void SetLineSpacing(const float32_t p_lineSpacing);
        /// <summary>
        /// Get line spacing between rendered lines.
        /// </summary>
        /// <returns>returns the line spacing </returns>
        float32_t GetLineSpacing(void) const;
        /// <summary>
        /// Set the hard cut char
        /// If it is zero no character is inserted and if it is non-zero insert the character to indicate hard cut.
        /// </summary>
        /// <param name="p_hardCutChar">  </param>
        void SetHardCutChar(const char16_t p_hardCutChar);
        /// <summary>
        /// Get maximum lines threashold for this text. maximum value is RC_TEXT_MAX_SUPPORTED_LINES
        /// </summary>
        /// <returns>returns the currently set threshold.</returns>
        char16_t GetHardCutChar(void) const;
        /// <summary>
        /// Set maximum lines threashold for this text. maximum value that can be set is RC_TEXT_MAX_SUPPORTED_LINES
        /// </summary>
        /// <param name="p_maxlines">maximum lines threshold value</param>
        void SetMaxLines(const size_t p_maxlines);
        /// <summary>
        /// Get maximum lines threashold for this text.
        /// </summary>
        /// <returns>returns the maximum lines threshold value </returns>
        size_t GetMaxLines(void) const;
        /// <summary>
        /// Loads this text node by creating dynamic contents..
        /// </summary>
        /// <param name="p_scene">id of the scene which is requesting this text node load</param>
        /// <param name="p_depth">depth of the node. used to prevent indefinite recursion</param>
        /// <param name="p_lrule">resource loading rule</param>
        /// <param name="p_visible">visibility of parent node, may affect resource loading depending on p_mode</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        virtual bool Load(const size_t p_scene, const size_t p_depth, const MdlResourceLoadRule p_lrule = MdlResourceLoadRule::All, const bool p_visible = true) override;
        /// <summary>
        /// Unloads this text node by deleting dynamic contents.. if none of the scene uses this text node anymore
        /// </summary>
        /// <param name="p_scene">id of the scene which is requesting this text node unload</param>
        /// <param name="p_depth">depth of the node. used to prevent indefinite recursion</param>
        /// <returns>returns the load status true - loaded / false - unloaded </returns>
        virtual bool UnLoad(const size_t p_scene, const size_t p_depth) override;
        /// measures the 'text' property of gfx3d_scg_3dtext_node
        /// Note :- when lineBreakSingleLine==true, the 'text' is processed for line breaks and then only measured
        ///         if full string width without line breaks is needed use the other MeasureString overloads
        /// <returns>returns in pixel units, width of string in vec2.x, font height in vec2.y </returns>
        glm::vec2 MeasureString();
        /// measure the passed string
        /// <param name="p_text">string to be measured</param>
        /// <returns>returns in pixel units, width of string in vec2.x, font height in vec2.y </returns>
        glm::vec2 MeasureString(const std::u16string& p_text);
        /// measures the 'text' property of gfx3d_scg_3dtext_node
        /// <param name="p_clip">if true the bounding box is restricted to the portion of the string that can be fitted in the text box. if false, returns the bbox of passed string</param>
        /// <returns>returns in pixel units, width of string in vec2.x, font height in vec2.y </returns>
        rc_text_bound_box MeasureStringEx(const bool p_clip = false);
        /// measure the passed string
        /// <param name="p_scene">string to be measured.</param>
        /// <param name="p_clip">if true the bounding box is restricted to the portion of the string that can be fitted in the text box. if false, returns the bbox of passed string</param>
        /// <returns>returns in pixel units, width of string in vec2.x, font height in vec2.y </returns>
        rc_text_bound_box MeasureStringEx(const std::u16string& p_text, const bool p_clip = false);
        /// Returns the line direction incase of a multiline text
        /// <returns>Auto, Up or Down ward direction</returns>
        mdl_textLineDir_E GetLineDirection() const;
        /// Sets the line direction incase of a multiline text
        /// <param name="p_dir">Set line drection as Auto, Up or Down ward</param>
        void SetLineDirection(const mdl_textLineDir_E p_dir);
        /// <summary>
        /// Set outline width
        /// if outline effect is not available it will create it
        /// </summary>
        /// <param name="p_value">outline width</param>
        void SetOutlineWidth(const uint8_t p_value);
        /// <summary>
        /// Return outline width
        /// </summary>
        /// <returns>return width</returns>
        uint8_t GetOutlineWidth() const;
        /// <summary>
        /// Set effect color
        /// </summary>
        /// <param name="p_value">effect color</param>
        void SetEffectColor(const glm::vec4 p_color);
        /// <summary>
        /// Get outline color
        /// </summary>
        /// <returns></returns>
        glm::vec4 GetEffectColor() const;
        /// <summary>
        /// Set Drop Shadow offset
        /// </summary>
        /// <param name="p_offset"></param>
        void SetDropshadowOffset(const glm::vec2 p_offset);
        /// <summary>
        /// Get Drop Shadow offset
        /// </summary>
        /// <returns>vec2 x,y offset</returns>
        glm::vec2 GetDropshadowOffset() const;
        /// Sets the passed font as active font for rendering this text node.
        /// Incase this font doesnot exists in the project, then creates it
        /// Note:- Internally it may change the active font index of the textnode
        /// </summary>
        /// <param name="p_uri">realative path to the font in asset</param>
        /// <param name="p_style">font style (optional)</param>
        /// <param name="p_hint">rendering hint (optional)</param>
        /// <returns>true on success</returns>
        bool SetFontUri(const std::string& p_uri, const MdlFontStyle p_style = MdlFontStyle::fsNormal, const MdlFontRenderHint p_hint = MdlFontRenderHint::rhDefault);
        /// <summary>
        /// Gets the current selection for the apply Line Break rules on Single Line text flag
        /// </summary>
        /// <returns>true if the rule are applied, false otherwise</returns>
        bool GetLineBreakSingleLine() const;
        /// <summary>
        /// Enable or disable application of line break rule on single line text
        /// If enabled \r and \n in a string will be processed
        ///  - for example "\nhello" input string will cause a display of "" or "..."
        ///  - for example "he\nllo" input string will cause a display of "he" or "he..."
        /// If disabled the passed input string will be renderd as is and the \r\n characters
        /// will cause display of default character.
        ///  - for example "\nhello" input string will cause a display of "?hello"
        /// </summary>
        /// <param name="p_val"></param>
        void SetLineBreakSingleLine(const bool p_val);
        /// <summary>
        /// calculates bounding box returns min and max 
        /// calculates based on matrix model_matrix 
        /// <param name="p_recursive">if true will calulate with child bounding box</param>
        /// <param name="minBounding">passed by reference, filled with valid minBounding</param>
        /// <param name="maxBounding">passed by reference, filled with valid maxBounding</param>
        /// <param name="p_recursive">if true will calulate with child bounding box</param>
        /// <param name="p_coordinateSpace">CoordinateSpace value //World-calculate in world space //View-calculate in view space //NDC-calculate in NDC //Screen-calulcate in screen coordinate</param>
        /// <returns>returns true if calulated properly else false</returns>
        /// usage, to calulate layout x,y,z,width,height,depth 
        /// glm::vec4 minBounding = glm::vec4(std::numeric_limits<float32_t>::max());
        /// glm::vec4 maxBounding = glm::vec4(std::numeric_limits<float32_t>::lowest()); //-FLT_MAX
        /// bool retVal = CalculateBoundingBox(minBounding, maxBounding);
        /// x = minBounding[0];
        /// y = minBounding[1];
        /// z = minBounding[2];
        /// width = maxBounding[0] - minBounding[0];
        /// height = maxBounding[1] - minBounding[1];
        /// depth = maxBounding[2] - minBounding[2];
        /// Note :- must work only after the prerender call. So calling by application code will have a limitation
        /// </summary>
        bool CalculateBoundingBox(glm::vec4& minBounding, glm::vec4& maxBounding, const bool p_recursive = true, const CoordinateSpace p_coordinateSpace = CoordinateSpace::World, const glm::fmat4x4* matrixToMul = nullptr, const gfx3d_scg_camera* const cameraNode = nullptr, const bool useMargin = false, uint32_t p_recurseLevel = 0U) override;
    };
    /// @}
}

#endif

