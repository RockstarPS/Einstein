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

if [ "$PROJECT" = "LINUX_X86_64" ]
then
MAKE_RULES="PROJECT=$PROJECT network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SHM VMF_MI=YES VMF_SQL=YES DLT_GW=YES VMF_TARGET_LOGGING=YES VMF_FILE_LOGGING=YES"
fi

if [ "$PROJECT" = "INTEGRITY" ]
then
MAKE_RULES="PROJECT=$PROJECT network_libs network_exec VMF_SPY=NO VMF_REM=YES VMF_TRACE=YES VMF_IPC=SOCK_DOMAIN VMF_MI=YES VMF_SQL=NO DLT_GW=NO VMF_TARGET_LOGGING=NO VMF_EXTS=NO VMF_SYSINFO=NO"
fi

mkdir -p ./rel/$PROJECT/bin
mkdir -p ./rel/$PROJECT/libs
mkdir -p ./rel/$PROJECT/obj

### BUILD IT...
echo "make $MAKE_RULES"
make $MAKE_RULES

cd ./test_processes/VmfPing
make PROJECT=$PROJECT clean all

cd ../../scripts
./create_devel.sh $PROJECT

