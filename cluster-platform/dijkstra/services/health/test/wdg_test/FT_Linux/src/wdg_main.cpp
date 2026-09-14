#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <csignal>
#include <thread>
#include <iostream>
#include <wdg_client.h>
#include "dk_logger.h"

#define SIGUSR3 (SIGRTMIN + 1)

uint8_t g_exit_U8 = 1U;

void signalHandler(const int32_t signum)
{
    std::cout << "Interrupt signal (" << signum << ") received.\n" << std::flush;
    g_exit_U8 = false;
}

int main ( const int argc, char *const argv[] )
{
    int32_t sleep_time = 10;
    int32_t testcase = 0;

    if(argc != 3)
    {
        std::cout << "Invalid no. of arguments \n" << std::flush;
    }
    else
    {
        testcase = atoi ( argv[1] );
        sleep_time = atoi ( argv[2] );
    }

    if (SIG_ERR == std::signal(SIGUSR3, &signalHandler))
    {
         std::cout << "Failed to create signal handler \n" << std::flush;
    }

    (void)LOG_REGISTER_APP_DLT ( "TEST", "Watchdog Client" );
    
    std::cout << "Start - Test Case: "<< testcase << ", sleep time " << sleep_time << "\n" << std::flush;

    std::cout << "Test Case "<< testcase << ": calling connect() \n" << std::flush;

    (void)dk::srvc::health::WdgClient::getInstance()->connect ();
    (void)sleep ( static_cast<uint32_t>(sleep_time) );

    std::cout << "Test case "<< testcase << ": calling start() \n" << std::flush;
    (void)dk::srvc::health::WdgClient::getInstance()->start ( 1000 );

    while(g_exit_U8)
    {
        (void)dk::srvc::health::WdgClient::getInstance()->pet();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    (void)sleep ( static_cast<uint32_t>(sleep_time) );

    std::cout << "Exit - Test case: " << testcase << "\n" << std::flush;
}
