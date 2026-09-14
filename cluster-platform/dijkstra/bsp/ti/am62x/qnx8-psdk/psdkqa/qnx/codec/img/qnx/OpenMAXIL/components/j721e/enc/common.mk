ifndef QCONFIG
QCONFIG=qconfig.mk
endif

include $(QCONFIG)
NAME=omxil_comp_j7_enc

EXTRA_INCVPATH+=$(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/khronos/openmaxil \
                $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/utility \
                $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/core \
                $(PSDK_QNX_PATH)/qnx/codec/img/timmlib/include \
                $(PSDK_QNX_PATH)/qnx/codec/img/qnx/encoder/cli

EXTRA_SRCVPATH+=$(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/components/common
EXCLUDE_OBJS+=omxil_component_dec.o

include $(MKFILES_ROOT)/qmacros.mk

INSTALLDIR=lib/dll/omxil
define PINFO
PINFO DESCRIPTION=OMX IL j721e encoder component
PINFO STATE=Experimental
PINFO VERSION_REL=$(PSDK_QNX_VERSION_REL)
PINFO TAGID=$(PSDK_QNX_TAGID)
endef

SOC_UPPER = SOC_$(shell echo $(SOC) | tr a-z A-Z)
CCFLAGS += -D$(SOC_UPPER)
include $(MKFILES_ROOT)/qtargets.mk

LIBS = c

ifeq ($(PSDK_QNX_USE_DSO),1)
  EXTRA_LIBVPATH+=$(PSDK_QNX_PATH)/qnx/pdk_libs/sciclient/aarch64/$(BUILD_PROFILE_QNX_SO)/
  EXTRA_LIBVPATH+=$(PSDK_QNX_PATH)/qnx/pdk_libs/pdk/aarch64/$(BUILD_PROFILE_QNX_SO)/
  EXTRA_LIBVPATH+=$(PSDK_QNX_PATH)/qnx/codec/img/qnx/encoder/lib/aarch64/$(BUILD_PROFILE_QNX_SO)/
  EXTRA_LIBVPATH+=$(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/utility/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/
  EXTRA_LIBVPATH+=$(PSDK_QNX_PATH)/qnx/codec/img/qnx/encoder/cli/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/

  LIBS+= vxe_enc-cli$(BUILD_PROFILE_QNX_SUFFIX)S
  LIBPREF_vxe_enc-cli$(BUILD_PROFILE_QNX_SUFFIX) = -Bstatic

  LIBS+= ti-sciclient$(BUILD_PROFILE_QNX_SUFFIX)
  LIBS+= ti-pdk$(BUILD_PROFILE_QNX_SUFFIX)
  LIBS+= omxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX)
else
  LIBS += $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/utility/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libomxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX)S.a
  LIBS += $(PSDK_QNX_PATH)/qnx/codec/img/qnx/encoder/cli/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libvxe_enc-cli$(BUILD_PROFILE_QNX_SUFFIX)S.a
  LIBS += $(PDK_INSTALL_PATH)/ti/drv/sciclient/lib/$(SOC)/qnx_mpu1_0/$(BUILD_PROFILE)/sciclient.aa72fg
  LIBS += $(PDK_INSTALL_PATH)/ti/csl/lib/$(SOC)/qnx_a72/$(BUILD_PROFILE)/ti.csl.aa72fg
  LIBS += $(PDK_INSTALL_PATH)/ti/osal/lib/qnx/$(SOC)/qnx_a72/$(BUILD_PROFILE)/ti.osal.aa72fg
  LIBS += $(PDK_INSTALL_PATH)/ti/board/lib/$(BOARD)/qnx_a72/$(BUILD_PROFILE)/ti.board.aa72fg
endif
