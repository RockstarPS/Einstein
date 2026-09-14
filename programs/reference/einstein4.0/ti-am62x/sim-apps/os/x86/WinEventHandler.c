#include <windows.h>
#include <stdio.h>

/*

Multimedia timer in windows gives the best accuracy for timer counters.
Multimedia timer is accessible through winmm.lib or winmm.dll
In order to access through dll, get the function address through ProcAddress and then 
call the function.
*/

typedef MMRESULT (*TIMEGETDEVCAPS)(LPTIMECAPS ptc,UINT       cbtc);
typedef MMRESULT (*TIMEBEGINPERIOD)(  UINT uPeriod);
typedef MMRESULT (*TIMESETEVENT)( UINT uDelay,   UINT uResolution,LPTIMECALLBACK lpTimeProc,DWORD_PTR dwUser, UINT fuEvent);



void CALLBACK MsecCBButton( UINT      uTimerID, UINT      uMsg,DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);
void CALLBACK MsecCANRx( UINT      uTimerID, UINT      uMsg,DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);

static TIMEGETDEVCAPS timeGetDevCapsS=NULL;
static TIMEBEGINPERIOD timeBeginPeriodS = NULL; 
static TIMESETEVENT timeSetEventS = NULL;

void WindowsEnterSchedCriticalSectionOriginal(void);
void WindowsSchedExitCriticalSectionOriginal(void);




HANDLE ghSciWaitEvent;

static int lScedCtr;

extern int l_postVsyncEvent;
extern int lGraphicsPending;
void CALLBACK MsecCBSched( UINT      uTimerID, UINT      uMsg,DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);

void EnterCat2ISR(void);
void ExitCat2ISR(void);

extern unsigned char lDispatchRequested;
static unsigned char lHMICntr =0;
int lScreenInitDone;
static int lCounter =0;
void CALLBACK MsecCBSched( UINT      uTimerID, UINT      uMsg,DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2)
{
	int init_done =0;
	WindowsEnterSchedCriticalSectionOriginal();
	 EnterCat2ISR();
	 IncrementOSTimer(0);
#ifdef GDT_INCLUDED	 
	 RendererInitDone(&init_done);
	 if(( init_done !=0) && (l_postVsyncEvent != 0))
	 {
			 lCounter++;
			 if(lCounter <=15)
			 {
			 }
			 else
			 {
				 if(lGraphicsPending ==0)
				 {
					 PostVsyncEvent();
					 lCounter=0;
				 }
			 }
	 }
#endif	 
	 ExitCat2ISR();
	WindowsSchedExitCriticalSectionOriginal();
}	




DWORD CbkPtr;
DWORD BtnCbkPtr;
DWORD CANCbkPtr;

void InitMultiMediaTimers(void)
{
	
	#define TARGET_RESOLUTION 1         // 1-millisecond target resolution
	
	
	xlLoadWindowsLibrary();
	TIMECAPS tc;
	UINT     wTimerRes;
	if (timeGetDevCapsS(&tc, sizeof(TIMECAPS)) != TIMERR_NOERROR) 
	{
	}
	wTimerRes = min(max(tc.wPeriodMin, TARGET_RESOLUTION), tc.wPeriodMax);
	timeBeginPeriodS(wTimerRes); 
	timeSetEventS(1,0,MsecCBSched,&CbkPtr,TIME_PERIODIC);
	StartCanTimer();
	
} 

void xlLoadWindowsLibrary(void){
  HANDLE hxlDll = LoadLibrary("Winmm.dll");
  timeGetDevCapsS =  (TIMEGETDEVCAPS*)GetProcAddress(hxlDll,"timeGetDevCaps");
  timeBeginPeriodS =  (TIMEBEGINPERIOD*)GetProcAddress(hxlDll,"timeBeginPeriod");
  timeSetEventS =  (TIMESETEVENT*)GetProcAddress(hxlDll,"timeSetEvent");
  
}



void StartCanTimer(void)
{
	timeSetEventS(1,0,MsecCANRx,&CANCbkPtr,TIME_PERIODIC);
}
void CANReceiveEventThread(void);

void CALLBACK MsecCANRx( UINT      uTimerID, UINT      uMsg,DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2)
{
	CANReceiveEventThread();
}
