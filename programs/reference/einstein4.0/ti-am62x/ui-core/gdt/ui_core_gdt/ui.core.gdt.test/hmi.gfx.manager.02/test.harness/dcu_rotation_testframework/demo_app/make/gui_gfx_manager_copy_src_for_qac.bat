echo Copy the files from rtc workspace to src folder for running QAC

xcopy ..\..\..\..\..\..\ui.core.gdt\hmi.gfx.manager.02\src\*.c		..\qac\src\  /Y


xcopy ..\autogen\*.c												..\qac\src\  /Y
xcopy ..\stub\*.c													..\qac\src\  /Y

echo source files copied to qac\src
exit 0



