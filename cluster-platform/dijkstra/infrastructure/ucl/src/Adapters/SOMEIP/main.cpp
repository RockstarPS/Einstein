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
#include <thread>
#include "UclSomeIpProxy.hpp"

static bool bRequestExit;

void exit_handler( int s )
{
    std::cout << "Ucl SomeIP Proxy Exiting.." << std::endl;
    bRequestExit = true;
}

int main(int, char *[])
{
    int Ret;
    // Initialize the UCL System
    std::cout << "Ucl StartS Running.." << std::endl;

    Ret = CUclSomeIpProxy::getInstance().start();

    if (Ret >= 0)
    {
        bRequestExit = false;

        std::signal( SIGINT, exit_handler );

        while (!bRequestExit)
        {
            std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
        }

        std::cout << "Ucl SomeIP Proxy Exiting..........." << std::endl;
        CUclSomeIpProxy::getInstance().stop();
        std::this_thread::sleep_for( std::chrono::seconds( 1u ) );
    }
    else
    {
        std::cout << "Ucl SomeIP Proxy Start Failed" << std::endl;
    }

    return 0;
}
