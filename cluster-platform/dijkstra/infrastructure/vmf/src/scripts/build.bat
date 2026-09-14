@echo off

REM **************************************************************************************************
REM * build.bat
REM **************************************************************************************************
REM * Build VMF (for Compilers installed on Windows)
REM **************************************************************************************************
REM * Command line arguments:
REM *   arg1 = PROJECT (QNX_X86 / P2D3 / D544 / WINDOWS_X86)
REM *
REM * e.g. build.bat QNX_X86
REM *
REM **************************************************************************************************


REM Remind the previous project to decide if clean is needed.
set PREVIOUS_VMF_PROJECT=%VMF_PROJECT%

REM check command line arg1 for project
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
REM NOTE: For QNX targets the environment needs to be set properly. Ensure the qnx660-env.bat is in PATH!
if "%QNX_INSTALL_PATH%" == "" call qnx660-env.bat
set VMF_PROJECT=QNX_X86
set VMF_MAKE_RULES=network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=MQ VMF_MI=YES VMF_SQL=YES
goto COMMON

:INNO_ARM
REM NOTE: For QNX targets the environment needs to be set properly. Ensure the qnx660-env.bat is in PATH!
set VMF_PROJECT=INNO_ARM
set VMF_MAKE_RULES=network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SHM VMF_MI=YES VMF_SQL=YES DLT_GW=NO VMF_TARGET_LOGGING=YES
goto COMMON

:QNX_660_ARMV7
REM NOTE: For QNX targets the environment needs to be set properly. Ensure the qnxsdp-env.bat is in PATH!
if "%QNX_INSTALL_PATH%" == "" call qnx660-env.bat
set VMF_PROJECT=QNX_660_ARMV7
set VMF_MAKE_RULES=network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=MQ VMF_MI=YES VMF_SQL=NO VMF_EXTS=NO
goto COMMON

:QNX_700_X86_64
REM NOTE: For QNX targets the environment needs to be set properly. Ensure the qnxsdp-env.bat is in PATH!
if "%QNX_INSTALL_PATH%" == "" call qnxsdp-env.bat
set VMF_PROJECT=QNX_700_X86_64
set VMF_MAKE_RULES=network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=MQ VMF_MI=YES VMF_SQL=NO VMF_EXTS=NO
goto COMMON

:QNX_700_AARCH64
REM NOTE: For QNX targets the environment needs to be set properly. Ensure the qnxsdp-env.bat is in PATH!
if "%QNX_INSTALL_PATH%" == "" call qnxsdp-env.bat
set VMF_PROJECT=QNX_700_AARCH64
set VMF_MAKE_RULES=network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=MQ VMF_MI=YES VMF_SQL=NO VMF_EXTS=NO
goto COMMON

:QNX_710_AARCH64
REM NOTE: For QNX targets the environment needs to be set properly. Ensure the qnxsdp-env.bat is in PATH!
if "%QNX_INSTALL_PATH%" == "" call qnxsdp-env.bat
set VMF_PROJECT=QNX_710_AARCH64
set VMF_MAKE_RULES=network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=MQ VMF_MI=YES VMF_SQL=NO VMF_EXTS=NO
goto COMMON

:QNX_700_ARMV7
REM NOTE: For QNX targets the environment needs to be set properly. Ensure the qnxsdp-env.bat is in PATH!
if "%QNX_INSTALL_PATH%" == "" call qnxsdp-env.bat
set VMF_PROJECT=QNX_700_ARMV7
set VMF_MAKE_RULES=network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=MQ VMF_MI=YES VMF_SQL=NO VMF_EXTS=NO
goto COMMON

:LINUX_AARCH64
set VMF_PROJECT=LINUX_AARCH64
set VMF_MAKE_RULES=network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SOCK_DOMAIN VMF_MI=YES VMF_SQL=NO VMF_EXTS=NO
goto COMMON

:D544
REM NOTE: For QNX targets the environment needs to be set properly. Ensure the qnx660-env.bat is in PATH!
if "%QNX_INSTALL_PATH%" == "" call qnx660-env.bat
set VMF_PROJECT=D544
set VMF_MAKE_RULES=network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=MQ VMF_MI=NO VMF_SQL=NO DLT_GW=NO VMF_SYSINFO=YES VMF_TARDIS=NO NO_SOCKETS=NO VMF_EXTS=NO
goto COMMON

:P2D3
REM NOTE: For QNX targets the environment needs to be set properly. Ensure the qnx660-env.bat is in PATH!
if "%QNX_INSTALL_PATH%" == "" call qnx660-env.bat
set VMF_PROJECT=P2D3
set VMF_MAKE_RULES=network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=MQ VMF_MI=NO VMF_SQL=NO DLT_GW=NO VMF_SYSINFO=YES VMF_TARDIS=NO NO_SOCKETS=NO VMF_EXTS=NO
goto COMMON

:WINDOWS_X86
set VMF_PROJECT=WINDOWS_X86
set VMF_MAKE_RULES=network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SOCK_UDP VMF_MI=YES VMF_SQL=YES VMF_SYSINFO=NO VMF_FILE_LOGGING=YES VMF_EXTS=YES
goto COMMON

:WINDOWS_X86_64
set VMF_PROJECT=WINDOWS_X86_64
set VMF_MAKE_RULES=network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SOCK_UDP VMF_MI=YES VMF_SQL=YES VMF_SYSINFO=NO VMF_FILE_LOGGING=YES VMF_EXTS=YES
goto COMMON

:INTEGRITY
set VMF_PROJECT=INTEGRITY
set VMF_MAKE_RULES=network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SOCK_DOMAIN VMF_MI=YES VMF_SQL=NO DLT_GW=NO VMF_TARGET_LOGGING=NO VMF_EXTS=NO VMF_SYSINFO=NO
goto COMMON

:COMMON
if "%PREVIOUS_VMF_PROJECT%" == "%VMF_PROJECT%" goto NO_CLEAN
call clean.bat %VMF_PROJECT%


:NO_CLEAN 

REM set the build command
set BUILD_COMMAND=make HOST=WINDOWS PROJECT=%VMF_PROJECT% %VMF_MAKE_RULES%

echo *****************************************************************************************************************************************************************************************
echo BUILD_COMMAND: 
echo %BUILD_COMMAND%
echo *****************************************************************************************************************************************************************************************


REM Go!
cd..
mkdir .\rel\%VMF_PROJECT%\bin
mkdir .\rel\%VMF_PROJECT%\libs
mkdir .\rel\%VMF_PROJECT%\obj
%BUILD_COMMAND%
cd scripts
