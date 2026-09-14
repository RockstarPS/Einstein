#define NOCRYPT 
#define NOGDI
#include "WinAbstraction.h"
#include <stdio.h>
#undef FAR
#define OS_TRAP_H
#include "Os.h"
#include "OsPrivate.h"


extern HANDLE lEventHandle  [OsNumberOfTasks];
extern HANDLE lThreadHandle [OsNumberOfTasks];
DWORD lTaskThreadId[OsNumberOfTasks];
void WindowsEnterSchedCriticalSectionOriginal(void);
void WindowsSchedExitCriticalSectionOriginal(void);

void WindowsSetEvent(HANDLE hEvent);

void WaitforScheduler (void);
void WindowsInitCriticalSection (void);
void InitMultiMediaTimers(void);
void InitWindowsStack(void);

static HANDLE  lpCriticalSection;
static HANDLE  lpSchedCriticalSection;
static unsigned int SystemTimeStamp; 
void IncrementOSTimer(unsigned char p); 
void fbutton_Simulation_init(void);
void WindowsInit(void);
unsigned char SciDrv_Init( void );
int ReturnSched1msCntr(void);

#define THREAD_SUSPENDED 1
#define THREAD_RUNNING 2
#define WAIT_FOR_EVENT 3
#define PENDING_CPU 4
HANDLE lHandleDispatchThread;
HANDLE lDispatcherThreadState;
HANDLE lDispatcherThreadEvent;
HANDLE lMainThreadEvent;

typedef struct
{
	unsigned char lSuspendStatus;

}TaskThreadAttributes;

unsigned long lCounterOS[OsNumberOfTasks];


static TaskThreadAttributes OsTaskAttributes[OsNumberOfTasks];


void Init_Taskfunc(void);
unsigned long lcnt;

void DispatcherFunction(void)
{
	while(1)
	{
		WindowsEnterSchedCriticalSectionOriginal();
		OsCtrlParam.ActiveTaskIndex = OsCtrlParam.RequestedTaskIndex; // New Requested task.
		OsCtrlParam.ActiveTaskPriority = OsCtrlParam.RequestedTaskPriority; // New Requested Priority
		TcbTaskRefConfig[OsCtrlParam.ActiveTaskIndex]->TaskParamRef->State = RUNNING;
		OsCtrlParam.RequestScheduler = FALSE;
		osTaskStartHook();
		if((TcbTaskRefConfig[OsCtrlParam.ActiveTaskIndex]->TaskCategory == 0))
		{
			/*This is a non-preemptive task. Lock the dispatacher*/
			OsCtrlParam.LockDispatcher = 1;
		}
		else
		{
			/*Pre-emptive task. No need to lock dispatcher. */
			OsCtrlParam.LockDispatcher =0;
		}
		if(OsTaskAttributes[OsCtrlParam.ActiveTaskIndex].lSuspendStatus ==1)
		{
			OsTaskAttributes[OsCtrlParam.ActiveTaskIndex].lSuspendStatus = 0;
			ResumeThread(lThreadHandle[OsCtrlParam.ActiveTaskIndex]);
		}
		else
		{
			WindowsSetEvent(lEventHandle[OsCtrlParam.RequestedTaskIndex]);
		}
		lDispatcherThreadState = WAIT_FOR_EVENT;
		WindowsSchedExitCriticalSectionOriginal();
		WaitForSingleObject(lDispatcherThreadEvent, INFINITE);
	}
}

void CreateDispatcherThread(void)
{

	// Create thread in suspended state
    lHandleDispatchThread = CreateThread(
        NULL,               // Default security attributes
        0,                  // Default stack size
        DispatcherFunction,         // Thread start address (entry point)
        NULL,               // Parameter to the thread function
        CREATE_SUSPENDED,   // Start the thread in a suspended state
        NULL                // Ignore the thread ID
    );
	lDispatcherThreadState = THREAD_SUSPENDED;
	lDispatcherThreadEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	/* 
	 *   The below event is created to have the Ecum_Init, StartOS in infinite wait.
	 *   Without this, the main thread will return and the process ends.
	 */
	lMainThreadEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	
	CreateEventAndThreads();
}

extern OsCtrlParamType OsCtrlParam;


