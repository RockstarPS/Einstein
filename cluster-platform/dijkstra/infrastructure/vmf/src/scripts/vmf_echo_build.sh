#! /usr/bin/env bash

cd ../test_processes/VmfEcho

### Default: LINUX X86
#make PROJECT=LINUX_X86 clean all
#make PROJECT=LINUX_X86 STATIC=YES clean all

### Windows
#make PROJECT=WINDOWS_X86 clean all

### Cross Compile for ST Linux
#make PROJECT=R013 clean all

### Cross Compile for Freescale Linux
#make PROJECT=EAGLE clean all

### Cross Compile for OE Linux
#make PROJECT=EAGLE_UPDATE clean all

### Compile for local Linux
#make PROJECT=R013 clean all

### Compile for X86 QNX
#make PROJECT=QNX_X86 clean all

### Compile for Nissan DC1.5 (QNX)
#make PROJECT=DC15 clean all

### Compile for OpenSynergy ARM (Linux)
make PROJECT=OPENSYN clean all
#make PROJECT=OPENSYN STATIC=YES clean all

file bin/vmf_echo
