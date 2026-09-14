ifndef QCONFIG
QCONFIG=qconfig.mk
endif

include $(QCONFIG)
NAME=omxil_comp_vpu_dec

EXTRA_INCVPATH+=$(PDK_INSTALL_PATH) \
                $(PSDK_QNX_PATH)/qnx/codec/vpu/tivpucodec/vpulib/public \
                $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/khronos/openmaxil \
                $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/utility \
                $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/core \
                $(PSDK_QNX_PATH)/qnx/codec/vpu/tivpucodec/decoder \
                $(PSDK_QNX_PATH)/qnx/codec/vpu/tivpucodec/helper \
                $(PSDK_QNX_PATH)/qnx/codec/vpu/resmgrlib/ \
                $(PSDK_QNX_PATH)/qnx/sharedmemallocator/usr/public/ \
                $(PSDK_QNX_PATH)/qnx/sharedmemallocator/resmgr/public/
#                $(PSDK_QNX_PATH)/qnx/codec/vpu/tivpucodec/common \
#                $(PSDK_QNX_PATH)/qnx/codec/vpu/tivpucodec/helper \
#                $(PSDK_QNX_PATH)/qnx/codec/vpu/tivpucodec/helper/misc \
#                $(PSDK_QNX_PATH)/qnx/codec/vpu/decoder/cli

EXTRA_SRCVPATH+=$(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/components/common \

EXCLUDE_OBJS+=omxil_component_enc.o

include $(MKFILES_ROOT)/qmacros.mk

INSTALLDIR=lib/dll/omxil
define PINFO
PINFO DESCRIPTION=OMX IL VPU decoder component
PINFO STATE=Experimental
PINFO VERSION_REL=$(PSDK_QNX_VERSION_REL)
PINFO TAGID=$(PSDK_QNX_TAGID)
endef

SOC_UPPER = SOC_$(shell echo $(SOC) | tr a-z A-Z)
CCFLAGS += -D$(SOC_UPPER)
include $(MKFILES_ROOT)/qtargets.mk

LIBS = c

ifeq ($(PSDK_QNX_USE_DSO),1)
  EXTRA_LIBVPATH += $(PSDK_QNX_PATH)/qnx/pdk_libs/pdk/aarch64/$(BUILD_PROFILE_QNX_SO)/
  EXTRA_LIBVPATH += $(PSDK_QNX_PATH)/qnx/pdk_libs/sciclient/aarch64/$(BUILD_PROFILE_QNX_SO)/
  EXTRA_LIBVPATH += $(PSDK_QNX_PATH)/qnx/codec/vpu/resmgrlib/aarch64/$(BUILD_PROFILE_QNX_SO)/
  EXTRA_LIBVPATH += $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/utility/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/
  EXTRA_LIBVPATH += $(PSDK_QNX_PATH)/qnx/sharedmemallocator/usr/aarch64/$(BUILD_PROFILE_QNX_SO)/

  LIBS += ti-pdk$(BUILD_PROFILE_QNX_SUFFIX)
  LIBS += ti-sciclient$(BUILD_PROFILE_QNX_SUFFIX)
  LIBS += vpu_usr_lib$(BUILD_PROFILE_QNX_SUFFIX)
  LIBS += omxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX)
  LIBS += sharedmemallocator$(BUILD_PROFILE_QNX_SUFFIX)
else
  LIBS += $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/utility/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libomxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX)S.a
  LIBS += $(PSDK_QNX_PATH)/qnx/codec/vpu/resmgrlib/aarch64/$(BUILD_PROFILE_QNX_SO)/libvpu_usr_lib$(BUILD_PROFILE_QNX_SUFFIX)S.a
  LIBS += $(PSDK_QNX_PATH)/qnx/sharedmemallocator/usr/aarch64/$(BUILD_PROFILE_QNX_SO)/libsharedmemallocator$(BUILD_PROFILE_QNX_SUFFIX)S.a
  LIBS += $(PDK_INSTALL_PATH)/ti/drv/sciclient/lib/$(SOC)/qnx_mpu1_0/$(BUILD_PROFILE)/sciclient.aa72fg
  LIBS += $(PDK_INSTALL_PATH)/ti/csl/lib/$(SOC)/qnx_a72/$(BUILD_PROFILE)/ti.csl.aa72fg
  LIBS += $(PDK_INSTALL_PATH)/ti/osal/lib/qnx/$(SOC)/qnx_a72/$(BUILD_PROFILE)/ti.osal.aa72fg
  LIBS += $(PDK_INSTALL_PATH)/ti/board/lib/$(BOARD)/qnx_a72/$(BUILD_PROFILE)/ti.board.aa72fg
endif
