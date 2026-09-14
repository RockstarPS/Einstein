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

#include "dk_gw_cmsgvmf.hpp"
#include "dk_runtime2_cthread.hpp"
#include "srvgw_core.hpp"


#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
LOG_IMPORT_CONTEXT(gSrvgwsomeipLogContext);
#endif

namespace dk{
namespace gw{

CMsgVmf::CMsgVmf(std::vector<std::pair<vsomeip::service_t, vsomeip::method_t>>* _pMsgIds,const char * _prcName,uint32_t _timeout)
:prcName(_prcName)
,running(true)
,vmfRdy(false)
,rxq(5000) // Review comments (p1) increase queue size to 500
,sem(0)
,nNofVmfMsgReceived(0)
,nNofSomeipMsgSend(0)
,nNofSomeipMsgReceived(0)
,nNofVmfMsgSend(0)
#ifndef SOMEIPGW_DLT_LOGGER_ENABLED
,PF_TRC_LOGGER_INIT(logger, "SRV_GATEWAY_VMF", "SRVV")
#endif
,timeout(_timeout)
,DIstate({0})
,IVIstate({0,0,0,0})
,VIPSystemStateChange({0,0})
,DIStateChange({0,0})
,IVIStateChange({0,0})
{
	vmfCliId = VMF_ERROR;

	for (auto id : *_pMsgIds)
	{
		 msgGroups.insert(std::get<0>(id));
		 if(std::get<1>(id)>=0x8000)
		 {
			 msgIds.insert(std::get<0>(id) * 256 + (std::get<1>(id)-0x8000));
		 }
	}
	// subscribe for DI power messages for STAT
	msgGroups.insert(POWER_GROUP_SOC);
	msgIds.insert(POWER_GROUP_SOC * 256 + (POWER_SOC_STATE_VMF));

	// subscribe for domain restart request
	msgIds.insert(POWER_GROUP_SOC * 256 + (POWER_SOC_RESTART_RES_VMF));
}

CMsgVmf::~CMsgVmf()
{

}
void CMsgVmf::registerVmf()
{
	bool vmfConnectionStatus = true;
	uint8_t numberOfVmfGroupToRegister = 0;
	uint8_t vmfGroupArray[MAX_GROUP_NUM]; /* There can be not more than a maximum of 128 VMF groups for registration.*/
	vmf_ret_t ipcServerGrpRegStatus;
	memset(vmfGroupArray, 255, sizeof(vmfGroupArray));

	while (1)
	{
		vmfCliId = nw_vmf_connect( prcName.c_str(), 0, 0, VMF_CLIENT_QUEUE_SIZE_BIG, MAX_VMF_DATA_LEN);

		if (0 > vmfCliId)
		{
			// TODO: attach to logger
			// In case of registration failure try continuously.
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
            LOGW(&gSrvgwsomeipLogContext,"SRVGW - Failed to connect to VMF! ProcessName:", prcName.c_str());
#else
			PF_TRC_WARN(logger,"SRVGW - Failed to connect to VMF! ProcessName: %s ", prcName.c_str());
#endif
		}
		else
		{
			break;
		}

		dk::runtime2::core::CThread::waitMs(500);
	}

	for (std::set<uint8_t>::iterator it = msgGroups.begin(); it != msgGroups.end(); ++it)
	{
		vmfGroupArray[numberOfVmfGroupToRegister] = *it;
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
        LOGI(&gSrvgwsomeipLogContext,"SRVGW - Reg VMF Grp:", *it);
#else
		PF_TRC_INFO(logger,"SRVGW - Reg VMF Grp: %d", *it);
#endif
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
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
        LOGI(&gSrvgwsomeipLogContext,"SRVGW - registerVmf failed !");
#else
		PF_TRC_ERR(logger,"SRVGW - registerVmf failed !");
#endif
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

    for (std::set<uint8_t>::iterator it = msgGroups.begin(); it != msgGroups.end(); ++it)
    {
        vmfGroupArray[numberOfVmfGroupToRegister] = *it;
        numberOfVmfGroupToRegister++;
    }

    if (numberOfVmfGroupToRegister != 0)
    {
        (void)nw_vmf_de_register_msg_group(vmfCliId, numberOfVmfGroupToRegister, &vmfGroupArray[0]);
    }

    (void)nw_vmf_disconnect(vmfCliId);
}

void  CMsgVmf::txMsg(vsomeip::byte_t *data, vsomeip::length_t size, uint8_t grId, uint8_t evId )
{
    if (vmfRdy )
    {
        {
			nNofSomeipMsgReceived++;
			
            std::unique_lock<std::mutex>  lock(mutex);

            rxMsgBuffer.msg_base.id.group = grId;
            rxMsgBuffer.msg_base.id.event = evId;
            rxMsgBuffer.data.length = 0;


            rxMsgBuffer.data.pl[rxMsgBuffer.data.length++] = 0x00;
            rxMsgBuffer.data.pl[rxMsgBuffer.data.length++] = 0x00;

            // add payload
            (void)memcpy(&rxMsgBuffer.data.pl[rxMsgBuffer.data.length], data, size);
            rxMsgBuffer.data.length += size;
        }

        if (rxMsgBuffer.data.length > 0)
        {
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
            LOGI(&gSrvgwsomeipLogContext,"TX VMF - Grp:",rxMsgBuffer.msg_base.id.group, "Evt:",rxMsgBuffer.msg_base.id.event, "Len: ",(rxMsgBuffer.data.length - 2));
#else
        	PF_TRC_INFO(logger,"TX VMF - Grp: %d, Evt: %d, Len: %d",
        			rxMsgBuffer.msg_base.id.group, rxMsgBuffer.msg_base.id.event, (rxMsgBuffer.data.length - 2));
#endif

            nw_vmf_send_basic(vmfCliId, (vmf_basic_msg_t*)&rxMsgBuffer);
			
			nNofVmfMsgSend++;
        }
        else
        {
            // TODO: attach to logger
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
            LOGE(&gSrvgwsomeipLogContext,"SRVGW - CMsgVmf: Wrong Message length sending");
#else
        	PF_TRC_ERR(logger,"SRVGW - CMsgVmf: Wrong Message length sending");
#endif
        }
    }
}

void CMsgVmf::setVsomeipServiceGw(CVsomeipServiceGw* _pVsomeipServiceGw)
{
	pVsomeipServiceGw = _pVsomeipServiceGw;
}

void CMsgVmf::onRx(dk::runtime2::core::MsgDeserializer & _m)
 {
    if (msgIds.find(_m.mMsgId) != msgIds.end()) // TODO: need to check if it is taking time and remove it.
    {
		 nNofVmfMsgReceived++;
         rxq.push(_m);
         sem.signal();
    }
    else if(POWER_GROUP_SOC != (_m.mMsgId&0xFF00)>>8)
    {
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
        LOGW(&gSrvgwsomeipLogContext,"SRVGW - Unmapped VMF Message: Grp: ",((_m.mMsgId&0xFF00)>>8), "Evt:", ((_m.mMsgId&0x00FF) + 0x8000));
#else
        PF_TRC_WARN(logger,"SRVGW - Unmapped VMF Message: Grp - %d, Evt - %d",((_m.mMsgId&0xFF00)>>8), ((_m.mMsgId&0x00FF) + 0x8000));
#endif
    }
 };

std::shared_ptr<dk::runtime2::core::MsgDeserializer> CMsgVmf::rxVmfMessage(vmf_client_id_t vmf_client_id)
{
    vmf_ret_t vmfRes = VMF_ERROR;
    vmf_msg_big_t vmfMsgRx;
    std::shared_ptr<dk::runtime2::core::MsgDeserializer> pm = nullptr;

    vmfRes = nw_vmf_receive(vmf_client_id, (vmf_msg_t*)&vmfMsgRx, sizeof(vmfMsgRx));

    if (vmfRes > VMF_OK && MSG_TYPE_BASIC_MESSAGE == NW_VMF_MSG_TYPE(&vmfMsgRx))
    {
        uint8_t msgSenderId = vmfMsgRx.vmf_basic_msg.data.pl[0];
        uint8_t msgCnt = vmfMsgRx.vmf_basic_msg.data.pl[1];
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
        LOGI(&gSrvgwsomeipLogContext,"RX VMF - Grp:",vmfMsgRx.vmf_basic_msg.msg_base.id.group," Evt:",vmfMsgRx.vmf_basic_msg.msg_base.id.event,"Len:",(vmfMsgRx.vmf_basic_msg.data.length - 2u));
#else
    	PF_TRC_INFO(logger,"RX VMF - Grp: %d, Evt: %d, Len: %d",
    				vmfMsgRx.vmf_basic_msg.msg_base.id.group, vmfMsgRx.vmf_basic_msg.msg_base.id.event, (vmfMsgRx.vmf_basic_msg.data.length - 2u));
#endif

        pm = std::make_shared< dk::runtime2::core::MsgDeserializer>(vmfMsgRx.vmf_basic_msg.msg_base.id.event |
            (uint16_t)((vmfMsgRx.vmf_basic_msg.msg_base.id.group << 8) & 0xFF00),
            msgSenderId,
            msgCnt,
            (uint8_t *)(&vmfMsgRx.vmf_basic_msg.data.pl[2]),
            (uint32_t)(vmfMsgRx.vmf_basic_msg.data.length - 2u));
    }
    else
    {
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
        LOGE(&gSrvgwsomeipLogContext,"SRVGW - Received non Basic VMF Message");
#else
    	PF_TRC_ERR(logger,"SRVGW - Received non Basic VMF Message");
#endif

    }

    return pm;
};

void CMsgVmf::rxDispatch()
{
    registerVmf();

    while (running)
    {
        std::shared_ptr<dk::runtime2::core::MsgDeserializer>  m = rxVmfMessage(vmfCliId);

        while (m)
        {
            onRx(*m);
            m.reset();
            m = rxVmfMessage(vmfCliId);
        }
    }
}

void  CMsgVmf::rxProcess()
{
	const uint8_t *states;

    while (running)
    {
        sem.wait();
        // pump out the queue
        dk::runtime2::core::MsgDeserializer * m = rxq.pull();

        while (m)
        {

			if(POWER_GROUP_VIP == static_cast<vsomeip::service_t>((m->mMsgId&0xFF00)>>8))
			{

				states = m->getData();

				if(POWER_SYSTEM_STATE_CHANGE_VMF == (m->mMsgId&0x00FF))
				{
					VIPSystemStateChange.currentState = states[0];
					VIPSystemStateChange.oldState = states[1];
				}
				else if(POWER_DI_STATE_CHANGE_VMF == (m->mMsgId&0x00FF))
				{
					DIStateChange.oldState = states[0];
					DIStateChange.currentState = states[1];
				}
				else if(POWER_IVI_STATE_CHANGE_VMF == (m->mMsgId&0x00FF))
				{
					IVIStateChange.oldState = states[0];
					IVIStateChange.currentState = states[1];
				}
				else if (POWER_SOC_RESTART_REQ_VMF == (m->mMsgId&0x00FF))
				{
					if(IVI_DOMAIN_ID == states[0])
					{
						IVIstate.isFactResetRebootReqd = 1;
					}
				}
				else
				{
				}
			}

			//Ignoring DI power state request. As it is subscribed for stat
			if( POWER_GROUP_SOC != static_cast<vsomeip::service_t>((m->mMsgId&0xFF00)>>8))
			{
				pVsomeipServiceGw->sendMsg(static_cast<vsomeip::service_t>((m->mMsgId&0xFF00)>>8), (m->mMsgId&0x00FF) +0x8000, m->getData(), m->getSize());
			}
			else
			{
				if (POWER_SOC_STATE_VMF == (m->mMsgId&0x00FF))
				{
					states = m->getData();
					//To avoid the IVI init and fullrun states
					if(DI_DOMAIN_ID == states[0])
					{
						DIstate.currentState = states[1];
					}
					else if(IVI_DOMAIN_ID == states[0])
					{
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
                        LOGE(&gSrvgwsomeipLogContext,"Sync cach message states[0]:",states[0], "states[1]:",states[1], "displayOff:",IVIstate.isTransitedForDisplayOff, 
						     "RebootReq:",IVIstate.isFactResetRebootReqd,"Restarted:",IVIstate.isRestarted,"CurrentState:",IVIstate.currentState);
#else
						PF_TRC_ERR(logger,"Sync cach message states[0]: %d states[1]: %d displayOff: %d RebootReq: %d Restarted: %d CurrentState: %d",states[0],states[1],
								IVIstate.isTransitedForDisplayOff,IVIstate.isFactResetRebootReqd,IVIstate.isRestarted,IVIstate.currentState);
#endif
						if(IVI_POWER_STATE_SYSTEM_IDLE == states[1])
						{
							if(IVI_POWER_STATE_FULL_RUN == IVIstate.currentState)
							{
								IVIstate.isTransitedForDisplayOff = 1;
							}
						}
						else if(IVI_POWER_STATE_FULL_RUN == states[1])
						{
							// usecase1: Factory Reset, currentState (00 / 05 /07) is less then or equal to 07
							// usecase2: HealthManager Reset, currentState (00 / 05 / 06 / 07) is less then or equal to 07
							// usecase3: VM Crash, currentState (00 / 05 / 06 / 07) is less then or equal to 07
							if(((IVIstate.currentState > 0) && (IVIstate.currentState < IVI_POWER_STATE_FULL_RUN)) &&
									((0 == IVIstate.isTransitedForDisplayOff) || (1 == IVIstate.isFactResetRebootReqd))) // usecase1
							{
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
                                LOGE(&gSrvgwsomeipLogContext,"Sync cach message displayOff:",IVIstate.isTransitedForDisplayOff, 
						           "RebootReq:",IVIstate.isFactResetRebootReqd,"Restarted:",IVIstate.isRestarted,"CurrentState:",IVIstate.currentState);

#else
								PF_TRC_ERR(logger,"Sync cach message displayOff: %d RebootReq: %d Restarted: %d CurrentState: %d Factory",
										IVIstate.isTransitedForDisplayOff,IVIstate.isFactResetRebootReqd,IVIstate.isRestarted,IVIstate.currentState);
#endif
								pVsomeipServiceGw->syncCacheMessages(0);
							}
							else if(((IVIstate.currentState > 0) && (IVIstate.currentState <= IVI_POWER_STATE_FULL_RUN)) && (1 == IVIstate.isRestarted)) // usecase2 & usecase3
							{
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
                                LOGE(&gSrvgwsomeipLogContext,"Sync cach message displayOff:",IVIstate.isTransitedForDisplayOff, 
						                    "RebootReq:",IVIstate.isFactResetRebootReqd,"Restarted:",IVIstate.isRestarted,"CurrentState:",IVIstate.currentState);
#else
								PF_TRC_ERR(logger,"Sync cach message displayOff: %d RebootReq: %d Restarted: %d CurrentState: %d Health",
										IVIstate.isTransitedForDisplayOff,IVIstate.isFactResetRebootReqd,IVIstate.isRestarted,IVIstate.currentState);
#endif
								pVsomeipServiceGw->syncCacheMessages(0);
							}
							else
							{
							}

							IVIstate.isRestarted = 0;
							IVIstate.isTransitedForDisplayOff = 0;
							IVIstate.isFactResetRebootReqd = 0;
						}
						else
						{
						}

						IVIstate.currentState = states[1];
					}
				}
				else if (POWER_SOC_RESTART_RES_VMF == (m->mMsgId&0x00FF))
				{
					states = m->getData();
					if(IVI_DOMAIN_ID == states[0])
					{
						IVIstate.isRestarted = 1;
					}
				}
				else
				{
				}
			}
			delete m;
			nNofSomeipMsgSend++;
			m = rxq.pull();
        }
    }
}

void CMsgVmf::printStatInfo()
{
	while (running)
    {
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
        LOGI(&gSrvgwsomeipLogContext,"STAT VMF Rx Msgs    :", nNofVmfMsgReceived);
		LOGI(&gSrvgwsomeipLogContext,"STAT SOMEIP Tx Msgs :", nNofSomeipMsgSend);
		LOGI(&gSrvgwsomeipLogContext,"STAT SOMEIP Rx Msgs :", nNofSomeipMsgReceived);
		LOGI(&gSrvgwsomeipLogContext,"STAT VMF Tx Msgs    :", nNofVmfMsgSend);
		LOGI(&gSrvgwsomeipLogContext,"STAT VMF Rx Queue ", rxq.getSize(), rxq.getMaxSize() );
#else
		PF_TRC_INFO(logger,"STAT VMF Rx Msgs    : %d", nNofVmfMsgReceived);
		PF_TRC_INFO(logger,"STAT SOMEIP Tx Msgs : %d", nNofSomeipMsgSend);
		PF_TRC_INFO(logger,"STAT SOMEIP Rx Msgs : %d", nNofSomeipMsgReceived);
		PF_TRC_INFO(logger,"STAT VMF Tx Msgs    : %d", nNofVmfMsgSend);
		PF_TRC_INFO(logger,"STAT VMF Rx Queue   : %d ( %d ) ", rxq.getSize(), rxq.getMaxSize() );
#endif

		// //PF_TRC_ERR(logger,"STAT VIP StateChange	: %d, %d ", VIPSystemStateChange.oldState, VIPSystemStateChange.currentState);
		// //PF_TRC_ERR(logger,"STAT IVI StateChange	: %d, %d ", IVIStateChange.oldState, IVIStateChange.currentState);
		// //PF_TRC_ERR(logger,"STAT DI StateChange		: %d, %d ", DIStateChange.oldState, DIStateChange.currentState);
		// //PF_TRC_ERR(logger,"STAT DI Current State	: %d ", DIstate.currentState);
		// //PF_TRC_ERR(logger,"STAT IVI Current State	: %d ", IVIstate.currentState);

		std::this_thread::sleep_for(std::chrono::milliseconds(5000));
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
            if(NULL != pVsomeipServiceGw)
            {
            	pullMsg.join();
            }
			statinfo.join();
        }
    }
    else
    {
    	////PF_TRC_WARN(logger,"Error vmf cannot be stopped because timeout is 0!\n");
    }
}

void CMsgVmf::start()
{
    running = true;

    if(NULL != pVsomeipServiceGw)
    {
    	dispatch = std::thread(&CMsgVmf::rxDispatch, this);
        pullMsg =  std::thread(&CMsgVmf::rxProcess, this);
        statinfo = std::thread(&CMsgVmf::printStatInfo, this);
    }

}

}   // namespace gw
}   // namespace dk

