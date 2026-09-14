#! /usr/bin/env bash

### Compiler for local Linux
echo "Build for local Linux"
CC=gcc

### CrossCompiler for R0-13 ARM!
#echo "Build for ARM"
#CC=arm-none-linux-gnueabi-gcc


cd ../test_processes/send_basic_message
rm -f send_basic_message

$CC main.c -I. -I../../include -I../../vmf/03_code/public -I../../vmf_config -I../../nw_config/03_code/public -L../../libs -lvmf_client -lvmf_trace -lpthread -lrt -o send_basic_message


echo "send_basic_message finished!"


