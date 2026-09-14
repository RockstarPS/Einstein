#! /usr/bin/env bash

cd ../test_processes/DBusMonitor

### Compile for local Linux
make clean all VMF_TRACE=YES

