#!/bin/sh

if [ "$1" = "?" ]
then
    echo " "
    echo "******************************************************************"
    echo "* clean.sh"
    echo "******************************************************************"
    echo "* clean VMF"
    echo "******************************************************************"
    echo "* Command line arguments:"
    echo "*   arg1 == PROJECT (WINDOWS_X86 / LINUX_X86 / EAGLE / R013 / "
    echo "*                    QNX_X86 / DC15 / EAGLE_UPDATE / RASPI / U321)"
    echo "******************************************************************"
    echo " "

    exit
fi

if [ -z "$1" ] #if empty
then
    project="LINUX_X86"
else
    project=$1
fi

rm -f project.$project

cd ..

rm -rf ./rel/$PROJECT/bin
rm -rf ./rel/$PROJECT/libs
rm -rf ./rel/$PROJECT/obj

echo " "
echo "*********************************************************************"
echo "*** Clean VMF for $project"
echo "*********************************************************************"
echo " "
make PROJECT=$project network_clean VMF_SPY=YES VMF_REM=YES VMF_TRACE=YES VMF_MI=YES VMF_SQL=YES

