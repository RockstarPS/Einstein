/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2016. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************
*  File Name         :  Apm.c                                                *
*  Module Short Name :  Apm                                                  *
*  Description       :  This file contains implementations of the Autosar    *
*                       Performance Measturement                             *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS Multi                                              *
* Target Hardware  :  Platform Independent                                   *
*                                                                            *
******************************************************************************/
#ifndef APM_C
#define APM_C


/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Os.h"
#include "Apm.h"

#define APM_CODE_SEC_START
 #include "MemMap.h"

#define APM_DATA_SEC_START
 #include "MemMap.h"

#define APM_CONST_SEC_START
 #include "MemMap.h"

#ifdef APM_ENABLED
/*****************************************************************************
*                                 Macro Definitions                          *
*----------------------------------------------------------------------------*
* Definition of macro shall be followed by a comment that explains the       *
* purpose of the macro.                                                      *
******************************************************************************/
#define APM_TICKS_TO_US(Ticks)                                  ((Ticks) / APM_GPT_FREQ_IN_MHZ)

#define APM_SAVE_TASK_MEASUREMENT(Type, EntryId)                                                    \
    Type ## Object * const Amp_CpuLoadEntry = &Apm_CpuLoad.Type[Apm_Measurement.Entry[EntryId].Id]; \
    Amp_CpuLoadEntry->InIsrTotal += IsrDelta;                                                       \
    if(DeltaTotal > Amp_CpuLoadEntry->Max)                                                          \
    {                                                                                               \
        Amp_CpuLoadEntry->Max = DeltaTotal;                                                         \
    }                                                                                               \
    if(DeltaTotal < Amp_CpuLoadEntry->Min)                                                          \
    {                                                                                               \
        Amp_CpuLoadEntry->Min = DeltaTotal;                                                         \
    }                                                                                               \
    Amp_CpuLoadEntry->Total += Delta;                                                               \
    Amp_CpuLoadEntry->Occurrence++;

#define APM_SAVE_TASK_PREEMPTION_MEASUREMENT(Type, EntryId)                                         \
    Type ## Object * const Amp_CpuLoadEntry = &Apm_CpuLoad.Type[Apm_Measurement.Entry[EntryId].Id]; \
    Amp_CpuLoadEntry->InIsrTotal += IsrDelta;                                                       \
    if(Delta > Amp_CpuLoadEntry->PreemptionMax)                                                     \
    {                                                                                               \
        Amp_CpuLoadEntry->PreemptionMax = Delta;                                                    \
    }                                                                                               \
    if(Delta < Amp_CpuLoadEntry->PreemptionMin)                                                     \
    {                                                                                               \
        Amp_CpuLoadEntry->PreemptionMin = Delta;                                                    \
    }                                                                                               \
    Amp_CpuLoadEntry->Total += Delta;                                                               \
    Amp_CpuLoadEntry->PreemptionOccurrence++;

#define APM_SAVE_ISR_MEASUREMENT(Type, EntryId)                                                     \
    Type ## Object * const Amp_CpuLoadEntry = &Apm_CpuLoad.Type[Apm_Measurement.Entry[EntryId].Id]; \
    if(Delta > Amp_CpuLoadEntry->Max)                                                               \
    {                                                                                               \
        Amp_CpuLoadEntry->Max = Delta;                                                              \
    }                                                                                               \
    if(Delta < Amp_CpuLoadEntry->Min)                                                               \
    {                                                                                               \
        Amp_CpuLoadEntry->Min = Delta;                                                              \
    }                                                                                               \
    Amp_CpuLoadEntry->Total += Delta;                                                               \
    Amp_CpuLoadEntry->Occurrence++;

#define APM_SAVE_RUNNABLE_MEASUREMENT(Type, EntryId)                                                \
    Type ## Object * const Amp_CpuLoadEntry = &Apm_CpuLoad.Type[Apm_Measurement.Entry[EntryId].Id]; \
    Amp_CpuLoadEntry->InIsrTotal += IsrDelta;                                                       \
    if(Delta > Amp_CpuLoadEntry->Max)                                                               \
    {                                                                                               \
        Amp_CpuLoadEntry->Max = Delta;                                                              \
    }                                                                                               \
    if(Delta < Amp_CpuLoadEntry->Min)                                                               \
    {                                                                                               \
        Amp_CpuLoadEntry->Min = Delta;                                                              \
    }                                                                                               \
    Amp_CpuLoadEntry->Total += Delta;                                                               \
    Amp_CpuLoadEntry->Occurrence++;

#define APM_SAVE_RUNNABLE_PERIOD_MEASUREMENT(Type, EntryId)                                         \
    Type ## Object * const Amp_CpuLoadEntry = &Apm_CpuLoad.Type[Apm_Measurement.Entry[EntryId].Id]; \
    Amp_CpuLoadEntry->TotalPeriod += Delta;                                                         \
    if(Delta > Amp_CpuLoadEntry->PeriodMax)                                                         \
    {                                                                                               \
        Amp_CpuLoadEntry->PeriodMax = Delta;                                                        \
    }                                                                                               \
    if(Delta < Amp_CpuLoadEntry->PeriodMin)                                                         \
    {                                                                                               \
        Amp_CpuLoadEntry->PeriodMin = Delta;                                                        \
    }

#define APM_SAVE_CHECKPOINT_MEASUREMENT                         APM_SAVE_ISR_MEASUREMENT
#define APM_SAVE_CHECKPOINT_PERIOD_MEASUREMENT                  APM_SAVE_RUNNABLE_PERIOD_MEASUREMENT

#define APM_NO_CURRENT_ENTRY                                    (0xFFFFFFFFuL)
#define APM_ENTRY_INIT_ID                                       (0xFFu)
#define APM_MIN_STARTING_VALUE                                  (0xFFFFFFFFuL)

#define NONE                                                    (0u)
#define APM_RESERVED_ENTRY                                      (0u)
#define APM_STARTING_ENTRY                                      (1u)
#define APM_RESERVED_ENTRY_COUNT                                (1u)

#ifndef APM_ENABLE_ISR_MEASUREMENT
#undef APM_NUMBER_OF_ISRS
#define APM_NUMBER_OF_ISRS                                      APM_RESERVED_ENTRY_COUNT
#undef APM_ISR_MEASUREMENT_ENTRY_COUNT
#define APM_ISR_MEASUREMENT_ENTRY_COUNT                         NONE
#endif // APM_ENABLE_ISR_MEASUREMENT

#ifndef APM_ENABLE_RUNNABLE_MEASUREMENT
#undef APM_NUMBER_OF_RUNNABLES
#define APM_NUMBER_OF_RUNNABLES                                 APM_RESERVED_ENTRY_COUNT
#undef APM_RUNNABLES_MEASUREMENT_ENTRY_COUNT
#define APM_RUNNABLES_MEASUREMENT_ENTRY_COUNT                   NONE
#endif // APM_ENABLE_RUNNABLE_MEASUREMENT

#ifndef APM_ENABLE_CHECKPOINT_MEASUREMENT
#undef APM_NUMBER_OF_CHECKPOINTS
#define APM_NUMBER_OF_CHECKPOINTS                               APM_RESERVED_ENTRY_COUNT
#undef APM_CHECKPOINTS_MEASUREMENT_ENTRY_COUNT
#define APM_CHECKPOINTS_MEASUREMENT_ENTRY_COUNT                 NONE
#endif // APM_ENABLE_CHECKPOINT_MEASUREMENT

#ifndef APM_ENABLE_STARTUP_MARKERS
#undef APM_NUMBER_OF_STARTUP_MARKERS
#define APM_NUMBER_OF_STARTUP_MARKERS                           APM_RESERVED_ENTRY_COUNT
#endif // APM_ENABLE_STARTUP_MARKERS

