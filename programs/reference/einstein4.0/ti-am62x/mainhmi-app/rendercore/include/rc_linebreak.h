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
//  Filename    : rc_linebreak.h
//  Description : Rendercore Line breaking algorithm
//  Created on  : 16-Mar-2020 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
///@file rc_linebreak.h
/// \brief 			Rendercore Line breaking algorithm
#ifndef rc_linebreak_h
#define rc_linebreak_h

#include "rc_text_attrib.h"

namespace rendercore_engine
{
    /// Holds one string segment from an input text. Used for multiline processing
   struct rc_text_seg
   {
       rc_mlstring text;            ///<segment string
       uint32_t width = 0U;        ///<width of the segment
       bool isWhiteSpace = false;  ///<indcates this as a whitespace segment & hence a break opportunity
       bool isNewline = false;     ///<indcates this as a newline segment
       rc_text_seg(const rc_mlstring& p_text, const bool p_isWhiteSpace, const bool p_isNewline);
   };
   enum class rc_lbstatus_e
   {
       NoBreak,     ///< No line breaking performed
       Breaked,     ///< Line breaked & total lines with in maximum line break threshold
       OverFlow     ///< Line breaked & total lines > maximum line break threshold
   };
   class rc_linebreak
   {
   private:
       /// Splits the input string based on unicode line breaking
       /// <param name="p_text">Input text to split</param>
       /// <param name="p_segs">Split text segments</param>
       static void UniBreaksplitWSSegments(const rc_mlstring& p_text, std::vector<rc_text_seg>& p_segs, const rc_textbox_attrib& p_conf);
       /// <summary>
       /// Adds a whitespace segment p_tline to the p_segs list. 
       /// incase the previous segment is already a whitespace, then appends to it rather than creating a new segment
       /// </summary>
       static void add_whitespace(std::vector<rc_text_seg>& p_segs, const rc_mlstring& p_tline);
       /// <summary>
       /// If the string starts or end with white spaces, split them as seperate words..
       /// </summary>
       /// <param name="p_segs">destination segments where the split strings is added</param>
       /// <param name="p_tline">input string to split</param>
       static void add_segment(std::vector<rc_text_seg>& p_segs, const rc_mlstring& p_tline);
   public:
     /// Splits the input string based on new line chars and break opportunities (currently white spaces)
     /// <param name="p_text">Input text to split</param>
     /// <param name="p_segs">Split text segments</param>
     static void splitSegments(const rc_mlstring& p_text, std::vector<rc_text_seg>& p_segs, const rc_textbox_attrib& p_conf);
       /// Breaks the set text in to multiple lines based on new line, whitespace or hardcut
       static rc_lbstatus_e DoLineBreak(std::vector<rc_mlstring>& p_textLines, const rc_textbox_attrib& p_conf, gfx3d_scg_font* const p_fengine);
       /// Breaks the set text in to multiple lines based on new line, whitespace or hardcut
       static rc_lbstatus_e DoLineBreak(rc_lbtext& p_lbtext, const rc_textbox_attrib& p_conf, gfx3d_scg_font* const p_fengine);
       /// <summary>
       /// Returns the first line by just breaking based on first 
       /// carriage return or newline character
       /// Incase the line is breaked, removes any trailing spaces
       /// Used for single line text display and eliminate more complex DoLineBreak
       /// Note:- p_conf.text is the input text.
       /// </summary>
       /// <param name="p_textout">Output string</param>
       /// <param name="p_conf">Text Config</param>
       /// <returns>returns status of break</returns>
       static rc_lbstatus_e GetFirstLine(rc_mlstring& p_textout, const rc_textbox_attrib& p_conf);
   };
}
#endif
