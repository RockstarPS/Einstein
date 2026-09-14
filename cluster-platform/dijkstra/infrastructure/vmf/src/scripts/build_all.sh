if ls /etc | grep qnx
then
echo "found /etc/qnx path"
if echo $PATH | grep qnx
then
echo "qnx environment already set"
else 
echo "call qconfig to setup qnx environment"
eval `/opt/qnx650/host/linux/x86/usr/bin/qconfig -n "QNX Software Development Platform 6.5.0" -e`
fi
fi

if ls /etc | grep qnx
then
# NOTE: This will compile for QNX 6.5!!! Newer projects are build with build_all.bat on Windows!
./build.sh DC15
./build.sh EINSTEIN
fi
if uname | grep Linux
then
./build.sh LINUX_X86
./build.sh LINUX_X86_GCOV
./build.sh LINUX_ARM_HF
./build.sh R013
./build.sh EAGLE
./build.sh EAGLE_UPDATE
./build.sh OPENSYN
./build.sh INNO_ARM
./build.sh INNO_ARM_HF
./build.sh INNO_WINDOWS
./build.sh U321
./build.sh INTEGRITY
fi

if [ -f /home/user/android-ndk-r10b/android-ndk-r10b/ndk-build ]
then
./build.sh ANDROID  
fi

./create_all_devels.sh

echo " "
echo " "
echo "*****************************************************************************************************************************"
echo "Verify what we have built..."
ls -l ../../vmf_devel/*/bin/*
ls -l ../../vmf_devel/*/libs/*
echo "*****************************************************************************************************************************"

./vmf-stress-test.sh
./vmf-coverage-test.sh