#define APM_MEASUREMENT_ENTRY_COUNT                             (APM_TASK_MEASUREMENT_ENTRY_COUNT + \
                                                                    APM_ISR_MEASUREMENT_ENTRY_COUNT + \
                                                                    APM_RUNNABLES_MEASUREMENT_ENTRY_COUNT + \
                                                                    APM_CHECKPOINTS_MEASUREMENT_ENTRY_COUNT + \
                                                                    APM_RESERVED_ENTRY_COUNT)

#define APM_HOOKTYPE_NONE                                       (0u)
#define APM_HOOKTYPE_PRETASK                                    (1u)
#define APM_HOOKTYPE_POSTTASK                                   (2u)
#define APM_HOOKTYPE_PREISR                                     (3u)
#define APM_HOOKTYPE_POSTISR                                    (4u)
#define APM_HOOKTYPE_PRERUNNABLE                                (5u)
#define APM_HOOKTYPE_POSTRUNNABLE                               (6u)
#define APM_HOOKTYPE_PRECHECKPOINT                              (7u)
#define APM_HOOKTYPE_POSTCHECKPOINT                             (8u)

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/
typedef struct
{
    uint32 Timestamp;
    TaskStateType State;
    uint8 Id;
    uint8 Type;
} Apm_MeasurementEntryObject;

typedef struct
{
    Apm_MeasurementEntryObject Entry[APM_MEASUREMENT_ENTRY_COUNT];
    uint32 EntryIndex;
} Apm_MeasurementObject;

typedef struct
{
    // Task specific
    // Temporary Data regarding Task Preemption by another Task
    uint32 TaskPreemptionTimes[APM_NUMBER_OF_TASKS];
    // Temporary Data regarding time spent in Isr context while executing a Task
    uint32 IsrTaskTime;

    // Runnable specific
    // Temporary Data regarding the relation between Runnable and Task when preepmtion is happening
    uint32 TaskToRunnableMapper[APM_NUMBER_OF_TASKS];
    // Temporary Data regarding Runnable Preemption by another Task
    uint32 RunnablePreemptionTimes[APM_NUMBER_OF_RUNNABLES];
    uint32 RunnablePreemptionIsrTimes[APM_NUMBER_OF_RUNNABLES];
    // Temporary Data regarding time spent in Isr context while executing a Runnable
    uint32 IsrRunnableTime;
    // Temporary Data regarding the Runnable previous execution
    uint32 RunnablePreviousTimestamp[APM_NUMBER_OF_RUNNABLES];

    // Checkpoint specific
    // Temporary Data regarding the starting timestamps for Cyclic Custom Checkpoints
    uint32 CheckpointPreviousTimestamp[APM_NUMBER_OF_CHECKPOINTS];

    // Stack Measurement specific
    // Temporary Data regarding the sequence of Tasks/ISRs when measuring Stack usage
    uint32 TaskCounter;
} Apm_CpuLoadCalculationObject;

typedef struct
{
    uint32 Min;
    uint32 PreemptionMin;
    uint32 Max;
    uint32 PreemptionMax;
    uint32 InIsrTotal;
    uint32 Total;
    uint32 Occurrence;
    uint32 PreemptionOccurrence;
    uint32 StackUsage;
    uint32 CSmin;
    uint32 CSmax;
} Apm_TaskCpuLoadObject;

typedef struct
{
    uint32 Min;
    uint32 PeriodMin;
    uint32 Max;
    uint32 PeriodMax;
    uint32 Total;
    uint32 Occurrence;
    uint32 TotalPeriod;
} Apm_CheckpointCpuLoadObject;

typedef struct
{
    uint32 Min;
    uint32 Max;
    uint32 Total;
    uint32 Occurrence;
    uint32 StackUsage;
} Apm_IsrCpuLoadObject;

typedef struct
{
    uint32 Min;
    uint32 PeriodMin;
    uint32 Max;
    uint32 PeriodMax;
    uint32 InIsrTotal;
    uint32 Total;
    uint32 Occurrence;
    uint32 TotalPeriod;
} Apm_RunnableCpuLoadObject;

typedef struct
{
    Apm_TaskCpuLoadObject Apm_TaskCpuLoad[APM_NUMBER_OF_TASKS];
    Apm_IsrCpuLoadObject Apm_IsrCpuLoad[APM_NUMBER_OF_ISRS];
    Apm_RunnableCpuLoadObject Apm_RunnableCpuLoad[APM_NUMBER_OF_RUNNABLES];
    Apm_CheckpointCpuLoadObject Apm_CheckpointCpuLoad[APM_NUMBER_OF_CHECKPOINTS];
    uint32 Apm_StartupMarker[APM_NUMBER_OF_STARTUP_MARKERS];
    uint32 TotalTime;
} Apm_CpuLoadObject;

#ifdef APM_ENABLE_DEBUG
typedef struct
{
    // Shows how high the Measurement Entry Buffer can become during measurement
    uint32 MaxEntryIndex;
} Apm_DebugObject;
#endif

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
Apm_CpuLoadObject Apm_CpuLoad;

/*****************************************************************************
*                                 Locally used Variable Declarations         *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/
#define APM_MEASUREMENT_COLLECTION_ALLOCATION_START
#include "MemMap.h"

static Apm_MeasurementObject Apm_Measurement;

#define APM_MEASUREMENT_COLLECTION_ALLOCATION_END
#include "MemMap.h"

static Apm_CpuLoadCalculationObject CpuLoadCalculationData = {0};
static boolean MeasurementAllowed = FALSE;
static uint32 LastApmEntryIndex = 0uL;
static uint32 CSInstCnt = 0UL;
static uint32 CSEnterTime = 0ul;
static uint32 CSExitTime = 0ul;
static uint32 CSMaxTime = 0ul;
static boolean isISRCtx = FALSE;
#ifdef APM_ENABLE_DEBUG
static Apm_DebugObject Apm_Debug = {0};
#endif // APM_ENABLE_DEBUG

/*****************************************************************************
*                              Limited Scope Prototypes                      *
******************************************************************************/
/*============================================================================
**                              Task Specific
**==========================================================================*/
static void Apm_CalculateTaskCpuLoad (uint32 EntryPointIndex, uint32 ExitPointIndex);
/*============================================================================
**                              Isr Specific
**==========================================================================*/
static void Apm_CalculateIsrCpuLoad (uint32 EntryPointIndex, uint32 ExitPointIndex, uint32 TaskInProgress, uint32 RunnableInProgress);
/*============================================================================
**                              Runnable Specific
**==========================================================================*/
static void Apm_CalculateRunnableCpuLoad (uint32 EntryPointIndex, uint32 ExitPointIndex);
static void Apm_CalculateRunnablePreemption (uint32 EntryPointIndex, uint32 ExitPointIndex);
static void Apm_CalculateRunnablePeriod (uint32 EntryPointIndex);
/*============================================================================
**                             Checkpoint Specific
**==========================================================================*/
static void Apm_CalculateCheckpointCpuLoad (uint32 ExitPointIndex);
static void Apm_CalculateCheckpointPeriod (uint32 EntryPointIndex);
/*============================================================================
**                              Marker Specific
**==========================================================================*/

/*============================================================================
**                                  Common
**==========================================================================*/
static void Apm_SeekLastApmTaskEntry (void);
static void Apm_EntryInterpreter (void);
static void Apm_MeasurementInterpreter (void);
static void Apm_IncrementMeasurementCounter (void);
static inline void Apm_CpuLoadCalculationDataInit (void);
static inline void Apm_CpuLoadInit (void);
static inline void Apm_EntryInit (uint32 StartEntryIndex, uint32 EndEntryIndex);
static void Apm_InterpretedEntryClear (void);

/*****************************************************************************
*                              Local Functions                               *
******************************************************************************/

/*============================================================================
**                              Task Specific
**==========================================================================*/

