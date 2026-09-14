//=============================================================================
// Project       Visteon Infotainment HeadUnit
// (c) copyright 2019
// Company       Visteon
//               All rights reserved
// Secrecy Level STRICTLY CONFIDENTAL
//=============================================================================
// @file        MessageDbParser.cpp
// @ingroup     visteon_cdc
// @brief       implementation of MessageDbParser class.
// @author      Krishnaswamy Durai (kdurai@visteon.com)

#include "MessageDbParser.hpp"

namespace GAC
{
namespace Someip
{
MessageDbParser::MessageDbParser(const std::string& file)
:messages_()
,dbFile_(file)
{

}

MessageDbParser::~MessageDbParser()
{
	reset();
}

bool MessageDbParser::parse(std::vector<Message>& messages)
{
	bool ret = true;
	std::ifstream file(dbFile_);
	if (!file.is_open())
	{
		ret = false;
		std::cout << "CLI : Failed to open MessageDb file:"  << dbFile_ << std::endl;
	}
	else
	{

		std::string line;
		while (getline(file, line))
		{
			//std::cout << line << std::endl;
			parseMessages(line);
		}
		file.close();
	}

	getMessages(messages);

	return ret;
}

bool MessageDbParser::parseMessages(const std::string& line)
{
	int tmp = 0;
	bool ret = false;
	uint8_t data = 0;
	uint32_t count = 0;
	std::string byteString = "";
	std::vector<std::string> tokens;

	Message msg;

	for (auto token : line)
	{
		if(token == ' ')
		{
		   tokens.push_back(byteString);
		   byteString = "";
		}
		else
		{
			byteString += token;
		}
	}

	if(byteString.length() > 0)
	{
		tokens.push_back(byteString);
	}

	for (auto token  : tokens)
	{
		msg.instance = 0x01;
		//std::cout << "CLI : token"  << "=" << token << std::endl;
		std::istringstream stream(token);

		switch(count)
		{
			case 0: // parse service id
				//stream >> serviceId;
				msg.service = std::strtol(token.c_str(), NULL, 16);
				break;
			case 1: // parse method id
				msg.method = std::strtol(token.c_str(), NULL, 16);
				break;
			case 2: // parse payload size
				msg.payloadSize = std::strtol(token.c_str(), NULL, 16);
				break;
			default: // parse payload data
				stream >> std::hex >> tmp;
				data = (uint8_t)tmp;
				msg.payloadData.push_back(data);
				break;

		}
		count++;
	}

	if(msg.payloadData.size() != (size_t)msg.payloadSize)
	{
		ret = false;
		std::cout << "CLI : payload size and payload data are not matching:" << " payloadSize: " << msg.payloadSize << " payloadData: " << msg.payloadData.size() << std::endl;
	}
	else
	{
		ret = true;

		messages_.push_back(msg);
		/*
		std::cout << "CLI : service:" << msg.service << std::endl;
		std::cout << "CLI : method:" << msg.method << std::endl;
		std::cout << "CLI : payloadSize:" << msg.payloadSize << std::endl;
		std::cout << "CLI : payloadData:" << std::endl;
		for (size_t i = 0; i < msg.payloadData.size(); i++)
		{
			std::cout << i << "=" << unsigned(msg.payloadData[i]) << std::endl;
		}
		*/
	}

	return ret;
}
void MessageDbParser::getMessages(std::vector<Message>& messages)
{
	messages.clear();
	for(size_t i=0;i<messages_.size();i++)
	{
		messages.push_back(messages_[i]);
	}
}

void MessageDbParser::reset()
{
	messages_.clear();
}
} // namespace Someip
} // namespace GAC
