--------------------------------------------------------------------------------------
#Code change to be done in the gp_program.cmake (In gp-build):

${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/services/ipsec/ipsec_start.cmake
${CMAKE_SOURCE_DIR}/cluster-platform/dijkstra/services/ipsec/test/ipsec_test.cmake

-------------------------------------------------------------------------------------

#Code changes to be done in the copy-rootfs-partition.sh and copy-system-partition.sh (In img-build): 

#Integrate the changes done for ipsec, swanctl and strongswan

#NOTE: The swanctl.conf given here is w.r.t BMW, like that it needs to be modified for the corresponding program.

#copy-rootfs-partition.sh

## Create Required Directories
mkdir -p $TGT_DIR/usr/bin/ipsec_start

## Test Application
chmod -R 700 $TGT_DIR/etc/swanctl/*
chmod -R 700 $TGT_DIR/etc/strongswan.d/*

yes | rm -rf $TGT_DIR/etc/swanctl/swanctl.conf
yes | rm -rf $TGT_DIR/etc/strongswan.d/charon-systemd.conf

ln -sf /persist/device1-key.pem                                               $TGT_DIR/etc/swanctl/private/device1-key.pem

yes | cp -rf $BIN_DIR/../../../../../gp-build/strongswan_swanctl/*            $TGT_DIR/etc/swanctl/
yes | cp -rf $BIN_DIR/../../../../../gp-build/strongswan.d/charon-systemd.conf    $TGT_DIR/etc/strongswan.d/charon-systemd.conf
yes | cp -rf $BIN_DIR/../../../../../gp-build/strongswan.d/pkcs11_plugin.conf     $TGT_DIR/etc/strongswan.d/pkcs11_plugin.conf

ln -sf /persist/swanctl_tmp.conf                                             $TGT_DIR/etc/swanctl/swanctl.conf
ln -sf /persist/device1-cert.pem                                              $TGT_DIR/etc/swanctl/x509/device1-cert.pem
ln -sf /etc/systemd/system/ipsec_starter.service                              $TGT_DIR/etc/systemd/system/multi-user.target.wants/ipsec_starter.service

yes | cp -rf $BIN_DIR/aarch64le/usr/bin/ipsec_start                           $TGT_DIR/usr/bin/ipsec_start/

chmod -R 700 $TGT_DIR/etc/swanctl/*
chmod -R 700 $TGT_DIR/etc/strongswan.d/*

------------------------------------------------------------------------------------
#copy-system-partition.sh:

yes | cp -rf $BIN_DIR/aarch64le/usr/bin/ipsec_test			$TGT_DIR/usr/bin/ipsec_test

--------------------------------------------------------------------------------------

# Add these file in the path -> programs/reference/einstein4.0/ti-am62x/gp-build/linux/prebuilt_common/etc/systemd/system

#Files: (It is archived in the folder - strongswan_swanctl)

1) ipsec_starter.service
2) strongswan-swanctl.service

---------------------------------------------------------------------------------------



    