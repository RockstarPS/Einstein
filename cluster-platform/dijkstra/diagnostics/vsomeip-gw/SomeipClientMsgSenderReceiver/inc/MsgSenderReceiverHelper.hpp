//=============================================================================
// Project       Visteon Infotainment HeadUnit
// (c) copyright 2019
// Company       Visteon
//               All rights reserved
// Secrecy Level STRICTLY CONFIDENTAL
//=============================================================================
// @file        MsgSenderReceiverHelper.hpp
// @ingroup     visteon_cdc
// @brief       implementation of MsgSenderReceiverHelper class.
// @author      Krishnaswamy Durai (kdurai@visteon.com)


#ifndef SOMEIP_MSG_SENDER_RECEIVER_MSG_SENDER_RECEIVER_HELPER
#define SOMEIP_MSG_SENDER_RECEIVER_MSG_SENDER_RECEIVER_HELPER

#include <stdint.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

namespace GAC
{
namespace Someip
{

static const std::string AppVersion = "v1.0.0";

/**
* \class MsgSenderReceiverHelper
* \brief MsgSenderReceiverHelper class provides helper functions
*/
class MsgSenderReceiverHelper
{
public:
	/**
	* \brief method return version of someip_msg_sender_receiver
	* \param none
	* \return string version
	*/
	static std::string getAppVersion();
	/**
	* \brief method check the file is exists in the given path or not
	* \param file path of the file
	* \return true if the file exists otherwise false
	*/
	static bool fileExists(const std::string& file);
    /**
	* \brief main method process command line arguments and perform necessary actions
	* \param argc number of arguments passed
	* \param argv is a pointer array which points to each argument passed to the program
	* \param fileOut return path of MessageDb file
	* \return error code
	*/
	static int32_t parseOptions(int argc, char **argv,std::string& fileOut);
    /**
	* \brief method prints the data adapter tool help information in console.
	* \param none
	* \return none
	*/
	static void showUsage();
    /**
	* \brief method prints the data adapter tool version in console.
	* \param none
	* \return none
	*/
	static void showVersion();
};

} // namespace Someip
} // namespace GAC
#endif  //SOMEIP_MSG_SENDER_RECEIVER_MSG_SENDER_RECEIVER_HELPER
