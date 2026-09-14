#ifndef STUB_FKTS_H
#define STUB_FKTS_H
#include "windows.h"
#include "nw_vmf.h"
#include "P32_TypeDef.h"


#define TRACE_SCAN_INIT	"PN_Scan_Init"
#define TRACE_DAB_CTRL	"DABCtrl"
#define TRACE_STUBS		"Stub_Fkts"

#ifndef B515_VMF_ARDU_GW_C
extern unsigned8  vmf_trid;

#ifdef VMF_TRACE
    #define DEBUG_INFO_HI(trace_task, args...)   VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO, trace_task, (char *)__PRETTY_FUNCTION__, args);
    #define DEBUG_INFO_LO(trace_task, args...)   VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_INFO_20, trace_task, (char *)__PRETTY_FUNCTION__, args);
    #define DEBUG_ERROR(trace_task, args...)     VMF_TRACE_PRINTF(vmf_trid, VMF_TRACE_SEVERITY_ERROR, trace_task, (char *)__PRETTY_FUNCTION__, args);
#else
	#define DEBUG_INFO(trace_task, args...)      if (verbose>0) {printf("INFO    "); printf(trace_task); printf(" "); printf(__PRETTY_FUNCTION__), printf("() -- "); printf(args); printf("\n");}
	#define DEBUG_INFO_HI(trace_task, args...)   if (verbose>1) {printf("INFO_HI "); printf(trace_task); printf(" "); printf(__PRETTY_FUNCTION__), printf("() -- "); printf(args); printf("\n");}
	#define DEBUG_INFO_LO(trace_task, args...)   if (verbose>2) {printf("INFO_LO "); printf(trace_task); printf(" "); printf(__PRETTY_FUNCTION__), printf("() -- "); printf(args); printf("\n");}
	#define DEBUG_ERROR(trace_task, args...)     {printf("ERROR   "); printf(trace_task); printf(" "); printf(__PRETTY_FUNCTION__), printf("() -- "); printf(args); printf("\n");}
#endif
#endif

void MakeUsbPacketRcvMsg(PN_U8 *status,PN_U8 cmd, PN_U16 length);
void MakeUsbPacketIsrRcvMsg(PN_U8* data ,PN_U16 len);
void Delay10us(void);
void DelayMs(PN_U16 ms);
void MAX2172_Tuner_Init(PN_U8 pn_type, PN_FLOAT tuner_freq);
void MAX2172_Tuner_ChangeFreq(PN_U8 tuner,PN_FLOAT tuner_freq);
void AGC_STAT_MAX2172(PN_U8 tuner, PN_U8 *data0, PN_U8 *data1);
void PNS3030D_Rst(void);
void PN_IrisIntEnable(void);
void PN_IrisIntDisable(void);
void SendRegStatus(PN_U8 play_on, PN_U8 data, PN_U8 cmd);


#endif

