#!/bin/bash

mount -t proc proc /proc

mkdir -p /data
mount -t ext4 /dev/mmcblk0p15 /data

#secure_qtd_mount -c /usr/sbin/dump-qtd.conf
#/usr/sbin/crashkernel.sh

if [ -f /data/dmesgfile ]; then
    rm /data/dmesgfile
fi
if [ -f /data/dumpfile ]; then
    rm /data/dumpfile
fi
makedumpfile --dump-dmesg /proc/vmcore /data/dmesgfile
makedumpfile -c -d 31 /proc/vmcore /data/dumpfile

sleep 2s
reboot -f

