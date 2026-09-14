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

#include "dk_runtime2_cmsgvmf.hpp"
#include "dk_runtime2_cthread.hpp"

namespace dk{
namespace runtime2{
namespace core{


void CMsgVmf::registerVmf()
{
    bool vmfConnectionStatus = true;
    uint8_t numberOfVmfGroupToRegister = 0;
    uint8_t vmfGroupArray[MAX_GROUP_NUM]; /* There can be not more than a maximum of 128 VMF groups for registration.*/
    vmf_ret_t ipcServerGrpRegStatus;
    memset(vmfGroupArray, 255, sizeof(vmfGroupArray));
    while (1)
    {
        vmfCliId = nw_vmf_connect( prcName.c_str(), 0, 0, VMF_CLIENT_QUEUE_SIZE_STANDARD, MAX_VMF_DATA_LEN);

        if (0 > vmfCliId)
        {
            // todo: attach to logger
            // In case of registration failure try continuously.
            printf("Failed to connect to VMF! ProcessName: %s ", prcName.c_str());
        }
        else
        {
            break;
        }
        CThread::waitMs(1000);
    }

    for (std::set<uint16_t>::iterator it = msgGroups.begin(); it != msgGroups.end(); ++it)
    {
        vmfGroupArray[numberOfVmfGroupToRegister] = static_cast<uint8_t>(*it);
        numberOfVmfGroupToRegister++;
    }

    if (numberOfVmfGroupToRegister != 0)
    {
        ipcServerGrpRegStatus = nw_vmf_register_msg_group(vmfCliId, numberOfVmfGroupToRegister, &vmfGroupArray[0]);
        if (ipcServerGrpRegStatus < 0)
        {
            vmfConnectionStatus = false;
        }
    }

    if (!vmfConnectionStatus )
    {
        printf( "registerVmf failed !\n");
    }
    else
    {
        vmfRdy = true;
    }
}

void CMsgVmf::unregisterVmf()
{

    uint8_t numberOfVmfGroupToRegister = 0;
    uint8_t vmfGroupArray[MAX_GROUP_NUM];

    vmfRdy = false;

    for (std::set<uint16_t>::iterator it = msgGroups.begin(); it != msgGroups.end(); ++it)
    {
        vmfGroupArray[numberOfVmfGroupToRegister] = static_cast<uint8_t>(*it);
        numberOfVmfGroupToRegister++;
    }

    if (numberOfVmfGroupToRegister != 0)
    {
        (void)nw_vmf_de_register_msg_group(vmfCliId, numberOfVmfGroupToRegister, &vmfGroupArray[0]);
    }

    (void)nw_vmf_disconnect(vmfCliId);
}

void  CMsgVmf::txMsg(std::shared_ptr<MsgSerializer> &_m)
{
    if (vmfRdy )
    {
        {
            std::unique_lock<std::mutex>  lock(mutex);

            rxMsgBuffer.msg_base.id.group = (_m->mMsgId >> 8) & 0xFF;
            rxMsgBuffer.msg_base.id.event = _m->mMsgId & 0xFF;
            rxMsgBuffer.data.length = 0;


            rxMsgBuffer.data.pl[rxMsgBuffer.data.length++] = _m->mSenderId;
            rxMsgBuffer.data.pl[rxMsgBuffer.data.length++] = _m->mMsgCnt;

            // add payload
            (void)memcpy(&rxMsgBuffer.data.pl[rxMsgBuffer.data.length], (uint8_t*)(void*)_m->getSerializedData(), _m->getSerializedDataSize());
            rxMsgBuffer.data.length += _m->getSerializedDataSize();
        }

        if (rxMsgBuffer.data.length > 0)
        {
            nw_vmf_send_basic(vmfCliId, (vmf_basic_msg_t*)&rxMsgBuffer);
        }
        else
        {
            // todo: attach to logger
            printf("Wrong Message length sending attempted in ui.server");
        }
    }
}

void CMsgVmf::onRx(MsgDeserializer & _m)
 {
    if (pMsgMap->find(_m.mMsgId) != pMsgMap->end())
    {
         rxq.push(_m);
         sem.signal();
    }
 };

std::shared_ptr<MsgDeserializer> CMsgVmf::rxVmfMessage(vmf_client_id_t vmf_client_id)
{
    vmf_ret_t vmfRes = VMF_ERROR;
    vmf_msg_big_t vmfMsgRx;
    std::shared_ptr<MsgDeserializer> pm = nullptr;

    if (timeout!=0)
    {
        vmfRes = nw_vmf_timed_receive(vmf_client_id, (vmf_msg_t*)&vmfMsgRx, sizeof(vmfMsgRx), 3000);
    }
    else
    {
      vmfRes = nw_vmf_receive(vmf_client_id, (vmf_msg_t*)&vmfMsgRx, sizeof(vmfMsgRx));
    }


    if (vmfRes > VMF_OK && MSG_TYPE_BASIC_MESSAGE == NW_VMF_MSG_TYPE(&vmfMsgRx))
    {
        uint8_t msgSenderId = vmfMsgRx.vmf_basic_msg.data.pl[0];
        uint8_t msgCnt = vmfMsgRx.vmf_basic_msg.data.pl[1];


        pm = std::make_shared< MsgDeserializer>(vmfMsgRx.vmf_basic_msg.msg_base.id.event |
            (uint16_t)((vmfMsgRx.vmf_basic_msg.msg_base.id.group << 8) & 0xFF00),
            msgSenderId,
            msgCnt,
            (uint8_t *)(&vmfMsgRx.vmf_basic_msg.data.pl[2]),
            (uint32_t)(vmfMsgRx.vmf_basic_msg.data.length - 2u));
    }

    return pm;
};

void CMsgVmf::rxDispatch()
{
    registerVmf();

    if (pMsgMap == NULL)
    {
        while (running)
        {
            CThread::waitMs(1000);
        }
    }
    else
    {
        while (running)
        {
            std::shared_ptr<MsgDeserializer>  m = rxVmfMessage(vmfCliId);

            while (m)
            {
                onRx(*m);
                m.reset();
                m = rxVmfMessage(vmfCliId);
            }

            CThread::waitMs(1);
        }
    }
}

void  CMsgVmf::rxProcess()
{
    while (running)
    {
        sem.wait();

        /// pump out the queue
        MsgDeserializer * m = rxq.pull();

        while (m)
        {
            (*pMsgMap)[m->mMsgId](*m);
            delete m;

            m = rxq.pull();
        }
    }
}

void CMsgVmf::stop()
{
    if(timeout!=0)
    {
        if(running)
        {
            unregisterVmf();
            running = false;

            dispatch.join();
            if(pMsgMap!=NULL) pullMsg.join();
        }
    }
    else std::cout<<"Error vmf cannot be stopped because timeout is 0!\n";
}

void CMsgVmf::start()
{
    running = true;
    dispatch = std::thread(&CMsgVmf::rxDispatch, this);
    if(pMsgMap!=NULL)
    {
        pullMsg =  std::thread(&CMsgVmf::rxProcess, this);
    }
}

}   // namespace dk
}   // namespace runtime2
}   // namespace core

