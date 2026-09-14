@echo off

REM **************************************************************************************************
REM * clean.bat
REM **************************************************************************************************
REM * Clean (make clean) VMF (for Compilers installed on Windows)
REM **************************************************************************************************
REM * Command line arguments:
REM *   arg1 = PROJECT (QNX_X86 / P2D3 / D544 / WINDOWS_X86)
REM *
REM * e.g. clean.bat QNX_X86
REM *
REM **************************************************************************************************

if "%1" == "QNX_X86" goto QNX_X86
if "%1" == "QNX_660_ARMV7" goto QNX_660_ARMV7
if "%1" == "QNX_700_X86_64" goto QNX_700_X86_64
if "%1" == "QNX_700_AARCH64" goto QNX_700_AARCH64
if "%1" == "QNX_710_AARCH64" goto QNX_710_AARCH64
if "%1" == "QNX_700_ARMV7" goto QNX_700_ARMV7
if "%1" == "LINUX_AARCH64" goto LINUX_AARCH64
if "%1" == "D544" goto D544
if "%1" == "P2D3" goto P2D3
if "%1" == "WINDOWS_X86" goto WINDOWS_X86
if "%1" == "WINDOWS_X86_64" goto WINDOWS_X86_64
if "%1" == "INNO_ARM" goto INNO_ARM
if "%1" == "INTEGRITY" goto INTEGRITY

goto DEFAULT_PROJECT

:DEFAULT_PROJECT
:QNX_X86
set VMF_PROJECT=QNX_X86
goto COMMON

:QNX_X86
set VMF_PROJECT=INNO_ARM
goto COMMON

:QNX_700_X86_64
set VMF_PROJECT=QNX_700_X86_64
goto COMMON

:QNX_700_ARMV7
set VMF_PROJECT=QNX_700_ARMV7
goto COMMON

:QNX_660_ARMV7
set VMF_PROJECT=QNX_660_ARMV7
goto COMMON

:LINUX_AARCH64
set VMF_PROJECT=LINUX_AARCH64
goto COMMON

:QNX_700_AARCH64
set VMF_PROJECT=QNX_700_AARCH64
goto COMMON

:QNX_710_AARCH64
set VMF_PROJECT=QNX_710_AARCH64
goto COMMON

:D544
set VMF_PROJECT=D544
goto COMMON

:P2D3
set VMF_PROJECT=P2D3
goto COMMON

:WINDOWS_X86
set VMF_PROJECT=WINDOWS_X86
goto COMMON

:WINDOWS_X86_64
set VMF_PROJECT=WINDOWS_X86_64
goto COMMON

:INTEGRITY
set VMF_PROJECT=INTEGRITY
goto COMMON

:COMMON
set CLEAN_COMMAND=make PROJECT=%VMF_PROJECT% network_clean VMF_SPY=YES VMF_REM=YES VMF_TRACE=YES VMF_MI=YES VMF_SQL=YES DLT_GW=YES VMF_SYSINFO=YES VMF_TARDIS=YES VMF_EXTS=YES

echo **************************************************************************************************
echo CLEAN_COMMAND: 
echo %CLEAN_COMMAND%
echo **************************************************************************************************


REM Go!
cd..
rm -rf .\rel\%VMF_PROJECT%\bin
rm -rf .\rel\%VMF_PROJECT%\libs
rm -rf .\rel\%VMF_PROJECT%\obj
%CLEAN_COMMAND%
cd scripts
