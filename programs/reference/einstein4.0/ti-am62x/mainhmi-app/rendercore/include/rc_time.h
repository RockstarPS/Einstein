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
//  Filename    : rc_time.h
//  Description : time data for script usage
//  Created on  : 31-Jul-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  rc_time.h
/// \brief time data for script usage.
#ifndef rc_time_h
#define rc_time_h

namespace rendercore_engine
{
    /// \ingroup Behaviour
    /// @{

    /// time data for script usage
    struct rc_time
    {
        float32_t time = 0.0F;      ///< describes current time
        float32_t deltaTime = 0.0F; ///< time difference between the current and previous frame.
    };

    /// @}
}
#endif