/*============================================================================
**
** Function Name    :   Apm_CalculateTaskCpuLoad
**
** Visibility       :   Private
**
** Description      :   Function to calculate and save the Cpu_Load measured
**                      for a specific Task, between two Apm_Measurement Entries.
**
** Invocation       :
**
** Inputs           :   EntryPointIndex - Id of the Entry for the PreTask Hook
**                      ExitPointIndex - Id of the Entry for the PostTask Hook
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static void Apm_CalculateTaskCpuLoad (uint32 EntryPointIndex, uint32 ExitPointIndex)
{
    uint32 Delta = 0uL;
    uint32 DeltaTotal = 0uL;
    uint32 IsrDelta = 0uL;

    // Check if the Ids of both entries are the same
    if(Apm_Measurement.Entry[EntryPointIndex].Id == Apm_Measurement.Entry[ExitPointIndex].Id)
    {
        if((WAITING == Apm_Measurement.Entry[ExitPointIndex].State) || (SUSPENDED == Apm_Measurement.Entry[ExitPointIndex].State))
        {
            // Calculate Task duration and convert to us
            Delta = APM_TICKS_TO_US(Apm_Measurement.Entry[ExitPointIndex].Timestamp - Apm_Measurement.Entry[EntryPointIndex].Timestamp);

            // Calculate time spend in Isr context, already converted to us
            IsrDelta = CpuLoadCalculationData.IsrTaskTime;

            // Add previously calculated preemption times
            DeltaTotal = Delta + CpuLoadCalculationData.TaskPreemptionTimes[Apm_Measurement.Entry[ExitPointIndex].Id];

            // Save measurement
            // Apm_TaskCpuLoad.Total
            // Apm_TaskCpuLoad.InIsrTotal
            // Apm_TaskCpuLoad.Max
            // Apm_TaskCpuLoad.Min
            // Apm_TaskCpuLoad.Occurrence
            APM_SAVE_TASK_MEASUREMENT(Apm_TaskCpuLoad, ExitPointIndex)

            // Clean up
            CpuLoadCalculationData.IsrTaskTime = 0uL;
            CpuLoadCalculationData.TaskPreemptionTimes[Apm_Measurement.Entry[ExitPointIndex].Id] = 0uL;
        }
        else if(RUNNING == Apm_Measurement.Entry[ExitPointIndex].State)
        {
            // Task preemption handling
            // Calculate Task duration and convert to us
            Delta = APM_TICKS_TO_US(Apm_Measurement.Entry[ExitPointIndex].Timestamp - Apm_Measurement.Entry[EntryPointIndex].Timestamp);

            // Calculate time spend in Isr context, already converted to us
            IsrDelta = CpuLoadCalculationData.IsrTaskTime;

            // Save preemption times for later use
            CpuLoadCalculationData.TaskPreemptionTimes[Apm_Measurement.Entry[ExitPointIndex].Id] += Delta;

            // Save measurement
            // Apm_TaskCpuLoad.Total
            // Apm_TaskCpuLoad.InIsrTotal
            // Apm_TaskCpuLoad.PreemptionMax
            // Apm_TaskCpuLoad.PreemptionMin
            // Apm_TaskCpuLoad.PreemptionOccurrence
            APM_SAVE_TASK_PREEMPTION_MEASUREMENT(Apm_TaskCpuLoad, ExitPointIndex)

            // Clean up
            CpuLoadCalculationData.IsrTaskTime = 0uL;
        }
        else
        {
            // Should not be reached
        }
    }
}

/*============================================================================
**                              Isr Specific
**==========================================================================*/

/*============================================================================
**
** Function Name    :   Apm_CalculateIsrCpuLoad
**
** Visibility       :   Private
**
** Description      :   Function to calculate and save the Cpu_Load measured
**                      for a specific Isr, between two Apm_Measurement Entries.
**                      Used for calculating the time a Task or Runnable spends
**                      in Isrs.
**
** Invocation       :
**
** Inputs           :   EntryPointIndex - Id of the Entry for the PreTask Hook
**                      ExitPointIndex - Id of the Entry for the PostTask Hook
**                      TaskInProgress - Id of the Task that is currently being evaluated
**                      RunnableInProgress - Id of the Runnable that is currently being evaluated
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static void Apm_CalculateIsrCpuLoad (uint32 EntryPointIndex, uint32 ExitPointIndex, uint32 TaskInProgress, uint32 RunnableInProgress)
{
    uint32 Delta = 0uL;

    // Check if the Ids of both entries are the same
    if(Apm_Measurement.Entry[EntryPointIndex].Id == Apm_Measurement.Entry[ExitPointIndex].Id)
    {
        // Calculate Isr duration and convert to us
        Delta = APM_TICKS_TO_US(Apm_Measurement.Entry[ExitPointIndex].Timestamp - Apm_Measurement.Entry[EntryPointIndex].Timestamp);

        // If PostIsr is called between PreTask and PostTask, save time spent in Isr
        if(APM_NO_CURRENT_ENTRY != TaskInProgress)
        {
            CpuLoadCalculationData.IsrTaskTime += Delta;
        }

        // If PostIsr is called between PreRunnable and PostRunnable, save time spent in Isr
        if(APM_NO_CURRENT_ENTRY != RunnableInProgress)
        {
            CpuLoadCalculationData.IsrRunnableTime += Delta;
        }

        // Save measurement
        APM_SAVE_ISR_MEASUREMENT(Apm_IsrCpuLoad, ExitPointIndex)
    }
}

/*============================================================================
**                              Runnable Specific
**==========================================================================*/