void osDispatchAsm(void)
{
	DWORD CurrentThreadID =0;
	unsigned int lNumofTasks=0;
	unsigned int lTaskIdx = OsNumberOfTasks;
	
	WindowsEnterSchedCriticalSectionOriginal();
	
	if(lDispatcherThreadState == THREAD_SUSPENDED)
	{
		ResumeThread(lHandleDispatchThread);
		lDispatcherThreadState = THREAD_RUNNING;
		WindowsSchedExitCriticalSectionOriginal();
		WaitForSingleObject(lMainThreadEvent,INFINITE);

	}
	else if(lDispatcherThreadState == WAIT_FOR_EVENT)
	{
		CurrentThreadID = GetCurrentThreadId();
		for(lNumofTasks = 0 ; lNumofTasks < OsNumberOfTasks; lNumofTasks++)
		{
			if(CurrentThreadID == lTaskThreadId[lNumofTasks])
			{
				/*Handle Matches. Use the corresponding event to put the thread in wait state */
				lTaskIdx = lNumofTasks;
				break;
			}
		}
		if(lTaskIdx != OsNumberOfTasks)
		{
			lDispatcherThreadState = PENDING_CPU;
			WindowsSetEvent(lDispatcherThreadEvent);
			WindowsSchedExitCriticalSectionOriginal();
			if(OsCtrlParam.ActiveTaskIndex != INVALID_TASK)
			{
			  WaitForSingleObject(lEventHandle[lTaskIdx],INFINITE);
			}
			else
			{
			  WaitForSingleObject(lEventHandle[lTaskIdx],INFINITE);
			}
		}
		else
		{
			
		}
	}
	else
	{
		WindowsSchedExitCriticalSectionOriginal();
	}

}

void EnterCat2ISR(void)
{
	
	OsCtrlParam.LockDispatcher++;
	
}

void ExitCat2ISR(void)
{
	OsCtrlParam.LockDispatcher--;
	if(lDispatcherThreadState != PENDING_CPU)
	{
		if((OsCtrlParam.RequestScheduler != 0) && (OsCtrlParam.LockDispatcher ==0))
		{
			if(OsCtrlParam.ActiveTaskIndex != INVALID_TASK)
			{
				if(TcbTaskRefConfig[OsCtrlParam.ActiveTaskIndex]->TaskParamRef->State == RUNNING)
				{
						if(lThreadHandle[OsCtrlParam.ActiveTaskIndex] != 0)
						{
							OsTaskAttributes[OsCtrlParam.ActiveTaskIndex].lSuspendStatus = 1;
							TcbTaskRefConfig[OsCtrlParam.ActiveTaskIndex]->TaskParamRef->State =READY;
							SuspendThread(lThreadHandle[OsCtrlParam.ActiveTaskIndex]);
							lDispatcherThreadState = PENDING_CPU;
							WindowsSetEvent(lDispatcherThreadEvent);
						}
				}
			}
		}
	}
}

void WindowsInit(void)
{
	
	HANDLE hProcess = GetCurrentProcess();
	#if 0
	SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
	#endif
	DWORD_PTR affinityMask = 0x02;
	 // Set the process affinity mask

    if (SetProcessAffinityMask(hProcess, affinityMask)) {
    } else {
    }
	

    CreateDispatcherThread();
	InitWindowsStack();
	SciDrv_Init();
	fbutton_Simulation_init();
	InitMultiMediaTimers();
}

void WindowsSetLowPriority(void)
{
	SetThreadPriority(GetCurrentThread(), NORMAL_PRIORITY_CLASS);
}


CRITICAL_SECTION cs;  

void WindowsInitCriticalSection (void)
{
	InitializeCriticalSectionAndSpinCount(&cs, 1);
   lpCriticalSection = CreateMutex(NULL, FALSE, NULL);
   lpSchedCriticalSection =  CreateMutex(NULL, FALSE, NULL);
}

HANDLE lCriticalSectionThreadID;
unsigned long lCriticalSectionCntr;

void WindowsEnterSchedCriticalSectionOriginal (void)
{
  
     WindowsEnterCriticalSectionOriginal();
 
}

void WindowsSchedExitCriticalSectionOriginal (void)
{

	WindowsExitCriticalSectionOriginal();
}



void WindowsEnterCriticalSectionOriginal (void)
{
   EnterCriticalSection(&cs);
  
}

void WindowsExitCriticalSectionOriginal (void)
{

  LeaveCriticalSection(&cs);
}

unsigned int GetSystemTimestamp(void)
{
    return SystemTimeStamp;
}

void Bswc_AppIntrpt_ISR(void);

void IncrementOSTimer(unsigned char p)
{
	osTimerInterruptfunc();
}	



