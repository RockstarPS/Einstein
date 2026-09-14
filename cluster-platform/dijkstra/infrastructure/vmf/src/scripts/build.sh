#!/bin/sh

if [ "$1" = "?" ]
then
    echo " "
    echo "******************************************************************"
    echo "* build.sh"
    echo "******************************************************************"
    echo "* Build VMF (for Compilers installed on Linux (Ubuntu VM/ Mint PC)"
    echo "******************************************************************"
    echo "* Command line arguments:"
    echo "*   arg1 == PROJECT (WINDOWS_X86 / LINUX_X86 / LINUX_ARM_HF / "
    echo "*                    EAGLE / R013 / QNX_X86 / DC15 / "
    echo "*                    EAGLE_UPDATE / ANDROID / EINSTEIN / "
    echo "*                    D544 / RASPI / U321) "
    echo "*           e.g. ./build.sh LINUX_X86"
    echo "******************************************************************"
    echo " "
    
    exit
fi

sudo echo

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

sudo rm -f project.*
echo $PROJECT > project."$PROJECT"


cd ..
echo " "
echo "*********************************************************************"
echo "*** Build VMF for $PROJECT"
echo "*********************************************************************"
echo " "
if [ "$PROJECT" = "WINDOWS_X86" ]
then
MAKE_RULES="PROJECT=$PROJECT network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SOCK_UDP VMF_MI=YES VMF_SQL=YES VMF_SYSINFO=NO VMF_FILE_LOGGING=YES"
fi

if [ "$PROJECT" = "LINUX_X86" ]
then
MAKE_RULES="PROJECT=$PROJECT network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SHM VMF_MI=YES VMF_SQL=YES DLT_GW=YES VMF_TARGET_LOGGING=YES VMF_FILE_LOGGING=YES"
fi

if [ "$PROJECT" = "LINUX_X86_64" ]
then
MAKE_RULES="PROJECT=$PROJECT network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SHM VMF_MI=YES VMF_SQL=YES DLT_GW=YES VMF_TARGET_LOGGING=YES VMF_FILE_LOGGING=YES"
fi

if [ "$PROJECT" = "LINUX_X86_GCOV" ]
then
MAKE_RULES="PROJECT=$PROJECT network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SHM VMF_MI=YES VMF_SQL=NO DLT_GW=NO VMF_TARGET_LOGGING=YES  VMF_FILE_LOGGING=YES"
fi

if [ "$PROJECT" = "LINUX_ARM_HF" ]
then
MAKE_RULES="PROJECT=$PROJECT network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SHM VMF_MI=YES VMF_SQL=YES DLT_GW=YES"
fi

if [ "$PROJECT" = "EAGLE" ]
then
MAKE_RULES="PROJECT=$PROJECT network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SHM VMF_MI=YES VMF_SQL=NO DLT_GW=NO"
fi

if [ "$PROJECT" = "R013" ]
then
MAKE_RULES="PROJECT=$PROJECT network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SOCK_DOMAIN VMF_MI=NO VMF_SQL=NO"
fi

if [ "$PROJECT" = "QNX_X86" ]
then
MAKE_RULES="PROJECT=$PROJECT network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=MQ VMF_MI=YES VMF_SQL=YES"
fi

if [ "$PROJECT" = "DC15" ]
then
MAKE_RULES="PROJECT=$PROJECT network_libs network_exec VMF_SPY=YES VMF_REM=YES VMF_TRACE=YES VMF_IPC=MQ VMF_MI=NO VMF_SQL=YES"
fi

if [ "$PROJECT" = "EINSTEIN" ]
then
MAKE_RULES="PROJECT=$PROJECT network_libs network_exec VMF_SPY=YES VMF_REM=YES VMF_TRACE=YES VMF_IPC=MQ VMF_MI=NO VMF_SQL=NO DLT_GW=NO"
fi

if [ "$PROJECT" = "EAGLE_UPDATE" ]
then
MAKE_RULES="PROJECT=$PROJECT network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SHM VMF_MI=YES VMF_SQL=YES DLT_GW=YES VMF_TARGET_LOGGING=YES"
fi

if [ "$PROJECT" = "OPENSYN" ]
then
MAKE_RULES="PROJECT=$PROJECT network_libs network_exec VMF_SPY=NO VMF_REM=NO VMF_TRACE=NO VMF_IPC=SHM VMF_MI=YES VMF_SQL=NO VMF_SYSINFO=NO VMF_TARDIS=NO NO_SOCKETS=YES VMF_EXTS=NO"
fi

if [ "$PROJECT" = "LINUX_ARM_HF" ]
then
MAKE_RULES="PROJECT=$PROJECT network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SHM VMF_MI=YES VMF_SQL=YES DLT_GW=YES"
fi