/*============================================================================
**
** Function Name    :   Apm_CalculateRunnableCpuLoad
**
** Visibility       :   Private
**
** Description      :   Function to calculate and save the Cpu_Load measured
**                      for a specific Runnable, between two Apm_Measurement Entries.
**
** Invocation       :
**
** Inputs           :   EntryPointIndex - Id of the Entry for the PreRunnable/PreTask Hook
**                      ExitPointIndex - Id of the Entry for the PostRunnable Hook
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static void Apm_CalculateRunnableCpuLoad (uint32 EntryPointIndex, uint32 ExitPointIndex)
{
    uint32 Delta = 0uL;
    uint32 IsrDelta = 0uL;

    // Check if Entry point is Runnable or Task
    if(APM_HOOKTYPE_PRERUNNABLE == Apm_Measurement.Entry[EntryPointIndex].Type)
    {
        // Check if the Ids of both entries are the same
        if(Apm_Measurement.Entry[EntryPointIndex].Id == Apm_Measurement.Entry[ExitPointIndex].Id)
        {
            // Calculate Task duration and convert to us
            Delta = APM_TICKS_TO_US(Apm_Measurement.Entry[ExitPointIndex].Timestamp - Apm_Measurement.Entry[EntryPointIndex].Timestamp);

            // Calculate time spend in Isr context, already converted to us
            IsrDelta = CpuLoadCalculationData.IsrRunnableTime;

            // Save measurement
            APM_SAVE_RUNNABLE_MEASUREMENT(Apm_RunnableCpuLoad, ExitPointIndex)

            // Clean up
            CpuLoadCalculationData.IsrRunnableTime = 0uL;
        }
    }
    else
    {
        // Check if the Ids of the Preempted Entry and the current Entry is the same
        if(CpuLoadCalculationData.TaskToRunnableMapper[Apm_Measurement.Entry[EntryPointIndex].Id] == Apm_Measurement.Entry[ExitPointIndex].Id)
        {
            // Calculate Task duration and convert to us
            Delta = APM_TICKS_TO_US(Apm_Measurement.Entry[ExitPointIndex].Timestamp - Apm_Measurement.Entry[EntryPointIndex].Timestamp);

            // Calculate time spend in Isr context, already converted to us
            // Use Isr times from Task Preemption because the entry point in this case is actually the PreTask Hook
            IsrDelta = CpuLoadCalculationData.IsrTaskTime;

            // Save preemption times for later use
            Delta += CpuLoadCalculationData.RunnablePreemptionTimes[Apm_Measurement.Entry[ExitPointIndex].Id];
            IsrDelta += CpuLoadCalculationData.RunnablePreemptionIsrTimes[Apm_Measurement.Entry[ExitPointIndex].Id];

            // Save measurement
            APM_SAVE_RUNNABLE_MEASUREMENT(Apm_RunnableCpuLoad, ExitPointIndex)

            // Clean up
            // CpuLoadCalculationData.IsrTaskTime will be cleaned up by the PostTask handle
            CpuLoadCalculationData.TaskToRunnableMapper[Apm_Measurement.Entry[EntryPointIndex].Id] = APM_ENTRY_INIT_ID;
            CpuLoadCalculationData.RunnablePreemptionTimes[Apm_Measurement.Entry[ExitPointIndex].Id] = 0uL;
            CpuLoadCalculationData.RunnablePreemptionIsrTimes[Apm_Measurement.Entry[ExitPointIndex].Id] = 0uL;
        }
    }
}

/*============================================================================
**
** Function Name    :   Apm_CalculateRunnablePreemption
**
** Visibility       :   Private
**
** Description      :   Function to calculate and save the Preempted time measured
**                      for a specific Runnable, between two Apm_Measurement Entries.
**
** Invocation       :
**
** Inputs           :   EntryPointIndex - Id of the Entry for the PreRunnable/PreTask Hook
**                      ExitPointIndex - Id of the Entry for the PostTask Hook
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static void Apm_CalculateRunnablePreemption (uint32 EntryPointIndex, uint32 ExitPointIndex)
{
    uint32 Delta = 0uL;
    uint32 IsrDelta = 0uL;

    // If Entry point is Runnable, then the Task has been preempted before the Runnable has reached its Exit point
    if(APM_HOOKTYPE_PRERUNNABLE == Apm_Measurement.Entry[EntryPointIndex].Type)
    {
        // Map current Runnable to current Task Id for preemption handling
        CpuLoadCalculationData.TaskToRunnableMapper[Apm_Measurement.Entry[ExitPointIndex].Id] = Apm_Measurement.Entry[EntryPointIndex].Id;

        // Calculate Runnable duration based on Runnable Entry and Task Exit and convert to us
        Delta = APM_TICKS_TO_US(Apm_Measurement.Entry[ExitPointIndex].Timestamp - Apm_Measurement.Entry[EntryPointIndex].Timestamp);

        // Calculate time spend in Isr context, already converted to us
        IsrDelta = CpuLoadCalculationData.IsrRunnableTime;

        // Save preemption times for later use
        CpuLoadCalculationData.RunnablePreemptionTimes[Apm_Measurement.Entry[EntryPointIndex].Id] += Delta;
        CpuLoadCalculationData.RunnablePreemptionIsrTimes[Apm_Measurement.Entry[EntryPointIndex].Id] += IsrDelta;

        // Clean up
        CpuLoadCalculationData.IsrRunnableTime = 0uL;
    }
    else
    {
        // Check if Mapping between Runnable and Task is correct
        if(APM_ENTRY_INIT_ID != CpuLoadCalculationData.TaskToRunnableMapper[Apm_Measurement.Entry[ExitPointIndex].Id])
        {
            // Calculate Runnable duration based on Task Entry and Task Exit and convert to us
            Delta = APM_TICKS_TO_US(Apm_Measurement.Entry[ExitPointIndex].Timestamp - Apm_Measurement.Entry[EntryPointIndex].Timestamp);

            // Calculate time spend in Isr context, already converted to us
            IsrDelta = CpuLoadCalculationData.IsrTaskTime;

            // Save preemption times for later use
            CpuLoadCalculationData.RunnablePreemptionTimes[CpuLoadCalculationData.TaskToRunnableMapper[Apm_Measurement.Entry[ExitPointIndex].Id]] += Delta;
            CpuLoadCalculationData.RunnablePreemptionIsrTimes[CpuLoadCalculationData.TaskToRunnableMapper[Apm_Measurement.Entry[ExitPointIndex].Id]] += IsrDelta;

            // CpuLoadCalculationData.IsrTaskTime will be cleaned up by the PostTask handle
        }
    }
}

/*============================================================================
**
** Function Name    :   Apm_CalculateRunnablePeriod
**
** Visibility       :   Private
**
** Description      :   Function to calculate and save the period time measured
**                      for a specific Runnable.
**
** Invocation       :
**
** Inputs           :   EntryPointIndex - Id of the Entry for the PreRunnable Hook
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static void Apm_CalculateRunnablePeriod (uint32 EntryPointIndex)
{
    uint32 Delta = 0uL;

    // Check if the Runnable has not been executed for the first time
    if(0u != CpuLoadCalculationData.RunnablePreviousTimestamp[Apm_Measurement.Entry[EntryPointIndex].Id])
    {
        // Calculate Runnable period based on Runnable Entry current and previous timestamps and convert to us
        Delta = APM_TICKS_TO_US(Apm_Measurement.Entry[EntryPointIndex].Timestamp - CpuLoadCalculationData.RunnablePreviousTimestamp[Apm_Measurement.Entry[EntryPointIndex].Id]);

        // Save measurement
        APM_SAVE_RUNNABLE_PERIOD_MEASUREMENT(Apm_RunnableCpuLoad, EntryPointIndex)
    }

    // Save current timestamp for later use
    CpuLoadCalculationData.RunnablePreviousTimestamp[Apm_Measurement.Entry[EntryPointIndex].Id] = Apm_Measurement.Entry[EntryPointIndex].Timestamp;
}

/*============================================================================
**                              Checkpoint Specific
**==========================================================================*/

/*============================================================================
**
** Function Name    :   Apm_CalculateCheckpointCpuLoad
**
** Visibility       :   Private
**
** Description      :   Function to calculate and save the Cpu_Load measured
**                      for a specific Checkpoint, between two Apm_Measurement Entries.
**
** Invocation       :
**
** Inputs           :   ExitPointIndex - Id of the Entry for the PostCheckpoint Hook
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static void Apm_CalculateCheckpointCpuLoad (uint32 ExitPointIndex)
{
    uint32 Delta = 0uL;

    if(0uL != CpuLoadCalculationData.CheckpointPreviousTimestamp[Apm_Measurement.Entry[ExitPointIndex].Id])
    {
        // Calculate Checkpoint duration based on saved Checkpoint Start Timestamp and Checkpoint Exit Entry and convert to us
        Delta = APM_TICKS_TO_US(Apm_Measurement.Entry[ExitPointIndex].Timestamp - CpuLoadCalculationData.CheckpointPreviousTimestamp[Apm_Measurement.Entry[ExitPointIndex].Id]);

        // Save measurement
        APM_SAVE_CHECKPOINT_MEASUREMENT(Apm_CheckpointCpuLoad, ExitPointIndex)
    }
}

/*============================================================================
**
** Function Name    :   Apm_CalculateCheckpointPeriod
**
** Visibility       :   Private
**
** Description      :   Function to calculate and save the period time measured
**                      for a specific Checkpoint.
**
** Invocation       :
**
** Inputs           :   EntryPointIndex - Id of the Entry for the PreCheckpoint Hook
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static void Apm_CalculateCheckpointPeriod (uint32 EntryPointIndex)
{
    uint32 Delta = 0uL;

    // Check if the Checkpoint has not been executed for the first time
    if(0uL != CpuLoadCalculationData.CheckpointPreviousTimestamp[Apm_Measurement.Entry[EntryPointIndex].Id])
    {
        // Calculate Checkpoint period based on Checkpoint Entry current and previous timestamps and convert to us
        Delta = APM_TICKS_TO_US(Apm_Measurement.Entry[EntryPointIndex].Timestamp - CpuLoadCalculationData.CheckpointPreviousTimestamp[Apm_Measurement.Entry[EntryPointIndex].Id]);

        // Save measurement
        APM_SAVE_CHECKPOINT_PERIOD_MEASUREMENT(Apm_CheckpointCpuLoad, EntryPointIndex)
    }

    // Save current timestamp for later use
    CpuLoadCalculationData.CheckpointPreviousTimestamp[Apm_Measurement.Entry[EntryPointIndex].Id] = Apm_Measurement.Entry[EntryPointIndex].Timestamp;
}

/*============================================================================
**                                  Common
**==========================================================================*/

