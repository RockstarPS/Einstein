///////////////////////////////////////////////////////////////////////////////
//
//                     CONFIDENTIAL VISTEON CORPORATION
//
// This is an unpublished work of authorship, which contains trade secrets,
// created in 2021. Visteon Corporation owns all rights to this work and
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
/// @file       : rc_mltext.h
/// @brief 		: Utility classes to manage multilie text. Multiline text is held by 
///               rc_lbtext root class as a list of pargraphs and lines.
//  Created on  : 16-Apr-2021 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_mltext_h
#define rc_mltext_h

// MISRA_TRIAGE:
// CID : 19851531   
// Checker : MISRA C++-2008 7-3-1 
// comments: cant be put inside namespace
struct UBiDi;

namespace rendercore_engine
{
   /// <summary>
   /// Holds nformation about a text segment
   /// if the text is "0123456789abc" and a segment "4567" will be stored as
   /// {spos:4, epos:8}, where epos-spos will give the length of segment
   /// </summary>
   class rc_lbline
   {
   private:
       std::string::size_type spos = 0U;    ///< Start index
       std::string::size_type epos = 0U;    ///< End index
   public:
       rc_lbline();
       rc_lbline(const std::string::size_type p_spos, const std::string::size_type p_epos);
       bool IsValid() const;
       std::string::size_type GetLineSpos() const;
       std::string::size_type GetLineEpos() const;
   };
   class rc_lbtext;
   /// <summary>
   /// Holds one paragraph of text as a list of lines
   /// </summary>
   class rc_lbpara
   {
   private:
       std::vector<rc_lbline> lines;    ///< Information about each line of text in rc_lbpara::text as a startindex and endindex
       rc_mlstring text;                ///< whole paragraph as a single text string 
       /// Memory to hold the BiDi reordered text. Its a shared memory by entire rc_lbtext
       /// i.e. at any given time only one bidi line can be held by it.
       std::vector<uint16_t> reordered_text;
       UBiDi* bidi = nullptr;           ///< Handle to UBiDi processor for a paragraph
       UBiDi* bidiLine = nullptr;       ///< Handle to UBiDi processor for a line in the paragraph
       rc_lbtext* parent = nullptr;     ///< Parent rc_lbtext object
       size_t activeLine = static_cast<size_t>(SIZE_MAX);    ///< Currently active line index
       int32_t processedLength = 0;     ///< Currently processed length by BiDi
       int32_t bidi_start_offset = 0;   ///< Start offset value of BiDi process
       int32_t segIndex = 0;            ///< Current bidi segment index
       int32_t segCount = 0;            ///< Total number of segments
       bool bParaInitialized = false;   ///< indicated if the bidi para is initialized or not..
       mdl_textBidiDir_E baseDir = mdl_textBidiDir_E::tbdneutral;       ///< Base direction for this paragraph

