#! /bin/bash

# Add the lib /bin to be packed with RootFS
BIN_DIR=$1
TGT_DIR=$2

############################################################
# Create mountpoints
############################################################ 
mkdir -p $TGT_DIR/system/
mkdir -p $TGT_DIR/app/
mkdir -p $TGT_DIR/asset/
mkdir -p $TGT_DIR/data/
mkdir -p $TGT_DIR/persist/
mkdir -p $TGT_DIR/ota-cache/

############################################################
# Create necessary directories for optee
############################################################
mkdir -p $TGT_DIR/lib/
mkdir -p $TGT_DIR/lib/optee_armtz
mkdir -p $TGT_DIR/usr/lib/tee-supplicant
mkdir -p $TGT_DIR/usr/lib/tee-supplicant/plugins
mkdir -p $TGT_DIR/bin
mkdir -p $TGT_DIR/etc/system_state
mkdir -p $TGT_DIR/etc/display_mgr

# Set to "ON" to copy the test binary to rootfs, or "OFF" to skip
COPY_PKCS11_TEST="OFF"

############################################################
# Add Binaries
############################################################
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/bl_ucl_proxy_vmf           $TGT_DIR/usr/bin/
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/bl_app_gp		           $TGT_DIR/usr/bin/
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/vmf*                       $TGT_DIR/usr/bin/
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/libvmf*                    $TGT_DIR/usr/lib/

yes | cp -rf $BIN_DIR/aarch64le/bin/dlt*                           $TGT_DIR/bin/
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/dlt_gateway                $TGT_DIR/usr/bin/

yes | cp -rf $BIN_DIR/aarch64le/usr/bin/dlt*                       $TGT_DIR/bin/
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/power_mgr                  $TGT_DIR/usr/bin/power_mgr
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/wdg_proxy                  $TGT_DIR/usr/bin/wdg_proxy
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/ucl_proxy_vmf              $TGT_DIR/usr/bin/ucl_proxy_vmf
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/display_mgr                $TGT_DIR/usr/bin/display_mgr
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/network_mgr                $TGT_DIR/usr/bin/network_mgr
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/secure_qtd_mount           $TGT_DIR/usr/bin/secure_qtd_mount
yes | cp -rf $BIN_DIR/usr/sbin/crash_image                         $TGT_DIR/usr/sbin/crash_image
yes | cp -rf $BIN_DIR/usr/sbin/kexec                               $TGT_DIR/usr/sbin/kexec
yes | cp -rf $BIN_DIR/usr/sbin/makedumpfile                        $TGT_DIR/usr/sbin/makedumpfile
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/boot_kpi_logger            $TGT_DIR/usr/bin/boot_kpi_logger
yes | cp -rf $BIN_DIR/usr/sbin/crashkernel.sh                      $TGT_DIR/usr/sbin/crashkernel.sh
yes | cp -rf $BIN_DIR/usr/sbin/dumpkernel.sh                       $TGT_DIR/usr/sbin/dumpkernel.sh
yes | cp -rf $BIN_DIR/usr/sbin/dump-qtd.conf                       $TGT_DIR/usr/sbin/dump-qtd.conf
yes | cp -rf $BIN_DIR/usr/sbin/start_ncm_ethernet.sh               $TGT_DIR/usr/sbin/start_ncm_ethernet.sh
yes | cp -rf $BIN_DIR/usr/sbin/start_eth0.sh                       $TGT_DIR/usr/sbin/start_eth0.sh

