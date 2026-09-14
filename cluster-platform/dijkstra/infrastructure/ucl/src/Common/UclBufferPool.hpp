///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2017] Visteon Corporation
/// All Rights Reserved.
///
/// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
/// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
/// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
/// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
/// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
/// under all copyright laws to protect this work as a published work, when appropriate.
/// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
/// without the written authorization of Visteon Corporation.
///
///---------------------------------------------------------------------------------------------------------------------
#ifndef UCLBUFFERPOOL_HPP
#define UCLBUFFERPOOL_HPP
#pragma once

#include <cstring>
#include <mutex>

template <size_t MAX_ELEMENTS, typename BUFFER_TYPE>
class CUclBufferPool
{

    struct Element
    {
        BUFFER_TYPE buffer;
        struct Element *next;
    };

    struct Element ElementPool[MAX_ELEMENTS];

    struct Element *freeList;
	mutable std::mutex pool_guard;

  public:
    CUclBufferPool(void)
    {
        size_t i;
        std::memset(ElementPool, 0, sizeof(ElementPool));
        freeList = ElementPool;
        for (i = 0; i < (MAX_ELEMENTS - 1); i++)
        {
            ElementPool[i].next = &ElementPool[i + 1];
			std::memset((void*)&ElementPool[i].buffer, 0, sizeof(ElementPool[i].buffer));
        }
		ElementPool[i].next = nullptr;
    };

    BUFFER_TYPE *GetBuffer(void)
    {
        BUFFER_TYPE *buffPtr = nullptr;
		std::lock_guard<std::mutex> lock(pool_guard);
        if (freeList != nullptr)
        {
            buffPtr = &freeList->buffer;
            freeList = freeList->next;
        }
        return buffPtr;
    };

    void PutBuffer(BUFFER_TYPE **buffPtr)
    {
		std::lock_guard<std::mutex> lock(pool_guard);
		{
			((struct Element *)(*buffPtr))->next = freeList; /* OK since this is POD */
			freeList = (struct Element *)(*buffPtr);
			*buffPtr = nullptr;
		}
    }
};

#endif //UCLBUFFERPOOL_HPP
