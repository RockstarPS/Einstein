from ctypes import *
import xlsxwriter
from xlsxwriter.utility import *
# Import Tasks, ISRs, Runnables... configuration
from config import *
import sys

# Get memory dump file name from argument
arguments = sys.argv

# Decision-making logic regarding binary dump interpretation and Excel sheets available
# Tasks are mandatory, there is no check here
TASK_COUNT = len(TASKS)
# Check for configured ISRs
if ISRS:
    showISRs = True
    ISR_COUNT = len(ISRS)
else:
    showISRs = False
    ISR_COUNT = 1
# Check for configured Runnables
if RUNNABLES:
    showRunnables = True
    RUNNABLE_COUNT = len(RUNNABLES)
else:
    showRunnables = False
    RUNNABLE_COUNT = 1
# Check for configured Checkpoints
if CHECKPOINTS:
    showCheckpoints = True
    CHECKPOINT_COUNT = len(CHECKPOINTS)
else:
    showCheckpoints = False
    CHECKPOINT_COUNT = 1
# Check for configured Markers
if MARKERS:
    showMarkers = True
    MARKER_COUNT = len(MARKERS)
else:
    showMarkers = False
    MARKER_COUNT = 1

# Excel sheets headers hardcoded descriptions
TASK_HEADER = ["Task Name", "Duration Min [us]", "Duration Max [us]", "Preemption Min [us]", "Preemption Max [us]", "Occurrence", "Preemption Occurrence", "Stack Usage",
               "Duration Total [us]", "Spent in ISR [us]", "CpuLoad [%]", "Duration Average [us]", "CS Min [0.1us]", "CS Max [0.1us]"]
ISR_HEADER = ["ISR Name", "Duration Min [us]", "Duration Max [us]", "Occurrence", "Stack Usage", "Duration Total [us]", "Duration Average [us]"]
RUNNABLE_HEADER = ["Runnable Name", "Duration Min [us]", "Duration Max [us]", "Period Min [us]", "Period Max [us]", "Occurrence", "Duration Total [us]", "Spent in ISR [us]", "CpuLoad [%]", "Duration Average [us]", "Period Total [us]", "Average Period [ms]"]
CHECKPOINT_HEADER = ["Checkpoint Name", "Duration Min [us]", "Duration Max [us]", "Period Min [us]", "Period Max [us]", "Occurrence", "Duration Total [us]", "Duration Average [us]"]
MARKER_HEADER = ["Marker Name", "Timestamp [ticks]"]

# Excel sheet headers hardcoded Comment descriptions
TASK_HEADER_COMMENTS = ["Name of the measured Task", "Minimum duration for this Task to reach SUSPENDED/WAITING state in microseconds", "Maximum duration for this Task to reach SUSPENDED/WAITING state in microseconds",
                        "Minimum time spent inside Task before being preempted in microseconds", "Maximum time spent inside Task before being preempted in microseconds",
                        "Number of times this Task has reached SUSPENDED/WAITING state", "Number of times this Task has been preempted", "Maximum Stack usage reached in bytes", "Total time spent inside this Task in microseconds",
                        "Total time spent in Interrupt context while in this Task in microseconds", "CPU Load percentage of Task based on measurement duration",
                        "Average duration for this Task to reach SUSPENDED/WAITING state in microseconds", "min Time Spent in Critical Section 0.1 microseconds", "max Time Spent in Critical Section in 0.1 microseconds"]
ISR_HEADER_COMMENTS = ["Name of the measured Interrupt", "Minimum duration for this Interrupt in microseconds", "Maximum duration for this Interrupt in microseconds",
                        "Number of times this Interrupt has been executed", "Maximum Stack usage reached in bytes", "Total time spent inside this Interrupt in microseconds",
                        "Average duration for this Interrupt in microseconds"]
RUNNABLE_HEADER_COMMENTS = ["Name of the measured Runnable", "Minimum duration for this Runnable in microseconds", "Maximum duration for this Runnable in microseconds", "Minimum time spent between two executions of this Runnable",
                            "Maximum time spent between two executions of this Runnable", "Number of times this Runnable has been executed", "Total time spent inside this Runnable in microseconds",
                            "Total time spent in Interrupt context while in this Runnable in microseconds", "CPU Load percentage of Runnable based on measurement duration",
                            "Average duration for this Runnable in microseconds", "Total Period for this Runnable", "Average Period for this Runnable"]
