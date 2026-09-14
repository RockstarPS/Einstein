.PHONY: qnx_sdk copy_spl_uboot

# override the default QNX_TARGET to point to staged mirror
#QNX_TARGET=$(PSDK_QNX_PATH)/qnx/qnx710_stage/qnx7

PROFILE ?= release
BOARD ?= j721e_evm

ifeq ($(PROFILE), $(filter $(PROFILE),release all))
BUILD_PROFILE_QNX_O=o.le
BUILD_PROFILE_QNX_SO=so.le
BUILD_PROFILE_QNX_D=dll.le
BUILD_PROFILE_QNX_SUFFIX=
endif
ifeq ($(PROFILE), $(filter $(PROFILE),debug))
BUILD_PROFILE_QNX_O=o.le.g
BUILD_PROFILE_QNX_SO=so.le.g
BUILD_PROFILE_QNX_D=dll.le.g
BUILD_PROFILE_QNX_SUFFIX=_g
endif

ifeq ($(BOARD),$(filter $(BOARD), j721e_evm))
  SOC = j721e
else ifeq ($(BOARD),$(filter $(BOARD), j7200_evm))
  SOC = j7200
else ifeq ($(BOARD),$(filter $(BOARD), j721s2_evm))
  SOC = j721s2
else ifeq ($(BOARD),$(filter $(BOARD), am62x_evm))
  SOC = am62x
else ifeq ($(BOARD),$(filter $(BOARD), am62a_evm))
  SOC = am62a
else ifeq ($(BOARD),$(filter $(BOARD), am62px_evm))
  SOC = am62px
else ifeq ($(BOARD),$(filter $(BOARD), j784s4_evm))
  SOC = j784s4
endif

qnx_sdk:
	########################
	##### Common Stuff #####
	########################
	## create needed dirs
	mkdir -p ${QNX_FS_PATH}/tilib
	mkdir -p ${QNX_FS_PATH}/tibin
	mkdir -p ${QNX_FS_PATH}/scripts
	mkdir -p ${QNX_FS_PATH}/tilib/firmware
	mkdir -p ${QNX_FS_PATH}/codec_test/bitstream
	mkdir -p ${QNX_FS_PATH}/codec_test/vpu/cfg
	mkdir -p ${QNX_FS_PATH}/codec_test/vpu/nv12
	mkdir -p ${QNX_FS_PATH}/codec_test/vpu/output
	
	######## ti bins & libs ######
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/pdk/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-pdk$(BUILD_PROFILE_QNX_SUFFIX).so                                $(QNX_FS_PATH)/tilib/libti-pdk$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/pdk/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-pdk$(BUILD_PROFILE_QNX_SUFFIX).so                                $(QNX_FS_PATH)/tilib/libti-pdk$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/sciclient/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-sciclient$(BUILD_PROFILE_QNX_SUFFIX).so                    $(QNX_FS_PATH)/tilib/libti-sciclient$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/sciclient/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-sciclient$(BUILD_PROFILE_QNX_SUFFIX).so                    $(QNX_FS_PATH)/tilib/libti-sciclient$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/udmalld/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-udmalld$(BUILD_PROFILE_QNX_SUFFIX).so                        $(QNX_FS_PATH)/tilib/libti-udmalld$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/udmalld/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-udmalld$(BUILD_PROFILE_QNX_SUFFIX).so                        $(QNX_FS_PATH)/tilib/libti-udmalld$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/ipclld/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-ipclld$(BUILD_PROFILE_QNX_SUFFIX).so                          $(QNX_FS_PATH)/tilib/libti-ipclld$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/ipclld/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-ipclld$(BUILD_PROFILE_QNX_SUFFIX).so                          $(QNX_FS_PATH)/tilib/libti-ipclld$(BUILD_PROFILE_QNX_SUFFIX).so.1
ifeq ($(SOC),$(filter $(SOC), am62a))
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/csirxlld/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-csirxlld$(BUILD_PROFILE_QNX_SUFFIX).so                      $(QNX_FS_PATH)/tilib/libti-csirxlld$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/csirxlld/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-csirxlld$(BUILD_PROFILE_QNX_SUFFIX).so                      $(QNX_FS_PATH)/tilib/libti-csirxlld$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/fvid2lld/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-fvid2lld$(BUILD_PROFILE_QNX_SUFFIX).so                      $(QNX_FS_PATH)/tilib/libti-fvid2lld$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/fvid2lld/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-fvid2lld$(BUILD_PROFILE_QNX_SUFFIX).so                      $(QNX_FS_PATH)/tilib/libti-fvid2lld$(BUILD_PROFILE_QNX_SUFFIX).so.1
endif

