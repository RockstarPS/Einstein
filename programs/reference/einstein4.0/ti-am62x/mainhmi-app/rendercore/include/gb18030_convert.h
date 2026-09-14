#if !defined( GB18030_CONVERT_H )
#define GB18030_CONVERT_H
// ===========================================================================
//
//                     CONFIDENTIAL VISTEON CORPORATION
//
// This is an unpublished work of authorship, which contains trade secrets,
// created in 2005.  Visteon Corporation owns all rights to this work and
// intends to maintain it in confidence to preserve its trade secret status.
// Visteon Corporation reserves the right, under the copyright laws of the
// United States or those of any other country that may have jurisdiction,
// to protect this work as an unpublished work, in the event of an inadvertent
// or deliberate unauthorized publication.  Visteon Corporation also reserves
// its rights under all copyright laws to protect this work as a published
// work, when appropriate.  Those having access to this work may not copy it,
// use it, modify it, or disclose the information contained in it without
// the written authorization of Visteon Corporation.
//
// ===========================================================================

// ===========================================================================
//
// File:            gb18030_convert.h
//
// Description:     header file to call out tables and definitions for china
//                  conversion logic
//
// =========================================================================== 
namespace rendercore_engine
{
    /// <summary>
    /// Converts a GB18030 byte sequence to unicode widestring
    /// Usage example :-
    /// using namespace rendercore_convert;
    /// std::u16string flout;
    /// uint8_t fl_in[] = { 0xB3, 0xA7};
    /// convert_residual_t res = gb18030_to_widestring(fl_in, 2, flout);
    /// Code 0xB3A7 will be converted to U+5382
    /// Note :- if an error is detected during conversion return string may contain partial results
    /// </summary>
    /// <param name="p_input">GB18030 byte array</param>
    /// <param name="p_input_length">length of GB18030 byte array</param>
    /// <returns>output wide string where the converted string is written</returns>
    std::u16string GB18030ToWideString(const uint8_t* p_input, uint32_t p_input_length);
}
#endif // #if !defined( CHINA_CONVERT_H )

