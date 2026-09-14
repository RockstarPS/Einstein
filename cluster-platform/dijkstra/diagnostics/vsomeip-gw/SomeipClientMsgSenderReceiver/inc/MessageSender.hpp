//=============================================================================
// Project       Visteon Infotainment HeadUnit
// (c) copyright 2019
// Company       Visteon
//               All rights reserved
// Secrecy Level STRICTLY CONFIDENTAL
//=============================================================================
// @file        MessageSender.hpp
// @ingroup     visteon_cdc
// @brief       implementation of MessageSender class.
// @author      Krishnaswamy Durai (kdurai@visteon.com)


#ifndef SOMEIP_MSG_SENDER_RECEIVER_MESSAGE_SENDER
#define SOMEIP_MSG_SENDER_RECEIVER_MESSAGE_SENDER

#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include "IMessageBroker.hpp"
#include "MessageDbParser.hpp"

namespace GAC
{
namespace Someip
{

/**
* \class MessageSender
* \brief MessageSender class implements SomeIP client feature to send SomeIP message to InterDomain service based on message catalog
*/
class MessageSender
{
private:
	/**
	* \brief constructor
	* \param none
	* \return none
	*/
	MessageSender();
	/**
	* \brief copy constructor
	* \param MessageSender object
	* \return MessageSender
	*/
	MessageSender(const MessageSender&);
	/**
	* \brief assignment operator
	* \param MessageSender object
	* \return MessageSender
	*/
	MessageSender& operator = (const MessageSender&);
public:
    /**
    * \brief constructor
    * \param broker object implements SomeIP client features
    * \param file path of the MessageDb file
    * \return none
    */
	MessageSender(IMessageBroker& _broker,const std::string& file);
   /**
	* \brief destructor
	* \param none
	* \return none
	*/
	virtual ~MessageSender();
    /**
	* \brief starts the Sender thread communication
	* \param none
	* \return none
	*/
    void start();
    /**
   	* \brief stops the Sender thread communication
   	* \param none
   	* \return none
   	*/
    void stop();
    /**
     * \brief method return state of the Sender thread
     * \param none
     * \result true if running otherwise false
     */
    bool isRunning();
    /**
	* \brief periodic thread send messages to remote SomeIP service
	* \param none
	* \return none
	*/
    void periodicTask();
    /**
	* \brief method log messages send to remote SomeIP service
	* \param msg SomeIP message
	* \return none
	*/
	void logMessage(const Message& msg);
private:
    // periodic task object
    std::thread thread_;

    // mutex to guard the task
    std::mutex taskMutex_;

    // condition variable for Worker thread to wait at stop event
    std::condition_variable condition_;

    // broker object implementation SomeIP client features
    IMessageBroker& broker_;

    // parser to parse the SomeIP messages from the MessageDb file
    MessageDbParser dbParser_;

    // flag to notify periodic task to stop.
    bool stop_;
};

} // namespace Someip
} // namespace GAC
#endif  //SOMEIP_MSG_SENDER_RECEIVER_MESSAGE_SENDER