ifneq ($(SOC),$(filter $(SOC), am62x am62a am62px))
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/enetlld/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-enetlld$(BUILD_PROFILE_QNX_SUFFIX).so                        $(QNX_FS_PATH)/tilib/libti-enetlld$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/enetlld/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-enetlld$(BUILD_PROFILE_QNX_SUFFIX).so                        $(QNX_FS_PATH)/tilib/libti-enetlld$(BUILD_PROFILE_QNX_SUFFIX).so.1
endif
	cp -rfL $(PSDK_QNX_PATH)/qnx/resmgr/sciclient_qnx_rsmgr/aarch64/$(BUILD_PROFILE_QNX_O)/tisci-mgr$(BUILD_PROFILE_QNX_SUFFIX)                      $(QNX_FS_PATH)/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/resmgr/ipc_qnx_rsmgr/resmgr/aarch64/$(BUILD_PROFILE_QNX_O)/tiipc-mgr$(BUILD_PROFILE_QNX_SUFFIX)                     $(QNX_FS_PATH)/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/sharedmemallocator/resmgr/aarch64/$(BUILD_PROFILE_QNX_O)/shmemallocator$(BUILD_PROFILE_QNX_SUFFIX)                  $(QNX_FS_PATH)/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/resmgr/udma_qnx_rsmgr/resmgr/aarch64/$(BUILD_PROFILE_QNX_O)/tiudma-mgr$(BUILD_PROFILE_QNX_SUFFIX)                   $(QNX_FS_PATH)/tibin/
ifeq ($(SOC),$(filter $(SOC), j721s2 j784s4 am62a am62px))
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/resmgr/aarch64/$(BUILD_PROFILE_QNX_O)/ti-vpu-codec-mgr$(BUILD_PROFILE_QNX_SUFFIX)                         $(QNX_FS_PATH)/tibin/
endif
ifeq ($(SOC),$(filter $(SOC), j721e j7200 j721s2 j784s4))
	cp -rfL $(PSDK_QNX_PATH)/qnx/devnp/cpsw2g/aarch64/$(BUILD_PROFILE_QNX_D)/devnp-cpsw2g$(BUILD_PROFILE_QNX_SUFFIX).so                              $(QNX_FS_PATH)/tilib/
endif
ifeq ($(SOC),$(filter $(SOC), j721e))
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/encoder/driver/aarch64/$(BUILD_PROFILE_QNX_O)/vxe_enc$(BUILD_PROFILE_QNX_SUFFIX)                      $(QNX_FS_PATH)/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/decoder/driver/aarch64/$(BUILD_PROFILE_QNX_O)/vxd_dec$(BUILD_PROFILE_QNX_SUFFIX)                      $(QNX_FS_PATH)/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/devnp/cpsw9g/aarch64/$(BUILD_PROFILE_QNX_D)/devnp-cpsw9g$(BUILD_PROFILE_QNX_SUFFIX).so                              $(QNX_FS_PATH)/tilib/
else ifeq ($(SOC),$(filter $(SOC), j7200))
	cp -rfL $(PSDK_QNX_PATH)/qnx/devnp/cpsw5g/aarch64/$(BUILD_PROFILE_QNX_D)/devnp-cpsw5g$(BUILD_PROFILE_QNX_SUFFIX).so                              $(QNX_FS_PATH)/tilib/
else ifeq ($(SOC),$(filter $(SOC), j721s2))
	cp -rfL $(PSDK_QNX_PATH)/qnx/devnp/cpsw2g-main/aarch64/$(BUILD_PROFILE_QNX_D)/devnp-cpsw2g-main$(BUILD_PROFILE_QNX_SUFFIX).so                    $(QNX_FS_PATH)/tilib/
else ifeq ($(SOC),$(filter $(SOC), j784s4))
	cp -rfL $(PSDK_QNX_PATH)/qnx/devnp/cpsw9g/aarch64/$(BUILD_PROFILE_QNX_D)/devnp-cpsw9g$(BUILD_PROFILE_QNX_SUFFIX).so                              $(QNX_FS_PATH)/tilib/
