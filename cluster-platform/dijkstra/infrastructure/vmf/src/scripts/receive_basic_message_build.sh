#! /usr/bin/env bash

### Compiler for local Linux
echo "Build for local Linux"
CC=gcc

### CrossCompiler for R0-13 ARM!
#echo "Build for ARM"
#CC=arm-none-linux-gnueabi-gcc

cd ../test_processes/receive_basic_message
rm -f receive_basic_message


$CC main.c -DVMF_TRACE -I. -I../../include -I../../vmf/03_code/public -I../../vmf_config -I../../vmf_trace/03_code/public -I../../nw_config/03_code/public -L../../libs -lvmf_client -lvmf_trace -lpthread -lrt -o receive_basic_message


echo "receive_basic_message finished!"