/*============================================================================
**
** Function Name    :   Apm_SeekLastApmTaskEntry
**
** Visibility       :   Private
**
** Description      :   Function to find the last PreTask Hook in the
**                      Apm_Measurement Entries that belongs to the Task where
**                      the Apm_MainFunction is being called.
**
** Invocation       :
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static void Apm_SeekLastApmTaskEntry (void)
{
    uint32 EntryIndex;

    for(EntryIndex = Apm_Measurement.EntryIndex - 1u; APM_RESERVED_ENTRY < EntryIndex; EntryIndex--)
    {
        if((APM_TASK_ID == Apm_Measurement.Entry[EntryIndex].Id) && (APM_HOOKTYPE_PRETASK == Apm_Measurement.Entry[EntryIndex].Type))
        {
            // Last Apm Task entry found, save index for later
            LastApmEntryIndex = EntryIndex;
            break;
        }
    }
}

/*============================================================================
**
** Function Name    :   Apm_IncrementMeasurementCounter
**
** Visibility       :   Private
**
** Description      :   Function for increasing the duration of the whole
**                      measurement once Apm_StartMeasurement has been called.
**
** Invocation       :
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static void Apm_IncrementMeasurementCounter (void)
{
    // Calculate difference between the whole measurement cycle, convert to us
    uint32 Delta = APM_TICKS_TO_US(Apm_Measurement.Entry[LastApmEntryIndex].Timestamp - Apm_Measurement.Entry[APM_STARTING_ENTRY].Timestamp);
    // Increase measurement duration time in us
    Apm_CpuLoad.TotalTime += Delta;
}

/*============================================================================
**
** Function Name    :   Apm_CpuLoadCalculationDataInit
**
** Visibility       :   Private
**
** Description      :   Helper function for initializing CpuLoadCalculationData
**                      stucture.
**
** Invocation       :
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static inline void Apm_CpuLoadCalculationDataInit (void)
{
    uint32 EntryIndex;

    for(EntryIndex = 0uL; APM_NUMBER_OF_TASKS > EntryIndex; EntryIndex++)
    {
        CpuLoadCalculationData.TaskToRunnableMapper[EntryIndex] = APM_ENTRY_INIT_ID;
    }
}

/*============================================================================
**
** Function Name    :   Apm_CpuLoadInit
**
** Visibility       :   Private
**
** Description      :   Helper function for initializing Apm_CpuLoad
**                      stucture.
**
** Invocation       :
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static inline void Apm_CpuLoadInit (void)
{
    uint32 EntryIndex;

    // Initialize Task calculations
    for(EntryIndex = 0uL; APM_NUMBER_OF_TASKS > EntryIndex; EntryIndex++)
    {
        Apm_TaskCpuLoadObject * const Amp_CpuLoadEntry = &Apm_CpuLoad.Apm_TaskCpuLoad[EntryIndex];

        Amp_CpuLoadEntry->Min = APM_MIN_STARTING_VALUE;
        Amp_CpuLoadEntry->PreemptionMin = APM_MIN_STARTING_VALUE;
        Amp_CpuLoadEntry->Max = 0uL;
        Amp_CpuLoadEntry->PreemptionMax = 0uL;
        Amp_CpuLoadEntry->InIsrTotal = 0uL;
        Amp_CpuLoadEntry->Total = 0uL;
        Amp_CpuLoadEntry->Occurrence = 0uL;
        Amp_CpuLoadEntry->PreemptionOccurrence = 0uL;
        Amp_CpuLoadEntry->StackUsage = 0uL;
        Amp_CpuLoadEntry->CSmin = APM_MIN_STARTING_VALUE; /* Initialized with Max Possible value, will be compared and updated to least measured value */
        Amp_CpuLoadEntry->CSmax = 0uL;
    }

    // Initialize Isr calculations
    for(EntryIndex = 0uL; APM_NUMBER_OF_ISRS > EntryIndex; EntryIndex++)
    {
        Apm_IsrCpuLoadObject * const Amp_CpuLoadEntry = &Apm_CpuLoad.Apm_IsrCpuLoad[EntryIndex];

        Amp_CpuLoadEntry->Min = APM_MIN_STARTING_VALUE;
        Amp_CpuLoadEntry->Max = 0uL;
        Amp_CpuLoadEntry->Total = 0uL;
        Amp_CpuLoadEntry->Occurrence = 0uL;
        Amp_CpuLoadEntry->StackUsage = 0uL;
    }

    // Initialize Runnables calculations
    for(EntryIndex = 0uL; APM_NUMBER_OF_RUNNABLES > EntryIndex; EntryIndex++)
    {
        Apm_RunnableCpuLoadObject * const Amp_CpuLoadEntry = &Apm_CpuLoad.Apm_RunnableCpuLoad[EntryIndex];

        Amp_CpuLoadEntry->Min = APM_MIN_STARTING_VALUE;
        Amp_CpuLoadEntry->PeriodMin = APM_MIN_STARTING_VALUE;
        Amp_CpuLoadEntry->Max = 0uL;
        Amp_CpuLoadEntry->PeriodMax = 0uL;
        Amp_CpuLoadEntry->InIsrTotal = 0uL;
        Amp_CpuLoadEntry->Total = 0uL;
        Amp_CpuLoadEntry->Occurrence = 0uL;
        Amp_CpuLoadEntry->TotalPeriod = 0uL;
    }

    // Initialize Checkpoint calculations
    for(EntryIndex = 0uL; APM_NUMBER_OF_CHECKPOINTS > EntryIndex; EntryIndex++)
    {
        Apm_CheckpointCpuLoadObject * const Amp_CpuLoadEntry = &Apm_CpuLoad.Apm_CheckpointCpuLoad[EntryIndex];

        Amp_CpuLoadEntry->Min = APM_MIN_STARTING_VALUE;
        Amp_CpuLoadEntry->PeriodMin = APM_MIN_STARTING_VALUE;
        Amp_CpuLoadEntry->Max = 0uL;
        Amp_CpuLoadEntry->PeriodMax = 0uL;
        Amp_CpuLoadEntry->Occurrence = 0uL;
        Amp_CpuLoadEntry->Total = 0uL;
    }

    // Initialize Startup Marker timestamps
    for(EntryIndex = 0uL; APM_NUMBER_OF_STARTUP_MARKERS > EntryIndex; EntryIndex++)
    {
        Apm_CpuLoad.Apm_StartupMarker[EntryIndex] = 0uL;
    }

    // Initialize measurement duration
    Apm_CpuLoad.TotalTime = 0uL;
}

