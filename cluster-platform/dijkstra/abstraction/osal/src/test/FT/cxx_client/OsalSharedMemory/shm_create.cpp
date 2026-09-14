#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "shm_create.h"
/* We print the program's name on the console, so in case you
* only have one console, you can distinguish between outputs
* of shm_creator and shm_user. */
const char *programe = "shm_creator";

int main(int argc, char **argv) {
    const char *text = "Text by shm_creator.c";
    char *fd;
    Error l_ret;

    cout <<programe<<" test started..!" << endl;
    cout<<endl;
    cout<<"testing create() and size() API's :"<<endl;
    cout<<"************************************************************************"<<endl;
    cout<<"creating 2-blk shared memory - SHM_BLK total size: 2x4096"<<endl;

    l_ret = oSharedMemory.create(SHM_BLK , SHM_SIZE);
    if(OK == l_ret)
    {
        cout <<programe<< " memory block created with size : "<<oSharedMemory.size()<<" KB"<< endl;
    }
    else
    {
        cout << programe<<" failed to create shared memory.!" << endl;
    }
    cout<<"************************************************************************"<<endl;

    /* Get a pointer to the shared memory, map it into
            * our address space */

    fd = (char *)oSharedMemory.pointer();
    if(fd == (void *)-1)
    {
        cout<<"failed to get shared memory pointer from "<<programe<<endl;
    }
    else
    {
        cout<<"pointer allocated to shared memory from "<<programe<<endl;
    }

    cout<<"writing data to shared memory from "<<programe<<endl;
    strcpy(fd, text);

    cout<<programe<<" : Shared memory created.."<<endl;
    cout<<programe<<" : Wrote text "<<fd<<" to shared memory"<<endl;
    cout<<programe<<" : Sleeping for 20 seconds.  While this program is sleeping"<<endl;
    cout<<programe<<" : run 'shm_user'"<<endl;

    sleep(20);

    cout<<"Closes the mapping of shared memory block"<<endl;
    oSharedMemory.close();

    cout<<"Remove (unlink) the name of the shared memory block."<<endl;
    SharedMemory::remove(SHM_BLK);
    
    cout<<"exiting from "<<programe<<endl;
    return 0;
}
