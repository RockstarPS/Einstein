echo Copy the files from rtc workspace to src folder for running QAC

xcopy ..\..\..\..\..\..\ui.core.gdt\hmi.gfx.manager.02\src\*.*		..\..\qac\src\  /Y


xcopy ..\..\autogen\gles20\*.*	..\..\qac\src\  /Y
xcopy ..\..\src\stubs\*.* 		..\..\qac\src\  /Y

echo source files copied to qac\src
rem exit 0