/*============================================================================
**
** Function Name    :   Apm_EntryInit
**
** Visibility       :   Private
**
** Description      :   Helper function for initializing Apm_Measurement
**                      stucture.
**
** Invocation       :
**
** Inputs           :   StartEntryIndex - Starting point for initialization
**                      EndEntryIndex - End point for initialization
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static inline void Apm_EntryInit (uint32 StartEntryIndex, uint32 EndEntryIndex)
{
    uint32 EntryIndex;

    for(EntryIndex = StartEntryIndex; EndEntryIndex > EntryIndex; EntryIndex++)
    {
        Apm_MeasurementEntryObject * const Amp_MeasurementEntry = &Apm_Measurement.Entry[EntryIndex];

        Amp_MeasurementEntry->Timestamp = 0uL;
        Amp_MeasurementEntry->Id = APM_ENTRY_INIT_ID;
        Amp_MeasurementEntry->State = PRE_READY;
        Amp_MeasurementEntry->Type = APM_HOOKTYPE_NONE;
    }
}

/*============================================================================
**
** Function Name    :   Apm_InterpretedEntryClear
**
** Visibility       :   Private
**
** Description      :   Helper function for initializing Apm_Measurement
**                      stucture.
**
** Invocation       :
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static void Apm_InterpretedEntryClear (void)
{
    uint32 EntryIndex;
    uint32 EntriesToBeMoved = Apm_Measurement.EntryIndex - LastApmEntryIndex;

    // Copy all entries from including the last Apm Task PreHook entry to the start of the measurement buffer
    for(EntryIndex = 0; EntryIndex < EntriesToBeMoved; EntryIndex++)
    {
        Apm_Measurement.Entry[EntryIndex + APM_RESERVED_ENTRY_COUNT] = Apm_Measurement.Entry[EntryIndex + LastApmEntryIndex];
    }

    // Clear all the rest of the measurement entries
    Apm_EntryInit(EntriesToBeMoved + APM_RESERVED_ENTRY_COUNT, Apm_Measurement.EntryIndex);

#ifdef APM_ENABLE_DEBUG
    // Save how high the Measurement Entry Index might become during the course of the measurement duration
    if(Apm_Debug.MaxEntryIndex < Apm_Measurement.EntryIndex)
    {
        Apm_Debug.MaxEntryIndex = Apm_Measurement.EntryIndex;
    }
#endif // APM_ENABLE_DEBUG

    // Set the entry index to match the newly cleared entries
    Apm_Measurement.EntryIndex = EntriesToBeMoved + APM_RESERVED_ENTRY_COUNT;
}

/*============================================================================
**
** Function Name    :   Apm_EntryInterpreter
**
** Visibility       :   Private
**
** Description      :   Main function for Apm_Measurement Entry interpreting.
**                      Interprets the measurements and initiates the calculations
**                      for Tasks, Isrs and Runnables.
**
** Invocation       :
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static void Apm_EntryInterpreter (void)
{
    uint32 EntryIndex;
    uint32 CurrentIsrEntry = APM_NO_CURRENT_ENTRY;
    uint32 CurrentTaskEntry = APM_NO_CURRENT_ENTRY;
    uint32 CurrentRunnableEntry = APM_NO_CURRENT_ENTRY;

    // Start iterating through all the entries in order to interpret the measurements
    for(EntryIndex = APM_STARTING_ENTRY; EntryIndex < LastApmEntryIndex; EntryIndex++)
    {
        switch(Apm_Measurement.Entry[EntryIndex].Type)
        {
            case APM_HOOKTYPE_PRETASK:
                // Save Entry Index of PreTask for PostTask pair matching later
                CurrentTaskEntry = EntryIndex;
                break;
            case APM_HOOKTYPE_POSTTASK:
                // Runnable preemption handling, if Runnable measurement is enabled
                if(APM_NO_CURRENT_ENTRY != CurrentRunnableEntry)
                {
                    // If Task Preemption is detected while Runnable is measured in this calculation cycle
                    Apm_CalculateRunnablePreemption(CurrentRunnableEntry, EntryIndex);
                    // Clear currently saved Index of PreRunnable, so that is wont interfere with later Runnable interpretations
                    CurrentRunnableEntry = APM_NO_CURRENT_ENTRY;
                }
                else
                {
                    // If Task has been preempted multiple times while Runnable is still being measured
                    Apm_CalculateRunnablePreemption(CurrentTaskEntry, EntryIndex);
                }
                // Using the information from both the Entry and Exit point calculate Task load
                Apm_CalculateTaskCpuLoad(CurrentTaskEntry, EntryIndex);
                CurrentTaskEntry = APM_NO_CURRENT_ENTRY;
                break;
            case APM_HOOKTYPE_PREISR:
                // Save Entry Index of PreIsr for PostIsr pair matching later
                CurrentIsrEntry = EntryIndex;
                break;
            case APM_HOOKTYPE_POSTISR:
                // Using the information from both the Entry and Exit point calculate Isr load
                Apm_CalculateIsrCpuLoad(CurrentIsrEntry, EntryIndex, CurrentTaskEntry, CurrentRunnableEntry);
                CurrentIsrEntry = APM_NO_CURRENT_ENTRY;
                break;
            case APM_HOOKTYPE_PRERUNNABLE:
                // Calculate Runnable period
                Apm_CalculateRunnablePeriod(EntryIndex);
                // Save Entry Index of PreRunnable for PostRunnable pair matching later
                CurrentRunnableEntry = EntryIndex;
                break;
            case APM_HOOKTYPE_POSTRUNNABLE:
                // Using the information from both the Entry and Exit point calculate Runnable load
                if(APM_NO_CURRENT_ENTRY != CurrentRunnableEntry)
                {
                    // If the Runnable Exit point is reached within the same task as the Entry point
                    Apm_CalculateRunnableCpuLoad(CurrentRunnableEntry, EntryIndex);
                }
                else
                {
                    // If the Runnable Exit point is reached in a preempted Task later on
                    Apm_CalculateRunnableCpuLoad(CurrentTaskEntry, EntryIndex);
                }
                CurrentRunnableEntry = APM_NO_CURRENT_ENTRY;
                break;
            case APM_HOOKTYPE_PRECHECKPOINT:
                // Calculate Checkpoint period and save Entry timestamp
                Apm_CalculateCheckpointPeriod(EntryIndex);
                break;
            case APM_HOOKTYPE_POSTCHECKPOINT:
                // Using the information from the last saved Entry timestamp and Exit point calculate Checkpoint load
                Apm_CalculateCheckpointCpuLoad(EntryIndex);
                break;
            default:
                break;
        }
    }
}

/*============================================================================
**
** Function Name    :   Apm_SaveStackUsage
**
** Visibility       :   Private
**
** Description      :   This function updates the Stack used by Tasks and ISRs.
**
** Invocation       :
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static uint32 Current_TaskStackUsage[APM_NUMBER_OF_TASKS] = {0};

static void Apm_SaveStackUsage(void)
{
#ifdef APM_ENABLE_STACK_MEASUREMENT
    if(CpuLoadCalculationData.TaskCounter < APM_NUMBER_OF_TASKS)
    {
        // Task stack usage
        Current_TaskStackUsage[CpuLoadCalculationData.TaskCounter] = (uint32)APM_GET_TASKSTACK_USAGE((TaskType)(CpuLoadCalculationData.TaskCounter));
        if((Current_TaskStackUsage[CpuLoadCalculationData.TaskCounter]) > Apm_CpuLoad.Apm_TaskCpuLoad[CpuLoadCalculationData.TaskCounter].StackUsage)
        {
            Apm_CpuLoad.Apm_TaskCpuLoad[CpuLoadCalculationData.TaskCounter].StackUsage = Current_TaskStackUsage[CpuLoadCalculationData.TaskCounter];
        }
        // Increment counter
        CpuLoadCalculationData.TaskCounter++;
    }
# ifdef APM_ENABLE_ISR_MEASUREMENT
    else if(CpuLoadCalculationData.TaskCounter < (APM_NUMBER_OF_TASKS + APM_NUMBER_OF_ISRS))
    {
        // Isr stack usage
        Apm_CpuLoad.Apm_IsrCpuLoad[CpuLoadCalculationData.TaskCounter - APM_NUMBER_OF_TASKS].StackUsage = (uint32)APM_GET_ISRSTACK_USAGE((ISRType)(CpuLoadCalculationData.TaskCounter - APM_NUMBER_OF_TASKS));
        // Increment counter
        CpuLoadCalculationData.TaskCounter++;
    }
# endif // APM_ENABLE_ISR_MEASUREMENT
    else
    {
        // Reset counter
        CpuLoadCalculationData.TaskCounter = 0uL;
    }
#endif // APM_ENABLE_STACK_MEASUREMENT
}

/*============================================================================
**
** Function Name    :   Apm_MeasurementInterpreter
**
** Visibility       :   Private
**
** Description      :   This function follows the sequence of steps for Interpreting
**                      and then clearing the Apm_Measurements taken during the last
**                      execution cycle.
**
** Invocation       :
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
static void Apm_MeasurementInterpreter (void)
{
    Apm_EnterCriticalSection();

    Apm_SeekLastApmTaskEntry();
    Apm_EntryInterpreter();
    Apm_IncrementMeasurementCounter();
    Apm_InterpretedEntryClear();

    Apm_ExitCriticalSection();

    // Does not need to be in Critical Section
    Apm_SaveStackUsage();
}

/*****************************************************************************
*                             External Functions                             *
******************************************************************************/

