@echo off
REM ****************************************************************************
REM *** coverity_qnx.bat
REM ****************************************************************************
REM *** Coverity analysis for VMF QNX_X86
REM ****************************************************************************
REM *** 
REM ***   >>>>   LOCAL COVERITY INSTALLATION NEEDED!!!!   <<<<
REM ***  
REM ****************************************************************************

REM NOTE: For QNX targets the environment needs to be set properly. Ensure the qnx660-env.bat is in PATH!
if "%QNX_INSTALL_PATH%" == "" call qnx660-env.bat

cd ..

rem Clean
make PROJECT=QNX_660_ARMV7 network_clean VMF_SPY=YES VMF_REM=YES VMF_TRACE=YES VMF_MI=YES VMF_SQL=YES DLT_GW=YES VMF_SYSINFO=YES VMF_TARDIS=YES VMF_EXTS=YES

rem Capture Build
"C:\Coverity\bin\cov-build.exe" --config=C:/Coverity/Visteon_Compiler_Config/QNX_QCC/CC_qnx_qcc.xml --dir ./rel/QNX_660_ARMV7/coverity/out --delete-stale-tus make HOST=WINDOWS PROJECT=QNX_660_ARMV7 network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=MQ VMF_MI=YES VMF_SQL=NO VMF_EXTS=NO

rem Analysis
"C:\Coverity\bin\cov-analyze.exe" --dir ./rel/QNX_660_ARMV7/coverity/out -j auto --strip-path C:/temp/strip --analysis-settings ./coverity_cfg/visteon_Ruleset_v4_0.json

rem "C:\Coverity\bin\cov-format-errors.exe" --dir ./coverity_out --filesort --html-output ./coverity_html
rem "C:\Coverity\bin\cov-format-errors.exe" --dir ./coverity_out --filesort --json-output-v2 coverity_errors.json

"C:\Coverity\bin\cov-analyze.exe" --dir ./rel/QNX_660_ARMV7/coverity/out --disable-default --misra-config C:/Coverity/config/MISRA/MISRA_c2012_7.config

rem "C:\Coverity\bin\cov-format-errors.exe" --dir ./coverity_out --filesort --html-output ./coverity_misra_html
rem "C:\Coverity\bin\cov-format-errors.exe" --dir ./coverity_out --filesort --json-output-v2 coverity_misra.json

rem Commit Defects
"C:\Coverity\bin\cov-commit-defects.exe" --dir ./rel/QNX_660_ARMV7/coverity/out --host chipd013.chennai.visteon.com --port 8080 --user kshanmu4 --stream VMF_DevEng

rem Open Results in browser
start http://chipd013.chennai.visteon.com:8080/query/defects.htm?"stream=VMF_DevEng&outstanding=true"

cd coverity_cfg
