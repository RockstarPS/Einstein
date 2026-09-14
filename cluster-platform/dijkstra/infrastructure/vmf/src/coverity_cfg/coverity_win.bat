@echo off
REM ****************************************************************************
REM *** coverity_win.bat
REM ****************************************************************************
REM *** Coverity analysis for VMF WINDOWS_X86
REM ****************************************************************************
REM *** 
REM ***   >>>>   LOCAL COVERITY INSTALLATION NEEDED!!!!   <<<<
REM ***  
REM ****************************************************************************


cd ..

rem Clean
make PROJECT=WINDOWS_X86 network_clean VMF_SPY=YES VMF_REM=YES VMF_TRACE=YES VMF_MI=YES VMF_SQL=YES DLT_GW=YES VMF_SYSINFO=YES VMF_TARDIS=YES VMF_EXTS=YES

rem Capture Build
"C:\Program Files\Coverity-761\bin\cov-build.exe" --dir C:\coverity-idirs\vmf --delete-stale-tus make HOST=WINDOWS PROJECT=WINDOWS_X86 network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SOCK_UDP VMF_MI=YES VMF_SQL=YES VMF_SYSINFO=NO VMF_FILE_LOGGING=YES VMF_EXTS=YES

rem Analysis
rem "C:\Program Files\Coverity-761\bin\cov-analyze.exe" --dir C:\coverity-idirs\vmf --output-tag c -j auto --all --preview --concurrency --security --symbian --enable-parse-warnings --rule --enable-constraint-fpp --enable-fnptr --enable-virtual --aggressiveness-level high --enable-callgraph-metrics --no-field-offset-escape --one-tu-per-psf=false --strip-path C:\data\rtc\VMF-hm\vmf_core
"C:\Program Files\Coverity-761\bin\cov-analyze.exe" --dir C:\coverity-idirs\vmf -j auto --analysis-settings coverity_cfg\visteon_Ruleset_v3_1.json


rem Commit Defects
"C:\Program Files\Coverity-761\bin\cov-commit-defects.exe" --dir C:\coverity-idirs\vmf --host chipd013.chennai.visteon.com --port 8080 --user jmerkle --stream jmerkle__vmf



rem Open Results in browser
start http://chipd013.chennai.visteon.com:8080/query/defects.htm?"stream=jmerkle__vmf&outstanding=true"



cd coverity_cfg



