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
/// @file rc_appversion.h
/// @author emanoj1@visteon.com
/// @brief Provides configuration to specify rendercore library version as Major.Minor.Patch.
/// RCVER_MAJOR - macro for major version (shall be set to non negative integer value)
/// RCVER_MINOR - macro for minor version (shall be set to non negative integer value)
/// RCVER_PATCH - macro for patch version (shall be set to non negative integer value)
/// @date 26-April-2019
/// @copyright � 2019, Visteon Corporation, All Rights Reserved
///////////////////////////////////////////////////////////////////////////////
#ifndef RC_APPVERSION_H
#define RC_APPVERSION_H

namespace rendercore_engine
{
    /// Holds the current version of the rendercore engine
    //  Note :- Any changes here other than version update
    //  i.e. enum type name or enumurator changes, make sure to update
    //  \build\get_version.py
    //  get_version.py extracts the version from this file for the build
    //  so it depends on format of this file..
    enum class RCVer_e
    {
        RCMAJOR = 13, ///< Major version number
        RCMINOR = 0, ///< Minor version number
        RCPATCH = 0, ///< Patch version number
    };
}

#endif
