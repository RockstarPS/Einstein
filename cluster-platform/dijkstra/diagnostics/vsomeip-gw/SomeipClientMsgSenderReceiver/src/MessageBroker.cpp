//=============================================================================
// Project       Visteon Infotainment HeadUnit
// (c) copyright 2019
// Company       Visteon
//               All rights reserved
// Secrecy Level STRICTLY CONFIDENTAL
//=============================================================================
// @file        MessageBroker.cpp
// @ingroup     visteon_cdc
// @brief       implementation of MessageBroker class.
// @author      Krishnaswamy Durai (kdurai@visteon.com)


#include "MessageBroker.hpp"

namespace GAC
{
namespace Someip
{
MessageBroker::MessageBroker(std::vector<std::pair<vsomeip::service_t, vsomeip::method_t >>* _pMsgIds, bool _reliable)
:rtm_(vsomeip::runtime::get())
,app_(rtm_->create_application("cli_someip_msg_sender_receiver"))
,state_(vsomeip::state_type_e::ST_DEREGISTERED)
,pMsgIds(_pMsgIds)
,reliable(_reliable)
{

}

MessageBroker::~MessageBroker()
{

}

bool MessageBroker::init()
{
	bool ret = true;

    // initialize the application
    if (!app_->init())
    {
        std::cout << "CLI : Couldn't initialize application" << std::endl;
    }
    else
    {
    	// register for notification on successful registration with Runtime
		app_->register_state_handler(std::bind(&MessageBroker::onStateCbk, this, std::placeholders::_1));

		// register for incoming notification from remote service
		app_->register_message_handler(vsomeip::ANY_SERVICE, 1, vsomeip::ANY_METHOD,
		std::bind(&MessageBroker::onAnyEvent, this, std::placeholders::_1));

		// register for availability status of remote service
		for(auto id:*pMsgIds)
		{
			app_->register_availability_handler(std::get<0>(id), 1,
			std::bind(&MessageBroker::onAvailabilityCbk, this, std::placeholders::_1, std::placeholders::_2,std::placeholders::_3));
		}

		// prepare event group for subscribing events from remote service
		std::set<vsomeip::eventgroup_t> its_groups;
		its_groups.insert(msg_eventgroup_id);

		// subscribe for events from remote service
		for(auto id:*pMsgIds)
		{
			if(std::get<1>(id) > 0x8000)
			{
				app_->request_event(std::get<0>(id), 1, std::get<1>(id), its_groups, false);
				app_->subscribe(std::get<0>(id), msg_instance_id, msg_eventgroup_id);
			}
		}
    }

    return ret;
}

void MessageBroker::start()
{
	/*
	 * start the application and wait for the on_event callback to be called
	 * this method only returns when app_->stop() is called. The application
	 * will goes to background (daemon).
	 */
    std::cout << "CLI : " << "app-> start()" << std::endl;
    app_->start();
}

void MessageBroker::onStateCbk(vsomeip::state_type_e _state)
{
    std::cout << "CLI : " << " on state cbk" << std::endl;
    if (_state == vsomeip::state_type_e::ST_REGISTERED)
    {
		/*
		* we are registered at the runtime now we can request the service
		* and wait for the on_availability callback to be called
		*/
        for(auto id:*pMsgIds)
        {
           app_->request_service(std::get<0>(id), msg_instance_id,0,0);
        }

        state_ = vsomeip::state_type_e::ST_REGISTERED;
    }
    else
    {
        std::cout << "CLI : " << " service deregistered" << std::endl;
    }
}

void MessageBroker::onAvailabilityCbk(vsomeip::service_t _service, vsomeip::instance_t _instance, bool _is_available)
{
    std::cout << "CLI : " << _service << " | instance: " << _instance << " | available: " << _is_available << std::endl;
    condition_.notify_one();
}

void MessageBroker::onAnyEvent(const std::shared_ptr<vsomeip::message> &_response)
{
    logMessage(_response);
}

void MessageBroker::logMessage(const std::shared_ptr<vsomeip::message> &_response)
{
    std::stringstream its_header;
    std::stringstream its_message;

    std::shared_ptr<vsomeip::payload> its_payload = _response->get_payload();

    its_header << "received a msg for event msg header["
    		<< std::setw(4) << std::setfill('0') << _response->get_service() << "."
            << std::setw(4) << std::setfill('0') << _response->get_instance() << "."
			<< std::setw(4) << std::setfill('0') << _response->get_method() << "{vmf_msg_id:" << _response->get_method() - 0x8000 << "}" <<  "]";


    its_message << "msg payload (" << std::dec << its_payload->get_length() << ") [";
    for (uint32_t i = 0; i < its_payload->get_length(); ++i)
	{
		its_message << std::hex << std::setw(2) << std::setfill('0') << (int) its_payload->get_data()[i] << " ";
	}
	its_message << "]";

    std::cout << "CLI : " << its_header.str() << its_message.str() << std::endl;
}

void MessageBroker::stop()
{
    // unregister the state handler
    app_->unregister_state_handler();

    // unregister the message handler
    app_->unregister_message_handler(vsomeip::ANY_SERVICE, msg_instance_id, vsomeip::ANY_METHOD);

    // alternatively unregister all registered handlers at once
    app_->clear_all_handler();

    if (state_ == vsomeip::state_type_e::ST_REGISTERED)
    {
        /*
         * We have requested the service after registering with runtime. we have to
         * release the service request (de-registration)
         */
        for(auto id:*pMsgIds)
        {
           app_->release_service(std::get<0>(id), msg_instance_id);
        }

        state_ = vsomeip::state_type_e::ST_DEREGISTERED;
    }

    /*
	* Release events and un-subscribe events
	*/
    for(auto id:*pMsgIds)
    {
        if(std::get<1>(id) > 0x8000)
        {
            app_->release_event(std::get<0>(id), msg_instance_id, std::get<1>(id));
            app_->unsubscribe(std::get<0>(id), msg_instance_id, msg_eventgroup_id);
        }
    }

    // shutdown the application
    app_->stop();
}

void MessageBroker::waitForAvailability()
{
	std::unique_lock<std::mutex> its_lock(mutex_);
	condition_.wait(its_lock);
}

bool MessageBroker::isStateRegistered()
{
	return state_ == vsomeip::state_type_e::ST_REGISTERED;
}

void MessageBroker::sendMessage(vsomeip::service_t _service, vsomeip::instance_t _instance, vsomeip::method_t _method,std::vector<vsomeip::byte_t>& _payload)
{
    std::shared_ptr<vsomeip::message> request = rtm_->create_request(reliable);

    request->set_service(_service);
    request->set_instance(_instance);
    request->set_method(_method);
    request->set_message_type(vsomeip::message_type_e::MT_REQUEST_NO_RETURN);

    std::shared_ptr<vsomeip::payload> payload = rtm_->create_payload();

    payload->set_data(_payload);
    request->set_payload(payload);

    app_->send(request, true);
}
} // namspace Someip
} // namespace GAC
