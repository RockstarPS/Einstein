@echo off

REM **************************************************************************************************
REM * create_all_devels.bat
REM **************************************************************************************************
REM * Create all VMF devel packages
REM **************************************************************************************************

call create_devel.bat QNX_X86
call create_devel.bat D544
call create_devel.bat P2D3

call create_devel.bat WINDOWS_X86