CHECKPOINT_HEADER_COMMENTS = ["Name of the measured Checkpoint", "Minimum absolute time for this Checkpoint from start to end in microseconds",
                              "Maximum absolute time for this Checkpoint from start to end in microseconds", "Minimum time spent between two executions of this Checkpoint",
                              "Maximum time spent between two executions of this Checkpoint", "Number of times this Checkpoint has been executed", "Total time of all durations gathered for this Checkpoint in microseconds",
                              "Average duration for this Checkpoint in microseconds"]
MARKER_HEADER_COMMENTS = ["Name of the Start-up Marker", "Timestamp when the location where the Marker has been placed is reached"]

# Apm_CpuLoad structure within C code, used for binary dump interpretation
class Apm_TaskCpuLoadObject(Structure):
    _fields_ = [ 
        ('Min',                     c_uint),
        ('PreemptionMin',           c_uint),
        ('Max',                     c_uint),            
        ('PreemptionMax',           c_uint),
        ('InIsrTotal',              c_uint),
        ('Total',                   c_uint),
        ('Occurrence',              c_uint),
        ('PreemptionOccurrence',    c_uint),
        ('StackUsage',              c_uint),
        ('CSmin',                   c_uint),
        ('CSmax',                   c_uint),
    ]

class Apm_IsrCpuLoadObject(Structure):
    _fields_ = [ 
        ('Min',                     c_uint),
        ('Max',                     c_uint),
        ('Total',                   c_uint),
        ('Occurrence',              c_uint),
        ('StackUsage',              c_uint)
    ]

class Apm_RunnableCpuLoadObject(Structure):
    _fields_ = [ 
        ('Min',                     c_uint),
        ('PeriodMin',               c_uint),
        ('Max',                     c_uint),            
        ('PeriodMax',               c_uint),
        ('InIsrTotal',              c_uint),
        ('Total',                   c_uint),
        ('Occurrence',              c_uint),
        ('TotalPeriod',              c_uint),
    ]

class Apm_CheckpointCpuLoadObject(Structure):
    _fields_ = [ 
        ('Min',                     c_uint),
        ('PeriodMin',               c_uint),
        ('Max',                     c_uint),            
        ('PeriodMax',               c_uint),
        ('Total',                   c_uint),
        ('Occurrence',              c_uint),
        ('TotalPeriod',             c_uint),
    ]

class Apm_CpuLoadObject(Structure):
    _fields_ = [ 
        ('Apm_TaskCpuLoad',         Apm_TaskCpuLoadObject * TASK_COUNT),
        ('Apm_IsrCpuLoad',          Apm_IsrCpuLoadObject * ISR_COUNT), 
        ('Apm_RunnableCpuLoad',     Apm_RunnableCpuLoadObject * RUNNABLE_COUNT),
        ("Apm_CheckpointCpuLoad",   Apm_CheckpointCpuLoadObject * CHECKPOINT_COUNT),
        ("Apm_StartupMarker",       c_uint * MARKER_COUNT),
        ("TotalTime",               c_uint)
    ]

# Insert binary dump into C structure
Apm_CpuLoad=Apm_CpuLoadObject()
binFileData = open(arguments[1], "rb")
binFileData.readinto(Apm_CpuLoad)
binFileData.close()

# Create Metrics Excel
workbook = xlsxwriter.Workbook('APM Measurement Report.xlsx')

# Create Formatting for Excel cells
# Percentage
percentageFormat = workbook.add_format({'num_format': '##0.00'})

#############################################################################
# Create Task Worksheet
tasksheet = workbook.add_worksheet('Task Metrics')

# Fill Task Worksheet with Task Header information, Set Column Length and write description Comments 
for col_num, data in enumerate(TASK_HEADER):
    tasksheet.write(0, col_num, data)
    tasksheet.set_column(col_num, col_num, len(str(data)))
    tasksheet.write_comment(0, col_num, TASK_HEADER_COMMENTS[col_num])
