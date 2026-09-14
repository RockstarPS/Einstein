ifndef QCONFIG
QCONFIG=qconfig.mk
endif
include $(QCONFIG)

define PINFO
PINFO DESCRIPTION=J7 video encoder test app
PINFO STATE=Experimental
PINFO VERSION_REL=$(PSDK_QNX_VERSION_REL)
PINFO TAGID=$(PSDK_QNX_TAGID)
endef

NAME = timmlibenc
INSTALLDIR = usr/bin

#Add extra include path
EXTRA_INCVPATH+=$(PSDK_QNX_PATH)/qnx/codec/img/timmlib/include \
                $(PSDK_QNX_PATH)/qnx/codec/img/osal/inc

CCFLAGS=-DOSAL_QNX -DSOC_J721E -DQNX_OS

LIBS = slog2 screen

ifeq ($(PSDK_QNX_USE_DSO),1)
  EXTRA_LIBVPATH += $(PSDK_QNX_PATH)/qnx/pdk_libs/sciclient/aarch64/$(BUILD_PROFILE_QNX_SO)/
  EXTRA_LIBVPATH += $(PSDK_QNX_PATH)/qnx/pdk_libs/pdk/aarch64/$(BUILD_PROFILE_QNX_SO)/
  EXTRA_LIBVPATH += $(PSDK_QNX_PATH)/qnx/codec/img/qnx/encoder/lib/aarch64/$(BUILD_PROFILE_QNX_SO)/

  LIBS += timmenc$(BUILD_PROFILE_QNX_SUFFIX)
  LIBS += ti-sciclient$(BUILD_PROFILE_QNX_SUFFIX)
  LIBS += ti-pdk$(BUILD_PROFILE_QNX_SUFFIX)
else
  LIBS += $(PSDK_QNX_PATH)/qnx/codec/img/qnx/encoder/lib/aarch64/$(BUILD_PROFILE_QNX_SO)/libtimmenc$(BUILD_PROFILE_QNX_SUFFIX)S.a
  LIBS += $(PDK_INSTALL_PATH)/ti/drv/sciclient/lib/$(SOC)/qnx_mpu1_0/$(BUILD_PROFILE)/sciclient.aa72fg
  LIBS += $(PDK_INSTALL_PATH)/ti/csl/lib/$(SOC)/qnx_a72/$(BUILD_PROFILE)/ti.csl.aa72fg
  LIBS += $(PDK_INSTALL_PATH)/ti/osal/lib/qnx/$(SOC)/qnx_a72/$(BUILD_PROFILE)/ti.osal.aa72fg
  LIBS += $(PDK_INSTALL_PATH)/ti/board/lib/$(BOARD)/qnx_a72/$(BUILD_PROFILE)/ti.board.aa72fg
endif

include $(MKFILES_ROOT)/qtargets.mk
