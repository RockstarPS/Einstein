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
//  Filename    : rc_string.h
//  Description : custom string class APIs
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file	rc_string.h
///	\brief 		custom string class APIs
#ifndef rc_string_h
#define rc_string_h

#include <string>

namespace rendercore_engine
{
    enum class rc_stringSplitOptions
    {
        ssoNone,               ///< Split string array can include empty strings.
        ssoRemoveEmptyEntries, ///< Split string array does not include empty strings.
    };
    /// \ingroup GenericTypes
    /// @{
    using float32_t = float;
    /// rendercore string class
    class rc_string : public std::string
    {
    public:
        rc_string();
        /// assign the given string to string object
        rc_string(const CHAR8* const s1);
        /// assign the given string to string object
        rc_string(const std::string& s1);
        /// operator = : assigning string to object
        rc_string& operator=(const CHAR8* const s1);
        /// operator = : assigning string to object
        rc_string& operator=(const rc_string& s1);
        /// operator = : assigning string to object
        rc_string& operator=(const std::string& s1);
        /// operator + : concatinating 2 string
        friend rc_string operator+(const rc_string& s1, const int32_t elem);
        /// operator + : concatinating 2 string
        friend rc_string operator+(const int32_t elem, const rc_string& s1);
        /// operator + : concatinating 2 string
        friend rc_string operator+(const rc_string& s1, const uint32_t elem);
        /// operator + : concatinating 2 string
        friend rc_string operator+(const uint32_t elem, const rc_string& s1);
        /// operator + : concatinating 2 string
        friend rc_string operator+(const rc_string& s1, const float32_t elem);
        /// operator + : concatinating 2 string
        friend rc_string operator+(const float32_t elem, const rc_string& s1);
        /// operator + : concatinating 2 string
        friend rc_string operator+(const rc_string& s1, const float64_t elem);
        /// operator + : concatinating 2 string
        friend rc_string operator+(const float64_t elem, const rc_string& s1);
        /// Replaces occurances of p_lookup with p_replace in this instance of string and returned the modified the string
        rc_string Replace(const CHAR8 p_lookup, const CHAR8 p_replace) const;
        /// Replaces occurances of p_lookup with p_replace in this instance of string and returned the modified the string
        rc_string Replace(const CHAR8* const p_lookup, const CHAR8* const p_replace) const;
        /// Replaces occurances of p_lookup with p_replace in this instance of string and returned the modified the string
        rc_string Replace(const rc_string& p_lookup, const rc_string& p_replace) const;
        /// <summary>
        /// Returns the character array represting this string object
        /// </summary>
        /// <returns>char array pointer</returns>
        const CHAR8* ToCharArray();
        /// <summary>
        /// Splits the string with the provide seperator/delimiter
        /// </summary>
        /// <param name="p_seperator">seperator character</param>
        /// <param name="p_options">to allow empty strings in returned list or not</param>
        /// <returns>returns a list of string splited by provided seperator</returns>
        std::vector<rc_string> Split(const CHAR8 p_seperator, const rc_stringSplitOptions p_options = rc_stringSplitOptions::ssoNone);
        /// <summary>
        /// Splits the string with the provide seperator/delimiter
        /// </summary>
        /// <param name="p_seperator">seperator character array</param>
        /// <param name="p_options">to allow empty strings in returned list or not</param>
        /// <returns>returns a list of string splited by provided seperator</returns>
        std::vector<rc_string> Split(const CHAR8* const p_seperator, const rc_stringSplitOptions p_options = rc_stringSplitOptions::ssoNone);
        /// <summary>
        /// Returns a substring from this string object
        /// </summary>
        /// <param name="p_start">starting index</param>
        /// <param name="length">length to be returned</param>
        /// <returns>sunstring if exists or empty</returns>
        rc_string Substring(const int32_t p_start, const int32_t p_length);
        /// <summary>
        /// Returns a substring from this string object
        /// </summary>
        /// <param name="p_start">starting index</param>
        /// <returns>sunstring if exists or empty</returns>
        rc_string Substring(const int32_t p_start);
        /// <summary>
        /// Reports the zero-based index of the first occurrence of the specified character in this instance
        /// </summary>
        /// <param name="p_schar">Search char</param>
        /// <param name="startIndex">start index of search</param>
        /// <param name="count">number of characters to search (-1 means all)</param>
        /// <returns>index of the string, -1 if search fails</returns>
        int32_t IndexOf(const CHAR8 p_schar, const int32_t p_startIndex = 0, const int32_t p_count = -1);
        /// <summary>
        /// Reports the zero-based index of the first occurrence of the specified string in this instance
        /// </summary>
        /// <param name="p_sstr">Search string</param>
        /// <param name="startIndex">start index of search</param>
        /// <param name="count">number of characters to search (-1 means all)</param>
        /// <returns>index of the string, -1 if search fails</returns>
        int32_t IndexOf(const rc_string& p_sstr, const int32_t p_startIndex = 0, const int32_t p_count = -1);
    };

    /// @}
    /// \ingroup GenericTypes
    /// @{

