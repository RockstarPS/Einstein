//=============================================================================
// Project       Visteon Infotainment HeadUnit
// (c) copyright 2019
// Company       Visteon
//               All rights reserved
// Secrecy Level STRICTLY CONFIDENTAL
//=============================================================================
// @file        MessageDbParser.hpp
// @ingroup     visteon_cdc
// @brief       implementation of MessageDbParser class.
// @author      Krishnaswamy Durai (kdurai@visteon.com)


#ifndef SOMEIP_MSG_SENDER_RECEIVER_MESSAGEDB_PARSER
#define SOMEIP_MSG_SENDER_RECEIVER_MESSAGEDB_PARSER

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace GAC
{
namespace Someip
{

/**
* \class Message
* \brief Message structure stores the parsed message from MessageDb file.
*/
typedef struct
{
	uint32_t service;
	uint32_t instance;
	uint32_t method;
	uint32_t payloadSize;
	std::vector<uint8_t> payloadData;
} Message;

/**
* \class MessageDbParser
* \brief MessageDbParser class implements parse to parse the SomeIP messages from the MessageDb file
*/
class MessageDbParser
{
private:
	/**
	* \brief constructor
	* \param none
	* \return none
	*/
	MessageDbParser();
	/**
	* \brief copy constructor
	* \param MessageDbParser object
	* \return MessageDbParser
	*/
	MessageDbParser(const MessageDbParser&);
	/**
	* \brief assignment operator
	* \param MessageDbParser object
	* \return MessageDbParser
	*/
	MessageDbParser& operator = (const MessageDbParser&);
public:
	/**
	* \brief constructor
	* \param none
	* \return none
	*/
	MessageDbParser(const std::string& file);
   /**
	* \brief destructor
	* \param none
	* \return none
	*/
	virtual ~MessageDbParser();
    /**
	* \brief parses the SomeIP messages from MesssgeDb file
	* \param messages out parameter return SomeIP messages
	* \return true if successful otherwise false.
	*/
    bool parse(std::vector<Message>& messages);
    /**
	* \brief getter method returns the parsed SomeIP messages
	* \param messages out parameter return SomeIP messages
	* \return none
	*/
    void getMessages(std::vector<Message>& messages);
    /**
	* \brief clear the message list
	* \param none
	* \return none
	*/
    void reset();
private:
    /**
	* \brief internal function to parse Messages from MessageDb file
	* \param line current line
	* \return true if parsing of message success otherwise false
	*/
    bool parseMessages(const std::string& line);
private:
    // list contains parsed SomeIp messages
    std::vector<Message> messages_;

    // path of MessageDb file
    std::string dbFile_;
};

} // namespace Someip
} // namespace GAC
#endif  //SOMEIP_MSG_SENDER_RECEIVER_MESSAGEDB_PARSER
