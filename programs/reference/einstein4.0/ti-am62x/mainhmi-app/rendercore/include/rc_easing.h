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
///  @file    : rc_easing.h
///  @brief   : Support functions to perform easing curve/interpolations
//  Created on  : 02-Jul-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_easing_h
#define rc_easing_h

namespace rendercore_engine
{
    /// <summary>
    /// Implements the easing curves..
    /// </summary>
    /// @image html rc_easing.jpg
    class rc_easing
    {
    public:
        /// <summary>
        /// Provides the current stage of easing based on the curve selected.
        /// </summary>
        /// <param name="p_curve">Easing curve selection</param>
        /// <param name="p_time">current time position (time ranged from 0.0 to p_duration)</param>
        /// <param name="p_duration">duration of the easing</param>
        /// <returns>Returns the stage/position of the curve. (0.0 at start and 1.0 means at the end)</returns>
        static float32_t EaseFunction(const MdlEasingCurve p_curve, const float32_t p_time, const float32_t p_duration);
    };
}
#endif