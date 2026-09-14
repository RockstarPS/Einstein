
#include "msg_ids.hpp"
#include "msg_version.hpp"
#include "MessageBroker.hpp"
#include "MessageSender.hpp"
#include "MsgSenderReceiverHelper.hpp"

using namespace GAC::Someip;

MessageBroker *msgBrokerPtr(nullptr);
MessageSender *msgSenderPtr(nullptr);

void handle_signal(int _signal)
{
    if (_signal == SIGINT || _signal == SIGTERM)
    {
    	if(msgBrokerPtr != nullptr)
    	{
    		msgBrokerPtr->stop();
    	}

    	if(msgSenderPtr != nullptr)
		{
    		msgSenderPtr->stop();
		}
    }
}

int main(int argc, char **argv)
{
	int ret = 1;
	std::string dbFile;
	std::string appVersion;

	std::cout << "CLI : cli_someip_msg_sender_receiver "
			<< "Version: "<< MsgSenderReceiverHelper::getAppVersion()
				<< " Catalogue Version: " << msg_catalogue_version << std::endl;

	int32_t parseOk = MsgSenderReceiverHelper::parseOptions(argc,argv,dbFile);
	if((EXIT_SUCCESS == parseOk) && (false == dbFile.empty()))
	{
		MessageBroker msgBroker(&MsgIds, true);
		MessageSender msgSender(msgBroker,dbFile);

		msgBrokerPtr = &msgBroker;
		msgSenderPtr = &msgSender;

		signal(SIGINT, handle_signal);
		signal(SIGTERM, handle_signal);

		if (msgBroker.init())
		{
			msgSender.start();
			msgBroker.start();
			ret = 0;
		}
	}

    return ret;
}

