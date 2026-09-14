/**
 * VISTEON CORPORATION CONFIDENTIAL
 * ________________________________
 *
 * [2017] Visteon Corporation
 * All Rights Reserved.
 *
 * NOTICE: This is an unpublished work of authorship, which contains trade secrets.
 * Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
 * its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
 * or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
 * in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
 * under all copyright laws to protect this work as a published work, when appropriate.
 * Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
 * without the written authorization of Visteon Corporation.
 */

#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <chrono>
#include <thread>
#include "msg_ids.hpp"
#include "msg_maps.hpp"
#include "uclstub_helper.hpp"
#include "uclstub_msg_sender.hpp"

int main(int argc, char **argv)
{
	int ret = 1;
	bool run = true;
	std::string dbFile;

	std::cout << "UCLSTUB : vmf_msg_sender_receiver "
	    		<< "Version: "<< uclstub::ipc::MsgSenderReceiverHelper::getAppVersion()
	    		<< " Catalogue Version: " << msg_catalogue_version << std::endl;

	int32_t parseOk = uclstub::ipc::MsgSenderReceiverHelper::parseOptions(argc,argv,dbFile);
	if((EXIT_SUCCESS == parseOk) && (false == dbFile.empty()))
	{
		dk::runtime2::core::CMsgVmf broker(&VmfMsgMap, "uclstub process", 3000);
		uclstub::ipc::MessageSender sender(broker,dbFile);

		broker.start();
		sender.start();

		while (run)
		{
			std::string s;
			std::cin >> s;

			if(s=="r")
			{
				broker.start();
				sender.start();
				std::cout << "UCLSTUB : start vmf \n";
			}
			else if(s=="s")
			{
				broker.stop();
				sender.stop();
				std::cout << "UCLSTUB : stop vmf \n";
			}
			else if(s=="q")
			{
				broker.stop();
				sender.stop();
				run = false;
			}
			else
			{
				std::cout << "UCLSTUB : key pressed = " << s << std::endl;
			}

			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}

    std::cout << "UCLSTUB : exit !\n";

    return ret;
}
