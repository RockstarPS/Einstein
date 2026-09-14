//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2015] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------

#ifndef I_DBG_H
#define I_DBG_H

//=====================================================================================================================
//  CONSTANTS & TYPES
//=====================================================================================================================
#define TRACE_CUSTOM_BEGIN_MARK         0
#define TRACE_CUSTOM_END_MARK           255

#define TRACE_CUSTOM_MARKER_BEGIN(MarkerId, TaskId)                     TraceCustomMarker(MarkerId, TaskId, TRACE_CUSTOM_BEGIN_MARK)
#define TRACE_CUSTOM_MARKER_END(MarkerId, TaskId)                       TraceCustomMarker(MarkerId, TaskId, TRACE_CUSTOM_END_MARK)
#define TRACE_CUSTOM_MARKER_ABS_BEGIN(MarkerId)                         TraceCustomMarkerAbsolute(MarkerId, TRACE_CUSTOM_BEGIN_MARK)
#define TRACE_CUSTOM_MARKER_ABS_END(MarkerId)                           TraceCustomMarkerAbsolute(MarkerId, TRACE_CUSTOM_END_MARK)
// The following markers close another marker named referenced (RefMarkerId). The referenced marker may occur many times inside the section and its time is summarized 
// to give a statistic as though RefMarkerId start were MarkerId start and RefMarkerId end were MarkerId end.  
#define TRACE_CUSTOM_MARKER_REF_BEGIN(MarkerId, RefMarkerId, TaskId)    TraceCustomMarkerReference(MarkerId, RefMarkerId, TaskId, TRACE_CUSTOM_BEGIN_MARK)
#define TRACE_CUSTOM_MARKER_REF_END(MarkerId, RefMarkerId, TaskId)      TraceCustomMarkerReference(MarkerId, RefMarkerId, TaskId, TRACE_CUSTOM_END_MARK)
// The following markers are used for GPU Load measurement
#define TRACE_GPU_MARKER_BEGIN()                                        TRACE_CUSTOM_MARKER_ABS_BEGIN(-1)
#define TRACE_GPU_MARKER_END()                                          TRACE_CUSTOM_MARKER_ABS_END(-1)

#define TRACE_CUSTOM_MARKER_LOG_REGISTER(MarkerId, pLog)                TraceCustomMarkerLogRegister(MarkerId, pLog)
#define TRACE_CUSTOM_MARKER_LOG_SAMPLE(MarkerId)                        TraceCustomMarkerLogSample(MarkerId)
#define TRACE_GPU_MARKER_LOG_REGISTER(pLog)                             TRACE_CUSTOM_MARKER_LOG_REGISTER(-1, pLog)
#define TRACE_GPU_MARKER_LOG_SAMPLE()                                   TRACE_CUSTOM_MARKER_LOG_SAMPLE(-1)

//----------------------------------------------------------------------------------------------------------------------
// Exported types
//----------------------------------------------------------------------------------------------------------------------
typedef struct {
    unsigned int unMaxTimeMs;
    unsigned int unAvrTimeMs;
    unsigned int unTaskLoad;
} tCpuTraceLogData;

typedef enum {
    eCpuTraceCommand_Load,
    eCpuTraceCommand_Max
} tCpuTraceCommand;

typedef struct {
    tCpuTraceCommand    command;
    tCpuTraceLogData*   pBuffer;
    int                 nBufferSize;
    int                 nIndex;
    unsigned int        unTotalTimeUs;
} tCpuTraceLog;

//----------------------------------------------------------------------------------------------------------------------
// Exported functions
//----------------------------------------------------------------------------------------------------------------------
//extern void DbgExt_SaveStackUsage(void);
//extern void TraceInit(void);
//extern void TraceCustomMarker( int nMarkerIdP, int nTaskIdP, int nValueP );
extern void TraceCustomMarkerAbsolute( int nMarkerIdP, int nValueP );
//extern void TraceCustomMarkerReference( int nMarkerIdP, int nRefMarkerIdP, int nTaskIdP, int nValueP );
extern void TraceCustomMarkerLogRegister(int, tCpuTraceLog*);
extern void TraceCustomMarkerLogSample(int);

// Runtime measurements of tasks and ISR routines
//extern void Rtm_PreTaskHook(TaskType TaskID);
//extern void Rtm_PostTaskHook(TaskType TaskID);
//extern void Rtm_PreISRHook(ISRType x);
//extern void Rtm_PostISRHook(ISRType x);

#endif //I_DBG_H