if [ "$PROJECT" = "D544" ]
then
MAKE_RULES="PROJECT=$PROJECT network_libs network_exec VMF_SPY=YES VMF_REM=YES VMF_TRACE=YES VMF_IPC=MQ VMF_MI=YES VMF_SQL=NO DLT_GW=NO VMF_SYSINFO=YES VMF_TARDIS=NO NO_SOCKETS=NO VMF_EXTS=NO"
fi

if [ "$PROJECT" = "P2D3" ]
then
MAKE_RULES="PROJECT=$PROJECT network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=MQ VMF_MI=YES VMF_SQL=NO DLT_GW=NO VMF_SYSINFO=YES VMF_TARDIS=NO NO_SOCKETS=NO VMF_EXTS=NO"
fi

if [ "$PROJECT" = "INNO_ARM" ]
then
MAKE_RULES="PROJECT=$PROJECT network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SHM VMF_MI=YES VMF_SQL=YES DLT_GW=NO VMF_TARGET_LOGGING=YES"
fi

if [ "$PROJECT" = "INNO_ARM_HF" ]
then
MAKE_RULES="PROJECT=$PROJECT network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SHM VMF_MI=YES VMF_SQL=YES DLT_GW=NO VMF_TARGET_LOGGING=YES"
fi

if [ "$PROJECT" = "INNO_WINDOWS" ]
then
MAKE_RULES="PROJECT=$PROJECT network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SOCK_UDP VMF_MI=YES VMF_SQL=YES VMF_SYSINFO=NO VMF_FILE_LOGGING=YES"
fi

if [ "$PROJECT" = "INNO_WINDOWS_64" ]
then
MAKE_RULES="PROJECT=$PROJECT network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SOCK_UDP VMF_MI=YES VMF_SQL=YES VMF_SYSINFO=NO VMF_FILE_LOGGING=YES"
fi

if [ "$PROJECT" = "RASPI" ]
then
MAKE_RULES="PROJECT=$PROJECT network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SHM VMF_MI=YES VMF_SQL=YES DLT_GW=NO VMF_TARGET_LOGGING=YES  VMF_FILE_LOGGING=YES"
fi

if [ "$PROJECT" = "U321" ]
then
MAKE_RULES="PROJECT=$PROJECT network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SHM VMF_MI=YES VMF_SQL=YES DLT_GW=YES VMF_TARGET_LOGGING=YES"
# set compiler environment
. /usr/local/oecore-i686/environment-setup-cortexa9hf-neon-oe-linux-gnueabi
fi

if [ "$PROJECT" = "INTEGRITY" ]
then
MAKE_RULES="PROJECT=$PROJECT network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SOCK_DOMAIN VMF_MI=YES VMF_SQL=NO DLT_GW=NO VMF_TARGET_LOGGING=NO VMF_EXTS=NO VMF_SYSINFO=NO"
fi


if [ "$PROJECT" = "ANDROID" ]
then
    if [ -f /home/user/android-ndk-r10b/android-ndk-r10b/ndk-build ]
    then
        cd jni
        /home/user/android-ndk-r10b/android-ndk-r10b/ndk-build clean
        /home/user/android-ndk-r10b/android-ndk-r10b/ndk-build
        cd ..
        
        # move it to our well-known folders...
        echo $PWD
        sudo cp -f libs/armeabi/vmf* bin/ANDROID
        sudo cp -f libs/armeabi/lib* libs/ANDROID
        rm -rf libs/armeabi
    else
        echo Please install NDK!
    fi
else

    ### BUILD IT...
    echo "make $MAKE_RULES"
    make $MAKE_RULES

fi


if [ "$PROJECT" = "LINUX_X86" ]
then
     if [ "$HOSTTYPE" = "x86_64" ]; then
         LIBDIR=/usr/local/lib64
     else
         LIBDIR=/usr/local/lib
     fi

     echo "************************************************************************************************"
     echo "VMF libraries are now in $(pwd)/libs/LINUX_X86"
     echo "Optionally copy them to ${LIBDIR} with the following command:"
     echo "sudo cp -af $(pwd)/libs/LINUX_X86/*.{a,so} ${LIBDIR}"
     echo "You may want to run ldconfig afterwards."
     echo "************************************************************************************************"

fi

if [ "$PROJECT" = "LINUX_X86_64" ]
then
     if [ "$HOSTTYPE" = "x86_64" ]; then
         LIBDIR=/usr/local/lib64
     else
         LIBDIR=/usr/local/lib
     fi

     echo "************************************************************************************************"
     echo "VMF libraries are now in $(pwd)/libs/LINUX_X86"
     echo "Optionally copy them to ${LIBDIR} with the following command:"
     echo "sudo cp -af $(pwd)/libs/LINUX_X86/*.{a,so} ${LIBDIR}"
     echo "You may want to run ldconfig afterwards."
     echo "************************************************************************************************"

fi

