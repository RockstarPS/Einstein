#ifndef VCAST_NEVER_STUB_EXTERNS
/* Begin defined extern variables */

/* INITIALIZATION_OBJECTS_USER_CODE "1" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "1" */
OsTaskConfigRefType TcbTaskRefConfig[21U] 
/* INITIALIZATION_CODE_USER_CODE "1" */

/* INITIALIZATION_CODE_USER_CODE_END "1" */
;


/* INITIALIZATION_OBJECTS_USER_CODE "2" */
/* INITIALIZATION_OBJECTS_USER_CODE_END "2" */
OsCtrlParamType OsCtrlParam 
/* INITIALIZATION_CODE_USER_CODE "2" */

/* INITIALIZATION_CODE_USER_CODE_END "2" */
;

/* End defined extern variables */
/* Begin defined static member variables */
/* End defined static member variables */
#endif /*VCAST_NEVER_STUB_EXTERNS*/
/* BEGIN PROTOTYPE STUBS */
void OsStartDispatchMetric(void)
{
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_10_1
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_10_1
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 1, 1, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_10_1
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_10_1
  vCAST_USER_CODE_TIMER_START();
  return;
}


unsigned char P_10_2_1

;
void osSchedInsertTask(TaskType TaskIndex)
{
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_10_2
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_10_2
  if ( vcast_is_in_driver ) {
    P_10_2_1 = TaskIndex;
    vCAST_COMMON_STUB_PROC_9( 10, 2, 2, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_10_2
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_10_2
  vCAST_USER_CODE_TIMER_START();
  return;
}


void osSchedRemoveTask(void)
{
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_10_3
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_10_3
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 3, 1, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_10_3
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_10_3
  vCAST_USER_CODE_TIMER_START();
  return;
}


void osEnableAllInterrupts(void)
{
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_10_4
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_10_4
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 4, 1, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_10_4
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_10_4
  vCAST_USER_CODE_TIMER_START();
  return;
}


unsigned char R_10_5;
osbool osCheckInterruptsEnabled(void)
{
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_10_5
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_10_5
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 5, 1, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_10_5
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_10_5
  vCAST_USER_CODE_TIMER_START();
  return R_10_5;
}


void OsPrvEnterCriticalSection(void)
{
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_10_6
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_10_6
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 6, 1, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_10_6
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_10_6
  vCAST_USER_CODE_TIMER_START();
  return;
}


void OsPrvExitCriticalSection(void)
{
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_10_7
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_10_7
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 7, 1, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_10_7
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_10_7
  vCAST_USER_CODE_TIMER_START();
  return;
}


void osDispatchAsm(void)
{
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_10_8
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_10_8
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 8, 1, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_10_8
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_10_8
  vCAST_USER_CODE_TIMER_START();
  return;
}


unsigned long P_10_9_1

;
unsigned char *P_10_9_2

;
unsigned char P_10_9_3

;
void OsErr_osApplicationErrorHook(OsServiceIdType ServiceId, StatusType * pStatus, StatusType Status)
{
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_10_9
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_10_9
  if ( vcast_is_in_driver ) {
    P_10_9_1 = ServiceId;
    P_10_9_2 = pStatus;
    P_10_9_3 = Status;
    vCAST_COMMON_STUB_PROC_9( 10, 9, 4, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_10_9
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_10_9
  vCAST_USER_CODE_TIMER_START();
  return;
}


void osTaskStopHook(void)
{
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_10_10
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_10_10
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 10, 1, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_10_10
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_10_10
  vCAST_USER_CODE_TIMER_START();
  return;
}


unsigned short R_10_11;
osuint16 Os_GetContext(void)
{
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_10_11
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_10_11
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 11, 1, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_10_11
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_10_11
  vCAST_USER_CODE_TIMER_START();
  return R_10_11;
}


unsigned long R_10_12;
osIntGlobaltype osSuspendInterruptsAsm(void)
{
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_10_12
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_10_12
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 10, 12, 1, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_10_12
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_10_12
  vCAST_USER_CODE_TIMER_START();
  return R_10_12;
}


/* END PROTOTYPE STUBS */
