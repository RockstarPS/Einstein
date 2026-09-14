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
/// @file rc_version.h
/// @author emanoj1@visteon.com
/// @brief Provides the API to get the version. Two APIs are provided.. to read 
/// version as integer value and a string value.
/// To use this file application shall -D (define) the version macros and it
/// gets embedded here and the application can use a standard API to read the 
/// versions across rendercore components.
/// RCVER_MAJOR - macro for major version (shall be set to non negative integer value)
/// RCVER_MINOR - macro for minor version (shall be set to non negative integer value)
/// RCVER_PATCH - macro for patch version (shall be set to non negative integer value)
/// @date 26-April-2019
/// @copyright � 2019, Visteon Corporation, All Rights Reserved
///////////////////////////////////////////////////////////////////////////////
#ifndef RC_VERSION_H
#define RC_VERSION_H

#if !defined(DLL_API)
#if defined(BUILDINGDLL)
#define DLL_API extern "C" __declspec(dllexport) ///< funtion declaration prefix when a dll is built.
#else
#define DLL_API extern
#endif
#endif
namespace rendercore_engine
{
    /// <summary>
    /// C style API : Get the Major, Minor, Patch version integer values
    /// </summary>
    /// <param name="p_major">pointer to major verion storage. If not null major version is written to here</param>
    /// <param name="p_minor">pointer to minor verion storage. If not null minor version is written to here</param>
    /// <param name="p_patch">pointer to patch verion storage. If not null patch version is written to here</param>
    DLL_API void RcGetVersion(int32_t* const p_major, int32_t* const p_minor, int32_t* const p_patch);
    /// <summary>
    /// C style API : Get the version string in Major.Minor.Patch format (e.g. 1.0.12)
    /// </summary>
    /// <returns>Returns the version string</returns>
    DLL_API CHAR8* RcGetVersionString(void);
    /// <summary>
    /// Copies the copyright string to passed buffer 'p_dest'
    /// </summary>
    /// <param name="p_dest">caller allocated destination string buffer where the copyright info is written</param>
    /// <param name="p_length">length of destination buffer (must be >= 30 chars)</param>
    /// <returns>true if info copied</returns>
    DLL_API bool RcGetCopyrightString(CHAR8* const p_dest, const size_t p_length);
}
#endif