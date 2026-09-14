#include "dk_logger.h"
LOG_DECLARE_CONTEXT ( mLogContext1 );
LOG_DECLARE_CONTEXT ( mLogContext2 );
int main()
{
    LOG_REGISTER_APP_CONSOLE ( "TC", "Test C Application Multple Context" );
    LOG_REGISTER_CONTEXT ( mLogContext1, "MOD1", "Module 1 Context", DLT_LOG_VERBOSE );
    LOG_REGISTER_CONTEXT ( mLogContext2, "MOD2", "Module 2 Context", DLT_LOG_WARN );

    LOGD ( &mLogContext1, "Debug message %d and %d", 100, 200 );
    LOGV ( &mLogContext1, "Verbose message %s %s", "Hello", "World" );
    LOGI ( &mLogContext1, "Info message" );

    LOGI ( &mLogContext2, "Info message" );
    LOGD ( &mLogContext2, "Debug message" );
    LOGW ( &mLogContext2, "Warning message" );
    LOGE ( &mLogContext2, "Error message" );

    LOG_UNREGISTER_CONTEXT ( mLogContext1 );
    LOG_UNREGISTER_CONTEXT ( mLogContext2 );
    
    return 0;
}
