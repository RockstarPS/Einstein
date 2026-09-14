#! /usr/bin/env bash

if ps | grep vmf
then
    echo ""
    echo "------- vmf already running! --------"
    echo "!!!!!!!  VMF NOT RESTARTET   !!!!!!!!"
    echo ""
else
    ../bin/LINUX_X86/vmf -p "../vmf/03_code/template" -i &
    echo "vmf startet."
fi
