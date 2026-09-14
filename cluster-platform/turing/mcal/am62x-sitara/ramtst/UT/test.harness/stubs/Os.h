#include "OsTypes.h"

extern void SuspendAllInterrupts(void);
extern void ResumeAllInterrupts(void);

#define SystemTimer 0


Std_ReturnType GetCounterValue(uint32,TickRefType Value);