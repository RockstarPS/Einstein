.PHONY: spl_create_copy
.PHONY: vision_apps_create_copy vision_apps_hs_create_copy
.PHONY: sbl_ethfw_create_copy sbl_ethfw_hs_create_copy
.PHONY: sbl_echo_create_copy sbl_echo_hs_create_copy
.PHONY: tar_built_filesystems
.PHONY: create_all_platform_packages

FS_DIR_SPL_BOOTFS?=$(PSDK_QNX_PATH)/fs_dir/bootfs_spl
FS_DIR_SPL_VISION_APPS_BOOTFS?=$(PSDK_QNX_PATH)/fs_dir/bootfs_spl_vision_apps
FS_DIR_QNXFS?=$(PSDK_QNX_PATH)/fs_dir/qnxfs
FS_DIR_VISION_APPS_QNXFS?=$(PSDK_QNX_PATH)/fs_dir/qnxfs_vision_apps
FS_DIR_SBL_VISION_APPS_BOOTFS?=$(PSDK_QNX_PATH)/fs_dir/bootfs_sbl_vision_apps
FS_DIR_SBL_VISION_APPS_HS_BOOTFS?=$(PSDK_QNX_PATH)/fs_dir/bootfs_sbl_vision_apps_hs
FS_DIR_SBL_ETHFW_BOOTFS?=$(PSDK_QNX_PATH)/fs_dir/bootfs_sbl_ethfw
FS_DIR_SBL_ETHFW_HS_BOOTFS?=$(PSDK_QNX_PATH)/fs_dir/bootfs_sbl_ethfw_hs
FS_DIR_ETHFW_ROOTFS?=$(PSDK_QNX_PATH)/fs_dir/rootfs_ethfw
FS_DIR_SBL_ECHO_BOOTFS?=$(PSDK_QNX_PATH)/fs_dir/bootfs_sbl_echo
FS_DIR_SBL_ECHO_HS_BOOTFS?=$(PSDK_QNX_PATH)/fs_dir/bootfs_sbl_echo_hs
FS_DIR_ECHO_ROOTFS?=$(PSDK_QNX_PATH)/fs_dir/rootfs_echo
FS_DIR_VISION_APPS_ROOTFS?=$(PSDK_QNX_PATH)/fs_dir/rootfs_vision_apps

FS_TAR_SPL_BOOTFS?=$(PSDK_QNX_PATH)/fs_tar/bootfs_spl_$(PSDK_QNX_TAGID).tar.gz
FS_TAR_SPL_VISION_APPS_BOOTFS?=$(PSDK_QNX_PATH)/fs_tar/bootfs_spl_vision_apps_$(PSDK_QNX_TAGID).tar.gz
FS_TAR_QNXFS?=$(PSDK_QNX_PATH)/fs_tar/qnxfs_$(PSDK_QNX_TAGID).tar.gz
FS_TAR_VISION_APPS_QNXFS?=$(PSDK_QNX_PATH)/fs_tar/qnxfs_vision_apps_$(PSDK_QNX_TAGID).tar.gz
FS_TAR_SBL_VISION_APPS_BOOTFS?=$(PSDK_QNX_PATH)/fs_tar/bootfs_sbl_vision_apps_$(PSDK_QNX_TAGID).tar.gz
FS_TAR_SBL_VISION_APPS_HS_BOOTFS?=$(PSDK_QNX_PATH)/fs_tar/bootfs_sbl_vision_apps_hs_$(PSDK_QNX_TAGID).tar.gz
FS_TAR_SBL_ETHFW_BOOTFS?=$(PSDK_QNX_PATH)/fs_tar/bootfs_sbl_ethfw_$(PSDK_QNX_TAGID).tar.gz
FS_TAR_SBL_ETHFW_HS_BOOTFS?=$(PSDK_QNX_PATH)/fs_tar/bootfs_sbl_ethfw_hs_$(PSDK_QNX_TAGID).tar.gz
FS_TAR_SBL_ETHFW_ROOTFS?=$(PSDK_QNX_PATH)/fs_tar/rootfs_ethfw_$(PSDK_QNX_TAGID).tar.xz
FS_TAR_SBL_ECHO_BOOTFS?=$(PSDK_QNX_PATH)/fs_tar/bootfs_sbl_echo_$(PSDK_QNX_TAGID).tar.gz
FS_TAR_SBL_ECHO_HS_BOOTFS?=$(PSDK_QNX_PATH)/fs_tar/bootfs_sbl_echo_hs_$(PSDK_QNX_TAGID).tar.gz
FS_TAR_SBL_ECHO_ROOTFS?=$(PSDK_QNX_PATH)/fs_tar/rootfs_echo_$(PSDK_QNX_TAGID).tar.xz
FS_TAR_VISION_APPS_ROOTFS?=$(PSDK_QNX_PATH)/fs_tar/rootfs_vision_apps_$(PSDK_QNX_TAGID).tar.xz

