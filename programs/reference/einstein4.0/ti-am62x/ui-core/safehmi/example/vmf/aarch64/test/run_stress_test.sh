#! /usr/bin/env bash
#mySuppressResults=-s
mySuppressResults=
myWaitBeforeStart=10

myPWD=$PWD

# start vmf
if ps | grep vmf > NUL
then
    killall vmf
fi

echo " "
echo " "
echo "*****************************************************************************************************************************"
echo "VMF stress test startet!"
echo "*****************************************************************************************************************************"
vmf -v 
vmf &


# start benchmark
./vmf_listener -i 0 -g 01 -c 10000 $mySuppressResults &
./vmf_listener -i 1 -g 01 -c 10000 $mySuppressResults &
./vmf_listener -i 2 -g 01 -c 10000 $mySuppressResults &
./vmf_listener -i 3 -g 01 -c 10000 $mySuppressResults &
./vmf_listener -i 4 -g 01 -c 10000 $mySuppressResults &
./vmf_listener -i 5 -g 01 -c 10000 $mySuppressResults &
./vmf_listener -i 6 -g 01 -c 10000 $mySuppressResults &
./vmf_listener -i 7 -g 01 -c 10000 $mySuppressResults &
./vmf_listener -i 8 -g 01 -c 10000 $mySuppressResults &
./vmf_listener -i 9 -g 01 -c 10000 $mySuppressResults &
./vmf_sender -g 01 -e 02 -n 11223344 -l1000 -t -c 10000 -d 0 -w $myWaitBeforeStart &

./vmf_listener -i 10 -g 02 -c 10000 $mySuppressResults &
./vmf_listener -i 11 -g 02 -c 10000 $mySuppressResults &
./vmf_listener -i 12 -g 02 -c 10000 $mySuppressResults &
./vmf_listener -i 13 -g 02 -c 10000 $mySuppressResults &
./vmf_listener -i 14 -g 02 -c 10000 $mySuppressResults &
./vmf_listener -i 15 -g 02 -c 10000 $mySuppressResults &
./vmf_listener -i 16 -g 02 -c 10000 $mySuppressResults &
./vmf_listener -i 17 -g 02 -c 10000 $mySuppressResults &
./vmf_listener -i 18 -g 02 -c 10000 $mySuppressResults &
./vmf_listener -i 19 -g 02 -c 10000 $mySuppressResults &
./vmf_sender -g 02 -e 03 -n 11223344 -l1000 -t -c 10000 -d 0 -w $myWaitBeforeStart &

./vmf_listener -i 20 -g 05 -c 1000 $mySuppressResults &
./vmf_listener -i 21 -g 05 -c 1000 $mySuppressResults &
./vmf_listener -i 22 -g 05 -c 1000 $mySuppressResults &
./vmf_listener -i 23 -g 05 -c 1000 $mySuppressResults &
./vmf_listener -i 24 -g 05 -c 1000 $mySuppressResults &
./vmf_listener -i 25 -g 05 -c 1000 $mySuppressResults &
./vmf_listener -i 26 -g 05 -c 1000 $mySuppressResults &
./vmf_listener -i 27 -g 05 -c 1000 $mySuppressResults &
./vmf_listener -i 28 -g 05 -c 1000 $mySuppressResults &
./vmf_listener -i 29 -g 05 -c 1000 $mySuppressResults &
./vmf_sender -g 05 -e 05 -n 11223344 -l1000 -t -c 1000 -d 1 -w $myWaitBeforeStart &

isActive="true"

while [ "$isActive" == "true" ]
do

    isActive="false"

    if ps | grep vmf_listener > NUL
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
