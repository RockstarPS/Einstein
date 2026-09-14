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
//  Filename    : rc_text_attrib.h
//  Description : Rendercore Line breaking algorithm
//  Created on  : 16-Mar-2020 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
///@file rc_text_attrib.h
/// \brief 			Rendercore Line breaking algorithm
#ifndef rc_text_attrib_h
#define rc_text_attrib_h

#include <vector>

#if !defined(RC_TEXT_MAX_SUPPORTED_LINES)
/// Ceiling for the maximum number of lines supported.
#define RC_TEXT_MAX_SUPPORTED_LINES (100)
#endif

namespace rendercore_engine
{
   // Holds the property specific to rendering of a text box by font rasterizing engine..
   struct rc_textbox_attrib
   {
       /// unprocessed input text to be processed by MeasureString/DoLineBreak/GetFirstLine
       /// for generating the text lines for rendering (BiDi & LineBreaking)
       /// processed text will be available in rc_textbox_attrib::lbCurPara
       rc_mlstring text;
       /// maximum lines threshold. Only up to this lines will be processed and 
       /// remaining lines are discarded from input text. 
       /// It can be set to range between 1 to RC_TEXT_MAX_SUPPORTED_LINES using SetMaxLines() API
       size_t maxLines = 1U;
       /// multiline hard cut character. 
       /// When a word gets a hard cut to break to next line this character is appended to
       /// indicate that the word is continuing to next line. 
       /// e.g. when hardCutChar = '-'; (hiphen) "ind-
       /// icating" a word break.
       /// e.g. when hardCutChar = 0; (disabled) "ind
       /// icating" a word break.
       char16_t hardCutChar = u'\0';
       uint32_t bboxWidthPx = 0U;              ///<text bounding box width in pixels
       uint32_t bboxHeightPx = 0U;             ///<text bounding box height in pixels
       int32_t charSpacing = 0;                ///<spacing between characters
       /// oflowMode - overflow handling mode
       ///             mdl_textOverflowMode_E::ovNone - no special handlings. fit as much possible in to the available width. Some characters may be drawn partially
       ///             mdl_textOverflowMode_E::ovClip - fit until a characters can be drawn fully in the available width.   
       ///             mdl_textOverflowMode_E::ovEllipses - If all charaters cannot be fullt fit in given width, show partial string + ellipses (e.g. "Text Render...")
       mdl_textOverflowMode_E oflowMode = mdl_textOverflowMode_E::ovNone;
       mdl_mlWordWrap_E wordWrap = mdl_mlWordWrap_E::wwBreakWord;  ///< Word wraping control
       mdl_mlWordBreak_E wordBreak = mdl_mlWordBreak_E::wbBreakAll;///< Word breaking control
       mdl_layoutHalign_E horzAlign = mdl_layoutHalign_E::hLeft;	///<horizontal alignment for text
       mdl_layoutValign_E vertAlign = mdl_layoutValign_E::vTop;    ///<vertival alignment for text
       mdl_textLineDir_E  mlineDir = mdl_textLineDir_E::tldAuto;      ///<Specifies the line direction for a multiline text
       uint8_t outlineWidth = 0U;    ///< Outline effect width
       bool overFlow = false;       ///< Indicates the text must be rendered with overflow indication (...)
       rc_lbpara* lbCurPara = nullptr; ///< Processed text output. Current paragraph to be rendered (Active line from this para will be rendered)
   };
}
#endif
