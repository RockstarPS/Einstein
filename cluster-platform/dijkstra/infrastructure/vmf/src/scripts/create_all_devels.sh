### Create all devel packages

if ls /etc | grep qnx
then
./create_devel.sh DC15
./create_devel.sh EINSTEIN
fi

if uname | grep Linux
then
./create_devel.sh R013
./create_devel.sh EAGLE
./create_devel.sh EAGLE_UPDATE
./create_devel.sh LINUX_X86
./create_devel.sh LINUX_ARM_HF
./create_devel.sh WINDOWS_X86
./create_devel.sh OPENSYN
./create_devel.sh INNO_WINDOWS
./create_devel.sh INNO_ARM
./create_devel.sh INNO_ARM_HF
./create_devel.sh U321
./create_devel.sh INTEGRITY
fi

if [ -f /home/user/android-ndk-r10b/android-ndk-r10b/ndk-build ]
then
./create_devel.sh ANDROID
fi