/*============================================================================
**
** Function Name    :   Apm_Init
**
** Visibility       :   Public
**
** Description      :   The Init function is called to initialise the Global
**                      and Static variables of this module.
**
** Invocation       :
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void Apm_Init (void)
{
    // Init measurement entries
    Apm_EntryInit(APM_RESERVED_ENTRY, APM_MEASUREMENT_ENTRY_COUNT);
    Apm_Measurement.EntryIndex = APM_STARTING_ENTRY;

    // Init temporary data used for calculations
    Apm_CpuLoadCalculationDataInit();

    // Init calculated Cpu Load metrics
    Apm_CpuLoadInit();
}

/*============================================================================
**
** Function Name    :   Apm_StartMeasurement
**
** Visibility       :   Public
**
** Description      :   Function that allows the measurement data to be
**                      processed.
**
** Invocation       :
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void Apm_StartMeasurement (void)
{
    MeasurementAllowed = TRUE;
}

/*============================================================================
**
** Function Name    :   Apm_StopMeasurement
**
** Visibility       :   Public
**
** Description      :   Function that denies the measurement data to be
**                      processed.
**
** Invocation       :
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void Apm_StopMeasurement (void)
{
    MeasurementAllowed = FALSE;
}

/*============================================================================
**
** Function Name    :   Apm_PreTaskProcess
**
** Visibility       :   Public
**
** Description      :   This function signals the start of a Task.
**
** Invocation       :
**
** Inputs           :   TaskId - Id of the Task that is strating
**                      TaskState - State of the Task that is starting
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void Apm_PreTaskProcess (TaskType TaskId, TaskStateType TaskState)
{
    if(FALSE != MeasurementAllowed)
    {
        if(APM_MEASUREMENT_ENTRY_COUNT > Apm_Measurement.EntryIndex)
        {
            Apm_MeasurementEntryObject * const Amp_MeasurementEntry = &Apm_Measurement.Entry[Apm_Measurement.EntryIndex];
            Apm_Measurement.EntryIndex++;

            Amp_MeasurementEntry->Timestamp = APM_GET_CURRENT_TIME();
            Amp_MeasurementEntry->Id = TaskId;
            Amp_MeasurementEntry->State = TaskState;
            Amp_MeasurementEntry->Type = APM_HOOKTYPE_PRETASK;
        }
    }

}

/*============================================================================
**
** Function Name    :   Apm_PostTaskProcess
**
** Visibility       :   Public
**
** Description      :   This function signals the end of a Task.
**
** Invocation       :
**
** Inputs           :   TaskId - Id of the Task that is ending
**                      TaskState - State of the Task that is ending
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void Apm_PostTaskProcess (TaskType TaskId, TaskStateType TaskState)
{
    if(FALSE != MeasurementAllowed)
    {
        if(APM_MEASUREMENT_ENTRY_COUNT > Apm_Measurement.EntryIndex)
        {
            Apm_MeasurementEntryObject * const Amp_MeasurementEntry = &Apm_Measurement.Entry[Apm_Measurement.EntryIndex];
            Apm_Measurement.EntryIndex++;

            Amp_MeasurementEntry->Id = TaskId;
            Amp_MeasurementEntry->State = TaskState;
            Amp_MeasurementEntry->Type = APM_HOOKTYPE_POSTTASK;
            Amp_MeasurementEntry->Timestamp = APM_GET_CURRENT_TIME();
        }
    }
}

/*============================================================================
**
** Function Name    :   Apm_PreIsrProcess
**
** Visibility       :   Public
**
** Description      :   This function signals the start of an ISR.
**
** Invocation       :
**
** Inputs           :   x - Id of the ISR that is starting
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void Apm_PreIsrProcess (ISRType x)
{
#ifdef APM_ENABLE_ISR_MEASUREMENT
    if(MeasurementAllowed != FALSE)
    {
        isISRCtx = TRUE;
        if(APM_MEASUREMENT_ENTRY_COUNT > Apm_Measurement.EntryIndex)
        {
            Apm_MeasurementEntryObject * const Amp_MeasurementEntry = &Apm_Measurement.Entry[Apm_Measurement.EntryIndex];
            Apm_Measurement.EntryIndex++;

            Amp_MeasurementEntry->Timestamp = APM_GET_CURRENT_TIME();
            Amp_MeasurementEntry->Id = x;
            Amp_MeasurementEntry->Type = APM_HOOKTYPE_PREISR;
        }
    }
#endif // APM_ENABLE_ISR_MEASUREMENT
}

/*============================================================================
**
** Function Name    :   Apm_PostIsrProcess
**
** Visibility       :   Public
**
** Description      :   This function signals the end of an ISR.
**
** Invocation       :
**
** Inputs           :   x - Id of the ISR that is ending
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void Apm_PostIsrProcess (ISRType x)
{
#ifdef APM_ENABLE_ISR_MEASUREMENT
    if(FALSE != MeasurementAllowed)
    {
        if(APM_MEASUREMENT_ENTRY_COUNT > Apm_Measurement.EntryIndex)
        {
            Apm_MeasurementEntryObject * const Amp_MeasurementEntry = &Apm_Measurement.Entry[Apm_Measurement.EntryIndex];
            Apm_Measurement.EntryIndex++;

            Amp_MeasurementEntry->Id = x;
            Amp_MeasurementEntry->Type = APM_HOOKTYPE_POSTISR;
            Amp_MeasurementEntry->Timestamp = APM_GET_CURRENT_TIME();
        }
        isISRCtx = FALSE;
    }
#endif // APM_ENABLE_ISR_MEASUREMENT
}

/*============================================================================
**
** Function Name    :   Apm_PreRunnableProcess
**
** Visibility       :   Public
**
** Description      :   This function signals the start of a Runnable.
**
** Invocation       :
**
** Inputs           :   RunnableId - Id of the Runnable that is starting
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void Apm_PreRunnableProcess (uint8 RunnableId)
{
#ifdef APM_ENABLE_RUNNABLE_MEASUREMENT
    Apm_EnterCriticalSection();
    if(FALSE != MeasurementAllowed)
    {
        if(APM_MEASUREMENT_ENTRY_COUNT > Apm_Measurement.EntryIndex)
        {
            Apm_MeasurementEntryObject * const Amp_MeasurementEntry = &Apm_Measurement.Entry[Apm_Measurement.EntryIndex];
            Apm_Measurement.EntryIndex++;

            Amp_MeasurementEntry->Timestamp = APM_GET_CURRENT_TIME();
            Amp_MeasurementEntry->Id = RunnableId;
            Amp_MeasurementEntry->Type = APM_HOOKTYPE_PRERUNNABLE;
        }
    }
    Apm_ExitCriticalSection();
#endif // APM_ENABLE_RUNNABLE_MEASUREMENT
}

/*============================================================================
**
** Function Name    :   Apm_PostRunnableProcess
**
** Visibility       :   Public
**
** Description      :   This function signals the end of a Runnable.
**
** Invocation       :
**
** Inputs           :   RunnableId - Id of the Runnable that is ending
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void Apm_PostRunnableProcess (uint8 RunnableId)
{
#ifdef APM_ENABLE_RUNNABLE_MEASUREMENT
    Apm_EnterCriticalSection();
    if(FALSE != MeasurementAllowed)
    {
        if(APM_MEASUREMENT_ENTRY_COUNT > Apm_Measurement.EntryIndex)
        {
            Apm_MeasurementEntryObject * const Amp_MeasurementEntry = &Apm_Measurement.Entry[Apm_Measurement.EntryIndex];
            Apm_Measurement.EntryIndex++;

            Amp_MeasurementEntry->Id = RunnableId;
            Amp_MeasurementEntry->Type = APM_HOOKTYPE_POSTRUNNABLE;
            Amp_MeasurementEntry->Timestamp = APM_GET_CURRENT_TIME();
        }
    }
    Apm_ExitCriticalSection();
#endif // APM_ENABLE_RUNNABLE_MEASUREMENT
}

/*============================================================================
**
** Function Name    :   Apm_PreCheckpointProcess
**
** Visibility       :   Public
**
** Description      :   This function signals the start of a Cyclic Checkpoint.
**
** Invocation       :
**
** Inputs           :   CheckpointId - Id of the Checkpoint that is starting
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void Apm_PreCheckpointProcess (uint8 CheckpointId)
{
#ifdef APM_ENABLE_CHECKPOINT_MEASUREMENT
    Apm_EnterCriticalSection();
    if(FALSE != MeasurementAllowed)
    {
        if(APM_MEASUREMENT_ENTRY_COUNT > Apm_Measurement.EntryIndex)
        {
            Apm_MeasurementEntryObject * const Amp_MeasurementEntry = &Apm_Measurement.Entry[Apm_Measurement.EntryIndex];
            Apm_Measurement.EntryIndex++;

            Amp_MeasurementEntry->Timestamp = APM_GET_CURRENT_TIME();
            Amp_MeasurementEntry->Id = CheckpointId;
            Amp_MeasurementEntry->Type = APM_HOOKTYPE_PRECHECKPOINT;
        }
    }
    Apm_ExitCriticalSection();
#endif // APM_ENABLE_CHECKPOINT_MEASUREMENT
}

/*============================================================================
**
** Function Name    :   Apm_PostCheckpointProcess
**
** Visibility       :   Public
**
** Description      :   This function signals the end of a Cyclic Checkpoint.
**
** Invocation       :
**
** Inputs           :   CheckpointId - Id of the Checkpoint that is ending
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void Apm_PostCheckpointProcess (uint8 CheckpointId)
{
#ifdef APM_ENABLE_CHECKPOINT_MEASUREMENT
    Apm_EnterCriticalSection();
    if(FALSE != MeasurementAllowed)
    {
        if(APM_MEASUREMENT_ENTRY_COUNT > Apm_Measurement.EntryIndex)
        {
            Apm_MeasurementEntryObject * const Amp_MeasurementEntry = &Apm_Measurement.Entry[Apm_Measurement.EntryIndex];
            Apm_Measurement.EntryIndex++;

            Amp_MeasurementEntry->Id = CheckpointId;
            Amp_MeasurementEntry->Type = APM_HOOKTYPE_POSTCHECKPOINT;
            Amp_MeasurementEntry->Timestamp = APM_GET_CURRENT_TIME();
        }
    }
    Apm_ExitCriticalSection();
#endif // APM_ENABLE_CHECKPOINT_MEASUREMENT
}

/*============================================================================
**
** Function Name    :   Apm_SaveStartupMarker
**
** Visibility       :   Public
**
** Description      :   This function signals the reaching of a Marker.
**                      Save a timestamp on reaching a certain point.
**
** Invocation       :
**
** Inputs           :   MarkerId - Id of the Marker that is being reached
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void Apm_SaveStartupMarker (uint8 MarkerId)
{
#ifdef APM_ENABLE_STARTUP_MARKERS
    Apm_EnterCriticalSection();
    if(FALSE != MeasurementAllowed)
    {
        if(0uL == Apm_CpuLoad.Apm_StartupMarker[MarkerId])
        {
            Apm_CpuLoad.Apm_StartupMarker[MarkerId] = APM_GET_CURRENT_TIME();
        }
    }
    Apm_ExitCriticalSection();
#endif // APM_ENABLE_STARTUP_MARKERS
}


/**
 ** @brief Stores the TimeStamp on Entering the Critical Section
 ** 
 */
