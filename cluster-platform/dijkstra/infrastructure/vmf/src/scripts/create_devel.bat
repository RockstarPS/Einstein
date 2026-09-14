@echo off

REM **************************************************************************************************
REM * create_devel.bat
REM **************************************************************************************************
REM * Create VMF devel package
REM **************************************************************************************************
REM * Command line arguments:
REM *   arg1 = PROJECT (QNX_X86 / D544 / P2D3)
REM *
REM * e.g. build.bat QNX_X86
REM *
REM **************************************************************************************************

REM check command line arg1 for project
if "%1" == "QNX_X86" goto QNX_X86
if "%1" == "QNX_700_X86_64" goto QNX_700_X86_64
if "%1" == "QNX_660_ARMV7" goto QNX_660_ARMV7
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
if "%1" == "ANDROID" goto ANDROID

goto DEFAULT_PROJECT

:DEFAULT_PROJECT
:QNX_X86
set VMF_PROJECT=QNX_X86
set DIR_OS_CONFIG=nw_os_config_qnx
goto COMMON

:QNX_660_ARMV7
set VMF_PROJECT=QNX_660_ARMV7
set DIR_OS_CONFIG=nw_os_config_qnx
goto COMMON

:INNO_ARM
set VMF_PROJECT=INNO_ARM
set DIR_OS_CONFIG=nw_os_config_linux
goto COMMON

:QNX_700_X86_64
set VMF_PROJECT=QNX_700_X86_64
set DIR_OS_CONFIG=nw_os_config_qnx
goto COMMON

:QNX_700_AARCH64
set VMF_PROJECT=QNX_700_AARCH64
set DIR_OS_CONFIG=nw_os_config_qnx
goto COMMON

:QNX_710_AARCH64
set VMF_PROJECT=QNX_710_AARCH64
goto COMMON

:QNX_700_ARMV7
set VMF_PROJECT=QNX_700_ARMV7
set DIR_OS_CONFIG=nw_os_config_qnx
goto COMMON

:LINUX_AARCH64
set VMF_PROJECT=LINUX_AARCH64
set DIR_OS_CONFIG=nw_os_config_linux
goto COMMON

:D544
set VMF_PROJECT=D544
set DIR_OS_CONFIG=nw_os_config_qnx
goto COMMON

:P2D3
set VMF_PROJECT=P2D3
set DIR_OS_CONFIG=nw_os_config_qnx
goto COMMON

:WINDOWS_X86
set VMF_PROJECT=WINDOWS_X86
set DIR_OS_CONFIG=nw_os_config_windows
goto COMMON

:WINDOWS_X86_64
set VMF_PROJECT=WINDOWS_X86_64
set DIR_OS_CONFIG=nw_os_config_windows_64
goto COMMON

:INTEGRITY
set VMF_PROJECT=INTEGRITY
set DIR_OS_CONFIG=nw_os_config_integrity
goto COMMON

:ANDROID
set VMF_PROJECT=ANDROID
set DIR_OS_CONFIG=nw_os_config_android
goto COMMON

:COMMON
set CURRENT=%cd%
cd ..\..
set DIR_DEVEL=%cd%\vmf_devel_NEW\%VMF_PROJECT%
mkdir %DIR_DEVEL%
cd %CURRENT%
cd ..

del /F /Q %DIR_DEVEL%\*.* /S

set FOLDER=bin
mkdir %DIR_DEVEL%\%FOLDER%
xcopy /s rel\%VMF_PROJECT%\%FOLDER% %DIR_DEVEL%\%FOLDER%

set FOLDER=libs
mkdir %DIR_DEVEL%\%FOLDER%
xcopy /s rel\%VMF_PROJECT%\%FOLDER% %DIR_DEVEL%\%FOLDER%

if "%1" == "WINDOWS_X86" copy %DIR_OS_CONFIG%\pthread_w32\%FOLDER%\*.dll %DIR_DEVEL%\%FOLDER%  

set FOLDER=include
mkdir %DIR_DEVEL%\%FOLDER%
copy include\*.* %DIR_DEVEL%\%FOLDER%
copy vmf\03_code\public\*.* %DIR_DEVEL%\%FOLDER%
copy vmf_trace\03_code\public\*.* %DIR_DEVEL%\%FOLDER%
copy vmf_config\*.* %DIR_DEVEL%\%FOLDER%
copy %DIR_OS_CONFIG%\03_code\public\*.* %DIR_DEVEL%\%FOLDER%
copy vmf_sql\03_code\public\*.* %DIR_DEVEL%\%FOLDER%
if "%1" == "WINDOWS_X86" copy %DIR_OS_CONFIG%\pthread_w32\include\*.* %DIR_DEVEL%\%FOLDER% 

del /F /Q %DIR_DEVEL%\dummy.txt /S

cd %CURRENT%
