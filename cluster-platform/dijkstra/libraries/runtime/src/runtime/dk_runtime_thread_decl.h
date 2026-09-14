//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2017] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
#ifdef _WIN32
#include <ciso646>
#endif
#if defined( PTH_REG )
#undef PTH_DECL
#define PTH_DECL( index, object, method)      threads.push_back(&s##index);

#elif defined ( PTH_BODY )
#undef PTH_DECL
#define PTH_DECL( index, object, method ) \
    void * th##index( void) \
    { \
        dk::runtime::core::DkThread * const p = threads[index]; \
        std::string threadName(#object#method); \
        p->setName(threadName); \
        while ( true ) \
        { \
            bool b; \
            { \
                std::lock_guard<std::mutex> guard(p->mMutex); \
                b = p->mIsRunning; \
            } \
            \
            if ( not b ) break; \
            \
            object.method(); \
        } \
        \
        return 0; \
    } \
    \
    dk::runtime::core::DkThread  s##index = { th##index, "id_##object##_##method"};
#elif defined ( PTH_ID )
#undef PTH_DECL
#define PTH_DECL( index, object, method )    TID_##object##_##method,

#else
#undef PTH_DECL
#define PTH_DECL( index, object, method )
#endif
