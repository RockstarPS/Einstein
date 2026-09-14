
@echo off

call echo ********************************************************************
call echo Clean
call echo ********************************************************************
call C:\distools\Android\ndk-r15c\ndk-build clean

call echo ********************************************************************
call echo Build
call echo ********************************************************************
call C:\distools\Android\ndk-r15c\ndk-build


call echo ********************************************************************
call echo "This is beeing built:"
call echo ********************************************************************
call dir ..\libs\armeabi