endif
	cp -rfL $(PSDK_QNX_PATH)/qnx/resmgr/ipc_qnx_rsmgr/usr/aarch64/$(BUILD_PROFILE_QNX_SO)/libtiipc-usr$(BUILD_PROFILE_QNX_SUFFIX).so                 $(QNX_FS_PATH)/tilib/libtiipc-usr$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/resmgr/ipc_qnx_rsmgr/usr/aarch64/$(BUILD_PROFILE_QNX_SO)/libtiipc-usr$(BUILD_PROFILE_QNX_SUFFIX).so                 $(QNX_FS_PATH)/tilib/libtiipc-usr$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/resmgr/udma_qnx_rsmgr/usr/aarch64/$(BUILD_PROFILE_QNX_SO)/libtiudma-usr$(BUILD_PROFILE_QNX_SUFFIX).so               $(QNX_FS_PATH)/tilib/libtiudma-usr$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/resmgr/udma_qnx_rsmgr/usr/aarch64/$(BUILD_PROFILE_QNX_SO)/libtiudma-usr$(BUILD_PROFILE_QNX_SUFFIX).so               $(QNX_FS_PATH)/tilib/libtiudma-usr$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL ${PSDK_QNX_PATH}/qnx/sharedmemallocator/usr/aarch64/$(BUILD_PROFILE_QNX_SO)/libsharedmemallocator$(BUILD_PROFILE_QNX_SUFFIX).so          ${QNX_FS_PATH}/tilib/libsharedmemallocator$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL ${PSDK_QNX_PATH}/qnx/sharedmemallocator/usr/aarch64/$(BUILD_PROFILE_QNX_SO)/libsharedmemallocator$(BUILD_PROFILE_QNX_SUFFIX).so          ${QNX_FS_PATH}/tilib/libsharedmemallocator$(BUILD_PROFILE_QNX_SUFFIX).so.1
