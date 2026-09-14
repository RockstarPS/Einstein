#include <iostream>
#include <unistd.h>

using namespace std;

int main ( int argc, char *argv[])
{
    int cnt;
    char *env_value;
    cout<<" << starting "<<argv[0]<<endl;
    cout<<" << pid printing from " <<argv[0]<<" = "<< getpid()<<endl;
    env_value = getenv("OSAL_PROCESS_ENV1");
    if(NULL != env_value)
    {
        cout<<" << OSAL_PROCESS_ENV1 = "<<env_value<<endl;
    }
    else
    {
        cout<<" << OSAL_PROCESS_ENV1 = empty(NULL)"<<endl;
    }
    cout<<" << argc printing from "<<argv[0]<<" = "<<argc<<endl;
    cout<<" << argv[] printing from " <<argv[0] <<" = ";
    for( cnt= 0; cnt< argc; cnt++)
    {
        cout<<argv[cnt]<<" ";
    }
    cout<<endl;

    return 0;
}
