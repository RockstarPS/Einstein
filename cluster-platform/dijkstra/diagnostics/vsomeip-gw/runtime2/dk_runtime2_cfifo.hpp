/**
 * VISTEON CORPORATION CONFIDENTIAL
 * ________________________________
 *
 * [2017] Visteon Corporation
 * All Rights Reserved.
 *
 * NOTICE: This is an unpublished work of authorship, which contains trade secrets.
 * Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
 * its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
 * or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
 * in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
 * under all copyright laws to protect this work as a published work, when appropriate.
 * Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
 * without the written authorization of Visteon Corporation.
 */

#ifndef ART_MSG_CFIFO_HPP
#define ART_MSG_CFIFO_HPP

#include <queue>

#include "dk_runtime2_msgsede.hpp"
#include <mutex>

#ifdef ART_EXPORT_LIB
    #ifndef ART_EXPORT
    #define ART_EXPORT   __declspec( dllexport )
    #endif
#else
    #ifndef ART_EXPORT
    #define ART_EXPORT
    #endif
#endif

namespace dk{
namespace runtime2{
namespace core{

template <class T>
    class cfifo: protected std::queue<T*>
    {
    public:
        cfifo(const unsigned _maxCount)
        {
            maxCount = _maxCount;
        }

        virtual ~cfifo()
        {
        }

        void push(T * const _pm)
        {
            if (_pm != nullptr)
            {
                std::unique_lock<std::mutex>  lock(mutex);
                {
                    if (_pm->isValid())
                    {
                        cfifo<T>::queue::push(_pm);
                    }
                    //else
                    //    std::cerr << "<<Invalid message>>\n";
                }
            }
        }

        void push(T & _m)
        {
            push(_m.mMsgId, _m.getData(), _m.getSize());
        }

        void push(const mid_t _id, const uint8_t * _data,
                uint32_t _size)
        {
            std::unique_lock<std::mutex>  lock(mutex);
            {
                if (_data && (_size > 0) && (cfifo<T>::size() < maxCount))
                {
                    T * pm = new T(_id, _data, _size);
                    cfifo<T>::queue::push(pm);
                }
            }
        }

        T * pull()
        {
            T * pm = nullptr;

            std::unique_lock<std::mutex>  lock(mutex);
            {
                if (cfifo<T>::size() > 0u)
                {
                    pm = cfifo<T>::queue::front();
                    cfifo<T>::queue::pop();
                }
            }

            return pm;
        }
        
        uint32_t getSize()
        {
            return cfifo<T>::size();
        }
		
		uint32_t getMaxSize()
        {
            return maxCount;
        }
        
    protected:

        unsigned maxCount;

        mutable std::mutex mutex;

    };

}   // namespace dk
}   // namespace runtime2
}   // namespace core

#endif /// ART_MSG_CFIFO_HPP