void Apm_StartCSMeasurement()
{
#ifdef APM_ENABLE_CRITICALSECTION_MEASUREMENT
    if((CSInstCnt == 0) && (FALSE == isISRCtx))
    {
        CSEnterTime =  APM_GET_CURRENT_TIME();
        CSInstCnt++;
    }
    else if(CSInstCnt > 0)
    {
        CSInstCnt++;
    }
    else
    {
        /* Do Nothing: Critcal Section was entered from ISR, Hence no need to take reading */
    }
#endif
}

/**
 ** @brief  Updates the Task Measurement Object with Max and Min time spent in CS section 
 ** 
 */
void Apm_EndCSMeasurement()
{
#ifdef APM_ENABLE_CRITICALSECTION_MEASUREMENT
    if((CSInstCnt == 1))
    {
        uint32 CSTime = 0ul; /* time spent in CS in 0.1us */
        TaskType TaskID = INVALID_TASK;

        CSExitTime = APM_GET_CURRENT_TIME();

        CSTime = (CSExitTime - CSEnterTime)/(APM_GPT_FREQ_IN_MHZ/10);

        (void)GetTaskID(&TaskID);


        if(INVALID_TASK != TaskID)
        {
            if(CSTime > CSMaxTime)
            {
                CSMaxTime = CSTime;

            }
            Apm_TaskCpuLoadObject * const pApm_TaskCpuLoad = &Apm_CpuLoad.Apm_TaskCpuLoad[TaskID];

            if(CSTime < pApm_TaskCpuLoad->CSmin)
            {
                pApm_TaskCpuLoad->CSmin = CSTime;

            }
            if(CSTime > pApm_TaskCpuLoad->CSmax)
            {
                pApm_TaskCpuLoad->CSmax = CSTime;
            }

        }

        CSInstCnt--;
    }
    else if(CSInstCnt > 1)
    {
        CSInstCnt--;
    }
    else
    {
        /* Do Nothing: Critcal Section was entered from ISR, Hence no need to take reading */
    }
#endif

}
/*============================================================================
**
** Function Name    :   Apm_MainFunction
**
** Visibility       :   Public
**
** Description      :   This function periodically calculates the CPU load.
**
** Invocation       :
**
** Inputs           :   None
**
** Outputs          :   None
**
** Critical Section :
**
**==========================================================================*/
void Apm_MainFunction (void)
{
    if(TRUE == MeasurementAllowed)
    {
        Apm_MeasurementInterpreter();
    }
    else
    {
        // If measurment is not allowed yet, clear all the entries and start the index from the begining
        Apm_EntryInit(APM_STARTING_ENTRY, Apm_Measurement.EntryIndex);
        Apm_Measurement.EntryIndex = APM_STARTING_ENTRY;
    }
}

#endif /* APM_ENABLED */
#define APM_CONST_SEC_END
 #include "MemMap.h"

#define APM_DATA_SEC_END
 #include "MemMap.h"

#define APM_CODE_SEC_END
 #include "MemMap.h"
#endif
/*============================================================================
**============================================================================
** R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
**===========================================================================*/
/*---------------------------------------------------------------------------
Date               : 23-Feb-2016
CDSID              : ssebast1
Traceability       : RTC #527207
Change Description : Initial Framework version of Apm
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 26-Feb-2016
CDSID              : ssebast1
Traceability       : RTC #527207
Change Description : Implementation of Task and CPU Load Measurement
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 06-Jun-2016
CDSID              : ssebast1
Traceability       : RTC #563852
Change Description : Implementation of Runnables measurements with nested
                     measurement support.
-----------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
Date               : 08-Sep-2021
CDSID              : praj1
Traceability       : 1453449
Change Description : Bucket data moved to no-init RAM.
-----------------------------------------------------------------------------*/
/* end of file =============================================================*/
