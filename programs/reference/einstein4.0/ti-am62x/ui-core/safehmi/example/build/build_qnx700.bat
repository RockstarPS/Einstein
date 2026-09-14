@echo off

setlocal
cd /D "%~dp0"

cd cmake

if not defined QNX700_DIR (
    if exist C:\qnx700\qnxsdp-env.bat (
        set QNX700_DIR=C:/qnx700
    ) else (
        if exist D:\qnx700\qnxsdp-env.bat (
            set QNX700_DIR=D:/qnx700
        ) else (
            echo "Build failed, Set QNX700_DIR"
            exit /B 1
        )
    )
)
if %ERRORLEVEL% == 0 call %QNX700_DIR%/qnxsdp-env.bat

if %ERRORLEVEL% == 0 call cmake_qnx_safehmi_app.bat qnx700 aarch64 qnx_700_arm_toolchain.txt Debug qualcomm
if %ERRORLEVEL% == 0 call cmake_qnx_safehmi_app.bat qnx700 aarch64 qnx_700_arm_toolchain.txt Release qualcomm
if %ERRORLEVEL% == 0 call cmake_qnx_safehmi_app.bat qnx700 aarch64 qnx_700_arm_toolchain.txt Debug
if %ERRORLEVEL% == 0 call cmake_qnx_safehmi_app.bat qnx700 aarch64 qnx_700_arm_toolchain.txt Release

if %ERRORLEVEL% == 0 goto :done

:error
cd /D "%~dp0"
echo Failed! :(
exit /B 1

:done
cd /D "%~dp0"
echo Success :)
exit /B 0
