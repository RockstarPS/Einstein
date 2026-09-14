
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include "srvgw_core.hpp"
#include "msg_ids.hpp"

#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
LOG_IMPORT_CONTEXT(gSrvgwsomeipLogContext);
#endif

namespace dk{
namespace gw{

CVsomeipServiceGw::CVsomeipServiceGw(std::vector<std::pair<vsomeip::service_t, vsomeip::method_t>>* _pMsgIds,
		std::map< vsomeip::service_t, std::map< vsomeip::event_t, uint8_t > >* _pMsgCacheIds, dk::gw::CMsgVmf* _pMsgVmf ) :
 rtm_(vsomeip::runtime::get())
,app_(rtm_->create_application("srvgw_vsomeip"))
,stop_(false)
,mxCache()
,mxStop()
,mthreadCache()
,mcvCacheNotify()
,pMsgIds(_pMsgIds)
,pMsgCacheIds(_pMsgCacheIds)
,subcriberQueue()
,msgIds()
,msgCache()
#ifndef SOMEIPGW_DLT_LOGGER_ENABLED
,PF_TRC_LOGGER_INIT(logger, "SRV_GATEWAY_SOMEIP", "SRVS")
#endif
,pMsgVmf(_pMsgVmf)
{
	for (auto id : *pMsgIds)
	{
		if(std::get<1>(id)<0x8000)
		{
			msgIds.insert(std::get<0>(id) * 256 + std::get<1>(id));
		}
	}
}

CVsomeipServiceGw::~CVsomeipServiceGw()
{

}

bool CVsomeipServiceGw::init()
{
    // init the application
    if (!app_->init())
    {
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
        LOGE(&gSrvgwsomeipLogContext,"SRVGW - Couldn't initialize application");
#else
    	PF_TRC_ERR(logger, "SRVGW - Couldn't initialize application");
#endif
        return false;
    }

    // register a state handler to get called back after registration at the
    // runtime was successful
    app_->register_state_handler(std::bind(&CVsomeipServiceGw::on_state_cbk, this, std::placeholders::_1));

    // Offer events
    std::set<vsomeip::eventgroup_t> its_groups;
    its_groups.insert(msg_eventgroup_id);

    for(auto id:*pMsgIds)
    {
    	vsomeip::service_t _service = std::get<0>(id);
    	vsomeip::event_t _event = std::get<1>(id);

        if(_event >= 0x8000)
		{
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
            LOGI(&gSrvgwsomeipLogContext,"SRVGW - Offer SOMEIP Srv:",_service, "Evt:",  _event);
#else
        	PF_TRC_INFO(logger,"SRVGW - Offer SOMEIP Srv: %d, Evt: %d", _service, _event);
#endif

	    	app_->offer_event(_service, msg_instance_id, _event, its_groups, false);
		}
    }

    for(auto id:*pMsgIds)
    {
    	vsomeip::service_t _service = std::get<0>(id);
    	vsomeip::event_t _event = std::get<1>(id);

        if(_event >= 0x8000)
		{
            app_->register_message_handler(_service , msg_instance_id, _event - 0x8000 ,
            std::bind(&CVsomeipServiceGw::onMsg, this, std::placeholders::_1));
		}
        else
		{
            app_->register_message_handler(_service, msg_instance_id, _event ,
            std::bind(&CVsomeipServiceGw::onMsg, this, std::placeholders::_1));
		}
    }

    return true;
}

void CVsomeipServiceGw::start()
{
    // start the application and wait for the on_event callback to be called
    // this method only returns when app_->stop() is called
	mthreadCache = std::thread(&CVsomeipServiceGw::subscriptionSyncHandler,this);

    app_->start();
}

void CVsomeipServiceGw::stop()
{
	{
		std::unique_lock<std::mutex> its_lock(mxStop);
	    stop_ = true;
	}
	mcvCacheNotify.notify_all();

    // stop offering the services
    vsomeip::service_t service_id = 0;
    vsomeip::event_t event_id = 0;
	std::map<vsomeip::service_t,vsomeip::instance_t> stoppedServices;

	for(auto id:*pMsgIds)
	{
		service_id = std::get<0>(id);
		event_id = std::get<1>(id);

		if(event_id >= 0x8000)
		{
			app_->stop_offer_event(service_id,msg_instance_id,event_id);
		}

		if(stoppedServices.find(service_id) == stoppedServices.end())
		{
			app_->stop_offer_service(service_id, msg_instance_id,0,0);
			stoppedServices.insert(std::pair<vsomeip::service_t,vsomeip::instance_t>(service_id,msg_instance_id));
		}
	}

    // clean message and state handlers
    app_->clear_all_handler();

    // shutdown the application
    app_->stop();

    // make sure worker thread is properly stopped
	if(mthreadCache.joinable())
	{
		mthreadCache.join();
	}
}

void CVsomeipServiceGw::on_state_cbk(vsomeip::state_type_e _state)
{
    if (_state == vsomeip::state_type_e::ST_REGISTERED)
    {
        // start offering the services
		vsomeip::service_t service_id = 0;
		std::map<vsomeip::service_t,vsomeip::instance_t> offeredServices;

        for(auto id:*pMsgIds)
        {
		    service_id = std::get<0>(id);
		    if(offeredServices.find(service_id) == offeredServices.end())
		    {
		        app_->offer_service(service_id, msg_instance_id);
		        offeredServices.insert(std::pair<vsomeip::service_t,vsomeip::instance_t>(service_id,msg_instance_id));
		    }
        }
    }
    else
    {
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
        LOGI(&gSrvgwsomeipLogContext,"SRVGW - unregistering");
#else
        PF_TRC_INFO(logger, "SRVGW - unregistering");
#endif
    }
}

bool CVsomeipServiceGw::syncCacheMessages(uint32_t counter)
{
	bool ret = true;
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
    LOGI(&gSrvgwsomeipLogContext,"SRVGW - syncCacheMessages");
#else
	PF_TRC_DBG(logger,"SRVGW - syncCacheMessages");
#endif

	{
		std::lock_guard<std::mutex> its_lock(mxStop);
		stop_ = false;
		subcriberQueue.push(counter);
	}

	mcvCacheNotify.notify_all();

	return ret;
}

void CVsomeipServiceGw::subscriptionSyncHandler()
{
	uint32_t counter;

	while(true)
	{
		{
		   std::unique_lock<std::mutex> lock(mxStop);
		   mcvCacheNotify.wait(lock,[this]{ return stop_ || !subcriberQueue.empty(); });

		   // break the loop
		   if(stop_)
		   {
			   break;
		   }

		   counter = subcriberQueue.front();
		   subcriberQueue.pop();
		}

		//std::this_thread::sleep_for(std::chrono::milliseconds(5000));
		sendCachedMsg(counter);
	}
}

void CVsomeipServiceGw::sendCachedMsg(uint32_t counter)
{
	(void)counter;

	if(nullptr == pMsgCacheIds)
	{
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
        LOGE(&gSrvgwsomeipLogContext,"SRVGW - pMsgCacheIds is empty. nothing to send");
#else
		PF_TRC_ERR(logger,"SRVGW - pMsgCacheIds is empty. nothing to send");
#endif
	}
	else
	{
		std::lock_guard<std::mutex> lock(mxCache);
		for(auto outer_itr = msgCache.begin(); outer_itr != msgCache.end(); outer_itr++ )
		{
			for(auto inner_itr = outer_itr->second.begin(); inner_itr != outer_itr->second.end(); inner_itr++ )
			{
				std::stringstream its_message;
				for (uint32_t i = 0; i < inner_itr->second->get_length(); ++i)
				{
					its_message << std::hex << std::setw(2) << std::setfill('0') << (int) inner_itr->second->get_data()[i] << " ";
				}
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
                LOGE(&gSrvgwsomeipLogContext,"TX SOMEIP to Sync - Srv:", outer_itr->first, "Evt:",inner_itr->first, "Len:",inner_itr->second->get_length(), "Payload: ",its_message.str().c_str());
#else
				PF_TRC_ERR(logger,"TX SOMEIP to Sync - Srv: %d, Evt: %d, Len: %d, Payload: %s", outer_itr->first, inner_itr->first, inner_itr->second->get_length(),its_message.str().c_str());
#endif
				auto it = pMsgCacheIds->find(outer_itr->first);
				if(it != pMsgCacheIds->end())
				{
					if(it->second.find(inner_itr->first) != it->second.end())
					{
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
                        LOGE(&gSrvgwsomeipLogContext,"TX SOMEIP to Sync - Srv:", outer_itr->first, "Evt:",inner_itr->first, "Len:",inner_itr->second->get_length(), "Payload: ",its_message.str().c_str());
#else
						PF_TRC_ERR(logger,"TX SOMEIP Sync - Srv: %d, Evt: %d, Len: %d, Payload: %s", outer_itr->first, inner_itr->first, inner_itr->second->get_length(),its_message.str().c_str());
#endif						
						sendMsg(outer_itr->first, inner_itr->first, inner_itr->second);
						std::this_thread::sleep_for(std::chrono::milliseconds(50));
					}
				}
			}
		}
	}

}

void CVsomeipServiceGw::sendMsg(vsomeip::service_t srvId, vsomeip::event_t eventId,const byte_t *pData, uint32_t sz)
{
	std::lock_guard<std::mutex> lock(mxCache);
	std::shared_ptr<vsomeip::payload> payload = vsomeip::runtime::get()->create_payload();
    payload->set_data(pData, sz);
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
    LOGI(&gSrvgwsomeipLogContext, "TX SOMEIP - Srv:",srvId, "Evt:",eventId, "Len:", payload->get_length());
#else
    PF_TRC_INFO(logger,"TX SOMEIP - Srv: %d, Evt: %d, Len: %d", srvId, eventId, payload->get_length());
#endif

    sendMsg(srvId, eventId, payload);
   	msgCache[srvId][eventId] = payload;
}

void CVsomeipServiceGw::sendMsg(vsomeip::service_t srvId, vsomeip::event_t eventId, std::shared_ptr<vsomeip::payload> payload)
{
    app_->notify(srvId, msg_instance_id, eventId, payload);
}

void CVsomeipServiceGw::onMsg(const std::shared_ptr<vsomeip::message> &_response)
{
    uint8_t gr = _response->get_service();
    uint8_t ev = _response->get_method();
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
    LOGI(&gSrvgwsomeipLogContext, "RX SOMEIP - Srv:",gr, "Evt:",ev, "Len:", _response->get_length());
#else
    PF_TRC_INFO(logger,"RX SOMEIP: Srv: %d, Mtd: %d, Len: %d", gr, ev, _response->get_length());
#endif

    if (msgIds.find(static_cast<uint16_t>(gr*256 + ev)) != msgIds.end())
    {
        std::shared_ptr<vsomeip::payload> its_payload = _response->get_payload();
        pMsgVmf->txMsg(its_payload->get_data(), its_payload->get_length(), _response->get_service(), _response->get_method());
    }
    else
    {
#ifdef SOMEIPGW_DLT_LOGGER_ENABLED
       LOGE(&gSrvgwsomeipLogContext, "SRVGW - SOMEIP Message not in the list: Srv:",gr, "Evt:",ev, "Len:", _response->get_length());
#else
       PF_TRC_ERR(logger,"SRVGW - SOMEIP Message not in the list: Srv: %d, MsgID: %d, Len: %d", gr, ev, _response->get_length());
#endif
    }
}


}   // namespace gw
}   // namespace dk
