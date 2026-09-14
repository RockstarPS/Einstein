#include "dk_logger.h"
LOG_DECLARE_CONTEXT ( mLogContext1 );
LOG_DECLARE_CONTEXT ( mLogContext2 );
int main()
{
    
    LOG_REGISTER_APP_CONSOLE ( "TCPP", "Test CPP Application" );
    LOG_REGISTER_CONTEXT ( mLogContext1, "MOD1", "Module 1 Context", DLT_LOG_VERBOSE );
    LOG_REGISTER_CONTEXT ( mLogContext2, "MOD2", "Module 2 Context", DLT_LOG_WARN );

    LOGD ( &mLogContext1, "Debug message ", 100, "and ", 200 );
    LOGV ( &mLogContext1, "Verbose message ", "Hello", " World" );
    LOGI ( &mLogContext1, "Info message" );
    
    LOGW ( &mLogContext2, "Warning message" );
    LOGE ( &mLogContext2, "Error message" );
    LOGV ( &mLogContext2, "Verbose message" );
    
    LOG_UNREGISTER_CONTEXT ( mLogContext1 );
    LOG_UNREGISTER_CONTEXT ( mLogContext2 );
    
    return 0;
}