# Fill Task Worksheet with Measurement Information
for row_num in range(1, TASK_COUNT+1):
    tasksheet.write(row_num, TASK_HEADER.index("Task Name"), TASKS[row_num-1])
    tasksheet.write(row_num, TASK_HEADER.index("Duration Min [us]"), Apm_CpuLoad.Apm_TaskCpuLoad[row_num-1].Min)
    tasksheet.write(row_num, TASK_HEADER.index("Duration Max [us]"), Apm_CpuLoad.Apm_TaskCpuLoad[row_num-1].Max)
    tasksheet.write(row_num, TASK_HEADER.index("Preemption Min [us]"), Apm_CpuLoad.Apm_TaskCpuLoad[row_num-1].PreemptionMin)
    tasksheet.write(row_num, TASK_HEADER.index("Preemption Max [us]"), Apm_CpuLoad.Apm_TaskCpuLoad[row_num-1].PreemptionMax)
    tasksheet.write(row_num, TASK_HEADER.index("Occurrence"), Apm_CpuLoad.Apm_TaskCpuLoad[row_num-1].Occurrence)
    tasksheet.write(row_num, TASK_HEADER.index("Preemption Occurrence"), Apm_CpuLoad.Apm_TaskCpuLoad[row_num-1].PreemptionOccurrence)
    tasksheet.write(row_num, TASK_HEADER.index("Stack Usage"), Apm_CpuLoad.Apm_TaskCpuLoad[row_num-1].StackUsage)
    tasksheet.write(row_num, TASK_HEADER.index("Duration Total [us]"), Apm_CpuLoad.Apm_TaskCpuLoad[row_num-1].Total)
    tasksheet.write(row_num, TASK_HEADER.index("Spent in ISR [us]"), Apm_CpuLoad.Apm_TaskCpuLoad[row_num-1].InIsrTotal)
    tasksheet.write(row_num, TASK_HEADER.index("CS Min [0.1us]"), Apm_CpuLoad.Apm_TaskCpuLoad[row_num-1].CSmin)
    tasksheet.write(row_num, TASK_HEADER.index("CS Max [0.1us]"), Apm_CpuLoad.Apm_TaskCpuLoad[row_num-1].CSmax)
# Fill Additional descriptions and Total Measurement Duration
tasksheet.write(TASK_COUNT+1, TASK_HEADER.index("Stack Usage"), "Sum:")
tasksheet.write(TASK_COUNT+2, TASK_HEADER.index("Stack Usage"), "Measurement Total:")
tasksheet.write(TASK_COUNT+2, TASK_HEADER.index("Duration Total [us]"), Apm_CpuLoad.TotalTime)
# Fill Task Worksheet with Measurement formulas
# Sum Total column formula
totalsumloc = xl_rowcol_to_cell(TASK_COUNT+1, TASK_HEADER.index("Duration Total [us]"))
totalsumfor = xl_range(1, TASK_HEADER.index("Duration Total [us]"), TASK_COUNT, TASK_HEADER.index("Duration Total [us]"))
tasksheet.write_formula(totalsumloc, '{=SUM(' + totalsumfor + ')}')
# Sum Spent in ISR column formula
spentisrsumloc = xl_rowcol_to_cell(TASK_COUNT+1, TASK_HEADER.index("Spent in ISR [us]"))
spentisrsumfor = xl_range(1, TASK_HEADER.index("Spent in ISR [us]"), TASK_COUNT, TASK_HEADER.index("Spent in ISR [us]"))
tasksheet.write_formula(spentisrsumloc, '{=SUM(' + spentisrsumfor + ')}')
# Cpu Load % formula
totaltimeloc = xl_rowcol_to_cell(TASK_COUNT+2, TASK_HEADER.index("Duration Total [us]"))
for row_num in range(1, TASK_COUNT+1):
    cpuloadperloc = xl_rowcol_to_cell(row_num, TASK_HEADER.index("CpuLoad [%]"))
    cpuloadperfor = xl_rowcol_to_cell(row_num, TASK_HEADER.index("Duration Total [us]"))
    tasksheet.write_formula(cpuloadperloc, '{=(('+cpuloadperfor+'/'+totaltimeloc+')*100)}', percentageFormat)
