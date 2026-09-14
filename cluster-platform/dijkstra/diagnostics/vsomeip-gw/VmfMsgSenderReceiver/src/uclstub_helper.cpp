//=============================================================================
// Project       Visteon Infotainment HeadUnit
// (c) copyright 2019
// Company       Visteon
//               All rights reserved
// Secrecy Level STRICTLY CONFIDENTAL
//=============================================================================
// @file        uclstub_helper.cpp
// @ingroup     visteon_cdc
// @brief       implementation of MsgSenderReceiverHelper class.
// @author      Krishnaswamy Durai (kdurai@visteon.com)

#include "uclstub_helper.hpp"

namespace uclstub
{
namespace ipc
{
std::string MsgSenderReceiverHelper::getAppVersion()
{
	return AppVersion;
}

bool MsgSenderReceiverHelper::fileExists(const std::string& file)
{
	bool ret = false;

    // Check if file exists
    struct stat st;
    if ((stat(file.c_str(), &st) == 0) && ((S_ISREG(st.st_mode)) || (S_ISLNK(st.st_mode))))
    {
        ret = true;
    }
    return ret;
}

int32_t MsgSenderReceiverHelper::parseOptions(int argc, char **argv,std::string& fileOut)
{
	int32_t opt = 0;
	int32_t ret = EXIT_SUCCESS;

	std::string msgDbFile;
	bool isGotoEndMain = false;

    if (argc < 2)
    {
        ret = EXIT_FAILURE;
        goto endMain;
    }

    // parse the command line arguments
    while(-1 != (opt = getopt(argc, (char* const*) argv, "i:o:hv")))
    {
    	isGotoEndMain = false;

        switch (opt)
        {
            case '?':
                // Return when there is missing option
                fprintf(stderr,"\nError: Missing option. Exiting here..\n\n");
                ret = EXIT_FAILURE;
                isGotoEndMain = true;
                break;
            case 'i':
            	msgDbFile = optarg;
            	if(!MsgSenderReceiverHelper::fileExists(msgDbFile))
				{
					fprintf(stderr,"\nError: The input file %s doesn't exist\n\n",msgDbFile.c_str());
            		ret = EXIT_FAILURE;
            		isGotoEndMain = true;
				}
                break;
            case 'h':
                showUsage();
        		ret = EXIT_SUCCESS;
        		isGotoEndMain = true;
        		break;
            case 'v':
            	showVersion();
        		ret = EXIT_SUCCESS;
        		isGotoEndMain = true;
        		break;
            default:
                showUsage();
        		ret = EXIT_SUCCESS;
        		isGotoEndMain = true;
                break;
        }

        if(isGotoEndMain)
		{
			break;
		}
    }

    if(isGotoEndMain)
    {
    	goto endMain;
    }


    if(msgDbFile.empty()) // make sure MessageDb file path is provided
	{
    	fprintf(stderr,"\nError: MessageDb file path not provided. Refer --input-messagedb option for more info..\n\n");
		ret = EXIT_FAILURE;
		goto endMain;
	}

  	fileOut = msgDbFile;

endMain:
	if(ret == EXIT_FAILURE)
	{
		showUsage();
	}

	return ret;
}

void MsgSenderReceiverHelper::showUsage()
{
    fprintf(stderr,"vmf_msg_sender_receiver. Options:\n");
    fprintf(stderr,"\nMiscellaneous:\n");
    fprintf(stderr,"\t-h,--help\t\t\tShow this help message\n");
    fprintf(stderr,"\t-v,--version\t\t\tShow version information\n");
    fprintf(stderr,"\nInput:\n");
    fprintf(stderr,"\t-i,--input-messagedb <file>\tUse `file` as the path of the MessageDb file. (Mandatory parameter)\n");
}

void MsgSenderReceiverHelper::showVersion()
{
	std::string version = MsgSenderReceiverHelper::getAppVersion();
    fprintf(stdout,"vmf_msg_sender_receiver\n");
    fprintf(stdout,"Version: \t %s\n",version.c_str());
    fprintf(stdout,"Catalogue Version: \t %s\n",msg_catalogue_version.c_str());
}

} // namespace ipc
} // namespace uclstub