ifeq ($(SOC),$(filter $(SOC), j721e))
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/encoder/lib/aarch64/$(BUILD_PROFILE_QNX_SO)/libtimmenc$(BUILD_PROFILE_QNX_SUFFIX).so                  $(QNX_FS_PATH)/tilib/libtimmenc$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/encoder/lib/aarch64/$(BUILD_PROFILE_QNX_SO)/libtimmenc$(BUILD_PROFILE_QNX_SUFFIX).so                  $(QNX_FS_PATH)/tilib/libtimmenc$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/encoder/cli/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libvxe_enc-cli$(BUILD_PROFILE_QNX_SUFFIX).so          $(QNX_FS_PATH)/tilib/libvxe_enc-cli$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/encoder/cli/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libvxe_enc-cli$(BUILD_PROFILE_QNX_SUFFIX).so          $(QNX_FS_PATH)/tilib/libvxe_enc-cli$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/core/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libomxcore_j7$(BUILD_PROFILE_QNX_SUFFIX).so        $(QNX_FS_PATH)/tilib/libomxcore_j7$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/core/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libomxcore_j7$(BUILD_PROFILE_QNX_SUFFIX).so        $(QNX_FS_PATH)/tilib/libomxcore_j7$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/components/j721e/enc/nto/aarch64/$(BUILD_PROFILE_QNX_D)/omxil_comp_j7_enc$(BUILD_PROFILE_QNX_SUFFIX).so             $(QNX_FS_PATH)/tilib/omxil_comp_j7_enc$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/components/j721e/enc/nto/aarch64/$(BUILD_PROFILE_QNX_D)/omxil_comp_j7_enc$(BUILD_PROFILE_QNX_SUFFIX).so             $(QNX_FS_PATH)/tilib/omxil_comp_j7_enc$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/utility/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libomxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX).so                       $(QNX_FS_PATH)/tilib/libomxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/utility/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libomxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX).so                       $(QNX_FS_PATH)/tilib/libomxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/decoder/lib/aarch64/$(BUILD_PROFILE_QNX_SO)/libtimmdec$(BUILD_PROFILE_QNX_SUFFIX).so                  $(QNX_FS_PATH)/tilib/libtimmdec$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/decoder/lib/aarch64/$(BUILD_PROFILE_QNX_SO)/libtimmdec$(BUILD_PROFILE_QNX_SUFFIX).so                  $(QNX_FS_PATH)/tilib/libtimmdec$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/decoder/cli/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libvxd_dec-cli$(BUILD_PROFILE_QNX_SUFFIX).so          $(QNX_FS_PATH)/tilib/libvxd_dec-cli$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/decoder/cli/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libvxd_dec-cli$(BUILD_PROFILE_QNX_SUFFIX).so          $(QNX_FS_PATH)/tilib/libvxd_dec-cli$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/components/j721e/dec/nto/aarch64/$(BUILD_PROFILE_QNX_D)/omxil_comp_j7_dec$(BUILD_PROFILE_QNX_SUFFIX).so             $(QNX_FS_PATH)/tilib/omxil_comp_j7_dec$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/components/j721e/dec/nto/aarch64/$(BUILD_PROFILE_QNX_D)/omxil_comp_j7_dec$(BUILD_PROFILE_QNX_SUFFIX).so             $(QNX_FS_PATH)/tilib/omxil_comp_j7_dec$(BUILD_PROFILE_QNX_SUFFIX).so.1
endif
ifeq ($(SOC),$(filter $(SOC), j721s2 j784s4 am62a am62px))
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/tivpucodec/vpulib/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-vpucodec$(BUILD_PROFILE_QNX_SUFFIX).so                          $(QNX_FS_PATH)/tilib/libti-vpucodec$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/tivpucodec/vpulib/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-vpucodec$(BUILD_PROFILE_QNX_SUFFIX).so                          $(QNX_FS_PATH)/tilib/libti-vpucodec$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/resmgrlib/aarch64/$(BUILD_PROFILE_QNX_SO)/libvpu_usr_lib$(BUILD_PROFILE_QNX_SUFFIX).so                          $(QNX_FS_PATH)/tilib/libvpu_usr_lib$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/resmgrlib/aarch64/$(BUILD_PROFILE_QNX_SO)/libvpu_usr_lib$(BUILD_PROFILE_QNX_SUFFIX).so                          $(QNX_FS_PATH)/tilib/libvpu_usr_lib$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/core/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libomxcore_j7$(BUILD_PROFILE_QNX_SUFFIX).so            $(QNX_FS_PATH)/tilib/libomxcore_j7$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/core/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libomxcore_j7$(BUILD_PROFILE_QNX_SUFFIX).so            $(QNX_FS_PATH)/tilib/libomxcore_j7$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/components/vpu/enc/nto/aarch64/$(BUILD_PROFILE_QNX_D)/omxil_comp_vpu_enc$(BUILD_PROFILE_QNX_SUFFIX).so $(QNX_FS_PATH)/tilib/omxil_comp_vpu_enc$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/components/vpu/enc/nto/aarch64/$(BUILD_PROFILE_QNX_D)/omxil_comp_vpu_enc$(BUILD_PROFILE_QNX_SUFFIX).so $(QNX_FS_PATH)/tilib/omxil_comp_vpu_enc$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/utility/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libomxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX).so         $(QNX_FS_PATH)/tilib/libomxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/utility/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libomxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX).so         $(QNX_FS_PATH)/tilib/libomxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/resmgrlib/aarch64/$(BUILD_PROFILE_QNX_SO)/libvpu_usr_lib$(BUILD_PROFILE_QNX_SUFFIX).so         $(QNX_FS_PATH)/tilib/libvpu_usr_lib$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/resmgrlib/aarch64/$(BUILD_PROFILE_QNX_SO)/libvpu_usr_lib$(BUILD_PROFILE_QNX_SUFFIX).so         $(QNX_FS_PATH)/tilib/libvpu_usr_lib$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/tivpucodec/vpulib/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-vpucodec$(BUILD_PROFILE_QNX_SUFFIX).so         $(QNX_FS_PATH)/tilib/libti-vpucodec$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/tivpucodec/vpulib/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-vpucodec$(BUILD_PROFILE_QNX_SUFFIX).so         $(QNX_FS_PATH)/tilib/libti-vpucodec$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/components/vpu/dec/nto/aarch64/$(BUILD_PROFILE_QNX_D)/omxil_comp_vpu_dec$(BUILD_PROFILE_QNX_SUFFIX).so $(QNX_FS_PATH)/tilib/omxil_comp_vpu_dec$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/components/vpu/dec/nto/aarch64/$(BUILD_PROFILE_QNX_D)/omxil_comp_vpu_dec$(BUILD_PROFILE_QNX_SUFFIX).so $(QNX_FS_PATH)/tilib/omxil_comp_vpu_dec$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/firmware/wave521c_k3_codec_fw.bin                                                                            ${QNX_FS_PATH}/tilib/firmware/wave521c_k3_codec_fw.bin
endif
	######## ti pdk qnx test bin ######
	cp -rfL ${PSDK_QNX_PATH}/qnx/examples/ipc/ipc_test_qnx/aarch64/$(BUILD_PROFILE_QNX_O)/ipc_test$(BUILD_PROFILE_QNX_SUFFIX)                                                ${QNX_FS_PATH}/tibin/
	cp -rfL ${PSDK_QNX_PATH}/qnx/examples/udma/udma_memcpy_test_qnx/aarch64/$(BUILD_PROFILE_QNX_O)/udma_memcpy_testapp$(BUILD_PROFILE_QNX_SUFFIX)                            ${QNX_FS_PATH}/tibin/
	cp -rfL ${PSDK_QNX_PATH}/qnx/examples/sciclient/sciclient_qnx_app/aarch64/$(BUILD_PROFILE_QNX_O)/sciclient_app$(BUILD_PROFILE_QNX_SUFFIX)                                ${QNX_FS_PATH}/tibin/
	cp -rfL ${PSDK_QNX_PATH}/qnx/sharedmemallocator/samples/sharedMemAllocator/usr/aarch64/$(BUILD_PROFILE_QNX_O)/SharedMemoryAllocatorTestApp$(BUILD_PROFILE_QNX_SUFFIX)    ${QNX_FS_PATH}/tibin/
	cp -rfL ${PSDK_QNX_PATH}/qnx/examples/osal/sem_test/aarch64/$(BUILD_PROFILE_QNX_O)/osal_sem_testapp$(BUILD_PROFILE_QNX_SUFFIX)                                           ${QNX_FS_PATH}/tibin/
	cp -rfL ${PSDK_QNX_PATH}/qnx/examples/gpio/aarch64/$(BUILD_PROFILE_QNX_O)/gpio_test$(BUILD_PROFILE_QNX_SUFFIX)                                                                ${QNX_FS_PATH}/tibin/
