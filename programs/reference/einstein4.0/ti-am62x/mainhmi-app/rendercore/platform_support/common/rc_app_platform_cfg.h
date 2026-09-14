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
//  Filename    : rc_app_platform_cfg.h
//  Description : Platform specific configurations. Modify as per requirement
//  Created on  : 29-Jun-2021 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_app_platform_cfg_h
#define rc_app_platform_cfg_h

#include "gfx3d_scg_types.h"

namespace rendercore_engine
{
    class rc_app_platform_cfg : public rc_pfm_cfg_ibase
    {
    public:
        /// <summary>
        /// Number of font faces to be cached. Once crosses the limit, cache will be flushed
        /// and unused items are removed.
        /// Currently this is applied only for Freetype
        /// </summary>
        size_t RcGetMaxFontFacesInCache() const override
        {
            return(20U);
        }
        /// <summary>
        /// Number of font sizes to be cached. Once crosses the limit, cache will be flushed
        /// and unused items are removed.
        /// Currently this is applied only for Freetype
        /// </summary>
        size_t RcGetMaxFontSizesInCache() const override
        {
            return(20U);
        }
        /// <summary>
        /// Font engine cache size. More cache means more performance
        /// Tune it according to needs.
        /// </summary>
        size_t RcGetFontEngineCacheSize() const override
        {
            return(1U * 1024U * 1024U);
        }
        /// <summary>
        /// Maximum mmeory allocation threshold where the memory monitor starts to unload least
        /// used items to freeup GPU memory.
        /// </summary>
        size_t RcGetDefaultGpuMemoryThreshold() const override
        {
            return (64U * 1024U * 1024U);
        }
        /// <summary>
        /// Maximum mmeory allocation threshold where the memory monitor starts to unload least
        /// used items to freeup Heap memory.
        /// </summary>
        size_t RcGetDefaultHeapMemoryThreshold() const override
        {
            return (64U * 1024U * 1024U);
        }
        /// <summary>
        /// Maximum heap allowed for the MonoType WorldShaper Engine
        /// A value of 256k is a large general heap for shaping
        /// Currently this is applied only for monotype engine
        /// </summary>
        size_t RcGetTextShaperCacheSize() const override
        {
            return(256U * 1024U);
        }
        /// <summary>
        /// Maximum depth allowed for a scene graph. Any nodes beyond this are not processed
        /// This will limit the maximum recursion excercised by the engine
        /// > 1 to 127 is the valid range.
        /// </summary>
        uint32_t RcGetMaxSceneDepth() const override
        {
            return(50U);
        }
        /// <summary>
        /// Maximum length of characters processed by the font engine. Any characters above 
        /// this limit are not processed and so not rendered as well.
        /// </summary>
        uint32_t RcGetMaxStringLength() const override
        {
            return(400U);
        }
        /// <summary>
        /// Maximum number of nodes allowed in project.
        /// </summary>
        size_t RcGetMaxNumberOfNodes() const override
        {
            return(0xFFFFU);
        }
        /// <summary>
        /// Maximum width of a text box in pixels. It is to restrict huge
        /// memory allocations if the application entered very large value for
        /// bounding box.
        /// </summary>
        /// <returns>width in pixels</returns>
        uint16_t RcGetMaxTextBBoxWidth() const override
        {
            return(2048U);
        }
        /// <summary>
        /// If the touch/gesture processing is required, then return true
        /// If no input processing is needed return false 
        /// </summary>
        /// <returns>true or false</returns>
        bool RcIsInputProcessingEnabled() const override
        {
            // Only constant value to be returned. Do not change the result during run time.
            return(false);
        }
        /// <summary>
        /// Skip scripts of invisible nodes when this returns true
        /// If false always executes the scripts Update() function regardless of node visibility
        /// </summary>
        /// <returns>true to skip or false to run always</returns>
        bool RcIsSkipInactiveScriptsEnabled() const override
        {
            return(false);
        }
        /// <summary>
        /// Returns the maximum number of bytes a single malloc can perform
        /// </summary>
        /// <returns>size in bytes</returns>
        size_t RcGetMaxSingleAllocSize() const override
        {
            return(256U * 1024U * 1024U);
        }
    };
}
#endif
