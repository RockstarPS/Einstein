#include "Os.h"


AccessType OsInternalCheckObjAccessRights (const OsMPUAccessGroupConfigType * const pAccessConfig, MemoryStartAddressType Address, MemorySizeType Size)
{
    AccessType Result = OS_ACCESS_TYPE_RWX;
   
    return Result;
}


void osSetupAndEnableConfiguredInterrupts(void){}

void WindowsEnterCriticalSectionOriginal(void);

void WindowsExitCriticalSectionOriginal(void);

osIntGlobaltype osSuspendInterruptsAsm(void)
{
  WindowsEnterCriticalSectionOriginal();
  return(0);
}

void osEnableGlobalInterruptAsm(void)
{
  WindowsExitCriticalSectionOriginal();
}


void osResumeInterruptsAsm(osIntGlobaltype intStatus)
{
  WindowsExitCriticalSectionOriginal();
}

osuint32 osGetCPSR(void) {return(0x00);}

void osDisableGlobalInterruptAsm(void)
{
  WindowsEnterCriticalSectionOriginal();
}

void OsHal_CheckIntrPending (void){}

void OsHal_CpuStartOS (void) 
{ 
  osStartOS();
}
