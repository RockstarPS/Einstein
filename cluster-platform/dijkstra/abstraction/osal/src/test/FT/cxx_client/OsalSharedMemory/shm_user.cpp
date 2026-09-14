#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "shm_create.h"
/* We print the program's name on the console, so in case you
* only have one console, you can distinguish between outputs
* of shm_creator and shm_user. */
const char *programe = "shm_user";

int main(int argc, char **argv)
{
    Error l_ret;
    char *pfile;
    int option;

    cout<<"starting "<<programe<<" test ..!"<<endl;
    option = atoi(argv[1]);
    switch (option)
    {
    case 1:
        cout<<"************************************************************************"<<endl;
        cout<<"testing open() API without a defined size:"<<endl;
        cout<<"It expected to return total size(8192 KB)"<<endl;
        cout<<endl;
        l_ret = oSharedMemory.open(SHM_BLK);
        if(OK == l_ret)
        {
            cout << programe<<" opened the shared memory block - SHM_BLK "<< endl;
        }
        else
        {
            cout << programe<<" failed to open shared memory - SHM_BLK.!"<< endl;
        }
        cout << "shm_user shared memory size - SHM_BLK : "<< oSharedMemory.size()<< endl;
        cout<<"************************************************************************"<<endl;
        break;
    case 2:
        cout<<"************************************************************************"<<endl;
        cout<<"testing open() API with defined size 1-block(4096 KB):"<<endl;
        cout<<"It expected to return 4096 KB"<<endl;
        cout<<endl;
        l_ret = oSharedMemory.open(SHM_BLK,4096);
        if(OK == l_ret)
        {
            cout << "memory block opened"<< endl;
        }
        else
        {
            cout << "shm_user failed to open shared memory.!" << endl;
        }
        cout << "shm_user shared memory size - SHM_BLK : "<< oSharedMemory.size()<< endl;
        cout<<"************************************************************************"<<endl;
        break;
    default:
        cout<<"usage "<<argv[0]<<" arg 1"<<endl;
        break;
    }

    pfile = (char *)oSharedMemory.pointer();
    if(pfile != NULL)
    {
        cout<<programe<<" : shared memory - SHM_BLK contains : "<<pfile<<endl;
    }
    else
    {
        cout<<programe<<" : shared memory - SHM_BLK is empty..!"<<endl;
    }

    cout<<"Closes the mapping of shared memory block"<<endl;
    oSharedMemory.close();

    cout<<"Remove (unlink) the name of the shared memory block."<<endl;
    SharedMemory::remove(SHM_BLK);
    
    cout << "exiting from "<<programe<<" test..!" << endl;

    return 0;
}
