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
make PROJECT=QNX_X86 network_clean VMF_SPY=YES VMF_REM=YES VMF_TRACE=YES VMF_MI=YES VMF_SQL=NO DLT_GW=YES VMF_SYSINFO=YES VMF_TARDIS=YES VMF_EXTS=YES

rem Capture Build
"C:\Program Files\Coverity-761\bin\cov-build.exe" --dir C:\coverity-idirs\vmf --delete-stale-tus make HOST=WINDOWS PROJECT=QNX_X86 network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=MQ VMF_MI=YES VMF_SQL=NO

rem Analysis
"C:\Program Files\Coverity-761\bin\cov-analyze.exe" --dir C:\coverity-idirs\vmf -j auto --analysis-settings coverity_cfg\visteon_Ruleset_v3_1.json


rem Commit Defects
"C:\Program Files\Coverity-761\bin\cov-commit-defects.exe" --dir C:\coverity-idirs\vmf --host chipd013.chennai.visteon.com --port 8080 --user jmerkle --stream jmerkle__vmf



rem Open Results in browser
start http://chipd013.chennai.visteon.com:8080/query/defects.htm?"stream=jmerkle__vmf&outstanding=true"


cd coverity_cfg

