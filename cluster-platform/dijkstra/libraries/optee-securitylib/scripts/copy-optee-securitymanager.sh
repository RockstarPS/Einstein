#!/bin/bash
BIN_DIR=$1
DST_DIR=$2
OPTEE_OS=$BIN_DIR/Prebuilt_OS/arm-plat-k3/core
OPTEE_CLIENT=$BIN_DIR/Prebuilt_client/out/export/usr

mkdir -p $DST_DIR/firmware
mkdir -p $DST_DIR/TEE_Client_Libraries
mkdir -p $DST_DIR/TEE-Supplicant
mkdir -p $DST_DIR/TA

# copy OPTEE OS firmware
yes | cp -rf $OPTEE_OS/tee-header_v2.bin                            $DST_DIR/firmware/
yes | cp -rf $OPTEE_OS/tee-pageable_v2.bin                          $DST_DIR/firmware/
yes | cp -rf $OPTEE_OS/tee-pager_v2.bin                             $DST_DIR/firmware/
yes | cp -rf $OPTEE_OS/tee-raw.bin                                  $DST_DIR/firmware/
yes | cp -rf $OPTEE_OS/tee.bin                                      $DST_DIR/firmware/
yes | cp -rf $OPTEE_OS/tee.elf                                      $DST_DIR/firmware/

# copy Trusted applications
yes | cp -rf $OPTEE_OS/../ta/avb/*.ta                               $DST_DIR/TA/
yes | cp -rf $OPTEE_OS/../ta/pkcs11/*.ta                            $DST_DIR/TA/
yes | cp -rf $OPTEE_OS/../ta/trusted_keys/*.ta                      $DST_DIR/TA/
yes | cp -rf $OPTEE_OS/../ta/remoteproc/*.ta                        $DST_DIR/TA/

# copy user TA and plugin
yes | cp -rf $BIN_DIR/SecurityManager/out/ta/*.ta                   $DST_DIR/TA/
yes | cp -rf $BIN_DIR/SecurityManager/out/plugins/*.plugin          $DST_DIR/TA/

#copy user CA libraries
yes | cp -rf $BIN_DIR/SecurityManager/out/lib/*.a                   $DST_DIR/../*/lib/
yes | cp -rf $OPTEE_CLIENT/lib/*.a                                  $DST_DIR/../*/lib/

# copy OPTEE Client libraries and tee-supplicant
yes | cp -rf $OPTEE_CLIENT/lib/libckteec.so.0.1.0                   $DST_DIR/TEE_Client_Libraries/
yes | cp -rf $OPTEE_CLIENT/lib/libseteec.so.0.1.0                   $DST_DIR/TEE_Client_Libraries/
yes | cp -rf $OPTEE_CLIENT/lib/libteeacl.so.0.1.0                   $DST_DIR/TEE_Client_Libraries/
yes | cp -rf $OPTEE_CLIENT/lib/libteec.so.2.0.0                     $DST_DIR/TEE_Client_Libraries/
yes | cp -rf $OPTEE_CLIENT/sbin/tee-supplicant                      $DST_DIR/TEE-Supplicant/