NUM_PROCS?=$(shell nproc)
NUM_THREADS?=$(shell expr $(NUM_PROCS) - 1)

spl_create_copy:
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/makefile 										clean
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/makefile 										all
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/makefile 										qnx_fs_create
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/makefile 										qnx_fs_copy_spl_uboot
	mkdir -p $(FS_DIR_SPL_BOOTFS)/
	mkdir -p $(FS_DIR_QNXFS)/
	cp -rfL $(PSDK_QNX_PATH)/bootfs/*												$(FS_DIR_SPL_BOOTFS)/
	cp -rfL $(PSDK_QNX_PATH)/qnxfs/*												$(FS_DIR_QNXFS)/
	mkdir -p $(FS_DIR_QNXFS)/version/images
	cp -rfL $(PSDK_QNX_PATH)/qnx/bsp/images/*.raw									$(FS_DIR_QNXFS)/version/images/
	cp -rfL $(PSDK_QNX_PATH)/qnx/bsp/images/*.build									$(FS_DIR_QNXFS)/version/images/
	cp -rfL $(PSDK_QNX_PATH)/qnx/bsp/readme.txt										$(FS_DIR_QNXFS)/version/bsp_version_info.txt
ifeq ($(SOC),$(filter $(SOC), j7200))
	cp -rfL $(LINUX_FS_BOOT_PATH)/tiboot3.bin										$(FS_DIR_SPL_BOOTFS)/
	cp -rfL $(LINUX_FS_BOOT_PATH)/tispl.bin											$(FS_DIR_SPL_BOOTFS)/
	cp -rfL $(LINUX_FS_BOOT_PATH)/u-boot.img										$(FS_DIR_SPL_BOOTFS)/
endif

vision_apps_create_copy:
	cd $(VISION_APPS_PATH) && \
	$(MAKE) sdk_scrub -j$(NUM_THREADS) BUILD_QNX_A72=yes BUILD_LINUX_A72=no && \
	$(MAKE) sdk -j$(NUM_THREADS) BUILD_QNX_A72=yes BUILD_LINUX_A72=no && \
	$(MAKE) qnx_fs_create -j$(NUM_THREADS) BUILD_QNX_A72=yes BUILD_LINUX_A72=no && \
	$(MAKE) qnx_fs_copy_spl_uboot -j$(NUM_THREADS) BUILD_QNX_A72=yes BUILD_LINUX_A72=no && \
	$(MAKE) qnx_fs_install -j$(NUM_THREADS) BUILD_QNX_A72=yes BUILD_LINUX_A72=no && \
	$(MAKE) sbl_bootimage BUILD_QNX_A72=yes BUILD_LINUX_A72=no
	mkdir -p $(FS_DIR_SPL_VISION_APPS_BOOTFS)/
	mkdir -p $(FS_DIR_SBL_VISION_APPS_BOOTFS)/
	mkdir -p $(FS_DIR_SBL_VISION_APPS_HS_BOOTFS)/
	mkdir -p $(FS_DIR_VISION_APPS_ROOTFS)/lib/firmware/
	mkdir -p $(FS_DIR_VISION_APPS_QNXFS)/version/images
	cp -rfL $(PSDK_QNX_PATH)/bootfs/*												$(FS_DIR_SPL_VISION_APPS_BOOTFS)/
	cp -rfL $(PSDK_QNX_PATH)/qnxfs/*												$(FS_DIR_VISION_APPS_QNXFS)/
	cp -rfL $(PSDK_QNX_PATH)/qnx/bsp/images/*.raw									$(FS_DIR_VISION_APPS_QNXFS)/version/images/
	cp -rfL $(PSDK_QNX_PATH)/qnx/bsp/images/*.build									$(FS_DIR_VISION_APPS_QNXFS)/version/images/
	cp -rfL $(PSDK_QNX_PATH)/qnx/bsp/readme.txt										$(FS_DIR_VISION_APPS_QNXFS)/version/bsp_version_info.txt
	cp -rfL $(VISION_APPS_PATH)/out/sbl_bootfiles/tiboot3.bin						$(FS_DIR_SBL_VISION_APPS_BOOTFS)/
	cp -rfL $(VISION_APPS_PATH)/out/sbl_bootfiles/tifs.bin							$(FS_DIR_SBL_VISION_APPS_BOOTFS)/
	cp -rfL $(VISION_APPS_PATH)/out/sbl_bootfiles/app								$(FS_DIR_SBL_VISION_APPS_BOOTFS)/
	cp -rfL $(VISION_APPS_PATH)/out/sbl_bootfiles/lateapp*							$(FS_DIR_SBL_VISION_APPS_BOOTFS)/
	cp -rfL $(VISION_APPS_PATH)/out/sbl_bootfiles/atf_optee.appimage				$(FS_DIR_SBL_VISION_APPS_BOOTFS)/
	cp -rfL $(VISION_APPS_PATH)/out/sbl_bootfiles/ifs_qnx.appimage					$(FS_DIR_SBL_VISION_APPS_BOOTFS)/
	cp -rfv $(PSDK_QNX_PATH)/rootfs/*												$(FS_DIR_VISION_APPS_ROOTFS)/

vision_apps_hs_create_copy:
	cd $(VISION_APPS_PATH) && \
	$(MAKE) sdk_scrub -j$(NUM_THREADS) BUILD_QNX_A72=yes BUILD_LINUX_A72=no && \
	$(MAKE) sdk -j$(NUM_THREADS) BUILD_QNX_A72=yes BUILD_LINUX_A72=no && \
	$(MAKE) qnx_fs_create -j$(NUM_THREADS) BUILD_QNX_A72=yes BUILD_LINUX_A72=no && \
	$(MAKE) qnx_fs_copy_spl_uboot -j$(NUM_THREADS) BUILD_QNX_A72=yes BUILD_LINUX_A72=no && \
	$(MAKE) qnx_fs_install -j$(NUM_THREADS) BUILD_QNX_A72=yes BUILD_LINUX_A72=no && \
	$(MAKE) sbl_bootimage_hs BUILD_QNX_A72=yes BUILD_LINUX_A72=no
	mkdir -p $(FS_DIR_SBL_VISION_APPS_HS_BOOTFS)/
	cp -rfL $(VISION_APPS_PATH)/out/sbl_bootfiles/tiboot3.bin.signed				$(FS_DIR_SBL_VISION_APPS_HS_BOOTFS)/tiboot3.bin
	cp -rfL $(VISION_APPS_PATH)/out/sbl_bootfiles/tifs.bin.signed					$(FS_DIR_SBL_VISION_APPS_HS_BOOTFS)/tifs.bin
	cp -rfL $(VISION_APPS_PATH)/out/sbl_bootfiles/app.signed						$(FS_DIR_SBL_VISION_APPS_HS_BOOTFS)/app
	cp -rfL $(VISION_APPS_PATH)/out/sbl_bootfiles/lateapp1.signed					$(FS_DIR_SBL_VISION_APPS_HS_BOOTFS)/lateapp1
	cp -rfL $(VISION_APPS_PATH)/out/sbl_bootfiles/lateapp2.signed					$(FS_DIR_SBL_VISION_APPS_HS_BOOTFS)/lateapp2
	cp -rfL $(VISION_APPS_PATH)/out/sbl_bootfiles/atf_optee.appimage.signed			$(FS_DIR_SBL_VISION_APPS_HS_BOOTFS)/atf_optee.appimage
	cp -rfL $(VISION_APPS_PATH)/out/sbl_bootfiles/ifs_qnx.appimage.signed			$(FS_DIR_SBL_VISION_APPS_HS_BOOTFS)/ifs_qnx.appimage

sbl_ethfw_create_copy:
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/makefile										clean
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/makefile 										all
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/makefile 										qnx_fs_create
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/makefile 										sbl_ethfw_clean
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/makefile 										sbl_ethfw
	mkdir -p $(FS_DIR_SBL_ETHFW_BOOTFS)/
	mkdir -p $(FS_DIR_ETHFW_ROOTFS)/lib/firmware/
	cp -rfL $(PSDK_QNX_PATH)/sbl_ethfw_bootfiles/tiboot3.bin						$(FS_DIR_SBL_ETHFW_BOOTFS)/
	cp -rfL $(PSDK_QNX_PATH)/sbl_ethfw_bootfiles/tifs.bin							$(FS_DIR_SBL_ETHFW_BOOTFS)/
	cp -rfL $(PSDK_QNX_PATH)/sbl_ethfw_bootfiles/app								$(FS_DIR_SBL_ETHFW_BOOTFS)/
	cp -rfL $(PSDK_QNX_PATH)/sbl_ethfw_bootfiles/lateapp*							$(FS_DIR_SBL_ETHFW_BOOTFS)/
	cp -rfL $(PSDK_QNX_PATH)/sbl_ethfw_bootfiles/atf_optee.appimage					$(FS_DIR_SBL_ETHFW_BOOTFS)/
	cp -rfL $(PSDK_QNX_PATH)/sbl_ethfw_bootfiles/ifs_qnx.appimage					$(FS_DIR_SBL_ETHFW_BOOTFS)/
	cp -rfv $(PSDK_QNX_PATH)/ethfw_firmware/*										$(FS_DIR_ETHFW_ROOTFS)/lib/firmware/

sbl_ethfw_hs_create_copy:
	cd $(PSDK_QNX_PATH)/qnx && \
	$(MAKE) clean -j$(NUM_THREADS) && \
	$(MAKE) all -j$(NUM_THREADS) && \
	$(MAKE) qnx_fs_create -j$(NUM_THREADS)
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/makefile 										sbl_ethfw_clean_hs
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/makefile 										sbl_ethfw_hs
	mkdir -p $(FS_DIR_SBL_ETHFW_HS_BOOTFS)/
	cp -rfL $(PSDK_QNX_PATH)/sbl_ethfw_bootfiles_hs/tiboot3.bin						$(FS_DIR_SBL_ETHFW_HS_BOOTFS)/
ifeq ($(SOC),$(filter $(SOC), j7200))
	cp -rfL $(PSDK_QNX_PATH)/sbl_ethfw_bootfiles_hs/tifs.bin.sr2.0					$(FS_DIR_SBL_ETHFW_HS_BOOTFS)/tifs.bin
endif
ifeq ($(SOC),$(filter $(SOC), j721e))
	cp -rfL $(PSDK_QNX_PATH)/sbl_ethfw_bootfiles_hs/tifs.bin.sr1.1					$(FS_DIR_SBL_ETHFW_HS_BOOTFS)/tifs.bin
endif
ifeq ($(SOC),$(filter $(SOC), j784s4))
	cp -rfL $(PSDK_QNX_PATH)/sbl_ethfw_bootfiles_hs/tifs.bin						$(FS_DIR_SBL_ETHFW_HS_BOOTFS)/tifs.bin
endif
	cp -rfL $(PSDK_QNX_PATH)/sbl_ethfw_bootfiles_hs/app								$(FS_DIR_SBL_ETHFW_HS_BOOTFS)/
	cp -rfL $(PSDK_QNX_PATH)/sbl_ethfw_bootfiles_hs/lateapp*						$(FS_DIR_SBL_ETHFW_HS_BOOTFS)/
	cp -rfL $(PSDK_QNX_PATH)/sbl_ethfw_bootfiles_hs/atf_optee.appimage				$(FS_DIR_SBL_ETHFW_HS_BOOTFS)/
	cp -rfL $(PSDK_QNX_PATH)/sbl_ethfw_bootfiles_hs/ifs_qnx.appimage				$(FS_DIR_SBL_ETHFW_HS_BOOTFS)/

sbl_echo_create_copy:
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/makefile 										clean
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/makefile 										all
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/makefile 										qnx_fs_create
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/makefile 										sbl_echo_test_clean
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/makefile 										sbl_echo_test
	mkdir -p $(FS_DIR_SBL_ECHO_BOOTFS)/
	mkdir -p $(FS_DIR_ECHO_ROOTFS)/lib/firmware/
	cp -rfL $(PSDK_QNX_PATH)/sbl_echo_bootfiles/tiboot3.bin							$(FS_DIR_SBL_ECHO_BOOTFS)/
	cp -rfL $(PSDK_QNX_PATH)/sbl_echo_bootfiles/tifs.bin							$(FS_DIR_SBL_ECHO_BOOTFS)/
	cp -rfL $(PSDK_QNX_PATH)/sbl_echo_bootfiles/app									$(FS_DIR_SBL_ECHO_BOOTFS)/
	cp -rfL $(PSDK_QNX_PATH)/sbl_echo_bootfiles/lateapp*							$(FS_DIR_SBL_ECHO_BOOTFS)/
	cp -rfL $(PSDK_QNX_PATH)/sbl_echo_bootfiles/atf_optee.appimage					$(FS_DIR_SBL_ECHO_BOOTFS)/
	cp -rfL $(PSDK_QNX_PATH)/sbl_echo_bootfiles/ifs_qnx.appimage					$(FS_DIR_SBL_ECHO_BOOTFS)/
	cp -rfv $(PSDK_QNX_PATH)/echo_firmware/*										$(FS_DIR_ECHO_ROOTFS)/lib/firmware

sbl_echo_hs_create_copy:
	cd $(PSDK_QNX_PATH)/qnx && \
	$(MAKE) clean -j$(NUM_THREADS) && \
	$(MAKE) all -j$(NUM_THREADS) && \
	$(MAKE) qnx_fs_create -j$(NUM_THREADS)
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/makefile 										sbl_echo_test_clean_hs
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/makefile 										sbl_echo_test_hs
	mkdir -p $(FS_DIR_SBL_ECHO_HS_BOOTFS)/
	cp -rfL $(PSDK_QNX_PATH)/sbl_echo_bootfiles_hs/tiboot3.bin						$(FS_DIR_SBL_ECHO_HS_BOOTFS)/
ifeq ($(SOC),$(filter $(SOC), j7200))
	cp -rfL $(PSDK_QNX_PATH)/sbl_echo_bootfiles_hs/tifs.bin.sr2.0					$(FS_DIR_SBL_ECHO_HS_BOOTFS)/tifs.bin
endif
ifeq ($(SOC),$(filter $(SOC), j721e))
	cp -rfL $(PSDK_QNX_PATH)/sbl_echo_bootfiles_hs/tifs.bin.sr1.1					$(FS_DIR_SBL_ECHO_HS_BOOTFS)/tifs.bin
endif
ifeq ($(SOC),$(filter $(SOC), j721s2 j784s4))
	cp -rfL $(PSDK_QNX_PATH)/sbl_echo_bootfiles_hs/tifs.bin							$(FS_DIR_SBL_ECHO_HS_BOOTFS)/tifs.bin
endif
	cp -rfL $(PSDK_QNX_PATH)/sbl_echo_bootfiles_hs/app								$(FS_DIR_SBL_ECHO_HS_BOOTFS)/
	cp -rfL $(PSDK_QNX_PATH)/sbl_echo_bootfiles_hs/lateapp*							$(FS_DIR_SBL_ECHO_HS_BOOTFS)/
	cp -rfL $(PSDK_QNX_PATH)/sbl_echo_bootfiles_hs/atf_optee.appimage				$(FS_DIR_SBL_ECHO_HS_BOOTFS)/
	cp -rfL $(PSDK_QNX_PATH)/sbl_echo_bootfiles_hs/ifs_qnx.appimage					$(FS_DIR_SBL_ECHO_HS_BOOTFS)/

tar_built_filesystems:
	mkdir -p $(PSDK_QNX_PATH)/fs_tar/
	if [ -f $(FS_TAR_SPL_BOOTFS) ]; then rm -rf $(FS_TAR_SPL_BOOTFS); fi
	if [ -f $(FS_TAR_QNXFS) ]; then rm -rf $(FS_TAR_QNXFS); fi
ifneq ($(SOC),$(filter $(SOC), j721s2))
	if [ -f $(FS_TAR_SBL_ETHFW_BOOTFS) ]; then rm -rf $(FS_TAR_SBL_ETHFW_BOOTFS); fi
	if [ -f $(FS_TAR_SBL_ETHFW_HS_BOOTFS) ]; then rm -rf $(FS_TAR_SBL_ETHFW_HS_BOOTFS); fi
	if [ -f $(FS_TAR_SBL_ETHFW_ROOTFS) ]; then rm -rf $(FS_TAR_SBL_ETHFW_ROOTFS); fi
endif
	if [ -f $(FS_TAR_SBL_ECHO_BOOTFS) ]; then rm -rf $(FS_TAR_SBL_ECHO_BOOTFS); fi
	if [ -f $(FS_TAR_SBL_ECHO_HS_BOOTFS) ]; then rm -rf $(FS_TAR_SBL_ECHO_HS_BOOTFS); fi
	if [ -f $(FS_TAR_SBL_ECHO_ROOTFS) ]; then rm -rf $(FS_TAR_SBL_ECHO_ROOTFS); fi
ifneq ($(SOC),$(filter $(SOC), j7200))
	if [ -f $(FS_TAR_SPL_VISION_APPS_BOOTFS) ]; then rm -rf $(FS_TAR_SPL_VISION_APPS_BOOTFS); fi
	if [ -f $(FS_TAR_VISION_APPS_QNXFS) ]; then rm -rf $(FS_TAR_VISION_APPS_QNXFS); fi
	if [ -f $(FS_TAR_SBL_VISION_APPS_BOOTFS) ]; then rm -rf $(FS_TAR_SBL_VISION_APPS_BOOTFS); fi
	if [ -f $(FS_TAR_SBL_VISION_APPS_HS_BOOTFS) ]; then rm -rf $(FS_TAR_SBL_VISION_APPS_HS_BOOTFS); fi
	if [ -f $(FS_TAR_VISION_APPS_ROOTFS) ]; then rm -rf $(FS_TAR_VISION_APPS_ROOTFS); fi
endif

	if [ -d $(FS_DIR_QNXFS) ]; then cd $(FS_DIR_QNXFS); tar -zcvf $(FS_TAR_QNXFS) .; cd -; fi
	if [ -d $(FS_DIR_SPL_BOOTFS) ]; then cd $(FS_DIR_SPL_BOOTFS); tar -zcvf $(FS_TAR_SPL_BOOTFS) .; cd -; fi
ifneq ($(SOC),$(filter $(SOC), j721s2))
	if [ -d $(FS_DIR_SBL_ETHFW_BOOTFS) ]; then cd $(FS_DIR_SBL_ETHFW_BOOTFS); tar -zcvf $(FS_TAR_SBL_ETHFW_BOOTFS) .; cd -; fi
	if [ -d $(FS_DIR_SBL_ETHFW_HS_BOOTFS) ]; then cd $(FS_DIR_SBL_ETHFW_HS_BOOTFS); tar -zcvf $(FS_TAR_SBL_ETHFW_HS_BOOTFS) .; cd -; fi
	if [ -d $(FS_DIR_ETHFW_ROOTFS) ]; then cd $(FS_DIR_ETHFW_ROOTFS); tar -pczvf $(FS_TAR_SBL_ETHFW_ROOTFS) .; cd -; fi
endif
	if [ -d $(FS_DIR_SBL_ECHO_BOOTFS) ]; then cd $(FS_DIR_SBL_ECHO_BOOTFS); tar -zcvf $(FS_TAR_SBL_ECHO_BOOTFS) .; cd -; fi
	if [ -d $(FS_DIR_SBL_ECHO_HS_BOOTFS) ]; then cd $(FS_DIR_SBL_ECHO_HS_BOOTFS); tar -zcvf $(FS_TAR_SBL_ECHO_HS_BOOTFS) .; cd -; fi
	if [ -d $(FS_DIR_ECHO_ROOTFS) ]; then cd $(FS_DIR_ECHO_ROOTFS); tar -pczvf $(FS_TAR_SBL_ECHO_ROOTFS) .; cd -; fi
ifneq ($(SOC),$(filter $(SOC), j7200))
	if [ -d $(FS_DIR_SPL_VISION_APPS_BOOTFS) ]; then cd $(FS_DIR_SPL_VISION_APPS_BOOTFS); tar -zcvf $(FS_TAR_SPL_VISION_APPS_BOOTFS) .; cd -; fi
	if [ -d $(FS_DIR_VISION_APPS_QNXFS) ]; then cd $(FS_DIR_VISION_APPS_QNXFS); tar -zcvf $(FS_TAR_VISION_APPS_QNXFS) .; cd -; fi
	if [ -d $(FS_DIR_SBL_VISION_APPS_BOOTFS) ]; then cd $(FS_DIR_SBL_VISION_APPS_BOOTFS); tar -zcvf $(FS_TAR_SBL_VISION_APPS_BOOTFS) .; cd -; fi
	if [ -d $(FS_DIR_SBL_VISION_APPS_HS_BOOTFS) ]; then cd $(FS_DIR_SBL_VISION_APPS_HS_BOOTFS); tar -zcvf $(FS_TAR_SBL_VISION_APPS_HS_BOOTFS) .; cd -; fi
	if [ -d $(FS_DIR_VISION_APPS_ROOTFS) ]; then cd $(FS_DIR_VISION_APPS_ROOTFS); tar -pczvf $(FS_TAR_VISION_APPS_ROOTFS) .; cd -; fi
endif

create_all_platform_packages:
	cd $(PSDK_QNX_PATH)/qnx && \
	$(MAKE) scrub -j$(NUM_THREADS) && \
	$(MAKE) qnx_spl_create_copy -j$(NUM_THREADS)
ifneq ($(SOC),$(filter $(SOC), j721s2))
	cd $(PSDK_QNX_PATH)/qnx && \
	$(MAKE) qnx_sbl_ethfw_create_copy -j$(NUM_THREADS)
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/scripts/automation/qnx_automation.mak			sbl_ethfw_hs_create_copy
endif
	cd $(PSDK_QNX_PATH)/qnx && \
	$(MAKE) qnx_sbl_echo_create_copy -j$(NUM_THREADS)
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/scripts/automation/qnx_automation.mak			sbl_echo_hs_create_copy
ifneq ($(SOC),$(filter $(SOC), j7200))
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/scripts/automation/qnx_automation.mak			vision_apps_create_copy
	$(MAKE) -f $(PSDK_QNX_PATH)/qnx/scripts/automation/qnx_automation.mak			vision_apps_hs_create_copy
endif
	cd $(PSDK_QNX_PATH)/qnx && \
	$(MAKE) qnx_tar_built_filesystems -j$(NUM_THREADS)
