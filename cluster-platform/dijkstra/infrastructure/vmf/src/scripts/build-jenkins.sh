#!/bin/bash

if [ "$1" == "?" ]
then
    echo " "
    echo "******************************************************************"
    echo "* build.sh"
    echo "******************************************************************"
    echo "* Build VMF"
    echo "******************************************************************"
    echo "* Command line arguments:"
    echo "*   arg1 == PROJECT (WINDOWS_X86 / LINUX_X86 / LINUX_ARM_HF / "
    echo "*                    EAGLE / R013 / QNX_X86 / DC15 / "
    echo "*                    EAGLE_UPDATE / ANDROID / EINSTEIN / "
    echo "*                    D544) "
    echo "*           e.g. ./build.sh LINUX_X86"
    echo "******************************************************************"
    echo " "
    
    exit
fi

#sudo echo

if [ ! -n "$1" ] #if empty
then
# default
    PROJECT="LINUX_X86"
else
#    PROJECT=$1
    PROJECT=$(echo $1 | tr '[:lower:]' '[:upper:]')

fi

if [ -f project."$PROJECT" ] #if file exists
then
    echo ""
else
    ./clean.sh $PROJECT
fi

#sudo rm -f project.*
rm -f project.*

echo $PROJECT > project."$PROJECT"


cd ..
echo " "
echo "*********************************************************************"
echo "*** Build VMF for $PROJECT"
echo "*********************************************************************"
echo " "

if [ "$PROJECT" == "WINDOWS_X86" ]
then
MAKE_RULES="PROJECT=$PROJECT network_clean network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SOCK_UDP VMF_MI=YES VMF_SQL=YES VMF_SYSINFO=NO VMF_FILE_LOGGING=YES"
fi

if [ "$PROJECT" == "QNX_X86" ]
then
MAKE_RULES="PROJECT=$PROJECT network_clean network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=MQ VMF_MI=YES VMF_SQL=YES VMF_TARGET_LOGGING=YES VMF_FILE_LOGGING=YES"
fi

if [ "$PROJECT" == "LINUX_X86" ]
then
MAKE_RULES="PROJECT=$PROJECT network_clean network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SHM VMF_MI=YES VMF_SQL=YES DLT_GW=YES VMF_TARGET_LOGGING=YES VMF_FILE_LOGGING=YES"
fi

if [ "$PROJECT" == "LINUX_X86_GCOV" ]
then
MAKE_RULES="PROJECT=$PROJECT network_clean network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SHM VMF_MI=YES VMF_SQL=NO DLT_GW=NO VMF_TARGET_LOGGING=YES VMF_FILE_LOGGING=YES"
fi

if [ "$PROJECT" == "LINUX_ARM_HF" ]
then
MAKE_RULES="PROJECT=$PROJECT network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SHM VMF_MI=YES VMF_SQL=YES DLT_GW=YES VMF_TARGET_LOGGING=YES VMF_FILE_LOGGING=YES"
fi


if [ "$PROJECT" == "ANDROID" ]
then
    if [ -f /usr/local/android-ndk-r10d/ndk-build ]
    then
        cd jni
        /usr/local/android-ndk-r10d/ndk-build clean
        /usr/local/android-ndk-r10d/ndk-build
        cd ..
        
        # move it to our well-known folders...
        echo $PWD
        sudo cp -f libs/armeabi/vmf* bin/ANDROID
        sudo cp -f libs/armeabi/lib* libs/ANDROID
        rm -rf libs/armeabi
    fi
else

    ### BUILD IT...
    echo "make $MAKE_RULES"
    make $MAKE_RULES

fi


if [ "$PROJECT" == "LINUX_X86" ]
then
    echo "Copy libs to /usr/lib"
    sudo cp -f libs/LINUX_X86/* /usr/lib
fi

if [ "$PROJECT" == "LINUX_X86_GCOV" ]
then
    cp -f bin/LINUX_X86_GCOV/* bin/LINUX_X86
fi