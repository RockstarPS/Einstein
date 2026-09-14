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
//  Filename    : rc_assetgroup.h
//  Description : Asset group handling
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file	rc_assetgroup.h
///	\brief 		Asset group handling
#ifndef rc_assetgroup_h
#define rc_assetgroup_h

#include <cstdint>
#include <vector>

namespace rendercore_engine
{
    class rc_assetgroup
    {
    private:
        bool bLoaded = false;      ///< true if this obj is loaded
        rc_flag sceneLoadedMask;    ///< indicates for which scenes loaded this object. Used to decide how many are using
        std::string assetfile;      ///< Asset file path
        int32_t shared = static_cast<int32_t>(rc_agcst_e::RC_ASSET_ID_INVALID); ///< Shared asset ID if Some files belonging to this group are in a shared asset ID
    public:
#if ((RC_MTHREADS & RC_MTHREAD_RENDERING) != 0)
        WTAsyncTask lAssetLoadAsyncSts{ nullptr }; ///< Asset loading status for this scene
#endif
        void WaitForLoad(gfx3d_scg_project* const p_pjt, const uint32_t p_clientId, const std::string& p_resPath);
        bool Load(gfx3d_scg_project * const p_pjt, const uint32_t p_clientId, const std::string& p_resPath);
        bool UnLoad(gfx3d_scg_project* const p_pjt, const uint32_t p_clientId);
        int32_t GetSharedAssetID() const;
        rc_assetgroup(const std::string p_assetfile, const int32_t p_shared);
        ~rc_assetgroup();
    };
}
#endif