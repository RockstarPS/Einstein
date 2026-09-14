#include "Os.h"

#define OS_COUNTER_RESOLUTION 1

uint32 sys_now(void)
{
    TickType counterValue;
    StatusType status;

    // Get the current value of the system counter
    status = GetCounterValue((CounterType)OsCounter_0, &counterValue);

    if (status != E_OK)
    {
        /* invoke det */
        return 0; 
    }

    // Convert counter value to milliseconds and return
    return (uint32)(counterValue * OS_COUNTER_RESOLUTION);
}
