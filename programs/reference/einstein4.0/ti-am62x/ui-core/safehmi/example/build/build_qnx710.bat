@echo off

setlocal
cd /D "%~dp0"

cd cmake

if not defined QNX710_DIR (
    if exist C:\qnx710\qnxsdp-env.bat (
        set QNX710_DIR=C:/qnx710
    ) else (
        if exist D:\qnx710\qnxsdp-env.bat (
            set QNX710_DIR=D:/qnx710
        ) else (
            echo "Build failed, Set QNX710_DIR"
            exit /B 1
        )
    )
)
if %ERRORLEVEL% == 0 call %QNX710_DIR%/qnxsdp-env.bat

if %ERRORLEVEL% == 0 call cmake_qnx_safehmi_app.bat qnx710 aarch64 qnx_710_arm_toolchain.txt Debug
if %ERRORLEVEL% == 0 call cmake_qnx_safehmi_app.bat qnx710 aarch64 qnx_710_arm_toolchain.txt Release

if %ERRORLEVEL% == 0 goto :done

:error
cd /D "%~dp0"
echo Failed! :(
exit /B 1

:done
cd /D "%~dp0"
echo Success :)
exit /B 0
