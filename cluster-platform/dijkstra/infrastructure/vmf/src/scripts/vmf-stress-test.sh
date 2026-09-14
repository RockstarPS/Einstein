#! /usr/bin/env bash


mySuppressResults=-s
myWaitBeforeStart=10



myPWD=$PWD

# Copy libraries to /usr/lib
sudo cp -f ../rel/LINUX_X86_64/libs/* /usr/lib

# start vmf
if ps | grep vmf > NULL
then
    killall vmf
    killall vmf_listener
    killall vmf_sender
    echo "Kill VMF executables" 
fi

echo " "
echo " "
echo "*****************************************************************************************************************************"
echo "VMF stress test startet!"
echo "*****************************************************************************************************************************"
../rel/LINUX_X86_64/bin/vmf -v 
../rel/LINUX_X86_64/bin/vmf & 

# build benchmark process
cd ../test_processes/VmfPing
make PROJECT=LINUX_X86 AUTOMATED_BENCHMARK=TRUE USE_PRINT_BUILD_TIME=FALSE clean all > NULL

cd $myPWD


# start benchmark
../rel/LINUX_X86_64/bin/vmf_listener -i 0 -g 01 -c 10000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 1 -g 01 -c 10000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 2 -g 01 -c 10000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 3 -g 01 -c 10000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 4 -g 01 -c 10000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 5 -g 01 -c 10000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 6 -g 01 -c 10000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 7 -g 01 -c 10000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 8 -g 01 -c 10000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 9 -g 01 -c 10000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_sender -g 01 -e 02 -l 1000 -t -c 10000 -d 0 -w $myWaitBeforeStart &

../rel/LINUX_X86_64/bin/vmf_listener -i 10 -g 02 -c 10000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 11 -g 02 -c 10000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 12 -g 02 -c 10000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 13 -g 02 -c 10000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 14 -g 02 -c 10000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 15 -g 02 -c 10000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 16 -g 02 -c 10000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 17 -g 02 -c 10000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 18 -g 02 -c 10000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 19 -g 02 -c 10000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_sender -g 02 -e 03 -l 1000 -t -c 10000 -d 0 -w $myWaitBeforeStart &

../rel/LINUX_X86_64/bin/vmf_listener -i 20 -g 05 -c 1000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 21 -g 05 -c 1000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 22 -g 05 -c 1000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 23 -g 05 -c 1000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 24 -g 05 -c 1000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 25 -g 05 -c 1000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 26 -g 05 -c 1000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 27 -g 05 -c 1000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 28 -g 05 -c 1000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_listener -i 29 -g 05 -c 1000 $mySuppressResults &
../rel/LINUX_X86_64/bin/vmf_sender -g 05 -e 05 -l 1000 -t -c 1000 -d 1 -w $myWaitBeforeStart &

isActive="true"

while [ "$isActive" == "true" ]
do

    isActive="false"

    if ps | grep vmf_listener > NULL
    then
        isActive="true"    
    fi

    echo -n ...

    sleep 1
    
done

echo .
echo "*****************************************************************************************************************************"
echo ">>> VMF stress test finished! <<< "
echo "*****************************************************************************************************************************"




