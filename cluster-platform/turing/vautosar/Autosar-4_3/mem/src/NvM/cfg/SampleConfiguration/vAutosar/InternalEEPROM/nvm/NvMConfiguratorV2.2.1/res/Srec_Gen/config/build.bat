@echo off

rem Ensure Mingw bin path to gcc is inside PATH system variable OR edit and manually add the path to CC Makefile variable

SET PROJECT_PATH=%CD%
if not exist %PROJECT_PATH%\stubs\.cfg (
md %PROJECT_PATH%\stubs\.cfg
)

if not exist %PROJECT_PATH%\obj (
md %PROJECT_PATH%\obj
)

echo Compiling...

make all CMD_PROJECT_PATH=%CD%

del %PROJECT_PATH%\obj\* /q

echo Compilation done!
Srec_Gen.exe
