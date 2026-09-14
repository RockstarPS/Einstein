#!/bin/bash

echo "loading crashkernel using kexec"
kexec -p /usr/sbin/crash_image --command-line="console=ttyS2,115200 quiet cma=0 noioapicquirk root=/dev/mmcblk0p3 rw rootfstype=ext4 rootwait init=/usr/sbin/dumpkernel.sh reset_devices swiotlb=0"

