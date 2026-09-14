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
//  Filename    : rc_global_mem_allocator.h

//  Description : global memory allocator
//  Created on  : 
///////////////////////////////////////////////////////////////////////////////
#ifndef rc_global_mem_allocator_h
#define rc_global_mem_allocator_h
#include <iostream>
#include <cstdlib>

namespace rendercore_engine
{
    /// Global new and delete overload
    void rc_freevp(const void* const p_ptr);
    template<typename T>
    inline void rc_freecm(const T* const p_ptr)
    {
        const void* const fl_ptr = reinterpret_cast<const void* const>(p_ptr);
        rc_freevp(fl_ptr);
    }
    template<typename T>
    inline void rc_free(const T* const p_ptr)
    {
        const void* const fl_ptr = reinterpret_cast<const void* const>(p_ptr);
        rc_freevp(fl_ptr);
    }
    void* rc_malloc(const size_t p_size);
    void* rc_calloc(const size_t p_items, const size_t p_size);
    bool IsMemAllocFailed();
}

#endif