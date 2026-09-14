///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2017] Visteon Corporation
/// All Rights Reserved.
///
/// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
/// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
/// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
/// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
/// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
/// under all copyright laws to protect this work as a published work, when appropriate.
/// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
/// without the written authorization of Visteon Corporation.
///
///---------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <chrono>
#include <csignal>
#include "UclSys.h"
#include <thread>

static bool bRequestExit;

extern Ucl_ReturnType UclGen_CapiServerInit();
extern void UclGen_CapiServerShutdown();

void exit_handler(int s)
{
	std::cout << "Ucl CommonAPI Proxy Exiting.." << std::endl;
	bRequestExit = true;
}

int main()
{
	Ucl_ReturnType Ret;

	// CAPI Init
	UclGen_CapiServerInit();

	// Initialize the UCL System
	Ret = UclSys_Initialize(0);

	if (UCL_E_OK == Ret)
	{
		bRequestExit = false;

		std::signal(SIGINT, exit_handler);

		while (!bRequestExit)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}

		Ret = UclSys_Shutdown(0);

		(void)UclGen_CapiServerShutdown();

		std::cout << "Ucl CommonAPI Proxy Exiting..........." << std::endl;

		std::this_thread::sleep_for(std::chrono::seconds(1u));
	}
	else
	{
		std::cout << "Ucl CommonAPI Proxy Start Failed" << std::endl;
	}

	return 0;
}
