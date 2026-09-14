REM  This script is sets environment variables requires to use this version of QNX Software Development Platform 6.6
REM  from the command line. 
REM 

set QNX_INSTALL_PATH=C:\qnx660

set QNX_TARGET=%QNX_INSTALL_PATH%\target\qnx6
set QNX_TARGET=%QNX_TARGET:\=/%
set QNX_HOST=%QNX_INSTALL_PATH%\host\win32\x86
set QNX_HOST=%QNX_HOST:\=/%
set QNX_CONFIGURATION=%QNX_INSTALL_PATH%\.qnx
set QNXLM_LICENSE_FILE=7130@vcs5057.vlgdc.visteon.com
set MAKEFLAGS=-I%QNX_INSTALL_PATH%\target\qnx6\usr\include
set MAKEFLAGS=%MAKEFLAGS:\=/%
set PATH=%QNX_INSTALL_PATH%\host\win32\x86\usr\bin;%QNX_INSTALL_PATH%\.qnx\bin;%QNX_INSTALL_PATH%\jre\bin;%PATH%
set qnxCarDeployment=C:\qnx660\deployment\qnx-car
if exist %qnxCarDeployment%\qnxcar-env.bat %qnxCarDeployment%\qnxcar-env.bat
set FLEXLM_TIMEOUT=1000000
