//=============================================================================
// Project       Visteon Infotainment HeadUnit
// (c) copyright 2019
// Company       Visteon
//               All rights reserved
// Secrecy Level STRICTLY CONFIDENTAL
//=============================================================================
// @file        uclstub_msg_sender.cpp
// @ingroup     visteon_cdc
// @brief       implementation of MessageSender class.
// @author      Krishnaswamy Durai (kdurai@visteon.com)


#include "uclstub_msg_sender.hpp"

namespace uclstub
{
namespace ipc
{
MessageSender::MessageSender(dk::runtime2::core::CMsgVmf& _broker,const std::string& file)
:thread_()
,broker_(_broker)
,dbParser_(file)
,stop_(false)
{

}

MessageSender::~MessageSender()
{
	stop();
}

void MessageSender::start()
{
	if(!isRunning())
	{
		thread_ = std::thread(&MessageSender::periodicTask,this);
	}
}

bool MessageSender::isRunning()
{
    return thread_.joinable();
}

void MessageSender::periodicTask()
{
	Message msg;
	size_t msgCounter = 0;
	std::vector<Message> messages;

	std::cout << "UCLSTUB : " << " ----> sender thread started" << std::endl;

	dbParser_.parse(messages);

	std::this_thread::sleep_for(std::chrono::seconds(5));

	while(true)
	{
		{
		   std::unique_lock<std::mutex> lock(taskMutex_);

		   condition_.wait(lock,[this,messages]{ return stop_ || !messages.empty(); });

		   if(stop_)
		   {
			   break;
		   }
		}

		if(msgCounter < messages.size())
		{
			msg = messages[msgCounter];
			sendMessage(msg);
			msgCounter++;
		}

		if(msgCounter >= messages.size())
		{
			msgCounter = 0;
		}

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void MessageSender::stop()
{
	{
		std::unique_lock<std::mutex> lock(taskMutex_);
		stop_ = true;
	}

	condition_.notify_one();

	if(isRunning())
	{
		thread_.join();
	}
}

void MessageSender::sendMessage(const Message& msg)
{
	std::shared_ptr<dk::runtime2::core::MsgSerializer> serializer =
			std::make_shared < dk::runtime2::core::MsgSerializer > ((msg.service * 256 + (msg.method - 0x8000)), 1, 0 /* TODO: Counter should be updated*/);
	serializer->serialize(msg.payloadData);

	broker_.txMsg(serializer);
	logMessage(msg);
}

void MessageSender::logMessage(const Message& msg)
{
	std::stringstream its_header;
	std::stringstream its_message;

	its_header << "sent a msg for event msg header["
			<< std::setw(4) << std::setfill('0') << msg.service << "."
			<< std::setw(4) << std::setfill('0') << 1 << "."
			<< std::setw(4) << std::setfill('0') << msg.method << "{vmf_msg_id:" << msg.method - 0x8000 << "}" <<  "]";


	its_message << "msg payload (" << std::dec << (uint32_t)msg.payloadData.size() << ") [";
	for (uint32_t i = 0; i < (uint32_t)msg.payloadData.size(); ++i)
	{
		its_message << std::hex << std::setw(2) << std::setfill('0') << (int) msg.payloadData[i] << " ";
	}
	its_message << "]";

	std::cout << "UCLSTUB : " << its_header.str() << its_message.str() << std::endl;
}

} // namespace ipc
} // namespace uclstub