    /// rendercore u16string class
    class rc_wstring : public std::u16string
    {
    public:
        rc_wstring();
        /// assign the given string to string object
        rc_wstring(const char16_t* const s1);
        /// assign the given string to string object
        rc_wstring(const std::u16string& s1);
        /// assign the given string to string object
        rc_wstring(const std::string& s1);
        /// operator = : assigning string to object
        rc_wstring& operator=(const char16_t* const s1);
        /// operator = : assigning string to object
        rc_wstring& operator=(const rc_wstring& s1);
        /// operator = : assigning string to object
        rc_wstring& operator=(const std::u16string& s1);
        /// operator + : concatinating 2 string
        friend rc_wstring operator+(const rc_wstring& s1, const int32_t elem);
        /// operator + : concatinating 2 string
        friend rc_wstring operator+(const int32_t elem, const rc_wstring& s1);
        /// operator + : concatinating 2 string
        friend rc_wstring operator+(const rc_wstring& s1, const uint32_t elem);
        /// operator + : concatinating 2 string
        friend rc_wstring operator+(const uint32_t elem, const rc_wstring& s1);
        /// operator + : concatinating 2 string
        friend rc_wstring operator+(const rc_wstring& s1, const float32_t elem);
        /// operator + : concatinating 2 string
        friend rc_wstring operator+(const float32_t elem, const rc_wstring& s1);
        /// operator + : concatinating 2 string
        friend rc_wstring operator+(const rc_wstring& s1, const float64_t elem);
        /// operator + : concatinating 2 string
        friend rc_wstring operator+(const float64_t elem, const rc_wstring& s1);
        /// operator + : concatinating 2 string
        friend rc_wstring operator+(const rc_wstring& s1, const rc_wstring& s2);
        /// operator + : concatinating 2 string
        friend rc_wstring operator+(const rc_wstring& s1, const char16_t* const s2);
        /// operator + : concatinating 2 string
        friend rc_wstring operator+(const char16_t* const s1, const rc_wstring& s2);
        /// Replaces occurances of p_lookup with p_replace in this instance of string and returned the modified the string
        rc_wstring Replace(const char16_t p_lookup, const char16_t p_replace) const;
        /// Replaces occurances of p_lookup with p_replace in this instance of string and returned the modified the string
        rc_wstring Replace(const char16_t* const p_lookup, const char16_t* const p_replace) const;
        /// Replaces occurances of p_lookup with p_replace in this instance of string and returned the modified the string
        rc_wstring Replace(const rc_wstring& p_lookup, const rc_wstring& p_replace) const;
        /// <summary>
        /// Returns the character array represting this string object
        /// </summary>
        /// <returns>char array pointer</returns>
        const char16_t* ToCharArray();
        /// <summary>
        /// Splits the string with the provide seperator/delimiter
        /// </summary>
        /// <param name="p_seperator">seperator character</param>
        /// <param name="p_options">to allow empty strings in returned list or not</param>
        /// <returns>returns a list of string splited by provided seperator</returns>
        std::vector<rc_wstring> Split(const char16_t p_seperator, const rc_stringSplitOptions p_options = rc_stringSplitOptions::ssoNone);
        /// <summary>
        /// Splits the string with the provide seperator/delimiter
        /// </summary>
        /// <param name="p_seperator">seperator character array</param>
        /// <param name="p_options">to allow empty strings in returned list or not</param>
        /// <returns>returns a list of string splited by provided seperator</returns>
        std::vector<rc_wstring> Split(const char16_t* const p_seperator, const rc_stringSplitOptions p_options = rc_stringSplitOptions::ssoNone);
        /// <summary>
        /// Returns a substring from this string object
        /// </summary>
        /// <param name="p_start">starting index</param>
        /// <param name="length">length to be returned</param>
        /// <returns>sunstring if exists or empty</returns>
        rc_wstring Substring(const int32_t p_start, const int32_t p_length);
        /// <summary>
        /// Returns a substring from this string object
        /// </summary>
        /// <param name="p_start">starting index</param>
        /// <returns>sunstring if exists or empty</returns>
        rc_wstring Substring(const int32_t p_start);
        /// <summary>
        /// Reports the zero-based index of the first occurrence of the specified string in this instance
        /// </summary>
        /// <param name="p_schar">Search char</param>
        /// <param name="startIndex">start index of search</param>
        /// <param name="count">number of characters to search (-1 means all)</param>
        /// <returns>index of the string, -1 if search fails</returns>
        int32_t IndexOf(const char16_t p_schar, const int32_t p_startIndex = 0, const int32_t p_count = -1);
        /// <summary>
        /// Reports the zero-based index of the first occurrence of the specified string in this instance
        /// </summary>
        /// <param name="p_sstr">Search string</param>
        /// <param name="startIndex">start index of search</param>
        /// <param name="count">number of characters to search (-1 means all)</param>
        /// <returns>index of the string, -1 if search fails</returns>
        int32_t IndexOf(const rc_wstring& p_sstr, const int32_t p_startIndex = 0, const int32_t p_count = -1);
    };
    class rc_mlstring : public std::u16string
    {
    private:
        mdl_textBidiDir_E baseDir = mdl_textBidiDir_E::tbdltr;
        uint8_t para = 0U;
    public:
        rc_mlstring(const mdl_textBidiDir_E p_baseDir = mdl_textBidiDir_E::tbdltr, const uint8_t p_para = 0U);
        /// assign the given string to string object
        rc_mlstring(const char16_t* const s1);
        /// assign the given string to string object
        rc_mlstring(const std::u16string& s1);
        /// assign the given string to string object
        rc_mlstring(const std::string& s1);
        /// assign the given string to string object
        rc_mlstring(const std::u16string& s1, const mdl_textBidiDir_E p_baseDir, const uint8_t p_para = 0U);
        /// operator = : assigning string to object
        rc_mlstring& operator=(const char16_t* const s1);
        /// operator = : assigning string to object
        rc_mlstring& operator=(const rc_mlstring& s1);
        /// operator = : assigning string to object
        rc_mlstring& operator=(const std::u16string& s1);
        /// <summary>
        /// Returns the base direction for the string
        /// </summary>
        /// <returns>base direction</returns>
        mdl_textBidiDir_E GetBaseDirection() const;
        void SetParagraphCount(const uint8_t p_para);
        uint8_t GetParagraphCount() const;
    };
    /// @}
}
#endif