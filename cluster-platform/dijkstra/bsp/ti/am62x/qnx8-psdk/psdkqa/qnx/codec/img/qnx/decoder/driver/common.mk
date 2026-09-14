
ifndef QCONFIG
QCONFIG=qconfig.mk
endif
include $(QCONFIG)

INSTALLDIR=usr/bin
NAME=vxd_dec

define PINFO
PINFO DESCRIPTION=J7 video decoder resource manager
PINFO STATE=Experimental
PINFO VERSION_REL=$(PSDK_QNX_VERSION_REL)
PINFO TAGID=$(PSDK_QNX_TAGID)
endef

EXTRA_INCVPATH+=$(PSDK_QNX_PATH)/qnx/codec/img/timmlib/include \
                $(PSDK_QNX_PATH)/qnx/codec/img/osal/inc


#for pdk
EXTRA_INCVPATH+=$(PSDK_QNX_PATH)/pdk/packages

#EXCLUDE_OBJS+=osa_module.o

LIBS = c

ifeq ($(PSDK_QNX_USE_DSO),1)
  EXTRA_LIBVPATH+=$(PSDK_QNX_PATH)/qnx/pdk_libs/sciclient/aarch64/$(BUILD_PROFILE_QNX_SO)/
  EXTRA_LIBVPATH+=$(PSDK_QNX_PATH)/qnx/pdk_libs/pdk/aarch64/$(BUILD_PROFILE_QNX_SO)/
  EXTRA_LIBVPATH+=$(PSDK_QNX_PATH)/qnx/codec/img/qnx/decoder/lib/aarch64/$(BUILD_PROFILE_QNX_SO)/

  LIBS += timmdec$(BUILD_PROFILE_QNX_SUFFIX)
  LIBS += ti-sciclient$(BUILD_PROFILE_QNX_SUFFIX)
  LIBS += ti-pdk$(BUILD_PROFILE_QNX_SUFFIX)
else
  LIBS += $(PSDK_QNX_PATH)/qnx/codec/img/qnx/decoder/lib/aarch64/$(BUILD_PROFILE_QNX_SO)/libtimmdec$(BUILD_PROFILE_QNX_SUFFIX)S.a
  LIBS += $(PDK_INSTALL_PATH)/ti/drv/sciclient/lib/$(SOC)/qnx_mpu1_0/$(BUILD_PROFILE)/sciclient.aa72fg
  LIBS += $(PDK_INSTALL_PATH)/ti/csl/lib/$(SOC)/qnx_a72/$(BUILD_PROFILE)/ti.csl.aa72fg
  LIBS += $(PDK_INSTALL_PATH)/ti/osal/lib/qnx/$(SOC)/qnx_a72/$(BUILD_PROFILE)/ti.osal.aa72fg
  LIBS += $(PDK_INSTALL_PATH)/ti/board/lib/$(BOARD)/qnx_a72/$(BUILD_PROFILE)/ti.board.aa72fg
endif

CCFLAGS=-DOSAL_QNX -DSOC_J721E -DQNX_OS

include $(MKFILES_ROOT)/qtargets.mk
