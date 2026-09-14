#include <stdio.h>
#include <stdlib.h>
#include "dk_logger.h"
#include <thread>
using namespace std;
LOG_DECLARE_CONTEXT ( mLogContext3 );
LOG_DECLARE_CONTEXT ( mLogContext2 ); 
LOG_DECLARE_CONTEXT ( mLogContext1 ); 
void thread3 ( void )
{  
    LOG_REGISTER_CONTEXT ( mLogContext3, "MOD1", "Module 1 Context", DLT_LOG_DEBUG );
    LOGE ( &mLogContext3, "Error message_thred_3" );
    LOGW ( &mLogContext3, "Warning message_thred_3" );
    LOGI ( &mLogContext3, "Info message_thred_3" );
    LOGD ( &mLogContext3, "Debug message_thred_3 " );
    LOGV ( &mLogContext3, "Verbose message_thred_3 " );
    LOG_UNREGISTER_CONTEXT ( mLogContext3 );
}

void thread2 ( void )
{
    LOG_REGISTER_CONTEXT ( mLogContext2, "MOD2", "Module 2 Context", DLT_LOG_VERBOSE );
    LOGE ( &mLogContext2, "Error message_thred_2" );
    LOGW ( &mLogContext2, "Warning message_thred_2" );
    LOGI ( &mLogContext2, "Info message_thred_2" );
    LOGD ( &mLogContext2, "Debug message_thred_2 " );
    LOGV ( &mLogContext2, "Verbose message_thred_2 " );
    
    LOG_UNREGISTER_CONTEXT ( mLogContext2 );
}

int main ( void )
{
    LOG_REGISTER_APP_CONSOLE ( "TC", "Test C Application" );
    LOG_REGISTER_CONTEXT ( mLogContext1, "MOD3", "Module 3 Context", DLT_LOG_VERBOSE);

    std::thread t1 ( thread2 );
    std::thread t2 ( thread3 );
    t1.join();
    t2.join();
    LOGE ( &mLogContext1, "Error message_thred_1" );
    LOGW ( &mLogContext1, "Warning message_thred_1" );
    LOGI ( &mLogContext1, "Info message_thred_1" );
    LOGD ( &mLogContext1, "Debug message_thred_1 " );
    LOGV ( &mLogContext1, "Verbose message_thred_1 " );
    LOG_UNREGISTER_CONTEXT ( mLogContext1 );
    return EXIT_SUCCESS;
}