# Sum Cpu Load column formula
cpuloadsumloc = xl_rowcol_to_cell(TASK_COUNT+1, TASK_HEADER.index("CpuLoad [%]"))
cpuloadsumfor = xl_range(1, TASK_HEADER.index("CpuLoad [%]"), TASK_COUNT, TASK_HEADER.index("CpuLoad [%]"))
tasksheet.write_formula(cpuloadsumloc, '{=SUM('+cpuloadsumfor+')}', percentageFormat)
# Average formula
for row_num in range(1, TASK_COUNT+1):
    averageloc = xl_rowcol_to_cell(row_num, TASK_HEADER.index("Duration Average [us]"))
    occurenceloc = xl_rowcol_to_cell(row_num, TASK_HEADER.index("Occurrence"))
    totalloc = xl_rowcol_to_cell(row_num, TASK_HEADER.index("Duration Total [us]"))
    tasksheet.write_formula(averageloc, '{=('+totalloc+'/'+occurenceloc+')}')

##############################################################################
if showISRs:
    # Create ISR Worksheet
    isrsheet = workbook.add_worksheet('ISR Metrics')

    # Fill ISR Worksheet with ISR Header information, Set Column Length and write description Comments 
    for col_num, data in enumerate(ISR_HEADER):
        isrsheet.write(0, col_num, data)
        isrsheet.set_column(col_num, col_num, len(str(data)))
        isrsheet.write_comment(0, col_num, ISR_HEADER_COMMENTS[col_num])
    # Fill ISR Worksheet with Measurement Information
    for row_num in range(1, ISR_COUNT+1):
        isrsheet.write(row_num, ISR_HEADER.index("ISR Name"), ISRS[row_num-1])
        isrsheet.write(row_num, ISR_HEADER.index("Duration Min [us]"), Apm_CpuLoad.Apm_IsrCpuLoad[row_num-1].Min)
        isrsheet.write(row_num, ISR_HEADER.index("Duration Max [us]"), Apm_CpuLoad.Apm_IsrCpuLoad[row_num-1].Max)
        isrsheet.write(row_num, ISR_HEADER.index("Occurrence"), Apm_CpuLoad.Apm_IsrCpuLoad[row_num-1].Occurrence)
        isrsheet.write(row_num, ISR_HEADER.index("Stack Usage"), Apm_CpuLoad.Apm_IsrCpuLoad[row_num-1].StackUsage)
        isrsheet.write(row_num, ISR_HEADER.index("Duration Total [us]"), Apm_CpuLoad.Apm_IsrCpuLoad[row_num-1].Total)
    # Fill Additional descriptions
    isrsheet.write(ISR_COUNT+1, ISR_HEADER.index("Stack Usage"), "Sum:")
    # Fill ISR Worksheet with Measurement formulas
    # Sum Total column formula
    totalsumloc = xl_rowcol_to_cell(ISR_COUNT+1, ISR_HEADER.index("Duration Total [us]"))
    totalsumfor = xl_range(1, ISR_HEADER.index("Duration Total [us]"), ISR_COUNT, ISR_HEADER.index("Duration Total [us]"))
    isrsheet.write_formula(totalsumloc, '{=SUM(' + totalsumfor + ')}')
    # Average formula
    for row_num in range(1, ISR_COUNT+1):
        averageloc = xl_rowcol_to_cell(row_num, ISR_HEADER.index("Duration Average [us]"))
        occurenceloc = xl_rowcol_to_cell(row_num, ISR_HEADER.index("Occurrence"))
        totalloc = xl_rowcol_to_cell(row_num, ISR_HEADER.index("Duration Total [us]"))
        isrsheet.write_formula(averageloc, '{=('+totalloc+'/'+occurenceloc+')}')

