//---------------------------------------------------------------------------------------------------------------------
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
//---------------------------------------------------------------------------------------------------------------------
#ifndef UCLBLOCKINGQUEUE_HPP
#define UCLBLOCKINGQUEUE_HPP
#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
class CUclBlockingQueue
{
  public:
    void push(T const &_data)
    {
		bool SigTrg = false;
		{
			std::lock_guard<std::mutex> lock(guard);
			if (queue.empty())
			{
				SigTrg = true;
			}
			queue.push(_data);
		}
		
		if(SigTrg == true)
		{				
			signal.notify_one();
		}
    }

    bool empty() const
    {
        std::lock_guard<std::mutex> lock(guard);
        return queue.empty();
    }

    bool tryPop(T &_value)
    {
        std::lock_guard<std::mutex> lock(guard);
        if (queue.empty())
        {
            return false;
        }
        _value = queue.front();
        queue.pop();
        return true;
    }

    void waitAndPop(T &_value)
    {
        std::unique_lock<std::mutex> lock(guard);
        while (queue.empty())
        {
            signal.wait(lock);
        }
        _value = queue.front();
        queue.pop();
    }

    bool tryWaitAndPop(T &_value, int _milli)
    {
        std::unique_lock<std::mutex> lock(guard);
        while (queue.empty())
        {
            signal.wait_for(lock, std::chrono::milliseconds(_milli));
            return false;
        }

        _value = queue.front();
        queue.pop();
        return true;
    }

  private:
    std::queue<T> queue;
    mutable std::mutex guard;
    std::condition_variable signal;
};

#endif //UCLBLOCKINGQUEUE_HPP
