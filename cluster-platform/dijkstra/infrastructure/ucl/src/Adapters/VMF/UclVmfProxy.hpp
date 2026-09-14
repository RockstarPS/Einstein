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
#ifndef UCLVMFPROXY_HPP
#define UCLVMFPROXY_HPP
#pragma once

#include <iostream>
#include <thread>
#include <map>
#include "UclBlockingQueue.hpp"
#include "UclBufferPool.hpp"
#include "UclVmfInterface.hpp"

class CUclVmfProxy
{
  public:
    CUclVmfProxy();
    ~CUclVmfProxy();
    Ucl_ReturnType start();
    Ucl_ReturnType stop();

    static CUclVmfProxy &getInstance()
    {
        static CUclVmfProxy inst;
        return inst;
    }

    void vmfRxThread();
    void vmfTxThread();
    void uclDispatchThread();

    Ucl_ReturnType addVmfMsgToTxQueue(const uint8 Gx, const uint8 Ex, const uint8 * const Payload, const uint16 Size);

  private:
    bool bRequestExit;
    CUclVmfInterface vmfIf;
    CUclBlockingQueue<CUclVmfInterface::SVmfMsg *> txQueue;
    CUclBlockingQueue<CUclVmfInterface::SVmfMsg *> rxQueue;
    CUclBufferPool<1000, CUclVmfInterface::SVmfMsg> vmfMsgBufferPool;
};

extern "C" uint8 UclGen_NotifyNewMessageReceived( uint8 msgIdx, uint8 duIdx, uint8 *pPayload, uint16 Size );
extern uint32 VmfUclMsgQMutexId;

#endif //UCLVMFPROXY_HPP
