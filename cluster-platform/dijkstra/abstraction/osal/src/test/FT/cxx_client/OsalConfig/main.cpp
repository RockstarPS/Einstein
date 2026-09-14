#include <iostream>
#include <thread>
#include <unistd.h>
#include "DKOsalConfig.h"

using namespace std;
using namespace dk::osal;

int main(int argc, char *argv[]) {

    thread t1;

    ThreadPrio l_Prio = 2;                       		 	// priority for this thread
    uint32_t l_stackSize = 3;								// stack size for this thread
    ThreadConfigID THREAD_DEFAULT_1 = (ThreadConfigID) "2"; // ThreadConfigID for which this config applies
    OSAL_THREAD_CONFIG config[] = { {THREAD_DEFAULT_1, l_Prio, l_stackSize }};

    cout<<"testing : getInstance() API "<<endl;
    cout<<"getting instance of OsalConfig  "<<endl;
    OsalConfig &Osalconfig_o = OsalConfig::getInstance();
    cout<<"Done"<<endl;
    cout<<endl;

    cout<<"testing : setThreadConfigTable() API "<<endl;
    cout<<"Setting  thread configuration Table  : "<<endl;
    if(Osalconfig_o.setThreadConfigTable(config, 1))
    {
        cout<<"Thread configTable updated"<<endl;
    }
    else
    {
        cout<<"Failed to update Thread ConfigTable"<<endl;
    }
    cout<<"Done"<<endl;
    cout<<endl;

    cout<<"Testing getThreadConfig() API"<<endl;
    cout<<"Reading  back the thread configuration : "<< endl;
    l_Prio = 0;
    l_stackSize = 0;
    if(Osalconfig_o.getThreadConfig(THREAD_DEFAULT_1, l_Prio, l_stackSize))
    {
        cout<<"priority : " << l_Prio << " and stack size : "<< l_stackSize << endl;
    }
    else
    {
        cout<<"Failed to read thread config"<<endl;
    }
    cout<<endl;

    cout<<"testing : isPrioReserved() API "<<endl;
    cout<<"checking priority is reserved or not"<<endl;
    if (Osalconfig_o.isPrioReserved(2))
    {
        cout << "thread priority - 2 is  already reserved" << endl;
    }
    else
    {
        cout << "thread priority - 2 is available" << endl;
    }

    if (Osalconfig_o.isPrioReserved(3))
    {
        cout << "thread priority - 3 already reserved" << endl;
    }
    else
    {
        cout << "thread priority - 3 is available" << endl;
    }
    cout<<endl;

    cout<<"Testing setDefaultThreadConfigTable() API"<<endl;
    cout<<"Setting default thread configuration : "<<endl;
    Osalconfig_o.setDefaultThreadConfigTable();
    cout<<"Done"<<endl;
    cout<<endl;

    cout<<"Testing getThreadConfig() API"<<endl;
    cout<<"Reading  back the thread configuration : "<<endl;
    if(Osalconfig_o.getThreadConfig(THREAD_DEFAULT_1, l_Prio, l_stackSize))
    {
        cout << "priority : " << l_Prio << "and stack size : " << l_stackSize << endl;
    }
    else
    {
        cout<<"No thread registered with given thread id "<<endl;
    }
    cout<<endl;
    if (Osalconfig_o.isPrioReserved(2))
    {
        cout << "thread priority - 2 is already reserved" << endl;
    }
    else
    {
        cout << "thread priority - 2 is available" << endl;
    }

}