       /// <summary>
       /// Writes the reordered buffer to p_reordered_text for the passed UBiDi object
       /// Returns the number of segments in the written string.
       /// </summary>
       int32_t write_reordered(UBiDi* const p_bidi);
   public:
       rc_lbpara(const rc_lbpara& p_rhs);
       rc_lbpara& operator=(const rc_lbpara& p_rhs);
       /// <summary>
       /// Ctor
       /// </summary>
       rc_lbpara();
       /// <summary>
       /// Dtor
       /// </summary>
       ~rc_lbpara();
       /// <summary>
       /// Resets the pargraph to the default ctor state
       /// </summary>
       void Reset();
       /// <summary>
       /// Sets the parent rc_lbtext object
       /// </summary>
       /// <param name="p_parent">parent object</param>
       void SetParent(rc_lbtext* const p_parent);
       /// <summary>
       /// Returns the number of text lines in this paragraph
       /// </summary>
       /// <returns>number of text lines</returns>
       size_t GetLineCount() const;
       /// <summary>
       /// Adds a line of text to the pargraph
       /// Append the string to rc_lbpara::text and as well adds a entry to rc_lbpara::lines
       /// with start idex and end index
       /// </summary>
       /// <param name="p_line"></param>
       void AddLine(const rc_mlstring& p_line);
       /// <summary>
       /// Sets the active line index and resets the BidiLine segment to 0th index
       /// Calls to GetBidiLineSegmentCount(), GetBidiNextLineSegment(), GetRawLineText()
       /// returns data for the active line
       /// Sequence for GetBidiNextLineSegment()
       /// if SetActiveLine(N)
       ///    cnt = GetBidiLineSegmentCount()
       ///    for cnt
       ///        GetBidiNextLineSegment()
       ///  Note that after the end segment is read, all internal data is erased and 
       ///  sequence must be repeated to read the data again
       /// </summary>
       /// <param name="p_lineIndex"></param>
       /// <returns></returns>
       bool SetActiveLine(const size_t p_lineIndex);
       /// <summary>
       /// Returns the text string held by rc_lbpara::text
       /// </summary>
       /// <returns>rc_lbpara::text</returns>
       rc_mlstring GetParagraph() const;
       /// <summary>
       /// Returns the number of BiDi segments in the active line
       /// </summary>
       /// <returns>number of BiDi segments</returns>
       int32_t GetBidiLineSegmentCount();
       /// <summary>
       /// Returns the BiDi reordered string for the current segIndex and increments segIndex
       /// to next. To restart from start a call to SetActiveLine() is needed
       /// Number of call must be must be within 0 to (GetBidiLineSegmentCount()-1) to get all
       /// all valid text segments in sequence. More calls produce empty strings
       /// See rc_lbpara::SetActiveLine for usage details
       /// </summary>
       /// <param name="p_segIndex"></param>
       /// <returns></returns>
       rc_mlstring GetBidiNextLineSegment();
       /// <summary>
       /// Returns the raw / bidi unprocessed text for the active line
       /// </summary>
       /// <returns>unprocessed text</returns>
       rc_mlstring GetRawLineText();
       /// <summary>
       /// Set the base direction for this paragraph
       /// </summary>
       /// <param name="p_dir">base direction</param>
       void SetBaseDirection(const mdl_textBidiDir_E p_dir);
       /// <summary>
       /// Returns the base direction for this paragraph
       /// </summary>
       /// <returns>base direction</returns>
       mdl_textBidiDir_E GetBaseDirection() const;
       /// <summary>
       /// Release the memory allocated for para processing
       /// </summary>
       void ReleaseMemory();
   };
   /// <summary>
   /// Holds a multiline text element which is breaked by rc_linebreak
   /// A list of paragraph (lines delimited by \r\n) is held by this class
   /// This also holds the unicode bidi agorithm handles.
   /// </summary>
   class rc_lbtext
   {
   private:
       std::vector<rc_lbpara> paras;        ///< List of paragraphs
       rc_lbtext(const rc_lbtext& p_rhs) = delete;
       rc_lbtext& operator=(const rc_lbtext& p_rhs) = delete;
   public:
       /// <summary>
       /// Ctor
       /// </summary>
       rc_lbtext();
       /// <summary>
       /// Dtor
       /// </summary>
       ~rc_lbtext();
       /// <summary>
       /// Resets the paragraphs
       /// </summary>
       void Reset();
       /// <summary>
       /// Release the memory allocated for paragraph processing
       /// </summary>
       void ReleaseMemory();
       /// <summary>
       /// Returns the total number of lines from all paragraphs
       /// </summary>
       /// <returns>total number of lines</returns>
       size_t GetLineCount() const;
       /// <summary>
       /// Adds a line of text to the paragraph. p_line will have information about
       /// which paragraph to be added
       /// </summary>
       /// <param name="p_line">line of text</param>
       void AddLine(const rc_mlstring& p_line);
       /// <summary>
       /// Sets the active line to passed line index
       /// </summary>
       /// <param name="p_line">line index (0 - firstline, 1 - second line and so on)</param>
       /// <returns>a pointer to paragraph object from where the text line coule be read</returns>
       rc_lbpara * SetActiveLine(size_t p_line);
       /// <summary>
       /// Returns the number of paragraphs held by this object
       /// </summary>
       /// <returns>number of paragraphs</returns>
       size_t GetParaCount() const;
   };
}
#endif
