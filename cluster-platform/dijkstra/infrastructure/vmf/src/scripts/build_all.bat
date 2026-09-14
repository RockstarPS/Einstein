@echo off

REM **************************************************************************************************
REM * build_all.bat
REM **************************************************************************************************
REM * Build all VMF versions (for Compilers installed on Windows)
REM **************************************************************************************************

call build.bat QNX_X86
call build.bat D544
call build.bat P2D3

call build.bat WINDOWS_X86
