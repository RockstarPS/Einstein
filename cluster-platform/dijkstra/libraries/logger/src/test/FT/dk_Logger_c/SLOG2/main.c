#include "dk_logger.h"
LOG_DECLARE_CONTEXT ( mLogContext1 );
int main ( int argc, char *argv[] )
{
    printf ( "Start: %s\n", argv[0] );
    int option;
    
    int8_t int8_var = 123;
    uint8_t uint8_var = 0xFF;

    int16_t int16_var = 1234;
    uint16_t uint16_var = 0xFFFF;

    int32_t int32_var =  12345;
    uint32_t uint32_var = 0xFFFFFFFF;

    int64_t int64_var = 123456;
    int64_t signed_int64_var = -123456;
    uint64_t uint64_var = 0xFFFFFFFFFFFFFFFF;
    char str_var[20] = "array str variable";
    char *ptr_var = "pointer str variable";

    float float_var = 123.456;

    float floatValue = 3.14;
    float* floatPtr = &floatValue;
    if(2 == argc )
    {
        
        option = strtol(argv[1],NULL, 16);
        
        if( option < 7 )
        {

            LOG_REGISTER_APP_SLOG2 ( "TC", "Test C Application" );
            LOG_REGISTER_CONTEXT ( mLogContext1, "MOD1", "Module 1 Context", option );
            
            LOGE ( &mLogContext1, "Error message" );
            LOGW ( &mLogContext1, "Warning message" );
            LOGI ( &mLogContext1, "Info message" );
            LOGD ( &mLogContext1, "Debug message " );
            LOGV ( &mLogContext1, "Verbose message " );
            
            LOGE ( &mLogContext1, "Error message %s %s", "Hello", "World" );
            LOGW ( &mLogContext1, "Warning message %s %s", "Welcome","To INDIA" );
            LOGI ( &mLogContext1, "Info message %d and %d", 500, 700  ); 
            LOGD ( &mLogContext1, "Debug message %d and %d", 100, 200 );
            LOGV ( &mLogContext1, "Verbose message %s %s", "WELCOME"," To Banagalore" );

            LOGI(&mLogContext1, "Signed 8bit: %d", int8_var);
            LOGI(&mLogContext1, "Unsigned 8bit: %d", uint8_var);
            LOGI(&mLogContext1, "Signed 16bit: %d", int16_var);
            LOGI(&mLogContext1, "Unsigned 16bit: %d", uint16_var);
            LOGI(&mLogContext1, "Signed 32bit: %d", int32_var);
            LOGI(&mLogContext1, "Unsigned 32bit: %u", uint32_var);
            LOGI(&mLogContext1, "Signed 64bit: %d ", int64_var);
            LOGI(&mLogContext1, "Signed 64bit: %d ", signed_int64_var);
            LOGI(&mLogContext1, "Unsigned 64bit: %lu", uint64_var);
            LOGI(&mLogContext1, "char: %s ", str_var);
            LOGI(&mLogContext1, "char pointer: %s ", ptr_var);
            LOGI(&mLogContext1, "Float: %f", float_var);
            LOGI(&mLogContext1, "Float pointer: %f", *floatPtr);
            LOGI(&mLogContext1, "Float pointer: %p Float: %f", floatPtr, float_var);
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

