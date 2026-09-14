//=============================================================================
// Project       Visteon Infotainment HeadUnit
// (c) copyright 2019
// Company       Visteon
//               All rights reserved
// Secrecy Level STRICTLY CONFIDENTAL
//=============================================================================
// @file        MessageBroker.hpp
// @ingroup     visteon_cdc
// @brief       implementation of MessageBroker class.
// @author      Krishnaswamy Durai (kdurai@visteon.com)


#ifndef SOMEIP_MSG_SENDER_RECEIVER_MESSAGE_RECEIVER
#define SOMEIP_MSG_SENDER_RECEIVER_MESSAGE_RECEIVER

#include <mutex>
#include <condition_variable>
#include "IMessageBroker.hpp"
#include "msg_ids.hpp"

namespace GAC
{
namespace Someip
{
/**
* \class MessageBroker
* \brief MessageBroker class implements SomeIP client feature listens to SomeIP notification from InterDomain service based on message catalog
*/
class MessageBroker : public IMessageBroker
{
private:
    /**
    * \brief constructor
    * \param none
    * \return none
    */
	MessageBroker();
    /**
    * \brief copy constructor
    * \param MessageBroker object
    * \return MessageBroker
    */
	MessageBroker(const MessageBroker&);
    /**
    * \brief assignment operator
    * \param MessageBroker object
    * \return MessageBroker
    */
	MessageBroker& operator = (const MessageBroker&);
public:
   /**
	* \brief constructor
	* \param _pMsgIds list contains service id and method for which notifications to be subscribed
	* \param _reliable flag to determine the usage of TCP / UDP segment for communication
	* \return none
	*/
	MessageBroker(std::vector<std::pair<vsomeip::service_t, vsomeip::method_t >>* _pMsgIds, bool _reliable);
   /**
	* \brief destructor
	* \param none
	* \return none
	*/
	virtual ~MessageBroker();
   /**
	* \brief initialize the SomeIP communication
	* \param none
	* \return true on successful otherwise false
	*/
    bool init();
    /**
	* \brief starts the SomeIP communication
	* \param none
	* \return none
	*/
    void start();
    /**
   	* \brief stops the SomeIP communication
   	* \param none
   	* \return none
   	*/
    void stop();
    /**
	* \brief callback will be invoked on successful registration of this application with SomeIP RT
	* \param _state current state
	* \return none
	*/
    void onStateCbk(vsomeip::state_type_e _state);
    /**
	* \brief callback will be invoked on availability of remote SomeIP service
	* \param _service service id of the remote service
	* \param _instance instance id of the remote service
	* \param _is_available availability state of the remote service
	* \return none
	*/
    void onAvailabilityCbk(vsomeip::service_t _service, vsomeip::instance_t _instance, bool _is_available);
    /**
	* \brief callback will be invoked on receiving SomeIP message from any service
	* \param _response object contains SomeIP message header and data
	* \return none
	*/
    void onAnyEvent(const std::shared_ptr<vsomeip::message> &_response);
    /**
	* \brief utility function to log the SomeIP message to console / DLT
	* \param _response object contains SomeIP message header and data
	* \return none
	*/
    void logMessage(const std::shared_ptr<vsomeip::message> &_response);
    /**
	* \brief wait function to wait at condition_variable for the availability of SomeIP service
	* \param none
	* \return none
	*/
    void waitForAvailability();
    /**
	* \brief utility method return true if the current state of application is registered otherwise false
	* \param none
	* \return true if the current state of application is registered otherwise false
	*/
    bool isStateRegistered();
    /**
   	* \brief utility method sends the SomeIP messages to remote service
   	* \param _service service id of the remote service
   	* \param _instance instance id of the remote service
   	* \param _method method id of the remote service
   	* \param _payload SomeIP message header and data
   	* \return true if the current state of application is registered otherwise false
   	*/
    void sendMessage(vsomeip::service_t _service, vsomeip::instance_t _instance, vsomeip::method_t _method, std::vector<vsomeip::byte_t>& _payload);
private:
    // SomeIP runtime
    std::shared_ptr<vsomeip::runtime> rtm_;

    // SomeIP application
    std::shared_ptr<vsomeip::application> app_;

    // SomeIP application current state
    vsomeip::state_type_e state_;

    // mutex for synchronization
    std::mutex mutex_;

    // conditional for synchronization
    std::condition_variable condition_;

    // list contains service id and method for which notifications to be subscribed
    std::vector<std::pair<vsomeip::service_t, vsomeip::method_t >>* pMsgIds;

    // Flag to determine the usage of TCP / UDP segment for communication
    bool reliable;
};

} // namespace Someip
} // namespace GAC
#endif  //SOMEIP_MSG_SENDER_RECEIVER_MESSAGE_RECEIVER
