#ifndef PC_CAN_H
#define PC_CAN_H
#ifdef  __cplusplus
extern "C" {
#endif


#define _WIN32_WINNT  0x0502

#undef CONST
#define _X86_
#include <stdio.h>
#include <stdarg.h>
#include <windef.h>
#include <winnt.h>
#include <winbase.h>

#define UNUSED_PARAM(a) { a=a; }

#define RECEIVE_EVENT_SIZE 1                // DO NOT EDIT! Currently 1 is supported only
#define RX_QUEUE_SIZE      4096             // internal driver queue size in CAN events
#include "vxlapi.h"

int GetCanChanCount();
char* GetCanChanName(int ix);
DWORD GetActiveCanChanalMasc();
DWORD GetAvailableCanChanalMasc();
void SetActiveCanChanalMasc(DWORD msk);
WORD CanTransmit(int Ch, unsigned int txID,unsigned char* pData, int dlc);
void SetActiveChanel(int ChanelP);

// Required 
void RxMsgCalback(unsigned char Ch, long MsgId, unsigned char Dlc, unsigned char* pData);

// Provided
extern void PC_CanInit(char* pAppNameP);
extern  void PC_CanStop();
#ifdef  __cplusplus
}
#endif

#endif //PC_CAN_H