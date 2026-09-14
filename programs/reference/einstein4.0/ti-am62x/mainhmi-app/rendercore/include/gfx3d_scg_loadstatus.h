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
//  Filename    : gfx3d_scg_loadstatus.h
//  Description : GFX3D scene loading status object
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef gfx3d_scg_loadstatus_h
#define gfx3d_scg_loadstatus_h

#include <cstddef>
#include <cstdint>
#include <memory>

namespace rendercore_engine
{
    /// \ingroup Engine
    /// @{
    /// <summary>
    /// object to indicate the loading/unloading status
    /// </summary>
    struct gfx3d_LoadStatus
    {
        volatile bool isDone = false; ///< true when the loading/unloading is done, false indicate in progress
        uint8_t priority = 0U;        ///< load priority (TODO : currently unused)
    };
    /// <summary>
    /// Shared pointer object for application to track load/unload status
    /// </summary>
    using rc_sceneload_sts = std::shared_ptr<gfx3d_LoadStatus>;
    /// @}
}
#endif