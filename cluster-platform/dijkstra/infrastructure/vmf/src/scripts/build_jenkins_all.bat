@echo off

REM **************************************************************************************************
REM * build_jenkins_all.bat
REM **************************************************************************************************
REM * Build VMF (for Compilers installed on Windows)
REM **************************************************************************************************

rmdir /s /q ..\rel
mkdir ..\rel

start cmd /k Call build_jenkins.bat QNX_X86
start cmd /k Call build_jenkins.bat QNX_660_ARMV7
start cmd /k Call build_jenkins.bat QNX_700_ARMV7
start cmd /k Call build_jenkins.bat QNX_700_AARCH64
start cmd /k Call build_jenkins.bat QNX_710_AARCH64
start cmd /k Call build_jenkins.bat QNX_700_X86_64
start cmd /k Call build_jenkins.bat LINUX_AARCH64
start cmd /k Call build_jenkins.bat WINDOWS_X86
start cmd /k Call build_jenkins.bat WINDOWS_X86_64
start cmd /k Call build_jenkins.bat ANDROID

EXIT
