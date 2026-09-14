//=============================================================================
// Project       Visteon Infotainment HeadUnit
// (c) copyright 2019
// Company       Visteon
//               All rights reserved
// Secrecy Level STRICTLY CONFIDENTAL
//=============================================================================
// @file        uclstub_msg_sender.hpp
// @ingroup     visteon_cdc
// @brief       implementation of MessageSender class.
// @author      Krishnaswamy Durai (kdurai@visteon.com)


#ifndef VMF_MSG_SENDER_RECEIVER_MESSAGE_SENDER
#define VMF_MSG_SENDER_RECEIVER_MESSAGE_SENDER

#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <dk_runtime2_cmsg.hpp>
#include <dk_runtime2_cmsgvmf.hpp>
#include "uclstub_msgdb_parser.hpp"

namespace uclstub
{
namespace ipc
{

/**
* \class MessageSender
* \brief MessageSender class implements UCL stub feature to send VMF message to InterDomain SomeIp Gateway service based on message catalog
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
    * \param broker object implements VMF client features
    * \param file path of the MessageDb file
    * \return none
    */
	MessageSender(dk::runtime2::core::CMsgVmf& _broker,const std::string& file);
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
	* \brief periodic thread send messages to remote VMF service
	* \param none
	* \return none
	*/
    void periodicTask();
    /**
	* \brief method send messages to remote VMF service
	* \param msg VMF message to be send
	* \return none
	*/
    void sendMessage(const Message& msg);
    /**
	* \brief method log messages send to remote VMF service
	* \param msg VMF message
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

    // broker object implementation VMF client features
    dk::runtime2::core::CMsgVmf& broker_;

    // parser to parse the VMF messages from the MessageDb file
    uclstub::ipc::MessageDbParser dbParser_;

    // flag to notify periodic task to stop.
    bool stop_;
};

} // namespace ipc
} // namespace uclstub
#endif  //VMF_MSG_SENDER_RECEIVER_MESSAGE_SENDER
