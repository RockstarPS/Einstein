#include "dk_logger.h"
#include "pthread.h"

void *myThreadFun(void *p ); 
void *myThreadFun_2(void *p ); 
LOG_DECLARE_CONTEXT ( mLogContext1 );
LOG_DECLARE_CONTEXT ( mLogContext2 );
LOG_DECLARE_CONTEXT ( mLogContext3 );
int main (void)
{
    LOG_REGISTER_APP_CONSOLE ( "TC", "Test C Application" );
    pthread_t tid_1, tid_2; 
    pthread_create(&tid_1, NULL, myThreadFun, NULL); 
    pthread_create(&tid_2, NULL, myThreadFun_2, NULL); 
    pthread_join(tid_1, NULL); 
    pthread_join(tid_2, NULL); 
    
    LOG_REGISTER_CONTEXT ( mLogContext1, "MOD1", "Module 1 Context", DLT_LOG_VERBOSE);
    LOGE ( &mLogContext1, "Error message_thred_1" );
    LOGW ( &mLogContext1, "Warning message_thred_1" );
    LOGI ( &mLogContext1, "Info message_thred_1" );
    LOGD ( &mLogContext1, "Debug message_thred_1 " );
    LOGV ( &mLogContext1, "Verbose message_thred_1 " );
    
    pthread_join(tid_1, NULL); 
    pthread_join(tid_2, NULL);
    pthread_exit(NULL); 
    LOG_UNREGISTER_CONTEXT ( mLogContext1 );
    
    return 0;
}

void *myThreadFun( void *p ) 
{ 
    LOG_REGISTER_CONTEXT ( mLogContext2, "MOD2", "Module 2 Context", DLT_LOG_VERBOSE );
    LOGE ( &mLogContext2, "Error message_thred_2" );
    LOGW ( &mLogContext2, "Warning message_thred_2" );
    LOGI ( &mLogContext2, "Info message_thred_2" );
    LOGD ( &mLogContext2, "Debug message_thred_2 " );
    LOGV ( &mLogContext2, "Verbose message_thred_2 " );
    
    LOG_UNREGISTER_CONTEXT ( mLogContext2 );

    return NULL;
}


void *myThreadFun_2( void *p ) 
{ 
    LOG_REGISTER_CONTEXT ( mLogContext3, "MOD3", "Module 3 Context", DLT_LOG_DEBUG );
    LOGE ( &mLogContext3, "Error message_thred_3" );
    LOGW ( &mLogContext3, "Warning message_thred_3" );
    LOGI ( &mLogContext3, "Info message_thred_3" );
    LOGD ( &mLogContext3, "Debug message_thred_3 " );
    LOGV ( &mLogContext3, "Verbose message_thred_3 " );
    
    LOG_UNREGISTER_CONTEXT ( mLogContext3 );
    
    return NULL;
}
