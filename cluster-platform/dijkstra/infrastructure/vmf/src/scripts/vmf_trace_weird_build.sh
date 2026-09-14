#! /usr/bin/env bash

cd ../test_processes/VmfTraceWeird

### Cross Compile for ST Linux
#echo "Build for ARM"
#make ARCH=arm clean all

### Compile for local Linux
echo "Build for local Linux"
make clean all

