#include "dk_logger.h"
using namespace std;
LOG_DECLARE_CONTEXT ( mLogContext1 );
int main(int argc , char *argv[])
{
    int option;
    
    cout << "Start:" << argv[0] << "\n"; 
    if(2 == argc )
    {
        
        option = strtol(argv[1],NULL, 16);
        
        if( option < 7 || option >= 0)
        {
            
            LOG_REGISTER_APP_CONSOLE ( "TCXX", "Test CXX Application ==> DLT_LOG_VERBOSE" );
            LOG_REGISTER_CONTEXT ( mLogContext1, "MOD1", "Module 1 Context", (DltLogLevelType)option );

            LOGE ( &mLogContext1, "Error message" );
            LOGW ( &mLogContext1, "Warning message" );
            LOGI ( &mLogContext1, "Info message" );
            LOGD ( &mLogContext1, "Debug message " );
            LOGV ( &mLogContext1, "Verbose message " );
            
            LOGE ( &mLogContext1, "Error message", "Hello", "World" );
            LOGW ( &mLogContext1, "Warning message", "Welcome", "To INDIA" );
            LOGI ( &mLogContext1, "Info message", 100, "and", 700  ); 
            LOGD ( &mLogContext1, "Debug message", 100, "and", 200 );
            LOGV ( &mLogContext1, "Verbose message", "WELCOME", " To Banagalore" );
        }
        else{
            cout << "Invalid Option " << "\n";
        }
    }
    else
    {	
        cout << "use:" << argv[0] << "<logLevel>" << "\n";
    }
    
    
    LOG_UNREGISTER_CONTEXT ( mLogContext1 );
    
    return 0;
}