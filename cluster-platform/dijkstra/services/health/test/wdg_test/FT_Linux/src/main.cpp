#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <csignal>
#include <thread>
#include <iostream>
#include "dk_logger.h"

#define SIGUSR3 (SIGRTMIN + 1)
#define SIGUSR4 (SIGRTMIN + 2)
#define SIGUSR5 (SIGRTMIN + 3)

uint8_t g_exit_U8 = 1U;
uint8_t testcase_signal = 0;

void signalHandler(const int32_t signum)
{
    std::cout << "Interrupt signal (" << signum << ") received.\n" << std::flush;
    g_exit_U8 = false;

    if(signum == SIGUSR3)
    {
        testcase_signal = 1;
    }
    else if(signum == SIGUSR4)
    {
        testcase_signal = 2;
    }
    else if(signum == SIGUSR5)
    {
        testcase_signal = 3;
    }
    else
    {

    }
}

int main ( const int argc, char *const argv[] )
{
    int testcase = 0;

    if(argc != 2)
    {
        std::cout << "Invalid no. of arguments \n" << std::flush;
    }
    else
    {
        testcase = atoi ( argv[1] );
    }

    std::cout << "Start - Test Case: " << testcase << "\n" << std::flush;
    std::cout << "SIG MIN: " << SIGRTMIN << "\n" << std::flush;
    std::cout << "SIG MAX: " << SIGRTMAX << "\n" << std::flush;

    if (SIG_ERR == std::signal(SIGUSR3, &signalHandler))
    {
         std::cout << "Failed to create signal handler" << std::flush;
    }

    if (SIG_ERR == std::signal(SIGUSR4, &signalHandler))
    {
         std::cout << "Failed to create signal handler" << std::flush;
    }

    if (SIG_ERR == std::signal(SIGUSR5, &signalHandler))
    {
         std::cout << "Failed to create signal handler" << std::flush;
    }

    while(g_exit_U8)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "Exit - Test case: " << testcase << "\n" << std::flush;

    if(testcase_signal == 2)
    {
        return 255;
    }
    else if(testcase_signal == 3)
    {
        return EXIT_FAILURE;
    }
    else
    {
        return EXIT_SUCCESS;
    }

}