############################################################
# Add libraries
############################################################
yes | cp -rf $BIN_DIR/aarch64le/usr/lib/libGpUpdateCdd.so          $TGT_DIR/usr/lib/libGpUpdateCdd.so
yes | cp -rf $BIN_DIR/aarch64le/usr/lib/libdk_logger.so.0.8.0      $TGT_DIR/usr/lib/libdk_logger.so.0.8.0
yes | cp -rf $BIN_DIR/aarch64le/usr/lib/libdlt.so.2.18.10           $TGT_DIR/usr/lib/libdlt.so.2.18.10
yes | cp -rf $BIN_DIR/aarch64le/usr/lib/libdk_logger.so.0.8.0      $TGT_DIR/usr/lib/libdk_logger.so.0.8.0
yes | cp -rf $BIN_DIR/aarch64le/usr/lib/libdk_runtime.so.0.11.0    $TGT_DIR/usr/lib/libdk_runtime.so.0.11.0
yes | cp -rf $BIN_DIR/aarch64le/usr/lib/libbspal_dio.so.0.11.0     $TGT_DIR/usr/lib/libbspal_dio.so.0.11.0
yes | cp -rf $BIN_DIR/aarch64le/usr/lib/libosal.so.0.1.1           $TGT_DIR/usr/lib/libosal.so.0.1.1
yes | cp -rf $BIN_DIR/aarch64le/usr/lib/libucl_vmf.so              $TGT_DIR/usr/lib/libucl_vmf.so
yes | cp -rf $BIN_DIR/aarch64le/usr/lib/libUclCommon.so            $TGT_DIR/usr/lib/libUclCommon.so
yes | cp -rf $BIN_DIR/aarch64le/usr/lib/libUclDL.so                $TGT_DIR/usr/lib/libUclDL.so
yes | cp -rf $BIN_DIR/aarch64le/usr/lib/libbspal_sys_shutdown.so   $TGT_DIR/usr/lib/libbspal_sys_shutdown.so
yes | cp -rf $BIN_DIR/aarch64le/usr/lib/libdk_wdg_client.so        $TGT_DIR/usr/lib/libdk_wdg_client.so
yes | cp -rf $BIN_DIR/aarch64le/usr/lib/libbspal_display.so.0.11.0 $TGT_DIR/usr/lib/libbspal_display.so.0.11.0
yes | cp -rf $BIN_DIR/aarch64le/usr/lib/libmetadata.so             $TGT_DIR/usr/lib/
yes | cp -rf $BIN_DIR/aarch64le/usr/lib/libbspal_sys_shutdown.so   $TGT_DIR/usr/lib/libbspal_sys_shutdown.so
yes | cp -rf $BIN_DIR/aarch64le/usr/lib/libdk_wdg_client.so        $TGT_DIR/usr/lib/libdk_wdg_client.so
yes | cp -rf $BIN_DIR/aarch64le/usr/lib/libbspal_display.so.0.11.0 $TGT_DIR/usr/lib/libbspal_display.so.0.11.0
yes | cp -rf $BIN_DIR/aarch64le/usr/lib/libbspal_sigunit.so        $TGT_DIR/usr/lib/libbspal_sigunit.so
yes | cp -rf $BIN_DIR/aarch64le/usr/lib/libbspal_deserializer.so   $TGT_DIR/usr/lib/libbspal_deserializer.so
yes | cp -rf $BIN_DIR/usr/lib/libdw.so                             $TGT_DIR/usr/lib/libdw.so
yes | cp -rf $BIN_DIR/aarch64le/usr/lib/libboost_*.so.*           $TGT_DIR/usr/lib/
# Copy TEE-related binaries and libraries
yes | cp -rf $BIN_DIR/aarch64le/usr/bin/securitymanager_test                   $TGT_DIR/usr/bin/securitymanager_test
yes | cp -rf $BIN_DIR/../OPTEE/TEE-Supplicant/tee-supplicant                   $TGT_DIR/usr/sbin/tee-supplicant
yes | cp -rf $BIN_DIR/../OPTEE/TEE_Client_Libraries/libteeacl.so.0.1.0         $TGT_DIR/usr/lib/libteeacl.so.0.1.0
yes | cp -rf $BIN_DIR/../OPTEE/TEE_Client_Libraries/libckteec.so.0.1.0         $TGT_DIR/usr/lib/libckteec.so.0.1.0
yes | cp -rf $BIN_DIR/../OPTEE/TEE_Client_Libraries/libseteec.so.0.1.0         $TGT_DIR/usr/lib/libseteec.so.0.1.0
yes | cp -rf $BIN_DIR/../OPTEE/TEE_Client_Libraries/libteec.so.2.0.0           $TGT_DIR/usr/lib/libteec.so.2.0.0
yes | cp -rf $BIN_DIR/../OPTEE/TEE-Supplicant/tee-supplicant                   $TGT_DIR/usr/lib/tee-supplicant
yes | cp -rf $BIN_DIR/../OPTEE/TA/*.plugin                                     $TGT_DIR/usr/lib/tee-supplicant/plugins
yes | cp -rf $BIN_DIR/../OPTEE/TA/*.ta                                         $TGT_DIR/lib/optee_armtz
yes | cp -rf $BIN_DIR/../OPTEE/firmware/tee*                                   $TGT_DIR/lib/firmware
# Ensure SystemD service for tee-supplicant is installed and enabled
yes | cp -rf $BIN_DIR/etc/tee-supplicant.service           $TGT_DIR/etc/systemd/system/   
ln -sf /etc/systemd/system/tee-supplicant.service          $TGT_DIR/etc/systemd/system/multi-user.target.wants/tee-supplicant.service

if [ "$COPY_PKCS11_TEST" = "ON" ]; then
    yes | cp -rf $BIN_DIR/aarch64le/usr/bin/pkcs11_test                 $TGT_DIR/usr/bin/pkcs11_test
fi


chmod -R 777 $TGT_DIR/usr/sbin/tee-supplicant

############################################################
# Create Symlinks
############################################################ 
cd $TGT_DIR/usr/lib
ln -s libdk_logger.so.0.8.0 libdk_logger.so.0
ln -s libdk_logger.so.0.8.0 libdk_logger.so
ln -sf libdlt.so.2.18.10 libdlt.so.2
ln -sf libdlt.so.2.18.10 libdlt.so
ln -s libdk_runtime.so.0.11.0 libdk_runtime.so.0
ln -s libdk_runtime.so.0.11.0 libdk_runtime.so
ln -s libosal.so.0.1.1 libosal.so.0
ln -s libosal.so.0.1.1 libosal.so
ln -s libbspal_display.so.0.11.0 libbspal_display.so.0
ln -s libbspal_display.so.0.11.0 libbspal_display.so
ln -s libteeacl.so.0.1.0 libteeacl.so.0
ln -s libckteec.so.0.1.0 libckteec.so.0
ln -s libseteec.so.0.1.0 libseteec.so.0
ln -s libteec.so.2.0.0   libteec.so.2
ln -s libdw.so libdw.so.1
ln -s libbspal_dio.so.0.11.0     libbspal_dio.so.0
ln -s libbspal_dio.so.0.11.0     libbspal_dio.so

############################################################
# Add Configurations
############################################################ 
yes | cp -rf $BIN_DIR/etc/dlt.conf                       $TGT_DIR/etc/dlt.conf
yes | cp -rf $BIN_DIR/etc/dlt_system.conf                $TGT_DIR/etc/dlt_system.conf
yes | cp -rf $BIN_DIR/etc/dlt_logstorage.conf            $TGT_DIR/etc/dlt_logstorage.conf
yes | cp -rf $BIN_DIR/etc/dlt_gateway.conf               $TGT_DIR/etc/dlt_gateway.conf
yes | cp -rf $BIN_DIR/etc/dlt_gw.ini                     $TGT_DIR/etc/dlt_gw.ini
yes | cp -rf $BIN_DIR/etc/primary-qtd.conf               $TGT_DIR/etc/primary-qtd.conf 
yes | cp -rf $BIN_DIR/etc/recovery-qtd.conf              $TGT_DIR/etc/recovery-qtd.conf
yes | cp -rf $BIN_DIR/etc/modules.conf                   $TGT_DIR/etc/modules-load.d/modules.conf
yes | cp -rf $BIN_DIR/etc/50-network-hardening.conf      $TGT_DIR/etc/sysctl.d/50-network-hardening.conf
yes | cp -rf $BIN_DIR/etc/system_state/system_state.ini  $TGT_DIR/etc/system_state/system_state.ini
yes | cp -rf $BIN_DIR/etc/display_mgr/display_mgr.ini    $TGT_DIR/etc/display_mgr/display_mgr.ini
yes | cp -rf $BIN_DIR/etc/doip.ini                       $TGT_DIR/etc/doip.ini
yes | cp -rf $BIN_DIR/etc/network_manager.ini            $TGT_DIR/etc/network_manager.ini
yes | cp -rf $BIN_DIR/etc/uds_core.ini                   $TGT_DIR/etc/uds_core.ini
yes | cp -rf $BIN_DIR/etc/uds_services.ini               $TGT_DIR/etc/uds_services.ini
yes | cp -rf $BIN_DIR/etc/system.conf                    $TGT_DIR/etc/systemd/

#################################################################
# Fix Permissions 755 - Read/execute by all, only root can modify
################################################################# 
chmod -R 755 $TGT_DIR/bin
chmod -R 755 $TGT_DIR/sbin
chmod -R 755 $TGT_DIR/usr/bin
chmod -R 755 $TGT_DIR/usr/sbin

############################################################
# Set Root Password
############################################################
echo "[+] Setting root password..."
# Generate SHA-512 hash (use openssl passwd -6 "yourpassword" to replace below securely)
ROOT_PWD_HASH='$6$5qnoxisvUCvapY.P$USf.m1HFgbm37lG6Njh3ektCOAV4H6lqRbhNdtZHMb9VBsfS8FCMzEC1bTZN9d/QvmtIcTtQIy2ZqZ89VAIPa.'  # replace with your real hash. Added hash for "root" password
 
 
# Replace root's line with hashed password
sed -i "s|^root:[^:]*:|root:${ROOT_PWD_HASH}:|" $TGT_DIR/etc/shadow
 
############################################################
# Create non-root user 'visteon' with password
############################################################
 
echo "[+] Adding visteon user to /etc/passwd and /etc/shadow manually"
 
# Ensure home dir exists
mkdir -p $TGT_DIR/home/visteon
#chown -R 1000:1000 $TGT_DIR/home/visteon
 
ls -ld $TGT_DIR/home/visteon
 
# Add to /etc/passwd
echo 'visteon:x:1000:1000:Visteon User:/home/visteon:/bin/sh' >> $TGT_DIR/etc/passwd
 
 
# Replace this hash with the one you generated
VIS_PWD_HASH='$6$ccqcON7a8fDKjBr.$4gZwO7iY0cN7JMaePHu0MouK7xVdbnQpix1SIddOGp4Zbq7uUtv4E0aDklGmnba8liKBgWFiLU2uY8XoCFMyh1'
 
chmod u+w $TGT_DIR/etc/shadow
 
# Append entry to /etc/shadow
echo "visteon:${VIS_PWD_HASH}:19392:0:99999:7:::" >> $TGT_DIR/etc/shadow

echo 'visteon:x:1000:' >> $TGT_DIR/etc/group
 
# Set correct permissions
chmod 644 $TGT_DIR/etc/passwd
chmod 600 $TGT_DIR/etc/shadow

############################################################
# Add systemd configuration Files
############################################################
yes | cp -rf $BIN_DIR/etc/systemd/system/*                         $TGT_DIR/lib/systemd/system/

############################################################
# Enable the services and map it to sysinit.target
############################################################
cd $TGT_DIR/etc/systemd/system/sysinit.target.wants
ln -sf /lib/systemd/system/hmi-app.service           $TGT_DIR/etc/systemd/system/sysinit.target.wants/hmi-app.service
ln -sf /lib/systemd/system/safeHmi.service           $TGT_DIR/etc/systemd/system/sysinit.target.wants/safeHmi.service
ln -sf /lib/systemd/system/vmf.service               $TGT_DIR/etc/systemd/system/sysinit.target.wants/vmf.service
#ln -sf /lib/systemd/system/vmf.path                  $TGT_DIR/etc/systemd/system/sysinit.target.wants/vmf.path
ln -sf /lib/systemd/system/display_mgr.service       $TGT_DIR/etc/systemd/system/sysinit.target.wants/display_mgr.service
ln -sf /lib/systemd/system/power_mgr.service         $TGT_DIR/etc/systemd/system/sysinit.target.wants/power_mgr.service
ln -sf /lib/systemd/system/display_powerup.service   $TGT_DIR/etc/systemd/system/sysinit.target.wants/display_powerup.service
ln -sf /lib/systemd/system/ucl_proxy_vmf.service     $TGT_DIR/etc/systemd/system/sysinit.target.wants/ucl_proxy_vmf.service
ln -sf /lib/systemd/system/bl_ucl_proxy_vmf.service      $TGT_DIR/etc/systemd/system/sysinit.target.wants/bl_ucl_proxy_vmf.service
ln -sf /lib/systemd/system/dlt-daemon.service        $TGT_DIR/etc/systemd/system/sysinit.target.wants/dlt-daemon.service
ln -sf /lib/systemd/system/dlt-system.service        $TGT_DIR/etc/systemd/system/sysinit.target.wants/dlt-system.service
ln -sf /lib/systemd/system/dlt_gateway.service        $TGT_DIR/etc/systemd/system/sysinit.target.wants/dlt_gateway.service
ln -sf /lib/systemd/system/mount_primary.service     $TGT_DIR/etc/systemd/system/sysinit.target.wants/mount_primary.service
ln -sf /lib/systemd/system/mount_recovery.service     $TGT_DIR/etc/systemd/system/sysinit.target.wants/mount_recovery.service
ln -sf /lib/systemd/system/crash_kernel.service      $TGT_DIR/etc/systemd/system/sysinit.target.wants/crash_kernel.service
ln -sf /etc/systemd/system/home-visteon.service      $TGT_DIR/etc/systemd/system/multi-user.target.wants/home-visteon.service
ln -sf /lib/systemd/system/health_mgr.service        $TGT_DIR/etc/systemd/system/multi-user.target.wants/health_mgr.service
ln -sf /lib/systemd/system/meet_app.service          $TGT_DIR/etc/systemd/system/multi-user.target.wants/meet_app.service
ln -sf /lib/systemd/system/diag_app_gp.service       $TGT_DIR/etc/systemd/system/multi-user.target.wants/diag_app_gp.service
ln -sf /lib/systemd/system/network_mgr.service       $TGT_DIR/etc/systemd/system/multi-user.target.wants/network_mgr.service
ln -sf /lib/systemd/system/fota_app.service	     	 $TGT_DIR/etc/systemd/system/multi-user.target.wants/fota_app.service
ln -sf /lib/systemd/system/bl_app_gp.service         $TGT_DIR/etc/systemd/system/multi-user.target.wants/bl_app_gp.service
ln -sf /lib/systemd/system/bl_ucl_proxy_vmf.service  $TGT_DIR/etc/systemd/system/multi-user.target.wants/bl_ucl_proxy_vmf.service
ln -sf /dev/null $TGT_DIR/etc/systemd/system/network-online.target.wants/systemd-networkd-wait-online.service
ln -sf /dev/null $TGT_DIR/etc/systemd/system/systemd-resolved.service
ln -sf /dev/null $TGT_DIR/etc/systemd/system/dbus-org.freedesktop.network1.service
ln -sf /dev/null $TGT_DIR/etc/systemd/system/dbus-org.freedesktop.resolve1.service
ln -sf /dev/null $TGT_DIR/etc/systemd/system/systemd-timesyncd.service
ln -sf /dev/null $TGT_DIR/etc/systemd/system/getty@.service
ln -sf /dev/null $TGT_DIR/etc/systemd/system/autovt@.service
ln -sf /dev/null $TGT_DIR/etc/systemd/system/dbus-org.freedesktop.locale1.service
ln -sf /dev/null $TGT_DIR/etc/systemd/system/dbus-org.freedesktop.timedate1.service
ln -sf /dev/null $TGT_DIR/etc/systemd/system/systemd-timedated.service
ln -sf /dev/null $TGT_DIR/etc/systemd/system/systemd-localed.service
ln -sf /dev/null $TGT_DIR/etc/systemd/system/systemd-hwdb-update.service
ln -sf /dev/null $TGT_DIR/etc/systemd/system/systemd-journal-flush.service
ln -sf /dev/null $TGT_DIR/etc/systemd/system/systemd-pstore.service
ln -sf /dev/null $TGT_DIR/etc/systemd/system/systemd-ask-password-console.service
ln -sf /dev/null $TGT_DIR/etc/systemd/system/pam_namespace.service
ln -sf /dev/null $TGT_DIR/etc/systemd/system/rc-local.service
ln -sf /dev/null $TGT_DIR/etc/systemd/system/systemd-ask-password-console.path
ln -sf /dev/null $TGT_DIR/etc/systemd/system/sync-clocks.service
ln -sf /dev/null $TGT_DIR/lib/systemd/system/dlt.service

mkdir -p $TGT_DIR/etc/systemd/system-generators/
ln -sf /dev/null $TGT_DIR/etc/systemd/system-generators/systemd-gpt-auto-generator
ln -sf /dev/null $TGT_DIR/etc/systemd/system-generators/systemd-debug-generator
ln -sf /dev/null $TGT_DIR/etc/systemd/system-generators/systemd-hibernate-resume-generator
ln -sf /dev/null $TGT_DIR/etc/systemd/system-generators/systemd-rc-local-generator
ln -sf /dev/null $TGT_DIR/etc/systemd/system-generators/systemd-run-generator
ln -sf /dev/null $TGT_DIR/etc/systemd/system-generators/systemd-system-update-generator
ln -sf /dev/null $TGT_DIR/etc/systemd/system-generators/systemd-sysv-generator
#ln -sf /lib/systemd/system/systemd-networkd-wait-online.service   $TGT_DIR/etc/systemd/system/network-online.target.wants/systemd-networkd-wait-online.service

############################################################
# Udev Rules Optimization
############################################################
rm -rf $TGT_DIR/etc/udev/rules.d/*
rm -rf $TGT_DIR/etc/udev/scripts/*
rm -rf $TGT_DIR/lib/udev/rules.d/*
rm -rf $TGT_DIR/lib/udev/hwdb.d/*
cp $BIN_DIR/etc/local.rules                   $TGT_DIR/etc/udev/rules.d/local.rules
