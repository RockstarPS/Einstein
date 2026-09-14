@echo off

set QNXVER=%1
set ABI=%2
set TC_FILE=%3
set EHMI_BUILD_TYPE=%4
set EHMI_BUILD_OUTDIR=%4
set PROCESSOR=%5

set EHMI_BASE=%~dp0
set EHMI_BUILD=%EHMI_BASE%..\..\build\%QNXVER%\%ABI%%PROCESSOR%
set EHMI_BUILD_FOLDER_PATH=%EHMI_BUILD%\%EHMI_BUILD_OUTDIR%

echo building ABI : %ABI%

:: ---------------------------------------------------
:: Building safehmi libraries.
:: ---------------------------------------------------
echo building safehmi app

::Build safehmi for QNX700
cd %EHMI_BASE%
rmdir %EHMI_BUILD_FOLDER_PATH% /s /q

cmake -B%EHMI_BUILD_FOLDER_PATH% -H. -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=%EHMI_BASE%/%TC_FILE% -DCMAKE_BUILD_TYPE=%EHMI_BUILD_TYPE% -DPROCESSOR=%PROCESSOR%
IF %ERRORLEVEL% NEQ 0 goto :fail

cd %EHMI_BUILD_FOLDER_PATH%
make clean
make
IF %ERRORLEVEL% NEQ 0 goto :fail

goto :exit

:fail
COLOR 4E
echo Failed! :(
cd %EHMI_BASE%
exit /B 1

:exit
COLOR 
echo Success :)
cd %EHMI_BASE%
exit /B 0

