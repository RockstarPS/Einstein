Description:
APM Report parser
Format APM measurement information in a human friendly format.


Usage:
Execute the parser.py script from cmd/terminal by adding as a parameter the location/name of the memory dump of structure Apm_CpuLoad.

[Example]
>parser.py tracedump.bin


Configuration file usage:
config.py file is the configuration file for the APM Report parser.
Inside you need to save as a list the names of the measured Tasks, ISRs, Runnables ...
The script uses the length of the lists in order to get the count of the Entries.
Make sure that the list of names matches the entry count number or the parser procedure will not work correctly.
If you disable a type of measurement in the code, you need to also empty the list of names for this particular type of measurement.

[Example]
If you have 3 Tasks and 3 ISRs
TASKS = [
	'Task0_Name',
	'Task1_Name',
	'Task2_Name'
]

ISRS = [
	'ISR0_Name',
	'ISR1_Name',
	'ISR2_Name'
]


List of dependencies:
--Python 3.x
--xlsxwriter (Python library)


Entry point:
The entry point of the script is in parser.py
All instructions that are not in subroutines are executed when reached.