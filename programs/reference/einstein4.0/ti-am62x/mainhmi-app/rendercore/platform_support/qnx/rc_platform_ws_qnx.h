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
//  Filename    : rc_platform_ws_qnx.h
//  Description : QNX Platform specific common APIs
//  Created on  : 20-Feb-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_platform_ws_qnx_h
#define rc_platform_ws_qnx_h

namespace rendercore_engine
{
    /// <summary>
    /// Sets the QNX screen pipeline and zorder to be set to the window
    /// </summary>
    /// <param name="p_pipeline">pipeline</param>
    /// <param name="p_zorder">zorder</param>
    /// <param name="p_display">display index</param>
    extern void SetupQNXScreenPipeline(const int32_t p_pipeline, const int32_t p_zorder, const int32_t p_display, const int32_t p_transp);
}

#endif