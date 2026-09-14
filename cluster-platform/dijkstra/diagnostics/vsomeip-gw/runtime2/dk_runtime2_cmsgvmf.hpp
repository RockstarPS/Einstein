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

#ifndef ART_MSG_CMSGVMF_HPP
#define ART_MSG_CMSGVMF_HPP

#include "dk_runtime2_cmsg.hpp"
#include "dk_runtime2_cfifo.hpp"
#include "dk_runtime2_csemaphore.hpp"
#include "dk_runtime2_msgsede.hpp"

#include "nw_vmf.h"
#include <string>
#include <mutex>
#include <map>
#include <set>
#include <chrono>
#include <thread>

namespace dk{
namespace runtime2{
namespace core{

class  CMsgVmf : public CMsg
{
public:
    explicit CMsgVmf(msg_map_t *_pMsgMap, const char * _prcName, uint32_t _timeout):
        prcName(_prcName),  running(true), vmfRdy(false), pMsgMap(_pMsgMap),rxq(1000), sem(0),timeout(_timeout)
     {
         vmfCliId = VMF_ERROR;
         if (_pMsgMap != NULL)
         {
             for (msg_map_t::iterator it = _pMsgMap->begin(); it != _pMsgMap->end(); ++it)
                 msgGroups.insert((it->first >> 8) & 0xFF);
         }
     }

    ART_EXPORT void stop();
    ART_EXPORT void start();
    ART_EXPORT void txMsg(std::shared_ptr<MsgSerializer> &_m);

private:
    void onRx(MsgDeserializer & _m);
	void registerVmf();
    void unregisterVmf();
    void rxDispatch();
    void rxProcess();
    std::shared_ptr<MsgDeserializer> rxVmfMessage(vmf_client_id_t vmf_client_id);

     vmf_basic_msg_big_t   rxMsgBuffer;
     vmf_client_id_t vmfCliId;
     std::string prcName;
     bool running;
     bool vmfRdy;
     msg_map_t * const pMsgMap;

     cfifo<MsgDeserializer> rxq;
     CSemaphore sem;
     uint32_t timeout;

     std::set<uint16_t> msgGroups;

     mutable std::mutex mutex;

     std::thread dispatch;
     std::thread pullMsg;
};



}   // namespace core
}   // namespace runtime2
}   // namespace dk

#endif // ART_MSG_CMSGVMF_HPP
