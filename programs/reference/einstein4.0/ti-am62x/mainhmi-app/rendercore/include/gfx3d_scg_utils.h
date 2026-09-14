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
//  Filename    : gfx3d_scg_utils.h
//  Description : it is a display class and contains graphics data for display
//  Created on  : 25-Jan-2018 by mpandey@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  gfx3d_scg_utils.cpp
/// \brief it is a display class and contains graphics data for display

#ifndef gfx3d_scg_utils_h
#define gfx3d_scg_utils_h

#include <array>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <map>
#include <string>
#include <vector>
#include <fstream> 
#include <memory>
#include "rc_string.h"
#include "gb18030_convert.h"
#include "big5_convert.h"

namespace rendercore_engine
{
    /// \defgroup Utlities Global Utility functions
    /// <summary>
    /// Provides APIs for common operations across rendercore classes..
    /// </summary>
    /// \ingroup Utlities
    /// @{

    /// <summary>
    /// Used internally for the BIG5 and GB18030 decode
    /// </summary>
    struct pageframe_table_t
    {
        uint32_t in_convert_start_value;
        uint16_t in_convert_compress_table_offset;
        uint32_t out_convert_start_value;
        uint16_t out_convert_compress_table_offset;
        uint8_t in_convert_performance_class;
        uint8_t out_convert_performance_class;
        uint8_t pageframe_length;
    };
    /// <summary>
    /// Used internally for the BIG5 and GB18030 decode
    /// </summary>
    struct pageframe_entry_t
    {
        uint32_t start_value;
        uint16_t compress_table_offset;
        uint8_t performance_class;
        uint8_t length;
    };
    /// <summary>
    /// reads a whole file content in to a dynamically allocated buffer 
    /// <param name="filepath">file path to be read</param>
    /// <param name="p_sizeout">pointer to size_t storage for updating the number of bytes read & written to buffer. Can be null</param>
    /// <param name="p_quiet">generate no error logs if true</param>
    /// <returns>dynamically allocated buffer pointer with data. null incase of any error</returns>
    /// </summary>
    const CHAR8* ReadWholeFile(const std::string& filepath, size_t& p_sizeout, const bool p_quiet = false);
    /// <summary>
    /// Extended version of ReadWholeFile with an option to load a compressed file
    /// incase if "<p_path>.gz" file exists, then loads, unzips and returns the raw bytes
    /// priority is to search p_path first and then "<p_path>.gz"
    /// <param name="p_path">file path to be read</param>
    /// <param name="p_length">storage for updating the number of bytes available in returned buffer pointer</param>
    /// <param name="p_quiet">try generate no error logs if true</param>
    /// <returns>returns a dynamically allocated buffer with data. nullptr in case of any error</returns>
    /// </summary>
    const CHAR8* ReadWholeFileExt(const std::string p_path, size_t& p_length, const bool p_quiet = false);
    /// <summary>
    /// another varient to reads a whole file content in to a std::vector<char> 
    /// <param name="filepath">Absolute path to a file in filesystem. Please note that this API will not read from rendercore resource tar</param>
    /// <returns>MdlRdAllBytes objects which holds the data and length, length will be 0 incase of any error</returns>
    /// </summary>
    MdlRdAllBytes ReadAllBytes(const std::string& filepath);
    /// <summary>
    /// combines the given string pathss, returns std::string
    /// </summary>
    std::string PathCombine(const std::string p_path1, const std::string p_path2);
    /// <summary>
    /// combines the given string paths returns rc_string
    /// </summary>
    rc_string PathCombine(const std::string p_path1, const rc_string p_path2);
    /// <summary>
    /// combines the given string paths returns rc_string
    /// </summary>
    rc_string PathCombine(const std::string p_path1, const CHAR8* const p_path2);
    /// <summary>
    /// Checks if given file exists
    /// (Note : its not recomended to use this API as its an overhead. Instead directly use ReadAllBytes)
    /// <param name="filepath">Absolute path to a file in filesystem. Please note that this API will not check in rendercore resource tar</param>
    /// <returns>true if the file exists, false otherwise</returns>
    /// </summary>
    bool FileExists(const std::string& p_path);
#if defined(WIN32) && !defined(MINGW_BUILD)
    void CheckUri(std::string p_uri);
#endif
    /// <summary>
    /// Converts a utf8 string utf16 wide string (when wchar_t is 2bytes) or 32bit unicode (when wchar_t is 4bytes)
    /// </summary>
    std::wstring StringtoWideString(const std::string& p_string);
    /// <summary>
    /// Converts a utf8 string to utf16 string
    /// </summary>
    std::u16string StringtoU16String(const std::string& p_string);
    /// <summary>
    /// Converts a wide string (when char16_t is 2bytes) or 32bit unicode (when char16_t is 4bytes) to utf8 standard string
    /// </summary>
    std::string WideStringtoString(const std::wstring& p_string);
    /// <summary>
    /// Converts a utf8 string to 32bit wide string, i.e. if sizeof(wchar_t) == 4
    /// </summary>
    /// <param name="p_string">utf8 string</param>
    /// <param name="p_length">length of utf8 string</param>
    /// <returns></returns>
    std::u32string Utf8ToUnicodeString(const CHAR8* const p_string, const size_t p_length);
    /// <summary>
    /// Converts a utf16 string to 32bit wide string, i.e. if sizeof(wchar_t) == 4
    /// </summary>
    /// <param name="p_string">utf16 string</param>
    /// <param name="p_length">length of utf16 string</param>
    /// <returns></returns>
    std::wstring Utf16ToWideString(const char16_t* const p_string, const size_t p_length);
    /// <summary>
    /// Converts a utf16 string to 32bit wide string, i.e. if sizeof(wchar_t) == 4
    /// </summary>
    /// <param name="p_string">utf16 string</param>
    /// <returns></returns>
    std::wstring Utf16ToWideString(const std::u16string& p_string);
    /// <summary>
    /// Decode a UTF16 byte sequence to Wide string
    /// </summary>
    /// <param name="p_string">UTF16 byte sequence</param>
    /// <param name="p_length">length of bytes</param>
    /// <param name="p_be">true means UTF16BE, else UTF16LE</param>
    /// <returns></returns>
    std::wstring Utf16ToWideString(const uint8_t* const p_string, size_t p_length, const bool p_be=false);
    /// <summary>
    /// Converts a Unicode char to utf8 string
    /// </summary>
    /// <param name="p_uchar"></param>
    /// <returns></returns>
    std::string UnicodeToString(const char32_t p_uchar);
    /// @}
    /// <summary>
    /// Used internally for the GB18030 and BIG5 decode
    /// </summary>
    void get_pageframe_value(const pageframe_entry_t* const pageframe_entry, const uint32_t pageframe_index, 
                             uint8_t const* const compressed_array, const size_t compressed_array_size, 
                             const uint32_t value_length_in_bytes,uint32_t* const return_32bit_value_ptr);
    /// <summary>
    /// Used internally for the GB18030 and BIG5 decode
    /// </summary>
    void decompress_segment(const uint8_t* segment_ptr, uint32_t counter, const uint32_t value_length_in_bytes, 
                            int32_t* const initial_and_return_32bit_value_ptr);
    /// <summary>
    /// Internal API to convert a 32bit unicode to UTF16
    /// </summary>
    /// <param name="p_unicode">unicode value</param>
    /// <param name="p_out">where to push the UTF16 codes</param>
    /// <returns>true when no errors</returns>
    bool utf32cp_to_utf16cp(const uint32_t p_unicode, std::u16string& p_out);
    /// <summary>
    /// Internal API to convert a 32bit unicode to UTF16
    /// Note that when wchar_t size is  4 bytes, no UTF16 conversion is performed..
    /// </summary>
    /// <param name="p_unicode">unicode value</param>
    /// <param name="p_out">where to push the UTF16 codes</param>
    /// <returns>true when no errors</returns>
    bool append_u32code_to_wstring(const uint32_t p_unicode, std::wstring& p_out);
    /// <summary>
    /// Converts a u16string to utf8 standard string
    /// </summary>
    std::string U16StringtoString(const std::u16string& p_string);
    /// <summary>
    /// Converts a 32bit unicode wide string (when wchar_t is 4bytes) to utf16 wide string
    /// hence use this only under a check <when wchar_t size is > 2 bytes>
    /// </summary>
    std::u16string UnicodeWstringtoUTF16Wstring(const std::wstring& p_string);
    /// <summary>
    /// Converts numbers to string
    /// </summary>
    /// <typeparam name="T">type of the value (int, float, char etc..)</typeparam>
    /// <param name="value">value</param>
    /// <returns>value converted to string</returns>
    template <typename T>
    inline std::u16string ToU16String(T value)
    {
        std::string u8str = std::to_string(value);
        return StringtoU16String(u8str);
    }
    /// <summary>
    /// Converts a half float value to float
    /// </summary>
    /// <param name="p_val"> half float value as uint16_t</param>
    /// <returns>float value</returns>
    float32_t HalfFloatToFloat(const uint16_t p_val);
}
#endif