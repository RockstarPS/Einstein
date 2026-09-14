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
//  Filename    : rc_flag.h
//  Description : flag handling
//  Created on  : 11-Sep-2018 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file	rc_flag.h
///	\brief 		custom string class APIs
#ifndef rc_active_flag_h
#define rc_active_flag_h

#include <cstdint>
#include <vector>

namespace rendercore_engine
{
    /// \ingroup Internal
    /// @{

    /// manages a bitwise flag implementation of RC_MAX_FLAGS bits
    class rc_flag
    {
    private:
        /// Maximum number of flags supported. e.g. 1024 bit flags are supported
        static const size_t RC_MAX_FLAGS = 1024U;
        static const size_t RC_MAX_FLAG_BYTES = (RC_MAX_FLAGS / 8U);
        uint8_t flags[RC_MAX_FLAG_BYTES]; ///< storage for flag bits
        size_t count; ///< tracks the number of flags currently set
    public:
        rc_flag();
        void Set(const size_t p_id);      ///< set flag for given id    
        void Clear(const size_t p_id);    ///< clear flag for given id    
        bool IsSet(const size_t p_id) const;    ///< Is flag set for given id
        bool IsSet(const std::vector<size_t>& p_ids) const;///< Is flag set for given ids
        bool IsClear(const size_t p_id) const;  ///< Is flag clear for given id
        bool IsClear() const;             ///< Is it all clear
        size_t GetMaxFlags() const;       ///< Get the maximum supported flags
        void ClearAll();                  ///< Clear all flags
    };

    /// @}
}

#endif