#include "dk_logger.h"
#include <vector>
using namespace std;
LOG_DECLARE_CONTEXT ( mLogContext1 );

int main(int argc , char *argv[])
{
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
    const char* ptr_var = "pointer str variable";

    std::string strg_var = "/system/etc/system/config/wave/overspeed.wav";

    bool bool_var = true;

    float float_var = 123.456;
    
    std::vector<uint8_t> vector_buffer={0,1,2,3,4};
    float floatValue = 3.14;
    float* floatPtr = &floatValue;
    cout << "Start:" << argv[0] << "\n"; 
    if(2 == argc )
    {
        option = strtol(argv[1],NULL, 16);
        
        if( option < 7 || option >= 0)
        {
            LOG_REGISTER_APP_DLT ( "TCPP", "Test CPP Application" );
            
            LOG_REGISTER_CONTEXT ( mLogContext1, "MOD2", "Module 2 Context",(DltLogLevelType)option );

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
            LOGI(&mLogContext1, "Signed 8bit: ", int8_var);
            LOGI(&mLogContext1, "Unsigned 8bit: ", uint8_var);
            LOGI(&mLogContext1, "Signed 16bit: ", int16_var);
            LOGI(&mLogContext1, "Unsigned 16bit: ", uint16_var);
            LOGI(&mLogContext1, "Signed 32bit: ", int32_var);
            LOGI(&mLogContext1, "Unsigned 32bit: ", uint32_var);
            LOGI(&mLogContext1, "Signed 64bit: ", int64_var);
            LOGI(&mLogContext1, "Signed 64bit: ", signed_int64_var);
            LOGI(&mLogContext1, "Unsigned 64bit: ", uint64_var);
            LOGI(&mLogContext1, "char: ", str_var);
            LOGI(&mLogContext1, "char pointer: ", ptr_var);
			LOGI(&mLogContext1, "String: ", strg_var, ", ", option);
            LOGI(&mLogContext1, "Bool: ", bool_var);
            LOGI(&mLogContext1, "Float: ", float_var);
            LOGI(&mLogContext1, "Vector: ", vector_buffer );
            
            LOGI(&mLogContext1, "Float pointer: ", *floatPtr);
            LOGI(&mLogContext1, "Float pointer: ", floatPtr, "Float: ", float_var);
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