#include "dk_logger.h"
LOG_DECLARE_CONTEXT ( mLogContext1 );

int main ( int argc, char *argv[] )
{
    printf ( "Start: %s\n", argv[0] );

    int option; 
    
    if(2 == argc )
    {
        option = strtol(argv[1],NULL, 16);
        
        if( option < 7 )
        {
            LOG_REGISTER_APP_CONSOLE ( "TC", "Test C Application" );
            LOG_REGISTER_CONTEXT ( mLogContext1, "MOD1", "Module 1 Context", option );

            LOGE ( &mLogContext1, "Error message" );
            LOGW ( &mLogContext1, "Warning message" );
            LOGI ( &mLogContext1, "Info message" );
            LOGD ( &mLogContext1, "Debug message " );
            LOGV ( &mLogContext1, "Verbose message " );
            
            LOGE ( &mLogContext1, "Error message %s %s", "Hello", "World" );
            LOGW ( &mLogContext1, "Warning message %s %s", "Welcome", "To INDIA" );
            LOGI ( &mLogContext1, "Info message %d and %d", 500, 700  ); 
            LOGD ( &mLogContext1, "Debug message %d and %d", 100, 200 );
            LOGV ( &mLogContext1, "Verbose message %s %s", "WELCOME", " To Banagalore" );
        }
        else{
            printf("Invalid Option\n");
        }
    }
    else
    {	
        printf ( "use: %s <logLevel>\n", argv[0] );
    }
    
    LOG_UNREGISTER_CONTEXT ( mLogContext1 );
    
    return 0;
}