ifneq ($(SOC),$(filter $(SOC), am62a am62x am62px))
	cp -rfL ${PSDK_QNX_PATH}/qnx/examples/gpio/aarch64/$(BUILD_PROFILE_QNX_O)/gpio$(BUILD_PROFILE_QNX_SUFFIX)                                                                ${QNX_FS_PATH}/tibin/
	cp -rfL ${PSDK_QNX_PATH}/qnx/examples/crypto/decrypt_app/aarch64/$(BUILD_PROFILE_QNX_O)/decrypt_app$(BUILD_PROFILE_QNX_SUFFIX)                                           ${QNX_FS_PATH}/tibin/
	cp -rfL ${PSDK_QNX_PATH}/qnx/examples/cpsw/ptp_test/aarch64/$(BUILD_PROFILE_QNX_O)/ptp_test$(BUILD_PROFILE_QNX_SUFFIX)                                                   ${QNX_FS_PATH}/tibin/
endif
#ifeq ($(SOC),$(filter $(SOC), am62a))
	#cp -rfL ${PSDK_QNX_PATH}/qnx/examples/csirx/csirx_capture_test_qnx/aarch64/$(BUILD_PROFILE_QNX_O)/csirx_capture_testapp$(BUILD_PROFILE_QNX_SUFFIX)                       ${QNX_FS_PATH}/tibin/
#endif
ifneq ($(SOC),$(filter $(SOC), am62x am62a am62px))
	cp -rfL ${PSDK_QNX_PATH}/qnx/examples/cpsw/cpsw_test/aarch64/$(BUILD_PROFILE_QNX_O)/cpsw_test$(BUILD_PROFILE_QNX_SUFFIX)                                                 ${QNX_FS_PATH}/tibin/
