#include "Os.h"
#include <assert.h>

unsigned int events[10] = {0};

int SetEvent(int task, int ev)
{
    events[task] |= ev;
    return 0;
}

int GetEvent(int task, EventMaskType* ev)
{
    *ev = events[task];
    return 0;
}

int WaitEvent(int ev)
{
    return 0;
}

int ClearEvent(int ev)
{
    events[OsTask_Render] &= ~ev;
    return 0;
}

