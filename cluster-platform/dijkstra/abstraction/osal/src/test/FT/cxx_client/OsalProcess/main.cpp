#include <iostream>
#include <chrono>
#include <thread>
#include <unistd.h>
#include "DKOsalProcess.h"

using namespace std;
using namespace dk::osal;

#define DEFAULT_PATH  "/:/bin:/tmp"
#define TEMP_PATH  "/:/system:/lib"

int main ( int argc, char *argv[] )
{
    uint32_t pid;
    uint32_t ret;
    int32_t chid;
    const char *file_name = "osal_testapp";
    char *file_name_non_const = const_cast<char*>(file_name);

    const char *retenv;

    cout<<"Test Program for DKOsalProcess...!"<<endl;

    if(2 == argc)
    {
        cout<<"testing getProcessId() API :"<<endl;
        pid = Process::getProcessId();
        cout<< argv[0] <<" process_Id = "<< pid <<endl;

        cout<<endl;

        cout<<"testing getenv() API - reading  OSAL_PROCESS_ENV1 :"<<endl;
        retenv = Process::getenv( "OSAL_PROCESS_ENV1");
        if(NULL != retenv)
        {
            cout<<"OSAL_PROCESS_ENV1 = "<<retenv<<endl;
        }
        else
        {
            cout<<"OSAL_PROCESS_ENV1 = empty(NULL)\n"<<endl;
        }

        cout<<endl;

        cout<<"testing setenv() API - updating OSAL_PROCESS_ENV1:"<<endl;
        ret = Process::setenv( "OSAL_PROCESS_ENV1", DEFAULT_PATH, 0 );
        if( 0 == ret)
        {
            cout<<"OSAL_PROCESS_ENV1 updated..!"<<endl;
        }

        cout<<endl;

        cout<<"reading  OSAL_PROCESS_ENV1 :"<<endl;
        retenv = Process::getenv( "OSAL_PROCESS_ENV1");
        if(NULL != retenv)
        {
            cout<<"OSAL_PROCESS_ENV1 = "<<retenv<<endl;
        }
        else
        {
            cout<<"OSAL_PROCESS_ENV1 = empty(NULL)"<<endl;
        }

        cout<<endl;

        cout<<"over-writing  OSAL_PROCESS_ENV1 :"<<endl;
        ret = Process::setenv( "OSAL_PROCESS_ENV1", TEMP_PATH, 1 );
        if( 0 == ret)
        {
            cout<<"OSAL_PROCESS_ENV1 updated..!"<<endl;
        }

        cout<<endl;

        cout<<"reading  OSAL_PROCESS_ENV1 :"<<endl;
        retenv = Process::getenv( "OSAL_PROCESS_ENV1");
        if(NULL != retenv)
        {
            cout<<"OSAL_PROCESS_ENV1 = "<<retenv<<endl;
        }
        else
        {
            cout<<"OSAL_PROCESS_ENV1 = empty(NULL)"<<endl;
        }

        cout<<endl;

        cout<<"testing unsetenv() API - deleting OSAL_PROCESS_ENV1 :"<<endl;
        ret = Process::unsetenv("OSAL_PROCESS_ENV1");
        if( 0 == ret)
        {
            cout<<"OSAL_PROCESS_ENV1 deleted..!"<<endl;
        }

        cout<<endl;

        cout<<"reading  OSAL_PROCESS_ENV1 :"<<endl;
        retenv = Process::getenv( "OSAL_PROCESS_ENV1" );
        if(NULL != retenv)
        {
            cout<<"OSAL_PROCESS_ENV1 = "<<retenv<<endl;
        }
        else
        {
            cout<<"OSAL_PROCESS_ENV1 = empty(NULL)"<<endl;
        }

        cout<<endl;

        cout<<"testing createProcess() API - creating a process < osal_testing >"<<endl;
        //char *argv1[] = {"osal_testing", argv[1], NULL };
        char arg1[] = "osal_testing";
        char* argv1[] = {arg1, argv[1], NULL};
        chid = Process::createProcess ( file_name_non_const, argv1);
        cout<<"pid return from osal_testing = "<<chid<<endl;

        std::this_thread::sleep_for ( std::chrono::seconds ( 5 ) );

        cout<<endl;

        cout<<"OSAL_PROCESS_ENV1 updating:"<<endl;
        ret = Process::setenv( "OSAL_PROCESS_ENV1", DEFAULT_PATH, 0 );
        if( 0 == ret)
        {
            cout<<"OSAL_PROCESS_ENV1 updated..!"<<endl;
        }

        cout<<endl;

        cout<<"testing createProcess() API - creating process < osal_testing >"<<endl;
        chid = Process::createProcess( file_name_non_const, argv1 );
        cout<<"pid return from osal_testing = "<<chid<<endl;
        std::this_thread::sleep_for ( std::chrono::seconds (5 ) );

    }
    else
    {
        cout<<"usage osal_process <arg 1>\n"<<endl;
    }
}