endif
ifeq ($(SOC),$(filter $(SOC), j721e))
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/encoder/cli_test/aarch64/$(BUILD_PROFILE_QNX_O)/enc_cli_ut$(BUILD_PROFILE_QNX_SUFFIX)                        $(QNX_FS_PATH)/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/encoder/test/aarch64/$(BUILD_PROFILE_QNX_O)/timmlibenc$(BUILD_PROFILE_QNX_SUFFIX)                            $(QNX_FS_PATH)/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/test/enc/nto/aarch64/$(BUILD_PROFILE_QNX_O)/omxil_video_enc$(BUILD_PROFILE_QNX_SUFFIX)             $(QNX_FS_PATH)/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/test/enc_performance/nto/aarch64/$(BUILD_PROFILE_QNX_O)/omxil_video_enc_p$(BUILD_PROFILE_QNX_SUFFIX)           $(QNX_FS_PATH)/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/decoder/test/aarch64/$(BUILD_PROFILE_QNX_O)/timmlibdec$(BUILD_PROFILE_QNX_SUFFIX)                            $(QNX_FS_PATH)/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/test/dec/nto/aarch64/$(BUILD_PROFILE_QNX_O)/omxil_video_dec$(BUILD_PROFILE_QNX_SUFFIX)             $(QNX_FS_PATH)/tibin/
endif
ifeq ($(SOC),$(filter $(SOC), j721s2 j784s4 am62a am62px))
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/tests/decoder_test/aarch64/$(BUILD_PROFILE_QNX_O)/vpu_decoder_test$(BUILD_PROFILE_QNX_SUFFIX)                                     ${QNX_FS_PATH}/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/tests/encoder_test/aarch64/$(BUILD_PROFILE_QNX_O)/vpu_encoder_test$(BUILD_PROFILE_QNX_SUFFIX)                                     ${QNX_FS_PATH}/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/tests/multi_inst_test/aarch64/$(BUILD_PROFILE_QNX_O)/vpu_multi_inst_test$(BUILD_PROFILE_QNX_SUFFIX)                               ${QNX_FS_PATH}/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/test/enc/nto/aarch64/$(BUILD_PROFILE_QNX_O)/omxil_video_enc$(BUILD_PROFILE_QNX_SUFFIX)                                  $(QNX_FS_PATH)/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/test/enc_performance/nto/aarch64/$(BUILD_PROFILE_QNX_O)/omxil_video_enc_p$(BUILD_PROFILE_QNX_SUFFIX)                    $(QNX_FS_PATH)/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/test/dec/nto/aarch64/$(BUILD_PROFILE_QNX_O)/omxil_video_dec$(BUILD_PROFILE_QNX_SUFFIX)                                  $(QNX_FS_PATH)/tibin/
endif
	######## ti pdk qnx test bin end ######
	######## qnx codec test files ######
ifeq ($(SOC),$(filter $(SOC), j721e))
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/codec_clips/nv12                                                                                              ${QNX_FS_PATH}/codec_test/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/test/enc/encoder_parameters.conf                                                            $(QNX_FS_PATH)/codec_test/
endif
ifeq ($(SOC),$(filter $(SOC), j721s2 j784s4 am62a am62px))
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/codec_clips/bitstream                                                                                         ${QNX_FS_PATH}/codec_test/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/codec_clips/nv12                                                                                              ${QNX_FS_PATH}/codec_test/vpu/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/test_files/cfg                                                                                            ${QNX_FS_PATH}/codec_test/vpu/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/test/enc/encoder_parameters.conf                                                                $(QNX_FS_PATH)/codec_test/vpu/cfg/
endif
	######## qnx codec test files end ######
	######## ti pdk qnx utils ######
	cp -rfL $(PSDK_QNX_PATH)/qnx/utils/k3conf/qnx/aarch64/$(BUILD_PROFILE_QNX_O)/k3conf$(BUILD_PROFILE_QNX_SUFFIX)                                   $(QNX_FS_PATH)/tibin/
	######## ti pdk qnx utils end ######
	#### copy scripts & extra ####