##############################################################################
if showRunnables:
    # Create Runnable Worksheet
    runnablesheet = workbook.add_worksheet('Runnable Metrics')

    # Fill Runnable Worksheet with Runnable Header information, Set Column Length and write description Comments 
    for col_num, data in enumerate(RUNNABLE_HEADER):
        runnablesheet.write(0, col_num, data)
        runnablesheet.set_column(col_num, col_num, len(str(data)))
        runnablesheet.write_comment(0, col_num, RUNNABLE_HEADER_COMMENTS[col_num])
    # Fill Runnable Worksheet with Measurement Information
    for row_num in range(1, RUNNABLE_COUNT+1):
        runnablesheet.write(row_num, RUNNABLE_HEADER.index("Runnable Name"), RUNNABLES[row_num-1])
        runnablesheet.write(row_num, RUNNABLE_HEADER.index("Duration Min [us]"), Apm_CpuLoad.Apm_RunnableCpuLoad[row_num-1].Min)
        runnablesheet.write(row_num, RUNNABLE_HEADER.index("Duration Max [us]"), Apm_CpuLoad.Apm_RunnableCpuLoad[row_num-1].Max)
        runnablesheet.write(row_num, RUNNABLE_HEADER.index("Period Min [us]"), Apm_CpuLoad.Apm_RunnableCpuLoad[row_num-1].PeriodMin)
        runnablesheet.write(row_num, RUNNABLE_HEADER.index("Period Max [us]"), Apm_CpuLoad.Apm_RunnableCpuLoad[row_num-1].PeriodMax)
        runnablesheet.write(row_num, RUNNABLE_HEADER.index("Occurrence"), Apm_CpuLoad.Apm_RunnableCpuLoad[row_num-1].Occurrence)
        runnablesheet.write(row_num, RUNNABLE_HEADER.index("Duration Total [us]"), Apm_CpuLoad.Apm_RunnableCpuLoad[row_num-1].Total)
        runnablesheet.write(row_num, RUNNABLE_HEADER.index("Spent in ISR [us]"), Apm_CpuLoad.Apm_RunnableCpuLoad[row_num-1].InIsrTotal)
        runnablesheet.write(row_num, RUNNABLE_HEADER.index("Period Total [us]"), Apm_CpuLoad.Apm_RunnableCpuLoad[row_num-1].TotalPeriod)
        try:
            runnablesheet.write(row_num, RUNNABLE_HEADER.index("Average Period [ms]"), (Apm_CpuLoad.Apm_RunnableCpuLoad[row_num-1].TotalPeriod/Apm_CpuLoad.Apm_RunnableCpuLoad[row_num-1].Occurrence/1000))
        except:
           runnablesheet.write(row_num, RUNNABLE_HEADER.index("Average Period [ms]"), (0)) 

    # Fill Additional descriptions and Total Measurement Duration
    runnablesheet.write(RUNNABLE_COUNT+1, RUNNABLE_HEADER.index("Occurrence"), "Sum:")
    runnablesheet.write(RUNNABLE_COUNT+2, RUNNABLE_HEADER.index("Occurrence"), "Measurement Total:")
    runnablesheet.write(RUNNABLE_COUNT+2, RUNNABLE_HEADER.index("Duration Total [us]"), Apm_CpuLoad.TotalTime)
    # Fill Runnable Worksheet with Measurement formulas
    # Sum Total column formula
    totalsumloc = xl_rowcol_to_cell(RUNNABLE_COUNT+1, RUNNABLE_HEADER.index("Duration Total [us]"))
    totalsumfor = xl_range(1, RUNNABLE_HEADER.index("Duration Total [us]"), RUNNABLE_COUNT, RUNNABLE_HEADER.index("Duration Total [us]"))
    runnablesheet.write_formula(totalsumloc, '{=SUM(' + totalsumfor + ')}')
    # Sum Spent in ISR column formula
    spentisrsumloc = xl_rowcol_to_cell(RUNNABLE_COUNT+1, RUNNABLE_HEADER.index("Spent in ISR [us]"))
    spentisrsumfor = xl_range(1, RUNNABLE_HEADER.index("Spent in ISR [us]"), RUNNABLE_COUNT, RUNNABLE_HEADER.index("Spent in ISR [us]"))
    runnablesheet.write_formula(spentisrsumloc, '{=SUM(' + spentisrsumfor + ')}')
    # Cpu Load % formula
    totaltimeloc = xl_rowcol_to_cell(RUNNABLE_COUNT+2, RUNNABLE_HEADER.index("Duration Total [us]"))
    for row_num in range(1, RUNNABLE_COUNT+1):
        cpuloadperloc = xl_rowcol_to_cell(row_num, RUNNABLE_HEADER.index("CpuLoad [%]"))
        cpuloadperfor = xl_rowcol_to_cell(row_num, RUNNABLE_HEADER.index("Duration Total [us]"))
        runnablesheet.write_formula(cpuloadperloc, '{=(('+cpuloadperfor+'/'+totaltimeloc+')*100)}', percentageFormat)
    # Sum Cpu Load column formula
    cpuloadsumloc = xl_rowcol_to_cell(RUNNABLE_COUNT+1, RUNNABLE_HEADER.index("CpuLoad [%]"))
    cpuloadsumfor = xl_range(1, RUNNABLE_HEADER.index("CpuLoad [%]"), RUNNABLE_COUNT, RUNNABLE_HEADER.index("CpuLoad [%]"))
    runnablesheet.write_formula(cpuloadsumloc, '{=SUM('+cpuloadsumfor+')}', percentageFormat)
    # Average formula
    for row_num in range(1, RUNNABLE_COUNT+1):
        averageloc = xl_rowcol_to_cell(row_num, RUNNABLE_HEADER.index("Duration Average [us]"))
        occurenceloc = xl_rowcol_to_cell(row_num, RUNNABLE_HEADER.index("Occurrence"))
        totalloc = xl_rowcol_to_cell(row_num, RUNNABLE_HEADER.index("Duration Total [us]"))
        runnablesheet.write_formula(averageloc, '{=('+totalloc+'/'+occurenceloc+')}')

