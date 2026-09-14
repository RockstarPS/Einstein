#! /bin/bash

BIN_DIR=$1
TGT_DIR=$2

## Create Required Directories
mkdir -p $TGT_DIR/usr/bin/
mkdir -p $TGT_DIR/usr/bin/asset/resources
mkdir -p $TGT_DIR/usr/bin/mainHmi
mkdir -p $TGT_DIR/usr/bin/safeHmi

############################################################
# Add Binaries
############################################################
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/mainHmi                    $TGT_DIR/usr/bin/mainHmi
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/resources/*.tar            $TGT_DIR/usr/bin/asset/resources
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/safeHmi                    $TGT_DIR/usr/bin/safeHmi

############################################################
# Fix Permissions
############################################################ 
chmod -R 777 $TGT_DIR/usr/bin
chmod -R 777 $TGT_DIR/usr/bin/asset/resources
chmod -R 777 $TGT_DIR/usr/bin/mainHmi
chmod -R 777 $TGT_DIR/usr/bin/safeHmi