ifeq ($(SOC),$(filter $(SOC), j721e))
	# This update the user.sh script which is invoked from the .build file, as well as overwriting
	# the graphics.conf that is use
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/user_j721e.sh                      ${QNX_FS_PATH}/scripts/user.sh
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/user__dss_on_a72.sh                ${QNX_FS_PATH}/scripts/
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/user__dss_on_r5.sh                 ${QNX_FS_PATH}/scripts/
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/screen/usr/lib/graphics/j721e/*    ${QNX_FS_PATH}/usr/lib/graphics/j721e/
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/start_qconn_with_usb-asix.sh       ${QNX_FS_PATH}/scripts/
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/start_qconn_with_devnp-cpsw2g.sh   ${QNX_FS_PATH}/scripts/
else ifeq ($(SOC),$(filter $(SOC), j7200))
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/user_j7200.sh                      ${QNX_FS_PATH}/scripts/user.sh
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/start_qconn_with_usb-asix.sh       ${QNX_FS_PATH}/scripts/
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/start_qconn_with_devnp-cpsw2g.sh   ${QNX_FS_PATH}/scripts/
else ifeq ($(SOC),$(filter $(SOC), j721s2))
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/user_j721s2.sh                     ${QNX_FS_PATH}/scripts/user.sh
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/start_qconn_with_usb-asix.sh       ${QNX_FS_PATH}/scripts/
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/start_qconn_with_devnp-cpsw2g.sh   ${QNX_FS_PATH}/scripts/
else ifeq ($(SOC),$(filter $(SOC), am62x))
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/user_am62x.sh                      ${QNX_FS_PATH}/scripts/user.sh
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/start_qconn_with_usb-asix.sh       ${QNX_FS_PATH}/scripts/
else ifeq ($(SOC),$(filter $(SOC), am62a))
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/user_am62a.sh                      ${QNX_FS_PATH}/scripts/user.sh
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/start_qconn_with_usb-asix.sh       ${QNX_FS_PATH}/scripts/
else ifeq ($(SOC),$(filter $(SOC), am62px))
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/user_am62px.sh                      ${QNX_FS_PATH}/scripts/user.sh
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/start_qconn_with_usb-asix.sh       ${QNX_FS_PATH}/scripts/
else ifeq ($(SOC),$(filter $(SOC), j784s4))
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/user_j784s4.sh                     ${QNX_FS_PATH}/scripts/user.sh
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/start_qconn_with_usb-asix.sh       ${QNX_FS_PATH}/scripts/
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/start_qconn_with_devnp-cpsw2g.sh   ${QNX_FS_PATH}/scripts/
endif
	#### copy scripts & extra - end ####


copy_spl_uboot:
ifeq ($(SOC),$(filter $(SOC), j721e))
	###### PSDKLA SPL Boot Binaries #########
	cp ${LINUX_FS_BOOT_PATH}/tiboot3.bin                                    ${QNX_BOOT_PATH}/
	cp ${LINUX_FS_BOOT_PATH}/sysfw.itb                                      ${QNX_BOOT_PATH}/
	cp ${LINUX_FS_BOOT_PATH}/tispl.bin                                      ${QNX_BOOT_PATH}/
	cp ${LINUX_FS_BOOT_PATH}/u-boot.img                                     ${QNX_BOOT_PATH}/
else ifeq ($(SOC),$(filter $(SOC), j721s2 j784s4 am62x am62a am62px))
	###### PSDKLA SPL Boot Binaries #########
	cp ${LINUX_FS_BOOT_PATH}/tiboot3.bin                                    ${QNX_BOOT_PATH}/
	cp ${LINUX_FS_BOOT_PATH}/tispl.bin                                      ${QNX_BOOT_PATH}/
	cp ${LINUX_FS_BOOT_PATH}/u-boot.img                                     ${QNX_BOOT_PATH}/
endif
	# Add the uEnv.txt to load the QNX-IFS
ifeq ($(SOC),$(filter $(SOC), j721e))
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/u-boot/uEnv_j721e.txt              ${QNX_BOOT_PATH}/uEnv.txt
else ifeq ($(SOC),$(filter $(SOC), j7200))
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/u-boot/uEnv_j7200.txt              ${QNX_BOOT_PATH}/uEnv.txt
else ifeq ($(SOC),$(filter $(SOC), j721s2))
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/u-boot/uEnv_j721s2.txt             ${QNX_BOOT_PATH}/uEnv.txt
else ifeq ($(SOC),$(filter $(SOC), j784s4))
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/u-boot/uEnv_j784s4.txt             ${QNX_BOOT_PATH}/uEnv.txt
else ifeq ($(SOC),$(filter $(SOC), am62x))
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/u-boot/uEnv_am62x_with_dtb.txt     ${QNX_BOOT_PATH}/uEnv.txt
else ifeq ($(SOC),$(filter $(SOC), am62a))
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/u-boot/uEnv_am62a_with_dtb.txt     ${QNX_BOOT_PATH}/uEnv.txt
else ifeq ($(SOC),$(filter $(SOC), am62px))
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/u-boot/uEnv_am62px_with_dtb.txt    ${QNX_BOOT_PATH}/uEnv.txt
endif