##############################################################################
if showCheckpoints:
    # Create Checkpoint Worksheet
    checkpointsheet = workbook.add_worksheet('Checkpoint Metrics')

    # Fill Checkpoint Worksheet with Checkpoint Header information, Set Column Length and write description Comments 
    for col_num, data in enumerate(CHECKPOINT_HEADER):
        checkpointsheet.write(0, col_num, data)
        checkpointsheet.set_column(col_num, col_num, len(str(data)))
        checkpointsheet.write_comment(0, col_num, CHECKPOINT_HEADER_COMMENTS[col_num])
    # Fill Checkpoint Worksheet with Measurement Information
    for row_num in range(1, CHECKPOINT_COUNT+1):
        checkpointsheet.write(row_num, CHECKPOINT_HEADER.index("Checkpoint Name"), CHECKPOINTS[row_num-1])
        checkpointsheet.write(row_num, CHECKPOINT_HEADER.index("Duration Min [us]"), Apm_CpuLoad.Apm_CheckpointCpuLoad[row_num-1].Min)
        checkpointsheet.write(row_num, CHECKPOINT_HEADER.index("Duration Max [us]"), Apm_CpuLoad.Apm_CheckpointCpuLoad[row_num-1].Max)
        checkpointsheet.write(row_num, CHECKPOINT_HEADER.index("Period Min [us]"), Apm_CpuLoad.Apm_CheckpointCpuLoad[row_num-1].PeriodMin)
        checkpointsheet.write(row_num, CHECKPOINT_HEADER.index("Period Max [us]"), Apm_CpuLoad.Apm_CheckpointCpuLoad[row_num-1].PeriodMax)
        checkpointsheet.write(row_num, CHECKPOINT_HEADER.index("Occurrence"), Apm_CpuLoad.Apm_CheckpointCpuLoad[row_num-1].Occurrence)
        checkpointsheet.write(row_num, CHECKPOINT_HEADER.index("Duration Total [us]"), Apm_CpuLoad.Apm_CheckpointCpuLoad[row_num-1].Total)
    # Fill Checkpoint Worksheet with Measurement formulas
    # Average formula
    for row_num in range(1, CHECKPOINT_COUNT+1):
        averageloc = xl_rowcol_to_cell(row_num, CHECKPOINT_HEADER.index("Duration Average [us]"))
        occurenceloc = xl_rowcol_to_cell(row_num, CHECKPOINT_HEADER.index("Occurrence"))
        totalloc = xl_rowcol_to_cell(row_num, CHECKPOINT_HEADER.index("Duration Total [us]"))
        checkpointsheet.write_formula(averageloc, '{=('+totalloc+'/'+occurenceloc+')}')

##############################################################################
if showMarkers:
    # Create Marker Worksheet
    markersheet = workbook.add_worksheet('Startup Markers')
    # Fill Marker Worksheet with Marker Header information and Set Column Length
    for col_num, data in enumerate(MARKER_HEADER):
        markersheet.write(0, col_num, data)
        markersheet.set_column(col_num, col_num, len(str(data)))
        markersheet.write_comment(0, col_num, MARKER_HEADER_COMMENTS[col_num])
    # Fill Marker Worksheet with Measurement Information
    for row_num in range(1, MARKER_COUNT+1):
        markersheet.write(row_num, MARKER_HEADER.index("Marker Name"), MARKERS[row_num-1])
        markersheet.write(row_num, MARKER_HEADER.index("Timestamp [ticks]"), Apm_CpuLoad.Apm_StartupMarker[row_num-1])

# Close and Save Excel file
workbook.close()
