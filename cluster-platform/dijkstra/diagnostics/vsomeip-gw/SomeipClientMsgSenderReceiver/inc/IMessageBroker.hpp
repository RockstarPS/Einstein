//=============================================================================
// Project       Visteon Infotainment HeadUnit
// (c) copyright 2019
// Company       Visteon
//               All rights reserved
// Secrecy Level STRICTLY CONFIDENTAL
//=============================================================================
// @file        IMessageBroker.hpp
// @ingroup     visteon_cdc
// @brief       implementation of IMessageBroker class.
// @author      Krishnaswamy Durai (kdurai@visteon.com)


#ifndef SOMEIP_MSG_SENDER_RECEIVER_IMESSAGE_BROKER
#define SOMEIP_MSG_SENDER_RECEIVER_IMESSAGE_BROKER

#include <iostream>
#include <sstream>
#include <iomanip>
#include <unistd.h>
#include <stdint.h>
#include <vector>
#include <vsomeip/vsomeip.hpp>

namespace GAC
{
namespace Someip
{
/**
* \class IMessageBroker
* \brief IMessageBroker abstract base class for the class implements the SomeIP client features.
*/
class IMessageBroker
{
public:
    /**
    * \brief constructor
    * \param none
    * \return none
    */
	IMessageBroker() { }
	/**
	* \brief destructor
	* \param none
	* \return none
	*/
    virtual ~IMessageBroker() { }
public:
    /**
	* \brief wait function to wait at condition_variable for the availability of SomeIP service
	* \param none
	* \return none
	*/
    virtual void waitForAvailability() = 0;
   /**
	* \brief utility method sends the SomeIP messages to remote service
	* \param _service service id of the remote service
	* \param _instance instance id of the remote service
	* \param _method method id of the remote service
	* \param _payload SomeIP message header and data
	* \return true if the current state of application is registered otherwise false
	*/
    virtual void sendMessage(vsomeip::service_t _service, vsomeip::instance_t _instance, vsomeip::method_t _method, std::vector<vsomeip::byte_t>& _payload) = 0;
};

} // namespace Someip
} // namespace GAC

#endif  //SOMEIP_MSG_SENDER_RECEIVER_IMESSAGE_BROKER
