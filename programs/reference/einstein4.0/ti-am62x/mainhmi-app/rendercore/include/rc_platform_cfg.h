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
//  Filename    : rc_platform_cfg.h
//  Description : Platform specific configurations.
//  Created on  : 29-Jun-2021 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_platform_cfg_h
#define rc_platform_cfg_h

namespace rendercore_engine
{
    class rc_pfm_cfg_ibase
    {
    public:
        /// <summary>
        /// Number of font faces to be cached. Once crosses the limit, cache will be flushed
        /// and unused items are removed.
        /// Currently this is applied only for Freetype. Default is 20
        /// </summary>
        virtual size_t RcGetMaxFontFacesInCache() const;
        /// <summary>
        /// Number of font sizes to be cached. Once crosses the limit, cache will be flushed
        /// and unused items are removed.
        /// Currently this is applied only for Freetype. Default is 20
        /// </summary>
        virtual size_t RcGetMaxFontSizesInCache() const;
        /// <summary>
        /// Font engine cache size in bytes. More cache means more performance
        /// Tune it according to needs. Defailt is 1MB
        /// </summary>
        virtual size_t RcGetFontEngineCacheSize() const;
        /// <summary>
        /// Returns the maximum mmeory allocation threshold in bytes where the memory monitor starts to unload least
        /// used items to freeup GPU memory. Defailt is 64MB
        /// </summary>
        virtual size_t RcGetDefaultGpuMemoryThreshold() const;
        /// <summary>
        /// Returns the maximum mmeory allocation threshold where the memory monitor starts to unload least
        /// used items to freeup Heap memory. Defailt is 64MB
        /// </summary>
        virtual size_t RcGetDefaultHeapMemoryThreshold() const;
        /// <summary>
        /// Maximum heap allowed for the MonoType WorldShaper Engine in bytes
        /// A value of 256k is a large general heap for shaping
        /// Currently this is applied only for monotype engine. Default is 256K
        /// </summary>
        virtual size_t RcGetTextShaperCacheSize() const;
        /// <summary>
        /// Maximum depth allowed for a scene graph. Any nodes beyond this are not processed
        /// This will limit the maximum recursion excercised by the engine. Default is 50
        /// </summary>
        virtual uint32_t RcGetMaxSceneDepth() const;
        /// <summary>
        /// Maximum length of characters processed by the font engine. Any characters above 
        /// this limit are not processed and so not rendered as well. Default is 400
        /// </summary>
        virtual uint32_t RcGetMaxStringLength() const;
        /// <summary>
        /// Maximum number of nodes allowed in project. Default is 65535
        /// </summary>
        virtual size_t RcGetMaxNumberOfNodes() const;
        /// <summary>
        /// Maximum width of a text box in pixels. It is to restrict huge
        /// memory allocations if the application entered very large value for
        /// bounding box. Default is 2048
        /// </summary>
        /// <returns>width in pixels</returns>
        virtual uint16_t RcGetMaxTextBBoxWidth() const;
        /// <summary>
        /// If the touch/gesture processing is required, then return true
        /// If no input processing is needed return false. Default is false
        /// Note :- return a const result always. Do not change return value during run time
        /// </summary>
        /// <returns>true or false</returns>
        virtual bool RcIsInputProcessingEnabled() const;
        /// <summary>
        /// Skip scripts of invisible nodes when this returns true
        /// If false always executes the scripts Update() function regardless of node visibility
        ///  Default is false
        /// </summary>
        /// <returns>true to skip or false to run always</returns>
        virtual bool RcIsSkipInactiveScriptsEnabled() const;
        /// <summary>
        /// Returns the maximum number of bytes a single malloc can perform
        /// Default is 256MB
        /// </summary>
        /// <returns>size in bytes</returns>
        virtual size_t RcGetMaxSingleAllocSize() const;
    };
}

#endif
