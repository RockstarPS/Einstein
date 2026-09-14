#! /bin/bash

BIN_DIR=$1
TGT_DIR=$2

mkdir -p $TGT_DIR/bin/
mkdir -p $TGT_DIR/lib/
mkdir -p $TGT_DIR/sbin/
mkdir -p $TGT_DIR/etc/
mkdir -p $TGT_DIR/usr/bin/
mkdir -p $TGT_DIR/usr/lib/
mkdir -p $TGT_DIR/usr/sbin/

#yes | cp -rf $BIN_DIR/aarch64le/bin/early_startup.sh						$TGT_DIR/bin/
#yes | cp -rf $BIN_DIR/aarch64le/bin/late_startup.sh							$TGT_DIR/bin/

yes | cp -rf $BIN_DIR/aarch64le/usr/bin/fota_app                $TGT_DIR/usr/bin/

yes | cp -rf $BIN_DIR/aarch64le/usr/bin/boot_kpi        				    $TGT_DIR/usr/bin/

#yes | cp -rf $BIN_DIR/aarch64le/usr/lib/libbspal_dioLinux*				$TGT_DIR/usr/lib/
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/set_dir_*				$TGT_DIR/usr/bin/
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/read_dir_*				$TGT_DIR/usr/bin/
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/dio_set*				$TGT_DIR/usr/bin/
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/display_power_off       $TGT_DIR/usr/bin/
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/display_power_on        $TGT_DIR/usr/bin/
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/display_set_get_power   $TGT_DIR/usr/bin/
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/display_state_read      $TGT_DIR/usr/bin/
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/display_state_off       $TGT_DIR/usr/bin/
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/read_pin_*				$TGT_DIR/usr/bin/
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/deser_test              $TGT_DIR/usr/bin/

yes | cp -rf $BIN_DIR/aarch64le/usr/bin/wdg_proxy				$TGT_DIR/usr/bin/
#yes | cp -R  $BIN_DIR/etc/                                      $TGT_DIR/
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/meet_app                $TGT_DIR/usr/bin/
yes | cp -rf $BIN_DIR/aarch64le/etc/images                      $TGT_DIR/etc/images

yes | cp -rf $BIN_DIR/aarch64le/usr/bin/diag_app_gp             $TGT_DIR/usr/bin/diag_app_gp


chmod -R 777 $TGT_DIR/bin/
chmod -R 777 $TGT_DIR/lib/
chmod -R 777 $TGT_DIR/sbin/
chmod -R 777 $TGT_DIR/usr/bin/
chmod -R 777 $TGT_DIR/usr/lib/
chmod -R 777 $TGT_DIR/usr/sbin/
